#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QFormLayout>
#include<QLineEdit>
#include<QPushButton>
#include "qstring.h"
#include"Contact.h"

/**
* @class form
* @brief est un widget qui permet à l'utilisateur de créer un contact
*/

class Form : public QWidget
{
    Q_OBJECT

    public:
        explicit Form(QWidget *parent = nullptr);
        ~Form();



    private:
    /**
    * ...  déclaration des élements du widget (formulaire)   ...
    */
        QFormLayout *formulaire;
        QLineEdit *nameEdit;
        QLineEdit *PrenomEdit;
        QLineEdit *phoneEdit;
        QLineEdit *emailEdit;
        QLineEdit *entrepriseEdit;
        QLineEdit *PhotoEdit;
        QVBoxLayout *mainLayout;
        QPushButton * valider;

    signals:
        void rajoutC(Contact *);
        /**
       * @fn rajoutC
       * @brief signal qui envoie  uun contact
       * @param le contact en paramètre est le contact créer par l'utilisateur en entrant ses cordonnées dans les champs du widget
       */


    public slots:
    void RecupInfos();
        /**
       * @fn rajoutC
       * @brief signal qui envoie  uun contact
       * @param le contact en paramètre est le contact créer par l'utilisateur en entrant ses cordonnées dans les champs du widget
       */


};

#endif // FORM_H
