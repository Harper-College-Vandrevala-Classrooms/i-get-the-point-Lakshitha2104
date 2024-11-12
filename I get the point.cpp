#include <iostream>
#include <cmath>

class Point {
private:
    double x;
    double y;

public:

    Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

    double getX() const { return x; }
    double getY() const { return y; }

    double operator-(const Point& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }

    bool operator==(const Point& other) const {
        return (x == other.x) && (y == other.y);
    }

    bool operator!=(const Point& other) const {
        return !(*this == other);
    }

    Point operator/(const Point& other) const {
        double midX = (x + other.x) / 2;
        double midY = (y + other.y) / 2;
        return Point(midX, midY);
    }

    void print() const {
        std::cout << "(" << x << ", " << y << ")";
    }
};

int main() {
    Point p1(3.2, 9.8);
    Point p2(5.5, -1.2);


    std::cout << "Distance between p1 and p2: " << p1 - p2 << std::endl;


    std::cout << "p1 == p2: " << (p1 == p2) << std::endl;


    std::cout << "p1 != p2: " << (p1 != p2) << std::endl;


    Point midpoint = p1 / p2;
    std::cout << "Midpoint between p1 and p2: ";
    midpoint.print();
    std::cout << std::endl;

    return 0;
}