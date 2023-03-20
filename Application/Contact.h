 /**
     * @file Contact.h
 */
#ifndef CONTACT_H
#define CONTACT_H
#include"Date.h"
#include"Interaction.h"
#include<string.h>
#include<list>
#include<iostream>

using namespace std;

  /**
     * @class Contact
     * @brief la class Contact a pour rôle de décrire la fiche d'un contact
     */

class Contact
{

private:
      
    /*!Attributs de classe*/
    string nom;
    string prenom;
    string email;
    string telephone;
    string entreprise;
    string photo;

    /*!Liste contenant toutes les interactions d'un contact*/
    list <Interaction> ListeInteraction;

    /*!Attributs qui définient la date de création et de modification d'un contact*/
    Date DateCreation;
    Date DateModif;

public:

    /*! Constructeur par défaut*/
    Contact();

    /*!Constructeur paramétrique*/
    Contact(const string& p,const string& n,const string& entreprise,
            const string& email,const string& tel, const string& photo);

    /*!Déconstructeur*/
    ~Contact();

    /*!Modificateur d'accès*/
    void setNom(const string& n);
    void setPrenom(const string& p);
    void setEmail(const string& email);
    void setTelephone(const string& tel);
    void setEntreprise(const string& entreprise);
    void setPhoto(const string& photo);
    void setDateModif(Date& dm);
    void setDateCreation(Date & dsupp);
    void setListeInteraction(const list<Interaction> &value);

    string getNom() const;
    string getPrenom() const;
    string getEmail() const;
    string getTelephone() const;
    string getEntreprise() const;
    string getPhoto() const;
    string getDateCreation() ;
    string getDateModif() ;
    list<Interaction> getListeInteraction() const;

    void ajoutInteracion(const Interaction &i);
     /**
     * @fn AfficheInterComplet
     * @return toutes les interactions d'un contact
     */
    string afficheInterComplet();
      /**
     * @fn SupprimerInteraction
     * @brief Supprimer une interaction de la liste d'interactions d'un contact
     */
    void supprimerInteraction( Interaction i);

    bool operator==(const Contact& c);
      /**
     * @fn affiche
     * @brief affiche le contact dans le terminal
     */
    string affiche();

      /**
     * @fn ModifierContact
     * @brief elle reçoit les paramètres nécessaires pour modifier un contact et elle fait appel au modificateur d'accès SET.
     */
    void ModifierContact(const string &NewNom, const string &NewPrenom, const string &NewEntreprise,
         const string &NewEmail, const string &NewTel, const string &NewPhoto);


};
#endif // CONTACT_H
