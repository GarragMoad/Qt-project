#include "interactioninteravalle.h"
#include "ui_interactioninteravalle.h"

InteractionInteravalle::InteractionInteravalle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InteractionInteravalle)
{
    ui->setupUi(this);
}

InteractionInteravalle::~InteractionInteravalle()
{
    delete ui;
}

void InteractionInteravalle::on_pushButton_clicked()
{
    /**
    * ...  Récupération du contenu des champs et émission du signal en prenant le contenu en paramètre  ...
    */
    QString Date1=ui->lineEdit->text();
    std::string Date1C = Date1.toStdString();
    QString Date2=ui->lineEdit_2->text();
    std::string Date2C = Date2.toStdString();
    emit InteraDate(&Date1C,&Date2C);
  close();
}

