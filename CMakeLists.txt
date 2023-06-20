cmake_minimum_required(VERSION 3.5)

project(tuxracer)

set(TCL_NAME tcl8.6)
set(SDL_LIB_NAME ${CMAKE_SHARED_LIBRARY_PREFIX}SDL3${CMAKE_SHARED_LIBRARY_SUFFIX})
set(TCL_LIB_NAME ${CMAKE_SHARED_LIBRARY_PREFIX}${TCL_NAME}${CMAKE_SHARED_LIBRARY_SUFFIX})

# Find TCL
find_library(TCL 
    NAMES ${TCL_LIB_NAME}
)
find_path(TCL_INCL
    NAMES ${TCL_NAME}/tcl.h
)
message("'TCL' found: " ${TCL}) 
message("'TCL_INCL' found: " ${TCL_INCL}) 

# find SDL
find_library(SDL 
    NAMES ${SDL_LIB_NAME} 
    HINTS ${SDL3_PATH} 
    PATH_SUFFIXES build 
    NO_CMAKE_FIND_ROOT_PATH
)
find_path(SDL_INCL 
    NAMES SDL3/SDL.h 
    HINTS ${SDL3_PATH} 
    PATH_SUFFIXES include 
    NO_CMAKE_FIND_ROOT_PATH
)
message("'SDL' found: " ${SDL}) 
message("'SDL_INCL' found: " ${SDL_INCL}) 

link_libraries(
    ${SDL} 
    ${TCL}
)
include_directories(
    .
    ${SDL_INCL} 
    ${TCL_INCL}/${TCL_NAME}
)

set(CMAKE_CXX_STANDARD 20)
add_definitions(
    -DUSE_ICEGL 
    -DHAVE_SDL 
    -DTUXRACER_NO_ASSERT
)

# Add an executable
add_executable(tuxracer 
    alglib.c
    audio.c
    audio_data.c
    button.c
    course_load.c
    course_mgr.c
    course_render.c
    credits.c
    debug.c
    error_util.c
    event_select.c
    file_util.c
    fog.c
    fonts.c
    fps.c
    game_config.c
    game_logic_util.c
    game_over.c
    game_type_select.c
    gauss.c
    gl_util.c
    hash.c
    hier.c
    hier_cb.c
    hier_util.c
    hud.c
    image.c
    intro.c
    joystick.c
    keyboard.c
    keyboard_util.c
    keyframe.c
    lights.c
    listbox.c
    list.c
    loading.c
    loop.c
    main.c
    mirror_course.c
    multiplayer.c
    nmrcl.c
    os_util.c
    part_sys.c
    paused.c
    phys_sim.c
    pic.c
    preview.c
    race_select.c
    racing.c
    render_util.c
    reset.c
    save.c
    screenshot.c
    splash_screen.c
    ssbutton.c
    string_util.c
    tcl_util.c
    tex_font_metrics.c
    textarea.c
    textures.c
    track_marks.c
    tux.c
    tux_shadow.c
    ui_mgr.c
    ui_snow.c
    ui_theme.c
    view.c
    viewfrustum.c
    course_quad.cpp
    quadgeom.cpp
    quadtree.cpp
    winsys.cpp
)

target_compile_options(tuxracer 
    PRIVATE -fsigned-char
)
target_link_libraries(tuxracer 
    PRIVATE gl spdlog::spdlog dmaproxy
)

add_subdirectory(Rasterix)
