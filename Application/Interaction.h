 /**
     * @file Interaction.h
 */
#ifndef INTERACTION_H
#define INTERACTION_H

#include<string>
#include<iostream>
#include<list>

#include"gestiontodo.h"
#include"Todo.h"
#include"Date.h"

/**
     * @class Interaction
     * @brief définie une interaction d'un contact
     */

class Interaction
{
public:
    
    //Attributs de la classe
    std::string ContenuI;
    Date DateI;
    gestionTodo ListeIToDo;

    //Constructeurs
    Interaction();
    Interaction(const std::string& contI, gestionTodo& List);

    //getters
    std::string getContI() const;
    std::string getDateI();
    gestionTodo getListeIToDo() const;

    //setters
    void setContenuI(const std::string& cI);
    void setDateI(const Date& dI);
    void setListeIToDo(const gestionTodo ListeITodo);

     /**
     * @fn afficheI
     * @brief affiche une interaction
     */
    std:: string afficheI();
};
#endif // INTERACTION_H
