#include "pch.h"
#include <iostream>

int start1 = 0;
int start2 = 1;
const int limit = 4000000;
int evenSum = 0;
//funktion som räknar ut fibonacci sekvensen samt identifierar om ena parametern, num2, är jämnt, isåfall läggs det till i summan evenSum.
void evaluateFibonacci(int num1, int num2) {
	//checkar om talet är jämnt
	if ((num2 % 2) == 0)
	{
		evenSum += num2;
	//	std::cout << evenSum << std::endl;
	}
	//funktionen som tar fram fibonacci sekvensen, görs genom rekursion då funktionen kallar sig själv om och om igen tills det att det större numret är större än 4 miljoner. 
	int placeholder;
	placeholder = num1;
	num1 = num2;
	num2 = placeholder + num2;
	//std::cout << num1 << std::endl;
	if(num2 < limit)
		evaluateFibonacci(num1, num2);
	
}


int main()
{
	//main funktionen, kör fibonacci funktionen med starttalen 0 och 1. 
	evaluateFibonacci(start1, start2);
	//till slut printas den slutgiltiga summan
	std::cout << "The final sum is: " << evenSum;
}

