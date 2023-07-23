#include <iostream>
#include <vector>
#include <iterator>
#include <queue>

/*
1-> implement Graph using array of vector
*/

struct Graph
{
public:
	typedef std::vector<int> listOfVectors;

protected:
	listOfVectors *graph_;
	int _vertices;

public:
	void
	print();

	void
	add_edge(int, int);

	Graph(int v) : _vertices(v)
	{
		graph_ = new listOfVectors[_vertices];
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
			// traverse neighbour for the current vertex
			std::cout << "[ ";
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

int main()
{
	Graph go(6);

	go.add_edge(0, 1);
	go.add_edge(0, 4);
	go.add_edge(0, 5);

	go.add_edge(1, 3);
	go.add_edge(1, 4);

	go.add_edge(2, 1);

	go.add_edge(3, 2);
	go.add_edge(3, 4);

	go.print();

	return 0;
}