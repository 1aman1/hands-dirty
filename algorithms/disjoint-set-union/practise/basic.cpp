#include <iostream>
#include <vector>

class DSU
{
private:
  std::vector<int> parent;

public:
  DSU(int n)
  {
    parent.resize(n);
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

  void unite(int x, int y)
  {
    int nodeX = find(x);
    int nodeY = find(y);
    if (nodeX != nodeY)
    {
      parent[nodeY] = nodeX; // Attach one root to the other
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

  dsu.unite(0, 1);
  dsu.unite(1, 2);

  std::cout << "Are 0 and 2 connected? " << (dsu.isConnected(0, 2) ? "Yes" : "No") << std::endl; // Yes
  std::cout << "Are 0 and 3 connected? " << (dsu.isConnected(0, 3) ? "Yes" : "No") << std::endl; // No

  dsu.unite(2, 3);
  dsu.unite(3, 4);

  std::cout << "Are 0 and 4 connected? " << (dsu.isConnected(0, 4) ? "Yes" : "No") << std::endl; // Yes

  return 0;
}
