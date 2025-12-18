//#include <iostream>
//#include <cstring>
//#include <cmath>
//using namespace std;
//
//// 修正：适配题目n≤10^5的范围，设为100001
//#define MAXN 100001
//bool prime[MAXN];
//
//void start() {
//    // memset按字节赋值，1等价于bool的true
//    memset(prime, 1, sizeof prime);
//    prime[0] = prime[1] = false;
//
//    int sqrt_max = sqrt(MAXN);
//    for (int i = 2; i <= sqrt_max; ++i) {
//        if (prime[i]) {
//            for (int j = i * i; j < MAXN; j += i) {
//                prime[j] = false;
//            }
//        }
//    }
//}
//
//int main() {
//    start();
//    int T;
//    cin >> T;
//    for (int i = 0; i < T; ++i) {
//        int m;
//        cin >> m;
//        // 增加边界判断：若m超过MAXN-1，直接输出No
//        if (m >= MAXN) {
//            cout << "No" << endl;
//        }
//        else {
//            cout << (prime[m] ? "Yes" : "No") << endl;
//        }
//    }
//    return 0;
//}






