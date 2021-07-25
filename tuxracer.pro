TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += opengl
LIBS += -framework OpenGL
LIBS += -framework GLUT
LIBS += -framework Tcl
DEFINES += TRACK_TRIANGLES
DEFINES += HAVE_GLUT

SOURCES += \
    alglib.c \
    audio.c \
    audio_data.c \
    button.c \
    course_load.c \
    course_mgr.c \
    course_quad.cpp \
    course_render.c \
    credits.c \
    debug.c \
    error_util.c \
    event_select.c \
    file_util.c \
    fog.c \
    fonts.c \
    fps.c \
    game_config.c \
    game_logic_util.c \
    game_over.c \
    game_type_select.c \
    gauss.c \
    gl_util.c \
    hash.c \
    hier.c \
    hier_cb.c \
    hier_util.c \
    hud.c \
    image.c \
    intro.c \
    joystick.c \
    keyboard.c \
    keyboard_util.c \
    keyframe.c \
    lights.c \
    list.c \
    listbox.c \
    loading.c \
    loop.c \
    main.c \
    mirror_course.c \
    multiplayer.c \
    nmrcl.c \
    os_util.c \
    part_sys.c \
    paused.c \
    phys_sim.c \
    pic.c \
    preview.c \
    quadgeom.cpp \
    quadtree.cpp \
    race_select.c \
    racing.c \
    render_util.c \
    reset.c \
    save.c \
    screenshot.c \
    splash_screen.c \
    ssbutton.c \
    string_util.c \
    tcl_util.c \
    tex_font_metrics.c \
    textarea.c \
    textures.c \
    track_marks.c \
    tux.c \
    tux_shadow.c \
    ui_mgr.c \
    ui_snow.c \
    ui_theme.c \
    view.c \
    viewfrustum.c \
    winsys.c

HEADERS += \
    alglib.h \
    audio.h \
    audio_data.h \
    button.h \
    course_load.h \
    course_mgr.h \
    course_quad.h \
    course_render.h \
    credits.h \
    debug.h \
    error_util.h \
    event_select.h \
    file_util.h \
    fog.h \
    fonts.h \
    fps.h \
    game_config.h \
    game_logic_util.h \
    game_over.h \
    game_type_select.h \
    gauss.h \
    gl_util.h \
    hash.h \
    hier.h \
    hier_cb.h \
    hier_util.h \
    hud.h \
    image.h \
    intro.h \
    joystick.h \
    keyboard.h \
    keyboard_util.h \
    keyframe.h \
    lights.h \
    list.h \
    listbox.h \
    loading.h \
    loop.h \
    mirror_course.h \
    multiplayer.h \
    nmrcl.h \
    os_util.h \
    part_sys.h \
    paused.h \
    phys_sim.h \
    pic.h \
    preview.h \
    quadgeom.hpp \
    quadtree.hpp \
    race_select.h \
    racing.h \
    render_util.h \
    reset.h \
    save.h \
    screenshot.h \
    splash_screen.h \
    ssbutton.h \
    string_util.h \
    tcl_util.h \
    tex_font_metrics.h \
    textarea.h \
    textures.h \
    track_marks.h \
    tux.h \
    tux_shadow.h \
    tux_types.h \
    tuxracer.h \
    ui_mgr.h \
    ui_snow.h \
    ui_theme.h \
    view.h \
    viewfrustum.h \
    winsys.h
