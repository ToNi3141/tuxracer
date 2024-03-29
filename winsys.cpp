/* 
 * Tux Racer 
 * Copyright (C) 1999-2001 Jasmin F. Patry
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#include "tuxracer.h"
#include "winsys.h"
#include "audio.h"

/* Windowing System Abstraction Layer */
/* Abstracts creation of windows, handling of events, etc. */

#if defined( HAVE_SDL )
#include "IceGL.hpp"
#include "Renderer.hpp"
#include "RenderConfigs.hpp"
#include "DMAProxyBusConnector.hpp"
#if defined( HAVE_SDL_MIXER )
#   include "SDL_mixer.h"
#endif

/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/* SDL version */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

static SDL_Surface *screen = NULL;

static winsys_display_func_t display_func = NULL;
static winsys_idle_func_t idle_func = NULL;
static winsys_reshape_func_t reshape_func = NULL;
static winsys_keyboard_func_t keyboard_func = NULL;
static winsys_mouse_func_t mouse_func = NULL;
static winsys_motion_func_t motion_func = NULL;
static winsys_motion_func_t passive_motion_func = NULL;
static winsys_atexit_func_t atexit_func = NULL;

static bool_t redisplay = False;

static const uint32_t RESOLUTION_H = 600;
static const uint32_t RESOLUTION_W = 1024;
rr::DMAProxyBusConnector m_busConnector {};
rr::Renderer<rr::RenderConfigRRXIFZynq> m_renderer { m_busConnector };


/*---------------------------------------------------------------------------*/
/*! 
  Requests that the screen be redrawn
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_post_redisplay() 
{
    redisplay = True;
}


/*---------------------------------------------------------------------------*/
/*! 
  Sets the display callback
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_set_display_func( winsys_display_func_t func )
{
    display_func = func;
}


/*---------------------------------------------------------------------------*/
/*! 
  Sets the idle callback
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_set_idle_func( winsys_idle_func_t func )
{
    idle_func = func;
}


/*---------------------------------------------------------------------------*/
/*! 
  Sets the reshape callback
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_set_reshape_func( winsys_reshape_func_t func )
{
    reshape_func = func;
}


/*---------------------------------------------------------------------------*/
/*! 
  Sets the keyboard callback
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_set_keyboard_func( winsys_keyboard_func_t func )
{
    keyboard_func = func;
}


/*---------------------------------------------------------------------------*/
/*! 
  Sets the mouse button-press callback
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_set_mouse_func( winsys_mouse_func_t func )
{
    mouse_func = func;
}


/*---------------------------------------------------------------------------*/
/*! 
  Sets the mouse motion callback (when a mouse button is pressed)
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_set_motion_func( winsys_motion_func_t func )
{
    motion_func = func;
}


/*---------------------------------------------------------------------------*/
/*! 
  Sets the mouse motion callback (when no mouse button is pressed)
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_set_passive_motion_func( winsys_motion_func_t func )
{
    passive_motion_func = func;
}



/*---------------------------------------------------------------------------*/
/*! 
  Copies the OpenGL back buffer to the front buffer
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_swap_buffers()
{
    rr::IceGL::getInstance().render();
}


/*---------------------------------------------------------------------------*/
/*! 
  Moves the mouse pointer to (x,y)
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_warp_pointer( int x, int y )
{
    SDL_WarpMouseGlobal( x, y );
}

/*---------------------------------------------------------------------------*/
/*! 
  Initializes the OpenGL rendering context, and creates a window (or 
  sets up fullscreen mode if selected)
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_init( int *argc, char **argv, char *window_title, 
		  char *icon_title )
{
    rr::IceGL::createInstance(m_renderer);
    m_renderer.setRenderResolution(RESOLUTION_W, RESOLUTION_H);

    setparam_x_resolution(RESOLUTION_W);
    setparam_y_resolution(RESOLUTION_H);

    SDL_bool done = SDL_FALSE;

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }

    SDL_Window* win = SDL_CreateWindow("Tuxracer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, RESOLUTION_W, RESOLUTION_H, SDL_WINDOW_FULLSCREEN);
}


/*---------------------------------------------------------------------------*/
/*! 
  Deallocates resources in preparation for program termination
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_shutdown()
{
    SDL_Quit();
}

/*---------------------------------------------------------------------------*/
/*! 
  Enables/disables key repeat messages from being generated
  \return  
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_enable_key_repeat( bool_t enabled )
{
}


/*---------------------------------------------------------------------------*/
/*! 
  Shows/hides mouse cursor
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_show_cursor( bool_t visible )
{
    SDL_ShowCursor( visible );
}

/*---------------------------------------------------------------------------*/
/*! 
  Processes and dispatches events.  This function never returns.
  \return  No.
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_process_events()
{
    SDL_Event event; 
    unsigned int key;
    int x, y;

    while (True) {

	// SDL_LockAudio();
	// SDL_UnlockAudio();

	while ( SDL_PollEvent( &event ) ) {
	    
	    switch ( event.type ) {
	    case SDL_KEYDOWN:
		if ( keyboard_func ) {
		    SDL_GetMouseState( &x, &y );
		    key = event.key.keysym.sym; 
		    (*keyboard_func)( (key & SDLK_SCANCODE_MASK) ? SPECIAL_KEY(key) : key,
				      static_cast<bool_t>((key & SDLK_SCANCODE_MASK) != 0),
				      False,
				      x, y );
		}
		break;

	    case SDL_KEYUP:
		if ( keyboard_func ) {
		    SDL_GetMouseState( &x, &y );
		    key = event.key.keysym.sym; 
		    (*keyboard_func)( (key & SDLK_SCANCODE_MASK) ? SPECIAL_KEY(key) : key,
				      static_cast<bool_t>((key & SDLK_SCANCODE_MASK) != 0),
				      True,
				      x, y );
		}
		break;

	    case SDL_MOUSEBUTTONDOWN:
	    case SDL_MOUSEBUTTONUP:
		if ( mouse_func ) {
		    (*mouse_func)( event.button.button,
				   event.button.state,
				   event.button.x,
				   event.button.y );
		}
		break;

	    case SDL_MOUSEMOTION:
		if ( event.motion.state ) {
		    /* buttons are down */
		    if ( motion_func ) {
			(*motion_func)( event.motion.x,
					event.motion.y );
		    }
		} else {
		    /* no buttons are down */
		    if ( passive_motion_func ) {
			(*passive_motion_func)( event.motion.x,
						event.motion.y );
		    }
		}
		break;
	    }

	    // SDL_LockAudio();
	    // SDL_UnlockAudio();
	}

	if ( redisplay && display_func ) {
	    redisplay = False;
	    (*display_func)();
	} else if ( idle_func ) {
	    (*idle_func)();
	}

	/* Delay for 1 ms.  This allows the other threads to do some
	   work (otherwise the audio thread gets starved). */
	// SDL_Delay(1);

    }

    /* Never exits */
    code_not_reached();
}


