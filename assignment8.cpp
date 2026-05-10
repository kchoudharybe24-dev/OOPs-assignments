// Kshaaunish Choudhary 
// 1024150193

//Part A: Function Templates
//Q1. Function Template to Swap Two Variables
//A function template swap() that exchanges the values of two variables of any data type:

#include <iostream>
using namespace std;

template <typename T>
void swapValues(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swapValues(x, y);
    cout << "After swap:  x = " << x << ", y = " << y << endl;

    double a = 3.14, b = 2.71;
    swapValues(a, b);
    cout << "After swap:  a = " << a << ", b = " << b << endl;

    string s1 = "Hello", s2 = "World";
    swapValues(s1, s2);
    cout << "After swap:  s1 = " << s1 << ", s2 = " << s2 << endl;

    return 0;
}


//Q2. Function Template to Find Minimum Element in an Array
//A function template findMin() that returns the smallest element in an array of any data type:

#include <iostream>
using namespace std;

template <typename T>
T findMin(T arr[], int size) {
    T minVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < minVal)
            minVal = arr[i];
    }
    return minVal;
}

int main() {
    int intArr[] = {5, 3, 8, 1, 9, 2};
    int n = 6;
    cout << "Min in int array: " << findMin(intArr, n) << endl;

    double dblArr[] = {3.5, 1.2, 7.8, 0.4};
    cout << "Min in double array: " << findMin(dblArr, 4) << endl;

    char charArr[] = {'z', 'a', 'm', 'b'};
    cout << "Min in char array: " << findMin(charArr, 4) << endl;

    return 0;
}


//Q3. Function Template to Sort an Array Using Bubble Sort
//A function template bubbleSort() that sorts an array of any comparable data type in ascending order:

#include <iostream>
using namespace std;

template <typename T>
void bubbleSort(T arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    cout << "Before sort: "; printArray(arr, n);
    bubbleSort(arr, n);
    cout << "After sort:  "; printArray(arr, n);

    double dArr[] = {5.5, 1.1, 3.3, 2.2};
    bubbleSort(dArr, 4);
    cout << "Sorted doubles: "; printArray(dArr, 4);

    return 0;
}


//Q4. Function Template to Perform Linear Search
//A function template linearSearch() that searches for a key in an array and returns its index (or -1 if not found):

#include <iostream>
using namespace std;

template <typename T>
int linearSearch(T arr[], int size, T key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;  // Not found
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int idx = linearSearch(arr, 5, 30);
    if (idx != -1)
        cout << "Found 30 at index: " << idx << endl;
    else
        cout << "30 not found" << endl;

    string sArr[] = {"apple", "banana", "cherry"};
    int sidx = linearSearch(sArr, 3, string("banana"));
    cout << "Found 'banana' at index: " << sidx << endl;

    int missing = linearSearch(arr, 5, 99);
    cout << "Search for 99: " << (missing == -1 ? "Not found" : "Found") << endl;

    return 0;
}


//Q5. Overloaded Versions of Function Template process()
//Three overloaded versions of process(): accepting one parameter, two parameters of the same type, and two parameters of different types:

#include <iostream>
using namespace std;

// i) Single parameter
template <typename T>
void process(T a) {
    cout << "process(single): " << a << endl;
}

// ii) Two parameters of the same type
template <typename T>
void process(T a, T b) {
    cout << "process(same type): " << a << " and " << b << endl;
    cout << "  Sum = " << (a + b) << endl;
}

// iii) Two parameters of different types
template <typename T1, typename T2>
void process(T1 a, T2 b) {
    cout << "process(diff types): " << a << " and " << b << endl;
}

int main() {
    process(42);             // single int
    process(3.14);           // single double
    process('A');            // single char

    process(10, 20);         // two ints
    process(1.5, 2.5);       // two doubles

    process(100, 3.14);      // int and double
    process('X', 99);        // char and int

    return 0;
}


//Part B: Class Templates
//Q6. Class Template for Stack with Push and Pop Operations
//A generic Stack class template supporting push() and pop() operations with any data type:

#include <iostream>
using namespace std;

template <typename T>
class Stack {
    T data[100];
    int top;
public:
    Stack() : top(-1) {}

    void push(T val) {
        if (top >= 99) { cout << "Stack Overflow!" << endl; return; }
        data[++top] = val;
        cout << val << " pushed onto stack." << endl;
    }

    void pop() {
        if (top < 0) { cout << "Stack Underflow!" << endl; return; }
        cout << data[top--] << " popped from stack." << endl;
    }

    T peek() const {
        if (top < 0) { cout << "Stack is empty!" << endl; return T(); }
        return data[top];
    }

    bool isEmpty() const { return top == -1; }
};

