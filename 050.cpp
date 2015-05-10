#include <iostream>
using namespace std;
int arr[33];
double temp_result[33];
class Solution 
{
public:
    double pow(double x, int n) 
	{
        if(n == 0)return 1;
		if(x == 0)return 0;
		bool flag_n_neg = false;
		bool flag_x_neg = false;
		if(n < 0)flag_n_neg = true;
		if(x < 0)flag_x_neg = true;
		n = abs(n);
		x = fabs(x);
		long long  count = 1;
		int i = 0;
		arr[0] = 1;
		temp_result[0] = x;
		while(count * 2 <= n)
		{
			i++;			
			count *= 2;
			arr[i] = count;
			x *= x;
			temp_result[i] = x;
		}

		for(int j = i; j >= 0; j--)
		{
			if(count + arr[j] < n)
			{
				count += arr[j];
				x *= temp_result[j];
			}
			else if(count + arr[j] == n)
			{
				count += arr[j];
				x *= temp_result[j];
				break;
			}
			else continue;
		}
		if(flag_x_neg && n % 2 != 0) x = -x;
		if(flag_n_neg) return 1/x;
		return x;

    }
};

int main()
{
	Solution s;
	cout << s.pow(-1.00000, -2147483648) << endl;
//	cout << s.pow(2, 3) << endl;
//	cout << s.pow(2, 4) << endl;
//	cout << s.pow(2, 10) << endl;
	system("pause");
}