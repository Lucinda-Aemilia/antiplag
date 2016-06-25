#include "widget.h"
#include "ui_widget.h"
#include "antiplag.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <QMessageBox>
#include <QDebug>
#include <iostream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this,SLOT(Print()));


}

Widget::~Widget()
{
    delete ui;
}

void Widget::Print()
{
   QMessageBox::information(this, tr("result"), tr("Get Done!"));
}

