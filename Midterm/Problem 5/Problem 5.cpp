/* OverloadedFunctions.cpp - Initial version of problem 5 in midterm
 * Author: Nate Douglas
 */

#include <iostream>
#include <sstream>
using namespace std;

class Complex {

private:
    double x, y;

public:
    Complex(const double x = 0, const double y = 0) : x(x), y(y) {}

    double getx() const {
        return x;
    }

    double gety() const {
        return y;
    }

    friend Complex operator+(Complex, Complex);
    friend ostream& operator<<(ostream&, const Complex);
};

Complex operator+(Complex obj, Complex obj2) {
    double xResult = obj.getx() + obj2.getx();
    double yResult = obj.gety() + obj2.gety();
    Complex result(xResult, yResult);
    return result;
}

ostream &operator<<(ostream& output, const Complex obj) {
    output << "x: " << obj.getx() << " y: " << obj.gety();
    return output;
}

int main() {

    Complex ones(1, 1.11), twos(2, 2.22), threes(3, 3.33), fours(4, 4.44);
    cout << ones << " + " << twos << " + " << threes
        << " + " << fours << " is "
        << (ones + twos + threes + fours) << endl;

    return 0;
}

