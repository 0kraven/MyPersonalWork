
#include<iostream>
#include<Question6.h>
using namespace std;

int main() {
    dateType date(2, 10, 2020);
    date.setMonth(2);
    date.setDay(28);
    date.setYear(2023);

    cout << "Date: " << date.getMonth() << "-" << date.getDay() << "-" << date.getYear() << endl;
    cout << "Is leap year? " << (date.isLeapYear(date.getYear()) ? "Yes." : "No") << endl;
    cout << "Number of days in the month: " << date.daysInCurrentMonth() << endl;
    cout << "Number of days passed in the year: " << date.daysPassedInYear() << endl;
    cout << "Number of days remaining in the year: " << date.remainingDaysInYear() << endl;
    date.addDays(25);
    cout << "The days to be added are 25. The new date is: " << date.getMonth() << "-" << date.getDay() << "-" << date.getYear() << endl;

    return 0;
}