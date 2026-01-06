//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include <algorithm>
//#include<string>
//using namespace std;
//
//int main()
//{
//    int t;
//    cin >> t;
//    while (t--)
//    {
//        string s;
//        cin >> s;
//        long long sum = 0LL;
//        long long c2 = 0LL, c3 = 0LL;
//        for (auto num : s)
//        {
//            sum += num - '0';
//            if (num == '2')c2++;
//            if (num == '3')c3++;
//        }
//
//        int cnt = sum % 9;
//        if (cnt == 0)
//        {
//            cout << "YES" << endl;
//            continue;
//        }
//        bool judge = false;
//        for (int i = 0; i <= min(c2, 8LL); i++)
//        {
//            for (int j = 0; j <= min(c3, 2LL); j++)
//            {
//                if ((sum + i * 2 + j * 6) % 9 == 0)
//                {
//                    judge = true;
//                    break;
//                }
//            }
//        }
//        if (judge)cout << "YES" << endl;
//        else cout << "NO" << endl;
//    }
//}