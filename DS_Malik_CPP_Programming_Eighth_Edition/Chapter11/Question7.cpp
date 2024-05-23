#include <iostream>
#include "Question6.h"
using namespace std;

dateType::dateType() : month(0), day(0), year(0) {}

dateType::dateType(int m, int d, int y) : month(m), day(d), year(y) {}

void dateType::setMonth(int m) {
    if (m >= 1 && m <= 12) {
        month = m;
    } else {
        cout << "Invalid month" << endl;
    }
}

void dateType::setDay(int d) {
    if (d >= 1 && d <= 31) {
        day = d;
    } else {
        cout << "Invalid day" << endl;
    }
}

void dateType::setYear(int y) {
    if (y >= 1900 && y <= 9999) {
        year = y;
    } else {
        cout << "Invalid year" << endl;
    }
}

int dateType::getMonth() const { return month; }

int dateType::getDay() const { return day; }

int dateType::getYear() const { return year; }

int dateType::daysInMonth(int month, int year) const {
    switch(month) {
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 31;
    }
}

int dateType::daysInCurrentMonth() const {
    return daysInMonth(month, year);
}

int dateType::daysPassedInYear() {
    int daysPassed = day;
    for (int i = 1; i < month; ++i) {
        daysPassed += daysInMonth(i, year);
    }
    return daysPassed;
}

int dateType::remainingDaysInYear() {
    int remainingDays = isLeapYear(year) ? 366 : 365;
    remainingDays -= daysPassedInYear();
    return remainingDays;
}

void dateType::addDays(int daysToAdd) {
    int newDays = day + daysToAdd;
    int newMonth = month;
    int newYear = year;
    
    while (newDays > daysInMonth(newMonth, newYear)) {
        newDays -= daysInMonth(newMonth, newYear);
        newMonth++;
        if(newMonth > 12){
            newYear++;
            newMonth = 1;
        }
    }
    
    day = newDays;
    month = newMonth;
    year = newYear;
}

bool dateType::isLeapYear(int year) const {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}