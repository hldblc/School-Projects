# include <iostream>		
# include <cstring>			
using namespace std;


int main ()
{
	const int num = 11;		
	const int length = 100;		

	
	char contacts[num][length] = {   "Alejandra Cruz, 555-1223", 
									 "Joe Looney, 555-0097",
									 "Geri Palmer, 555-8787", 
									 "Li Chen, 555-1212",
									 "Holly Gaddis, 555-8878", 
									 "Sam Wiggins, 555-0998",
									 "Bob Kain, 555-8712", 
									 "Tim Haynes, 555-7676",
									 "Warren Gaddis, 555-9037", 
									 "Jean James, 555-4949",
									 "Ron Palmer, 555-2783"};

	char search[length];		
								
	char *IdContact = NULL;		 
  
	int index;		
	
	
	cout << "To search for your contact's number please enter a name or partial name of the person.\n";
	cin.getline(search, length);		
	
	
	for (index = 0; index < num; index++)
	{
		IdContact = strstr(contacts[index], search);
			if (IdContact != NULL)
			{
				cout << contacts[index];		
				
			}
			
	}

		if (IdContact == NULL)
				cout << "Sorry, No matches were found!";
	return 0;
}
