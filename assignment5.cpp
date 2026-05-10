// LAB ASSIGNMENT - 5
// Name: Kshaaunish Choudhary
// Roll No: 1024150193

#include <iostream>
#include <string>
using namespace std;

// Q1: Simple base and derived class
class Animal {
public:
    void eat() { cout << "Animal eats food." << endl; }
};
class Dog : public Animal {
public:
    void bark() { cout << "Dog barks." << endl; }
};
void q1() {
    Animal a; a.eat();
    Dog d; d.eat(); d.bark();
}

// Q2: Protected access specifier
class Base {
protected:
    int protectedVar = 42;
};
class Derived : public Base {
public:
    void show() { cout << "Protected var from Base: " << protectedVar << endl; }
};
void q2() {
    Derived d; d.show();
}

// Q3: Public, Protected, Private inheritance modes
class Person {
public:    string pubName = "Public";
protected: string proName = "Protected";
private:   string priName = "Private";
};
class PublicDerived : public Person {
public:
    void show() { cout << "Public: " << pubName << ", Protected: " << proName << endl; }
    // priName not accessible
};
class ProtectedDerived : protected Person {
public:
    void show() { cout << "Via protected inherit - pub becomes protected: " << pubName << endl; }
};
class PrivateDerived : private Person {
public:
    void show() { cout << "Via private inherit - pub becomes private: " << pubName << endl; }
};
void q3() {
    PublicDerived pd; pd.show();
    ProtectedDerived prd; prd.show();
    PrivateDerived pvd; pvd.show();
}

// Q4: Types of Inheritance
// Single
class Shape { public: void draw() { cout << "Drawing shape." << endl; } };
class Circle : public Shape { public: void area() { cout << "Circle area." << endl; } };

// Multiple
class Engine2 { public: void start() { cout << "Engine started." << endl; } };
class Wheels  { public: void roll()  { cout << "Wheels rolling." << endl; } };
class Car : public Engine2, public Wheels {};

// Hierarchical
class Vehicle { public: void move() { cout << "Vehicle moves." << endl; } };
class Bus  : public Vehicle { public: void board() { cout << "Bus boards passengers." << endl; } };
class Bike : public Vehicle { public: void ride()  { cout << "Bike rides." << endl; } };

// Multilevel
class LivingBeing { public: void breathe() { cout << "Breathing." << endl; } };
class Mammal : public LivingBeing { public: void feed() { cout << "Feeds young." << endl; } };
class Human  : public Mammal { public: void talk() { cout << "Human talks." << endl; } };

// Hybrid (combination of hierarchical + multiple)
class A { public: void showA() { cout << "Class A" << endl; } };
class B : public A { public: void showB() { cout << "Class B" << endl; } };
class C : public A { public: void showC() { cout << "Class C" << endl; } };
class D : public B, public C { public: void showD() { cout << "Class D (hybrid)" << endl; } };

void q4() {
    cout << "-- Single --" << endl; Circle c; c.draw(); c.area();
    cout << "-- Multiple --" << endl; Car car; car.start(); car.roll();
    cout << "-- Hierarchical --" << endl; Bus b; b.move(); b.board(); Bike bk; bk.ride();
    cout << "-- Multilevel --" << endl; Human h; h.breathe(); h.feed(); h.talk();
    cout << "-- Hybrid --" << endl; D d; d.showB(); d.showC(); d.showD();
}

// Q5: Constructors and Destructors in Inheritance
class BaseCD {
public:
    BaseCD() { cout << "Base Constructor" << endl; }
    ~BaseCD() { cout << "Base Destructor" << endl; }
};
class DerivedCD : public BaseCD {
public:
    DerivedCD() { cout << "Derived Constructor" << endl; }
    ~DerivedCD() { cout << "Derived Destructor" << endl; }
};
void q5() { DerivedCD d; }

// Q6: Book -> Textbook (Single Inheritance)
class Book {
protected:
    string title, author;
    float price;
public:
    Book(string t, string a, float p) : title(t), author(a), price(p) {}
    void display() { cout << "Title: " << title << ", Author: " << author << ", Price: " << price << endl; }
};
class Textbook : public Book {
private:
    string subject;
public:
    Textbook(string t, string a, float p, string s) : Book(t, a, p), subject(s) {}
    void display() { Book::display(); cout << "Subject: " << subject << endl; }
};
void q6() {
    Book b("Novel", "Author A", 299); b.display();
    Textbook tb("C++ Programming", "Stroustrup", 599, "Computer Science"); tb.display();
}

