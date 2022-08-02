#include<iostream>
#include<fstream>
#include<cstdlib>
#include <iomanip>
#include<ctime>

using namespace std;

void display1D_2D(int *x, const int ROWS, const int COLS){
	for(int i=0;i<ROWS;i++){
		for(int j=0;j<COLS;j++)
			cout << x[i*COLS+j] <<' ';
		cout <<'\n';
	}	
}

void addValues(){

	int values;
	cout << "Enter number of Values: "; 
	cin >> values;
	int *arr = new int[values];
	for(int i=0;i<values;i++)
		arr[i]=rand()%89+11;
		
	fstream file("file.txt",ios::app);
	for(int i=0;i<values;i++)
		file << arr[i] << ' ';
	delete []arr;
	file.close();
}

void searchValue(){
	int number,index=0;
	cout << "Enter the number to search: "; 
	cin >> number;
	fstream openfile("file.txt",ios::in);
	int c[200];
	for(int i=0;!openfile.eof();i++){
		openfile >> c[i];
		if(c[i]==number)
			index=i;
	}
	if(index)
		cout << number <<" found at position " << index << endl;
	else
		cout << number <<" Not found" <<endl;
	openfile.close();

}

void modifyValue(){
	
	int find, replace,position;
	cout << "Input number to find " << endl; 
	cin >> find;
	cout << "\nInput number to replace:" << endl;
	cin >> replace;
	fstream readwrite("file.txt",ios::in|ios::out);
	int c[200];
	for(int i=0;!readwrite.eof();i++){
		readwrite >> c[i];
		if(c[i]==find){
			position=readwrite.tellg();
			readwrite.seekp(position-2);
			readwrite << replace ;
		}
	}
	readwrite.close();
}
void deleteValue(){
	int number;
	cout << "Enter the number to delete: "; 
	cin >> number;
}
void deleteAllValues(){
	fstream deletefile("file.txt",ios::out);
	deletefile.close();
}
void showAll(){
	fstream openfile("file.txt",ios::in);
	int c[200];
	while(1){
		int i=0;
		openfile >> c[i] ;
		if (c[0]==openfile.eof())
			cout << "File is empty" << endl;
		if(c[i]==openfile.eof())
			break;
		i++;
	}
}
void showMenu(){
	cout << "\t1. Add values\n\t2. Search value\n\t3. Modify value\n";
	cout << "\t4. Delete value\n\t5. Delete all values\n\t6.Show All\n";
	cout << "\t7. Quit\n\n\tEnter Choice: ";
}

int main(){
	
	srand(time(0));
	
	int choice;
	do{
		showMenu();
		cin >> choice;
		switch(choice){
			case 1: addValues(); break;
			case 2: searchValue(); break;
			case 3: modifyValue(); break;
			case 4: deleteValue(); break; 
			case 5: deleteAllValues(); break;
			case 6: showAll(); break;
			default: cout << "Invalid Input\n";
		}
	}while (choice != 7);
	cout << "\n\n\tThanks! End of Program\n"; 
	return 0;
}
