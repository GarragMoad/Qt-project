#ifndef AJOUTTAG_H
#define AJOUTTAG_H

#include <QWidget>
using namespace std;
#include <string>
#include "Todo.h"

/**
* @class Affichertag
* @brief est un widget qui permet d'afficher un tag selon la date
*/
    namespace Ui {
    class AjoutTag;
    }

class AjoutTag : public QWidget
{
    Q_OBJECT

    public:
        explicit AjoutTag(QWidget *parent = nullptr);
        ~AjoutTag();

    private slots:
        void on_pushButton_clicked();
    signals:
        void ajoutTag(string *,Todo*);
        /**
       * @fn ajoutTag
       * @brief signal qui envoie un todo et une chaines de caractère
       * @param chaine de caractère présente l'ID de l'interaction où on devrait affecter le todo présent en deuxième param
       */
    private:
        Ui::AjoutTag *ui;
};

#endif // AJOUTTAG_H
