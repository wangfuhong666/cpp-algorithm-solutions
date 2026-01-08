//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//    int n;
//    cin >> n;
//    vector<int>arr(n, 0);
//    for (auto& num : arr)cin >> num;
//    int q;
//    cin >> q;
//    while (q--)
//    {
//        long long ret1, ret2;
//        int x, y;
//        cin >> x >> y;
//        auto it1 = lower_bound(arr.begin(), arr.end(), x);
//        if (it1 == arr.end())
//        {
//            cout << 0 << endl;
//            continue;
//        }
//        auto it2 = upper_bound(arr.begin(), arr.end(), y);
//        if (it2 == arr.begin() && *it2 > y)
//        {
//            cout << 0 << endl;
//            continue;
//        }
//        cout << it2 - it1 << endl;
//    }
//    return 0;
//}