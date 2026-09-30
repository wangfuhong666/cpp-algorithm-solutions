#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string>
#include<cmath>
#include<cstdio>
using namespace std;
//string::iterator
typedef union
{
    int i;
    double d;
}aaa;
int main()
{
    string s1 = "123Xacv85629ZZ44";
    string s2 = "02598ZH88X265";
    string s3 = "0x5892Zsjf6892X45";
    string s4 = "89.561Xac9.25";
    string a[3] = { s1,s2,s3 };
    aaa arr[5];
    arr[0].i = 584;
    arr[1].i = 0123;
    arr[2].i = 0x589;
    arr[3].d  = 3.15;
    arr[4].d = 0.589;
    bool judge[5] = { true,true,true ,false,false };
    string sc;
    for (int j = 0; j < 5; j++)
    {
        if (judge[j])
        {
            sc += to_string(arr[j].i);
            sc += ' ';
        }
        else
        {
            sc += to_string(arr[j].d);
            sc += ' ';
        
        }
        
    }
    cout << sc;

    //for (int i = 0; i < 3; i++)
    //{
    //    string s0 = a[i];
    //    size_t pos;
    //    int res = stoi(s0, &pos, 0);
    //    //double res = stod(s4, &pos);
    //    //cout << res << ' ' << "pos= " << pos << endl;
    //}
    
   
    return 0;
}





