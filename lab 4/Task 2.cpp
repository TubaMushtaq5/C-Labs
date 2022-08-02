#include <iostream>

using namespace std;
int main(){
	int i, j, count=1, ch,k;
	char input[7][10]={{"Apple"},{"Mango"},{"Banana"},{"Grapes"},{"Pear"},{"Orange"},{"Melon"}};
	char *output;

	for(i=0;i<7;i++){
		
        for (j=0;j<10;j++){
        	
        	count++;
		}
		count++;
    }
     cout <<"The total characters of the given string= "<<count;
     
     output = new char[count];
     
     k=0;
     
     for(i=0;i<7;i++){
		
        for (j=0;j<10;j++,k++){
        	
        	output[k]=input[i][j];
		}
		
		output[k]=' ';
		
    }
    output[k+1] = '\0';

    cout <<"\n";
    
    cout << output <<endl;
	return 0;
}
