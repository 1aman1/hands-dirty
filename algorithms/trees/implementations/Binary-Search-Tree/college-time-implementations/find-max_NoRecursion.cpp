// give algo to find the max element in tree without using Recursion

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

void findMax(tNode *pRoot)
{
  queue<tNode *> Q;
  double m = INT_MIN;

  tNode *temp = NULL;
  Q.push(pRoot);
  while (!Q.empty())
  {
    temp = Q.front();
    Q.pop();
    if (temp->data > m)
      m = temp->data;

    if (temp->left)
      Q.push(temp->left);
    if (temp->right)
      Q.push(temp->right);
  }
  cout << m;
  while (!Q.empty())
    Q.pop();
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

  root->left = newNode1;
  root->right = newNode2;
  newNode1->left = newNode3;
  newNode1->right = newNode4;
  newNode2->left = newNode5;
  newNode2->right = newNode6;

  cout << "elements present are:";
  cout << endl;
  findMax(root);

  return 0;
}
