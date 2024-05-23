#include <iostream>
#include <cmath>
using namespace std;

class primeFactorization {
private:
    int factors[10];
    int size;

public:
    primeFactorization() {
        size = 0;
    }

    void findPrimeFactors(int num) {
        size = 0;

        while (num % 2 == 0) {
            factors[size++] = 2;
            num /= 2;
        }

        for (int i = 3; i * i <= num; i += 2) {
            while (num % i == 0) {
                factors[size++] = i;
                num /= i;
            }
        }

        if (num > 2) {
            factors[size++] = num;
        }
    }

    void printPrimeFactors() const {
        if (size == 0) {
            cout << "No prime factors found." << endl;
            return;
        }

        cout << "Prime factors: ";
        for (int i = 0; i < size; ++i) {
            cout << factors[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    primeFactorization pf;
    int number;

    cout << "Enter a number to find its prime factors: ";
    cin >> number;

    pf.findPrimeFactors(number);
    pf.printPrimeFactors();

    return 0;
}
