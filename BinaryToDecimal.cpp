#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void decimalToBinary();
void decimalToBinaryLogic();
void binaryToDecimal();

int main()
{
	decimalToBinary();
	decimalToBinaryLogic();
	binaryToDecimal();
}

void decimalToBinary()
{
	unsigned int decimalNumber = 0;

	std::cout << "Enter a decimal number: ";
	std::cin >> decimalNumber;

	//Check: if number == 0;
	if (decimalNumber == 0)
	{
		std::cout << decimalNumber << " = 0 in binary\n";

		return;
	}

	std::string binaryString = "";

	unsigned int powerOfTwoCount = 0;

	unsigned int decimalNumberCopy = decimalNumber;

	//Get power of two;
	for (int i = 0; decimalNumberCopy != 0; ++i)
	{
		decimalNumberCopy = decimalNumberCopy / 2;
		++powerOfTwoCount;
	}

	//Assign for future processing;
	decimalNumberCopy = decimalNumber;

	std::vector<int> powerOfTwoVec;
	powerOfTwoVec.resize(powerOfTwoCount);
	powerOfTwoVec[0] = 1;

	//Create vector 2^n
	for (int i = 0; i < powerOfTwoCount - 1; ++i)
	{
		powerOfTwoVec[i + 1] = powerOfTwoVec[i] * 2;
	}
	std::reverse(powerOfTwoVec.begin(), powerOfTwoVec.end());


	for (int i = 0; i < powerOfTwoCount; ++i)
	{
		if (decimalNumberCopy - powerOfTwoVec[i] >= 0)
		{
			decimalNumberCopy = decimalNumberCopy - powerOfTwoVec[i];
			binaryString += "1";
		}
		else
		{
			binaryString += "0";
		}
	}
	std::cout << decimalNumber << " = " << binaryString << " in binary.\n";
}

void decimalToBinaryLogic()
{
	unsigned int decimalNumber = 0;

	std::cout << "Enter a decimal number: ";
	std::cin >> decimalNumber;

	//Create temporary copu for futire processing
	unsigned int decimalNumberCopy = decimalNumber;

	std::string binaryString = "";

	//decimalNumber copy for /2 actions
	while (decimalNumberCopy > 0)
	{
		//If decimalNumberCopy == 1: (1&1 = 1 + 48 = 49 = '1') or if decimalNumberCopy == 0: (0&1 = 0 + 48 = 48 = '0')
		char bit = (decimalNumberCopy & 1) + '0';

		binaryString.push_back(bit);
		//Divide on 2 logically
		decimalNumberCopy = decimalNumberCopy >> 1;
	}
	//Because string for 0010 will be look like 0100
	std::reverse(binaryString.begin(), binaryString.end());

	std::cout << decimalNumber << " = " << binaryString << " in binary.\n";
}

void binaryToDecimal()
{
	std::string binary = "";

	std::cout << "Enter binary string: ";
	std::cin >> binary;

	int decimalNumber = 0;

	//For all chars in string do:
	for (char c : binary)
	{
		//ASCII '0' = 48, '1' = 49;
		int bit = c - '0';

		//Shift bit to lefts
		decimalNumber <<= 1;

		//And if it 1: *2 (0|0 = 0, 0|1 = 1) 
		decimalNumber |= bit;
	}
	std::cout << decimalNumber << "\n";
}

