#include "operate.h"
#include "ui_operate.h"

operate::operate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::operate)
{
    ui->setupUi(this);
}

operate::~operate()
{
    delete ui;
}
