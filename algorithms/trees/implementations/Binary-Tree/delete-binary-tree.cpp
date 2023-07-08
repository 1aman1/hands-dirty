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

void levelOrder(tNode *pRoot)
{
  queue<tNode *> Q;

  tNode *temp = NULL;
  Q.push(pRoot);
  while (!Q.empty())
  {
    temp = Q.front();
    Q.pop();

    if (temp->data < INT_MAX && temp->data > INT_MIN)
      cout << temp->data << " ";

    if (temp->left)
      Q.push(temp->left);
    if (temp->right)
      Q.push(temp->right);
  }
  while (!Q.empty())
    Q.pop();
}

void del(tNode *pRoot)
{
  if (pRoot)
  {
    del(pRoot->left);
    del(pRoot->right);
    cout << pRoot->data << "\t\n";
    delete pRoot;
  }
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

  del(root);
  levelOrder(root);
  cerr << "deleted" << endl;
  return 0;
}
