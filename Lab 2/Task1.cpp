#include <iostream>
using namespace std;
int main(){
	
    int i,k;
    char input[80], output[200];
    
    cin.getline(input, 80, '\n');
    output[0]='*';
    
    for(i=0,k=1; input[i]!='\0';i++,k++){
        if(input[i] == ' '){
        	
            output[k]='*';
            continue;
        }
        output[k]=input[i];

    }
    output[k]='*';


    cout << output << "\n";
    return 0;
}
