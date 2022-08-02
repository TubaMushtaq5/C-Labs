#ifndef TRUEFALSE
#define TRUEFALSE
#include <iostream>

class TrueFalse:public Question{
	char store;
	
	public:
	TrueFalse(char* question, int marks, char ans) :Question(question,marks){
		store=ans;
	}
	
	void printQuestion(){
		Question::printQuestion();
		cout <<"Write T for True or F for False: " <<endl;
	}
	
	int checkQuestion(char *answer) {
		if(store!=answer[0])
			return 0;
		return marks;	
	}
	~TrueFalse(){
		cout << "here";
	}
};

#endif
