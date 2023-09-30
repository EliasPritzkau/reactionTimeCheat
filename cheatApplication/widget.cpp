#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    //QPixmap pic =QPixmap("F:\\FCode\\Projects\\Q2 Projects\\cheatApplication\\testPicture.png");
    desktop = QGuiApplication::primaryScreen();
    scene = new QGraphicsScene(pic.rect());
    HWND_desktop = new HWND(GetDesktopWindow());
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
        m_makeScreenshot();
    }
    quit();

}

void Widget::m_makeScreenshot()
{

    pic = desktop->grabWindow(0, 200,200,10,10);
    if(pic.isNull())
        qDebug() << "picture could not be loadet";
    else if(QColor(printColor()).green() == 219)
        m_makeKlick(200,200);


}

QRgb Widget::printColor()
{
    QImage Image = pic.toImage();
    QRgb rgb =  Image.pixel (1,1);
    qDebug() << QColor(rgb).red() << QColor(rgb).green() << QColor(rgb).blue();
    return rgb;
}


void Widget::m_makeKlick(int y, int x)
{

    SetCursorPos(x, y);
    mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
    Sleep(200);
    mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);

}

void Widget::quit()
{
    QApplication::exit();
}
void Widget::m_makeDebugWindow()
{
    this->resize(pic.width(), pic.height());
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    scene->addPixmap(pic);

    scene->update();
    ui->graphicsView->resize(pic.width(), pic.height());
    ui->graphicsView->setScene(scene);
    ui->graphicsView->update();
    this->show();
}

