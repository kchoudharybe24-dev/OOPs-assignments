// LAB ASSIGNMENT - 4
// Name: Kshaaunish Choudhary
// Roll No: 1024150193

#include <iostream>
using namespace std;

// Q1: Rectangle class with 3 constructors
class Rectangle {
private:
    float length, breadth;
public:
    Rectangle() : length(1), breadth(1) {}             // default
    Rectangle(float l) : length(l), breadth(l) {}      // one param (square)
    Rectangle(float l, float b) : length(l), breadth(b) {} // two params

    float area() { return length * breadth; }
    void display() { cout << "Area = " << area() << endl; }
};

void q1() {
    Rectangle r1;           // no param
    Rectangle r2(5.0f);     // one param
    Rectangle r3(4.0f, 6.0f); // two params
    cout << "No param:    "; r1.display();
    cout << "One param:   "; r2.display();
    cout << "Two params:  "; r3.display();
}

// Q2: Array of objects + default args + destructor
class RectArray {
private:
    float length, breadth;
public:
    RectArray(float l = 2, float b = 3) : length(l), breadth(b) {
        cout << "Constructor: l=" << l << " b=" << b << endl;
    }
    ~RectArray() {
        cout << "Destructor called for l=" << length << " b=" << breadth << endl;
    }
    float area() { return length * breadth; }
};

void q2() {
    RectArray arr[3] = { RectArray(), RectArray(5), RectArray(4, 7) };
    for (int i = 0; i < 3; i++)
        cout << "Rectangle " << i+1 << " area: " << arr[i].area() << endl;
}

// Q3: Destructor properties demo
class DestructorDemo {
private:
    int id;
public:
    DestructorDemo(int i) : id(i) { cout << "Constructor: Object " << id << endl; }
    ~DestructorDemo() { cout << "Destructor: Object " << id << endl; }
    // Only ONE destructor allowed
    // ~DestructorDemo(int x) {} // ERROR: no parameters allowed
    // int ~DestructorDemo() {}  // ERROR: no return type allowed
};

void q3() {
    {
        DestructorDemo d1(1), d2(2), d3(3);
        cout << "Inside scope." << endl;
    } // destructors called here automatically (LIFO)
    cout << "Outside scope." << endl;
}

// Q4: Dynamic memory allocation
class Sample {
public:
    int val;
    Sample() { val = 0; cout << "Sample default constructed." << endl; }
    Sample(int v) : val(v) { cout << "Sample(" << v << ") constructed." << endl; }
    ~Sample() { cout << "Sample(" << val << ") destroyed." << endl; }
};

void q4() {
    // Integer variable
    int *iPtr = new int(42);
    cout << "Dynamic int: " << *iPtr << endl;
    delete iPtr;

    // Float variable
    float *fPtr = new float(3.14f);
    cout << "Dynamic float: " << *fPtr << endl;
    delete fPtr;

    // Integer array
    int *iArr = new int[4]{10, 20, 30, 40};
    cout << "Dynamic int array: ";
    for (int i = 0; i < 4; i++) cout << iArr[i] << " ";
    cout << endl;
    delete[] iArr;

    // Float array
    float *fArr = new float[3]{1.1f, 2.2f, 3.3f};
    cout << "Dynamic float array: ";
    for (int i = 0; i < 3; i++) cout << fArr[i] << " ";
    cout << endl;
    delete[] fArr;

    // Class object
    Sample *sPtr = new Sample(99);
    cout << "Dynamic object val: " << sPtr->val << endl;
    delete sPtr;

    // Array of Objects
    Sample *sArr = new Sample[2];
    sArr[0].val = 10; sArr[1].val = 20;
    cout << "Array of objects: " << sArr[0].val << ", " << sArr[1].val << endl;
    delete[] sArr;
}

int main() {
    cout << "=== Q1: Rectangle (3 Constructors) ===" << endl;
    q1();

    cout << "\n=== Q2: Array of Rect + Default Args + Destructor ===" << endl;
    q2();

    cout << "\n=== Q3: Destructor Properties ===" << endl;
    q3();

    cout << "\n=== Q4: Dynamic Memory Allocation ===" << endl;
    q4();

    return 0;
}
