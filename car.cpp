#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using std::cout;
using std::string;
using std::stringstream;
using std::fixed;
using std::setprecision;

class Car
{
private:
	// Member variables
	string make, model, year, price, transmission, mileage, fuelType, mpg, engineSize;

public:
	// Default Constructor
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

	// Constructor
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

	/* All Get Functions */

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

	// Function to print member variable data of Car object (formatted)
	void printData()
	{
		stringstream ss;
		ss << std::dec << price;
		double p = 0;
		ss >> p;

		p *= 1.25;
		
		cout << year << " " << make << " " << model << "\n";
		cout << "Transmission: " << transmission << " | Mileage: " 
			 << mileage << " miles | Fuel: " << fuelType << " | MPG: "
			 << mpg << " | Engine Size: " << engineSize << " litres\n";
		cout << "Price: $" << std::fixed << std::setprecision(2) << p << "\n\n";
	}
};