#include "GenerateRandom.hpp"

int generateRandomNumber(int max)
{
	int randomNumber = rand();
	float random = (randomNumber % max) + 1;
	int myRandomNumber = random;
	return myRandomNumber;
}

int generateRandomNumberFromZero(int max)
{
	int randomNumber = rand();
	float random = (randomNumber % max);
	int myRandomNumber = random;
	return myRandomNumber;
}

bool generateRandomBoolNumber(int max)
{
	int randomNumber = rand();
	float random = (randomNumber % 2) + 1;
	int myRandomNumber = random;

	return myRandomNumber == 1 ? true : false;
}