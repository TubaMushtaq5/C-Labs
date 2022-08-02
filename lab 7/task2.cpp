#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Player{
	int noofmatches;
	int *score;
	int *status;
	public:
		
	int getnoofmatch(int noofmatches){
		this->noofmatches=noofmatches;
	}
	
	int getscore(int noofmatches){
		score = new int[noofmatches];
		for(int i=0;i<noofmatches;i++)
			score[i]=rand()%151;
	}
	
	int getstatus(int noofmatches){
		status = new int[noofmatches];
		for(int i=0;i<noofmatches;i++)
			status[i]=rand()%2;
	}
	
	int getscorecopy(const Player &s){
		getnoofmatch(s.noofmatches);
		getscore(s.noofmatches);
		int i;
		for (i=0;i<s.noofmatches;i++)
			score[i]= s.score[i];
	}
	
	int getstatuscopy(const Player &s){
		getstatus(s.noofmatches);
		int i;
		for (i=0;i<s.noofmatches;i++)
			status[i]=s.status[i];
	}
	
	Player(int noofmatches){
		getnoofmatch(noofmatches);
		getscore(noofmatches);
		getstatus(noofmatches);
	}
	
	void deletememory(){
		delete []score;
		delete []status;
	}
	
	Player(const Player &copy){
		getscorecopy(copy.noofmatches);
		getstatuscopy(copy.noofmatches);
}

	Player& operator = (const Player &p){
		deletememory();
		getscorecopy(p.noofmatches);
		getstatuscopy(p.noofmatches);
	}
	
	~Player(){
		deletememory();
	}
	
	float getaverage(){
		int sum = 0; 
		float average;
		for(int i=0;i<noofmatches;i++)
			sum=sum+score[i];
		average=(float)sum/noofmatches;
		return average;
	}
	
	void increment (){
		int tempscore[noofmatches];
		int tempstatus[noofmatches];
		for(int i=0;i<noofmatches;i++){
			tempscore[i]=score[i];
			tempstatus[i]=status[i];
		}
		deletememory();
		noofmatches++;
		getscore(noofmatches);
		getstatus(noofmatches);
		for(int i=0;i<noofmatches-1;i++){
			score[i]=tempscore[i];
			status[i]=tempstatus[i];
		}
		score[noofmatches]=rand()%151;
		status[noofmatches]=rand()%2;
	}
	
	Player& operator ++ (){
		increment();
		return *this;
	}
	
	Player operator ++ (int){
		Player copy=*this;
		increment();
		return copy;
	}
	
	Player& operator += (int score){
		increment();
		if(score>=0 && score<151)
			this->score[noofmatches]=score;
		return *this;
	}
	
	bool operator == (Player &equal){
		return(getaverage()==equal.getaverage());
	}
	
	bool operator > (Player &greater){
		return(getaverage()>greater.getaverage());
	}
	
	friend ostream& operator << (ostream &out, Player &p){
		out << "No of matches: " << p.noofmatches << '\t' << "Average: " << p.getaverage() <<endl;
		out << "Match: ";
		for(int i=0;i<p.noofmatches;i++)
			out << i+1 << '\t';
		out << "\n";
		out << "Score: ";
		for(int i=0;i<p.noofmatches;i++)
			out << p.score[i] << '\t';
		out << "\n";
		out << "Status: ";
		for(int i=0;i<p.noofmatches;i++){
			if(p.status[i]==1)
			out << "Out" << '\t';
			if(p.status[i]==0)
			out << "Not Out" << '\t';
		}
		out << "\n";
		return out;
	}
};

int main(){
	srand(time(0));
	Player a1(4);
	cout << a1;
	cout << "--------------------------------\n";
	Player a2=++a1;
	cout << a2;
	cout << "--------------------------------\n";
	if(a2==a1)
	cout << "Equal "<< endl;
	else
	cout << "Not Equal "<< endl;
	cout << "--------------------------------\n";
	if(a2>a1)
	cout << "Player 2 has greater average ";
	else
	cout << "Player 1 has greater average  ";

	return 0;
}
