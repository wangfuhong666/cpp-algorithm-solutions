#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<vector>
#include <iomanip>
#include<algorithm>
#define MAX (long long)(1e6)
using namespace std;
≤Â»Î≈≈–Ú() 1  2 3  5 4
1.µ• ˝◊È∞Ê
 ß∞‹∞Ê
void sort_1_1_1(vector<int>&arr)
{
	
	for (int i = 0; i < arr.size()-1; i++)
	{
			int tem = arr[i + 1];
			int p2 = i; 
			int j;
			for (j = 0; j < arr.size(); j++)
			{
				if (tem <= arr[j]) { break; }
			}
			int p1 = j;
			for (int k = p2; k >= p1; k--)
			{
				arr[k + 1] = arr[k];
			}
			arr[p1] = tem;		
	}
}// 0 1 2 3 4 5 6 7 8
 1 1 2 3 4 5 6
j=0
void sort_1_1_2(vector<int>& arr) {
	for (int i = 1; i < arr.size(); i++) {
		int tem = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > tem) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = tem;
	}
}
2.À´ ˝◊È∞Ê
void sort_1_2(vector<int>& arr)
{
	vector<int>sort;
	sort.reserve(arr.size());
	for (auto it = arr.begin(); it != arr.end(); it++)
	{
		if (sort.size() == 0)
		{
			sort.push_back(*it);
		}
		else
		{
			//1 5 4 6 8 5 4
			//1 5
			if (sort[sort.size() - 1] > *it)
			{
				auto it1 = sort.begin();
				for (it1 = sort.begin(); it1 != sort.end(); it1++)
				{
					if (*it1 >= *it)
					{
						break;
					}
					
				}
				sort.insert(it1, *it);
			}
			else
			{
				sort.push_back(*it);
			}
		}
	}
	arr = sort;
}
—°‘Ò≈≈–Ú
void sort_2(vector<int>& arr)
{
	for (int i = 0; i < arr.size()-1; i++)
	{
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[i] > arr[j])
			{
				int tem = arr[i];
				arr[i] = arr[j];
				arr[j] = tem;
			}
		}
	}
}
√∞∫≈≈≈–Ú
void sort_3_1(vector<int>& arr)
{
	for (int i = 0; i < arr.size()-1; i++)
	{
		for (int j = 0; j < arr.size() - 1 - i; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				int tem = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tem;
			}
		}
	}
}
”≈ªØ∫Ûµƒ√∞∫≈≈≈–Ú
void sort_3_2(vector<int>& arr)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		bool ju = false;
		for (int j = 0; j < arr.size() - 1 - i; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				int tem = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tem;
				ju = true;
			}
		}
		if (!ju)break;
	}
}
∂—≈≈–Ú£®∂—’‚÷÷ ˝æ›Ω·ππ Ù”⁄∂˛≤Ê ˜£©

øÏÀŸ≈≈–Ú
int get_rand(vector<int>&arr,int left, int right) 
{

	return arr[rand() % (right - left + 1) + left];
}
void sort_4(vector<int>&arr,int left, int right)
{
	if (left >= right)return;
	int p = get_rand(arr,left, right);
	int l = left - 1, i = left, r = right + 1;
	while (i < r)
	{
		if (arr[i] < p) swap(arr[++l], arr[i++]);
		else if (arr[i] == p) i++;
		else swap(arr[--r], arr[i]);
	
	}
	sort_4(arr,left, l);
	sort_4(arr,r, right);
}
πÈ≤¢≈≈–Ú
void sort_5(vector<int>& arr, int left, int right)
{
	vector<int>tmp(right+1);
	if (left >= right)return;
	int mid = (left + right) / 2;
	sort_5(arr, left, mid);
	sort_5(arr, mid+1, right);
	int cur1 = left, cur2 = mid+1,i=left;
	while (cur1 <= mid && cur2 <= right)
	{
		if (arr[cur1] <=arr[cur2])
		{
			tmp[i] = arr[cur1];
			i++; cur1++;
		}
		else
		{
			tmp[i] = arr[cur2];
			i++; cur2++;
		}

	}
	while(cur1 <= mid)
	{
		tmp[i] = arr[cur1];
		i++; cur1++;
	}
	while(cur2 <= right)
	{
		tmp[i] = arr[cur2];
		i++; cur2++;
	}
	for (int j = left; j <= right; j++)
	{
		arr[j] = tmp[j];
	}
}
int main()
{
	
	vector<int>arr1{ 1,9,6,5,99999,8,23,65,15689,7,23,6,56985,98,54,82,61,75,1,2,95326,6,95,785,6548,95,6952,64656 };
	vector<int>arr2 = arr1;
	vector<int>arr3 = arr1;
	vector<int>arr4 = arr1;
	vector<int>arr5 = arr1;
	vector<int>arr6 = arr1;
	vector<int>arr7 = arr1;
	≤Â»Î≈≈–Ú1
	 ß∞‹∞Ê
	vector<int>arr10 = { 2,1,4,3,6,5 };
	sort_1_1_1(arr10);
	for (auto m : arr10)
	{
		cout << m << ' ';
	}
	cout << endl;
	sort_1_1_2(arr1);
	for (auto m : arr1)
	{
		cout << m << ' ';
	}
	≤Â»Î≈≈–Ú2
	cout << endl;
	sort_1_2(arr2);
	for (auto m : arr2)
	{
		cout << m << ' ';
	}
	cout << endl;
	—°‘Ò≈≈–Ú
	sort_2(arr3);
	for (auto m : arr3)
	{
		cout << m << ' ';
	}
	cout << endl;
	√∞∫≈≈≈–Ú	
	sort_3_1(arr4);
	
	for (auto m : arr4)
	{
		cout << m << ' ';
	}
	cout << endl;
	sort_3_2(arr5);
	for (auto m : arr5)
	{
		cout << m << ' ';
	}
	cout << endl;
	//≤‚ ‘¡Ω÷÷√∞∫≈≈≈–Úµƒ ±º‰œ˚∫ƒ
	srand(time(NULL));
	vector<int>arr11(1000);
	vector<int>H((int)5e6+10,0);
	for (int i = 0; i < arr11.size(); )
	{
		int tem=rand() % ((int)3e5 + 50) + 1;
		if(H[tem]==0)
		{
			arr11[i] = tem;
			H[tem] += 1;
			i++;
		}
	}
	vector<int>arr12 = arr11;
	auto B = clock();
	sort_3_1(arr11);
	auto S= clock();
	double time1 = (double)(S - B) / CLOCKS_PER_SEC * 1000;
	for (auto m : arr11)
	{
		cout << m << ' ';
	}
	cout << endl <<endl << endl << endl << endl << fixed << setprecision(3) << time1 << " ms" << endl;
	
	B = clock();
	sort_3_2(arr12);
	S = clock();
	time1 = (double)(S - B) / CLOCKS_PER_SEC * 1000;
	for (auto m : arr12)
	{
		cout << m << ' ';
	}
	cout << endl << endl << endl << endl << endl << fixed << setprecision(3) << time1 << " ms" << endl;
	//øÏÀŸ≈≈–Ú
	srand(time(nullptr));
	sort_4(arr6,0,arr6.size()-1);
	for (auto m : arr6)
	{
		cout << m << ' ';
	}
	cout << endl;
	//πÈ≤¢≈≈–Ú
	sort_5(arr7,0,arr7.size()-1);
	for (auto m : arr7)
	{
		cout << m << ' ';
	}
	cout << endl;

	return 0;
}