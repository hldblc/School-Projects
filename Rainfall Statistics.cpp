#include <iostream>
#include <string>

using namespace std;

void sortByRain(double rainfall[], string months[])
{
   for (int i = 0; i < 12 - 1; i++)
   {
       int max = i;
       for (int j = i + 1; j < 12;j++)
       {
           if (rainfall[j]> rainfall[max])
           {
              max = j;
           }
       }
       if (max != i)
       {
          swap(rainfall[i], rainfall[max]);
           swap(months[i],months[max]);
       }
   }
}

int main()
{
   const int TOTALMONTHS = 12;

   double highest, lowest, getAverage;
   double total = 0;
   double rainfall[TOTALMONTHS];
   string months[TOTALMONTHS] = { "January", "February","March", "April","May",
       "June", "July", "August","September","October", "November", "December" };

   for (int month = 0; month < TOTALMONTHS;month++)
   {
       cout << "Enter rainfall for "<< months[month] << ": ";
       cin >> rainfall[month];
       total += rainfall[month];


       while (rainfall[month] <0)
       {
           cout <<"ninvalid data(negative rainfall) --retry";
           cout <<"nEnter rainfall for " << months[month] << ": ";
           cin >>rainfall[month];
           total +=rainfall[month];
       }
   }

   cout << "Total rainfall: " << total<< endl;

   getAverage = total / TOTALMONTHS;
   cout << "Average rainfall: " << getAverage<< endl;


   string maxMonth = "January", minMonth ="January";
   highest = rainfall[0];
   for (int count = 0; count < TOTALMONTHS;count++)
   {
       if (rainfall[count] >highest)
       {
           highest =rainfall[count];
           maxMonth =months[count];
       }
   }
   lowest = rainfall[0];
   for (int count = 0; count < TOTALMONTHS;count++)
   {
       if (rainfall[count] <lowest)
       {
           lowest =rainfall[count];
           minMonth =months[count];
       }
   }
   cout << "Least rainfall in: " << minMonth<< endl;
   cout << "Most rainfall in: " << maxMonth<< endl;
   //call sortbyrain function

   sortByRain(rainfall, months);
   for (int i = 0; i < TOTALMONTHS; i++)
   {
       cout << months[i] <<endl;
   }
   return 0;
}
