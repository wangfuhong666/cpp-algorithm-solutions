//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    long long arr[35][35] = { 0 };
//
//    int n;
//    //cin >> n;
//    for (int i = 1; i <= 34; i++)
//    {
//        arr[i][1] = 1LL;
//        arr[i][i] = 1LL;
//    }
//    for (int i = 3; i <= 34; i++)
//    {
//        for (int j = 2; j < 34; j++)
//        {
//            if (i > j)
//            {
//                arr[i][j] = arr[i - 1][j] + arr[i-1][j - 1];
//            }
//        }
//    }
//    for (int i = 0; i < 35; i++)
//    {
//        for (int j = 0; j < 35; j++)
//        {
//            cout << arr[i][j] << ' ';
//        }
//        cout << endl;
//    }
//    return 0;
//}