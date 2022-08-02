#ifndef BLANKS
#define BLANKS
#include <iostream>

class FillInTheBlanks:public Question{
	char* correct;
	
	public:
	FillInTheBlanks(char* question, int marks, char* correctans) :Question(question,marks){
		correct =  new char [findlength(correctans)];
		strcpy(correct,correctans);
	}
	
	void printQuestion(){
		Question::printQuestion();
		cout <<"Write word to fill blank: " <<endl;
	}
	
	int checkQuestion(char *answer) {
		int i,count =0;
		for(i=0;correct[i]!='\0';i++){
			if(correct[i]!=answer[i])
				return 0;
			return marks;	
		}
	}
	~FillInTheBlanks(){
		delete []correct;
	}
};

#endif
