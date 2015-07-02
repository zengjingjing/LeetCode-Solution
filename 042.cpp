/****************************************************************************************************
Solution:
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
	int trap(vector<int>& height)
	{
		//return trap1(height);
		//return trap2(height);
		return trap3(height);
	}

	int trap1(vector<int>& height)
	{
		int size = height.size();
		int ans = 0;
		if(size == 0)
			return ans;
		for(int i = 0; i < size; i++)
		{
			int leftMax = height[i];
			int rightMax = height[i];
			for(int j = i - 1; j >= 0; j--)
			{
				if(height[j] > leftMax)
					leftMax = height[j];
			}

			for(int j = i + 1; j < size; j++)
			{
				if(height[j] > rightMax)
					rightMax = height[j];
			}

			int val = leftMax < rightMax ? leftMax : rightMax;
			ans += val - height[i];
		}
		return ans;
	}

	int trap2(vector<int>& height)
	{
		int size = height.size();
		int ans = 0;
		if(size == 0)
			return ans;
		int* arr = new int[size];
		int leftMax = 0;
		for(int i = 0; i < size; i++)
		{
			arr[i] = leftMax;
			if(height[i] > leftMax)
				leftMax = height[i];

		}

		int rightMax = 0;
		for(int i = size - 1; i >= 0; i--)
		{
			int val = arr[i] < rightMax ? arr[i] : rightMax;
			if(val - height[i] > 0)
				ans += val - height[i];
			if(height[i] > rightMax)
				rightMax = height[i];
		}
		delete[] arr;
		return ans;
	}


	int trap3(vector<int>& height)
	{
		int size = height.size();
		int ans = 0;
		if(size == 0)
			return ans;
		int left = 0;
		int right = size - 1;
		while(left < right)
		{
			bool turn = false;
			if(height[left] <= height[right])
				turn = true;

			if(turn)
			{
				int val = height[left];
				left++;
				while(left < right && height[left] < val)
				{
					ans += (val - height[left] );
					left++;
				}
			}
			else
			{
				int val = height[right];
				right--;
				while(left < right && height[right] < val)
				{
					ans += (val - height[right]);
					right--;
				}
			}
		}
		return ans;

	}

};

void test()
{
	Solution s;
	vector<int> heights;
	heights.push_back(0);
	heights.push_back(1);
	heights.push_back(0);
	heights.push_back(2);
	heights.push_back(1);
	heights.push_back(0);
	heights.push_back(1);
	heights.push_back(3);
	heights.push_back(2);
	heights.push_back(1);
	heights.push_back(2);
	heights.push_back(1);
	cout << s.trap(heights) << endl;
}

int main()
{
	test();
	system("pause");
	return 1;
}

