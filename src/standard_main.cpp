#include <iostream>

using namespace std;

#include "string.hpp"

int main()
{
	String firstString("First");
	String secondString("Second");
	String thirdString(firstString);
	String fourthString("Fourth");
	String fifthString = String();
	cout << "+: " << firstString + secondString << '\n';
	cout << "+=: " << (firstString += secondString) << '\n';
	cout << "indexOf (String)" << firstString.indexOf(secondString) << '\n';
	cout << "indexOf (char) " << firstString.indexOf('t') << '\n';
	cout << "LT: " << (secondString < firstString) << '\n';
	cout << "GT: " << (secondString > firstString) << '\n';
	cout << "LE: " << (secondString <= firstString) << '\n';
	cout << "GE: " << (secondString >= firstString) << '\n';
	cout << "<<: " << fifthString << '\n';
	cout << "<<: " << fourthString << '\n';
	cout << "== " << (secondString == firstString) << '\n';
	cout << "indexOf(String: " << fourthString.indexOf(fifthString) << '\n';
	cout << "size(): " << fifthString.size() << '\n'; 
	cout << "size(): " << fourthString.size() << '\n';
	cout << "[]: " << firstString[0] << '\n';
	cout << "[]: " << firstString[firstString.size() - 1] << '\n';
	cout << "[]" << secondString[0] << '\n';
	cout << "[]: " << secondString[secondString.size() - 1] << '\n';
	cout << "[]: " << fifthString[0] << '\n';
	cout << "!=: " << (thirdString != thirdString) << '\n';
	cout << "Enter a test string: ";
	cin >> firstString;
	cout << firstString << '\n';
	cout << (firstString > secondString) << '\n';
	cout << (firstString <= thirdString) << '\n';
	cout << (firstString > fourthString) << '\n';
	cout << (firstString >= fifthString) << '\n';
	return 0;


 









}
