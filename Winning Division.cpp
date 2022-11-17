#include <iostream>
#include <string>

using namespace std;

double getSales(string);
void findHighest(double, double, double, double);
bool again();

int main()
{
// variables
double nwSales, neSales, swSales, seSales;
string NW = "Northwest", NE = "Northeast", SW = "Southwest", SE = "Southeast";

do
{
// these are calls to a function that returns a value
nwSales = getSales(NW);
neSales = getSales(NE);
swSales = getSales(SW);
seSales = getSales(SE);

findHighest(nwSales,neSales,swSales,seSales);
}
while (again());
}

double getSales(string division)
{
double sales;
do
{
cout << "The " << division << " division had a quarterly sales of: \t$ ";
cin >> sales;
cout << "\n";
}
while (sales < 0.0);
return sales;
}

void findHighest(double nwSales, double neSales, double swSales, double seSales)
{
double highestSales = neSales;
string highestDivision = "Northeast";

if (nwSales >= highestSales)
{
highestSales = nwSales;
highestDivision = "Northwest";
}

if (swSales >= highestSales)
{
highestSales = swSales;
highestDivision = "Southwest";
}

if (seSales > highestSales)
{
highestSales = seSales;
highestDivision = "Southeast";
}
cout << "The " << highestDivision << " quarterly sales was the highest with $" << highestSales << " on sales." << endl;
}

bool again()
{
char yesorno;
cout << "\n\nWould you like to calculate again? Y/N ";
cin >> yesorno;

if (toupper(yesorno) == 'Y')
return true;
else
return false;
}
