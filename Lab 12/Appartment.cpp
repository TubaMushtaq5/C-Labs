#include<iostream>
#include<cstdlib>
#include"Room.cpp"
#include"AttachedKitchen.cpp"
#include"DoubleAttached.cpp"
#include"DoubleSeparate.cpp"
#include"SeparateKitchen.cpp" 
#include"Furnish.cpp" 
#include"furnish1.cpp" 
#include"furnish2.cpp"
#include"furnish3.cpp"  

using namespace std;

class Apartment{
	static int ApartmentNo;
	int Apartmentno;
	Room *rooms;
	Furnish *furnish; 
	
	public:
	Apartment(){
		ApartmentNo++;
		Apartment=ApartmentNo;
	}
	
	static int getappno(){
		return ApartmentNo;
	}
	
	int getapp(){
		return Apartment;
	}
	
	void AssignRoom(int type){
		if(type==1) rooms= new Attachedkitchen;
		if(type==2) rooms= new doubleSeparate;
		if(type==3) rooms= new doubleAttached;
		if(type==4) rooms= new SeparateKitchen;
	}
	
	void AssignFurnishing(int type){
		if(type==1) furnish= new furnish1;
		if(type==2) furnish= new furnish2;
		if(type==3) furnish= new furnish3;
	}
	
	void describe(){
		if (rooms==NULL)
			cout << "Show Details of room are missing";
		else 
			rooms->print();
			
		if(furnish==NULL)
			cout << "Show Details of room are missing";
		else 
			furnish->print();
	}
	
	void changeFurnishing(int type){
		delete []furnish;
		AssignFurnishing(type);
	}
	
	~Apartment(){
		delete [] rooms;
		delete [] furnish;
	}
};

int Apartment::ApartmentNo=0;

int main()
{
	Appartment obj1;
	obj1.AssignRoom(rand()%3+1);
	obj1.AssignFurnishing(rand()%3+1);
	cout << "Apartment No:" << Appartment::getappno;
	obj1.describe();
	
	Appartment obj;
	obj.AssignRoom(rand()%3+1);
	obj.AssignFurnishing(rand()%3+1);
	obj.describe();
	return 0;
}

