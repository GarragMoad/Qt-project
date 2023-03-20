#include "supdate.h"
#include "ui_supdate.h"

supDate::supDate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::supDate)
{
    ui->setupUi(this);
}

supDate::~supDate()
{
    delete ui;
}

void supDate::on_pushButton_clicked()
{
    /**
    * ...  Récupération du contenu des champs et émission du signal en prenant le contenu en paramètre  ...
    */
    QString date=ui->lineEdit->text();
    std::string dateC = date.toStdString();
    emit supprimerD(&dateC);
  close();
}

