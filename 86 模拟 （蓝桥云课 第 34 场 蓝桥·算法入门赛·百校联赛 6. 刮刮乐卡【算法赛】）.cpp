//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<string>
//using namespace std;
//
//bool test(string& s, string& ss) {
//    ss = "";
//    bool judge = false;
//    int n = s.size();
//    for (int i = 0; i < n; ) {
//        if (i + 1 < n && s[i] == 'L' && s[i + 1] == 'Q') {
//            if (i + 2 < n && s[i + 2] == 'Q') {
//                judge = true;
//                i += 2;
//                continue;
//            }
//        }
//        ss += s[i];
//        i++;
//    }
//    return judge;
//}
//
//int main() {
//    string s, ss;
//    cin >> s;
//    long long count = 0;
//    while (test(s, ss)) {
//        count++;
//        s = ss;
//    }
//    cout << s << endl;
//    return 0;
//}