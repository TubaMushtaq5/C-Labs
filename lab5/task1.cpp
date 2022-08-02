#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

class Address{
	
	 int houseNo;//1-8
	 char floor;//a-d
	 char block;//A-J
	
public:	

 Address(int houseNo,char floor,char block){
	
	sethouseno(houseNo);
	setfloor(floor);
	setblock(block);
}
	
	void sethouseno(int houseno){
	 	
	 	if(houseno<1 || houseno>8)
	 		houseNo=1;
	 	else 
		    houseNo=houseno;
	 }
	
	void setfloor(char floorget){
	 	
	 	if(floorget!='a' && floorget!= 'b' && floorget!= 'c' && floorget!= 'd')
	 		floor='a';
	 	else 
	 	    floor=floorget;
	}
	
	void setblock(char blockget){
	 	
	 	if(blockget!='A' && blockget!= 'B' && blockget!= 'C' && blockget!= 'D' && blockget!='E' && blockget!= 'F' && blockget!= 'G' && blockget!= 'H'&& blockget!= 'I' && blockget!= 'J')
	 	  block='A';

	 	else block=blockget;
	}
	
	int gethouseno(int houseNo){
		return houseNo;
	}
	
	char getfloor(char floor){
		return floor;
	}
	
	char getblock(char block){
		return block;
	}
	
void show(){
	
	cout << "House No: " << houseNo<<endl;
	cout << "FLoor No: "  << floor << endl;
	cout << "Block No: "  << block << endl;
	cout << "------------------"<<endl;
}
	

};

int main(){
	

	Address a1(2,'a','C');
	Address a2(4,'a','C');
	Address a3(5,'c','D');
	a1.show();
	a2.show();
	a3.show();
	a1.setfloor('d');
	a2.setfloor('c');
	cout<<"Now A2 has floor: "<<a2.getfloor('c')<<'\n';
	cout<<"A3 has block:" <<a3.getblock('D')<<'\n';
	cout<<"A1 has house no: "<<a1.gethouseno(2)<<'\n';
return 0;
}
