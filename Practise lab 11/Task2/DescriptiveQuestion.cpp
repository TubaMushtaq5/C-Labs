#ifndef DESCRIPTIVE
#define DESCRIPTIVE
#include <iostream>

using namespace std;

class DescriptiveQuestion:public Question{
	
	char *ans;

	public:
	DescriptiveQuestion(char* question, int marks, char* answer) :Question(question,marks){
		ans=new char[findlength(answer)];
		strcpy(ans,answer);
	}
	
	void printQuestion(){
		Question::printQuestion();
		cout <<"Write your answer: " <<endl;
	}
	
	int checkQuestion(char *answer) {
		int i,count =0,studentMarks;
		for(i=0;ans[i]!='\0';i++){
			if(ans[i]!=answer[i])
				break;
			count ++;	
		}
		
		studentMarks=(count*marks)/findlength(ans);
		return studentMarks;
	}
	
	~DescriptiveQuestion(){
		delete []ans;
	}
	
};

#endif
