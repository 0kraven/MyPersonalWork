#include <iostream>
#include <cmath>
using namespace std;
class CylinderType {
private:
    double radius;
    double height;
    double shipping_cost_per_liter;
    double paint_cost_per_sq_foot;

public:
    CylinderType(double r = 0, double h = 0, double shipping_cost = 0, double paint_cost = 0)
        : radius(r), height(h), shipping_cost_per_liter(shipping_cost), paint_cost_per_sq_foot(paint_cost) {}

    void setDimensions(double r, double h) {
        radius = r;
        height = h;
    }

    void setShippingCost(double cost) {
        shipping_cost_per_liter = cost;
    }

    void setPaintCost(double cost) {
        paint_cost_per_sq_foot = cost;
    }

    double calculateVolumeLiters() const {
        return radius * radius * height * 28.32;
    }

    double calculateShippingCost() const {
        return calculateVolumeLiters() * shipping_cost_per_liter;
    }

    double calculateSurfaceArea() const {
        return 2 * 3.14 * radius * (radius + height);
    }

    double calculatePaintingCost() const {
        return calculateSurfaceArea() * paint_cost_per_sq_foot;
    }

    void getUserData() {
        cout << "Enter the radius of the container (in feet): ";
        cin >> radius;
        cout << "Enter the height of the container (in feet): ";
        cin >> height;
        cout << "Enter the shipping cost per liter: ";
        cin >> shipping_cost_per_liter;
        cout << "Enter the paint cost per square foot: ";
        cin >> paint_cost_per_sq_foot;
    }

    void outputData() const {
        cout << "Shipping Cost: $" << calculateShippingCost() << endl;
        cout << "Painting Cost: $" << calculatePaintingCost() << endl;
    }
};

int main() {
    
    CylinderType container;
    container.getUserData();
    container.outputData();

    return 0;
}
