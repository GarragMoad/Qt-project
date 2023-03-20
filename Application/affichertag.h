#ifndef AFFICHERTAG_H
#define AFFICHERTAG_H

#include <QWidget>
using namespace std;
#include <string>
    /**
   * @class Affichertag
   * @brief est un widget qui permet d'afficher un tag selon la date
   */
namespace Ui {
    class AfficherTag;
}

class AfficherTag : public QWidget
{
    Q_OBJECT

    public:
        explicit AfficherTag(QWidget *parent = nullptr);
        ~AfficherTag();

    private slots:
        void on_pushButton_clicked();

    signals:
        void afficherT(string *);
        /**
       * @fn afficherT
       * @brief est un signal qui va déclancher après un slot qui recherche le todo par son nom
       */
    private:
        Ui::AfficherTag *ui;
};

#endif // AFFICHERTAG_H
