#include <iostream>
#include <cstring> 
using namespace std;


int countChar(char*);

int main()
{
	const int SIZE = 21;
	char userStr[SIZE];

	char* myPtr = nullptr;
	myPtr = userStr;

	cout << "Enter sentence or word not more than " << (SIZE - 1)
		<< " Characters\n";
	cin.getline(myPtr, SIZE);

	
	cout << "Sentence is " << countChar(myPtr) << " characters" << endl;

	return 0;
}

int countChar(char* sentence)
{
	int length;
	length = strlen(sentence);

	return length;


}
