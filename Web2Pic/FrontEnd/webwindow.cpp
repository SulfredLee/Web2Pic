#include "webwindow.h"
#include "ui_webwindow.h"
#include <QtGui/QMouseEvent>
#include <QtCore/QTimer>
#include <QtTest/QTest>

#include <iostream>

WebWindow::WebWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WebWindow)
{
    ui->setupUi(this);
    m_w = new QWebEngineView();
    connect(m_w, SIGNAL(loadFinished(bool)), this, SLOT(HandleFinished(bool)));
}

WebWindow::~WebWindow()
{
    delete ui;
}

void WebWindow::DoCapture(){
    m_w->setUrl(QUrl("https://www.google.com/search?q=0001"));
    m_w->resize(1024, 750);
    m_w->show();
}

void WebWindow::HandleFinished(bool bFinished){
    if(bFinished){
        //QWidget* eventsReciverWidget = nullptr;
        //foreach(QObject* obj, m_w.children()){
        //    QWidget* wgt = qobject_cast<QWidget*>(obj);
        //    if (wgt){
        //        eventsReciverWidget = wgt;
        //        break;
        //    }
        //}
        //QPoint clickPos(550, 315);
        //if(eventsReciverWidget != nullptr){
        //    LeftMouseClick(eventsReciverWidget, clickPos);
        //}
        QPoint clickPoint(550, 315);
        QTest::mouseMove(m_w, clickPoint, -1);
        //QTest::mouseClick(m_w, Qt::LeftButton, Qt::NoModifier, QPoint(550, 315), 50);
        QTest::mousePress(m_w, Qt::LeftButton, Qt::NoModifier, clickPoint, 50);
        QTest::mouseRelease(m_w, Qt::LeftButton, Qt::NoModifier, clickPoint, 50);

        QTimer::singleShot(500, [this] {
                int height, width, left, top;
                //top = 315;
                //left = 550;
                top = 170;
                left = 150;
                height = 532;
                width = 636;

                QImage image(width, height, QImage::Format_RGB32);
                QRegion rg(left, top, width, height);
                QPainter painter(&image);
                this->m_w->render(&painter, QPoint(), rg);
                painter.end();
                image.save("test.png", "PNG", 80);
            });
    }
}

void WebWindow::LeftMouseClick(QWidget* eventsReciverWidget, QPoint clickPos){
    QMouseEvent *press = new QMouseEvent(QEvent::MouseButtonPress,
                                         clickPos,
                                         Qt::LeftButton,
                                         Qt::MouseButton::NoButton,
                                         Qt::NoModifier);
    QCoreApplication::postEvent(eventsReciverWidget, press);
    std::cout << "----------------Here is 1\n";
    // Some delay
    QTimer::singleShot(500, [clickPos, eventsReciverWidget]() {
            QMouseEvent *release = new QMouseEvent(QEvent::MouseButtonRelease,
                                                   clickPos,
                                                   Qt::LeftButton,
                                                   Qt::MouseButton::NoButton,
                                                   Qt::NoModifier);
            QCoreApplication::postEvent(eventsReciverWidget, release);
            std::cout << "----------------Here is 2\n";
        });
}
