/*
 * Title: Car Salesman
 * Author: Brandon Grunes
 * Description: Car Salesman allows UK citizens to find used cars for sale by make, model, year, price, transmission type, fuel type, engine size, mileage, and mpg.
 *				The program allows you to first sort the list of cars using merge sort and tim sort by year, price, and mileage to find the fastest way to sort through the list of cars.
 *				You can also specify the search by make, price, and year so that you can get a smaller list of cars printed out for you to see.
*/

#include "car.cpp"
#include <iostream>
#include <fstream>
#include<sstream>
#include <vector>
#include <chrono>
#include <algorithm>
using std::cout;
using std::cin;
using std::getline;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::milli;
using std::min;

// All Main Functions
void getData(string fileName, vector<Car>& ur, string make);
void sortProblem(vector<Car> vec, int vSize, int input);
bool handleData(vector<Car> vec);
void saveToFile(vector<Car> vec);
vector<Car> subsort(vector<Car> vec, string input, string type);
vector<Car> subsort(vector<Car> vec, int min, int max);
void mergeSort(vector<Car>& vec, int left, int right, int type);
void merge(vector<Car>& vec, int left, int mid, int right, int type);
void timSort(vector<Car>& vec, int type);
void insertion(vector<Car>& vec, int left, int right, int type);



int main()
{	
	vector<string> fileName = { "files\\audi.csv", "files\\bmw.csv", "files\\cclass.csv", "files\\ford.csv", "files\\hyundi.csv",
		"files\\merc.csv", "files\\skoda.csv", "files\\toyota.csv", "files\\vauxhall.csv", "files\\vw.csv"};
	vector<Car> cars;
	int vSize;

	cout << "Loading data...";
	getData(fileName[0], cars, "Audi");
	getData(fileName[1], cars, "BMW");
	getData(fileName[2], cars, "Mercedes");
	getData(fileName[3], cars, "Ford");
	getData(fileName[4], cars, "Hyundi");
	getData(fileName[5], cars, "Mercedes");
	getData(fileName[6], cars, "Skoda");
	getData(fileName[7], cars, "Toyota");
	getData(fileName[8], cars, "Vauxhall");
	getData(fileName[9], cars, "Volkswagon");
	vSize = cars.size();
	cout << "done!\n\n";

	// Print Welcome
	cout << "------------------------------------------------------------------------------------------------------------------------\n";
	cout << "Welcome to Car Salesman!\n";
	cout << "Created by Brandon Grunes\n";
	cout << "Here you can sort through all the used cars for sale. The easier way to buy!\n";
	cout << "------------------------------------------------------------------------------------------------------------------------\n\n";
	while (true)
	{
		// Print Main Menu
		cout << "---------\n";
		cout << "MAIN MENU\n";
		cout << "---------\n";
		cout << "What would you like to do?\n";
		cout << "1. Sort by year\n";
		cout << "2. Sort by mileage\n";
		cout << "3. Sort by Price\n";
		cout << "4. Exit\n\n";
		cout << "Choose (by number): ";

		string input;
		cin >> input;

		stringstream ss(input);
		int in = 0;
		ss >> in;

		// Sort by:
		// State
		if (in == 1)
		{
			sortProblem(cars, vSize, in);
		}
		// City
		else if (in == 2)
		{
			sortProblem(cars, vSize, in);
		}
		// Zipcode
		else if (in == 3)
		{
			sortProblem(cars, vSize, in);
		}
		// Exit
		else if (in == 4)
		{
			cout << "\nExiting program...";
			exit(0);
		}
		// Catch if the user types in an unnecessary response
		else
		{
			cout << "Unknown response detected! Please try again.\n";
			cout << "Example response: 1\n\n";
		}
	}
	return 0;
}

// Acquire data from csv file
void getData(string fileName, vector<Car>& ur, string make)
{
	ifstream file(fileName);

	if (file.is_open())
	{
		string title;
		string model, year, price, trans, mileage,  fuel, tax, mpg, eSize;

		// Buffer over the 1st column
		getline(file, title, '\n');

		while (!file.eof())
		{
			getline(file, model, ',');
			getline(file, year, ',');
			getline(file, price, ',');
			getline(file, trans, ',');
			getline(file, mileage, ',');
			getline(file, fuel, ',');
			getline(file, tax, ',');
			if (fileName != "files\\cclass.csv")
				getline(file, mpg, ',');
			getline(file, eSize, '\n');

			Car newR(make, model, year, price, trans, mileage, fuel, mpg, eSize);

			ur.push_back(newR);
		}

		file.close();
	}
	else
		cout << "ERROR: FILE NOT FOUND\n";
}

