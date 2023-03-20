/**
     * @file GestionContact.h
 */
#ifndef GestionContact
#define GESTIONCONTACT_H
#include"Contact.h"
using namespace std;
#include<string>
#include<list>
#include<iostream>


  /**
     * @class Gestioncontact
     * @brief la class Gestioncontact gère l'ensemble des contacts
     */
class Gestioncontact
{
private:
    /*!ListeContact contient touts les contacts*/

    list<Contact> ListeContact;

    /*!resultRecherche est une liste contenant les contacts recherchés par l'utilisateur en appelant la méthode reherche*/

    list<Contact> resultRecherche;

    /*!attributs qui stockent le dernier contact supprimé et sa date de suppression*/
    
    string DateSupprimees;
    string NomContactSupp;

public:

    /*!Constructeurs et déconstructeurs*/

    Gestioncontact();
    Gestioncontact(list<Contact> c );
    ~Gestioncontact();

    void AjouterContact(Contact c);

    /**
     * @fn SupprimerContact
     * @brief elle enlève le contact c de la liste des contacts 
     */

    void SupprimerContact(Contact c);

    /**
     * @fn DateSuppression
     * @return toutes les interactions d'un contact
     */

    void DateSuppression(string nom);

    /**
     * @fn Recherche
     * @return affiche les contacts demandés par l'utilisateur
     */

    list<Contact> Recherche(int rep,string entree);

    /**
     * @fn AfficheContacts
     * affiche l'ensemble de contacts
     */

    void AfficheContacts();

    /*! GETTERS SETTERS*/

    string getDateSupprimees() const;
    void setDateSupprimees(const string &value);
    string getNomContactSupp() const;
    void setNomContactSupp(const string &value);
    list<Contact> getResultRecherche() const;
    void setResultRecherche(const list<Contact> &value);
    list<Contact> getListRecherche() const;
    void setListRecherche(const list<Contact> &value);

};
#endif // GESTIONCONTACT
