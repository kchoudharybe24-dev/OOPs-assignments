// LAB ASSIGNMENT - 3
// Name: Kshaaunish Choudhary
// Roll No: 1024150193

#include <iostream>
using namespace std;

// Q1: Pointer to object, this pointer
class Box {
private:
    int length;
public:
    Box(int l) : length(l) {}
    void display() {
        cout << "Length (via this->): " << this->length << endl;
    }
};
void q1() {
    Box b(10);
    Box *ptr = &b;
    ptr->display();   // arrow operator
    (*ptr).display(); // dot operator via dereferenced pointer
}

// Q2: Swap private values using friend function
class ClassA;
class ClassB {
private:
    int data;
public:
    ClassB(int d) : data(d) {}
    friend void swapData(ClassA &a, ClassB &b);
    void display() { cout << "ClassB data: " << data << endl; }
};

class ClassA {
private:
    int data;
public:
    ClassA(int d) : data(d) {}
    friend void swapData(ClassA &a, ClassB &b);
    void display() { cout << "ClassA data: " << data << endl; }
};

void swapData(ClassA &a, ClassB &b) {
    int temp = a.data;
    a.data = b.data;
    b.data = temp;
}
void q2() {
    ClassA a(5);
    ClassB b(10);
    cout << "Before swap:" << endl; a.display(); b.display();
    swapData(a, b);
    cout << "After swap:" << endl; a.display(); b.display();
}

// Q3: Add data objects of two different classes using friend function
class ClassX;
class ClassY {
private:
    int y;
public:
    ClassY(int val) : y(val) {}
    friend int addObjects(ClassX a, ClassY b);
};
class ClassX {
private:
    int x;
public:
    ClassX(int val) : x(val) {}
    friend int addObjects(ClassX a, ClassY b);
};
int addObjects(ClassX a, ClassY b) { return a.x + b.y; }
void q3() {
    ClassX cx(15);
    ClassY cy(25);
    cout << "Sum of objects: " << addObjects(cx, cy) << endl;
}

// Q4: Friend class
class Engine {
private:
    int horsepower;
public:
    Engine(int hp) : horsepower(hp) {}
    friend class Car;
};
class Car {
public:
    void showHP(Engine &e) {
        cout << "Car engine horsepower: " << e.horsepower << endl;
    }
};
void q4() {
    Engine e(200);
    Car c;
    c.showHP(e);
}

// Q5: Array of Objects - area of multiple rectangles
class Rectangle {
private:
    float length, breadth;
public:
    void setData(float l, float b) { length = l; breadth = b; }
    float area() { return length * breadth; }
};
void q5() {
    Rectangle rects[3];
    rects[0].setData(4, 5);
    rects[1].setData(7, 3);
    rects[2].setData(2, 9);
    for (int i = 0; i < 3; i++)
        cout << "Rectangle " << i+1 << " area: " << rects[i].area() << endl;
}

// Q6: Inline function - cube
inline float cube(float n) { return n * n * n; }
void q6() {
    cout << "Cube of 3: " << cube(3) << endl;
    cout << "Cube of 5.5: " << cube(5.5) << endl;
}

// Q7: Pass and return objects (pass-by-value and pass-by-address)
class Point {
public:
    int x, y;
    Point(int a = 0, int b = 0) : x(a), y(b) {}
    void display() { cout << "Point(" << x << ", " << y << ")" << endl; }
};

Point addByValue(Point p1, Point p2) {
    return Point(p1.x + p2.x, p1.y + p2.y);
}
Point addByAddress(Point *p1, Point *p2) {
    return Point(p1->x + p2->x, p1->y + p2->y);
}
void q7() {
    Point p1(1, 2), p2(3, 4);
    Point r1 = addByValue(p1, p2);
    cout << "Sum by value: "; r1.display();
    Point r2 = addByAddress(&p1, &p2);
    cout << "Sum by address: "; r2.display();
}

int main() {
    cout << "=== Q1: Pointer to Object & this ===" << endl; q1();
    cout << "\n=== Q2: Swap using Friend Function ===" << endl; q2();
    cout << "\n=== Q3: Add Objects using Friend ===" << endl; q3();
    cout << "\n=== Q4: Friend Class ===" << endl; q4();
    cout << "\n=== Q5: Array of Objects (Rectangle) ===" << endl; q5();
    cout << "\n=== Q6: Inline Function ===" << endl; q6();
    cout << "\n=== Q7: Pass and Return Objects ===" << endl; q7();
    return 0;
}
