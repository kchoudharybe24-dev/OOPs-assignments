// LAB ASSIGNMENT - 1
// Name: Kshaaunish Choudhary 
// Roll No: 1024150193

#include <iostream>
#include <string>
using namespace std;

// Q1: Display "Hello World"
void q1() {
    cout << "Hello World" << endl;
}

// Q2: Read two values and display the larger
void q2() {
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;
    cout << "Larger value: " << (a > b ? a : b) << endl;
}

// Q3: Read a, b, c and display x = a/b-c
void q3() {
    float a, b, c;
    cout << "Enter a, b, c: ";
    cin >> a >> b >> c;
    if (b - c == 0) { cout << "Division by zero error." << endl; return; }
    cout << "x = " << a / (b - c) << endl;
}

// Q4: Control characters
void q4() {
    cout << "New line:\nTabbed:\tText\nAlarm:\a\nCarriage return:\rOverwritten" << endl;
}

// Q5: Namespace
namespace MathLib {
    int add(int a, int b) { return a + b; }
    int value = 100;
}
namespace StringLib {
    string add(string a, string b) { return a + b; }
    int value = 200;
}
void q5() {
    cout << "MathLib add: " << MathLib::add(3, 4) << endl;
    cout << "StringLib add: " << StringLib::add("Hello", " World") << endl;
    cout << "MathLib value: " << MathLib::value << ", StringLib value: " << StringLib::value << endl;
}

// Q6: Structure Student
struct Student {
    string name;
    int roll;
    float marks;
    void setStudentData(string n, int r, float m) { name = n; roll = r; marks = m; }
    void getStudentData() { cout << "Name: " << name << ", Roll: " << roll << ", Marks: " << marks << endl; }
};
void q6() {
    Student s;
    s.setStudentData("Kshaaunish Choudhary", 1024150193, 99.2);
    s.getStudentData();
}

// Q7: Make data private, functions public (class version)
class StudentClass {
private:
    string name;
    int roll;
    float marks;
public:
    void setStudentData(string n, int r, float m) { name = n; roll = r; marks = m; }
    void getStudentData() { cout << "Name: " << name << ", Roll: " << roll << ", Marks: " << marks << endl; }
};
void q7() {
    StudentClass s;
    s.setStudentData("Kshaaunish Choudhary", 1024150193, 87.0);
    s.getStudentData();
}

// Q8: Convert struct to class
class StudentQ8 {
private:
    string name;
    int roll;
    float marks;
    string controlChars() { return "\n\t\a\r"; } // private helper
public:
    void setData(string n, int r, float m) { name = n; roll = r; marks = m; }
    void displayData() { cout << "Name: " << name << ", Roll: " << roll << ", Marks: " << marks << endl; }
};
void q8() {
    StudentQ8 s;
    s.setData("Kshaaunish Choudhary", 1024150193, 86.0);
    s.displayData();
}

// Q10: Print "WELL DONE" n times
void q10() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    for (int i = 0; i < n; i++) cout << "WELL DONE" << endl;
}

// Q11: += and -= operators
void q11() {
    int x = 10;
    x += 5; cout << "After +=5: " << x << endl;
    x -= 3; cout << "After -=3: " << x << endl;
}

// Q12: Swap using bitwise XOR
void q12() {
    int a = 5, b = 9;
    cout << "Before: a=" << a << " b=" << b << endl;
    a ^= b; b ^= a; a ^= b;
    cout << "After swap: a=" << a << " b=" << b << endl;
}

// Q13: Library fine
void q13() {
    int days;
    cout << "Enter number of days late: ";
    cin >> days;
    if (days > 30) cout << "Membership cancelled." << endl;
    else if (days > 10) cout << "Fine: Rs. " << days * 5 << endl;
    else if (days > 5)  cout << "Fine: Rs. " << days * 1 << endl;
    else                cout << "Fine: " << days * 0.5 << " paise (Rs. " << days * 0.005 << ")" << endl;
}

int main() {
    cout << "=== Q1: Hello World ===" << endl; q1();
    cout << "\n=== Q5: Namespace ===" << endl; q5();
    cout << "\n=== Q6: Structure ===" << endl; q6();
    cout << "\n=== Q7: Class (private data) ===" << endl; q7();
    cout << "\n=== Q8: Struct to Class ===" << endl; q8();
    cout << "\n=== Q11: += and -= ===" << endl; q11();
    cout << "\n=== Q12: Swap using bitwise ===" << endl; q12();
    return 0;
}
