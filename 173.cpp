#include <iostream>
#include <string>
#include <vector>

using namespace std;




typedef struct TreeNode 
{
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

class BSTIterator {
private:
	TreeNode * curr;
	TreeNode * father;
public:
    BSTIterator(TreeNode *root) {
        
    }

    /** @return whether we have a next smallest number */
    bool hasNext() 
	{
        
    }

    /** @return the next smallest number */
    int next()
	{
        
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

void test()
{

}
int main()
{
test();
	system("pause");
	return 1;
}
