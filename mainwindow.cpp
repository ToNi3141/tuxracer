#include "mainwindow.h"
#include <QImage>
#include <QPixmap>
#include <math.h>
#include <QDebug>
//#include <verilated.h>
#include "QTime"
#include <QThread>
#include <QFile>
#include <QKeyEvent>
//#include "softwarerenderer.h"
#include "winsys.h"

extern winsys_display_func_t disp_func;
extern winsys_idle_func_t idle_func;
extern winsys_keyboard_func_t keyboard_func;

double sc_time_stamp() {
    static double t = 0;
    return ++t;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_image(RESOLUTION_W, RESOLUTION_H, QImage::Format_RGB888)
{
    rr::IceGL::createInstance(m_renderer);
    m_renderer.setRenderResolution(RESOLUTION_W, RESOLUTION_H);
    setupUi(this);

    connect(&m_timer, &QTimer::timeout, this, &MainWindow::newFrame);
    label->setPixmap(QPixmap::fromImage(m_image));
    m_timer.setInterval(33);
    m_timer.setSingleShot(false);
    m_timer.start();
    #if SPDLOG_ACTIVE_LEVEL == SPDLOG_LEVEL_TRACE
    spdlog::set_level(spdlog::level::trace);
    #elif SPDLOG_ACTIVE_LEVEL == SPDLOG_LEVEL_DEBUG
    spdlog::set_level(spdlog::level::debug);
    #elif SPDLOG_ACTIVE_LEVEL == SPDLOG_LEVEL_INFO
    spdlog::set_level(spdlog::level::info);
    #elif SPDLOG_ACTIVE_LEVEL == SPDLOG_LEVEL_WARN
    spdlog::set_level(spdlog::level::warn);
    #elif SPDLOG_ACTIVE_LEVEL == SPDLOG_LEVEL_ERROR
    spdlog::set_level(spdlog::level::err);
    #elif SPDLOG_ACTIVE_LEVEL == SPDLOG_LEVEL_CRITICAL
    spdlog::set_level(spdlog::level::critical);
    #endif
}


void MainWindow::newFrame()
{
//    if (disp_func)
//        disp_func();
    if (idle_func)
        idle_func();

    rr::IceGL::getInstance().render();

#if USE_SIMULATION
    // To prevent tearing in the simulation, wait till the last line is rendered and wait till the last chunk from the framebuffer was transferred.
    m_busConnector.waitForLastFramebufferChunk();

    // Copy picture from internal framebuffer into the QImage.
    for (uint32_t i = 0; i < RESOLUTION_H; i++)
    {
        for (uint32_t j = 0; j < RESOLUTION_W; j++)
        {
            uint8_t r = ((m_framebuffer[(i*RESOLUTION_W)+j] >> 11) & 0x1f) << 3;
            uint8_t g = ((m_framebuffer[(i*RESOLUTION_W)+j] >> 5) & 0x3f) << 2;
            uint8_t b = ((m_framebuffer[(i*RESOLUTION_W)+j] >> 0) & 0x1f) << 3;
            // uint8_t r = ((m_framebuffer[(i*RESOLUTION_W)+j] >> 24) & 0xff) << 0;
            // uint8_t g = ((m_framebuffer[(i*RESOLUTION_W)+j] >> 16) & 0xff) << 0;
            // uint8_t b = ((m_framebuffer[(i*RESOLUTION_W)+j] >> 8) & 0xff) << 0;
            m_image.setPixelColor(QPoint(j, i), QColor(r, g, b));
        }
    }
    label->setPixmap(QPixmap::fromImage(m_image.scaled(m_image.width()*PREVIEW_WINDOW_SCALING, m_image.height()*PREVIEW_WINDOW_SCALING)));
#endif
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
    if ( keyboard_func ) {
        bool special = ev->key() <= 0;
        int key = (special) ? ev->key() * -1 : ev->key();
        if (key == Qt::Key_Escape)
            key = 0x1b;
        if (key == Qt::Key_Enter)
            key = 0xd;
        if (key == Qt::Key_Return)
            key = 0xd;
        if (key == Qt::Key_Left)
            key = WSK_LEFT, special = true;
        if (key == Qt::Key_Right)
            key = WSK_RIGHT, special = true;
        if (key == Qt::Key_Up)
            key = WSK_UP, special = true;
        if (key == Qt::Key_Down)
            key = WSK_DOWN, special = true;
        (*keyboard_func)( key, special ? True : False, False, 0, 0 );
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *ev) {
    if ( keyboard_func ) {
        bool special = ev->key() <= 0;
        int key = (special) ? ev->key() * -1 : ev->key();
        if (key == Qt::Key_Escape)
            key = 0x1b;
        if (key == Qt::Key_Enter)
            key = 0xd;
        if (key == Qt::Key_Left)
            key = WSK_LEFT, special = true;
        if (key == Qt::Key_Right)
            key = WSK_RIGHT, special = true;
        if (key == Qt::Key_Up)
            key = WSK_UP, special = true;
        if (key == Qt::Key_Down)
            key = WSK_DOWN, special = true;
        (*keyboard_func)( key, special ? True : False, True, 0, 0 );
    }
}


MainWindow::~MainWindow()
{
}

void MainWindow::init()
{
}
