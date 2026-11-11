#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {  
        cout << "Base Destructor Called" << endl;
    }
};

class Derived : public Base {
private:
    int* data;

public:
    Derived() {
        data = new int[100];
        cout << "Memory Allocated" << endl;
    }

    ~Derived() {
        delete[] data;
        cout << "Memory Freed" << endl;
    }
};

int main() {
    Base* ptr = new Derived();

    delete ptr;

    return 0;
}