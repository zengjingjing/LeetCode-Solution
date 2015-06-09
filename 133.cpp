/****************************************************************************************************
Solution:
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;


struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
	{
		UndirectedGraphNode * root = NULL;
		if(!node)
			return root;
		map<UndirectedGraphNode*, UndirectedGraphNode* > visited;
		queue<UndirectedGraphNode*> queue1;
		queue<UndirectedGraphNode*> queue2;
		root = new UndirectedGraphNode(node->label);
		visited[node] = root;
		queue1.push(node);
		queue2.push(root);
		while(!queue1.empty())
		{
			UndirectedGraphNode* f1 = queue1.front();
			UndirectedGraphNode* f2 = queue2.front();
			for(int i = 0; i < f1->neighbors.size(); i++)
			{
				if(visited.find(f1->neighbors[i]) == visited.end())
				{
					UndirectedGraphNode * neighbor = new UndirectedGraphNode(f1->neighbors[i]->label);
					queue1.push(f1->neighbors[i]);
					queue2.push(neighbor);
					visited[f1->neighbors[i]] = neighbor;
					f2->neighbors.push_back(neighbor);					
				}
				else
					f2->neighbors.push_back(visited[f1->neighbors[i]]);
			}
			queue1.pop();
			queue2.pop();
		}
		return root;

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