#include<iostream>
#include<cstdlib>
#include<fstream>
#include <iomanip>
#include<ctime>

using namespace std;

class Point{
	int x;
	int y;
	
	public:
	Point(){
		x=rand()%9+1;
		y=rand()%9+1;
	}
	
	friend istream& operator >> (istream&in, Point &p){
		char temp;
		in >> p.x;
		in >> temp;
		in >> p.y;
		return in;
	}
	
	friend ostream& operator << (ostream&out, Point &p){
		out << p.x << ',' << p.y << ' ';
		return out;
	}
};
int main()
{
	srand(time(0));
	Point p1[10];
	Point p2bin[10];
	Point p2txt[10];
	fstream file("data.txt",ios::out);
	for(int i=0;i<10;i++)
		file << p1[i];
	file.close();
	fstream filebin("data.bin",ios::out|ios::binary);
	filebin.write((char*) p1, sizeof(p1));
	filebin.close();
	
	file.open("data.txt",ios::in);
	filebin.open("data.bin",ios::in|ios::binary);
	file.seekg(0);
	filebin.seekg(0);
	
	for(int i=0;i<10;i++)
		file >> p2txt[i];
	file.close();
	filebin.read((char*) p2bin, sizeof(p2bin));
	filebin.close();
	
	filebin.open("data.bin",ios::app|ios::binary);
	int number = rand()%9+1;
	Point *p3 = new Point[number];
	filebin.write((char*) p3, sizeof(p3)*number);
	filebin.close();
	
	filebin.open("data.bin",ios::in|ios::binary);
	filebin.seekg(0, ios::end);
	int size=filebin.tellg()/8; //4 bytes x 4 bytes y
	filebin.seekg(0);
	Point *arr = new Point[size];
	filebin.read((char*) arr, sizeof(arr)*size);
	cout << "More Objects " << number <<endl;
	for(int i=0;i<size;i++)
		cout << arr[i] << '\n';
	filebin.close();
	delete[] p3;
	delete[] arr;
	return 0;
}
