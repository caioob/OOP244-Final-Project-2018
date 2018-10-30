/**********************************************************
 * Name:Caio Leonardo Bueno Basaglia
 * Student ID:152593174

 * Section: SSF
 * Seneca email:clbueno-basaglia@myseneca.ca
 **********************************************************/
#ifndef AMA_DATE_H
#define AMA_DATE_H

namespace aid {

        const int min_year = 2018;
        const int max_year = 2038;
        const int min_date = 751098;
    class Date {
        int year;
        int month;
        int day;
        int comparator;
        int error;
        int no_error = 0;//valid data
        int cin_failed = 1;//istream failed on entering data
        int day_error = 2;//value of day invalid
        int mon_error = 3;//value of month invalid
        int year_error = 4;//value of year invalid
        int past_error = 5;//invalid date
        int mdays(int, int)const;
        int errCode(int);
    public:
        Date();
        Date(int, int, int);
        bool operator == (const Date&);
        bool operator != (const Date&);
        bool operator < (const Date&);
        bool operator > (const Date&);
        bool operator <= (const Date&);
        bool operator >= (const Date&);
        int errCode () const;
        bool bad() const;
};





}
#endif
