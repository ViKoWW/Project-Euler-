
#include "pch.h"
#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>

//taken from stack overflow to get a constexpr alternative to using pow(number, 0.5) as it cant be used when declaring array sizes.
template <typename T>
constexpr T sqrt_helper(T x, T lo, T hi)
{
	if (lo == hi)
		return lo;

	const T mid = (lo + hi + 1) / 2;

	if (x / mid < mid)
		return sqrt_helper<T>(x, lo, mid - 1);
	else
		return sqrt_helper(x, mid, hi);
}

template <typename T>
constexpr T ct_sqrt(T x)
{
	return sqrt_helper<T>(x, 0, x / 2 + 1);
}

const int searchLimit = 50000000;
constexpr int primeSearchLimit = ct_sqrt(searchLimit);



std::vector<int> primeVec(int limit)
{
	//creates the vector that will contain the primes
	//also creates the bool array which states if a number is prime
	//the memset function sets the whole array to true as a starting point
	std::vector<int> placeHolderVec;
	
	bool prime[(primeSearchLimit + 1) + 1];
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

	//  std::cout << placeHolderVec.size();
	  //returns the final vector containing all the primes
	return placeHolderVec;

}

std::vector<int> uniqueNumbers(std::vector<int> &myVector) {

	std::vector<int>A = myVector;
	std::sort(A.begin(), A.end());
	A.erase(std::unique(A.begin(), A.end()), A.end());

	return A;

}

int searchSolutions(std::vector<int> primes)
{
	int solutionCount = 0;
	int currentNumber;
	std::vector<int> primeVector = primes;
	std::vector<int> encounteredNums;
	

	std::vector<int> fourthVector = primeVec(pow(searchLimit, 0.25)+10);
	std::vector<int> cubeVector = primeVec(std::cbrt(searchLimit)+10);
	std::vector<int> squareVector = primeVec(pow(searchLimit, 0.50));

	//std::cout << cubeVector.size();

	//gets all the solutions that are under 50 000 000, including duplicates.
	for (int i = 0; i < fourthVector.size(); i++)
	{
		for (int j = 0; j < cubeVector.size(); j++)
		{

			for (int n = 0; n < squareVector.size(); n++)
			{
				currentNumber = pow(primeVector[n], 2) + pow(primeVector[j], 3) + pow(primeVector[i], 4);
				if (currentNumber < searchLimit)
				{
					//solutionCount++;
					encounteredNums.push_back(currentNumber);
				}
			}
		}

	}
	//this removes all duplicates and gives the size of the vector, that is the amount of solutions. 
	solutionCount = uniqueNumbers(encounteredNums).size();
	std::cout << solutionCount;
	return 1;



}



int main()
{
//	std::cout << primeSearchLimit << " " << pow(searchLimit, 0.5);
	searchSolutions(primeVec(primeSearchLimit+1));


}
