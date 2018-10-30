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
        error = NO_ERROR;
    }
    Date::Date(int year_, int month_, int day_){
        int comparator_ = year_ * 372 + month_ *31 + day;
        if(year_ < max_year && year_ > min_year && month_< 12 && month_ > 1 && day_ > 0 && day_ < mdays(month_, day_)){
            year - year_;
            month = month_;
            day = day_;
            error = NO_ERROR;
        }
        if (year_ > max_year || year_ < min_year){
            year = 0;
            month = 0;
            day = 0;
            error = YEAR_ERROR;
            comparator = 0;
        }
        else if (month_ > 12 || month_ < 1){
            year = 0;
            month = 0;
            day = 0;
            error = MON_ERROR;
            comparator = 0;
        }
        else if (day_ < 1 || day_ > mdays(month_, day_)){
            year = 0;
            month = 0;
            day = 0;
            error = DAY_ERROR;
            comparator = 0;
        }
        else if (comparator_ < min_date){
            year = 0;
            month = 0;
            day = 0;
            error = PAST_ERROR;
            comparator = 0;
        }
        else {
            year = year_;
            month = month_;
            day = day_;
            error = NO_ERROR;
            comparator = comparator_;
        }

    }
    bool Date::operator == (const Date& rhs){
        if (year == rhs.year && day == rhs.day && month == rhs.month && comparator == rhs.comparator){
            return true;
        }
        else if (year == 0 || rhs.year == 0){
            return false;
        }
        else {
            return false;
        }
    }
    bool Date::operator!=(const Date& rhs){
        if (year != rhs.year && day != rhs.day && month != rhs.month && comparator != rhs.comparator){
            return true;
        }
        else if (year == 0 || rhs.year == 0){
            return false;
        }
        else {
            return false;
        }
    }
    bool Date::operator<(const Date& rhs){
        if (year < rhs.year && day < rhs.day && month < rhs.month && comparator < rhs.comparator){
            return true;
        }
        else if (year == 0 || rhs.year == 0){
            return false;
        }
        else {
            return false;
        }
    }
    bool Date::operator>(const Date& rhs){
        if (year > rhs.year && day > rhs.day && month > rhs.month && comparator > rhs.comparator){
            return true;
        }
        else if (year == 0 || rhs.year == 0){
            return false;
        }
        else {
            return false;
        }
    }
    bool Date::operator<=(const Date& rhs){
        if (year <= rhs.year && day <= rhs.day && month <= rhs.month && comparator <= rhs.comparator){
            return true;
        }
        else if (year == 0 || rhs.year == 0){
            return false;
        }
        else {
            return false;
        }
    }
    bool Date::operator>=(const Date& rhs){
        if (year >= rhs.year && day >= rhs.day && month >= rhs.month && comparator >= rhs.comparator){
            return true;
        }
        else if (year == 0 || rhs.year == 0){
            return false;
        }
        else {
            return false;
        }
    }
    int Date::errCode() const{
        if (error == NO_ERROR){
            return 0;
        }
        else if(error == CIN_FAILED){
            return 1;
        }
        else if(error == DAY_ERROR){
            return 2;
        }
        else if(error == MON_ERROR){
            return 3;
        }
        else if(error == YEAR_ERROR){
            return 4;
        }
        else if(error == PAST_ERROR){
            return 5;
        }
    }
    bool Date::bad() const{
        if (error == NO_ERROR){
            return true;
        }
        else{
            return false;
        }
    }
}


