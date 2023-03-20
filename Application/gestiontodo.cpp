 /**
     * @file gestiontodo.cpp
 */
#include "gestiontodo.h"

gestionTodo::gestionTodo()
{
}

gestionTodo::~gestionTodo(){
    this->GestionTodoo.clear();
}

std::list<Todo>gestionTodo::getGestionTodoo()
{
    return this->GestionTodoo;
}

void gestionTodo::setGestionTodoo(const std::list<Todo> GestionTodoo)
{
    this->GestionTodoo=GestionTodoo;
}

void gestionTodo::addTodo(const Todo &i)
{
    GestionTodoo.push_back(i);//ajoute un todo
}
  
 void gestionTodo::removetodo(const Todo &i)
 {
    bool verif=false;
    auto j=GestionTodoo.begin();//debut de la liste
    while(verif==false && j!=GestionTodoo.end())
    {

            if(j->getContenu()==i.getContenu() && j->getDate()==i.getDate()) // comapraison du contenu et de la date des deux todo
        {
            verif=true;  // mettre vrai au verif pour arrêter la boucle 
            GestionTodoo.erase(j);//supprime un todo
        }
            else
             j++;
     }
 }

 std::string gestionTodo::afficheTousTodo()
{
    for(auto i=GestionTodoo.begin();i!=GestionTodoo.end();i++)
    {
        this-> inc=this->inc+ i->affiche();  //on appelle la fonction affiche()de la classe todo
        this->inc=this->inc+"\n";

    }
    return this->inc;

}
