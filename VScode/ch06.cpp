#include<iostream>
using namespace std;
int main()
{
    char automobile[50];
    int year;
    double a_price;
    double b_price;
    ofstream outFile;
    outFile  = open("carinfo.txt");
    cout<<"enter the make and model of the automobil;"
    cin.getline(automobile,50);
    cout<<"enter the model year:";
    cin>>year;
    cout<<"enter the orgin asking price :";
    cin>>a_price;
    b_price = 0.913 * a_price;
    cout<<
}