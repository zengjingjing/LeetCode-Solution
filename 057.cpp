#include <iostream>
#include  <vector>
using namespace std;

 typedef struct Interval 
 {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 }Interval;
 
Interval SubMerge(const Interval& v1, const Interval& v2)
{
	Interval ret_value;
	ret_value.start = v1.start < v2.start ? v1.start : v2.start;
	ret_value.end = v1.end > v2.end ? v1.end : v2.end;

	return ret_value;

}

class Solution
{
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) 
	{
         vector<Interval> result;
		int val = newInterval.start;
		int size = intervals.size();
		if(size < 1)
			{
				result.push_back(newInterval);
				return result;
		}
		int left = 0;
		int right =size - 1;
		while(left <= right)
		{
			int middle = (left + right) / 2;
			if(intervals[middle].start <= val)
				left = middle + 1;
			else right = middle - 1;
		}
		for(int i = 0; i <= right - 1; i++)
			result.push_back(intervals[i]);
		if(right >= 0 && newInterval.start > intervals[right].end)
		{
				result.push_back(intervals[right]);
				right++;
		}
		else if(right < 0)right++; // right 指向第一个可以merge的位置
		Interval v1 = newInterval; 
		while(right < size && newInterval.end >= intervals[right].start)
		{
			Interval v2 = SubMerge(v1, intervals[right]);
			v1.start = v2.start;
			v1.end = v2.end;
			right++;
		}
		result.push_back(v1);
		while(right < size)
			result.push_back(intervals[right++]);
		return result;			
    }
};


int main()
{
	vector<Interval> intervals;

	Interval v1(1,5);
//	Interval v2(3,5);
//	Interval v3(6,7);
	Interval v4(8,10);
	Interval v5(12,16);

//	Interval v1(1,2);
//	Interval v1(1,2);
	intervals.push_back(v1);
//	intervals.push_back(v2);
//	intervals.push_back(v3);
//	intervals.push_back(v4);
//	intervals.push_back(v5);
	Interval insert_one(0,1);
	Solution s;
	vector<Interval> result = s.insert(intervals, insert_one);
	for(int i = 0; i < result.size(); i++)
		cout << "[" << result[i].start << " " << result[i].end << "]" << endl;
	system("pause");
	return 1;

}