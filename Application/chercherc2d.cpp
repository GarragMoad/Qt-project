#include "chercherc2d.h"
#include "ui_chercherc2d.h"

ChercherC2D::ChercherC2D(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChercherC2D)
{
    ui->setupUi(this);
}

ChercherC2D::~ChercherC2D()
{
    delete ui;
}

void ChercherC2D::on_pushButton_clicked()
{
    /**
    * ...  Récupération du contenu des champs et émission du signal en prenant le contenu en paramètre  ...
    */
    QString Date1=ui->lineEdit->text();
    std::string Date1C = Date1.toStdString();
    QString Date2=ui->lineEdit_2->text();
    std::string Date2C = Date2.toStdString();
    emit chercherDate2(&Date1C,&Date2C);
  close();
}

