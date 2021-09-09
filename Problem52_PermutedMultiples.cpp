// Permuted multiples.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

//gets a vector of the digits in a number, sorted in ascending order.
std::vector<int> getDigits(int number_)
{
	int number = number_;
	std::vector<int> outputVec;
	bool divisible = true;
	while (divisible == true)
	{
		outputVec.push_back(number % 10);
		number /= 10;
		if (number < 1)
			divisible = false;


	}

	std::sort(outputVec.begin(), outputVec.end());
	/*
	for(int i = 0; i < outputVec.size(); i++)
		std::cout << outputVec[i];
		*/
	return outputVec;

}


//gets the solution to the problem.
int getSolution() {

	bool searching = true;
	int index = 0;
	//the given max number for x in the problem
	int limit = 6;
	//loop is going on untill a match is found, thus it is sure to be the smallest solution.
	while (searching == true)
	{
		index++;
		//if the vector is the same for all six multiples of the index, then we have found our solution. 
		for (int i = 1; i <= limit; i++)
		{
			if (i == limit)
				searching = false;
			if (getDigits(index) == getDigits(index*i))
				continue;
			else
				break;
		}

		

	}
	//this prints out the solution to the problem.
	std::cout << index;
	return 1;

}

int main()
{
	
	getSolution();
}

