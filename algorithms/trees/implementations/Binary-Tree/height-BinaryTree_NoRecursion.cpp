#include <bits/stdc++.h>
using namespace std;

class tNode
{
public:
  size_t data;
  tNode *left;
  tNode *right;
  tNode(int item) : data(item)
  {
  }
};

void heightNonRecursively(tNode *pRoot)
{
  queue<tNode *> Q;
  size_t count = 0;
  tNode *temp = NULL;
  Q.push(pRoot);
  Q.push(NULL);

  while (!Q.empty())
  {
    temp = Q.front();
    Q.pop();

    if (temp == NULL)
    {
      if (!Q.empty())
        Q.push(NULL);
      ++count; // increment level
    }
    else
    {
      if (temp->left)
        Q.push(temp->left);
      if (temp->right)
        Q.push(temp->right);
    }
  }

  while (Q.empty())
    Q.pop();
  cout << count << endl;
}

int main()
{

  tNode *root = new tNode(1);
  tNode *newNode1 = new tNode(2);
  tNode *newNode2 = new tNode(3);
  tNode *newNode3 = new tNode(4);
  tNode *newNode4 = new tNode(5);
  tNode *newNode5 = new tNode(6);
  tNode *newNode6 = new tNode(7);
  tNode *newNode7 = new tNode(8);

  root->left = newNode1;
  root->right = newNode2;
  newNode1->left = newNode3;
  newNode1->right = newNode4;
  newNode2->left = newNode5;
  newNode2->right = newNode6;
  newNode3->left = newNode7;

  heightNonRecursively(root);
  return 0;
}
