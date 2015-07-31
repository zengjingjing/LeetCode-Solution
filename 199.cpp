#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;


 typedef struct TreeNode
 {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;
 
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root) 
	{
        vector<int> ans;
		if(!root)return ans;
		queue<TreeNode*> myQueue;
		myQueue.push(root);
		int count = 1;
		while(!myQueue.empty())
		{
			int nextCount = 0;
			for(int i = 0; i < count; i++)
			{
				TreeNode* top = myQueue.front();
				myQueue.pop();
				if(top->left)
				{
					myQueue.push(top->left);
					nextCount++;
				}
				if(top->right)
				{
					myQueue.push(top->right);
					nextCount++;
				}
				if(i == count - 1)
					ans.push_back(top->val);
				
			}
			count = nextCount;
		}
		return ans;
    }
};


void test()
{

}

int main()
{
	test();	
	system("pause");
	return 1;
}


while(1)
fopen(1.txt)'



