#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

class employeeInfo {
private:
    string name;
    string streetAddress;
    string city;
    string state;
    string zipcode;
    string department;
    double salary;
    int ID;

public:
    void setID(int);//function to add an employees ID
    void employeeIntake();//employees info
    void giveRaise();//function to give raise to the employee
    void printEmployee();//function to print employ info
    void printEmployeeList(vector<employeeInfo>);
};

//function that adds an employees ID
void employeeInfo::setID(int id) {
    ID = id;
}

//employees info
void employeeInfo::employeeIntake() {
    cout << "Please enter employee's name: ";
    getline(cin, name);
    cout << "Street Address: ";
    getline(cin, streetAddress);
    cout << "City: ";
    getline(cin, city);
    cout << "State: ";
    getline(cin, state);
    cout << "Zipcode: ";
    getline(cin, zipcode);
    cout << "Department: ";
    getline(cin, department);
    cout << "Current Salary: ";
    cin >> salary;
    cin.ignore();// Clear the newline from the input buffer
}
//function that gives employees a raise
void employeeInfo::giveRaise() {
    int bump = 0;
    cout << fixed << setprecision(2);
    cout << name << "'s current salary is $" << salary << " per year. What % increase would you like to apply? " << endl;
    cin >> bump;
    cin.ignore();  // Clear the newline from the input buffer
    salary += (salary * bump) / 100;
    cout << name << "'s new salary is now $" << salary << " per year." << endl;
}
//function printing employees information
void employeeInfo::printEmployee() {
    cout << left;
    cout << setw(20) << "Employee ID: " << ID << endl;
    cout << setw(20) << "Name: " << name << endl;
    cout << setw(20) << "Street Address: " << streetAddress << endl;
    cout << setw(20) << "City: " << city << endl;
    cout << setw(20) << "State: " << state << endl;
    cout << setw(20) << "Zipcode: " << zipcode << endl;
    cout << setw(20) << "Department: " << department << endl;
    cout << fixed << setprecision(2);
    cout << setw(20) << "Salary:" << "$" << salary << endl;
    cout << "=================================================" << endl;
}


void employeeInfo::printEmployeeList(vector<employeeInfo> empList) {
    for (int i = 0; i < empList.size(); i++) {
        cout << i + 1 << ". " << empList.at(i).name << endl;
    }
}

int main() {
    int menu;
    int choice = 0;
    int empCount = 1200;  


    vector<employeeInfo> allEmployees;//vector to store all employees
    employeeInfo tempEmployee;//temperary storage for input

    cout << "This is the Employee Information System" << endl;
    cout << "Please select from the following menu options" << endl;

    do {
        //menu option for user to choose from
        cout << "Menu:" << endl;
        cout << "1. Add employee" << endl;
        cout << "2. Give an employee a raise" << endl;
        cout << "3. Print an employee's info" << endl;
        cout << "4. Print all employee info" << endl;
        cout << "5. Exit" << endl;
        cin >> menu;//user entering a choice from the menu
        cin.ignore();  // Clear the newline from the input buffer

        if (menu == 1) {
            tempEmployee.setID(empCount);
            tempEmployee.employeeIntake();
            allEmployees.push_back(tempEmployee);
            empCount++;
        }


        //giving an employee a raise
        if (menu == 2) {
            if (allEmployees.empty()) {
                cout << "There are no employees listed in the system yet, please add one first." << endl;
            }
            else {
                cout << "Pick an Employee: " << endl;
                tempEmployee.printEmployeeList(allEmployees);
                cout << "Enter Choice: ";
                cin >> choice;//users choice of an employee
                cin.ignore();  // Clear the newline from the input buffer
                allEmployees.at(choice - 1).giveRaise();
            }
        }


        //printing an employees info
        if (menu == 3) {
            if (allEmployees.empty()) {
                cout << "There are no employees listed in the system yet, please add one first." << endl;
            }
            else {
                cout << "Pick an Employee: " << endl;
                tempEmployee.printEmployeeList(allEmployees);
                cout << "Enter Choice: ";
                cin >> choice;
                cin.ignore();  // Clear the newline from the input buffer
                allEmployees.at(choice - 1).printEmployee();
            }
        }


        //printing all employees info
        if (menu == 4) {
            if (allEmployees.empty()) {
                cout << "Employee not found, please add one." << endl;
            }
            else {
                for (int i = 0; i < allEmployees.size(); i++) {
                    allEmployees.at(i).printEmployee();
                }
            }
        }


        //exiting
        if (menu == 5) {
            cout << "Thank you for using the Employee Information System" << endl;
        }
        //wrong input from the menu option
        if (menu < 1 || menu > 5) {
            cout << "Invalid Entry, try again.\n";
        }
    } while (menu != 5);

    cout << "The Program will be shutting down." << endl;
    return 0;
}
