//#define _CRT_SECURE_NO_WARNINGS
//#include <cstdio>
//#include<iostream>
//#include <cstring>
//#include<vector>
//using namespace std;
//int main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    int T = 0;
//    cin >> T;
//    for (int i = 0; i < T; i++)
//    {
//        int n = 0, m = 0, k = 0;
//        cin >> n >> m >> k;
//        if (k == 0)
//        {
//            vector<vector<int>>arr(n, vector<int>(m));
//            cout << "Yes\n";
//            int num = n * m;
//            for (int x = 0; x < n; x++)for (int y = 0; y < m; y++)arr[x][y] = num--;                                                                                
//            for (int x = 0; x <- n; x++)
//            {
//                for (int y = 0; y < m; y++)
//                {
//                  
//                    cout << arr[x][y] << ' ';
//
//                }
//                cout << "\n";
//            }
//        }
//        else if (n < 3 || m < 3 || (k > ((n - 1) / 2) * ((m - 1) / 2)))
//            cout << "No\n";
//        else
//        {
//            cout << "Yes\n";
//            vector<vector<int>>arr(n, vector<int>(m));
//            int num = m * n;
//            int point = 0;
//            for (int x = 1; x < n - 1; x += 2)
//            {
//                bool flag = false;
//                for (int y = 1; y < m - 1; y += 2)
//                {
//                    arr[x][y] = num--;
//                    point++;
//                    if (point == k)
//                    {
//                        flag = true;
//                        break;
//                    }
//                }
//                if (flag)
//                    break;
//            }
//            for (int x = 0; x < n; x++)for (int y = 0; y < m; y++)if (arr[x][y] == 0)arr[x][y] = num--;          
//            for (int x = 0; x < n; x++)
//            {
//                for (int y = 0; y < m; y++)
//                {
//                   
//                    cout << arr[x][y] << ' ';
//
//                }
//                cout << "\n";
//            }
//        }
//    }
//    return 0;
//}