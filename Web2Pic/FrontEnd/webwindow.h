#ifndef WEBWINDOW_H
#define WEBWINDOW_H

#include <QMainWindow>
#include <QtWebEngineWidgets/QWebEngineView>

namespace Ui {
class WebWindow;
}

class WebWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit WebWindow(QWidget *parent = 0);
    ~WebWindow();

    void DoCapture();

private:
    Ui::WebWindow *ui;
    QWebEngineView* m_w;

    void LeftMouseClick(QWidget* eventsReciverWidget, QPoint clickPos);
private slots:
    void HandleFinished(bool bFinished);
};

#endif // WEBWINDOW_H
