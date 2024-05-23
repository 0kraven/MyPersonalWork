#include<iostream>
#include<string>
using namespace std;

class DateType {
    private:
        int month;
        int day;
        int year;
    public:
        DateType() {
            month = 0;
            day = 0;
            year = 0;
        }
        DateType(int m, int d, int y) {
            month = m;
            day = d;
            year = y;
        }
        void setMonth(int m) {
            month = m;
        }
        void setDay(int d) {
            day = d;
        }
        void setYear(int y) {
            year = y;
        }
        int getMonth() const {
            return month;
        }
        int getDay() const {
            return day;
        }
        int getYear() const {
            return year;
        }
        void printDate() const {
            cout << month << "/" << day << "/" << year << endl;
        }
};

class PersonType {
    private:
        string firstName;
        string lastName;
    public:
        PersonType() {
            firstName = "";
            lastName = "";
        }
        PersonType(const string first, const string last) {
            firstName = first;
            lastName = last;
        }
        void setFirstName(const string first) {
            firstName = first;
        }
        void setLastName(const string last) {
            lastName = last;
        }
        string getFirstName() const {
            return firstName;
        }
        string getLastName() const {
            return lastName;
        }
        void printName() const {
            cout << firstName << " " << lastName << endl;
        }
};

class DoctorType : public PersonType {
    private:
        string specialty;
    public:
        DoctorType() {
            specialty = "";
        }
        DoctorType(const string special, const string first, const string last) : PersonType(first, last) {
            specialty = special;
        }
        void setSpecialty(const string special) {
            specialty = special;
        }
        string getSpecialty() const {
            return specialty;
        }
        void printDoctorInfo() const {
            printName();
            cout << ", specialty " << specialty << endl;
        }
};

class BillType {
    private:
        string patientId;
        double pharmacyCharges;
        double doctorFee;
        double roomCharges;
    public:
        BillType() {
            patientId = "";
            pharmacyCharges = 0.0;
            doctorFee = 0.0;
            roomCharges = 0.0;
        }
        BillType(string id, double pharmacy, double fee, double room) {
            patientId = id;
            pharmacyCharges = pharmacy;
            doctorFee = fee;
            roomCharges = room;
        }
        void setPatientId(string id) {
            patientId = id;
        }
        void setPharmacyCharges(double pharmacy) {
            pharmacyCharges = pharmacy;
        }
        void setDoctorFee(double fee) {
            doctorFee = fee;
        }
        void setRoomCharges(double room) {
            roomCharges = room;
        }
        string getPatientId() const {
            return patientId;
        }
        double getPharmacyCharges() const {
            return pharmacyCharges;
        }
        double getDoctorFee() const {
            return doctorFee;
        }
        double getRoomCharges() const {
            return roomCharges;
        }
        double totalCharges() const {
            return pharmacyCharges + doctorFee + roomCharges;
        }
};

class PatientType : public PersonType {
    private:
        string patientId;
        int age;
        DateType dob;
        DateType admitDate;
        DateType dischargeDate;
        DoctorType doctor;
    public:
        PatientType() {
            patientId = "";
            age = 0;
        }
        PatientType(const string id, int ag, const string first, const string last) : PersonType(first, last) {
            patientId = id;
            age = ag;
        }
        void setPatientId(const string id) {
            patientId = id;
        }
        string getPatientId() const {
            return patientId;
        }
        void setAge(int ag) {
            age = ag;
        }
        int getAge() const {
            return age;
        }
        void setDob(int m, int d, int y) {
            dob.setMonth(m);
            dob.setDay(d);
            dob.setYear(y);
        }
        DateType getDob() const {
            return dob;
        }
        void setAdmitDate(int m, int d, int y) {
            admitDate.setMonth(m);
            admitDate.setDay(d);
            admitDate.setYear(y);
        }
        DateType getAdmitDate() const {
            return admitDate;
        }
        void setDischargeDate(int m, int d, int y) {
            dischargeDate.setMonth(m);
            dischargeDate.setDay(d);
            dischargeDate.setYear(y);
        }
        DateType getDischargeDate() const {
            return dischargeDate;
        }
        void setDoctor(const DoctorType& doctor) {
            this->doctor = doctor;
        }
        DoctorType getDoctor() const {
            return doctor;
        }
        void printInfo() const {
            printName();
            cout << "age: " << age << " Patient ID: " << patientId << endl;
            cout << "Date of birth: ";
            dob.printDate();
            cout << "Admit date: ";
            admitDate.printDate();
            cout << "Discharge date: ";
            dischargeDate.printDate();
            cout << "Attending physician: ";
            doctor.printDoctorInfo();
            cout << endl;
        }
};

int main() {
    DoctorType doctor("Cardiology", "John", "Doe");
    PatientType patient("P1234", 30, "Alice", "Smith");
    patient.setDob(12, 21, 2122);
    patient.setAdmitDate(4, 22, 2020);
    patient.setDischargeDate(5, 22, 2020);
    patient.setAge(40);
    patient.setDoctor(doctor);
    cout << "Patient info" << endl;
    patient.printInfo(); 
}
