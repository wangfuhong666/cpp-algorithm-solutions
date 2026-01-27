#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long sum = 0LL;
        int num = 1;
        long long sum1 = 0LL, sum2 = 0LL;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++)
        {
            int tem;
            cin >> tem;
            sum += tem;
            if (num == 1)sum1 += tem, cnt1++;
            if (num == -1)sum2 += tem, cnt2++;
            num *= -1;
        }
        if (sum % n != 0)cout << "NO" << endl;
        else
        {
            long long tem = sum / n;
            if (sum1 == cnt1 * tem && sum2 == cnt2 * tem)cout << "YES" << endl;
            else cout << "NO" << endl;

        }

    }
    return 0;
}
