 /**
     * @file Contact.cpp
 */
#include "Contact.h"
using namespace std;

 /*!implémenattion des constructeurs*/
Contact::Contact(const string &p, const string &n, const string &entreprise,
                 const string &email, const string &tel, const string &photo)
{
    this->setPrenom(n);
    this->setNom(p);
    this->setEntreprise(entreprise);
    this->setEmail(email);
    this->setTelephone(tel);
    this->setPhoto(photo);
    this->DateCreation.ddmmyy();
}

Contact::Contact()
{
    this->nom="";
    this->prenom="";
    this->email="";
    this->telephone="";
    this->entreprise="";
    this->photo="";
    this->DateCreation.ddmmyy();
}

 /*déconstructeur de la classe*/
Contact::~Contact(){
    ListeInteraction.clear();
}

 /*!GETTERS ET SETTERS*/
void Contact::setNom(const string &n)
{
    this->nom=n;
}

void Contact::setPrenom(const string &p)
{
    this->prenom=p;
}

void Contact::setEmail(const string &email)
{
    this->email=email;
}

void Contact::setTelephone(const string& tel)
{
    this->telephone=tel;
}

void Contact::setEntreprise(const string &entreprise)
{
    this->entreprise=entreprise;
}

void Contact::setPhoto(const string &photo)
{
    this->photo=photo;
}

void Contact::setDateCreation(Date &dsupp)
{
    this->DateCreation=dsupp;

}
void Contact::setDateModif(Date &dm)
{
    this->DateModif=dm;
}
//Getters
string Contact::getNom() const
{
    return this->nom;
}

string Contact::getPrenom() const
{
    return this->prenom;
}

string Contact::getEmail() const
{
    return this->email;
}

string Contact::getTelephone() const
{
    return this->telephone;
}

string Contact::getEntreprise() const
{
    return this->entreprise;
}

string Contact::getPhoto() const
{
    return this->photo;
}


string Contact::getDateCreation()
{
    return this->DateCreation.ddmmyy();
}

string Contact::getDateModif()
{
    return this->DateModif.ddmmyy();
}
list<Interaction> Contact::getListeInteraction() const
{
    return ListeInteraction;
}

void Contact::setListeInteraction(const list<Interaction> &value)
{
    ListeInteraction = value;
}


      /**
     * @fn Ajouter Interaction
     * @param i 
     * @brief l'interaction ajoutée à la liste d'interaction du contact
     */

void Contact::ajoutInteracion(const Interaction &i)
{
   this->ListeInteraction.push_back(i);
}
 /**
     * @fn SupprimerInteraction
     * @param j 
     * @brief Interaction supprimée
     */
void Contact::supprimerInteraction( Interaction j)
{

    for( auto i=ListeInteraction.begin();i!=ListeInteraction.end();i++)
    {
        if(i->getContI()==j.getContI())
            ListeInteraction.erase(i);
     }

}
 /**
     * @fn Ajouter AfficheInterComplet
     * @return toutes les inetractions d'un contact en chaine de caractère
     */
string Contact:: afficheInterComplet(){

    string s="";
    for(auto i=ListeInteraction.begin();i!=ListeInteraction.end();i++)
    {
        s= s + i->afficheI();
    }
    return s;
}



string Contact::affiche()
{
    string sortie;
    string out=afficheInterComplet();
    sortie=sortie+"{";
    sortie=sortie+"NOM :"+ this->getNom()+"\n";;
    sortie=sortie+"PRENOM :"+this->getPrenom()+"\n";
    sortie=sortie+"ENTREPRISE :"+this->getEntreprise()+"\n";
    sortie=sortie+"MAIL :"+this->getEmail()+"\n";
    sortie=sortie+"TELEPHONE :"+this->getTelephone()+"\n";
    sortie=sortie+"PHOTO :"+this->getPhoto()+"\n";
    sortie=sortie+"DATE DE CREATION :"+this->getDateCreation()+"}"+"\n\n";
    sortie=sortie+out;
    return sortie;
}
  
void Contact::ModifierContact(const string &NewNom, const string &NewPrenom, const string &NewEntreprise,
                          const string &NewEmail, const string &NewTel, const string &NewPhoto)
{
    this->setNom(NewNom);
    this->setPrenom(NewPrenom);
    this->setEntreprise(NewEntreprise);
    this->setEmail(NewEmail);
    this->setTelephone(NewTel);
    this->setPhoto(NewPhoto);

    /*Affecter la date courante à l'attribut DateModif du l'objet Conatct*/
    Date time;
    this->setDateModif(time);
}

bool Contact::operator==(const Contact& c)
{
    return this->getNom()==c.getNom();
}
