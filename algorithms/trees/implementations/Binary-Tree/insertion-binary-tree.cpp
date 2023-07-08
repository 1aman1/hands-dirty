#include<bits/stdc++.h>

using namespace std;

class tNode{
public:
  size_t data;
  tNode* left;
  tNode* right;
  tNode( int item ): data( item ), left( NULL ), right( NULL )
  {}
};

void insert( tNode* pRoot, int item ){
  if( !pRoot ) 
    return ;
  tNode* tmp = new tNode( item );
  tNode* pqr = NULL;
  queue<tNode*> Q;
  Q.push( pRoot );

  while( !Q.empty() ){
    pqr = Q.front(); Q.pop();

    if( pqr->left )
      Q.push( pqr->left );
    else{
      pqr->left = tmp;
      while( !Q.empty() ) Q.pop();
      return;
    }
    if( pqr->right )
      Q.push( pqr->right );
    else{
      pqr->right = tmp;
      while( !Q.empty() ) Q.pop();;
      return ;
    }
  }
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
  cout << endl;
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
  // postOrder ( root );
  //  iterPostOrder( root );
  //inOrder( root );
  //cout<<endl;
  //iterInOrder(root);

  //preOrder( root );
  //cout<<endl;
  // iterPreOrder(root );

  levelOrder( root );
  insert( root, 15);
  levelOrder( root );
  return 0;
}
