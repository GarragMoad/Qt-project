 /**
     * @file interaction.cpp
 */
#include "Interaction.h"

Interaction::Interaction()
{
 // l'interaction prend la date courante dans son attribut DateI
  Date d;
  this->DateI=d;
}

/*! le constructeur paramétrique affecte les paramètres aux attributs de classe sauf la date qui est affecté comme au constructeur par défaut*/

Interaction::Interaction(const std::string &contI,gestionTodo &list)
{

    this-> ContenuI=contI;

    this->DateI.ddmmyy();
    this->ListeIToDo=list;
}

std::string Interaction::getContI() const
{
    return this-> ContenuI;
}

std::string Interaction::getDateI()
{
    return this->DateI.ddmmyy();
}

gestionTodo Interaction::getListeIToDo() const
{
    return this->ListeIToDo;
}

void Interaction::setContenuI(const std::string &cI)
{
    this->ContenuI=cI;
}

void Interaction::setDateI(const Date &dI)
{
    this->DateI=dI;
}

void Interaction::setListeIToDo(const gestionTodo ListeITodo)
{
    this->ListeIToDo=ListeITodo;
}

std::string Interaction::afficheI()
{
    std::string s="";
    s=    "Contenu de l'interaction de ce contact: "+this->getContI()+"\n"
               +"Date : "+"\n"+this->getDateI()+"\n"
           +"taches :"+"\n"+this->ListeIToDo.afficheTousTodo()+"\n";
    return s;
}
