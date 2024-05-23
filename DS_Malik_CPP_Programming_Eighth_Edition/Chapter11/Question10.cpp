#include <iostream>
#include <iomanip>

class calendarType {
private:
    int month;
    int year;

public:
    // Constructor
    calendarType(int m = 1, int y = 1900) : month(m), year(y) {}

    // Function to set the month and year
    void setDate(int m, int y) {
        month = m;
        year = y;
    }

    // Function to get the month
    int getMonth() const {
        return month;
    }

    // Function to get the year
    int getYear() const {
        return year;
    }

    // Function to print the calendar for a specific month
    void printMonthCalendar() const {
        std::string monthNames[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        std::cout << std::setw(22) << monthNames[month - 1] << " " << year << std::endl;
        std::cout << " Sun Mon Tue Wed Thu Fri Sat" << std::endl;

        // Get the day of the week for the first day of the month
        int startDay = getStartDayOfMonth(month, year);

        // Print spaces for the days before the first day of the month
        for (int i = 0; i < startDay; ++i) {
            std::cout << "    ";
        }

        // Print the days of the month
        for (int day = 1; day <= getNumDaysInMonth(month, year); ++day) {
            std::cout << std::setw(4) << day;
            if ((startDay + day) % 7 == 0 || day == getNumDaysInMonth(month, year)) {
                std::cout << std::endl;
            }
        }
    }

    void printYearCalendar(){
        std::cout << std::setw(30) << year << std::endl;
        for (int month = 1; month <= 12; ++month) {
            setDate(month, year);
            printMonthCalendar();
            std::cout << std::endl;
        }
    }

private:
    bool isLeapYear(int y) const {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int getNumDaysInMonth(int m, int y) const {
        int daysInMonth[] = {31, (isLeapYear(y) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return daysInMonth[m - 1];
    }

    int getStartDayOfMonth(int m, int y) const {
        int startDay[] = {2, 5, 5, 1, 3, 6, 1, 4, 0, 2, 5, 0};
        int century = y / 100;
        int yearInCentury = y % 100;
        int index = (yearInCentury + yearInCentury / 4 + century / 4 - 2 * century + 26 * (m + 1) / 10 + startDay[m - 1]) % 7;
        return index >= 0 ? index : index + 7;
    }
};

int main() {
    calendarType calendar(9, 2019);
    calendar.printMonthCalendar();

    return 0;
}
