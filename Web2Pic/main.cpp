#include <QtWidgets/QApplication>
#include <QtWebEngineWidgets/QWebEngineView>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    QWebEngineView* w = new QWebEngineView();
    //w->setUrl(QUrl("https://www.google.com/search?q=0001"));
    w->setUrl(QUrl("https://www.yahoo.com"));
    w->resize(1024, 750);
    w->show();
    QObject::connect(w, &QWebEngineView::loadFinished,
                     [w](bool bOk)
                     {
                         int height, width, left, top;
                         height = 600;
                         width = 800;
                         left = 0;
                         top = 0;

                         QImage image(height, width, QImage::Format_RGB32);
                         QRegion rg(left, top, width, height);
                         QPainter painter(&image);
                         //w.render(&painter, QPoint(), rg);
                         w->page()->view()->render(&painter, QPoint(), rg);
                         painter.end();
                         //image.save(&bu, "PNG", 80);
                         image.save("test.png", "PNG", 80);
                     });

    return a.exec();
}
