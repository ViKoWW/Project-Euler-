// smallest multiple.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>


int number = 1;
const int factorLimit = 20;


//generates a vector with all the primes below the limit given. 
//this uses the fast sieves algorithm 
std::vector<int> primeVec(int limit)
{
	//creates the vector that will contain the primes
	//also creates the bool array which states if a number is prime
	//the memset function sets the whole array to true as a starting point
	std::vector<int> placeHolderVec;
	bool prime[factorLimit + 1];
	memset(prime, true, sizeof(prime));

	for (int p = 2; p*p <= limit; p++)
	{
		//if prime[p] is not changed, it is true;

		if (prime[p] == true)
		{


			//update all the multiples of p greater than or equal to the square of it.
			//numbers which are multiple of p and are less than p*p are already marked.
			for (int i = p * p; i <= limit; i += p)
			{
				prime[i] = false;
			}

		}

	}
	//after the prime array is correct this loop then adds the prime numbers to the prime number vector.
	for (int p = 2; p <= limit; p++)
	{
		if (prime[p])
		{
			placeHolderVec.push_back(p);
		//	std::cout << p << " ";
		}
			
	}
	//returns the final vector containing all the primes
	return placeHolderVec;

}

//gets prime factors of a number into a vector
std::vector<int> primeFactors(int inputNum_)
{
	int inputNum = inputNum_;
	std::vector<int> primePlaceholderVec;
	bool divisible;
	
		for (int i = 0; i < primeVec(factorLimit).size(); i++)
		{
			divisible = true;
			//as long as the number is divisible the loop will continue
			while (divisible == true) 
			{
				if (inputNum % primeVec(factorLimit)[i] == 0)
				{
					inputNum /= primeVec(factorLimit)[i];
					primePlaceholderVec.push_back(primeVec(factorLimit)[i]);
				//	std::cout << primeVec(factorLimit)[i] << " ";
				}
				else
				{
					//std::cout << "moving on" << '\n';
					divisible = false;
				}
			}

		}
	

	return primePlaceholderVec;


}

//function for getting the unique prime factors for a number, not the amount of times they occur. 
std::vector<int> uniquePrimeFactors(int num) {

	std::vector<int>A =primeFactors(num);
	std::sort(A.begin(), A.end());
	A.erase(std::unique(A.begin(), A.end()), A.end());
	
	return A;

}

int LeastCommonMultiple(int limit)
{
	int indexNum;
	int countIn;
	int countOut;
	int finalOut = 1;
	std::vector<int> outputVector;
	
	//the main loop, from 2 to the limit
	for (int p = 2; p <= limit; p++)
	{

		//gets the primefactors for the current number into a vector
		std::vector<int> primeFactorVec1 = primeFactors(p);
		indexNum = p;
		
		for (int i = 0; i < uniquePrimeFactors(indexNum).size(); i++)
		{
			
			//checks the number of times that the unique factor that the loop runs through occurs in the input vector, which is the primeFactorVec1, and the amount of times the factor occurs in the outputVector
				countIn = std::count(primeFactorVec1.begin(), primeFactorVec1.end(), uniquePrimeFactors(indexNum)[i]);
				countOut = std::count(outputVector.begin(), outputVector.end(), uniquePrimeFactors(indexNum)[i]);
			//if the countIn is larger it adds the factor so that the out matches the in. 
				if (countIn > countOut)
				{
					int countDiff = countIn - countOut;
					for (int j = 0; j < countDiff; j++)
					{
						outputVector.push_back(uniquePrimeFactors(indexNum)[i]);
					
					}
				}
			

		

		}
	}
	//multiplies the factors together to get the finalnumber in finalform and not as factors. 
	for (int c = 0; c < outputVector.size(); c++)
	{
		
		finalOut *= outputVector[c];

	}

	std::cout << "The least common multiple of all the numbers between 1 and " << limit << " is: "<< finalOut;


	return 1;
}

int main()
{
	//searchMultiple(number);
	//std::cout << searchMultiple(1);
	//primeVec(factorLimit);
	//primeFactors(120);
	
	//will output the least common multiple between 1 and the limit, in the case of the euler project the limit is 20. 
	LeastCommonMultiple(20);
}

