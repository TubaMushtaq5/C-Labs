#include <iostream>

using namespace std;

int main(){
	
	int wordscount=1, i , lettercount=0, maxword, k=0,j;
    char input[100];
    char **output;
    
    cout << "Input a string ";
    cin.getline(input, 300, '\n');
    
    for(i=0; input[i] != '\0';i++){
			
			if(input[i]==',' || input[i]==':' || input[i]=='\''||  input[i]==';' || input[i]=='\"' ||  input[i]=='.'|| input[i]=='?')
			continue;
			
			else if(input[i]==' '){
					
					wordscount++;
					
					if(lettercount>maxword)
						maxword=lettercount;
					
					lettercount=0;
					
					continue;
				}
			else
			lettercount++;
	}
	
	output = new char*[wordscount];
	
	for(i=0;i<wordscount;i++)
	output[i] = new char[maxword];
	
    for(i=0;i<wordscount,input[k]!='\0'; i++)
    {
    	
    	for(j=0; j<lettercount; j++,k++)
		{
    		
    		if(input[k] >= 65 && input[k] <= 90)
    		input[k]=input[k]+32;
    		
    		if(input[k]==',' || input[k]==':' || input[k]=='\''||  input[k]==';' || input[k]=='\"' ||  input[k]=='.'|| input[k]=='?' )
			continue;
			
			else if(input[k-1]==' ' && input[k]=='i' && input[k+1]=='s')
			{
				k=k+2;
				continue;
			}
			
			
			else if(input[k-1]==' ' && input[k]=='a' && input[k+1]=='m')
			{
				k=k+2;
				continue;
			}
			
			else if(input[k-1]==' ' && input[k]=='a' && input[k+1]=='r' && input[k+2]=='e')
			{
				k=k+3;
				continue;
			}
			
			else if(input[k-1]==' ' && input[k]=='w' && input[k+1]=='a' && input[k+2]=='s')
			{
				k=k+3;
				continue;
			}
			
			else if(input[k-1]==' ' && input[k]=='w' && input[k+1]=='e' && input[k+2]=='r' && input[k+3]=='e')
			{
				k=k+4;
				continue;
			}
    		
    		else output[i][j]=input[k];
		
    		cout<< output[i][j];
		}
	}
	
	return 0;
}
