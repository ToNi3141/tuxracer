#include "mainwindow.h"
#include <QImage>
#include <QPixmap>
#include <math.h>
#include <QDebug>
//#include <verilated.h>
#include "QTime"
#include <QThread>
#include <QFile>
#include "IceGLWrapper.h"
#include <QKeyEvent>
//#include "softwarerenderer.h"
#include "winsys.h"

extern winsys_display_func_t disp_func;
extern winsys_idle_func_t idle_func;
extern winsys_keyboard_func_t keyboard_func;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_image(RESOLUTION_W, RESOLUTION_H, QImage::Format_RGB888)
{
    initIceGlCWrapper(&m_ogl);
    setupUi(this);

    connect(&m_timer, &QTimer::timeout, this, &MainWindow::newFrame);
    label->setPixmap(QPixmap::fromImage(m_image));
    m_timer.setInterval(50);
    m_timer.setSingleShot(false);
    m_timer.start();
}


void MainWindow::newFrame()
{
//    if (disp_func)
//        disp_func();
    if (idle_func)
        idle_func();

    m_ogl.commit();

    for (uint32_t i = 0; i < RESOLUTION_H; i++)
    {
        for (uint32_t j = 0; j < RESOLUTION_W; j++)
        {
            uint8_t r = ((m_framebuffer[(i*RESOLUTION_W)+j] >> 12) & 0xf) << 4;
            uint8_t g = ((m_framebuffer[(i*RESOLUTION_W)+j] >> 8) & 0xf) << 4;
            uint8_t b = ((m_framebuffer[(i*RESOLUTION_W)+j] >> 4) & 0xf) << 4;
            m_image.setPixelColor(QPoint(j, i), QColor(r, g, b));
        }
    }
    label->setPixmap(QPixmap::fromImage(m_image.scaled(m_image.width()*PREVIEW_WINDOW_SCALING, m_image.height()*PREVIEW_WINDOW_SCALING)));
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
        if (key == Qt::Key_Left)
            key = WSK_LEFT, special = true;
        if (key == Qt::Key_Right)
            key = WSK_RIGHT, special = true;;
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
            key = WSK_RIGHT, special = true;;
        (*keyboard_func)( key, special ? True : False, True, 0, 0 );
    }
}


MainWindow::~MainWindow()
{
}

void MainWindow::init()
{
}
