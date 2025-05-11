#include "date_query.h"

#include "date.h"
#include "ui_date_query.h"


date_query::date_query(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::date_query)
{
    ui->setupUi(this);
}

date_query::~date_query()
{
    delete ui;
}

void date_query::on_search_clicked()
{
    QObject::connect(control,SIGNAL(address_push(Control*)),this,SLOT(address_get(Control*)));


    Date first(ui->dateEdit->date().year(),ui->dateEdit->date().month(),ui->dateEdit->date().day());
    Date second(ui->dateEdit_2->date().year(),ui->dateEdit_2->date().month(),ui->dateEdit_2->date().day());

    control->log_search_finished(first,second);

    this->close();
}

void date_query::address_get(Control *con)
{
    control = con;

}
