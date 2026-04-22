#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    bool q = true;
    cin >> n;
    for (int i = n; i >= 0; i--)
    {
        int tem;
        cin >> tem;
        if (tem == 0)continue;
        if (!q)
        {
            if (tem > 0)cout << '+';
            else cout << '-';

        }
        else
        {
            q = false;
            if (tem < 0)cout << '-';
        }
        if (i > 0)
        {
            if (abs(tem) != 1)
            {
                cout << abs(tem);
            }
            if (i > 1)cout << "x^" << i;
            else cout << "x";

        }
        else
        {
            cout << abs(tem);
        }



    }
    return 0;
}
