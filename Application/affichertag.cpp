#include "affichertag.h"
#include "ui_affichertag.h"

AfficherTag::AfficherTag(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AfficherTag)
{
    ui->setupUi(this);
}

AfficherTag::~AfficherTag()
{
    delete ui;
}

void AfficherTag::on_pushButton_clicked()
{
    /**
    * ... Récupération du contenu des champs et émission du signal en prenant le contenu en paramètre  ...
    */
    QString Date=ui->lineEditDate->text();
    std::string DateC = Date.toStdString();
     emit afficherT(&DateC); //Emission du signal
    close(); // fermer le widget
}

