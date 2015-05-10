#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define N 10000
TreeNode *arr[N]; 

typedef  struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

class Solution
{
public:
	vector<vector<int> > zigzagLevelOrder(TreeNode *root)
	{
		vector<vector<int>> result;
		if(!root) return result;
		int  left = 0;
		int	 right = 0;
		arr[left] = root;
		bool turn = true; // ==  true: left to right;       == false:  right to left
		while(left <= right)
		{
			vector<int> sub_result;
			int nextRight = right;
			if(turn)
			{
				for(int i = left; i <= right; i++)
				{
					TreeNode* top = arr[i];
					sub_result.push_back(top->val);
				}
				turn = false;
			}
			else
			{
				for(int i = right; i >= left; i--)
				{
					TreeNode* top = arr[i];
					sub_result.push_back(top->val);
				}

				turn = true;
			}
			for(int i = left; i <= right; i++)
			{
				TreeNode* top = arr[i];
				if(top->left)
				{
					arr[++nextRight] = top->left;
				}
				if(top->right)
				{
					arr[++nextRight] = top->right;
				}
			}

			left = right + 1;
			right = nextRight;
			result.push_back(sub_result);
		}
		return result;
	}
};

void BuildTree(vector<int>& list, TreeNode * root)
{
	if(list.size() == 0)return ;

}

void test()
{

}
int main()
{
	test();
	system("pause");
	return 1;
}


