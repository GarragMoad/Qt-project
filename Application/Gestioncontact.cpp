/**
     * @file GestionContact.cpp
 */
using namespace std;
#include"Gestioncontact.h"

void Gestioncontact::setNomContactSupp(const string &value)
{
    NomContactSupp = value;
}

string Gestioncontact::getDateSupprimees() const
{
    return DateSupprimees;
}

void Gestioncontact::setDateSupprimees(const string &value)
{
    DateSupprimees = value;
}

string Gestioncontact::getNomContactSupp() const
{
    return NomContactSupp;
}


Gestioncontact::Gestioncontact(){}


Gestioncontact::Gestioncontact(list<Contact> c)
{
    this->ListeContact=c;
}

Gestioncontact::~Gestioncontact(){
    ListeContact.clear();
    resultRecherche.clear();

}


void Gestioncontact::AjouterContact(Contact c)
{
    this->ListeContact.push_back(c);

}

/**
     * @fn GestionContact
     * @brief récupère la date courante et le nom du contact qui va être supprimer avant de le supprimer de la liste
     */

void Gestioncontact:: SupprimerContact(Contact c)
{

    NomContactSupp=c.getNom();
    Date d;
    DateSupprimees=d.ddmmyy();
    for( auto i=ListeContact.begin();i!=ListeContact.end();i++)
    {
        if(i->getNom()==NomContactSupp)
            ListeContact.erase(i);
     }

}

void Gestioncontact:: AfficheContacts()
{
    for(auto i=ListeContact.begin();i!=ListeContact.end();i++)
    {
        i->affiche();
    }
}

 /**
     * @fn Recherche
     * @brief cherche les contacts demandés et les stocke dans la liste resultrecherche , elle les affiches aussi dans le terminal
     */
 list<Contact> Gestioncontact::Recherche(int rep,string entree)

    {

     for( auto i=ListeContact.begin();i!=ListeContact.end();i++)
     {


         if(rep==1)
         {
           if(i->getNom()==entree)
           {

             this->resultRecherche.push_back(*i);
           }


      }
         else if(rep==2)
         {
             
             if(i->getEntreprise()==entree)
             {
                this->resultRecherche.push_back(*i);
             }
         }

     }
    return resultRecherche;
    }






