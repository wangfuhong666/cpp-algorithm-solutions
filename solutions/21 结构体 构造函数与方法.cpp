#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
struct stu
{
	string name;
	int chinese;
	int math;
	int total;
	double avg;
	//构造函数(创建变量时自动调用)
	stu()
	{
		name = "zhangsan";
		chinese = 60;
		math = 60;
		total = chinese + math;
		avg = total / 2.0;

	}
	~stu()
	{

	}
	//输出结构体成员
	void print()
	{
		cout << "名字: " << name<<endl;
		cout << "语文成绩: " << chinese << endl;;
		cout << "数学成绩: " << math << endl;;
		cout << "总成绩: " << total << endl;;
		cout << "平均成绩: " << avg << endl;;

	}
	void total1()
	{
		total = chinese + math;
	}
	void avg1()
	{
		avg = total / 2.0;
	}
};
int main()
{
	stu stu1;
	stu1.print();
	return 0;
}