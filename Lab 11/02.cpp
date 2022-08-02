#include <iostream>

using namespace std;

class Vehicle{
	int mileage;
	int price;
	int ownershipfees;
	public:
	Vehicle(int price, int mileage, int ownershipfees){
		this->price=price;
		this->mileage=mileage;
		this->ownershipfees=ownershipfees;
	}
	
	friend ostream& operator << (ostream &out, const Vehicle &veh){	
		out <<"Price: "<<veh.price <<'\n';
		out<<"Mileage:  "<< veh.mileage <<'\n';
		out<<"Ownership Fee: "<< veh.ownershipfees <<'\n';
		return out;
	}
};

class Car:public Vehicle{
	int seatingcapacity;
	char fueltype; //('D' diesel or 'P' petrol)
	public:
	Car(int price,int mileage,int ownershipfees,int seatingcapacity,char fueltype) :Vehicle(price,mileage,ownershipfees){
		this->seatingcapacity=seatingcapacity;
		this->fueltype=fueltype;
	}
	
	friend ostream& operator << (ostream &out, const Car &veh){	
		out << (Vehicle)veh;
		out<<"Seating Capacity:  "<< veh.seatingcapacity <<'\n';
		out<<"Fuel Type: ";
		if(veh.fueltype=='P' || veh.fueltype=='p')
			cout << "Petrol" << endl;
		if(veh.fueltype=='D' || veh.fueltype=='d')
			cout << "Diesel" << endl;
		return out;
	}
};

class Bike:public Vehicle{
	
	protected:
	int cubiccapacity;
	int tanksize;
	
	public:
	Bike(int price, int mileage, int ownershipfees, int cubiccapacity, int tanksize) :Vehicle(price,mileage,ownershipfees){
		this->cubiccapacity=cubiccapacity;
		this->tanksize=tanksize;
	}
			
	friend ostream& operator << (ostream &out, const Bike &veh){	
		out << (Vehicle)veh;
		out<<"Engine Capacity:  "<< veh.cubiccapacity<<'\n';
		out<<"Tank Size: "<< veh.tanksize << " Inches" <<'\n';
		return out;
	}
};

class ImportedCar:public Car{
	
	int importYear;
	int manufactureYear;
	int mileageAbroad;
	public:
	ImportedCar(int price, int mileage, int ownershipfees,int seatingcapacity, char fueltype, int importYear,int manufactureYear,int mileageAbroad) 
	:Car(price,mileage,ownershipfees,seatingcapacity,fueltype)
	{
		this->importYear= importYear;
		this->manufactureYear=manufactureYear;
		this->mileageAbroad=mileageAbroad;
	}
	
	
	friend ostream& operator << (ostream &out, const ImportedCar &veh){	
		out << (Car)veh;
		out<<"Import Year:  "<< veh.importYear<<'\n';
		out<<"Manufacture Year: "<< veh.manufactureYear<<'\n';
		out << "Mileage Abroad: " << veh.mileageAbroad <<'\n';
		return out;
	}
};

class LocalCar:public Car{
	int manufacturedYear;
	public:
	LocalCar(int price, int mileage, int ownershipfees,int seatingcapacity, char fueltype, int manufacturedYear) 
	:Car(price,mileage,ownershipfees,seatingcapacity,fueltype)
	{
		this->manufacturedYear=manufacturedYear;
	}
	friend ostream& operator << (ostream &out, const LocalCar &veh){	
		out << (Car)veh;
		out<<"Manufacture Year: "<< veh.manufacturedYear<<'\n';
		return out;
	}
};


class HeavyBike:public Bike{
	int NoofCylinders;
	int NoofGears;
	char CoolingType; //('A' air, 'L' liquid or 'O' oil)
	char WheelType; //('A' alloys or 'S' spokes)
	
	public:
	HeavyBike(int price, int mileage, int ownershipfees, int tanksize, int cubiccapacity,int NoofCylinders, int NoofGears, char CoolingType,char WheelType) 
	:Bike(price, mileage, ownershipfees, tanksize, cubiccapacity)
	{
		this->NoofCylinders=NoofCylinders;
		this->NoofGears=NoofGears;
		this->CoolingType=CoolingType;
		this->WheelType=WheelType;
	}
	
	friend ostream& operator << (ostream &out, const HeavyBike &veh){	
		out << (Vehicle)veh;
		out<<"Cylinders:  "<< veh.NoofCylinders <<'\n';
		out<<"Number Of Gears: "<< veh.tanksize <<'\n';
		out<<"Cooling Type: ";
		if(veh.CoolingType=='A' || veh.CoolingType=='a')
			cout << "Air" << endl;
		if(veh.CoolingType=='L' || veh.CoolingType=='l')
			cout << "Liquid" << endl;
		if(veh.CoolingType=='O' || veh.CoolingType=='o')
			cout << "Oil" << endl;
			
		out<<"Tyre Type: ";
		if(veh.WheelType=='A' || veh.WheelType=='a')
			cout << "Alloys" << endl;
		if(veh.WheelType=='S' || veh.WheelType=='s')
			cout << "Spokes" << endl;
		return out;
	}

};

int main(){
	Bike bike(70000, 12000, 1000, 70, 10);
    cout << bike;
    cout <<"----------------------------\n";
    HeavyBike hbike(70000, 12000, 1000, 70, 10, 4,6,'A','A');
    cout << hbike;
    cout <<"----------------------------\n";
    ImportedCar iCar(870000, 120000, 10000, 5, 'P', 2008, 2006,90000);
    cout << iCar;
    cout <<"----------------------------\n";
    LocalCar lCar(870000, 120000, 10000, 5, 'P', 2008);
    cout << lCar;
    cout <<"----------------------------\n";
    return 0;

}





