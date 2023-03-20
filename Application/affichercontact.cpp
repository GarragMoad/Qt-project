#include "affichercontact.h"
#include"QDebug"

AfficherContact::AfficherContact(QWidget *parent) :
    QWidget(parent)

{

}
AfficherContact::AfficherContact(Gestioncontact *g)
{

    formulaire=new QFormLayout();
    Nom=new QLineEdit();

    formulaire->addRow(tr("&Chercher par Nom"),Nom);
    formulaire->addRow(tr("&Chercher par l'entreprise"),Entreprise);
    formulaire->addRow(tr("&Chercher par la date"),Date);
    formulaire->addRow(tr("&Chercher par Intervalle (Date1)"),IntervalleDate1);
    formulaire->addRow(tr("&Chercher par Intervalle (Date2)"),IntervalleDate2);

    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formulaire);
    mainLayout->addWidget(Chercher);
    setLayout(mainLayout);
    setWindowTitle(tr("Chercher Contact"));

     QObject::connect(Chercher, SIGNAL(clicked()), this, SLOT(ChercherContact()));
}


AfficherContact::~AfficherContact()
{

}




void AfficherContact::ChercherContact()
{

    QString nom=Nom->text();
    std::string NomC = nom.toStdString();
    QString entreprise=Entreprise->text();
    std::string EntrepriseC = entreprise.toStdString();
    QString date=Date->text();
    std::string DateC = date.toStdString();
    QString date1=IntervalleDate1->text();
    std::string Date1 = date1.toStdString();
    QString date2=IntervalleDate2->text();
    std::string Date2 = date2.toStdString();
    if(!NomC.empty())
        {
           emit declencher(&NomC);
        }
     if(!EntrepriseC.empty())
        {
           emit declencherE(&EntrepriseC);
        }
    if(!DateC.empty())
        {
           emit declencherD(&DateC);
        }
    if(!Date1.empty()&&!Date2.empty())
        {
           emit declencherIntervalle(&Date1,&Date2);
        }

     close();
}
