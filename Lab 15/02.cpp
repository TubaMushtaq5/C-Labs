#include<iostream>
#include<cstring>
#include<stdexcept>

using namespace std;

class OutOfRange : out_of_range{
	double high;
	double low;
	double value;
public:
	OutOfRange ( double h, double l, double v ) : out_of_range("Error")
	{
		high = h;
		low = l;
		value = v;
	}
	double getHigh() const
	{
		return high;
	}
	double getLow() const
	{
		return low;
	}
	double getValue() const
	{
		return value;
	}
};

class Meal{
	char* mealName;
	double price;
public:
	Meal() { mealName = new char[100];	}
	
	friend istream& operator >> (istream& in, Meal &m)
	{
		double price;
		cout << "Enter Meal Name: ";
		in.ignore();
		in.getline(m.mealName, 100, '\n');
		cout << "Enter Price: ";
		in >> price;
		m.setPrice(price);
		return in;
	}
	void setPrice(double p)
	{
		if( p >= 5 && p <= 29.99 )
			this->price = p;
		else 
		{
			OutOfRange obj(5, 29.99, p);
			throw (obj);
		}
	}
	
	void show() const
	{
		cout << "Meal Name is: " << mealName << '\n';
		cout << "Price of Meal is: " << price << '\n';
	}
	~Meal()
	{
		delete[] mealName;
	}
};

int  main()
{
	Meal meal[5];
	int i;
	
	for(i = 0; i < 5; i++)
	{
		try{
			cin >> meal[i];
		}
		catch( OutOfRange obj )
		{
			cout << "-----------Error Entering Price-------------------\n";
			cout << "Upper Field: " << obj.getHigh() << '\n';
			cout << "Lower Field: " << obj.getLow() << '\n';
			cout << "Entered Field: " << obj.getValue() << '\n';
			cout << '\n';
			meal[i].setPrice(18);
		}
	}
	
	cout << "\n----------Displaying Data---------------\n\n";
	for(i = 0; i < 5; i++ )
		meal[i].show();
	return 0;
}
