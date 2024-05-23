#ifndef DATETYPE_H
#define DATETYPE_H

class dateType {
    private:
        int month;
        int day;
        int year;

        int daysInMonth(int month, int year) const;
    
    public:
        dateType();
        dateType(int m, int d, int y);
        
        void setMonth(int m);
        void setDay(int d);
        void setYear(int y);
        
        int getMonth() const;
        int getDay() const;
        int getYear() const;
        
        int daysInCurrentMonth() const;
        int daysPassedInYear();
        int remainingDaysInYear();
        
        void addDays(int daysToAdd);
        bool isLeapYear(int year) const;
};

#endif
