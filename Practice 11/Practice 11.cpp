#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void strcpy(char* t, char* s)
{
	int i;
	for( i = 0; s[i] != 0; i++ )
		t[i] = s[i];
	t[i] = 0;
}

class Player{
	char fName[11],	sName[12],	country[13], span[10];
	int noOfMatches, noOfInnings, noOfNotOuts, runs, highest, ballsFaced;
	int noOf100s, noOf50s, noOfZeros, noOf4s, noOf6s;
	float average, 	strikeRate; 
public:
	readValues(ifstream &in){
		in >> fName >> sName >> country >> span;
		in.clear();
		in >> noOfMatches >> noOfInnings >> noOfNotOuts >> runs >> highest;
		in >> average >> ballsFaced >> strikeRate >> noOf100s >> noOf50s;
		in >> noOfZeros >> noOf4s >> noOf6s;
		
	}
	
	bool searchname(char *name){
		for(int i=0;fName[i]!='\0';i++)
			if(fName[i]!=name[i])
				return 0;
		return 1;
	}
	
	float getaverage(){
		return average;
	}
	
	static void showFloat(float value, int width, int pre){
		cout  << fixed << setprecision(pre) << setw(width) << value << ' ';
	}
	
	Player& operator = ( Player &p )
	{
		strcpy( fName, p.fName);
		strcpy( sName, p.sName);
		strcpy( country, p.country);
		strcpy( span, p.span );
		noOfMatches = p.noOfMatches;
		noOfInnings = p.average;
		noOfNotOuts = p.noOfNotOuts;
		runs = p.runs;
		highest = p.highest; 
		ballsFaced = p.ballsFaced;
		noOf100s = p.noOf100s; 
		noOf50s = p.noOf50s;
		noOfZeros = p.noOfZeros;
		noOf4s = p.noOf4s;
		noOf6s = p.noOf6s;
		average = p.average;
		strikeRate = p.strikeRate;
 	}
	
	int getHighest() const{	return highest;}
	void showInSingleLine() const{
		int i,j;
		for (i=0;i<fName[i]!=0;i++)	cout << fName[i];
		cout << ' ';
		j=i+1;
		for (i=0;i<sName[i]!=0;i++)	cout << sName[i];
		for (j=j+i;j<19;j++)	cout << ' ';
		cout << left << setw(12) << country;
		cout << setw(10) << span  << right << setw(4) << noOfMatches << setw(4) << noOfInnings;
		cout << setw(3) << noOfNotOuts << setw(5) << runs << setw(5) << highest << ' ';
		showFloat(average, 5, 2);
		cout << setw(5) << ballsFaced <<' ';
		showFloat(strikeRate, 5, 2);
		cout  << setw(3) << noOf100s;
		cout << setw(3) << noOf50s << setw(2) << noOfZeros << setw(4) << noOf4s << ' ';
		cout << setw(3) << noOf6s <<'\n';
	}
	void show() const{
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
};
class PlayersList{
	int playersCount;
	Player *players;
	Player namefound;
public:
	static void printHeading(){
		cout << " Name           Country          Span     MC  IC   NO  RS   HS  AVE   BF   SR  100s 50s 0's 4s  6s\n";
		cout << "---------------------------------------------------------------------------------------------------\n";
	}
	PlayersList(){
		ifstream in("T20.txt");
		if (in.fail())		{cout << "Error";	playersCount=0; return;}
		in >> playersCount;
		players =new Player[playersCount];
		for (int i=0;i<playersCount;i++)
			players[i].readValues(in);
	}
	void showIthPlayer(int playerNo){
		if (playerNo<playersCount)
			players[playerNo].show();		
		else
			cout << "Player No is larger than count of players\n";
	}
	
	void searchByFirstName(char *name){
		int i;
		for ( i=0;i<playersCount;i++)
		{
			if (players[i].searchname(name))
				break;
		}
		if ( i != playersCount )
			players[i].show();
		else 
			cout << "Player not found." <<endl;
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
	void printPlayerHavingOverallHighest(){
		if (playersCount==0){
			cout << "List Empty\n";
			return;
		}
		int index=0;
		for (int i=1;i<playersCount;i++)
			if (players[0].getHighest()<players[i].getHighest())
				index = i;
		players[index].show();
	}
	
	void sortplayers(){
		int i,j;
		Player temp;
		
		for(i=0;i<playersCount;i++)
			for(j=0;j<playersCount-1;j++)
				if(players[j].getaverage()<players[j+1].getaverage())
				{
					temp = players[j];
					players[j] = players[j+1];
					players[j+1] = temp;
				}
	}
};

int main()
{
	PlayersList list;	
	//list.searchByFirstName("Babar");
	list.sortplayers();
	list.showAll();

	//list.showIthPlayer(34);
	//list.printPlayerHavingOverallHighest();
	return 0;
}
