#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>
#include <QGraphicsScene>
#include <QScreen>
#include <QCursor>
#include <QTest>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void run();
private:
    QImage pic ;
    Ui::Widget *ui;
    QScreen *desktop;

private slots:
    void m_run();
    void m_makeScreenshot();
    QRgb m_printColor();
    void m_makeKlick(int y, int x);
    void quit();

};
#endif // WIDGET_H
