// LAB ASSIGNMENT - 6
// Name: Kshaaunish Choudhary
// Roll No: 1024150193

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Q1: Library class with array of Book objects

class Book {
public:
    string title, author, ISBN;
    Book(string t = "", string a = "", string i = "") : title(t), author(a), ISBN(i) {}
};

class Library {
private:
    Book books[100];
    int count = 0;
public:
    bool addNewBook(string title, string author, string ISBN) {
        if (count >= 100) return false;
        books[count++] = Book(title, author, ISBN);
        return true;
    }
    bool removeBooks(string ISBN) {
        for (int i = 0; i < count; i++) {
            if (books[i].ISBN == ISBN) {
                for (int j = i; j < count - 1; j++) books[j] = books[j+1];
                count--;
                return true;
            }
        }
        return false;
    }
    void displayDetails() {
        cout << "Library Books (" << count << "):" << endl;
        for (int i = 0; i < count; i++)
            cout << "  " << i+1 << ". " << books[i].title << " by " << books[i].author
                 << " [ISBN: " << books[i].ISBN << "]" << endl;
    }
};

void q1() {
    Library lib;
    lib.addNewBook("C++ Primer", "Lippman", "ISBN001");
    lib.addNewBook("Clean Code", "Martin", "ISBN002");
    lib.addNewBook("OOPS Concepts", "Balaguruswamy", "ISBN003");
    lib.addNewBook("Design Patterns", "Gang of Four", "ISBN004");
    lib.addNewBook("The Pragmatic Programmer", "Hunt", "ISBN005");
    lib.displayDetails();
    cout << "Removing ISBN002..." << endl;
    lib.removeBooks("ISBN002");
    lib.displayDetails();
}

// Q2: Book Class with constructors, this pointer, array of obj

class Book2 {
private:
    string title, author, ISBN;
public:
    // Default constructor
    Book2() { this->title = ""; this->author = ""; this->ISBN = ""; }
    // Parameterized constructor
    Book2(string title, string author, string ISBN) {
        this->title  = title;
        this->author = author;
        this->ISBN   = ISBN;
    }
    // Copy constructor
    Book2(const Book2 &b) {
        this->title  = b.title;
        this->author = b.author;
        this->ISBN   = b.ISBN;
    }
    bool removeBooks(string ISBN) { return (this->ISBN == ISBN); }
    void displayDetails() {
        cout << this->title << " | " << this->author << " | " << this->ISBN << endl;
    }
};

void q2() {
    // 1. Initializer list
    Book2 arr1[3] = {
        Book2("C++ Primer", "Lippman", "A01"),
        Book2("Clean Code", "Martin", "A02"),
        Book2("OOPS", "Bala", "A03")
    };
    cout << "Initializer list:" << endl;
    for (int i = 0; i < 3; i++) arr1[i].displayDetails();

    // 2. Dynamic initialization
    Book2 *arr2 = new Book2[3];
    arr2[0] = Book2("Design Patterns", "GoF", "B01");
    arr2[1] = Book2("Pragmatic Prog", "Hunt", "B02");
    arr2[2] = Book2("Refactoring", "Fowler", "B03");
    cout << "Dynamic initialization:" << endl;
    for (int i = 0; i < 3; i++) arr2[i].displayDetails();
    delete[] arr2;
}

// Q3: Account Class

class Account {
private:
    const long accountNumber;
    long transactionID;
    string transactionType;
    double balance;
public:
    Account(long accNo, double initialBalance) :
        accountNumber(accNo), balance(initialBalance), transactionID(1000) {}

    long depositAmount(const long to, const long from, const double amount) {
        if (accountNumber == to) {
            balance += amount;
            transactionType = "Credited";
        }
        transactionID++;
        cout << "Deposit TxnID: " << transactionID << endl;
        return transactionID;
    }
    long creditAmount(const long to, const long from, const double amount) {
        if (accountNumber == from) {
            balance -= amount;
            transactionType = "Debited";
        }
        transactionID++;
        cout << "Debit TxnID: " << transactionID << endl;
        return transactionID;
    }
    void displayDetails() const {
        cout << "Account: " << accountNumber
             << " | Balance: " << balance
             << " | Last Txn: " << transactionType << endl;
    }
};

void q3() {
    Account accounts[5] = {
        Account(1001, 5000), Account(1002, 3000),
        Account(1003, 7000), Account(1004, 2000), Account(1005, 9000)
    };
    accounts[0].depositAmount(1001, 1002, 500);
    accounts[1].creditAmount(1001, 1002, 500);
    accounts[2].depositAmount(1003, 1004, 1500);
    cout << "\nAccount Details:" << endl;
    for (int i = 0; i < 5; i++) accounts[i].displayDetails();
}

// Q4: Friend Function - Add objects of two different classes

class ClassP;
class ClassQ {
    int q;
public:
    ClassQ(int val) : q(val) {}
    friend int addTwoClasses(ClassP, ClassQ);
};
class ClassP {
    int p;
public:
    ClassP(int val) : p(val) {}
    friend int addTwoClasses(ClassP, ClassQ);
};
int addTwoClasses(ClassP a, ClassQ b) { return a.p + b.q; }

void q4() {
    ClassP p(30);
    ClassQ q(70);
    cout << "Sum: " << addTwoClasses(p, q) << endl;
}

// Q5: Complex Number Class with friend sum function

class Complex {
private:
    float real, imaginary;
public:
    Complex(float r = 0, float i = 0) : real(r), imaginary(i) {}
    Complex(const Complex &c) : real(c.real), imaginary(c.imaginary) {}
    void display() {
        cout << real << (imaginary >= 0 ? " + " : " - ") << abs(imaginary) << "i" << endl;
    }
    friend void sum(Complex c1, Complex c2);
};

void sum(Complex c1, Complex c2) {
    Complex result(c1.real + c2.real, c1.imaginary + c2.imaginary);
    cout << "Sum: "; result.display();
}

void q5() {
    Complex c1(3.5f, 2.0f), c2(1.5f, -1.0f);
    cout << "C1: "; c1.display();
    cout << "C2: "; c2.display();
    sum(c1, c2);
    Complex c3(c1);  // copy constructor
    cout << "C3 (copy of C1): "; c3.display();
}

int main() {
    cout << "=== Q1: Library Class ===" << endl; q1();
    cout << "\n=== Q2: Book with Constructors & this ===" << endl; q2();
    cout << "\n=== Q3: Account Class ===" << endl; q3();
    cout << "\n=== Q4: Friend Function (two classes) ===" << endl; q4();
    cout << "\n=== Q5: Complex Number Class ===" << endl; q5();
    return 0;
}
