#include "widget.h"
#include "ui_widget.h"
#include <QOpenGLWidget>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

 //   ui->openGLWidget->update();
  //  QOpenGLWidget ca;
    Planet *pl=new Planet();
    QVBoxLayout *mainlay=new QVBoxLayout();
    mainlay->addWidget(pl);
    setLayout(mainlay);

}

Widget::~Widget()
{
    delete ui;
}
