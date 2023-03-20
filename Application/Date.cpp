/**
     * @file Date.cpp
 */
#include "Date.h"

 /**
     * @fn Constructeur par défaut
     * @brief affecter la date courante aux attributs de la structure d de type tm (venant de la classe time.h)
     */
Date::Date()
{
    time_t tn=time(0);
    this->d=localtime(&tn);
    d->tm_mon=d->tm_mon+1;
    d->tm_year=d->tm_year+1900;
}
Date::Date(const int d,const int m,const int y)
{
    this->day=d;
    this->month=m;
    this->year=y;
}

void Date::setDay(int d)
{
    this->day=d;
}

void Date::setMonth(int m)
{
    this->month=m;
}

void Date::setYear(int y)
{
    this->year=y;
}

int Date::getDay() const
{
    return this->day;
}

int Date::getMonth() const
{
    return this->month;
}

int Date::getYear() const
{
    return this->year;
}

std::string Date::ddmmyy()
{
    std::string date="";
        if (d->tm_mday <= 9)
        {
            date = "0"+std::to_string(d->tm_mday);
        }
        else
        {
            date = std::to_string(d->tm_mday);
        }
        date += "/";
        if (d->tm_mon <= 9)
        {
            date = date+ "0"+std::to_string(d->tm_mon);
        }
        else
        {
            date = date + std::to_string(d->tm_mon);
        }
        date += "/";
        date +=std::to_string(d->tm_year);

        return date;
}
