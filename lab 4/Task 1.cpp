
#include <iostream>

using namespace std;

int main(){
	char input[80], output[200];
	int i,j;
	cin.getline(input, 80, '\n');
	
	for (i=0,j=0;input[i]!='\0';i++,j++){
		
		if(input[i]==' '){
			
			output[j] = '*';
			j++;
		}
		
		else 
		output[j]=input[i];
		cout << output[j] ;
	}
	//cout << output << "*\n";
	return 0;
}
/*Sample Run:
This statement has five words
This*statement*has*five*words*/
