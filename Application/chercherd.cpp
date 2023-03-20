#include "chercherd.h"
#include "ui_chercherd.h"

ChercherD::ChercherD(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChercherD)
{
    ui->setupUi(this);
}

ChercherD::~ChercherD()
{
    delete ui;
}

void ChercherD::on_pushButton_clicked()
{
    /**
    * ...  Récupération du contenu des champs et émission du signal en prenant le contenu en paramètre  ...
    */
    QString Date=ui->lineEdit->text();
    std::string DateC = Date.toStdString();
    emit chercherDate(&DateC);
  close();
}

