#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <stack>

/*
1-> implement Graph using array of list

2-> Depth first search
*/

//-DFS-/

struct Graph
{
public:
	typedef std::list<int> listOfInts;

protected:
	listOfInts *graph_;
	int _vertices;

public:
	void
	print();

	void
	add_edge(int, int);

	Graph(int v) : _vertices(v)
	{
		graph_ = new listOfInts[_vertices];
	}

	~Graph()
	{
		delete[] graph_;
	}
};

void Graph::print()
{
	for (int node = 0; node < _vertices; ++node)
	{
		std::cout << "vertex : " << node << " : ";
		{
			std::cout << "[ ";

			// traverse neighbour for the current vertex
			for (auto node_neighbrs = graph_[node].begin(); node_neighbrs != graph_[node].end(); ++node_neighbrs)
			{
				std::cout << *node_neighbrs << ", ";
			}

			std::cout << " ]" << std::endl;
		}
	}
}

void Graph::add_edge(int u, int v)
{
	// undirected Graph
	graph_[u].push_back(v);

	// directed Graph
	// graph_[v].push_back(u);
}

//-DFS-/

struct Solution : public Graph
{
protected:
	// needed for a cyclic graph
	std::vector<bool> visited;

public:
	Solution(int V) : Graph(V)
	{
		visited.resize(V);
		std::fill(visited.begin(), visited.end(), false);
	}

	void
	depth_first_search_recursive(int);

	void
	depth_first_search_iterative(int);
};

void Solution::depth_first_search_recursive(int src = 0)
{
	if (!visited[src])
	{
		visited[src] = true;
		std::cout << "visited : " << src << "\n";

		for (auto itr = graph_[src].begin(); itr != graph_[src].end(); ++itr)
		{
			depth_first_search_recursive(*itr);
		}
	}
}

void Solution::depth_first_search_iterative(int src = 0)
{
	std::cout << "Iterative DFS sequence : \n";
	std::fill(visited.begin(), visited.end(), false);

	std::stack<int> stack;

	stack.push(src);
	while (!stack.empty())
	{
		int curr_node = stack.top();
		stack.pop();

		visited[curr_node] = true;
		std::cout << "visited : " << curr_node << "\n";

		for (auto itr = graph_[curr_node].begin(); itr != graph_[curr_node].end(); ++itr)
		{
			if (!visited[*itr])
				stack.push(*itr);
		}
	}

	std::fill(visited.begin(), visited.end(), false);
}

int main()
{
	Solution go(6);

	go.add_edge(0, 2);
	go.add_edge(0, 1);
	go.add_edge(1, 3);
	go.add_edge(2, 4);
	go.add_edge(3, 5);

	// go.add_edge(0, 1);
	// go.add_edge(0, 4);
	// go.add_edge(0, 5);
	// go.add_edge(1, 3);
	// go.add_edge(1, 4);
	// go.add_edge(2, 1);
	// go.add_edge(3, 2);
	// go.add_edge(3, 4);

	go.print();

	go.depth_first_search_recursive();

	go.depth_first_search_iterative();

	return 0;
}