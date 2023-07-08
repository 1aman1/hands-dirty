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

int size( tNode* pRoot ){
  
  if( !pRoot )
    return -1;

  size_t count = 0;
  queue<tNode*> Q;
  tNode* tmp = NULL;

  Q.push( pRoot );
  while( !Q.empty() ){
    tmp = Q.front(), Q.pop();
    ++count;
    if( tmp->left )
      Q.push( tmp->left );
    if( tmp->right )
      Q.push( tmp->right );
  }
  return count;
}
int main(){

  tNode* root = new tNode(1);
  tNode* newNode1 = new tNode(2);
  tNode* newNode2 = new tNode(3);
  tNode* newNode3 = new tNode(4);
  tNode* newNode4 = new tNode(5);
  tNode* newNode5 = new tNode(6);
  tNode* newNode6 = new tNode(7);

  root->left = newNode1;
  root->right = newNode2 ;
  newNode1->left = newNode3;
  newNode1->right= newNode4;
  newNode2->left = newNode5;
  newNode2->right = newNode6;

  levelOrder( root );
  cout << endl;
  cout <<   size( root );

  return 0;
}
