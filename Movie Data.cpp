#include <iostream>
using namespace std;

const int SIZE = 50; 

struct Moviedata
{
   char movieTitle[SIZE]; 
   char movieDirector[SIZE]; 
   int yearReleased; 
   int runningTime;
};

int main()
{

	Moviedata first = {"Interstellar ", "Christopher Nolan", 2014, 169};
	Moviedata second = {"Inception", "Christopher Nolan", 2010, 148};

	cout << "\nHere is the data for the first movie.\n";

	
	cout << "Movie Tittle: " << first.movieTitle << endl;
	cout << "Director of the movie: " << first.movieDirector << endl;
	cout << "The year the movie was released: " << first.yearReleased <<endl;
	cout << "The running time of the movie in minutes: " << first.runningTime << endl;
	
	cout << "\nHere is the data for the second movie.\n";

	
	cout << "Movie Title: " << second.movieTitle << endl;
	cout << "Director of the movie: " << second.movieDirector << endl;
	cout << "The year the movie was released: " << second.yearReleased << endl;
	cout << "The running time of the movie in minutes: " << second.runningTime << endl;
	
	return 0;
}
