#ifndef QUESTION
#define QUESTION
#include <iostream>

using namespace std;

class Question{
	protected:
	char *description;
	int marks;
	
	public:
	Question(char *p, int marks){
		description=new char[findlength(p)];
		strcpy(description,p);
		this->marks=marks;
	}
	
	
	void strcpy(char* t, char* s){
		int i;
		for(i=0;s[i]!=0;i++)
			t[i]=s[i];
		t[i]=0;
	}
	
	int findlength(char *string){
		int i,count=0;
		for(i=0;string[i]!=0;i++)
			count++;
		return count;
	}
		
	virtual void printQuestion(){
		cout << description << endl;
	}
	
	virtual int checkQuestion(char *) {
		return 1;
	}
	
	virtual ~Question(){
		delete []description;
	}
};
#endif
