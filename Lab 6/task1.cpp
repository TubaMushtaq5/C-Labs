#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class MyList{
	int *x;
	int size;
public:
	void array(int size){
		x = new int[size];
		for (int i=0;i<size;i++)
			x[i] = rand() % 100;
	}
	MyList(){	
		size = rand()%5+5;
		array(size);
	}
	
	void setsize(int size){
		
		if(size>0)
		this->size=size;
		else
		this->size=5;
		array(size);
	}
	
	MyList(int size){
		setsize(size);
	}
	
	int get(int i){
		if(i<=size)
		return x[i];
		else
		return INT_MIN;
	}
	MyList& sort(){
		int i,j,temp;
		for(i=0;i<size;i++)
			for(j=0;j<size-i-1;j++)
				if(x[j]>x[j+1]){
					temp=x[j];
					x[j]=x[j+1];
					x[j+1]=temp;
				}
		return *this;
	}
	
	MyList& add(int num){
		int i;
		for(i=0;i<size;i++)
			x[i]=x[i]+num;
		return *this;
	}
	
	MyList& multiply(int num){
		int i;
		for(i=0;i<size;i++)
			x[i]=x[i]*num;
		return *this;
	}
	
	MyList& set(int value, int index){
		if (index<size)
			x[index]=value;
		return *this;
	}
	
	MyList& shuffle(int size){
		for(int i=0;i<size;i++){
			
			int index1=rand()%this->size;
			int index2=rand()%this->size;
			int temp=x[index1];
			x[index1]=x[index2];
			x[index2]=temp;
		}
	return *this;
	}
	
	void show() const{	
		for (int i=0;i<size;i++)
			cout << x[i] << ' ';
		cout << '\n';
}
	~MyList(){	delete []x;	}
};

int main(){
	srand(time(0));
	MyList list1(10);
	list1.show();
	cout << "Fourth element is:" << list1.get(3) << '\n';
	list1.sort().show();
	cout << "Fourth element is:" << list1.get(3) << '\n';
	list1.set(95,1).show();
	list1.shuffle(20).show();
	list1.sort().show();
	list1.add(3).show();
	list1.multiply(2).show(); 
return 0;
}

