#include <QtWidgets/QApplication>
#include "webwindow.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    WebWindow ww;

    ww.DoCapture();
    //QWebEngineView w;
    //QImage image(height, width, QImage::Format_RGB32);
    //QRegion rg(left, top, width, height);
    //QPainter painter(&image);
    ////w->setUrl(QUrl("https://www.google.com/search?q=0001"));
    //w.setUrl(QUrl("https://www.yahoo.com"));
    //w.resize(1024, 750);
    //w.show();
    //w.render(&painter, QPoint(), rg);
    ////w.page()->view()->render(&painter, QPoint(), rg);
    //painter.end();
    ////QByteArray ba;
    ////QBuffer bu(&ba);
    ////bu.open(QBuffer::ReadWrite);
    ////bu.close();
    ////image.save(&bu, "PNG", 80);
    //image.save("test.png", "PNG", 80);

    return a.exec();
}
