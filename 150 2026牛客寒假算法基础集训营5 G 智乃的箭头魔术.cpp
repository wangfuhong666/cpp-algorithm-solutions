#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s = "0112233445142015320125410214530214510214102302142025101203201451451522302514203214510021454101002532";
    int x = 0;
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (ch == '0')
        {
            if (x == 0)x = 3;
            else if (x == 1)x = 2;
            else if (x == 2)x = 1;
            else if (x == 3)x = 0;
        }
        if (ch == '1')
        {
            if (x == 0)x = 0;
            else if (x == 1)x = 3;
            else if (x == 2)x = 2;
            else if (x == 3)x = 1;
        }
        if (ch == '2')
        {
            if (x == 0)x = 1;
            else if (x == 1)x = 0;
            else if (x == 2)x = 3;
            else if (x == 3)x = 2;
        }
        if (ch == '3')
        {
            if (x == 0)x = 2;
            else if (x == 1)x = 1;
            else if (x == 2)x = 0;
            else if (x == 3)x = 3;
        }
        if (ch == '4')
        {
            if (x == 0)x = 1;
            else if (x == 1)x = 2;
            else if (x == 2)x = 3;
            else if (x == 3)x = 0;
        }
        if (ch == '5')
        {
            if (x == 0)x = 3;
            else if (x == 1)x = 0;
            else if (x == 2)x = 1;
            else if (x == 3)x = 2;
        }
        res += x + '0';
    }
    cout << res;
    return 0;
}
