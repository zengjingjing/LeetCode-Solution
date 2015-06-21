/****************************************************************************************************
������AC����12.5%�����������ѣ���ʵ�ܼ򵥡�

Solution 1:
ֱ�ӱ�����٣�����ÿ�����㹹�ɵ�ֱ�ߣ����������㿴�Ƿ���ֱ���ϡ�Cn2 * n = O(N*N*N)

Solution 2: (false solution)
��ʱ����Ϊ���������÷��η���Ҳ����˵ѡ���м�ĵ㣬�����������ֱ��Ҫô����ߣ�Ҫô���ұߣ�Ҫô�;�������㡣
ò������˼·����ȷ�����Ӷ���F(n) = 2 * F(n/2) + O(n*n);  =>  F(n) = lgn * n * n;
��O(N*N*N)�ã������Ҿ���ô���ˣ������������˼·����©���ġ�Ҳ����˵�������������ֱ�߿�������ߣ��������ұߣ�
��������Ҫ�����ߺ��ұߣ�Ҳ��һ��Ҫ�����м������㣡�п������ܳ����������ǲ������м�����㡣

Solution 3:
�Ա�����ٵĸĽ���
��������������Ĺ��̣�ÿѡ�������㣬����ֱ�ߺ󣬶�Ҫ�������ĵ㣬��һ��k������ѡ������һ��ֱ�ߺ���Ҫ��һ�����е㵽��ǰ���k,����м���������ˡ�
��ʵ���ԶԵ�ǰ�㣬�����������е㵽����k��map,�ڱ�����ʱ���������ͬ��k,��ôcount��1�����û�У���ô�� = 1,������O(n)ʱ���ھͿ������������ǰ��������ֱ���ˡ�

�����Ҫ�ڱʼǱ�������һ�£�����˼�����㷨���Ż��о�����������һ��ϵ�С�
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
