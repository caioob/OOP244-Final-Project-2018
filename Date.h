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
        int NO_ERROR = 0;//valid data
        int CIN_FAILED = 1;//istream failed on entering data
        int DAY_ERROR = 2;//value of day invalid
        int MON_ERROR = 3;//value of month invalid
        int YEAR_ERROR = 4;//value of year invalid
        int PAST_ERROR = 5;//invalid date
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
