#include <iostream>
#include <string>
#include <vector>
using namespace std;

int PermutationNum(int n )
{
	int mul = 1;
	while(n)
		{
			mul *= n;
			n--;
	}
	return mul;
}
int GetCount(int count, int*arr ,int n)
{
	int i;
	for(i = 1; i <= n; i++)
	{
		if(arr[i] == 1)continue;
		count--;
		if(count == 0)
		{
			arr[i] = 1;	
			break;
		}
	}
	return i;
}
class Solution 
{
public:
    string getPermutation(int n, int k)
	{
		string result;

		result.resize(n);
		int arr[10];
		for(int i = 0; i < 10; i++)
			arr[i] = 0;
		for(int i = 0; i < n; i++)
		{
			int mul = PermutationNum(n - 1 - i);
			int count = k / mul;

			result[i] = GetCount(count + 1, arr, n) + '0';
			k -= count * mul; 
		}
		return result;       
    }
};




int main()
{
/*	Solution s;
	cout << s.getPermutation(3, 5) <<endl;
	system("pause");
	return 1;*/
	vector<int> my;
	my.push_back(1);
	my.push_back(2);
	vector<int> a(my.rbegin(), my.rend());
	cout << a[0] <<" "<< a[1] <<endl;
	system("pause");
}