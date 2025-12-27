//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//    int x1, x2, x3, x4, t2, t3, t4;
//    long long q;
//    vector<long long>arr;
//    cin >> x1 >> x2 >> x3 >> x4 >> t2 >> t3 >> t4 >> q;
//    vector<int>price{ x2,x3,x4 };
//    vector<int>time{ t2,t3,t4 };
//    for (int st = 0; st < (1 << 3); st++)
//    {
//        long long tem = q;
//        long long total = 0LL, sum = 0LL;
//        for (int i = 0; i < 3; i++)
//        {
//            if ((st >> i) & 1)
//            {
//                total += price[i];
//                sum += time[i];
//            }
//        }
//        tem -= sum;
//        if (tem > 0)total += x1 * tem;
//        arr.push_back(total);
//    }
//    sort(arr.begin(), arr.end());
//    cout << arr[0];
//    return 0;
//}
