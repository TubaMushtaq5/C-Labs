#include <iostream>

using namespace std;

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
			dataset[currentSize++]= set.dataset[i];
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
int main(){
	Set <int> set1(2);
	set1.addElement(23);
	set1.addElement(19);
	set1.addElement(50);
	set1.addElement(17);
	set1.addElement(18);
	set1.addElement(20);	
	cout << "{" <<set1 << "}" <<'\n';
	
	Set <char> set2(2);
	set2.addElement('I');
	set2.addElement('M');
	set2.addElement('A');
	set2.addElement('A');
	set2.addElement('N');	
	cout << "{" <<set2 << "}" <<'\n'; 
	
	Set <int> set3(2);
	set3.addElement(2);
	set3.addElement(3);
	set3.addElement(5);
	set3.addElement(7);	
	cout << "{" <<set3 << "}" <<'\n';
	
	cout <<"\n-----------------\n";
	
	Set <char>set4 = set2;
	cout << "{" << set4<< "}" <<'\n';
	
	cout <<"\n-----------------\n";
	
	set1=set3;
	cout << "{" << set1<< "}" <<'\n';
	cout <<"\n-----------------\n";
	
	return 0;
}
