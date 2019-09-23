// Prob49_Prime_permutations.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
1487 4817 8147 148748178147
2969 6299 9629 296962999629
Hello World!
*/
#include "pch.h"
#include <iostream>

int CheckPrime(unsigned long int n)
{
	int i;
	float sr;
	sr = sqrtf(n);
	for (i = 2; i <= sr && n % i != 0; i++);
	if (i > sr)
		return 1; // not 0 true
	return 0;
	// 0 is false
}

int main()
{
	unsigned int n = 1000;
	int temp, i, samedigits;
	while (n < 9999 - 3330 * 2)
	{
		int s[10] = {0,0,0,0,0,0,0,0,0,0};
		if (CheckPrime(n) && CheckPrime(n + 3330) && CheckPrime(n + 6660))
		{
			for (i = 0; i < 10; s[i++] = 0);
			temp = n;
			samedigits = 1;
			for (i = 0; i < 4; i++)
			{
				s[temp % 10] = 1; 
				temp = temp / 10;
			}
			temp = n + 3330;
			for (i = 0; samedigits && i < 4; i++)
			{
				samedigits = samedigits && s[temp % 10];
				temp = temp / 10;
			}
			temp = n + 6660;
			for (i = 0; samedigits && i < 4; i++)
			{
				samedigits = samedigits && s[temp % 10];
				temp = temp / 10;
			}
			if (samedigits)
				printf("\n%d %d %d %d%d%d", n, n + 3330, n + (6660), n, n + 3330, n + (6660));
		}
		n++;
	}
	printf("\nHello World!");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
