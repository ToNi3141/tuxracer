#TARGET = glut
TARGET = simulation
#TARGET = hardware
TEMPLATE = app
CONFIG += console c++17
QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.15
CONFIG -= app_bundle

LIBS += -framework Tcl
DEFINES += TUXRACER_NO_ASSERT
DEFINES += TRACK_TRIANGLES

VAL = 0
equals(TARGET, "hardware") {
    VAL = 1
}

equals(TARGET, "simulation") {
    VAL = 1
}

greaterThan(VAL, 0) {
# Set here the path to your local verilator installation
VERILATOR_PATH = /opt/homebrew/Cellar/verilator/4.220/share/verilator

ICEGL_PATH = ../tuxracer/Rasterix/lib/gl
VERILATOR_BUS_CONNECTOR_PATH = ../tuxracer/Rasterix/unittest/cpp/include
VERILATOR_CODE_GEN_PATH = ../tuxracer/Rasterix/rtl/top/Verilator/obj_dir
FT2232H_BUS_CONNECTOR_PATH = ../tuxracer/Rasterix/unittest/cpp/include
FT60X_BUS_CONNECTOR_PATH = ../tuxracer/Rasterix/lib/driver
FT60X_LIB_PATH = ../tuxracer/Rasterix/lib/ftd3xx/osx

CONFIG += qt
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT       += core

#DEFINES += SOFTWARE_RENDERER
#DEFINES += NO_PERSP_CORRECT

DEFINES += USE_ICEGL

equals(TARGET, "simulation") {
    DEFINES += USE_SIMULATION

    LIBS += $${VERILATOR_CODE_GEN_PATH}/Vtop__ALL.a

    QMAKE_CXXFLAGS += -I$${VERILATOR_CODE_GEN_PATH}/ \
        -I$${VERILATOR_BUS_CONNECTOR_PATH}/ \
        -I$${VERILATOR_PATH}/include/

    QMAKE_CFLAGS += -I$${VERILATOR_CODE_GEN_PATH}/ \
        -I$${VERILATOR_BUS_CONNECTOR_PATH}/ \
        -I$${VERILATOR_PATH}/include/

    SOURCES += $${VERILATOR_PATH}/include/verilated.cpp

    HEADERS += $${VERILATOR_BUS_CONNECTOR_PATH}/VerilatorBusConnector.hpp
}

equals(TARGET, "hardware") {
    DEFINES += USE_HARDWARE

#    LIBS += /usr/local/lib/libftd2xx.dylib
    LIBS += /usr/local/homebrew/Cellar/libusb/1.0.26/lib/libusb-1.0.dylib
    LIBS += $${FT60X_LIB_PATH}/libftd3xx-static.a

#    QMAKE_CXXFLAGS += -I/usr/local/include/ \
#        -I$${FT2232H_BUS_CONNECTOR_PATH}/

#    QMAKE_CFLAGS += -I/usr/local/include/ \
#        -I$${FT2232H_BUS_CONNECTOR_PATH}/

    QMAKE_CXXFLAGS += -I$${FT60X_BUS_CONNECTOR_PATH}/ \
        -I$${FT60X_LIB_PATH}/

    QMAKE_CFLAGS += -I$${FT60X_BUS_CONNECTOR_PATH}/\
        -I$${FT60X_LIB_PATH}/

    # HEADERS += $${FT2232H_BUS_CONNECTOR_PATH}/FT2232HBusConnector.hpp
    HEADERS += $${FT60X_BUS_CONNECTOR_PATH}/FT60XBusConnector.hpp
}

QMAKE_CXXFLAGS += -I$${ICEGL_PATH}/

QMAKE_CFLAGS += -I$${ICEGL_PATH}/

SOURCES += \
    mainwindow.cpp \
    $${ICEGL_PATH}/TnL.cpp \
    $${ICEGL_PATH}/IceGL.cpp \
    $${ICEGL_PATH}/Rasterizer.cpp \
    $${ICEGL_PATH}/IceGLWrapper.cpp

HEADERS += \
    mainwindow.h \
    $${ICEGL_PATH}/DisplayList.hpp \
    $${ICEGL_PATH}/IBusConnector.hpp \
    $${ICEGL_PATH}/IRenderer.hpp \
    $${ICEGL_PATH}/Renderer.hpp \
    $${ICEGL_PATH}/TnL.hpp \
    $${ICEGL_PATH}/Vec.hpp \
    $${ICEGL_PATH}/Mat44.hpp \
    $${ICEGL_PATH}/Veci.hpp \
    $${ICEGL_PATH}/IceGL.hpp \
    $${ICEGL_PATH}/Rasterizer.hpp \
    $${ICEGL_PATH}/IceGLWrapper.h \
    $${ICEGL_PATH}/IceGLTypes.h
}

equals(TARGET, "glut") {
    DEFINES += HAVE_GLUT
    LIBS += -framework OpenGL
    LIBS += -framework GLUT
    CONFIG += opengl
}



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
    winsys.cpp

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
