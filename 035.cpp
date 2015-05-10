#include <iostream>
using namespace std;

class Solution
{
public:
    int searchInsert(int A[], int n, int target)
	{
        int left = 0;
		int right = n - 1;
		int middle ;
		while(left < right)
		{
			middle = (left + right ) / 2;
			if(A[middle] == target)return middle;
			else if(A[middle] < target)
				left = middle + 1;
			else
				right = middle - 1;

		}
		if(A[left] == target)return left;
		else if(A[left] > target) return left ;
		else return left + 1;
    }
};


int main()
{
	Solution s;
	int arr[] = {1,3,5,6};
	cout << s.searchInsert(arr, 4, 5) << endl;
	cout << s.searchInsert(arr, 4, 2) << endl;
	cout << s.searchInsert(arr, 4 ,7) << endl;
	cout << s.searchInsert(arr ,4 ,0) << endl;
	system("pause");

}