#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //QPixmap pic =QPixmap("F:\\FCode\\Projects\\Q2 Projects\\cheatApplication\\testPicture.png");
    desktop = QGuiApplication::primaryScreen();
    int x = 200;int y = 200;
    scene = new QGraphicsScene(pic.rect());
    m_run();
    HWND desktop = GetDesktopWindow();
    // Check if the coordinates are valid
    if (IsWindowEnabled(desktop)) {
        // Move the cursor to the coordinates
        SetCursorPos(x, y);
        // Simulate a mouse click
        mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
        mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
}
}


Widget::~Widget()
{
    delete ui;
}

void Widget::m_run()
{


    for(int i = 0; i < 30; i-=-1)
    {

        m_makeScreenshot();

    }

}

void Widget::m_makeScreenshot()
{

    pic = desktop->grabWindow(0, 200,200,200,200);
    if(pic.isNull())
        qDebug() << "picture could not be loadet";
    printColor();


}

void Widget::printColor()
{
    QImage Image = pic.toImage();
    QRgb rgb =  Image.pixel (10,10);
    qDebug() << QColor(rgb).red() << QColor(rgb).green() << QColor(rgb).blue();
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

void Widget::m_makeClick()
{
    QCursor::setPos(100,100);

}


