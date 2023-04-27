# Car Salesman
Project 3 of Data Structures and Algorithms, Individual Project
# Author
Brandon Grunes
# Description
Car Salesman allows UK citizens to find used cars for sale by make, model, year, price, transmission type, fuel type, engine size, mileage, and mpg. The program allows you to first sort the list of cars using merge sort and tim sort by year, price, and mileage to find the fastest way to sort through the list of cars. You can also specify the search by make, price, and year so that you can get a smaller list of cars printed out for you to see.

# Time Complexity
Asymptotically, tim sort and merge sort both have the same time complexity of O(n log n), where n is the number of elements in the list. Tim sort is usually faster when physically timed as it uses insertion sort for smaller parts of the data.Technically, the main function can run infinitely as long as the user does not exit the program, so the time complexity is determined by the user input. The rest of the functions are as follow:

*getData = O(n), where n is the number of lines in the input file

*sortProblem = O(n log n) based on tim and merge sort

*handleData = O(n), where n is the size of the vector

*saveToFile = O(n), where n is the size of the vector

*subsort = O(n), where n is the size of the vector

*merge = O(n), where n is the size of the vector

*insertion: O(n), where n is the size of the subvector
