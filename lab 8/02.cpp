#include <iostream>

using namespace std;

class Rectangle{
	int rows;
	int columns;
	char style;
	public:
		Rectangle(int rows,int columns, char style){
			setrows(rows); 
			setcols(columns);
			setstyle(style);
		}		
		
		void setrows(int rows){
			
		if(rows <= 0) 
			this->rows = 10;
		else 
			this->rows = rows;
		}
		
		void setcols(int columns){
		if(columns <= 0) 
			this->columns = 10;
		else 
			this->columns = columns;}
		
		void setstyle(char style){
			this->style=style;
		}
		
		void setSize(int percent){
			
			rows=rows*(float)(percent)/100.0;
			columns=columns*(float)(percent)/100.0;
		}
		
		void pattern(){ 
			for(int i=0;i<columns;i++)
				cout << style;
			cout << '\n';
			for(int i=0;i<(rows-2);i++)
				{
				cout << style;
				for(int j=0;j<(columns-2);j++)
					cout << ' ';
				cout << style << '\n';
				}
			for(int i=0;i<columns;i++)
				cout << style;
				
			cout << "\n";
		}
		
		void multipleoutline(int noofoutline){
		
			for(int i=0;i<noofoutline;i++)
				{
				for(int i=0;i<columns;i++)
					cout << style;
				cout << '\n';
				}
				
			for(int i=0;i<rows;i++){
			
				for(int i=0;i<noofoutline;i++)		
					cout << style;
				for(int i=0;i<(columns-(2*noofoutline));i++)
					cout << ' ';
				for(int i=0;i<noofoutline;i++)
						cout << style;
				cout << '\n';
				}
				
			for(int i=0;i<noofoutline;i++){
				for(int i=0;i<columns;i++)
					cout << style;
				cout << "\n";
				}
				
				cout << "\n";
	}
		
		Rectangle& operator ++ (){
			rows++;
			columns++;
			return *this;
		}
		
		Rectangle operator ++ (int){
			Rectangle newR = *this;
			rows++;
			columns++;
			return newR;
		}
		
		Rectangle& operator += (Rectangle &r){
			rows += r.rows;
			columns += r.columns;
			return *this;
		}
		
		Rectangle& operator -= (Rectangle &r){
			if (rows>r.rows && columns > r.columns )
			{
				rows -= r.rows;
				columns -= r.columns;
			}
			else if (rows<r.rows && columns<r.columns )
			{
				rows = r.rows - rows;
				columns = r.columns - columns;
			}
			return *this;
		}
			
		Rectangle& operator *= (float newsize){
			rows *= newsize;
			columns *= newsize;
			return *this;
		}		
};
int main()
{
	Rectangle a1(4,10, '*'), a2(5,10, '#');
	a1.pattern();
	a2.pattern();
	
	a1 += a2;
	a1.pattern();
	
	a1 -= a2;
	a1.pattern();
	
	a1++;
	a1.pattern();
	
	++a1;
	a1.pattern();
	a1.setstyle('#');
	
	a1 *= 1.5;
	a1.pattern();
	
	a1.setSize(100);
	
	a1.pattern();
	
	a1.multipleoutline(3);
	
	return 0;
}

