#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Robot
{
	int h;
	int w;
	int s = 0;
public:
	Robot(int width, int height) :w(width), h(height) {}

	void step(int num)
	{
		s = (s + num - 1) % ((w + h - 2) * 2) + 1;
	}

	vector<int> getPos()
	{
		int x, y;
		if (s < w) 
		{
			x = s;
			y = 0;
		}
		else if (s < w + h - 1) 
		{
			x = w - 1;
			y = s - w + 1;
		}
		else if (s < 2 * w + h - 2)
		{
			x = 2 * w + h - s - 3;
			y = h - 1;
		}
		else 
		{
			x = 0;
			y = 2 * (w + h) - s - 4;
		}
		return { x, y };
	}
	string getDir() 
	{
		if (s < w)
		{
			return "East";
		}
		else if (s < w + h - 1)
		{
			return "North";
		}
		else if (s < 2 * w + h - 2)
		{
			return "West";
		}
		else 
		{
			return "South";
		}
	}
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	return 0;
}
