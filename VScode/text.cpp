#include <iostream>
#include<cstring>
#include<string>
#include<stdlib.h>
#include<typeinfo>
#include<vector>
#include<array>
using namespace std;

int main()
{
	// struct Node * Link = new Node;
	// Node * Position = new Node;
	// cout<< "struct Node Link = new Node " <<Link<<endl;
	// cout<< "type of(Link->next) "<<typeid(Link->next).name()<<endl;
	// cout<< "Node * Position = new Node " <<Position<<endl;
	// cout<< "type of (Position->next) "<<typeid(Position->next).name()<<endl; 
	
	// C original c++
	double a1[4] = {1.2,2.4,3.6,4.8};
	//c++ 98 stl
	vector<double> a2(4);
	//no sample way to initialize C98
	a2[0] = 1.0/2.0;
	a2[1] = 1.0/3.0;
	a2[2] = 1.0/5.0;
	a2[3] = 1.0/7.0;
	//c++11 create and initialize array object
	array<double,4> a3 = {3.14,2.72,1.92,1.41};
	array<double,4> a4;
	a4 = a3;
	
	for(int i = 0;i<4;i++)
		cout<<a2[i]<<endl;
	for(int i = 0;i<a3.Length;i++)
		cout<<a3[i]<<endl;
	system("pause");
    return 0;
}
