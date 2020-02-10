#include "graphSearch.h"
#include <stdlib.h>

bool isCyclic(int u, bool visited[], int parent, int n, const int graph[][n])
{
	visited[u] = true;
	for (int v = 0; v < n; v++)
	{
		if (graph[u][v])
		{
			if (!visited[v])
			{
				if (isCyclic(v, visited, u, n, graph))
					return true;
			}
			else if (v != parent)
				return true;
		}
	}
	return false;
}

bool isTree(int n, const int graph[][n])
{
	bool visited[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;
	if (isCyclic(0, visited, -1, n, graph))
		return false;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
			return false;
	}
	return true;
}

int dfs(int v, int n, const int safeSeq[][n], int *visit)
{
	visit[v] = 1;
	int hCnt = 1;
	for (int i = 0; i < n; i++)
	{
		if (safeSeq[v][i] && (!visit[i]))
			hCnt += dfs(i, n, safeSeq, visit);
	}
	return hCnt;
}

int dfswithK(int v, int k, int n, const int safeSeq[][n], int *visit)
{
	visit[v] = 1;
	int hCnt = 1;
	for (int i = 0; i < n; i++)
	{
		if (safeSeq[v][i] && (!visit[i]) && abs(v - i) <= k)
			hCnt += dfs(i, n, safeSeq, visit);
	}
	return hCnt;
}

int bfs(int n, const int safeSeq[][n], int *visit)
{

}

Result pepesAnswers(int n, const int safeSeq[][n])
{
	Result t;
	t.numDeliveryFrogs = 0;
	t.maxHouses = 0;
	int max;
	int visited[n];
	for (int i = 0; i < n; i++)
		visited[i] = 0;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			max = dfs(i, n, safeSeq, visited);
			t.maxHouses = (t.maxHouses > max) ? t.maxHouses : max;
			t.numDeliveryFrogs++;
		}
	}
	return t;
}

Result pepesAnswersWithK(int n, const int safeSeq[][n], int k)
{
	Result t;
	t.numDeliveryFrogs = 0;
	t.maxHouses = 0;
	int max;
	int visited[n];
	for (int i = 0; i < n; i++)
		visited[i] = 0;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			max = dfswithK(i, k, n, safeSeq, visited);
			t.maxHouses = (t.maxHouses > max) ? t.maxHouses : max;
			t.numDeliveryFrogs++;
		}
	}
	return t;
}