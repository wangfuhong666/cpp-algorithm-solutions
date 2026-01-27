//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include<cstdio>
//using namespace std;
//long long year_num(int year)
//{
//	if (year == 2007)return 0LL;
//	long long sum = 0LL;
//	for (int i = 2007; i < year; i++)
//	{
//		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)sum += 366LL;
//		else sum += 365LL;
//	}
//	return sum;
//}
//int mon_day(int year, int month)
//{
//	if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month == 2)return 29;
//	int day;
//	switch (month)
//	{
//	case 1:
//	case 3:
//	case 5:
//	case 7:
//	case 8:
//	case 10:
//	case 12:
//		day = 31;
//		break;
//	case 4:
//	case 6:
//	case 9:
//	case 11:
//		day = 30;
//		break;
//	case 2:
//		day = 28;
//		break;
//	}
//
//	return day;
//}
//int main()
//{
//	// 请在此输入您的代码
//	int year, month;
//	cin >> year >> month;
//	long long numday = year_num(year);
//	for (int i = 1; i < month; i++)
//	{
//		numday += mon_day(year, i);
//	}
//	int num = (1 + numday) % 7;
//	printf("Calendar %d-%02d\n", year, month);
//	printf("---------------------\n Su Mo Tu We Th Fr Sa\n---------------------\n");
//	for (int i = 0; i < num; i++)
//	{
//		printf("   ");
//	}
//	int io = num;
//	for (int i = 1; i <= mon_day(year, month); i++)
//	{
//		printf("%3d", i);
//		num++;
//		if (num % 7 == 0)
//		{
//			printf("\n");
//			num = 0;
//		}
//	}
//	if (num != 0)printf("\n");
//	printf("---------------------");
//	return 0;
//}