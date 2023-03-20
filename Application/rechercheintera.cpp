#include "rechercheintera.h"
#include "ui_rechercheintera.h"

rechercheIntera::rechercheIntera(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rechercheIntera)
{
    ui->setupUi(this);
}

rechercheIntera::~rechercheIntera()
{
    delete ui;
}

void rechercheIntera::on_rechercheI_clicked()
{

    QString nom=ui->lineEditN->text();
    std::string NomC = nom.toStdString();
    QString Prenom=ui->Prenom->text();
    std::string PrenomC = Prenom.toStdString();
    QString date1=ui->lineEdit1->text();
    std::string date11 = date1.toStdString();
    QString date2=ui->lineEdit2->text();
    std::string date22 = date2.toStdString();
    emit rechercherrIntera(&NomC,&PrenomC,&date11,&date22);
    close();
}

