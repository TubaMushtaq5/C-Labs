#include<iostream>
#include<cstring>

using namespace std;

class Job;

class JobException{
	Job* job;
	char message[100];
	
	public:
	JobException(Job &j){
		job = &j;
		strcpy(message, "job Fee must be greater than or equal to 250");
	}
	
	Job &getjob() const{
		return *job;
	}
	
	void show(){
		cout << message << '\n';
	}
};

class Job{
	int jobID;
	static int count;
	int CostOfJob;
	
	public:
	Job(){
		jobID = count++;
	}
	
	friend istream& operator >> (istream &in, Job &j){
			int temp;
			cout << "Enter the Job Fee\n";
			in >> temp;
			if(temp >= 250)
				j.CostOfJob = temp;
			
			else{
				JobException objjob(j);
				throw(objjob);
		}
		return in;
	}
	
	friend ostream& operator << (ostream &out, const Job &j){
		out << "Job ID: "<< j.jobID << endl;
		out << "Cost Of Job: " << j.CostOfJob << endl;
		return out;
	}
};

int Job::count = 1;

int  main()
{
	Job jobs[5];
	int i;
	
	for(int i=0;i<5;i++){
		try{
			cout << "job No " << i+1 << ' ';
			cin >> jobs[i];
		}
		
		catch(JobException &e){
			e.show();
			i--;
		}
	}
	
	cout << "\nData\n\n";	
	for(int i = 0; i < 5; i++ )
		cout << jobs[i];
	return 0;
}
