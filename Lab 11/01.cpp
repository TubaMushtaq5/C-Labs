#include <iostream>
#include "Employee.cpp"

using namespace std;

class RegularEmployee:public Employee{
	
	public:
	RegularEmployee(int basicSalary):
		Employee(basicSalary){
	}
	
	friend ostream& operator << (ostream &out, const RegularEmployee &regularemployee){
		out << (Employee)regularemployee;
		out << "Salary: " << regularemployee.currentMonthSalary <<endl;
		return out;
	}
};

class SalesMan:public Employee{
	
	float commissionrate;
	public:
	SalesMan(int basicSalary, float commissionrate) :Employee(basicSalary){
		this->commissionrate=commissionrate; 
	}
	
	calculateSalary(int sales){
		Employee::calculateSalary();
		currentMonthSalary=sales*commissionrate+currentMonthSalary;
	}
	
	friend ostream& operator << (ostream &out, const SalesMan &regularemployee){
		out << (Employee)regularemployee;
		out << "Salary: " << regularemployee.currentMonthSalary <<endl;
		return out;
	}
};


int main(){
	int temp;
	RegularEmployee emp1(30000);
	emp1.calculateSalary();
	cout<<emp1;
	cout<<"\n***************\n\n";
	SalesMan emp2(20000,0.02);
	emp2.calculateSalary(200000);
	cout<<emp2;
	cout<<"\n***************\n\n";
	Employee *emp=new RegularEmployee(35000);
	cout<<*emp;//Calling ostream of Employee
	delete emp;
	cout<<"\n***************\n\n";
	emp=new SalesMan(25000,0.03);
	((SalesMan*)emp)->calculateSalary(180000);
	cout<<*emp;//Calling ostream of Employee
	delete emp;
	return 0;
}


