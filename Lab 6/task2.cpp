#include <iostream>

using namespace std;

class Rope{
	 int ft;//any positive number greater than 0
	 int inch;//0-11 only, if exceed add to ft and assign remaining to inch
	 //using integer division and remainder operators, default value 0
	public:
	Rope(){ 
		ft=1; 
		inch=1;
	}
	
	void setFt(int ft){
		if(ft>0) 
		this->ft=ft;
		else 
		this->ft=1;
	}
	
	void setInch(int inch){
		if(inch<0) 
		this->inch=0;
		
		else if(inch>0 && inch < 12)
		this->inch=inch;
		
		if(inch>11){
			this->ft+=(inch/12);
			inch = inch%12;
			this->inch=inch;
		}
	}
	
	Rope(int f, int i){ 
		setFt(f); 
		setInch(i);
	}
	
	
	Rope operator+(Rope &r){
		Rope newR = *this;
		return newR+=r;	
	}
	
	Rope operator+=(Rope &r){
		ft =ft + r.ft;
		inch=inch+r.inch;
		setInch(inch);
		return *this;
	}
	
	Rope operator-(int k){
		Rope newR = *this;
		return newR-=k;	
	}
	
	Rope operator-=(int k){
		if(k>inch)
		inch+=6;
		ft--;
		return *this;
	}
	
	
	void show() const {
	cout << "Length:";
	if (ft==1 ) cout << "1 foot ";
	else if (ft>1) cout << ft << " feet ";
   	if (inch==0) cout << '\n';
	else if (inch==1) cout << "1 inch\n";
	else cout << inch << " inches\n";
	}
};

int main() { 
	Rope r1(3,4), r2(-4,6);
	Rope r3(2,-5), r4(4,19);
	cout << "Rope R1: "; r1.show();
	cout << "Rope R2: "; r2.show();
	cout << "Rope R3: "; r3.show();
	cout << "Rope R4: "; r4.show();
	cout << "Rope R2+R4: "; (r2+r4).show();
	cout << "Rope R1+=R4: "; (r3+=r4).show();
	cout << "Rope R3: "; r3.show();
	cout << "Rope R1-6 inches: "; (r1-=6).show();
	return 0;
}

