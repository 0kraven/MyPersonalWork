#include <iostream>

using namespace std;

const int MAX_ENTRIES = 500;
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

class AddressType {
public:
    string street;
    string city;
    string state;
    string zipCode;

    AddressType(string street="", string city="", string state="", string zipCode="") :
        street(street), city(city), state(state), zipCode(zipCode) {}

    void printAddress() {
        cout << "Address: " << street << ", " << city << ", " << state << " " << zipCode << endl;
    }
};

class ExtPersonType {
public:
    string firstName;
    string lastName;
    string birthDate;
    AddressType address;
    string phone;
    string relationship;

    ExtPersonType(string firstName="", string lastName="", string birthDate="", AddressType address=AddressType(), string phone="", string relationship="") :
        firstName(firstName), lastName(lastName), birthDate(birthDate), address(address), phone(phone), relationship(relationship) {}

    void printInfo() {
        cout << "Name: " << firstName << " " << lastName << endl;
        if (!birthDate.empty())
            cout << "Birth Date: " << birthDate << endl;
        address.printAddress();
        cout << "Phone: " << phone << endl;
        cout << "Relationship: " << relationship << endl;
    }
};

class AddressBookType {
public:
    ExtPersonType entries[MAX_ENTRIES];
    int count = 0;

    void sortByLastName() {
        for (int i = 0; i < count - 1; ++i) {
            for (int j = 0; j < count - i - 1; ++j) {
                if (entries[j].lastName > entries[j + 1].lastName) {
                    ExtPersonType temp = entries[j];
                    entries[j] = entries[j + 1];
                    entries[j + 1] = temp;
                }
            }
        }
    }

    ExtPersonType* searchByLastName(string lastName) {
        for (int i = 0; i < count; ++i) {
            if (entries[i].lastName == lastName)
                return &entries[i];
        }
        return nullptr;
    }

    void printBirthdayMonth(int month) {
        for (int i = 0; i < count; ++i) {
            if (!entries[i].birthDate.empty() && stoi(entries[i].birthDate.substr(0, 2)) == month)
                cout << entries[i].firstName << " " << entries[i].lastName << endl;
        }
    }

    void printBetweenLastNames(string startName, string endName) {
        for (int i = 0; i < count; ++i) {
            if (entries[i].lastName >= startName && entries[i].lastName <= endName)
                cout << entries[i].firstName << " " << entries[i].lastName << endl;
        }
    }

    void printByRelationship(string relationship) {
        for (int i = 0; i < count; ++i) {
            if (entries[i].relationship == relationship)
                cout << entries[i].firstName << " " << entries[i].lastName << endl;
        }
    }
};

int main() {
    AddressBookType addressBook;
    addressBook.sortByLastName();
    ExtPersonType* person = addressBook.searchByLastName("Smith");
    if (person)
        person->printInfo();
    addressBook.printBirthdayMonth(5);
    addressBook.printBetweenLastNames("Johnson", "Smith");
    addressBook.printByRelationship("Family");

    return 0;
}
