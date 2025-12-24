//#define _CRT_SECURE_NO_WARNINGS
//#include<cstdlib>
//#include<iostream>
//#define MAXSIZE 100
//using namespace std;
//// 静态链表静态数组实现
//typedef struct MyStruct
//{
//	//数据源
//	int data[MAXSIZE];
//	//相当于指针源
//	int next[MAXSIZE];
//	//记录头节点下标
//	int h;
//	//记录新节点存储位置
//	int id;
//}node;
//
//// //链表初始化
//node* start()
//{
//	node* L = (node*)malloc(sizeof(node));
//	L->h = 0;
//	L->id = 0;
//	L->next[L->h] = 0;
//	return L;
//}
////判断链表是否为空
//bool isempty(node* L)
//{
//	return L->id == 0;
//}
//// //头插法插入元素
//bool head(node* L, int e)
//{
//	if (L->id >= MAXSIZE - 1) { return false; }
//	L->id++;
//	L->data[L->id] = e;
//	L->next[L->id] = L->next[L->h];
//	L->next[L->h] = L->id;
//
//	return true;
//}
//// //遍历链表
//void sc(node* L)
//{
//	int p = L->next[L->h];
//	while (p != 0)
//	{
//		cout << L->data[p] << ' ';
//		p = L->next[p];
//	}
//	cout << endl;
//}
//// //获取尾部下标
//int gettail(node* L)
//{
//	int p = L->next[L->h];
//	while (L->next[p] != 0) { p = L->next[p]; }
//	return p;
//}
//// //尾插法插入元素
//bool tail(node* L, int e)
//{
//	if (L->id >= MAXSIZE - 1) { return false; }
//	int q = gettail(L);
//	L->id++;
//	L->data[L->id] = e;
//	L->next[q] = L->id;
//	L->next[L->id] = 0;
//	return true;
//}
//////指定位置插入数据
//bool insert(node* L, int pos, int e)
//{
//	int p = L->next[L->h];
//	for (int i = 0; i < pos - 1; i++)
//	{
//		if (L->next[p] == 0) { return false; }
//		p = L->next[p];
//	}
//	int q = L->next[p];
//	if (L->id >= MAXSIZE - 1) { return false; }
//	L->id++;
//	L->data[L->id] = e;
//	L->next[L->id] = q;
//	L->next[p] = L->id;
//	return true;
//
//}
//////删除指定节点
//bool pop(node* L, int pos)
//{
//	int p = L->next[L->h];
//	for (int i = 0; i < pos - 1; i++)
//	{
//		if (L->next[p] == 0) { return false; }
//		p = L->next[p];
//	}
//	if (L->id >= MAXSIZE - 1) { return false; }
//	int q = L->next[p];
//	int m= L->next[q];
//	L->next[p] = m;
//}
/////查找元素在该链表中的位置（不包含头节点）
//
//////查找链表正数第几个的元素（不包含头节点）
//// 
////查找链表倒数第几个的元素（不包含头节点）
//// 
//////清空链表
//
//////获取链表长度(不包含头节点)
//
//
//int main()
//{
//	//初始化
//	node* list1 = start();
//	//头插法
//	for (int i = 0; i <= 5; i++)
//	{
//		head(list1, i *2);
//	}
//	//尾插法
//	for (int i = 0; i <= 5; i++)
//	{
//		tail(list1, i + 1);
//	}
//	//遍历
//	sc(list1);
//	//指定位置插入
//	insert(list1, 2, 99);
//	sc(list1);
//	//指定位置删除
//	pop(list1, 2);
//	sc(list1);
//	return 0;
//}