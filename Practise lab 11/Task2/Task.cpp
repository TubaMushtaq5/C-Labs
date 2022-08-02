#include "Question.cpp"
#include "DescriptiveQuestion.cpp"
#include "FillInTheBlanks.cpp"
#include "TrueFalse.cpp"
#include "MCQ.cpp"
#include <iostream>

using namespace std;

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
	q = new TrueFalse("The sun sets in the west", 1, 'T');
	q->printQuestion();
	cin.getline(userAnswer, 80, '\n');
	cout << "Marks: " << q->checkQuestion(userAnswer) << '\n';
	delete q;
	return 0;
}
