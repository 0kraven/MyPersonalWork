#include <iostream>
#include<cmath>
using namespace std;
class pointType {
private:
    double x;
    double y;

public:
    pointType(double x = 0, double y = 0) : x(x), y(y) {}

    void setX(double newX) {
        x = newX;
    }

    void setY(double newY) {
        y = newY;
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    double distance(const pointType other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }
};

class lineType {
private:
    pointType point1;
    pointType point2;

public:
    lineType(const pointType p1, const pointType p2) : point1(p1), point2(p2) {}

    bool isVertical() const {
        return point1.getX() == point2.getX();
    }

    bool isHorizontal() const {
        return point1.getY() == point2.getY();
    }


    double slope() const {
        if (isVertical()) {
            cout << "The line is vertical. Slope is undefined." << endl;
            return 0;
        } else {
            return (point2.getY() - point1.getY()) / (point2.getX() - point1.getX());
        }
    }

    void equation() const {
        if (isVertical()) {
            cout << "x = " << point1.getX() << endl;
        } else {
            double m = slope();
            double b = point1.getY() - m * point1.getX();
            cout << "y = " << m << "x + " << b << endl;
        }
    }

    pointType intersection(const lineType other){
        if (isVertical() && other.isVertical()) {
            cout << "Both lines are vertical. No intersection point." << endl;
            return pointType();
        } else if (isVertical()) {
            double x = point1.getX();
            double m2 = other.slope();
            double b2 = other.point1.getY() - m2 * other.point1.getX();
            double y = m2 * x + b2;
            return pointType(x, y);
        } else if (other.isVertical()) {
            double x = other.point1.getX();
            double m1 = slope();
            double b1 = point1.getY() - m1 * point1.getX();
            double y = m1 * x + b1;
            return pointType(x, y);
        } else {
            double m1 = slope();
            double b1 = point1.getY() - m1 * point1.getX();
            double m2 = other.slope();
            double b2 = other.point1.getY() - m2 * other.point1.getX();
            double x = (b2 - b1) / (m1 - m2);
            double y = m1 * x + b1;
            return pointType(x, y);
        }
    }
};

int main() {
    pointType p1(1, 2);
    pointType p2(3, 4);
    lineType line(p1, p2);

    cout << "Equation of the line: ";
    line.equation();

    cout << "Slope of the line: " << line.slope() << endl;

    pointType p3(2, 1);
    pointType p4(4, 3);
    lineType otherLine(p3, p4);

    cout << "Equation of the other line: ";
    otherLine.equation();

    cout << "Slope of the other line: " << otherLine.slope() << endl;

    pointType intersection = line.intersection(otherLine);
    cout << "Intersection point: (" << intersection.getX() << ", " << intersection.getY() << ")" << endl;

    return 0;
}
