
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <ios>
#include <cstring>
#include <iomanip>
#include <cmath>
#include <string>


using namespace std;

struct matrix
{
    double a=0.0, b=0.0, c= 0.0, d=0.0;
    string name;
};

void infunc( matrix &m1, matrix &m2, double &scal)
{
    cout<< "enter the first matrix name as m1"<<">>";
    cin>> m1.name;

    cout<< "input the values of m1 matrix (just space the numbers in a line)"<<">>";
    cin>> m1.a;

    cout<<">>";
    cin>> m1.b;

    cout<<">>";
    cin>> m1.c;

    cout<<">>";
    cin>> m1.d;



    cout<< "enter the second matrix name as m2"<<">>";
    cin>> m2.name;

    cout<< "input values for the m2 matrix (space the numbers in a line)"<<">>";
    cin>> m2.a;

    cout<<">>";
    cin>> m2.b;

    cout<<">>";
    cin>> m2.c;

    cout<<">>";
    cin>> m2.d;


    cout<< "input the scalar number"<<">>";
    cin>> scal;
}
// ADDITION
void addmatrix(matrix &m1, matrix &m2, matrix &outputmat)
{
    outputmat.a= m1.a + m2.a;
    outputmat.b= m1.b + m2.b;
    outputmat.c= m1.c + m2.c;
    outputmat.d= m1.d + m2.d;
}
// SUBTRACTION
void diffmatrix(matrix &m1, matrix &m2, matrix &outputmat)
{
    outputmat.a= m1.a - m2.a;
    outputmat.b= m1.b - m2.b;
    outputmat.c= m1.c - m2.c;
    outputmat.d= m1.d - m2.d;
}
//MULTIPLICATION questionable
void multiplymatrix(matrix &m1, matrix &m2, matrix &outputmat)
{
    outputmat.a= (m1.a * m2.a) + (m1.b * m2.c);
    outputmat.b= (m1.b * m2.b) + (m1.b * m2.d);
    outputmat.c= (m1.c * m2.c) + (m1.d * m2.c);
    outputmat.d= (m1.d * m2.d) + (m1.d * m2.d);
}
//SCALAR
void scalfunc(matrix &m1, matrix &outputmat, double &scal)
{
    outputmat.a= m1.a*scal;
    outputmat.b= m1.b*scal;
    outputmat.c= m1.c*scal;
    outputmat.d= m1.d*scal;
}
//INVERSE... questionable???
void inversefunc(matrix &m1, matrix &outputmat, double &scal)
{
    outputmat.a= m1.a/scal;
    outputmat.b= m1.b/scal;
    outputmat.c= m1.c/scal;
    outputmat.d= m1.d/scal;
}
void outputFunc(matrix &m1, matrix &m2, matrix &outputmat, double &scal)

{
//*M1 Matrix output

    cout<< m1.name<<":" <<endl;
    cout << left << setw(10) << "--"<<"--"<< endl;
    cout<<left<<setw(2)<<
        "|"<<setw(10)<<setprecision(1)<<fixed<<m1.a<<setw(2)<<setprecision(1)<< fixed<<m1.b<<"|"<<endl;
    cout<<left<<setw(10)<<"|"<<"|"<<endl;
    cout<<left<<setw(10)<<"|"<<"|"<<endl;
    cout<<left<<setw(5)<<"|"<<setw(10)<<setprecision(1)<<fixed<<m1.c<<setw(5)<<setprecision(1)<<fixed<<m1.d<<"|"<<endl;
    cout<<left<<setw(10)<<"|"<<"|"<<endl;
    cout<<left<<setw(10)<<"|"<<"|"<<endl;
    cout<<endl;

 //M2 Matrix output
    cout << m2.name<<":" <<endl;
    cout << left<<setw(10)<< "--"<<"--"<< endl;
    cout << left<<setw(2)<< "|"<<setw(10)<<setprecision(1)<<fixed<<m2.a<<setw(2)<<setprecision(1)<< fixed<<m2.b<<"|"<<endl;
    cout<<left<<setw(10)<<"|"<<"|"<<endl;
    cout<<left<<setw(10)<<"|"<<"|"<<endl;
    cout<<left<<setw(5)<<"|"<<setw(10)<<setprecision(1)<<fixed<<m2.c<<setw(5)<<setprecision(1)<<fixed<<m2.d<<"|"<<endl;
    cout<<left<<setw(10)<<"|"<<"|"<<endl;
    cout<<left<<setw(10)<<"|"<<"|"<<endl;
    cout<<endl;

 //Scalar
    cout<< "the scalar is--"<<scal<<endl;
    cout<<endl;

//Output of matrix
    cout<<outputmat.name<<endl;
    cout<<left<<setw(10)<<"--"<<"--"<<endl;
    cout<<left<<setw(5)<<"|"<<setw(10)<<setprecision(1)<<fixed<<outputmat.a<<setw(5)<<setprecision(1)<<fixed<<outputmat.b<<"|"<<endl;
    cout<<left<<setw(10)<<"|"<<"|"<<endl;
    cout<<left<<setw(10)<<"|"<<"|"<<endl;
    cout<<left<<setw(5)<<"|"<<setw(10)<<setprecision(1)<<fixed<<outputmat.c<<setw(5)<<setprecision(1)<<fixed<<outputmat.d<<"|"<<endl;
}
int main ()
{
    int operations;
    char done;
    matrix m1,m2,outputmat;
    outputmat.name= "matrix results";
    double scal;
    infunc(m1,m2,scal);
    do
    {
        cout << "select an operation of your choosing by inputting the number to the corresponding operation"<<endl<< "1~~ adding operation"<<endl<<"2~~ subtracting operation"<<endl<<"3~~ multiplying operation"<<endl<<"4~~ scalar operation"<<endl<<"5~~ inverse operation"<<endl<< "operating number >>>>>>>>----";
        cin>> operations;
        switch(operations)
        {

            case 1:
            {
                addmatrix(m1,m2,outputmat);
                outputFunc(m1,m2,outputmat,scal);
                break;
        }
            case 2:
            {
                diffmatrix(m1,m2,outputmat);
                outputFunc(m1,m2,outputmat, scal);
                break;
            }
            case 3:
            {
                multiplymatrix(m1,m2,outputmat);
                outputFunc(m1,m2,outputmat,scal);
                break;
            }
            case 4:
            {
                scalfunc(m1,outputmat,scal);
                outputFunc(m1,m2,outputmat,scal);
                break;
            }
            case 5:
            {
                inversefunc(m1,outputmat,scal);
                outputFunc(m1,m2,outputmat,scal);
                break;
            }

            }
        cout<<" do you want to do another operation?:"<<endl;
        cin>> done;
        cin.ignore();
        }
    while(done=='y');
    system("bye");
    return 0;
}
