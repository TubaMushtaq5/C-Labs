#include <iostream>

using namespace std;

int main(){
	char input[80], output[200], i, k;
	cin.getline(input, 80, '\n');
	
	output[k]='*';
	
	for(i=0,k=1; input[i]!='\0';i++,k++){
		
		if(input[i]==' '){
			
			output[k]='*';
		}
		
		else
		output[k]=input[i];
	}
	output[k]='*';
	
	cout << output << "\n";
	return 0;
}
