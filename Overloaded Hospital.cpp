#include <iostream>
#include <iomanip>

using namespace std;

void validInput(int, int, double, double, double);
double calcCharges(int, double, double, double);
double calcCharges(double, double);

int main()
{
    
    int days, choice;
    double rate, serviceCharge, medCharge;
    
    cout << fixed << showpoint << setprecision(2);
    
    cout << "What type of patient was admitted?" << endl;
    
    do
    {
        cout << "ENTER '1' for IN-PATIENT or '0' for OUT-PATIENT: \t ";
        cin >> choice;
    }
    while(choice != 1 && choice != 0);
    
    validInput(choice, days, rate, serviceCharge, medCharge);

    return 0;
}

void validInput(int c, int d, double r, double s, double m)
{
    {
        switch(c)
        {
        case 1:
            cout << "Enter the number of days spent in the Hospital: \t ";
            cin >> d;
            cout << "Enter the Hospital's daily rate for stay: \t\t$";
            cin >> r;
            cout << "Enter the fee for the Medical Services provided: \t$";
            cin >> s;
            cout << "Enter the fee for Hospital Medication administered: \t$";
            cin >> m;
            cout << "The Hospital charges for the Patient are : \t\t$" << calcCharges(d, r, s, m) << endl;
            break;
        case 0:
            cout << "Enter the fee for the Medical Services provided: \t$";
            cin >> s;
            cout << "Enter the fee for Hospital Medication administered: \t$";
            cin >> m;
            cout << "The Hospital charges for the Patient are : \t\t$" << calcCharges(s, m) << endl;
            break;
        }
    }
    while((d < 0) || (r < 0) || (s < 0) || (m < 0));
}

double calcCharges(int numDays, double dayRate, double medServ, double hospMed)
{
    return (numDays * dayRate) + medServ + hospMed;
}

double calcCharges(double medServ, double hospMed)
{
    return medServ + hospMed;
}
