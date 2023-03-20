 /**
     * @file Todo.h
 */
#ifndef TODO_H
#define TODO_H

#include"Date.h"
#include<iostream>
#include<string>
#include<list>

/**
     * @class Todo
     * @brief définit la structure d'un todo
     */
class Todo
{
private:

     //attributs de la classe
     std::string Contenu;
     Date temps;
     std::string date;

public:

 Todo();
 Todo(const std::string& C, const std::string& d);

    //setters
    void setContenu(const std::string& contTd);
    void setdate(const std::string& dToDo);

    //getters
    std::string getContenu() const;
    std::string getDate() const;
   
       /**
     * @fn affiche
     * @return affiche le todo en chaine de caractère
     */
     std::string affiche();
 

};
#endif // TODO_H
