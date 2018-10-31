/**********************************************************
 * Name:Caio Leonardo Bueno Basaglia
 * Student ID:152593174

 * Section: SSF
 * Seneca email:clbueno-basaglia@myseneca.ca
 **********************************************************/
#include "Date.h"
#include <iostream>
using namespace std;
namespace aid {

	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

    int Date::comparatorCalc(int year_, int month_, int day_){
        int comparator_;
        comparator_ = year_ * 372 + month_ *31 + day_;
        return comparator_;
    }

    Date::Date(){
        year = 0;
        month = 0;
        day = 0;
        error = NO_ERROR;
        comparator = comparatorCalc(year, month, day);
    }

    Date::Date(int year_, int month_, int day_){
        int comparator_ = year_ * 372 + month_ *31 + day;
        if (year_ > max_year || year_ < min_year){
            year = 0;
            month = 0;
            day = 0;
            error = YEAR_ERROR;
            comparator = comparatorCalc(year, month, day);
        }
        else if (month_ > 12 || month_ < 1){
            year = 0;
            month = 0;
            day = 0;
            error = MON_ERROR;
            comparator = comparatorCalc(year, month, day);
        }
        else if (day_ < 1 || day_ > mdays(month_, year_)){
            year = 0;
            month = 0;
            day = 0;
            error = DAY_ERROR;
            comparator = comparatorCalc(year, month, day);
        }
        else if (comparator_ < min_date){
            year = 0;
            month = 0;
            day = 0;
            error = PAST_ERROR;
            comparator = comparatorCalc(year, month, day);
        }
        else {
            year = year_;
            month = month_;
            day = day_;
            error = NO_ERROR;
            comparator = comparatorCalc(year, month, day);
        }

    }
    void Date::errCode(int errcode){
        if (errcode == 0){
            error = NO_ERROR;
        }
        else if (errcode == 1){
            error = CIN_FAILED;
        }
        else if (errcode == 2){
            error = DAY_ERROR;
        }
        else if (errcode == 3){
            error = MON_ERROR;
        }
        else if (errcode == 4){
            error = YEAR_ERROR;
        }
        else if (errcode == 5){
            error = PAST_ERROR;
        }
    }


    bool Date::operator == (const Date& rhs){
        if (comparator == rhs.comparator){
            return true;
        }
        else{
            return false;
        }

    }

    bool Date::operator!=(const Date& rhs){

        if(comparator != rhs.comparator){
            return true;
        }
        else{
            return false;
        }
    }

    bool Date::operator<(const Date& rhs){

        if (comparator < rhs.comparator){
            return true;
        }
        else{
            return false;
        }
    }

    bool Date::operator>(const Date& rhs){

        if (comparator > rhs.comparator){
            return true;
        }
        else {
            return false;
        }
    }

    bool Date::operator<=(const Date& rhs){

        if(comparator <= rhs.comparator){
            return true;
        }
        else{
            return false;
        }
    }

    bool Date::operator>=(const Date& rhs){

        if(comparator >= rhs.comparator){
            return true;
        }
        else{
            return false;
        }
    }

    int Date::errCode() const{
        int answer = 0;
        if (error == NO_ERROR){
            answer = 0;
        }
        else if(error == CIN_FAILED){
            answer = 1;
        }
        else if(error == DAY_ERROR){
            answer = 2;
        }
        else if(error == MON_ERROR){
            answer = 3;
        }
        else if(error == YEAR_ERROR){
            answer = 4;
        }
        else if(error == PAST_ERROR){
            answer = 5;
        }
        return answer;
        //return error;
    }

    bool Date::bad() const{
        if (error == NO_ERROR){
            return false;
        }
        else{
            return true;
        }
    }

    std::istream& Date::read(std::istream& istr){
        int year_, month_, day_, comparator_;
        char dash = '/';
        cin >> year_ >> dash >> month_ >> dash >> day_;
        comparator_ = comparatorCalc(year_, month_, day_);

        if(istr.fail() == true){
            error = CIN_FAILED;
        }
        else {
            if (year_ < min_year || year_ > max_year ){
                error = YEAR_ERROR;
            }
            else if (month_ > 12 || month_ < 1){
                error = MON_ERROR;
            }
            else if (day_ < 1 || day_ > mdays(month_, year_)){
                error = DAY_ERROR;
            }
            else if (min_date > comparator_){
                error = PAST_ERROR;
            }
            else{
                error = NO_ERROR;
                year = year_;
                month = month_;
                day = day_;
                comparator = comparator_;
            }
        }
        return istr;
    }

    std::ostream& Date::write(std::ostream& ostr) const{
        cout << aid::Date::year << "/";
        cout.width(2);
        cout.fill('0');
        cout << aid::Date::month << "/";
        cout.width(2);
        cout.fill('0');
        cout << aid::Date::day;
        return ostr;
    }
}

std::ostream& operator << (std::ostream& ostr, aid::Date& date){
    return date.write(ostr);
}

std::istream& operator >> (std::istream& istr, aid::Date& date){
    return date.read(istr);
}

