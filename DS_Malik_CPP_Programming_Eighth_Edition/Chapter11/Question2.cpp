#include <iostream>
using namespace std;
class dateType {
public:
    dateType(int m = 1, int d = 1, int y = 1900);

    void setDate(int m, int d, int y);
    void setMonth(int m);
    void setDay(int d);
    void setYear(int y);


    int getMonth() const;
    int getDay() const;
    int getYear() const;

    bool isLeapYear(int year) const;

    void printDate() const;

private:
    int month;
    int day;
    int year;
};
dateType::dateType(int m, int d, int y) {
    setDate(m, d, y);
}
void dateType::setDate(int m, int d, int y) {

    if (m < 1 || m > 12) {
        cout<< "Invalid month. Setting to default (1)" << endl;
        m = 1;
    }


    if (d < 1 || d > 31) {
        cout << "Invalid day. Setting to default (1)" << endl;
        d = 1;
    }


    if (y < 1900 || y > 2100) {
        cout << "Invalid year. Setting to default (1900)" << endl;
        y = 1900;
    }

    if ((m == 4 || m == 6 || m == 9 || m == 11) && (d > 30)) {
        cout << "Invalid day for this month. Setting to default (1)" << endl;
        d = 1;
    }
    if (m == 2) {
        if (isLeapYear(y) && d > 29) {
            cout << "Invalid day for February in a leap year. Setting to default (1)" << endl;
            d = 1;
        }
        if (!isLeapYear(y) && d > 28) {
            cout << "Invalid day for February. Setting to default (1)" << endl;
            d = 1;
        }
    }


    month = m;
    day = d;
    year = y;
}

void dateType::setMonth(int m) {
    setDate(m, day, year);
}
void dateType::setDay(int d) {
    setDate(month, d, year);
}
void dateType::setYear(int y) {
    setDate(month, day, y);
}

int dateType::getMonth() const {
    return month;
}

int dateType::getDay() const {
    return day;
}

int dateType::getYear() const {
    return year;
}
bool dateType::isLeapYear(int year) const {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
void dateType::printDate() const {
    cout << month << "/" << day << "/" << year << endl;
}

int main() {
    dateType date(2, 29, 2024); 
    date.printDate();

    dateType date2(2, 29, 2023);
    date2.printDate();

    return 0;
}
