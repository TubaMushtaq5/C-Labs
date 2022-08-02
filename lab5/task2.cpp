#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

class Time{
	
	 int hours;//0-23
	 int minutes;//0-59
	 int seconds;//0:59
	 int format;
	 
	public:
		
	Time(){
		hours=0;
	 	minutes=0;
	 	seconds=0;
		format=0;
	}	
		
	void sethours(int hours){
	 	
	 	if(hours<0 || hours>23)
	 		this->hours=1;
	 	else 
		    this->hours=hours;
	 }
	
	void setminutes(int minutes){
	 	
	 	if(minutes<0 || minutes>59)
	 		this->minutes=1;
	 	else 
		    this->minutes=minutes;
	}
	
	void setseconds(int seconds){
		
		if(seconds<0 || seconds>59)
	 		this->seconds=0;
	 	else 
		    this->seconds=seconds;
	}
	void setformat(int format){
		
		if(format==1 || format==2)
			
			this->format=format;
		else
		    this->format=1;
	}
	
	int gethours(int hoursget){
		
		return hours;
	}
	
	int getminutes(int minutesget){
		
		return minutes;
	}
	
	int getseconds(int secondsget){
		
		return seconds;
	}
	
	Time(int hours, int minutes,int seconds){
	
		sethours(hours);
		setminutes(minutes);
		setseconds(seconds);
}
	void set(int hours, int minutes,int seconds){
	
		sethours(hours);
		setminutes(minutes);
		setseconds(seconds);
}


void show(){
	
		if(hours<10)
			cout << "0";
		cout << hours << ":";
	
		if(minutes<10)
			cout <<"0";
		cout << minutes << ":";
		
		if(seconds<10)
			cout << "0";
		cout << seconds;
}

	void showdefault(){
		
	if(format==1)
		show();		
		
	
	if(format==2){

		if (hours>12)	
			hours = hours % 12;
		show();
	
		if (hours< 12)	
		cout << " AM\n";
		
	    else			
		cout << " PM";
	}
}
	 
};
int main(){
		
	Time t1(3,30,18);
	t1.show(); //03:30:18
	cout << "\n";
	t1.setseconds (70);
	t1.show(); //03:30:00
	cout << "\n";
	Time t2(0,0,0);
	t2.show(); //00:00:00
	cout << "\n";
	t2.set(19,5,8);
	t2.show(); //19:05:08
	cout << "\n";
	t2.setformat(2);
	t2.showdefault(); //07:05:08 PM
	t2.sethours(12);//By default 0 to 11 is AM, whereas 12 to 23 is PM
	t2.showdefault(); 
	
	return 0;
}


