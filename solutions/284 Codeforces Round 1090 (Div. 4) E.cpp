#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) 
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (auto &num:arr) cin >> num;
        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        n = arr.size();
        int ans = 0;
        for (auto x : arr) 
        {
            int cnt = 0;
            for (int i = 29; i >= 0; i--) 
            {
                int tem = !((x >> i) & 1);
                int tmp = cnt | (tem << i);
                auto it = lower_bound(arr.begin(), arr.end(), tmp);
                if (it != arr.end())if((*it >> i) == (tmp >> i)) cnt = tmp;
                else  cnt |= ((1 - tem) << i);
                
            }
            ans = max(ans, x ^ cnt);
        }
        cout << ans << '\n';
    }
    return 0;
}
