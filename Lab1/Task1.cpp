#include <iostream>


using namespace std;

int main(){
	
	int start , end , number , i , j;
	cout <<"Enter starting table number";
    cin >> start ;
    cout <<"Enter ending table number";
    cin >> end ;
    for (i = start ; i<= end ; i++) {
    	
	    for	( j = 1 ; j <=10 ; j++){
	    		cout << i << " x " << j << " = " << i*j << '\n' ;
			}
			if (i < end) {
			cout << "Enter any number to continue" ;
			cin >> number ;	
			}
	}
	return 0;
}
