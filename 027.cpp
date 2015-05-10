#include <iostream>
using namespace std;


void ShiftArray(int A[], int start, int left, int right)
{
	left++;
	while(left <= right - 1)
	{
		A[start++] = A[left++];
	}
}
class Solution 
{
public:
	int removeElement(int A[], int n, int elem)
	{
		//if(n < 2)return n;
		int right = n - 1;
		int  left= 0;
		int i = 0;
		int count = 0;
		int start =  -1;
		while(i < n)
		{
			if(A[i++] != elem)continue;
			
			left = i - 1;
			if(start == -1)start = left;
			count++;
			while(i < n && A[i] != elem)i++;
			if(i == n)right = left;
			else right = i;			
			if(left != right && left != right - 1)
			{
				ShiftArray(A, start, left, right);
				start += (right - left - 1);
			}			
			//i++;
		}
		while(right + 1 < n)
		{
			A[start++] = A[right+1];
			right++;
		}
		return n - count;
	}
};



int main()
{
	Solution s;
	int arr[] = {0,3,1,1,0,1,3,0,3,3,1,1};
	int size = s.removeElement(arr, 12, 1);
	for(int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	system("pause");
	return 1;
}