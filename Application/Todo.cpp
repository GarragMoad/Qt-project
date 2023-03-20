 /**
     * @file Todo.cpp
 */
#include "Todo.h"

/*!dans le constructeur par défaut on affecte la date courante à l'attribut date de la classe*/
Todo::Todo(){

    Date d;
    setdate(d.ddmmyy());
}


Todo::Todo(const std::string& C, const std::string& d)
{
    this->Contenu= C;
    this->date="";
    if(d=="")
       this->date+=temps.ddmmyy(); // recuperation de la date courante dans l'attribur date si le paramètre d est une chaine vide
    else
       this->date+=d; // sinon on passe à l'attribut de la classe le paramètre d
}
void Todo::setContenu(const std::string &contTodo)
{
    this->Contenu=contTodo;
}

void Todo::setdate(const std::string &d)
{
    this->date=d;
}

std::string Todo::getContenu() const
{
    return this->Contenu;
}

std::string Todo::getDate() const
{
    return this->date;
}

 
std::string Todo::affiche()
{
    std::string a="@todo "+this->getContenu();
    std:: string b="@date"+this->getDate();
    std::string ab= a+" "+b;
    return ab;
}


