#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


class Point{
	int x, y;
public:
	Point(){
		this->x = rand()%10;
		this->y = rand()%10;
	}
	
	bool operator == (const Point &p){
		return (x==p.x&&y==p.y);
	}
	
	friend ostream& operator << (ostream &out, const Point &p){
		cout << '(' << p.x << ',' << p.y <<')';
	}
};

template <class T>
class Set{
	T *dataset;
	int currentSize;
	int size;
	void resize(int newSize){
		size = newSize;
		T *temp = new T[size];
		for (int i=0;i<currentSize;i++)
			temp[i] = dataset[i];
		delete []dataset;
		dataset = temp;
	}
	void MemoryAllocation(int size){
		dataset = new T[size];
		currentSize = 0;
	}
	void copyfunc(const	Set& set){
		this->size = set.size;
		MemoryAllocation(size);
		for(int i=0;i<size;i++)
			dataset[i]= set.dataset[i];
	}
	void deleteMemory(){
		delete[] dataset;
	}
public:
	
	Set(){
		this->size = 10;
		MemoryAllocation(size);
	}
	
	void setsize(int size){
		if (size<=0)	size = 10;
		this->size = size;
	}
	
	Set(int size){
		setsize(size);
		MemoryAllocation(size);
	}
	
	Set(T arr[], int size){
		setsize(size);
		MemoryAllocation(size);
		for(int i=0;i<size;i++)
			addElement(arr[i]);
	}
	
	Set(const Set &set){
		copyfunc(set);	
	}
	
	void operator = (const Set &set){
		deleteMemory();
		copyfunc(set);
	}
	void addElement(const T ELEMENT){
		int ifonlyone = 1;
		if (currentSize == size)	resize(size*2);
		for(int i=0;i<currentSize;i++)
			if(dataset[i]==ELEMENT)
				ifonlyone = 0;
		if(ifonlyone)
			dataset[currentSize++] = ELEMENT;
	}
	
	friend ostream& operator << (ostream &out, const Set &set){
		int i;
		for (i=0;i<set.currentSize-1;i++)
			out << set.dataset[i] << ", ";
		out << set.dataset[i]; 
		return out;
	}
	~Set(){
		deleteMemory();
	}
};

template <class type>
class SetList{
	Set <type> *set[10];

int main(){
	srand(time(0));
	Point point1, point2, point3, point4;
	
	Set <Point> Allpoints(2);
	
	Allpoints.addElement(point1);
	Allpoints.addElement(point2);
	Allpoints.addElement(point3);
	Allpoints.addElement(point4);
	Allpoints.addElement(point2); 

	cout << Allpoints <<'\n';
	return 0;
}
