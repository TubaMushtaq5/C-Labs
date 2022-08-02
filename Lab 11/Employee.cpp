#ifndef EMPLOYEE
#define EMPLOYEE
#include <iostream>

using namespace std;

class Employee{
protected:
	int empNo, basicSalary, currentMonthSalary;
	static int employeeCount;
public:
	Employee(int bSalary){
		basicSalary=bSalary;
		empNo=employeeCount++;
	}
	friend ostream& operator << (ostream &out, const Employee &employee){	
		out<<"Employee Number:"<<employee.empNo<<'\n';
		out<<"Basic Salary:  "<<employee.basicSalary<<'\n';
		return out;
	}
	int calculateSalary(){
		//45% house rent, 10% medical allowance
		currentMonthSalary = basicSalary + basicSalary * 0.45 + basicSalary * 0.1;
		return currentMonthSalary;
	}
};
int Employee::employeeCount=1;
#endif
