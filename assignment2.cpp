// LAB ASSIGNMENT - 2
// Name: Kshaaunish Choudhary
// Roll No: 1024150193

#include <iostream>
#include <string>
using namespace std;

// Q1: Structure with Student details
struct Student {
    string name, degree, hostel;
    int rollNo;
    float cgpa;

    void addDetails(string n, int r, string d, string h, float c) {
        name = n; rollNo = r; degree = d; hostel = h; cgpa = c;
    }
    void updateDetails(string n, string d) { name = n; degree = d; }
    void updateCGPA(float c) { cgpa = c; }
    void updateHostel(string h) { hostel = h; }
    void displayDetails() {
        cout << "Name: " << name << "\nRoll No: " << rollNo
             << "\nDegree: " << degree << "\nHostel: " << hostel
             << "\nCGPA: " << cgpa << endl;
    }
};

// Q2: Class with private data members
class StudentClass {
private:
    string name, degree, hostel;
    int rollNo;
    float cgpa;
    void validate() { if (cgpa > 10) cgpa = 10; } // private function

public:
    void addDetails(string n, int r, string d, string h, float c) {
        name = n; rollNo = r; degree = d; hostel = h; cgpa = c;
        validate();
    }
    void updateDetails(string n, string d) { name = n; degree = d; }
    void updateCGPA(float c) { cgpa = c; validate(); }
    void updateHostel(string h) { hostel = h; }
    void displayDetails() {
        cout << "Name: " << name << "\nRoll No: " << rollNo
             << "\nDegree: " << degree << "\nHostel: " << hostel
             << "\nCGPA: " << cgpa << endl;
    }
};

// Q3: Calling private member function inside public
class Demo {
private:
    void privateFunc() { cout << "Private function called!" << endl; }
public:
    void publicFunc() {
        cout << "Public function calling private..." << endl;
        privateFunc();
    }
};

// Q4: Rectangle class
class Rectangle {
private:
    int width, height;
public:
    void getdata() {
        cout << "Enter width and height: ";
        cin >> width >> height;
    }
    void calculateArea() {
        cout << "Area = " << width * height << endl;
    }
};

// Q5: Complex class
class Complex {
private:
    float real, imaginary;
public:
    void setComplex(float r, float i) { real = r; imaginary = i; }
    void displayComplex() {
        cout << real << " + " << imaginary << "i" << endl;
    }
    Complex addComplex(Complex c) {
        Complex result;
        result.real = real + c.real;
        result.imaginary = imaginary + c.imaginary;
        return result;
    }
};

// Q6: Scope resolution operator
int value = 50; // global

class ScopeDemo {
public:
    static int staticVar;
    void showGlobal() {
        int value = 10; // local
        cout << "Local value: " << value << endl;
        cout << "Global value: " << ::value << endl;
    }
    static void showStatic() {
        cout << "Static variable: " << staticVar << endl;
    }
    void show();
};
int ScopeDemo::staticVar = 99;
void ScopeDemo::show() {  // defined outside using ::
    cout << "Function defined outside class using ::" << endl;
    std::cout << "Using std:: scope resolution: " << staticVar << std::endl;
}

// Q7: Namespace
namespace LibA {
    int x = 10;
    void display() { cout << "LibA x = " << x << endl; }
}
namespace LibB {
    int x = 200;
    void display() { cout << "LibB x = " << x << endl; }
}

int main() {
    // Q1
    cout << "=== Q1: Student Structure ===" << endl;
    Student s;
    s.addDetails("Shaurya Goel", 1024150330, "B.Tech", "H1", 8.5);
    s.displayDetails();
    s.updateCGPA(9.0); s.updateHostel("H2");
    cout << "After update:" << endl;
    s.displayDetails();

    // Q2
    cout << "\n=== Q2: Student Class (private data) ===" << endl;
    StudentClass sc;
    sc.addDetails("Kshaaunish Choudhary", 1024150193, "B.Tech ENC", "D1", 8.3);
    sc.displayDetails();

    // Q3
    cout << "\n=== Q3: Private function via public ===" << endl;
    Demo d;
    d.publicFunc();

    // Q4
    cout << "\n=== Q4: Rectangle ===" << endl;
    Rectangle r;
    r.getdata();
    r.calculateArea();

    // Q5
    cout << "\n=== Q5: Complex ===" << endl;
    Complex c1, c2;
    c1.setComplex(3.0, 4.0); c2.setComplex(1.5, 2.5);
    cout << "C1: "; c1.displayComplex();
    cout << "C2: "; c2.displayComplex();
    Complex sum = c1.addComplex(c2);
    cout << "Sum: "; sum.displayComplex();

    // Q6
    cout << "\n=== Q6: Scope Resolution ===" << endl;
    ScopeDemo sd;
    sd.showGlobal();
    ScopeDemo::showStatic();
    sd.show();

    // Q7
    cout << "\n=== Q7: Namespace ===" << endl;
    LibA::display();
    LibB::display();

    return 0;
}
