#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char bowlers[5][20] = {"Sajid Ali", "Ahmad Butt", "Nadeem Ali", "Sohail Rana", "Najam Khan"};

class Over{
	int balls;
	int noofballs;//current balls //there may be zero or more runs on each ball
	int *statusofball; //(0 for normal, 1 for no ball, 2 for wide ball
	int *statusofwicket; //0 for without wicket, 1 for bold, 2 for catch out, 3 for LBW, 4 for stump, 5 for run out 
	int *score;
	int totalscore;
	static int noofwickets;
	static int ballerid;
	
	void resize(int newballs){
		balls = newballs;
		int *tempscore = new int[balls];
		int *tempwicketstatus = new int[balls];
		int *tempballstatus = new int[balls];
		
		for (int i=0;i<noofballs;i++){
			tempscore[i] = score[i];
			tempwicketstatus[i] = statusofwicket[i];
			tempballstatus[i] = statusofball[i];
		}
		
		delete []score;
		delete []statusofwicket;
		delete []statusofball;
		
		score = tempscore;
		statusofwicket = tempwicketstatus;
		statusofball = tempballstatus;
	}

	void statusofballs(int noofballs){
		for(int i=0;i<noofballs;i++){
			statusofball[i]=rand()%10;
			if (statusofball[i] > 7 ){
				statusofball[i] = 1;
				if(noofballs==balls)
					resize(balls*2);
				this->noofballs++;
			}
			else if (statusofball[i] > 5){
				statusofball[i] = 2;
				if(noofballs==balls)
					resize(balls*2);
				this->noofballs++;
			}
			else 
				statusofball[i] = 0;
		}
	}
	
	void statusofwickets(int noofballs){
		for(int i=0;i<noofballs;i++){
			if(noofwickets<=10)
				statusofwicket[i]=rand()%15;
			else if(noofwickets>10)
				statusofwicket[i]=0;

			if(statusofwicket[i]>13)
				statusofwicket[i]=1;
				
			else if(statusofwicket[i]>10)
				statusofwicket[i]=2;
			else
				statusofwicket[i]=0;
		}
	}
	
	void scoreofball(int noofballs){
		
		for(int i=0;i<noofballs;i++){
			score[i]=rand()%6+1;
		}
	}
	
	void totalscores(int noofballs){
		for(int i=0;i<noofballs;i++){
			totalscore+=score[i];
		}
	}
  	public:
	Over (){
		noofballs=6;
		balls=6;
		score = new int[noofballs];
		statusofball = new int[noofballs];
		statusofwicket=new int[noofballs];
		statusofballs(noofballs);
		statusofwickets(noofballs);
		scoreofball(noofballs);
		totalscore = 0;
		totalscores(noofballs);
	}
	
	friend ostream& operator << (ostream& out, Over& m){
		out <<"Bowler: " << bowlers[m.ballerid] << endl;
		ballerid++;
		out <<"Number of balls: "<< m.noofballs << endl;
		for(int i=1;i<=m.noofballs;i++)
			out << i << "\t\t";
		out << "\n";
		
		for(int i=0;i<m.noofballs;i++){
			if ( m.statusofball[i]== 0 ){
				if(m.statusofwicket[i]==1){
					out << "Bold\t\t";
					noofwickets++;
				}
				else if(m.statusofwicket[i]==2){
					out << "Catchout\t\t";
					noofwickets++;
				}
				else if(m.statusofwicket[i]==3){
					out << "LBW\t\t";
					noofwickets++;
				}
				else if(m.statusofwicket[i]==4){
					out << "stump\t\t";
					noofwickets++;
				}	
				else if(m.statusofwicket[i]==5){
					out << "Run out\t\t";
					noofwickets++;
				}	
			}
			else if(m.statusofball[i]==2)
				out << "Wide\t\t";
			else if(m.statusofball[i]==1)
				out << "No Ball\t\t";
		}
		out << "\n";
		
		for(int i=0;i<m.noofballs;i++)
			out << m.score[i] <<"\t\t";
		out <<"\n";	
		out << "Total runs in the over: " << m.totalscore << endl;	
		out << "Total wickets: " << m.noofwickets<< endl;
		out << "\n-------------------------\n\n";
		return out;	
	}
};
int Over::ballerid=0;
int Over::noofwickets = 0;

int main(){
	srand(time(0));
	Over a1[5];
	
	for (int i = 0; i < 5; i++)
		cout << a1[i];
		
	return 0;
}
