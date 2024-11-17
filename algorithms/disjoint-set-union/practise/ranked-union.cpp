#include <iostream>
#include <vector>

class DSU
{
private:
  std::vector<int> parent; // Stores the parent of each element
  std::vector<int> rank;   // Used for union by rank

public:
  DSU(int n)
  {
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; ++i)
    {
      parent[i] = i; // Each element is its own parent initially
    }
  }

  int find(int x)
  {
    if (parent[x] != x)
    {
      parent[x] = find(parent[x]); // Path compression
    }
    return parent[x];
  }

  // Union two sets containing 'x' and 'y' (by rank)
  void unite(int x, int y)
  {
    int nodeX = find(x);
    int nodeY = find(y);

    if (nodeX != nodeY)
    {
      if (rank[nodeX] < rank[nodeY])
      {
        parent[nodeX] = nodeY;
      }
      else if (rank[nodeX] > rank[nodeY])
      {
        parent[nodeY] = nodeX;
      }
      else
      {
        parent[nodeY] = nodeX;
        rank[nodeX]++;
      }
    }
  }

  // Check if 'x' and 'y' are in the same set
  bool isConnected(int x, int y)
  {
    return find(x) == find(y);
  }
};

int main()
{
  DSU dsu(5); // Create DSU for elements 0 to 4

  dsu.unite(0, 1); // Union sets containing 0 and 1
  dsu.unite(1, 2); // Union sets containing 1 and 2

  std::cout << "Are 0 and 2 connected? " << (dsu.isConnected(0, 2) ? "Yes" : "No") << std::endl; // Yes
  std::cout << "Are 0 and 3 connected? " << (dsu.isConnected(0, 3) ? "Yes" : "No") << std::endl; // No

  dsu.unite(3, 4); // Union sets containing 3 and 4
  dsu.unite(2, 3); // Union sets containing 2 and 3 (now all are connected)

  std::cout << "Are 0 and 4 connected? " << (dsu.isConnected(0, 4) ? "Yes" : "No") << std::endl; // Yes

  return 0;
}
