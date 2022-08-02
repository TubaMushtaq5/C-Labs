#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void display1D_2D(int *x, const int ROWS, const int COLS);

int main(){
	
	int rows, columns, *arr, i;
	srand(time(0));
	
	cout << "Enter the rows and columns of array ";
	cin >> rows >> columns;
	
	arr = new int[rows*columns];
	
	for ( i=0; i<rows*columns; i++)
	{
		arr[i] = rand() % 100;
	}
	display1D_2D(arr,rows,columns);
    free(arr);
	return 0;
}

void display1D_2D(int *x, const int ROWS, const int COLS){
	
	int i,j;
	for(i=0; i<ROWS; i++){
		
		for(j=0; j<COLS; j++){
			
			cout << x[i*COLS+j] << '\t';
		}
		cout << "\n";
	}
}
