#include <iostream>
#include <iomanip>
using namespace std;

class dayType {
private:
    string day;

public:
    dayType(string d = "") : day(d) {}

    void setDay(string d) {
        day = d;
    }

    string getDay() const {
        return day;
    }
};

class calendarType {
private:
    extDateType monthYear;
    dayType firstDay;

    int daysInMonth(int month, int year) const {
        switch (month) {
            case 4: case 6: case 9: case 11:
                return 30;
            case 2:
                return monthYear.isLeapYear(year) ? 29 : 28;
            default:
                return 31;
        }
    }

    void printMonth() const {
        cout << "-----------------------------" << endl;
        cout << " Sun Mon Tue Wed Thu Fri Sat" << endl;
        cout << "-----------------------------" << endl;

        int startDay = 1;
        int totalDays = daysInMonth(monthYear.getMonth(), monthYear.getYear());
        int currentDay = 1;

        // Finding the start day of the month
        while (firstDay.getDay() != "Sun" && startDay <= 7) {
            cout << "    ";
            startDay++;
        }

        // Printing the calendar
        while (currentDay <= totalDays) {
            if (startDay > 7) {
                cout << endl;
                startDay = 1;
            }

            if (currentDay < 10)
                cout << "   " << currentDay << " ";
            else
                cout << "  " << currentDay << " ";

            currentDay++;
            startDay++;
        }
        cout << endl;
    }

public:
    calendarType(int month, int year, string firstDay) : monthYear(month, 1, year), firstDay(firstDay) {}

    void printCalendar() const {
        cout << endl;
        cout << setw(19) << monthYear.getMonthString() << " " << monthYear.getYear() << endl;
        cout << endl;
        printMonth();
        cout << endl;
    }
};

int main() {
    calendarType calendar(5, 2024, "Thu");
    calendar.printCalendar();

    return 0;
}