// Calculate and print the total time it takes for merge and tim sort to complete (in milliseconds)
void sortProblem(vector<Car> cars, int vSize, int input)
{
	auto t1 = high_resolution_clock::now();
	auto t2 = high_resolution_clock::now();
	duration<double, milli> mergeTime;
	duration<double, milli> timTime;

	vector<Car> mergedCars = cars;
	vector<Car> timCars = cars;
	
	cout << "Merge Sorting...";
	t1 = high_resolution_clock::now();
	mergeSort(mergedCars, 0, vSize - 1, input);
	t2 = high_resolution_clock::now();
	mergeTime = t2 - t1;
	cout << "done in " << mergeTime.count() << " ms!\n";

	cout << "Tim Sorting...";
	t1 = high_resolution_clock::now();
	timSort(timCars, input);
	t2 = high_resolution_clock::now();
	timTime = t2 - t1;
	cout << "done in " << timTime.count() << "ms!\n\n";

	bool isDone = false;
	while (!isDone)
	{
		isDone = handleData(mergedCars);
	}
}

// Handle what to do after sorting by user specifications
bool handleData(vector<Car> vec)
{
	vector<Car> newVec;
	string input;

	cout << "Specify Data? (y/n): ";
	cin >> input;

	if (input == "y")
	{
		cout << "\nSubsection by: \n";
		cout << "1. Make\n";
		cout << "2. Year\n";
		cout << "3. Price Range\n\n";
		cout << "Choice (by Number): ";
		cin >> input;

		if (input == "1")
		{
			cout << "\nWhich make would you like to choose?\n";
			cout << "Available makes: \n";
			cout << "1. Audi\n";
			cout << "2. BMW\n";
			cout << "3. Ford\n";
			cout << "4. Hyundai\n";
			cout << "5. Mercedes\n";
			cout << "6. Skoda\n";
			cout << "7. Toyota\n";
			cout << "8. Vauxhall\n";
			cout << "9. Volkswagon\n\n";
			cout << "Choice (by number): ";

			cin >> input;

			if (input == "1")
				newVec = subsort(vec, "Audi", "1");
			else if (input == "2")
				newVec = subsort(vec, "BMW", "1");
			else if (input == "3")
				newVec = subsort(vec, "Ford", "1");
			else if (input == "4")
				newVec = subsort(vec, "Hyundai", "1");
			else if (input == "5")
				newVec = subsort(vec, "Mercedes", "1");
			else if (input == "6")
				newVec = subsort(vec, "Skoda", "1");
			else if (input == "7")
				newVec = subsort(vec, "Toyota", "1");
			else if (input == "8")
				newVec = subsort(vec, "Vauxhall", "1");
			else if (input == "9")
				newVec = subsort(vec, "Volkswagon", "1");
		}
		else if (input == "2")
		{
			cout << "Input a year: ";
			cin >> input;

			newVec = subsort(vec, input, "2");
		}
		else if (input == "3")
		{
			cout << "Input two numbers separated by a space to represent the minimum and maximum of the range (Example: 3000 5000):";
			string min, max;

			cin >> min;
			cin >> max;

			newVec = subsort(vec, stoi(min), stoi(max));
		}
	}
	else if (input == "n")
	{
		return true;
	}


	cout << "Would you like to do another specified search?\n";
	cout << "WARNING: typing \'n' will delete your current search query (y/n): ";
	cin >> input;

	cout << "\n";
	if (input == "y")
		handleData(newVec);
	else if (input == "n")
	{
		cout << "Would you like to save your data to a file? (y/n): ";
		cin >> input;

		if (input == "y")
			saveToFile(vec);
		return true;
	}
	else
	{
		cout << "Please provide a valid response!\n\n";
		return false;
	}

	return true;
}

