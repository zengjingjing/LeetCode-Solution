#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

 typedef struct Interval 
 {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 }Interval;
 
bool cmp(const Interval& v1, const Interval& v2)
{
	if(v1.start < v2.start)
		return true;
	return false;
}
 
Interval SubMerge(const Interval& v1, const Interval& v2)
{
	Interval ret_value;
	ret_value.start = v1.start;

	if(v2.end > v1.end)
		ret_value.end = v2.end;
	else
		ret_value.end = v1.end;
	return ret_value;

}

class Solution
{
public:
    vector<Interval> merge(vector<Interval> &intervals)
	{
         vector<Interval> result;
		int size = intervals.size();
		if(size <= 1)return  intervals;
		sort(intervals.begin(), intervals.end(), cmp);
		Interval v1 = intervals[0];
		for(int i = 1; i < size; i++)
		{
			Interval v2 =  intervals[i];
			if(v2.start <= v1.end)
			{
				Interval v3 = SubMerge(v1, v2);
				v1.start = v3.start;
				v1.end = v3.end;
			}
			else
			{
				result.push_back(v1);
				v1.start = v2.start;
				v1.end = v2.end;
			}
		}
		result.push_back(v1);
		return result;

    }
};



int main()
{
	vector<Interval> intervals;
	Interval v1(1,3);
//	Interval v2(3,6);
//	Interval v3(6,6);
//	Interval v4(6,6);
	intervals.push_back(v1);
//	intervals.push_back(v2);
//	intervals.push_back(v3);
//	intervals.push_back(v4);

//	Interval v1(1,3);
//	Interval v1(1,3);
	Solution s;
	vector<Interval> result = s.merge(intervals);
	for(int i = 0; i < result.size(); i++)
		cout << "[ "<< result[i].start <<" "<< result[i].end << " ]" << endl;
	system("pause");
	return 1;
	
}


