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
#ifndef WINSYS_H
#define WINSYS_H 1

#include "tuxracer.h"
#include "tux_types.h"

#ifdef USE_ICEGL
#include "gl.h"
#include "glu.h"
#include "SDL.h"
#else
#if defined( HAVE_SDL )
#   include "SDL.h"
#elif defined( HAVE_GLUT )
#   include "GLUT/glut.h"
#else
#   error "Neither SDL nor GLUT are present."
#endif
#endif // USE_ICEGL

#ifdef __cplusplus
extern "C"
{
#endif

/* Keysyms */

#if defined( HAVE_SDL ) 
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/* SDL version */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
#define SPECIAL_KEY(x) ((x & 0xffff) | 0x8000)
typedef enum {
    WSK_NOT_AVAIL = SDLK_UNKNOWN,

    /* Numeric keypad */
    WSK_KP0 = SPECIAL_KEY(SDLK_KP_0),
    WSK_KP1 = SPECIAL_KEY(SDLK_KP_1),
    WSK_KP2 = SPECIAL_KEY(SDLK_KP_2),
    WSK_KP3 = SPECIAL_KEY(SDLK_KP_3),
    WSK_KP4 = SPECIAL_KEY(SDLK_KP_4),
    WSK_KP5 = SPECIAL_KEY(SDLK_KP_5),
    WSK_KP6 = SPECIAL_KEY(SDLK_KP_6),
    WSK_KP7 = SPECIAL_KEY(SDLK_KP_7),
    WSK_KP8 = SPECIAL_KEY(SDLK_KP_8),
    WSK_KP9 = SPECIAL_KEY(SDLK_KP_9),
    WSK_KP_PERIOD = SPECIAL_KEY(SDLK_KP_PERIOD),
    WSK_KP_DIVIDE = SPECIAL_KEY(SDLK_KP_DIVIDE),
    WSK_KP_MULTIPLY = SPECIAL_KEY(SDLK_KP_MULTIPLY),
    WSK_KP_MINUS = SPECIAL_KEY(SDLK_KP_MINUS),
    WSK_KP_PLUS = SPECIAL_KEY(SDLK_KP_PLUS),
    WSK_KP_ENTER = SPECIAL_KEY(SDLK_KP_ENTER),
    WSK_KP_EQUALS = SPECIAL_KEY(SDLK_KP_EQUALS),

    /* Arrows + Home/End pad */
    WSK_UP = SPECIAL_KEY(SDLK_UP),
    WSK_DOWN = SPECIAL_KEY(SDLK_DOWN),
    WSK_RIGHT = SPECIAL_KEY(SDLK_RIGHT),
    WSK_LEFT = SPECIAL_KEY(SDLK_LEFT),
    WSK_INSERT = SPECIAL_KEY(SDLK_INSERT),
    WSK_HOME = SPECIAL_KEY(SDLK_HOME),
    WSK_END = SPECIAL_KEY(SDLK_END),
    WSK_PAGEUP = SPECIAL_KEY(SDLK_PAGEUP),
    WSK_PAGEDOWN = SPECIAL_KEY(SDLK_PAGEDOWN),

    /* Function keys */
    WSK_F1 = SPECIAL_KEY(SDLK_F1),
    WSK_F2 = SPECIAL_KEY(SDLK_F2),
    WSK_F3 = SPECIAL_KEY(SDLK_F3),
    WSK_F4 = SPECIAL_KEY(SDLK_F4),
    WSK_F5 = SPECIAL_KEY(SDLK_F5),
    WSK_F6 = SPECIAL_KEY(SDLK_F6),
    WSK_F7 = SPECIAL_KEY(SDLK_F7),
    WSK_F8 = SPECIAL_KEY(SDLK_F8),
    WSK_F9 = SPECIAL_KEY(SDLK_F9),
    WSK_F10 = SPECIAL_KEY(SDLK_F10),
    WSK_F11 = SPECIAL_KEY(SDLK_F11),
    WSK_F12 = SPECIAL_KEY(SDLK_F12),
    WSK_F13 = SPECIAL_KEY(SDLK_F13),
    WSK_F14 = SPECIAL_KEY(SDLK_F14),
    WSK_F15 = SPECIAL_KEY(SDLK_F15),

    /* Key state modifier keys */
    WSK_NUMLOCK = SPECIAL_KEY(SDLK_NUMLOCKCLEAR),
    WSK_CAPSLOCK = SPECIAL_KEY(SDLK_CAPSLOCK),
    WSK_SCROLLOCK = SPECIAL_KEY(SDLK_SCROLLLOCK),
    WSK_RSHIFT = SPECIAL_KEY(SDLK_RSHIFT),
    WSK_LSHIFT = SPECIAL_KEY(SDLK_LSHIFT),
    WSK_RCTRL = SPECIAL_KEY(SDLK_RCTRL),
    WSK_LCTRL = SPECIAL_KEY(SDLK_LCTRL),
    WSK_RALT = SPECIAL_KEY(SDLK_RALT),
    WSK_LALT = SPECIAL_KEY(SDLK_LALT),
    WSK_RMETA = SPECIAL_KEY(SDLK_RALT),
    WSK_LMETA = SPECIAL_KEY(SDLK_LALT),

    WSK_LAST = 0xffff

} winsys_keysym_t;

typedef enum {
    WS_LEFT_BUTTON = SDL_BUTTON_LEFT,
    WS_MIDDLE_BUTTON = SDL_BUTTON_MIDDLE,
    WS_RIGHT_BUTTON = SDL_BUTTON_RIGHT
} winsys_mouse_button_t;

typedef enum {
    WS_MOUSE_DOWN = SDL_PRESSED,
    WS_MOUSE_UP = SDL_RELEASED
} winsys_button_state_t;

#else
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/* GLUT version */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/

/* GLUT doesn't define as many keysyms as SDL; we map those to 
   WSK_NOT_AVAIL (0) */
#ifdef HAVE_GLUT
typedef enum {
    WSK_NOT_AVAIL = 0,

    /* Numeric keypad */
    WSK_KP0 = 0,
    WSK_KP1 = 0,
    WSK_KP2 = 0,
    WSK_KP3 = 0,
    WSK_KP4 = 0,
    WSK_KP5 = 0,
    WSK_KP6 = 0,
    WSK_KP7 = 0,
    WSK_KP8 = 0,
    WSK_KP9 = 0,
    WSK_KP_PERIOD = 0,
    WSK_KP_DIVIDE = 0,
    WSK_KP_MULTIPLY = 0,
    WSK_KP_MINUS = 0,
    WSK_KP_PLUS = 0,
    WSK_KP_ENTER = 0,
    WSK_KP_EQUALS = 0,

    /* Arrows + Home/End pad */
    WSK_UP = GLUT_KEY_UP,
    WSK_DOWN = GLUT_KEY_DOWN,
    WSK_RIGHT = GLUT_KEY_RIGHT,
    WSK_LEFT = GLUT_KEY_LEFT,
    WSK_INSERT = GLUT_KEY_INSERT,
    WSK_HOME = GLUT_KEY_HOME,
    WSK_END = GLUT_KEY_END,
    WSK_PAGEUP = GLUT_KEY_PAGE_UP,
    WSK_PAGEDOWN = GLUT_KEY_PAGE_DOWN,

    /* Function keys */
    WSK_F1 = GLUT_KEY_F1,
    WSK_F2 = GLUT_KEY_F2,
    WSK_F3 = GLUT_KEY_F3,
    WSK_F4 = GLUT_KEY_F4,
    WSK_F5 = GLUT_KEY_F5,
    WSK_F6 = GLUT_KEY_F6,
    WSK_F7 = GLUT_KEY_F7,
    WSK_F8 = GLUT_KEY_F8,
    WSK_F9 = GLUT_KEY_F9,
    WSK_F10 = GLUT_KEY_F10,
    WSK_F11 = GLUT_KEY_F11,
    WSK_F12 = GLUT_KEY_F12,
    WSK_F13 = 0,
    WSK_F14 = 0,
    WSK_F15 = 0,

    /* Key state modifier keys */
    WSK_NUMLOCK = 0,
    WSK_CAPSLOCK = 0,
    WSK_SCROLLOCK = 0,
    WSK_RSHIFT = 0,
    WSK_LSHIFT = 0,
    WSK_RCTRL = 0,
    WSK_LCTRL = 0,
    WSK_RALT = 0,
    WSK_LALT = 0,
    WSK_RMETA = 0,
    WSK_LMETA = 0,

    WSK_LAST = UCHAR_MAX /* GLUT doesn't define a max key, but this is more
			    than enough as of version 3.7 */
} winsys_keysym_t;

typedef enum {
    WS_LEFT_BUTTON = GLUT_LEFT_BUTTON,
    WS_MIDDLE_BUTTON = GLUT_MIDDLE_BUTTON,
    WS_RIGHT_BUTTON = GLUT_RIGHT_BUTTON 
} winsys_mouse_button_t;

typedef enum {
    WS_MOUSE_DOWN = GLUT_DOWN,
    WS_MOUSE_UP = GLUT_UP
} winsys_button_state_t;

#endif // HAVE_GLUT
#endif /* defined( HAVE_SDL ) */

typedef void (*winsys_display_func_t)();
typedef void (*winsys_idle_func_t)();
typedef void (*winsys_reshape_func_t)( int w, int h );
typedef void (*winsys_keyboard_func_t)( unsigned int key, bool_t special,
					bool_t release, int x, int y );
typedef void (*winsys_mouse_func_t)( int button, int state, int x, int y );
typedef void (*winsys_motion_func_t)( int x, int y );

typedef void (*winsys_atexit_func_t)( void );

void winsys_post_redisplay();
void winsys_set_display_func( winsys_display_func_t func );
void winsys_set_idle_func( winsys_idle_func_t func );
void winsys_set_reshape_func( winsys_reshape_func_t func );
void winsys_set_keyboard_func( winsys_keyboard_func_t func );
void winsys_set_mouse_func( winsys_mouse_func_t func );
void winsys_set_motion_func( winsys_motion_func_t func );
void winsys_set_passive_motion_func( winsys_motion_func_t func );

void winsys_swap_buffers();
void winsys_enable_key_repeat( bool_t enabled );
void winsys_warp_pointer( int x, int y );
void winsys_show_cursor( bool_t visible );

void winsys_init( int *argc, char **argv, char *window_title,
		  char *icon_title );
void winsys_shutdown();

void winsys_process_events(); /* Never returns */

void winsys_atexit( winsys_atexit_func_t func );

void winsys_exit( int code );

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* WINSYS_H */

/* Emacs Customizations
;;; Local Variables: ***
;;; c-basic-offset:0 ***
;;; End: ***
*/

/* EOF */
