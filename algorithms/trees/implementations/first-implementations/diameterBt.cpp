#include<bits/stdc++.h>
using namespace std;

class tNode{
public:
  size_t data;
  tNode* left;
  tNode* right;
  tNode( int item ): data( item )
  {}
};

int height(tNode* root, int& ans)
{
    if (root == NULL)
        return 0;

    int left_height = height(root->left, ans);
    int right_height = height(root->right, ans);

    ans = 1 + left_height + right_height;

    return 1 + max(left_height, right_height);
}

int diamater(tNode* root)
{
    if (root == NULL)
        return 0;
    int ans = INT_MIN; 
    int height_of_tree = height(root, ans);
    return ans;
}

void levelOrder( tNode* pRoot ){
  queue<tNode*> Q;

  tNode* temp = NULL;
  Q.push( pRoot );
  while( !Q.empty() ){
    temp = Q.front(); Q.pop();

    cout << temp->data << " ";

    if( temp->left )
      Q.push( temp->left );
    if( temp->right )
      Q.push( temp->right );
  }
  while( !Q.empty() ) Q.pop();
}

int main(){
/*                       1
                      2     3
                    4   5  6   7
                  8 
              */       
  tNode* root = new tNode(1);
  tNode* newNode1 = new tNode(2);
  tNode* newNode2 = new tNode(3);
  tNode* newNode3 = new tNode(4);
  tNode* newNode4 = new tNode(5);
  tNode* newNode5 = new tNode(6);
  tNode* newNode6 = new tNode(7);
  tNode* newNode7 = new tNode(8);
  root->left = newNode1;
  root->right = newNode2 ;
  newNode1->left = newNode3;
  newNode1->right= newNode4;
  newNode2->left = newNode5;
  newNode2->right = newNode6;
  newNode3->left = newNode7;

//  levelOrder( root );'
  cout << diamater(root ) << endl;  return 0;
}
