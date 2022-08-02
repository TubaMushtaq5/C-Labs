#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void convert2D_1D(int **src, const int ROWS, const int COLS, int *tar, const int SIZE);

int main(){
	
	int rows=3, columns=4, **arr, i, j, *z;
	srand(time(0));
	
	//cout << "Enter the rows and columns of array ";
	//cin >> rows >> columns;
	
	arr=new int*[rows];
	for(i=0; i<rows; i++){
		
		arr[i]=new int[columns];
	}
	for (i=0 ; i<rows;i++){
		
		for (j=0 ; j<columns; j++){
			
			arr[i][j]=rand() % 100;
			cout << arr[i][j] << ' ';
		}
		cout << "\n";
	}
	cout << "\n";
	
	z=new int[rows*columns];
	
	convert2D_1D(arr, rows, columns, z, rows*columns);
	

	return 0;

}
void convert2D_1D(int **src, const int ROWS, const int COLS, int *tar, const int SIZE){
	
	cout << "converted array:";
	int i, j,k=0;
	for (i=0 ; i<ROWS ;i++){
		
		for (j=0 ; j<COLS; j++){
			
			tar[k]=src[i][j];
			cout << tar[k] << ' ';
			k++;
		}
	}

}

