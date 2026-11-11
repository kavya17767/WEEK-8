#include <iostream>
using namespace std;

class Account {
protected:
    double balance;

public:
    Account(double b) {
        balance = b;
    }

    virtual double calculateInterest() = 0; 

    virtual void display() {
        cout << "Balance: " << balance << endl;
    }

    virtual ~Account() {}
};

class Savings : public Account {
public:
    Savings(double b) : Account(b) {}

    double calculateInterest() override {
        return balance * 0.05; 
    }
};

class Current : public Account {
public:
    Current(double b) : Account(b) {}

    double calculateInterest() override {
        return balance * 0.02; 
    }
};

int main() {
    Account* accounts[2];

    accounts[0] = new Savings(10000);
    accounts[1] = new Current(10000);

    for (int i = 0; i < 2; i++) {
        accounts[i]->display();
        cout << "Interest = " << accounts[i]->calculateInterest() << endl;
        cout << endl;
    }

    for (int i = 0; i < 2; i++) {
        delete accounts[i];
    }

    return 0;
}