#include <iostream>

using namespace std;

void pattern(int width);
void middleLines( int width, int height);

int main()
{
	int input, width, middle;
	do
	{
		cout << "Enter any odd Number between 7 and 15: ";
		cin >> input;
		
		if ( input < 7 || input > 15 )
			cout << "Invalid Input!!\n";
			
	} while (input < 7 || input > 15 );
	
	width = input / 2 + 1;
	middle = ( input - 3 ) / 2;
	
	cout << ' ';
	
	pattern( width );
	middleLines( width , middle );
	
	pattern( width+1);
	middleLines( width, middle );
	
	cout << ' ';
	pattern( width );

}

void pattern(int width)
{
	int i; 
	
	for ( i = 0; i < width; i++ )
		cout << '*';
		
	cout << endl;
}

void middleLines( int width, int height)
{
	int i, j;
	
	for ( i = 0; i < height; i++ )
	{
		cout << '*';
		
		for ( j = 0; j < width; j++ )
			cout << ' ';
		
		cout << '*' << endl;
	}
}