// Save grouping vector created by user to new csv file
void saveToFile(vector<Car> vec)
{
	ofstream newFile;
	newFile.open("carlist.csv");

	newFile << "Year,Make,Model,Transmission,Mileage,Fuel Type,MPG,Engine Size, Price (in $)\n";
	
	for (int i = 0; i < vec.size(); i++)
	{
		newFile << vec[i].getYear() << "," << vec[i].getMake() << "," << vec[i].getModel() << "," << vec[i].getTrans() << "," << vec[i].getMileage() << "," <<
			vec[i].getFuelType() << "," << vec[i].getMpg() << "," << vec[i].getEngineSize() << "," << vec[i].getPrice() << "\n";
	}

	newFile.close();
}

// Both subsorts are used in the handleData function
// Specifically for printing out the data
vector<Car> subsort(vector<Car> vec, string input, string type)
{
	vector<Car> newVec;
	for (int i = 0; i < vec.size(); i++)
	{
		if (type == "1")
		{
			if (vec[i].getMake() == input)
			{
				newVec.push_back(vec[i]);
				vec[i].printData();
			}
		}
		if (type == "2")
		{
			if (vec[i].getYear() == input)
			{
				newVec.push_back(vec[i]);
				vec[i].printData();
			}
		}
	}

	return newVec;
}

vector<Car> subsort(vector<Car> vec, int min, int max)
{
	vector<Car> newVec;
	for (int i = 0; i < vec.size(); i++)
	{
		if (stoi(vec[i].getPrice()) * 1.25 >= min && stoi(vec[i].getPrice()) * 1.25 <= max)
		{
			newVec.push_back(vec[i]);
			vec[i].printData();
		}
	}

	return newVec;
}

//Credit to Amanpreet Kapoor lecture slides on Sorting, with modification for project
void mergeSort(vector<Car>& vec, int left, int right,int type)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeSort(vec, left, mid, type);
		mergeSort(vec, mid + 1, right, type);

		// Merge the sorted vectors
		merge(vec, left, mid, right, type);
	}
}

void merge(vector<Car>& vec, int left, int mid, int right, int type)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
	vector<Car> x(n1), y(n2);

	for (int i = 0; i < n1; i++)
		x[i] = vec[left + i];
	for (int i = 0; i < n2; i++)
		y[i] = vec[mid + 1 + i];

	//Merge vectors x and y into vec
	int i, j, k;
	i = 0; j = 0; k = left;

	while (i < n1 && j < n2)
	{
		if (type == 1)
		{
			if (x[i].getYear() <= y[j].getYear())
			{
				vec[k] = x[i];
				i++;
			}
			else
			{
				vec[k] = y[j];
				j++;
			}
		}
		else if (type == 2)
		{
			if (x[i].getMileage() <= y[j].getMileage())
			{
				vec[k] = x[i];
				i++;
			}
			else
			{
				vec[k] = y[j];
				j++;
			}
		}
		else if (type == 3)
		{
			if (x[i].getPrice() <= y[j].getPrice())
			{
				vec[k] = x[i];
				i++;
			}
			else
			{
				vec[k] = y[j];
				j++;
			}
		}
		k++;
	}

	while (i < n1)
	{
		vec[k] = x[i];
		i++; k++;
	}

	while (j < n2)
	{
		vec[k] = y[j];
		j++; k++;
	}
}

// Tim sort uses the merge and insertion functions to process
void timSort(vector<Car>& vec, int type)
{
	const int run = 32;
	int n = vec.size();
 	for (int i = 0; i < n; i += run)
		insertion(vec, i, min(i + run - 1, n - 1), type);

	for (int j = run; j < n; j *= 2)
	{
		for (int left = 0; left < n - j; left += 2 * j)
		{
			int mid = left + j - 1;
			int right = min(left + 2 * j - 1, n - 1);

			merge(vec, left, mid, right, type);
		}
	}
}

// Insertion sort function for tim sort
void insertion(vector<Car>& vec, int left, int right, int type)
{
	for (int i = left + 1; i <= right; i++)
	{
		Car temp = vec[i];
		int j = i - 1;

		if (type == 1)
		{
			while (j >= left && vec[j].getYear() > temp.getYear())
			{
				vec[j + 1] = vec[j];
				j--;
			}
		}
		else if (type == 2)
		{
			while (j >= left && vec[j].getMileage() > temp.getMileage())
			{
				vec[j + 1] = vec[j];
				j--;
			}
		}
		else if (type == 3)
		{
			while (j >= left && vec[j].getPrice() > temp.getPrice())
			{
				vec[j + 1] = vec[j];
				j--;
			}
		}
		vec[j + 1] = temp;
	}
}
