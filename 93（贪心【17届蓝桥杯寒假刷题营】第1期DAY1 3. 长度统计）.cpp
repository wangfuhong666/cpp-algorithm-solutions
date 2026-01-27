//#include <bits/stdc++.h>
//using namespace std;
//int main()
//{
//    // 请在此输入您的代码
//    int n;
//    cin >> n;
//    vector<pair<int, int>>arr(n);
//    for (auto& num : arr)cin >> num.first >> num.second;
//    sort(arr.begin(), arr.end());
//    long long len = 0LL;
//    int l = arr[0].first, r = arr[0].second;
//    for (int i = 1; i < n; i++)
//    {
//        int l1 = arr[i].first;
//        int r1 = arr[i].second;
//        if (l1 <= r)
//        {
//            r = max(r, r1);
//        }
//        else
//        {
//            len += r - l;
//            l = l1;
//            r = r1;
//        }
//    }
//    cout << len + r - l;
//    return 0;
//}
