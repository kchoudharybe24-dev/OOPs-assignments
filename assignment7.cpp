//Program 1: Polygon, Rectangle and Triangle with Virtual Function
//Description: Class polygon contains data members width and height with set_value(). Rectangle and Triangle inherit from polygon and override calculate_area() using virtual functions accessed via base class pointer.

//Code:
#include<iostream>
using namespace std;
 
class Polygon {
protected:
    int width, height;
public:
    void set_value(int w, int h) {
        width = w; height = h;
    }
    virtual float calculate_area() {
        return 0;
    }
};
 
class Rectangle : public Polygon {
public:
    float calculate_area() override {
        return width * height;
    }
};
 
class Triangle : public Polygon {
public:
    float calculate_area() override {
        return 0.5 * width * height;
    }
};
 
int main() {
    Polygon* p;
    Rectangle rect;
    Triangle tri;
 
    p = &rect;
    p->set_value(10, 5);
    cout << "Rectangle Area: " << p->calculate_area() << endl;
 
    p = &tri;
    p->set_value(10, 5);
    cout << "Triangle Area: " << p->calculate_area() << endl;
 
    return 0;
}


//Program 2: Abstract Shape Class with Circle, Rectangle and Triangle
//Description: A class Shape is defined with pure virtual functions area() and display(). Derived classes Circle, Rectangle, and Triangle override these functions.

//Code:
#include<iostream>
#include<cmath>
using namespace std;
 
class Shape {
public:
    virtual float area() = 0;
    virtual void display() = 0;
};
 
class Circle : public Shape {
    float r;
public:
    Circle(float r) : r(r) {}
    float area() override { return M_PI * r * r; }
    void display() override {
        cout << "Circle | Radius: " << r << " | Area: " << area() << endl;
    }
};
 
class Rectangle : public Shape {
    float l, b;
public:
    Rectangle(float l, float b) : l(l), b(b) {}
    float area() override { return l * b; }
    void display() override {
        cout << "Rectangle | L: " << l << " B: " << b << " | Area: " << area() << endl;
    }
};
 
class Triangle : public Shape {
    float base, height;
public:
    Triangle(float b, float h) : base(b), height(h) {}
    float area() override { return 0.5 * base * height; }
    void display() override {
        cout << "Triangle | Base: " << base << " H: " << height << " | Area: " << area() << endl;
    }
};
 
int main() {
    Shape* shapes[3];
    shapes[0] = new Circle(5);
    shapes[1] = new Rectangle(4, 6);
    shapes[2] = new Triangle(3, 8);
    for (int i = 0; i < 3; i++) shapes[i]->display();
    return 0;
}


//Program 3: Triangle Area using Function Overloading
//Description: Function overloading is used to compute the area of right angle triangle, equilateral triangle, and isosceles triangle.

//Code:
#include<iostream>
#include<cmath>
using namespace std;
 
float area(float base, float height) {
    return 0.5 * base * height;  // Right angle triangle
}
 
float area(float side) {
    return (sqrt(3) / 4) * side * side;  // Equilateral triangle
}
 
float area(float a, float b, char flag) {
    float h = sqrt(a*a - (b/2)*(b/2));
    return 0.5 * b * h;  // Isosceles triangle
}
 
int main() {
    cout << "Right Angle Triangle Area: " << area(6.0f, 4.0f) << endl;
    cout << "Equilateral Triangle Area: " << area(5.0f) << endl;
    cout << "Isosceles Triangle Area: " << area(5.0f, 6.0f, 'i') << endl;
    return 0;
}


//Program 4: Abstract Student Class with Engineering, Medicine, Science
//Description: Student is an abstract base class. Derived classes Engineering, Medicine, Science override a pure virtual function. Objects are accessed via an array of base class pointers.

//Code:
#include<iostream>
using namespace std;
 
class Student {
public:
    string name;
    virtual void display() = 0;
};
 
class Engineering : public Student {
public:
    Engineering(string n) { name = n; }
    void display() override {
        cout << "Engineering Student: " << name << endl;
    }
};
 
class Medicine : public Student {
public:
    Medicine(string n) { name = n; }
    void display() override {
        cout << "Medicine Student: " << name << endl;
    }
};
 
class Science : public Student {
public:
    Science(string n) { name = n; }
    void display() override {
        cout << "Science Student: " << name << endl;
    }
};
 
int main() {
    Student* arr[3];
    arr[0] = new Engineering("Amit");
    arr[1] = new Medicine("Priya");
    arr[2] = new Science("Rahul");
    for (int i = 0; i < 3; i++) arr[i]->display();
    return 0;
}


//Program 5: Class Time with '+' Operator Overloading
//Description: Class Time has private members h, m, s. The '+' operator is overloaded to add two Time objects.

//Code:
#include<iostream>
using namespace std;
 
class Time {
    int h, m, s;
public:
    Time() : h(0), m(0), s(0) {}
    Time(int h, int m, int s) : h(h), m(m), s(s) {}
 
    Time operator+(const Time& t) {
        int ts = s + t.s;
        int tm = m + t.m + ts / 60;
        int th = h + t.h + tm / 60;
        return Time(th, tm % 60, ts % 60);
    }
 
    void show() {
        cout << h << ":" << m << ":" << s << endl;
    }
};
 
int main() {
    Time t1(5,15,34), t2(9,53,58), t3;
    t3 = t1 + t2;
    t3.show();
    return 0;
}


//Program 6: Class STRING with '==' and '+' Operator Overloading
//Description: Class STRING overloads == for string comparison and + for string concatenation.

//Code:
#include<iostream>
#include<cstring>
using namespace std;
 
class STRING {
    char str[100];
public:
    STRING() { str[0] = '\0'; }
    STRING(const char* s) { strcpy(str, s); }
 
