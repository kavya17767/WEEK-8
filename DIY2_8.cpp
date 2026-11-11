#include <iostream>
#include <fstream>
using namespace std;

class Logger {
public:
    virtual void write(string msg) = 0;
    virtual ~Logger() {}
};

class ConsoleLogger : public Logger {
public:
    void write(string msg) override {
        cout << "Console Log: " << msg << endl;
    }
};

class FileLogger : public Logger {
public:
    void write(string msg) override {
        ofstream file("log.txt", ios::app);

        if (file.is_open()) {
            file << msg << endl;
            file.close();
            cout << "Message written to log.txt" << endl;
        }
    }
};

int main() {
    Logger* logger;

    int choice;

    cout << "1. Console Logger\n";
    cout << "2. File Logger\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
        logger = new ConsoleLogger();
    else
        logger = new FileLogger(); /

    logger->write("Hello, this is a test log!");

    delete logger;

    return 0;
}