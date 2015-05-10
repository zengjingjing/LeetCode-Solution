#include <iostream>
using namespace std;


void ShiftArray(int A[], int left, int index, int right)
{
	for(int i = index; i <= right; i++)
	{
		A[left] = A[i];
		left++;
	}
}
class Solution 
{
public:
	int removeDuplicates(int A[], int n)
	{
		if(n < 2)return n;
		int right = n - 1;
		int  left= 0;
		int i = 0;
		int start = -1;
		int count = 0;
		for( i = 0; i < n; i++)
		{
			if(A[i+1] == A[i])
			{
				start = i;
				break;
			}
			else continue;
		}
		while(i < n - 1)
		{
			if(A[i] < A[i + 1])continue;
			while((i +1) < n && A[i] == A[i + 1])
			{
				i++;
				count++;
			}
			//count--;
			left = i;
			while((i + 1) < n && A[i] < A[ i + 1])i++;
			if( (i +1) == n)
				right = i;
			else 
				right = i - 1;
			ShiftArray(A, start, left, right);
			//count += (right - left + 1);
			start += (right - left + 1);
		}
		return n - count;
	}
};


int main()
{
	Solution s;
	int arr[] = {1,1};
	int count = s.removeDuplicates(arr, 2);
	for(int i = 0; i < count; i++)
	{
		cout << arr[i] << " ";
	}
	system("pause");
	return 1;

}