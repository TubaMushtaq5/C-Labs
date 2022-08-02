#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void show(int *x, const int SIZE);
void show(int **x, const int ROWS, const int COLS);
void convert1D_2D(int *src, const int SIZE, int **tar, const int ROWS, const int COLS);


int main(){
	
	int rows, columns, *x, i, j;
	srand(time(0));
	
	cout << "Enter the rows and columns of array ";
	cin >> rows >> columns;
	
	x = new int[rows*columns];
	
	for ( i=0; i<rows*columns; i++)
	{
		x[i] = rand() % 100;
	}
	
	show (x, rows*columns);

	int **y=new int*[rows];
	
	for (i=0;i<rows;i++)
		y[i]=new int[columns];
		
	int **z=new int*[columns];
	
	for (i=0;i<columns;i++)
		z[i]=new int[rows];
		
	convert1D_2D(x, rows*columns, y, rows, columns);
	show (y, rows, columns);
	
	return 0;
}

void show(int *x, const int SIZE){
	
	int i;
	for (i = 0 ; i < SIZE; i++)
		cout << x[i] << ' ';
	cout << "\n\n";
}

void show(int **x, const int ROWS, const int COLS){
	int i, j;
	cout << "Show function: " <<endl;
	for (i = 0 ; i < ROWS; i++){
		for (j = 0 ; j < COLS; j++)
			cout << x[i][j] << ' ';
		cout << '\n';
		}
	cout << '\n';
}

void convert1D_2D(int *src, const int SIZE, int **tar, const int ROWS, const int COLS){
	
	int i, j,k;
	cout << "2D Array: "<< endl;
	for (i = 0 ; i < ROWS; i++){
		for (j = 0 ; j < COLS; j++){
			
			tar[i][j]=src[k];
		    k++;
		    cout << tar[i][j] << ' ';
		}
		
		cout<< "\n";
		}
	cout << '\n';

}

