#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QTimer>
#include "IceGL.hpp"
#include "Renderer.hpp"
#if USE_SIMULATION
#include "VerilatorBusConnector.hpp"
#endif
#if USE_HARDWARE
#undef VOID // Undef void because it is defined in the tcl.h and there is a typedef in WinTypes.h (which is used for the FT2232 library)
#include "FT2232HBusConnector.hpp"
#endif
#include <QWidget>
#include <QHBoxLayout>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(192, 150);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        MainWindow->setCentralWidget(centralWidget);

        //retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

//    void retranslateUi(QMainWindow *MainWindow)
//    {
//        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
//        label->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
//    } // retranslateUi
public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void init();

public slots:
    void newFrame();

private:
    static const uint32_t PREVIEW_WINDOW_SCALING = 1;

    void keyPressEvent(QKeyEvent *ev) override;
    void keyReleaseEvent(QKeyEvent *ev) override;

    int32_t m_fbSel = 0;
    float m_clipPlane = 1;

    QTimer m_timer;
    QImage m_image;


#ifdef SOFTWARE_RENDERER
public:
    static const uint32_t RESOLUTION_W = 480;
    static const uint32_t RESOLUTION_H = 320;
private:
    SoftwareRenderer m_renderer{m_framebuffer, m_zbuffer, RESOLUTION_W, RESOLUTION_H};
#endif
#if USE_SIMULATION
public:
    static const uint32_t RESOLUTION_W = 640;
    static const uint32_t RESOLUTION_H = 480;
private:
    uint16_t m_framebuffer[RESOLUTION_W*RESOLUTION_H];
    uint16_t m_zbuffer[RESOLUTION_W*RESOLUTION_H];

    VerilatorBusConnector<uint64_t> m_busConnector{reinterpret_cast<uint64_t*>(m_framebuffer), RESOLUTION_W, RESOLUTION_H};
    Renderer<256*1024, 4, RESOLUTION_H / 4, 32> m_renderer{m_busConnector};
#endif
#if USE_HARDWARE
public:
    static const uint32_t RESOLUTION_W = 480;
    static const uint32_t RESOLUTION_H = 320;
private:
    FT2232HBusConnector m_busConnector;
    Renderer<512*1024, 5, RESOLUTION_H / 5, 128, 256> m_renderer{m_busConnector};
#endif
    IceGL m_ogl{m_renderer};
};

#endif // MAINWINDOW_H
