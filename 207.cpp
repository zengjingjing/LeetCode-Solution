/****************************************************************************************************
Solution:
这道题我最开始用adj matrix来存储数组，直接MLE了，WAP那道题估计也是（怪不得我WAP跪）。以后：稀疏表或者有可能有大量节点的表，能用链表数组就用链表数组表示吧。

******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution 
{
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) 
	{
		if(numCourses == 0)return true;

		int size = prerequisites.size();
		if(size == 0)return true;
		// build graph (no adj matrix)
		set<int> *graphOut = new set<int>[numCourses];  // store out degree
		set<int> *graphIn = new set<int>[numCourses]; // store in degree
		bool *visited = new bool[numCourses];

		for(int i = 0; i < numCourses; i++)
		{
			visited[i] = false;
		}

		for(int i = 0; i < prerequisites.size(); i++)
		{
			int row = prerequisites[i].first;
			int col = prerequisites[i].second;
			graphOut[row].insert(col);	
			graphIn[col].insert(row);	
		}

		while(1)
		{
			int index = FindOutDegreeZero(graphOut, visited, numCourses);

			// if we can find a index , then erase all edge which in degree it to 0 , which means delete index and its edges.
			if(index != -1)
			{
				visited[index] = true; 
				EraseInDegree(index, graphIn, graphOut, visited, numCourses);

			}
			else
				break;
		}
		delete[] graphOut;
		delete[] graphIn;
		for(int i = 0; i < numCourses; i++)
		{
			if(visited[i] == false)
			{
				delete visited;
				return false;
			}
		}
		delete visited;
		return true;

	}

	// find index who's out degree = 0
	int FindOutDegreeZero(set<int>* grpahOut, bool* visited, int numCourses)
	{

		for(int i = 0; i < numCourses; i++)
		{
			if(visited[i] == false && grpahOut[i].size() == 0)
				return i;
		}
		return -1;
	}

	//delete all edges which has edge to index
	void EraseInDegree(int index, set<int>* graphIn, set<int>* graphOut, bool * visited, int numCourses)
	{
		for(set<int>::const_iterator it = graphIn[index].begin(); it !=  graphIn[index].end(); it++)
		{
			graphOut[*it].erase(index);
		}
	}
};


void test()
{
	Solution s;
	vector<pair<int, int>> prerequisites;
	prerequisites.push_back(make_pair(0, 1));
	prerequisites.push_back(make_pair(1, 0));
//	prerequisites.push_back(make_pair(2, 1));
//	prerequisites.push_back(make_pair(2, 3));
	if(s.canFinish(2, prerequisites))
		cout << "true" << endl;
	else
		cout << "false" << endl;
}
int main()
{
	test();
	system("pause");
	return 1;
}
