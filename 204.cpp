/****************************************************************************************************
Solution:
Naive����O��N*N����TLE�ġ�

��������ɸ��(Sieve of Eeatosthese).
���һ������prime,��ô���ı�������=1��������prime��Ҳ����˵��ÿ����һ��prime������������ɨ�裬���䱶�����޳���ȥ��
������������ʱ�䣬�ռ临�Ӷ�O��N��
����ѧ���ˡ�
�ܶ��Ȿ�ʶ�����ѧ���⣬���ֹ��ɣ��ҵ��ⷨ��������ѧ˼ά��

******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
	int countPrimes(int n)
	{
		int ans = 0;
		if(n < 2)
			return ans;
		bool *flag = new bool[n];
		for(int i = 0; i < n; i++)
			flag[i] = true;
		for(int i = 2; i < n; i++)
		{
			if(flag[i])
			{
				int temp = i * 2;
				while(temp < n)
				{
					flag[temp] = false;
					temp += i;
				}
			}
		}
		for(int i = 2; i < n; i++)
		{
			if(flag[i] == true)
				ans++;
		}
		return ans;
	}

};

void test()
{
	Solution s;
	cout << s.countPrimes(499979) << endl;
}

int main()
{
	test();
	system("pause");
	return 1;
}
