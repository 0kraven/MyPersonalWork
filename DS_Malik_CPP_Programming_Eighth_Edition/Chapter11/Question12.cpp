#include <iostream>
#include <string>
using namespace std;

class Course {
private:
    string name;
    string code;
    int credits;
    char grade;

public:
    
    Course(string name = "", string code = "", int credits = 0, char grade = ' ') {
        this->name = name;
        this->code = code;
        this->credits = credits;
        this->grade = grade;
    }

    
    string getName() const {
        return name;
    }

    string getCode() const {
        return code;
    }

    int getCredits() const {
        return credits;
    }

    char getGrade() const {
        return grade;
    }
};

class Student {
private:
    string name;
    int numCourses;
    string courseNames[6];
    string courseCodes[6];
    int courseCredits[6];
    char courseGrades[6];

public:
    
    Student(string name = "", int numCourses = 0) {
        this->name = name;
        this->numCourses = numCourses;
    }

    
    string getName() const {
        return name;
    }

    int getNumCourses() const {
        return numCourses;
    }

    string getCourseName(int index) const {
        if (index >= 0 && index < numCourses) {
            return courseNames[index];
        } else {
            return ""; 
        }
    }

    string getCourseCode(int index) const {
        if (index >= 0 && index < numCourses) {
            return courseCodes[index];
        } else {
            return ""; 
        }
    }

    int getCourseCredits(int index) const {
        if (index >= 0 && index < numCourses) {
            return courseCredits[index];
        } else {
            return 0; 
        }
    }

    char getCourseGrade(int index) const {
        if (index >= 0 && index < numCourses) {
            return courseGrades[index];
        } else {
            return ' '; 
        }
    }
};

int main() {
    
    Student student("John Doe", 3);
    cout << "Student Name: " << student.getName() << endl;
    cout << "Number of Courses: " << student.getNumCourses() << endl;

    
    for (int i = 0; i < student.getNumCourses(); ++i) {
        cout << "Course " << i + 1 << ": " << student.getCourseName(i) << " (" << student.getCourseCode(i) << ")" << endl;
        cout << "Credits: " << student.getCourseCredits(i) << ", Grade: " << student.getCourseGrade(i) << endl;
    }

    return 0;
}
