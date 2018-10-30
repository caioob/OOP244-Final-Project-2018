/**********************************************************
 * Name:Caio Leonardo Bueno Basaglia
 * Student ID:152593174

 * Section: SSF
 * Seneca email:clbueno-basaglia@myseneca.ca
 **********************************************************/
#include "Date.h"
#include <iostream>

namespace aid {

	// number of days in month mon and year year
	//
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}
    Date::Date(){
        year = 0;
        month = 0;
        day = 0;
        error = no_error;
    }
    Date::Date(int year_, int month_, int day_){
        int comparator_ = year_ * 372 + month_ *31 + day;
        if(year_ < max_year && year_ > min_year && month_< 12 && month_ > 1 && day_ > 0 && day_ < mdays(month_, day_)){
            year - year_;
            month = month_;
            day = day_;
            error = no_error;
        }
        if (year_ > max_year || year_ < min_year){
            year = 0;
            month = 0;
            day = 0;
            error = year_error;
            comparator = 0;
        }
        else if (month_ > 12 || month_ < 1){
            year = 0;
            month = 0;
            day = 0;
            error = mon_error;
            comparator = 0;
        }
        else if (day_ < 1 || day_ > mdays(month_, day_)){
            year = 0;
            month = 0;
            day = 0;
            error = day_error;
            comparator = 0;
        }
        else if (comparator_ < min_date){
            year = 0;
            month = 0;
            day = 0;
            error = past_error;
            comparator = 0;
        }
        else {
            year = year_;
            month = month_;
            day = day_;
            error = no_error;
            comparator = comparator_;
        }

    }
    bool Date::bad() const{
        if (error == no_error){
            return true;
        }
        else{
            return false;
        }
    }
}


