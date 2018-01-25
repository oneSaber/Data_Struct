#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;
int InputMaxtri(int maxtri[][100],int m)
{
    for(int i = 0;i<m;i++)
        for(int j = 0;j<m;j++)
            cin>>maxtri[i][j];
}
int main()
{
    //矩阵乘法
    int m;
    cout<<"input maxtri size,m:";
    cin>>m;
    int maxtri1[100][100];
    int maxtri2[100][100];
    
    cout<<"Enter maxtri 1: "<<endl;
    InputMaxtri(maxtri1,m);
    //maxtri1 :
    /* 
    1 2 3 4 5
    2 3 4 5 6
    3 4 5 6 7
    4 5 6 7 8
    5 6 7 8 9
    */
    cout<<"Enter maxtri 2: "<<endl;
    InputMaxtri(maxtri2,m);
    //maxtri2:
    // 9 8 7 6 5
    // 8 7 6 5 4
    // 7 6 5 4 3
    // 6 5 4 3 2
    // 5 4 3 2 1

    cout<<"output maxtri1:"<<endl;
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<m;j++)
            cout<<maxtri1[i][j]<<" ";
        cout<<endl;
    }
    cout<<"output maxtri2:"<<endl;
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<m;j++)
            cout<<maxtri2[i][j]<<" ";
        cout<<endl;
    }
    int maxtri3[100][100] = {0};
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<m;j++)
        {
            for(int k = 0;k<m;k++)
            {
                maxtri3[i][j] += maxtri1[i][k] * maxtri2[k][j];
            }
        }

    }
    cout<<"output maxtri3:"<<endl;
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<m;j++)
            cout<<maxtri3[i][j]<<" ";
        cout<<endl;
    }
    system("pause");
    return 0;
}