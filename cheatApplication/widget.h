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
    QPixmap pic ;
    QGraphicsScene *scene = nullptr;
    Ui::Widget *ui;
    QScreen *screenshot;

private slots:
    void m_run();
    void m_makeScreenshot();
    void printColor();
    void m_makeDebugWindow();
    void m_makeClick();

};
#endif // WIDGET_H