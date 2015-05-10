#include <iostream>
#include <vector>
using namespace std;
typedef struct POINT
{
	int x;
	int y;
}POINT;

void PrintMatirx(vector<vector<int>>& matrix)
{
	int size = matrix.size();
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		cout <<matrix[i][j]<<" ";
			cout<<endl;
	}
}

class Solution 
{
public:
    void rotate(vector<vector<int> > &matrix)
	{
		  
		
		int size = matrix.size();
		if(size == 1 )return ;
			for(int i = 0; i < size/2; i++)
		   {
			   int startx = i;
			   int starty = i;
			   int time = size - i * 2 - 1;
			   int temp ;
			   POINT p1,p2,p3,p4;
			   for(int j = 0; j < time; j++)
			   {
				   p1.x = startx;
				   p1.y = starty + j;

				   p2.x = starty + j;
				   p2.y = size - startx - 1;

				   p3.x = size - startx - 1;
				   p3.y = size - (starty + j) - 1;

				   p4.x = size - (starty + j) - 1;
				   p4.y = startx;
				   temp = matrix[p1.x][p1.y];
				   matrix[p1.x][p1.y] = matrix[p4.x][p4.y];
				   matrix[p4.x][p4.y] = matrix[p3.x][p3.y];
				   matrix[p3.x][p3.y] = matrix[p2.x][p2.y];
				   matrix[p2.x][p2.y] = temp;
				   
			   }
		   }
    }
};
int main()
{
	Solution s;
	vector<vector<int>> matrix;
	int size =2;
	for(int i = 0; i < size; i++)
	{
		vector<int> temp;
		for(int j = 0; j < size; j++)
		{
			temp.push_back(i * size + j);
		}
		matrix.push_back(temp);
	}
	PrintMatirx(matrix);
	s.rotate(matrix);
	cout << "********************" <<endl;
	PrintMatirx(matrix);
	system("pause");
	return 1;
}

