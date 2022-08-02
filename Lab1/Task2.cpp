#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int main()
{
	
	srand(time(0));
	int *ptr1, *ptr2, *ptr3, *ptr4, *ptr5 ,n[5], i, sum[5], j=0, maxindex=0 ;
	float avg1, avg2, avg3, avg4, avg5;
	
	for(i=0;i<5;i++){
		
		n[i] = rand() % 4 + 11;
	}
	
	ptr1 = new int [n[0]];
	ptr2 = new int [n[1]];
	ptr3 = new int [n[2]];
	ptr4 = new int [n[3]];
	ptr5 = new int [n[4]];
	sum[j] = 0;
	for(i=0;i<n[0];i++){
		
	
		ptr1[i]=rand() % 90 + 10;
		
		sum[j]=sum[j]+ptr1[i];
	}
	
	avg1 = (float)sum[j]/(float)n[0];
	j++;
	sum[j] = 0;
	
	for(i=0;i<n[1];i++){
		
		
		ptr2[i]=rand() % 90 + 10;
		
		sum[j]=sum[j]+ptr2[i];
	}
	
	avg2 = (float)sum[j]/(float)n[1];
	j++;
	sum[j] = 0;
	
	for(i=0;i<n[2];i++){
		
		
		ptr3[i]=rand() % 90 + 10;
		
		sum[j]=sum[j]+ptr3[i];
	}
	
	avg3 = (float)sum[j]/(float)n[2];
	j++;
	sum[j] = 0;
	
	for(i=0;i<n[3];i++){
		
		
		ptr4[i]=rand() % 90 + 10;
		
		sum[j]=sum[j]+ptr4[i];
	}
	
	avg4 = (float)sum[j]/(float)n[3];
	j++;
	sum[j] = 0;
	
	for(i=0;i<n[4];i++){
		
		
		ptr5[i]=rand() % 90 + 10;
		
		sum[j]=sum[j]+ptr5[i];
	}
	
	avg5 = (float)sum[j]/(float)n[4];

	
	if(avg1> avg2 && avg1>avg3 && avg1>avg4 && avg1>avg5)
	{
		cout<<"Array 1 has maximum Average\n";
		
		for( i=0; i<n[0]; i++)
			cout << ptr1[i] << ' ';
	}
	
	else if(avg2>avg1 && avg2>avg3 && avg2>avg4 && avg2>avg5)
	{
		cout<<"Array 2 has maximum Average\n";
		for(i=0; i<n[1]; i++)
			cout << ptr2[i] << ' ';
	}
	
	else if(avg3>avg1 && avg3>avg2 && avg3>avg4 && avg3>avg5)
	{
		cout<<"Array 3 has maximum Average\n";
		for(i=0; i<n[2]; i++)
			cout << ptr3[i] << ' ';
	}
	
	else if(avg4>avg1 && avg4>avg2 && avg4>avg3 && avg4>avg5)
	{
		cout<<"Array 4 has maximum Average\n";
		for(i=0; i<n[3]; i++)
			cout << ptr4[i] << ' ';

	}
	
	else 
	{
		cout<<"Array 5 has maximum Average\n";
		for(i=0; i<n[4]; i++)
			cout << ptr5[i] << ' ';

	}
	
	
	delete [] ptr1;
	delete [] ptr2;
	delete [] ptr3;
	delete [] ptr4;
	delete [] ptr5;
	
	return 0;
}
