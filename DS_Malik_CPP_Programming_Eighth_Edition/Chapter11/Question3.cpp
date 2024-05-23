#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159;

class circleType {

protected:
    double radius;
public:
	circleType(){
	    radius=0.0;	
    }
    circleType(double r ) {
        radius = r;
    }
    void setRadius(double r) {
        radius = r;
    }

    double getRadius() const {
        return radius;
    }
    double area() const {
        return PI * radius * radius;
    }

    double circumference() const {
        return 2 * PI * radius;
    }

    void print() const {
        cout << "Radius: " << radius << endl;
        cout << "Area: " << area() << endl;
        cout << "Circumference: " << circumference() << endl;
    }
};

class cylinderType : public circleType {
	private:
    double height;
public:
	cylinderType()
	{
		height= 0.0;
		radius =0.0;
	}
    cylinderType(double r , double h ) 
	{
    radius = r;
    height = h;
    }
    void setHeight(double h) {
        height = h;
    }
double getHeight() const {
        return height;
    }

    double volume() const {
        return area() * height;
    }

    double surfaceArea() const {
        return 2 * area() + circumference() * height;
    }

    void print() const {
        circleType::print();
        cout << "Height: " << height << endl;
        cout << "Volume: " << volume() << endl;
        cout << "Surface Area: " << surfaceArea() << endl;
    }
};

int main() {
    cylinderType myCylinder(5.0, 10.0);
    myCylinder.print();

    return 0;
}