int main() {
    Stack<int> s;
    s.push(10); s.push(20); s.push(30);
    cout << "Top: " << s.peek() << endl;
    s.pop(); s.pop();
    cout << "Top after pops: " << s.peek() << endl;

    Stack<string> ss;
    ss.push("Hello"); ss.push("World");
    ss.pop();

    return 0;
}


//Q7. Class Template for Queue with Enqueue and Dequeue Operations
//A generic Queue class template supporting enqueue() and dequeue() operations:

#include <iostream>
using namespace std;

template <typename T>
class Queue {
    T data[100];
    int front, rear, count;
public:
    Queue() : front(0), rear(-1), count(0) {}

    void enqueue(T val) {
        if (count >= 100) { cout << "Queue Full!" << endl; return; }
        data[++rear] = val;
        count++;
        cout << val << " enqueued." << endl;
    }

    void dequeue() {
        if (count == 0) { cout << "Queue Empty!" << endl; return; }
        cout << data[front++] << " dequeued." << endl;
        count--;
    }

    T getFront() const {
        if (count == 0) { cout << "Queue is empty!" << endl; return T(); }
        return data[front];
    }

    bool isEmpty() const { return count == 0; }
};

int main() {
    Queue<int> q;
    q.enqueue(1); q.enqueue(2); q.enqueue(3);
    cout << "Front: " << q.getFront() << endl;
    q.dequeue(); q.dequeue();
    cout << "Front after dequeues: " << q.getFront() << endl;

    Queue<double> qd;
    qd.enqueue(1.1); qd.enqueue(2.2);
    qd.dequeue();

    return 0;
}


//Q8. Class Template to Store and Display a Pair of Values
//A generic Pair class template that stores and displays two values, which may be of the same or different types:

#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Pair {
    T1 first;
    T2 second;
public:
    Pair(T1 f, T2 s) : first(f), second(s) {}

    void display() const {
        cout << "Pair: (" << first << ", " << second << ")" << endl;
    }

    T1 getFirst() const  { return first; }
    T2 getSecond() const { return second; }
};

int main() {
    Pair<int, int> p1(10, 20);
    p1.display();

    Pair<string, int> p2("Age", 21);
    p2.display();

    Pair<double, char> p3(3.14, 'P');
    p3.display();

    Pair<string, string> p4("Hello", "World");
    p4.display();

    return 0;
}



//Q9. Class Template for Basic Arithmetic Operations
//A generic Calculator class template that performs addition, subtraction, multiplication, and division:

#include <iostream>
using namespace std;

template <typename T>
class Calculator {
    T a, b;
public:
    Calculator(T x, T y) : a(x), b(y) {}

    T add()      const { return a + b; }
    T subtract() const { return a - b; }
    T multiply() const { return a * b; }

    T divide() const {
        if (b == 0) { cout << "Error: Division by zero!" << endl; return 0; }
        return a / b;
    }

    void showAll() const {
        cout << a << " + " << b << " = " << add()      << endl;
        cout << a << " - " << b << " = " << subtract() << endl;
        cout << a << " * " << b << " = " << multiply() << endl;
        cout << a << " / " << b << " = " << divide()   << endl;
    }
};

int main() {
    cout << "--- Integer Calculator ---" << endl;
    Calculator<int> ci(10, 3);
    ci.showAll();

    cout << "--- Double Calculator ---" << endl;
    Calculator<double> cd(10.0, 3.0);
    cd.showAll();

    return 0;
}


//Q10. Class Template to Input and Display Array Elements
//A generic Array class template that stores, inputs, and displays elements of any data type:

#include <iostream>
using namespace std;

template <typename T>
class Array {
    T* arr;
    int size;
public:
    Array(int n) : size(n) {
        arr = new T[size];
    }

    ~Array() { delete[] arr; }

    void input() {
        cout << "Enter " << size << " elements: " << endl;
        for (int i = 0; i < size; i++) {
            cout << "  Element[" << i << "]: ";
            cin >> arr[i];
        }
    }

    void display() const {
        cout << "Array elements: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    T& operator[](int i) { return arr[i]; }
};

int main() {
    // Demo with pre-filled values (avoids cin in non-interactive runs)
    Array<int> intArr(5);
    for (int i = 0; i < 5; i++) intArr[i] = (i + 1) * 10;
    cout << "Integer "; intArr.display();

    Array<double> dblArr(4);
    dblArr[0]=1.1; dblArr[1]=2.2; dblArr[2]=3.3; dblArr[3]=4.4;
    cout << "Double  "; dblArr.display();

    Array<char> chrArr(4);
    chrArr[0]='A'; chrArr[1]='B'; chrArr[2]='C'; chrArr[3]='D';
    cout << "Char    "; chrArr.display();

    return 0;
}
