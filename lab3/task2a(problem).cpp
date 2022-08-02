#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int* findCommon(int *a1, const int SIZE1, int *a2, const int SIZE2, int &commonCount);
void show(int *x, const int SIZE);

int main(){
	
	int elements1, elements2,  *arr1, *arr2,i;
	cout << "Enter number of elements of 1st array";
	cin >> elements1;
	
	cout << "Enter number of elements of 2nd array";
	cin >> elements2;
	
	arr1=new int[elements1];
	arr2=new int[elements2];
	
	for(i=0;i<elements1;i++){
		
		arr1[i]=rand()%100;
	}
	
	for(i=0;i<elements2;i++){
		
		arr2[i]=rand()%100;
	}
	int commonCount;
	
	int *common=findCommon(arr1,elements1,arr2,elements2,commonCount);
	show (common, commonCount);
    delete []common;

	
	return 0;
}

int* findCommon(int *a1, const int SIZE1, int *a2, const int SIZE2, int &commonCount){
	
	int i,j,*commonarr,k;
	for(i=0; i<SIZE1; i++){
	
		for(j=0; j<SIZE2; j++){
		
			if(a1[i]==a2[j])
				commonCount++;
				
			}
				
	}
	commonarr=new int[commonCount];
	
	for(i=0; i<SIZE1; i++){
		
		for(j=0; j<SIZE2; j++){
			
			if(a1[i]==a2[j]){
				
				commonarr[k++]=a1[i];
			}
		}
	}
	return commonarr;
}

void show(int *x, const int SIZE){
	for (int i = 0 ; i < SIZE; i++)
		cout << x[i] << ' ';
	cout << "\n";
}
