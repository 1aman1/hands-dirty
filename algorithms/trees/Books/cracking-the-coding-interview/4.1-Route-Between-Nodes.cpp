#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <queue>

/*
1-> implement graph using array of list

2-> a function for routeBetweenNode traversal
*/

struct graph
{
	// graph utility
	std::list<int> *adjacencyList;
	int vertices;

	graph(int v) : vertices(v)
	{
		adjacencyList = new std::list<int>[vertices];

		visited = new bool[vertices];
		std::fill(visited, visited + vertices, false);
	}

	void print();
	void add_edge(int, int);

	// BFS utility for route between nodes
	bool *visited;
	bool routeBetweenNode(int, int);
};

void graph::print()
{
	for (int i = 0; i < vertices; ++i)
	{
		std::cout << "vertex :" << i << " : ";
		{
			std::list<int>::iterator it;
			for (it = adjacencyList[i].begin(); it != adjacencyList[i].end(); ++it)
			{
				std::cout << *it << ", ";
			}
			std::cout << std::endl;
		}
	}
}

void graph::add_edge(int u, int v)
{
	// undirected graph
	adjacencyList[u].push_back(v);

	// directed graph
	// adjacencyList[v].push_back(u);
}

bool graph::routeBetweenNode(int src, int target)
{
	if (src == target)
	{
		return true;
	}

	std::queue<int> Q;

	Q.emplace(src);
	while (!Q.empty())
	{
		int top = Q.front();
		Q.pop();

		visited[top] = true;

		for (auto it = adjacencyList[top].begin(); it != adjacencyList[top].end(); ++it)
		{
			if (*it == target)
			{
				return true;
			}
			if (visited[*it] != true)
			{
				visited[*it] = true;
				Q.push(*it);
			}
		}
	}
	return false;
}

int main()
{
	graph go(6);

	go.add_edge(0, 1);
	go.add_edge(0, 4);
	go.add_edge(0, 5);

	go.add_edge(1, 3);
	go.add_edge(1, 4);

	go.add_edge(2, 1);

	go.add_edge(3, 2);
	go.add_edge(3, 4);

	go.print();

	int src = 0;
	int target = 2;
	std::cout << src << " to " << target << " route exists ? "
			  << std::boolalpha
			  << go.routeBetweenNode(src, target)
			  << std::endl;

	return 0;
}