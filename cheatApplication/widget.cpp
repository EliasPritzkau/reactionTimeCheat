#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    //QPixmap pic =QPixmap("F:\\FCode\\Projects\\Q2 Projects\\cheatApplication\\testPicture.png");
    desktop= QApplication::primaryScreen();
    m_run();

}


Widget::~Widget()
{
    delete ui;
}

void Widget::m_run()
{
    for(int i = 0; i < 10000; i-=-1)
    {
        qDebug() << "is running";
        m_makeScreenshot();
    }

    quit();

}

void Widget::m_makeScreenshot()
{

    pic = desktop->grabWindow(0, 200,200,10,10).toImage();

    if(QColor(m_printColor()).green() == 219)
        m_makeKlick(200,200);


}

QRgb Widget::m_printColor()
{

    QRgb rgb =  pic.pixel (1,1);
    return rgb;
}


void Widget::m_makeKlick(int y, int x)
{

    SetCursorPos(x, y);
    mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
    Sleep(500);
    qDebug()<< "Klicked";
    mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);

}

void Widget::quit()
{
    qDebug()<< "app quit";
    this->close();

}