/*---------------------------------------------------------------------------*/
/*! 
  Sets the function to be called when program ends.  Note that this
  function should only be called once.
  \author  jfpatry
  \date    Created:  2000-10-20
  \date Modified: 2000-10-20 */
void winsys_atexit( winsys_atexit_func_t func )
{
    static bool_t called = False;

    check_assertion( called == False, "winsys_atexit called twice" );

    called = True;
    atexit_func = func;
}


/*---------------------------------------------------------------------------*/
/*! 
  Exits the program
  \author  jfpatry
  \date    Created:  2000-10-20
  \date    Modified: 2000-10-20
*/
void winsys_exit( int code )
{
    if ( atexit_func ) {
	(*atexit_func)();
    }
    
    exit( code );
}

#else

#ifdef HAVE_GLUT
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/* GLUT version */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

static winsys_keyboard_func_t keyboard_func = NULL;

static bool_t redisplay = False;


/*---------------------------------------------------------------------------*/
/*! 
  Requests that the screen be redrawn
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_post_redisplay() 
{
    redisplay = True;
}


/*---------------------------------------------------------------------------*/
/*! 
  Sets the display callback
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_set_display_func( winsys_display_func_t func )
{
    glutDisplayFunc( func );
}


/*---------------------------------------------------------------------------*/
/*! 
  Sets the idle callback
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_set_idle_func( winsys_idle_func_t func )
{
    glutIdleFunc( func );
}


/*---------------------------------------------------------------------------*/
/*! 
  Sets the reshape callback
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_set_reshape_func( winsys_reshape_func_t func )
{
    glutReshapeFunc( func );
}


/* Keyboard callbacks */
static void glut_keyboard_cb( unsigned char ch, int x, int y ) 
{
    if ( keyboard_func ) {
	(*keyboard_func)( ch, False, False, x, y );
    }
}

static void glut_special_cb( int key, int x, int y ) 
{
    if ( keyboard_func ) {
	(*keyboard_func)( key, True, False, x, y );
    }
}

static void glut_keyboard_up_cb( unsigned char ch, int x, int y ) 
{
    if ( keyboard_func ) {
	(*keyboard_func)( ch, False, True, x, y );
    }
}

