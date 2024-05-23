#include <iostream>
#include<Question6.h>
using namespace std;

class extDateType : public dateType {
private:
    string monthString;

    string monthToString(int m) const {
        switch (m) {
            case 1: return "January";
            case 2: return "February";
            case 3: return "March";
            case 4: return "April";
            case 5: return "May";
            case 6: return "June";
            case 7: return "July";
            case 8: return "August";
            case 9: return "September";
            case 10: return "October";
            case 11: return "November";
            case 12: return "December";
            default: return "Invalid Month";
        }
    }

public:
    extDateType() : dateType(), monthString("") {}

    extDateType(int m, int d, int y) : dateType(m, d, y), monthString(monthToString(m)) {}

    void setMonth(int m) {
        dateType::setMonth(m);
        monthString = monthToString(m);
    }

    string getMonthString() const {
        return monthString;
    }

    void printDate() const {
        cout << monthString << " " << getDay() << ", " << getYear() << endl;
    }
};
