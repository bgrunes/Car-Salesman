#pragma once
#include <iostream>
#include <string>
using std::cout;
using std::string;

class Car
{
private:
	string make, model, year, price, transmission, mileage, fuelType, mpg, engineSize;

public:
	Car()
	{
		this->make = "";
		this->model = "";
		this->year = "";
		this->price = "";
		this->transmission = "";
		this->mileage = "";
		this->fuelType = "";
		this->mpg = "";
		this->engineSize = "";
	}

	Car(string make, string model, string year, string price, string transmission, string mileage, string fuelType, string mpg, string engineSize)
	{
		this->make = make;
		this->model = model;
		this->year = year;
		this->price = price;
		this->transmission = transmission;
		this->mileage = mileage;
		this->fuelType = fuelType;
		this->mpg = mpg;
		this->engineSize = engineSize;
	}

	string getMake()
	{
		return make;
	}

	string getModel()
	{
		return model;
	}

	string getYear()
	{
		return year;
	}

	string getPrice()
	{
		return price;
	}

	string getTrans()
	{
		return transmission;
	}

	string getMileage()
	{
		return mileage;
	}

	string getFuelType()
	{
		return fuelType;
	}

	string getMpg()
	{
		return mpg;
	}

	string getEngineSize()
	{
		return engineSize;
	}

	void printData()
	{
		cout << year << " " << make << " " << model << "\n";
		cout << "Transmission: " << transmission << " | Mileage: " 
			 << mileage << " miles | Fuel: " << fuelType << " | MPG: "
			 << mpg << " | Engine Size: " << engineSize << " litres\n";
		cout << "Price: " << price << " pounds\n\n";
	}
};