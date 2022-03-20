#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool intersection(vector<int>a,vector<int>b) 
{
	for (auto iter1 = a.begin(); iter1 != a.end(); ++iter1) 
	{
		for (auto iter2 = b.begin(); iter2 != b.end(); ++iter2) 
		{
			if (*iter1 == *iter2)return true;
		}
	}
	return false;
}

void ReorganizeMatrixElements(const vector<vector<float>> &graph,vector<int> &index)
{
	int m = graph.size();
	vector<int> queueLists;
	vector<bool> visited(m,false);
	vector<int> currentIndex;
	vector<vector<int>> index_temp;
	int current;
	set<int> temp;
	int flag = 0;
	for (auto i = 0; i < m; ++i) 
	{
		queueLists.push_back(i);
		currentIndex.push_back(i);
		visited = vector<bool>(m,false);
		while (!queueLists.empty()) 
		{
			current = queueLists.back();
			visited[current] = true;
			queueLists.pop_back();
			for (auto j = 0; j < m; ++j) 
			{
				if (!visited[j] && graph[current][j]) 
				{
					queueLists.push_back(j);
					currentIndex.push_back(j);
					visited[j] = true;
				}
			}
		}
		flag = 0;
		if (!index_temp.empty()) 
		{
			for (auto k = 0; k < index_temp.size(); ++k) 
			{
				if (intersection(index_temp[k],currentIndex)) 
				{
					temp = set<int>(currentIndex.begin(),currentIndex.end());
					for (auto iter = index_temp[k].begin(); iter != index_temp[k].end(); ++iter)temp.insert(*iter);
					index_temp[k].clear();
					index_temp[k] = vector<int>(temp.begin(),temp.end());
					flag = 1;
				}
			}
		}
		if (!flag || index_temp.empty())
		{
			index_temp.push_back(currentIndex);
			flag = 0;
		}
		currentIndex.clear();
	}
	for (auto i = 0; i < index_temp.size(); ++i) 
	{
		for (auto j = 0; j < index_temp[i].size(); ++j) 
		{
			index.push_back(index_temp[i][j]);
		}
	}
}

int main()
{
	vector<vector<float>> temp = { {0,1,0,0,0,0},{0,0,0,0,0,1},{0,0,0,1,0,0},{0,1,0,0,0,1},{0,0,0,0,1,0},{0,0,1,0,0,1} };
	vector<int> index;
	ReorganizeMatrixElements(temp,index);
	return 0;
}
