#ifndef MCQQUESTIONS
#define MCQQUESTIONS
#include <iostream>

using namespace std;

class MCQ:public Question{
	char *choice[4];
	char correctchoice;
	
	public:
	MCQ(char *p, int marks, char *choice1, char *choice2, char *choice3, char *choice4, char correct) :Question(p,marks){
		correctchoice=correct;
		choice[0]=new char[findlength(choice1)];
		strcpy(choice[0],choice1);
		choice[1]=new char[findlength(choice2)];
		strcpy(choice[1],choice2);
		choice[2]=new char[findlength(choice3)];
		strcpy(choice[2],choice3);
		choice[3]=new char[findlength(choice4)];
		strcpy(choice[3],choice4);	
	}
	
	void printQuestion(){
		Question::printQuestion();
		cout << "Select your choice: " << endl;
		cout << "Choice 1: "<< choice[0] << endl;
		cout << "Choice 2: "<< choice[1] << endl; 
		cout << "Choice 3: "<< choice[2] << endl; 
		cout << "Choice 4: "<< choice[3] << endl;
	}
	
	int checkQuestion(char *answer){
		if(answer[0]!=correctchoice)
			return 0;
		else
			return marks;
	}
	
	~MCQ(){
		for(int i=0;i<4;i++)
			delete []choice[i];
	}
};

#endif
