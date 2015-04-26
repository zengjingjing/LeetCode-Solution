#include <iostream>
#include <vector>
#include <stack>
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
 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) 
	{
		vector<int> result;
		stack<TreeNode *> myStack1;
		stack<TreeNode *> myStack2;
		if(!root)return result;
		myStack1.push(root);
		while(!myStack1.empty())
		{
			TreeNode * temp = myStack1.top();
			myStack1.pop();
			myStack2.push(temp);
			if(temp->left)myStack1.push(temp->left);
			if(temp->right)myStack1.push(temp->right);
		}
		while(!myStack2.empty())
		{
			result.push_back(myStack2.top()->val);
			myStack2.pop();
		}
		return result;
		
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

