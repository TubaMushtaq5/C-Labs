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
		getscore(s.noofmatches);
		int i;
		for (i=0;i<s.noofmatches;i++)
			score[i]= s.score[i];
	}
	
	int getstatuscopy(const Player &s){
		getstatus(s.noofmatches);
		int i;
		for (i=0;i<s.noofmatches;i++)
			status[i]= s.status[i];
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
	return 0;
}
