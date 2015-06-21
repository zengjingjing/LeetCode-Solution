/****************************************************************************************************
这道题的AC率是12.5%，看起来很难，其实很简单。

Solution 1:
直接暴力穷举，对于每两个点构成的直线，遍历其他点看是否在直线上。Cn2 * n = O(N*N*N)

Solution 2: (false solution)
当时我认为这道题可以用分治法。也就是说选定中间的点，这条最“长”的直线要么在左边，要么在右边，要么就经过这个点。
貌似这种思路很正确，复杂度是F(n) = 2 * F(n/2) + O(n*n);  =>  F(n) = lgn * n * n;
比O(N*N*N)好，于是我就这么做了，结果发现这种思路是有漏洞的。也就是说，这条最“长”的直线可能在左边，可能在右边，
但就算是要跨过左边和右边，也不一定要经过中间的这个点！有可能它很长，但它就是不经过中间这个点。

Solution 3:
对暴力穷举的改进：
暴力穷举是这样的过程：每选定两个点，构成直线后，都要对其他的点，算一遍k；当再选定另外一条直线后，又要算一遍所有点到当前点的k,这就有计算的冗余了。
其实可以对当前点，保存其他所有点到它的k到map,在遍历的时候，如果有相同的k,那么count加1，如果没有，那么就 = 1,这样在O(n)时间内就可以算出经过当前点的最“长”直线了。

这道题要在笔记本上整理一下，这种思想在算法的优化中经常遇到，是一个系列。
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

#define K_MAX 1000000
typedef struct Point 
{
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
 }Point;

typedef struct DIR
{
	int a;
	int b;
	DIR(int x, int y)
	{
		a = x;
		b = y;
	}
}DIR;

bool cmp(const Point&p1 ,const Point& p2)
{
	return p1.x < p2.x;
}

class Solution
{
public:
    int maxPoints(vector<Point>& points)
	{
        int size = points.size();
		if(size <= 2)
			return size;
		sort(points.begin(), points.end(), cmp);

		int ans = -1;
		map<double, int> myMap;
		for(int i = 0; i < size; i++)
		{
			myMap.clear();
			int count = 0;
			for(int j = 0; j < size; j++)
			{
				if(IsSame(points[j], points[i]))
					count++;
				else
				{
					double k;
					int x = points[j].x - points[i].x;
					int y = points[j].y - points[i].y;
					if(x == 0)
						k = K_MAX;
					else
						k = (double)y / x;
					if(myMap.find(k) != myMap.end())
						myMap[k]++;
					else
						myMap[k] = 1;
				}
			}
			int sub_ans = 0;
			for(map<double, int>::const_iterator it = myMap.begin(); it != myMap.end(); it++)
			{
				if(it->second > sub_ans)
					sub_ans = it->second;
			}
			sub_ans += count;
			if(sub_ans > ans)
				ans = sub_ans;
		}
		return ans;
		
    }

	bool IsSame(const Point& p1, const Point& p2)
	{
		if(sqrt(double(p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)) < 1e-6)
			return true;
		return false;
	}
};


void test()
{
	 Solution s;
	 vector<Point> points;
	 Point p2(-1, -1);
	 Point p3(-1, -1);
	 Point p4(-1, -1);
	 Point p5(-1, -1);
	 points.push_back(p2);
	 points.push_back(p3);
	 points.push_back(p4);
	  points.push_back(p5);
	 cout << s.maxPoints(points) << endl;
	 
}

int main()
{
	test();
	system("pause");
	return 1;
}
