#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

char* copyString(char *t, const char *s){
	for (int i=0;true;i++){
		t[i] = s[i];
		if (s[i] ==  0)	return t;
	}
}
void printHeading(){
	cout << "   PN   Name             Country        Span      MC  IC NO  RS   HS  AVE     BF   SR    100s 50s 0s   4s  6s\n";
	cout << "------------------------------------------------------------------------------------------------------------\n";
}
	
class Player{
	char fName[11],	sName[12],	country[13], span[10];
	int playerNo, noOfMatches, noOfInnings, noOfNotOuts, runs, highest, ballsFaced;
	int noOf100s, noOf50s, noOfZeros, noOf4s, noOf6s;
	float average, 	strikeRate; 
public:
	Player(){}

	void readValues(ifstream &in){
		in >> playerNo;
		in >> fName >> sName >> country >> span;
		in.clear();
		in >> noOfMatches >> noOfInnings >> noOfNotOuts >> runs >> highest;
		in >> average >> ballsFaced >> strikeRate >> noOf100s >> noOf50s;
		in >> noOfZeros >> noOf4s >> noOf6s;
	}
	static void showFloat(float value, int width, int pre){
		cout  << fixed << setprecision(pre) << setw(width) << value << ' ';
	}
	int getPlayerNo(){ return playerNo; }
	void showInSingleLine() const{
		int i,j;
		cout << setw(3) << playerNo << ' ';
		for (i=0;i<fName[i]!=0;i++)	cout << fName[i];
		cout << ' ';
		j=i+1;
		for (i=0;i<sName[i]!=0;i++)	cout << sName[i];
		for (j=j+i;j<19;j++)	cout << ' ';
		cout << left << setw(13) << country;
		cout << setw(10) << span  << right << setw(4) << noOfMatches << setw(4) << noOfInnings;
		cout << setw(3) << noOfNotOuts << setw(5) << runs << setw(5) << highest << ' ';
		showFloat(average, 4, 2);
		cout << ' ' << setw(4) << ballsFaced <<' ';
		showFloat(strikeRate, 5, 2);
		cout  << setw(3) << noOf100s;
		cout << setw(4) << noOf50s << setw(4) << noOfZeros << setw(5) << noOf4s << ' ';
		cout << setw(3) << noOf6s <<'\n';
	}
	void show() const{
		cout << "Player No:" << playerNo << '\n';
		cout << "Name:" << fName <<' '<< sName << '\n';
		cout <<"Country: "<< country  << '\n';
		cout << "Span: " << span  << '\n';
		cout << "Matches played: " << noOfMatches  << '\n';
		cout << "No of times batted: "<< noOfInnings  << '\n';
		cout << "No of times not out: " << noOfNotOuts  << '\n';
		cout << "Runs: " << runs  << "\nHighest Score: " << highest;
		cout << "\nAverage Score: " << average << "\nBalls Faced: " << ballsFaced;
		cout << "\nStrike Rate: " << strikeRate << "\nHundreds: " << noOf100s;
		cout << "\nFifties: " << noOf50s << "\nNo of zeros: " << noOfZeros;
		cout << "\nNo of fours: " << noOf4s << "\nNo of sixes: "<< noOf6s <<'\n';
	}
	void swap(Player &p){
		Player temp = *this;
		*this = p;
		p = temp;
	}
};

class PlayersList{
	int playersCount;
	Player *players;
public:
	PlayersList(){
		ifstream in("T20_1.txt");
		if (in.fail())		{cout << "Error";	playersCount=0; return;}
		in >> playersCount;
		players = new Player[playersCount];
		for (int i=0;i<playersCount;i++)
			players[i].readValues(in);
	}
	void showIthPlayer(int playerNo){
		if (playerNo<playersCount)
			players[playerNo].show();		
		else
			cout << "Player No is larger than count of players\n";
	}
	
	Player getPlayer()
	{
		return players[rand() % playersCount];
	}
	
	void showAll(){
		char temp;
		if (playersCount==0){
			cout << "List Empty\n";
			return;
		}
		for(int i=0;i<playersCount;i++){
			if (i%22==0)	printHeading();
			players[i].showInSingleLine();		
			if (i%22==21){
				cout << "Press any key to continue:";
				cin >> temp;				
			}
		}
	}
};

class Team{
	Player players[11];
	char teamName[50];
	
  public:
  	Team( char *teamName, PlayersList& p )
  	{
  		int i, j;
  		
  		copyString(this->teamName, teamName);
  		
  		for ( i = 0; i < 11; i++ )
  		{
  			players[i] = p.getPlayer();  			
  			for ( j = 0; j < i; j++ )
  				if ( players[i].getPlayerNo() == players[j].getPlayerNo() )
  				{
  					i--;
  					break;
				}
		}
	}
	
	void showTeam()
	{
		cout << "Team Name : " << teamName << "\n\n";
		printHeading();
		for( int i = 0; i < 11; i++ )
		{
			cout << left << setw(3) << i + 1 ;
			players[i].showInSingleLine();
		}
			
	}
};
int main(){
	srand(time(0));
	
	PlayersList list;
//	list.showAll();
	
	cout << "\n***********************\n";
	
	Team team("ABCDEF", list);
	team.showTeam();
	return 0;
} 