static void glut_special_up_cb( int key, int x, int y ) 
{
    if ( keyboard_func ) {
	(*keyboard_func)( key, True, True, x, y );
    }
}


/*---------------------------------------------------------------------------*/
/*! 
  Sets the keyboard callback
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_set_keyboard_func( winsys_keyboard_func_t func )
{
    keyboard_func = func;
}


/*---------------------------------------------------------------------------*/
/*! 
  Sets the mouse button-press callback
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_set_mouse_func( winsys_mouse_func_t func )
{
    glutMouseFunc( func );
}


/*---------------------------------------------------------------------------*/
/*! 
  Sets the mouse motion callback (when a mouse button is pressed)
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_set_motion_func( winsys_motion_func_t func )
{
    glutMotionFunc( func );
}


/*---------------------------------------------------------------------------*/
/*! 
  Sets the mouse motion callback (when no mouse button is pressed)
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_set_passive_motion_func( winsys_motion_func_t func )
{
    glutPassiveMotionFunc( func );
}



/*---------------------------------------------------------------------------*/
/*! 
  Copies the OpenGL back buffer to the front buffer
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_swap_buffers()
{
    glutSwapBuffers();
}


/*---------------------------------------------------------------------------*/
/*! 
  Moves the mouse pointer to (x,y)
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_warp_pointer( int x, int y )
{
    glutWarpPointer( x, y );
}


/*---------------------------------------------------------------------------*/
/*! 
  Initializes the OpenGL rendering context, and creates a window (or 
  sets up fullscreen mode if selected)
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_init( int *argc, char **argv, char *window_title, 
		  char *icon_title )
{
    int width, height;
    int glutWindow;

    glutInit( argc, argv );

#ifdef USE_STENCIL_BUFFER
    glutInitDisplayMode( GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE | GLUT_STENCIL );
#else
    glutInitDisplayMode( GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE );
#endif 

    /* Create a window */
//    if ( getparam_fullscreen() ) {
//	glutInitWindowPosition( 0, 0 );
//	glutEnterGameMode();
//    } else {
	/* Set the initial window size */
	width = getparam_x_resolution();
	height = getparam_y_resolution();
	glutInitWindowSize( width, height );

	if ( getparam_force_window_position() ) {
	    glutInitWindowPosition( 0, 0 );
	}

	glutWindow = glutCreateWindow( window_title );

	if ( glutWindow == 0 ) {
	    handle_error( 1, "Couldn't create a window." );
	}
//    }
}


/*---------------------------------------------------------------------------*/
/*! 
  Deallocates resources in preparation for program termination
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_shutdown()
{
    if ( getparam_fullscreen() ) {
	glutLeaveGameMode();
    }
}

/*---------------------------------------------------------------------------*/
/*! 
  Enables/disables key repeat messages from being generated
  \return  
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_enable_key_repeat( bool_t enabled )
{
    glutIgnoreKeyRepeat(!enabled);
}

/*---------------------------------------------------------------------------*/
/*! 
  Shows/hides mouse cursor
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_show_cursor( bool_t visible )
{
    if ( visible ) {
	glutSetCursor( GLUT_CURSOR_LEFT_ARROW );
    } else {
	glutSetCursor( GLUT_CURSOR_NONE );
    }
}



/*---------------------------------------------------------------------------*/
/*! 
  Processes and dispatches events.  This function never returns.
  \return  No.
  \author  jfpatry
  \date    Created:  2000-10-19
  \date    Modified: 2000-10-19
*/
void winsys_process_events()
{
    /* Set up keyboard callbacks */
    glutKeyboardFunc( glut_keyboard_cb );
    glutKeyboardUpFunc( glut_keyboard_up_cb );
    glutSpecialFunc( glut_special_cb );
    glutSpecialUpFunc( glut_special_up_cb );

    glutMainLoop();
}

/*---------------------------------------------------------------------------*/
/*! 
  Sets the function to be called when program ends.  Note that this
  function should only be called once.
  \author  jfpatry
  \date    Created:  2000-10-20
  \date Modified: 2000-10-20 */
void winsys_atexit( winsys_atexit_func_t func )
{
    static bool_t called = False;

    check_assertion( called == False, "winsys_atexit called twice" );

    called = True;

    atexit(func);
}


/*---------------------------------------------------------------------------*/
/*! 
  Exits the program
  \author  jfpatry
  \date    Created:  2000-10-20
  \date    Modified: 2000-10-20
*/
void winsys_exit( int code )
{
    exit(code);
}

#endif // HAVE_GLUT
#endif /* defined( HAVE_SDL ) */

/* EOF */
