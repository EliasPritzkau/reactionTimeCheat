#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //QPixmap pic =QPixmap("F:\\FCode\\Projects\\Q2 Projects\\cheatApplication\\testPicture.png");
    screenshot = QGuiApplication::primaryScreen();

    scene = new QGraphicsScene(pic.rect());
    m_run();

}


Widget::~Widget()
{
    delete ui;
}

void Widget::m_run()
{

    QTest::mouseClick(this,Qt::MouseButton::LeftButton,Qt::NoModifier, QPoint(200,200));
    for(int i = 0; i < 30; i-=-1)
    {

        m_makeScreenshot();

    }

}

void Widget::m_makeScreenshot()
{

    pic = screenshot->grabWindow(0, 200,200,200,200);
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


