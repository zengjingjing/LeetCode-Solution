#include <iostream>
#include <string>
#include <vector>

using namespace std;

int finalMiddle;

double FindFinal(vector<int>& nums1, vector<int>& nums2, int start1, int end1, int start2, int end2, bool direction)
{
	if(direction == true)
	{
		int eleNum2 = end2 - start2;
		return nums1[start1 + (finalMiddle - eleNum2)];
	}
	else
	{
		int eleNum1 = end1 - start1;
		return nums2[start2 + (finalMiddle - eleNum1)];
	}
}


double FindMedian(vector<int>& nums1, vector<int>& nums2, int start1, int end1, int start2, int end2)
{
	int middle1 = (start1 + end1) / 2;
	int middle2 = (start2 + end2) / 2;
	int eleNum1 = end1 - start1 + 1;
	int eleNum2 = end2 - start2 + 1;
	
	if(nums1[middle1] < nums2[middle2])
	{
		if(eleNum1 + eleNum2 / 2 > finalMiddle)
			return FindMedian(nums1, nums2, start1, end1, start2, middle2);
		else if(eleNum1 + eleNum2 / 2 == finalMiddle)
		{
			//return nums1[end1] > nums2[middle2] ? nums1[end1] : nums2[middle2];
			return nums2[middle2];
		}
		else
		{
			return FindFinal(nums1, nums2, start1, end1, start2, end2, false); // 1 < 2

		}
	}
	else
	{
		if(eleNum1 / 2  + eleNum2 > finalMiddle)
			return FindMedian(nums1, nums2, start1, middle1, start2, end2);
		else if(eleNum1 / 2 + eleNum2 == finalMiddle)
		{
			//return nums1[end1] > nums2[middle2] ? nums1[end1] : nums2[middle2];
			return nums1[middle1];
		}
		else
		{
			return FindFinal(nums1, nums2, start1, end1, start2, end2, true); // 1 > 2

		}
	}
}



class Solution 
{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		int size1 = nums1.size();
		int size2 = nums2.size();
		finalMiddle = (size1 + size2) / 2 ;
		return  FindMedian(nums1, nums2, 0, nums1.size() -1 , 0, nums2.size() - 1);		
	}
};

void test()
{
	Solution s;
	vector<int> nums1;
	vector<int> nums2;
	nums1.resize(3);
	nums2.resize(5);
	nums1[0] = 1;
	nums1[1] = 4;
	nums1[2] = 7;

	nums2[0] = 2;
	nums2[1] = 3;
	nums2[2] = 5;
//	nums2[3] = 9;
//	nums2[4] = 10;
	cout << s.findMedianSortedArrays(nums1, nums2)<< endl;

}
int main()
{
	test();
	system("pause");
	return 1;
}