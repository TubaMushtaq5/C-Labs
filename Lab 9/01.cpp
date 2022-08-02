#include<iostream>
#include<cstdlib>
#include<fstream>
#include <iomanip>
#include<ctime>

using namespace std;

int main()
{
	srand(time(0));
	fstream file("file.txt",ios::out);
	for(int i=0;i<20;i++)
		file << setw(4) <<rand()%100;
	file.close();
	file.open("file.txt",ios::in|ios::out);
	
	while(1){
		int x;
		file >> x ;
		if(file.eof())
			break;
		cout << setw(4)<< x;
	}
	file.seekg(0,ios::beg);
	cout << '\n';
	while(1){
		int y;
		file >> y ;
		if(file.eof())
			break;
		if(y%2==1){
			int position=file.tellg();
			while(y%2==1){
				if (file.eof())
					break;
				file >> setw(4) >> y;
			}
			file.seekg(position);
			file.seekp(position-4);
			file << setw(4) << y;
		}
	}
	file.close();
	
	file.seekg(0,ios::beg);
	file.open("file.txt",ios::in);
	while(1){
		int z;
		file >> z ;
		if(file.eof())
			break;
		cout <<setw(4) << z;
	}
	return 0;
}
