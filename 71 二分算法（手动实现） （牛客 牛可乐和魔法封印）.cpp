//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
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
//        long long l = 0, r = n - 1, mid = 0LL;
//        while (l < r)
//        {
//            mid = (l + r) / 2;
//            if (arr[mid] >= x)r = mid;
//            else l = mid + 1;
//        }
//        if (arr[l] < x)
//        {
//            cout << 0 << endl;
//            continue;
//        }
//        ret1 = l;
//        l = 0; r = n - 1; mid = 0LL;
//        while (l < r)
//        {
//            mid = (l + r + 1) / 2;
//            if (arr[mid] > y)r = mid - 1;
//            else l = mid;
//        }
//        if (arr[l] > y)
//        {
//            cout << 0 << endl;
//            continue;
//        }
//        cout << l - ret1 + 1 << endl;
//
//    }
//    return 0;
//}