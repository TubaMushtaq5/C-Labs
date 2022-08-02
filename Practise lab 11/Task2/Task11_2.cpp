#include "FillInTheBlanks.cpp"
#include "TrueFalse.cpp"
#include "MCQ.cpp"
#include "DescriptiveQuestion.cpp"
#include <iostream>

using namespace std;

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
	
	virtual void printQuestion(){
		int i;
		for(i=0;description[i]!=0;i++)
			cout << description;
		cout <<'\n';
	}
	
	virtual int checkQuestion(char *) {
		return 1;
	}
	
	~Question(){
		delete []description;
	}
};

int main(){
	char userAnswer[100];
	Question *q;
	q = new DescriptiveQuestion("Write four directions in small letter alphabetically with single space?", 4, "east north south west");
	q->printQuestion();
	cin.getline(userAnswer, 80, '\n');
	cout << "Marks: " << q->checkQuestion(userAnswer) << '\n';
	delete q;
	q = new MCQ("2+3=?", 1, "2", "3", "4", "5", '4');
	q->printQuestion();
	cin.getline(userAnswer, 80, '\n');
	cout << "Marks: " << q->checkQuestion(userAnswer) << '\n';
	delete q;	
	q = new FillInTheBlanks("The sun ____ in the east", 1, "sets");
	q->printQuestion();
	cin.getline(userAnswer, 80, '\n');
	cout << "Marks: " << q->checkQuestion(userAnswer) << '\n';
	delete q;
	q = new TrueFalse("The sun sets in the west", 1, 'F');
	q->printQuestion();
	cin.getline(userAnswer, 80, '\n');
	cout << "Marks: " << q->checkQuestion(userAnswer) << '\n';
	delete q;	
	return 0;
}
