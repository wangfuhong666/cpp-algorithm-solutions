//////#define _CRT_SECURE_NO_WARNINGS
//////#include<iostream>
//////#include<cstdio>
//////#include<cstring>
//////#include<cstdlib>
//////#include<ctime>
//////#include<cmath>
//////#include<vector>
//////#include <iomanip>
//////#include<algorithm>
//////using namespace std;
//////int main()
//////{
//////	int p1, p2, p3;
//////	cin >> p1 >> p2 >> p3;
//////	string s;
//////	cin >> s;
//////	bool judge1 = false;
//////	bool judge2 = false;
//////	int size = s.size();
//////	vector<int>pos_x;
//////	vector<int>pos_y;
//////	for (int i = 1; i < s.size()-1; i++)
//////	{
//////		if (s[i] == '-')
//////		{
//////			pos_x.push_back(i - 1);
//////			pos_y.push_back(i + 1);
//////			if (s[i - 1] >= '0' && s[i - 1] <= '9'&& s[i + 1] >= '0' && s[i + 1] <= '9' && s[i - 1] < s[i + 1])
//////			{
//////				judge1 = true;
//////				judge2 = true;
//////			}
//////			else if (s[i - 1] >= 'a' && s[i - 1] <= 'z'&&s[i + 1] >= 'a' && s[i + 1] <= 'z' && s[i - 1] < s[i + 1])
//////			{
//////				judge1 = true;
//////				
//////			}
//////
//////		}
//////		if (judge1)
//////		{
//////			if (p1 == 3)
//////			{
//////				s.erase(i);
//////				pos_y[pos_y.size() - 1] -= 1;
//////				int num = s[i + 1] - s[i - 1] - 1;
//////				s.insert(i, num * p2, '*');
//////				pos_y[pos_y.size() - 1] += num * p2;
//////			}
//////			else
//////			{
//////				if (judge2)
//////				{
//////					string s1;
//////					for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
//////					{
//////						for (int k = 0; k < p2; k++)
//////						{
//////							s1 += char(j);
//////						}
//////					}
//////					s.erase(i);
//////					pos_y[pos_y.size() - 1] -= 1;
//////					int num = s[i + 1] - s[i - 1] - 1;
//////					s.insert(i, s1);
//////					pos_y[pos_y.size() - 1] += num * p2;
//////
//////				}
//////				else
//////				{
//////					if (p1 == 1)
//////					{
//////						string s1;
//////						for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
//////						{
//////							for (int k = 0; k < p2; k++)
//////							{
//////								s1 += char(j);
//////							}
//////						}
//////						s.erase(i);
//////						pos_y[pos_y.size() - 1] -= 1;
//////						int num = s[i + 1] - s[i - 1] - 1;
//////						s.insert(i, s1);
//////						pos_y[pos_y.size() - 1] += num * p2;
//////					}
//////					else if (p1 == 2)
//////					{
//////						string s1;
//////						for (int j = s[i - 1] - 32 + 1; j < s[i + 1] - 32; j++)
//////						{
//////							for (int k = 0; k < p2; k++)
//////							{
//////								s1 += char(j);
//////							}
//////						}
//////						s.erase(i);
//////						pos_y[pos_y.size() - 1] -= 1;
//////						int num = s[i + 1] - s[i - 1] - 1;
//////						s.insert(i, s1);
//////						pos_y[pos_y.size() - 1] += num * p2;
//////					}
//////				}
//////			}
//////
//////		}	
//////		judge1 = false;
//////		judge2 = false;
//////	}
//////	bool judge1 = false;
//////	bool judge2 = false;
//////	 移除无用的size变量，直接使用s.size()
//////	vector<int>pos_x;
//////	vector<int>pos_y;
//////
//////	 修改1：将for循环改为while循环，手动控制i的移动，避免索引错乱
//////    int i = 1;
//////    while (i < s.size() - 1)
//////    {
//////         校验i的合法性，避免无效索引
//////        if (i < 1 || i >= s.size() - 1) break;
//////
//////        if (s[i] == '-')
//////        {
//////            pos_x.push_back(i - 1);
//////            pos_y.push_back(i + 1);
//////             校验i-1和i+1的合法性
//////            if (i - 1 < 0 || i + 1 >= s.size()) { judge1 = false; }
//////            else if (s[i - 1] >= '0' && s[i - 1] <= '9' && s[i + 1] >= '0' && s[i + 1] <= '9' && s[i - 1] < s[i + 1])
//////            {
//////                judge1 = true;
//////                judge2 = true;
//////            }
//////            else if (s[i - 1] >= 'a' && s[i - 1] <= 'z' && s[i + 1] >= 'a' && s[i + 1] <= 'z' && s[i - 1] < s[i + 1])
//////            {
//////                judge1 = true;
//////            }
//////            else { judge1 = false; }
//////
//////        }
//////        if (judge1)
//////        {
//////             校验i-1和i+1的合法性
//////            if (i - 1 < 0 || i + 1 >= s.size()) break;
//////
//////            int num = s[i + 1] - s[i - 1] - 1;
//////            char right_char = s[i + 1];
//////            int insert_len = num * p2;
//////            int erase_pos = i;
//////            int insert_pos = i;
//////
//////            if (p1 == 3)
//////            {
//////                 1. erase前更新pos_x/pos_y：后续索引-1
//////                for (int k = 0; k < pos_x.size(); k++) {
//////                    if (pos_x[k] > erase_pos) pos_x[k]--;
//////                    if (pos_y[k] > erase_pos) pos_y[k]--;
//////                }
//////                s.erase(erase_pos, 1);
//////
//////                pos_y[pos_y.size() - 1] -= 1; // 原有代码
//////
//////                 2. insert前更新pos_x/pos_y：后续索引+insert_len
//////                for (int k = 0; k < pos_x.size(); k++) {
//////                    if (pos_x[k] >= insert_pos) pos_x[k] += insert_len;
//////                    if (pos_y[k] >= insert_pos) pos_y[k] += insert_len;
//////                }
//////                s.insert(insert_pos, insert_len, '*');
//////
//////                pos_y[pos_y.size() - 1] += insert_len; // 原有代码
//////            }
//////            else
//////            {
//////                string s1;
//////                if (judge2)
//////                {
//////                    for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
//////                    {
//////                        for (int k = 0; k < p2; k++)
//////                        {
//////                            s1 += char(j);
//////                        }
//////                    }
//////                }
//////                else
//////                {
//////                    if (p1 == 1)
//////                    {
//////                        for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
//////                        {
//////                            for (int k = 0; k < p2; k++)
//////                            {
//////                                s1 += char(j);
//////                            }
//////                        }
//////                    }
//////                    else if (p1 == 2)
//////                    {
//////                        for (int j = s[i - 1] - 32 + 1; j < s[i + 1] - 32; j++)
//////                        {
//////                            for (int k = 0; k < p2; k++)
//////                            {
//////                                s1 += char(j);
//////                            }
//////                        }
//////                    }
//////                }
//////
//////                 1. erase前更新pos_x/pos_y：后续索引-1
//////                for (int k = 0; k < pos_x.size(); k++) {
//////                    if (pos_x[k] > erase_pos) pos_x[k]--;
//////                    if (pos_y[k] > erase_pos) pos_y[k]--;
//////                }
//////                s.erase(erase_pos, 1);
//////
//////                pos_y[pos_y.size() - 1] -= 1; // 原有代码
//////
//////                 2. insert前更新pos_x/pos_y：后续索引+insert_len
//////                for (int k = 0; k < pos_x.size(); k++) {
//////                    if (pos_x[k] >= insert_pos) pos_x[k] += insert_len;
//////                    if (pos_y[k] >= insert_pos) pos_y[k] += insert_len;
//////                }
//////                s.insert(insert_pos, s1);
//////
//////                pos_y[pos_y.size() - 1] += insert_len; // 原有代码
//////            }
//////
//////             回插右字符的位置
//////            int right_insert_pos = insert_pos + insert_len;
//////             3. 回插右字符前更新pos_x/pos_y：后续索引+1
//////            for (int k = 0; k < pos_x.size(); k++) {
//////                if (pos_x[k] >= right_insert_pos) pos_x[k]++;
//////                if (pos_y[k] >= right_insert_pos) pos_y[k]++;
//////            }
//////             安全回插右字符
//////            if (right_insert_pos <= s.size()) {
//////                s.insert(right_insert_pos, 1, right_char);
//////            }
//////
//////             动态调整i，跳至右字符之后
//////            i = right_insert_pos + 1;
//////        }
//////         重置标志位
//////        judge1 = false;
//////        judge2 = false;
//////         非处理状态下i正常递增
//////        if (!judge1) { i++; }
//////   }
//////
//////
//////   if (p3 == 1)cout << s;
//////   else
//////   {
//////       for (int i = 0; i < pos_x.size(); i++)
//////       {
//////            仅新增这4行校验：过滤非法索引，避免越界
//////           if (pos_x[i] < 0 || pos_x[i] >= s.size()
//////               || pos_y[i] < 0 || pos_y[i] >= s.size())
//////           {
//////               continue; // 跳过无效索引，不执行swap
//////           }
//////           swap(s[pos_x[i]], s[pos_y[i]]); // 保留你的swap操作
//////       }
//////        保留你的手动倒序输出，无需修改
//////       for (int i = s.size() - 1; i >= 0; i++)
//////       {
//////           cout << s[i];
//////       }
//////   }
//////	return 0;
//////}
////
//
//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<ctime>
//#include<cmath>
//#include<vector>
//#include <iomanip>
//#include<algorithm>
//using namespace std;
//int main()
//{
//    int p1, p2, p3;
//    cin >> p1 >> p2 >> p3;
//    string s;
//    cin >> s;
//
//    bool judge1 = false;
//    bool judge2 = false;
//    vector<int>pos_x;
//    vector<int>pos_y;
//
//    int i = 1;
//    while (i < s.size() - 1)
//    {
//        if (i < 1 || i >= s.size() - 1) break;
//
//        if (s[i] == '-')
//        {
//            pos_x.push_back(i - 1);
//            pos_y.push_back(i + 1);
//            if (i - 1 < 0 || i + 1 >= s.size()) { judge1 = false; }
//            else if (s[i - 1] >= '0' && s[i - 1] <= '9' && s[i + 1] >= '0' && s[i + 1] <= '9' && s[i - 1] < s[i + 1])
//            {
//                judge1 = true;
//                judge2 = true;
//            }
//            else if (s[i - 1] >= 'a' && s[i - 1] <= 'z' && s[i + 1] >= 'a' && s[i + 1] <= 'z' && s[i - 1] < s[i + 1])
//            {
//                judge1 = true;
//            }
//            else { judge1 = false; }
//
//        }
//        if (judge1)
//        {
//            if (i - 1 < 0 || i + 1 >= s.size()) break;
//
//            int num = s[i + 1] - s[i - 1] - 1;
//            char right_char = s[i + 1];
//            int insert_len = num * p2;
//            int erase_pos = i;
//            int insert_pos = i;
//
//            if (p1 == 3)
//            {
//                for (int k = 0; k < pos_x.size(); k++) {
//                    if (pos_x[k] > erase_pos) pos_x[k]--;
//                    if (pos_y[k] > erase_pos) pos_y[k]--;
//                }
//                s.erase(erase_pos, 1);
//
//                pos_y[pos_y.size() - 1] -= 1;
//
//                for (int k = 0; k < pos_x.size(); k++) {
//                    if (pos_x[k] >= insert_pos) pos_x[k] += insert_len;
//                    if (pos_y[k] >= insert_pos) pos_y[k] += insert_len;
//                }
//                s.insert(insert_pos, insert_len, '*');
//
//                pos_y[pos_y.size() - 1] += insert_len;
//            }
//            else
//            {
//                string s1;
//                if (judge2)
//                {
//                    for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
//                    {
//                        for (int k = 0; k < p2; k++)
//                        {
//                            s1 += char(j);
//                        }
//                    }
//                }
//                else
//                {
//                    if (p1 == 1)
//                    {
//                        for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
//                        {
//                            for (int k = 0; k < p2; k++)
//                            {
//                                s1 += char(j);
//                            }
//                        }
//                    }
//                    else if (p1 == 2)
//                    {
//                        for (int j = s[i - 1] - 32 + 1; j < s[i + 1] - 32; j++)
//                        {
//                            for (int k = 0; k < p2; k++)
//                            {
//                                s1 += char(j);
//                            }
//                        }
//                    }
//                }
//
//                for (int k = 0; k < pos_x.size(); k++) {
//                    if (pos_x[k] > erase_pos) pos_x[k]--;
//                    if (pos_y[k] > erase_pos) pos_y[k]--;
//                }
//                s.erase(erase_pos, 1);
//
//                pos_y[pos_y.size() - 1] -= 1;
//
//                for (int k = 0; k < pos_x.size(); k++) {
//                    if (pos_x[k] >= insert_pos) pos_x[k] += insert_len;
//                    if (pos_y[k] >= insert_pos) pos_y[k] += insert_len;
//                }
//                s.insert(insert_pos, s1);
//
//                pos_y[pos_y.size() - 1] += insert_len;
//            }
//
//            i = insert_pos + insert_len + 1;
//        }
//        judge1 = false;
//        judge2 = false;
//        if (!judge1) { i++; }
//    }
//
//    if (p3 == 1)cout << s;
//    else
//    {
//        for (int i = 0; i < pos_x.size(); i++)
//        {
//            if (pos_x[i] < 0 || pos_x[i] >= s.size()
//                || pos_y[i] < 0 || pos_y[i] >= s.size())
//            {
//                continue;
//            }
//            swap(s[pos_x[i]], s[pos_y[i]]);
//        }
//        for (int i = s.size() - 1; i >= 0; i--)
//        {
//            cout << s[i];
//        }
//    }
//    return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS
//// 1. C语言标准输入输出头文件（scanf/printf依赖）
//#include <cstdio>
//// 2. C++标准命名空间头文件（using namespace std; 依赖，可省略，但保持原代码风格）
//#include <cstddef>
//// 3. C语言字符处理相关头文件（可选，本代码未直接使用，但万能头包含）
//#include <cctype>
//// 4. C++标准基础头文件（可选，本代码为C++风格封装，保持兼容性）
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <cmath>
//#include <cstdlib>
//#include <cstring>
//using namespace std;
//int p1, p2, p3, i = 0, k;
//char ch[300], be, af, f, j, p;//p用于输出; 
//int main() {
//	scanf("%d%d%d%s", &p1, &p2, &p3, ch);//输入;
//	while (ch[i]) {//当ch[i]有值时;
//		be = ch[i - 1]; af = ch[i + 1]; f = ch[i];//f存储ch[i],便于判断; 
//		if (f == '-' && af > be && (be >= '0' && af <= '9' || be >= 'a' && af <= 'z')) {//意思是ch[i]若为'-',就判断其前后是否满足条件，满足进入循环; 
//			for (p3 == 1 ? j = be + 1 : j = af - 1; p3 == 1 ? j<af : j>be; p3 == 1 ? j++ : j--) {
//				p = j;//j是整形变量，p是字符型变量，这样是将p赋值为ASCII码为j的字符; 
//				if (p1 == 2)//是否大写; 
//					p = (p >= 'a') ? p - 32 : p;//如果是字母就转成大写 
//				else if (p1 == 3) p = '*';//是否输出'*' 
//				for (k = 0; k < p2; k++)//输出p2个 
//					printf("%c", p);
//			}
//		}
//		else
//			printf("%c", f);//如果ch[i]是非'-'或者其前后不满足条件，就原样输出;
//		i++;//一定要放在后面，不然会出错QAQ;
//	}
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<ctime>
//#include<cmath>
//#include<vector>
//#include <iomanip>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	int p1, p2, p3;
//	cin >> p1 >> p2 >> p3;
//	string s;
//	cin >> s;
//	bool judge1 = false;
//	bool judge2 = false;
//	int size = s.size();
//
//	for (int i = 1; i < s.size()-1; i++)
//	{
//		if (s[i] == '-')
//		{
//
//			if (s[i - 1] >= '0' && s[i - 1] <= '9' && s[i + 1] >= '0' && s[i + 1] <= '9' && s[i - 1] < s[i + 1])
//			{
//				judge1 = true;
//				judge2 = true;
//			}
//			else if (s[i - 1] >= 'a' && s[i - 1] <= 'z' && s[i + 1] >= 'a' && s[i + 1] <= 'z' && s[i - 1] < s[i + 1])
//			{
//				judge1 = true;
//
//			}
//
//		}
//		if (judge1)
//		{
//			if (p1 == 3)
//			{
//				s.erase(i);
//		
//				int num = s[i + 1] - s[i - 1] - 1;
//				s.insert(i, num * p2, '*');
//			}
//			else
//			{
//				if (judge2)
//				{
//					string s1;
//					for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
//					{
//						for (int k = 0; k < p2; k++)
//						{
//							s1 += char(j);
//						}
//					}
//					if (p3 == 2) { std::reverse(s1.begin(), s1.end()); }
//					
//					s.erase(i);
//					
//					int num = s[i + 1] - s[i - 1] - 1;
//					s.insert(i, s1);
//
//				}
//				else
//				{
//					if (p1 == 1)
//					{
//						string s1;
//						for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
//						{
//							for (int k = 0; k < p2; k++)
//							{
//								s1 += char(j);
//							}
//						}
//						if (p3 == 2) { std::reverse(s1.begin(), s1.end()); }
//						s.erase(i);
//						int num = s[i + 1] - s[i - 1] - 1;
//						s.insert(i, s1);
//					}
//					else if (p1 == 2)
//					{
//						string s1;
//						for (int j = s[i - 1] - 32 + 1; j < s[i + 1] - 32; j++)
//						{
//							for (int k = 0; k < p2; k++)
//							{
//								s1 += char(j);
//							}
//						}
//						if (p3 == 2) { std::reverse(s1.begin(), s1.end()); }
//						s.erase(i);
//						int num = s[i + 1] - s[i - 1] - 1;
//						s.insert(i, s1);
//					}
//				}
//			}
//
//		}
//		judge1 = false;
//		judge2 = false;
//	}
//	cout << s;
//	return 0;
//}
//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<cstdlib>
//#include<ctime>
//#include<cmath>
//#include<vector>
//#include <iomanip>
//#include<algorithm>
//using namespace std;
//
//int main()
//{
//    int p1, p2, p3;
//    cin >> p1 >> p2 >> p3;
//    string s;
//    cin >> s;
//    bool judge1 = false;
//    bool judge2 = false;
//
//    int i = 1;
//    while (i < s.size() - 1)
//    {
//        if (s[i] == '-')
//        {
//            if (isdigit(s[i - 1]) && isdigit(s[i + 1]) && s[i - 1] < s[i + 1])
//            {
//                judge1 = true;
//                judge2 = true;
//            }
//            else if (islower(s[i - 1]) && islower(s[i + 1]) && s[i - 1] < s[i + 1])
//            {
//                judge1 = true;
//            }
//            else
//            {
//                judge1 = false;
//                judge2 = false;
//            }
//        }
//        else
//        {
//            judge1 = false;
//            judge2 = false;
//        }
//
//        if (judge1)
//        {
//            string s1;
//            if (p1 == 3)
//            {
//                int num = s[i + 1] - s[i - 1] - 1;
//                s1 = string(num * p2, '*');
//                s.erase(i, 1);
//                s.insert(i, s1);
//            }
//            else
//            {
//                if (judge2)
//                {
//                    for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
//                    {
//                        s1.append(p2, char(j));
//                    }
//                }
//                else
//                {
//                    if (p1 == 1)
//                    {
//                        for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
//                        {
//                            s1.append(p2, char(j));
//                        }
//                    }
//                    else if (p1 == 2)
//                    {
//                        for (int j = s[i - 1] + 1; j < s[i + 1]; j++)
//                        {
//                            s1.append(p2, toupper(char(j)));
//                        }
//                    }
//                }
//                if (p3 == 2) reverse(s1.begin(), s1.end());
//                s.erase(i, 1);
//                s.insert(i, s1);
//            }
//            i += s1.size();
//        }
//        else
//        {
//            i++;
//        }
//
//        judge1 = false;
//        judge2 = false;
//    }
//
//    cout << s;
//    return 0;
//}

