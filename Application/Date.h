/**
     * @file Date.h
 */
#ifndef DATE_H
#define DATE_H

#include<string>
#include<time.h>

 /**
     * @class Date
     * @brief la class Date permet de stocker soit la date courante soit une date passée en parmètre dans ses attributs
     */

class Date
{
private:
    struct tm* d;

    int day;
    int month;
    int year;


public:
    Date();
    Date(const int d,const int m,const int y);



    void setDay(int d);
    void setMonth(int m);
    void setYear(int y);

    
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    /**
     * @fn ddmmyy
     * @return la date en forme de chaine de caracteres
     */
    std::string ddmmyy();

};

#endif // DATE_H
