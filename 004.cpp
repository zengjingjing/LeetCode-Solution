/****************************************************************************************************
Solution:
Method 1: 类似于merge.
Method 2: Kth value, 分治。
******************************************************************************************************/


#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

class Solution 
{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
	{
		int size1 = nums1.size();
		int size2 = nums2.size();
		if((size1 + size2) % 2 == 1)
			return (double)FindMedian(nums1, nums2, 0, size1 - 1, 0, size2 - 1, (size1 + size2 + 1) / 2);
		else
		{
			return ((double)FindMedian(nums1, nums2, 0, size1 - 1, 0, size2 - 1, (size1 + size2 + 1) / 2) + FindMedian(nums1, nums2, 0, size1 - 1, 0, size2 - 1, (size1 + size2 + 1) / 2 + 1)) / 2;
		}
	
	}

	double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2)
	{
		int size1 = nums1.size();
		int size2 = nums2.size();
		if((size1 + size2) % 2 == 1)
			return (double)FindMedian2(nums1, nums2, (size1 + size2 + 1) / 2);
		else
		{
			return ((double)FindMedian2(nums1, nums2, (size1 + size2 + 1) / 2) + FindMedian2(nums1, nums2, (size1 + size2 + 1) / 2 + 1)) / 2;
		}

	}

	int FindMedian(vector<int>& nums1, vector<int>& nums2, int start1, int end1, int start2, int end2, int k)
	{
		if(end1 - start1 > end2 - start2)
			return FindMedian(nums2, nums1, start2, end2, start1, end1, k);
		if(end1 - start1 < 0)
			return nums2[start2 + k - 1];
		if(k == 1)
		{
			return GetMin(nums1[start1], nums2[start2]);
		}

		int pos1 = GetMin(end1 - start1 + 1, k/2);
		int pos2 = k - pos1;
		if(nums1[start1 + pos1 - 1] == nums2[start2 + pos2 - 1])
		{
			return nums1[start1 + pos1 - 1];
		}
		else if(nums1[start1 + pos1 - 1] < nums2[start2 + pos2 - 1])
		{
			start1 = start1 + pos1;
			return FindMedian(nums1, nums2, start1, end1, start2, end2, k - pos1);
			
		}
		else
		{
			start2 = start2 + pos2;
			return FindMedian(nums1, nums2, start1, end1, start2, end2, k - pos2);
		}
	}

	int FindMedian2(vector<int>& nums1, vector<int>& nums2, int k)
	{
		int size1 = nums1.size();
		int size2 = nums2.size();
		int i = 0,j = 0;
		int count = 0;
		int index = 0;
		while(i < size1 && j < size2)
		{
			if(nums1[i] <= nums2[j])
			{	
				count++;
				if(count == k)
					return nums1[i];
				i++;
			}
			else
			{
				count++;
				if(count == k)
					return nums2[j];
				j++;
			}
		}
		if(i < size1)
			return nums1[i + k - count - 1];
		if(j < size2)
			return nums2[j + k - count - 1];
	}

	int GetMin(const int& a, const int& b)
	{
		return a < b ? a : b;
	}
};

void PrintVec(vector<int>& nums)
{
	for(int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
}

void test()
{
	Solution s;
	vector<int> nums1;
	vector<int> nums2;
	vector<int> nums3;
	srand((unsigned int)time(NULL));
	for(int i = 0; i < 10; i++)
	{
		int val1 = rand() % 100;
		int val2 = rand() % 100;
		//nums1.push_back(val1);
		nums2.push_back(val2);
		//nums3.push_back(val1);
		nums3.push_back(val2);
	}
	int val = rand() % 100;
	nums2.push_back(val);
	nums3.push_back(val);
	std::sort(nums1.begin(), nums1.end());
	std::sort(nums2.begin(), nums2.end());
	std::sort(nums3.begin(), nums3.end());
	//PrintVec(nums1);
	//PrintVec(nums2);
	PrintVec(nums3);
	//cout << " method 1 : " << s.findMedianSortedArrays1(nums1, nums2)<< endl;
	//cout << " method 2 : " << s.findMedianSortedArrays2(nums1, nums2)<< endl;
}
int main()
{
	test();
	system("pause");
	return 1;
}