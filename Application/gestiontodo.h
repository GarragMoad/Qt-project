 /**
     * @file gestiontodo.h
 */
#ifndef GESTIONTODO_H
#define GESTIONTODO_H

#include<list>
#include "Todo.h"

    /**
     * @class gestionTodo
     * @brief gère tous les todos
     */

class gestionTodo
{
private:
    std::list<Todo> GestionTodoo;
    std::string inc;

public:
    gestionTodo();
    ~gestionTodo();

    std::list<Todo> getGestionTodoo();

    void setGestionTodoo(const std::list<Todo> GestionTodoo);
/**
     * @fn addTodo
     * @param i
     * @brief ajout du todo i dans la liste GestionTodoo
     */
    void addTodo(const Todo& i);

    /**
     * @fn removetodo
     * @param i
     * @brief supprime un todo de la liste
     */

    void removetodo(const Todo& i);

    /**
     * @fn afficheTousTodo
     *@return touts les todo en chaine de caractère
     */
    std::string afficheTousTodo();
};

#endif // Todo_H
