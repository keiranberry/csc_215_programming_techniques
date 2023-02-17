#pragma once
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

using namespace std;

struct empData
{
    int id;
    char firstName[20];
    char lastName[40];
    double salary;
    double bonus;
};

void printFile(fstream &fileIn);
bool applyRaise(fstream &fileIn, int empId, float empRaise);

int main(int argc, char** argv)
{
    fstream file;
    int idInt;
    float raiseF;
    bool empFound;
    if (argc != 4)
    {
        cout << "Usage: m0041.exe binaryData employeeID salaryRaise" << endl;
        return 0;
    }
    file.open(argv[1], ios::in | ios::out | ios::binary);
    if (!file.is_open())
    {
        cout << "Unable to open binary file: " << argv[1] << endl;
        return 0;
    }
    idInt = atoi(argv[2]);
    raiseF = stof(argv[3]);
    printFile(file);
    cout << endl;
    file.clear();
    file.seekg(ios::beg);
    empFound = applyRaise(file, idInt, raiseF);
    if (empFound == true)
    {
        cout << "Employee ID " << argv[2] << " has been updated." << endl << endl;
    }
    else
    {
        cout << "Employee ID " << argv[2] << " was not found." << endl << endl;
    }
    file.clear();
    file.seekg(ios::beg);
    printFile(file);
    file.close();
    return 0; 
}

void printFile(fstream &fileIn)
{
    empData emp;
    while (fileIn.read((char*)&emp, sizeof(empData)))
    {
        cout << setw(7) << emp.id << " "
            << left << setw(20) << emp.firstName
            << setw(40) << emp.lastName << right
            << setprecision(2) << fixed << " Salary: " << setw(10) 
            << emp.salary << " Bonus: " << setw(10) << emp.bonus << endl;
    }
}

bool applyRaise(fstream &fileIn, int empId, float empRaise)
{
    empData emp;
    int count = 0;
    bool found = false;
    while (fileIn.read((char*)&emp, sizeof(empData)))
    {
        count++;
        if (emp.id == empId)
        {
            found = true;
            emp.salary = emp.salary + empRaise;
            emp.salary = trunc(emp.salary);
            fileIn.seekp((count - 1) * sizeof(empData));
            fileIn.write((char*)&emp, sizeof(empData));
            return found;
        }
    }
    return found;
}