// Q7: Car Dashboard (Multiple Inheritance)
class Speedometer { protected: int speed = 80; public: void showSpeed() { cout << "Speed: " << speed << " km/h" << endl; } };
class FuelGauge   { protected: int fuel  = 60; public: void showFuel()  { cout << "Fuel: "  << fuel  << "%" << endl; } };
class Thermometer { protected: int temp  = 90; public: void showTemp()  { cout << "Temp: "  << temp  << "°C" << endl; } };
class CarDashboard : public Speedometer, public FuelGauge, public Thermometer {
public:
    void display() { showSpeed(); showFuel(); showTemp(); }
};
void q7() { CarDashboard dash; dash.display(); }

// Q8: Library User System (Hierarchical)
class LibraryUser {
protected:
    string name, id, contact;
public:
    LibraryUser(string n, string i, string c) : name(n), id(i), contact(c) {}
    void display() { cout << "Name: " << name << ", ID: " << id << ", Contact: " << contact << endl; }
};
class Student8 : public LibraryUser {
    string gradeLevel;
public:
    Student8(string n, string i, string c, string g) : LibraryUser(n,i,c), gradeLevel(g) {}
    void display() { LibraryUser::display(); cout << "Grade: " << gradeLevel << endl; }
};
class Teacher : public LibraryUser {
    string department;
public:
    Teacher(string n, string i, string c, string d) : LibraryUser(n,i,c), department(d) {}
    void display() { LibraryUser::display(); cout << "Dept: " << department << endl; }
};
void q8() {
    Student8 s("Dhruv", "S001", "9999", "3rd Year"); s.display();
    Teacher t("Dr. Aggarwal", "T001", "8888", "CSE"); t.display();
}

// Q9: Vehicle -> Truck -> RefrigeratedTruck (Multilevel)
class Vehicle9 {
protected: string make, model; int year;
public:
    Vehicle9(string mk, string mo, int y) : make(mk), model(mo), year(y) {}
    void display() { cout << make << " " << model << " (" << year << ")" << endl; }
};
class Truck : public Vehicle9 {
protected: float load_capacity;
public:
    Truck(string mk, string mo, int y, float lc) : Vehicle9(mk,mo,y), load_capacity(lc) {}
    void display() { Vehicle9::display(); cout << "Load: " << load_capacity << " tons" << endl; }
};
class RefrigeratedTruck : public Truck {
    float temperature_control;
public:
    RefrigeratedTruck(string mk, string mo, int y, float lc, float tc)
        : Truck(mk,mo,y,lc), temperature_control(tc) {}
    void display() { Truck::display(); cout << "Temp Control: " << temperature_control << "°C" << endl; }
};
void q9() { RefrigeratedTruck rt("Volvo","FH16",2022,20,-18); rt.display(); }

// Q10: Hybrid Inheritance - Teaching Assistant
class Person10 {
protected: string name, address;
public:
    Person10(string n="", string a="") : name(n), address(a) {}
    void display() { cout << "Name: " << name << ", Address: " << address << endl; }
};
class Staff : virtual public Person10 {
protected: string emp_id, dept;
public:
    Staff(string n="", string a="", string e="", string d="") : Person10(n,a), emp_id(e), dept(d) {}
    void display() { Person10::display(); cout << "EmpID: " << emp_id << ", Dept: " << dept << endl; }
};
class Student10 : virtual public Person10 {
protected: string stu_id, grade;
public:
    Student10(string n="", string a="", string s="", string g="") : Person10(n,a), stu_id(s), grade(g) {}
    void display() { Person10::display(); cout << "StuID: " << stu_id << ", Grade: " << grade << endl; }
};
class TeachingAssistant : public Staff, public Student10 {
public:
    TeachingAssistant(string n, string a, string e, string d, string s, string g)
        : Person10(n,a), Staff(n,a,e,d), Student10(n,a,s,g) {}
    void display() {
        Person10::display();
        cout << "EmpID: " << emp_id << ", Dept: " << dept << endl;
        cout << "StuID: " << stu_id << ", Grade: " << grade << endl;
    }
};
void q10() { TeachingAssistant ta("Pranav","LPU","E101","CSE","S202","A"); ta.display(); }

int main() {
    cout << "=== Q1: Single Inheritance ===" << endl; q1();
    cout << "\n=== Q2: Protected Access ===" << endl; q2();
    cout << "\n=== Q3: Inheritance Modes ===" << endl; q3();
    cout << "\n=== Q4: All Inheritance Types ===" << endl; q4();
    cout << "\n=== Q5: Constructor/Destructor in Inheritance ===" << endl; q5();
    cout << "\n=== Q6: Book -> Textbook ===" << endl; q6();
    cout << "\n=== Q7: Car Dashboard ===" << endl; q7();
    cout << "\n=== Q8: Library User System ===" << endl; q8();
    cout << "\n=== Q9: Multilevel (Vehicle) ===" << endl; q9();
    cout << "\n=== Q10: Hybrid - Teaching Assistant ===" << endl; q10();
    return 0;
}
