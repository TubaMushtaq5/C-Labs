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
	int size;
	static int count;
public:
	SetList(){	
		size=0;
	}
	
	template <class T>
	void addSet(Set<T> &obj){
		size=++count;
		set[size-1]=&obj;
	}
	
	friend ostream& operator << (ostream &out, const SetList &list){
		for(int i=0;i<list.size;i++)
			cout << "{" << *list.set[i] << "}\n";
		return out;
	}
};

template <class type>
int SetList<type>::count=0;

int main(){
	
	Set <int> set1(2);
	set1.addElement(23);
	set1.addElement(19);
	set1.addElement(50);
	set1.addElement(17);
	set1.addElement(18);
	set1.addElement(20);	
	cout << "{" <<set1 << "}" <<'\n';
	
	Set <int> set2(2);
	set2.addElement(10);
	set2.addElement(20);
	set2.addElement(30);
	set2.addElement(40);
	set2.addElement(50);	
	cout << "{" <<set2 << "}" <<'\n'; 
	
	cout << "\n---------------------\n";
	
	SetList <int> set;
	set.addSet(set1);
	set.addSet(set2);
	cout << set;	
 	return 0;
}