    bool operator==(const STRING& s) {
        return strcmp(str, s.str) == 0;
    }
 
    STRING operator+(const STRING& s) {
        STRING temp;
        strcpy(temp.str, str);
        strcat(temp.str, s.str);
        return temp;
    }
 
    void display() { cout << str << endl; }
};
 
int main() {
    STRING s1("Hello "), s2("World"), s3;
    s3 = s1 + s2;
    cout << "Concatenated: ";
    s3.display();
    if (s1 == s2) cout << "Strings are equal" << endl;
    else cout << "Strings are not equal" << endl;
    return 0;
}


//Program 7: Matrix Class with '*' Operator Overloading (Friend Function)
//Description: Class Matrix overloads the * operator using a friend function to multiply two matrices.

//Code:
#include<iostream>
using namespace std;
 
class Matrix {
    int a[3][3], r, c;
public:
    Matrix(int rows, int cols) : r(rows), c(cols) {}
 
    void input() {
        cout << "Enter elements:\n";
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                cin >> a[i][j];
    }
 
    void display() {
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }
 
    friend Matrix operator*(const Matrix& m1, const Matrix& m2);
};
 
Matrix operator*(const Matrix& m1, const Matrix& m2) {
    Matrix res(m1.r, m2.c);
    for(int i=0;i<m1.r;i++)
        for(int j=0;j<m2.c;j++) {
            res.a[i][j] = 0;
            for(int k=0;k<m1.c;k++)
                res.a[i][j] += m1.a[i][k] * m2.a[k][j];
        }
    return res;
}
 
int main() {
    Matrix m1(2,2), m2(2,2);
    m1.input(); m2.input();
    Matrix m3 = m1 * m2;
    cout << "Result:\n";
    m3.display();
    return 0;
}


//Program 8: Overload '[]' to Check Array Index Out of Bounds
//Description: The [] operator is overloaded to check array index out of bounds at runtime.

//Code:
#include<iostream>
using namespace std;
 
class SafeArray {
    int arr[10];
    int size;
public:
    SafeArray(int s) : size(s) {}
 
    int& operator[](int index) {
        if(index < 0 || index >= size) {
            cout << "Index " << index << " out of bounds!" << endl;
            exit(1);
        }
        return arr[index];
    }
};
 
int main() {
    SafeArray a(5);
    a[0] = 10; a[1] = 20;
    cout << "a[0] = " << a[0] << endl;
    cout << "a[1] = " << a[1] << endl;
    cout << a[7] << endl;  // This triggers out-of-bounds
    return 0;
}


//Program 9: Overload '()' for Arbitrary Number of Arguments
//Description: The () operator is overloaded to accept an arbitrary number of arguments using variadic templates.

//Code:
#include<iostream>
#include<initializer_list>
using namespace std;
 
class Functor {
public:
    void operator()(initializer_list<int> args) {
        cout << "Arguments received: ";
        for(auto x : args)
            cout << x << " ";
        cout << endl;
    }
};
 
int main() {
    Functor f;
    f({1, 2, 3});
    f({10, 20, 30, 40, 50});
    return 0;
}


//Program 10: Overload Input (>>) and Output (<<) Operators
//Description: Input and output operators are overloaded as friend functions to input/output an object of class Student.

//Code:
#include<iostream>
using namespace std;
 
class Student {
    string name;
    int roll;
public:
    friend istream& operator>>(istream& in, Student& s) {
        cout << "Enter Name: ";
        in >> s.name;
        cout << "Enter Roll: ";
        in >> s.roll;
        return in;
    }
 
    friend ostream& operator<<(ostream& out, const Student& s) {
        out << "Name: " << s.name << ", Roll: " << s.roll;
        return out;
    }
};
 
int main() {
    Student s;
    cin >> s;
    cout << s << endl;
    return 0;
}


//Program 11: Convert Basic Data Type (float) to User Defined Type
//Description: A constructor in class Distance converts a float (meters) to an object with feet and inches.

//Code:
#include<iostream>
using namespace std;
 
class Distance {
    int feet;
    float inches;
public:
    Distance(float meters) {
        float totalInches = meters * 39.3701f;
        feet = (int)(totalInches / 12);
        inches = totalInches - feet * 12;
    }
 
    void show() {
        cout << feet << " ft " << inches << " in" << endl;
    }
};
 
int main() {
    float m = 1.5f;
    Distance d = m;  // float to UDT
    d.show();
    return 0;
}


//Program 12: Convert UDT to Basic Data Type (float)
//Description: A conversion operator in class Distance converts the object back to float (meters).

//Code:
#include<iostream>
using namespace std;
 
class Distance {
    int feet;
    float inches;
public:
    Distance(int f, float i) : feet(f), inches(i) {}
 
    operator float() {
        return feet * 0.3048f + inches * 0.0254f;
    }
};
 
int main() {
    Distance d(5, 6.5f);
    float meters = d;  // UDT to float
    cout << "Meters: " << meters << endl;
    return 0;
}


//Program 13: Convert One UDT to Another UDT (Polar to Cartesian)
//Description: A Polar object is converted to a Cartesian object using a constructor in the Cartesian class that accepts a Polar object.

//Code:
#include<iostream>
#include<cmath>
using namespace std;
 
class Polar {
public:
    float r, theta;
    Polar(float r, float theta) : r(r), theta(theta) {}
};
 
class Cartesian {
    float x, y;
public:
    Cartesian(Polar p) {
        x = p.r * cos(p.theta);
        y = p.r * sin(p.theta);
    }
 
    void show() {
        cout << "x = " << x << ", y = " << y << endl;
    }
};
 
int main() {
    Polar p(10, 5);
    Cartesian c = p;
    c.show();
    return 0;
}
