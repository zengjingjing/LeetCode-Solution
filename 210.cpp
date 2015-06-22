/****************************************************************************************************
Solution:
ͬ207:course schedule.
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution 
{
public:
	
	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) 
	{
		vector<int> ans ; 
		if(numCourses == 0)return ans;

		int size = prerequisites.size();
		if(size == 0)
		{
			for(int i = 0; i < numCourses; i++)
				ans.push_back(i);
			return ans;
		}

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
				ans.push_back(index);
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
				vector<int> temp;
				return temp;
			}
		}
		delete visited;
		return ans;
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
//	prerequisites.push_back(make_pair(0, 1));
//	prerequisites.push_back(make_pair(1, 2));
//	prerequisites.push_back(make_pair(2, 3));
//	prerequisites.push_back(make_pair(2, 3));
	vector<int> ans = s.findOrder(2, prerequisites);
	for(int i = 0; i< ans.size(); i++)
		cout << ans[i] << endl;
}
int main()
{
	test();
	system("pause");
	return 1;
}
