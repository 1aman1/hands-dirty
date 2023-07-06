#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

class tNode{
  public:
    tNode(int value):data(value), left(NULL), right(NULL), height(0)
  {}
    int data;
    int height;
    tNode* left;
    tNode* right;
};

int height(tNode* pRoot ){
  if( pRoot ){
    int left = height( pRoot->left );
    int right = height( pRoot->right );
    return 1 + max(left, right );
  }
  else
    return -1;
}

//mention all rotations ,

tNode* treatLeftLeft( tNode* parent){
  tNode* child = parent->left;

  parent->left = child->right;
  child->right = parent;
  parent->height = max( height(parent->left), height(parent->right) ) +1;
  child->height = max( height(child->left), parent->height ) +1;
  //return new root
  return child;
}

tNode* treatRightRight( tNode* parent){
  tNode* child = parent->right;

  parent->right = child->left;
  child->left = parent;
  parent->height = max( height(parent->left), height(parent->right) ) +1;
  child->height = max( height(child->left), parent->height ) +1;
  //return new root
  return child;
}

tNode* treatRightLeft( tNode* parent ){
  parent->right = treatLeftLeft( parent->right );
  return treatLeftLeft( parent);
}

tNode* treatLeftRight( tNode* parent ){
  parent->left = treatRightRight( parent->left );
  return treatRightRight( parent );
}

tNode* insert( tNode* root, int data ) {

  if( !root ) {
    tNode* temp = new tNode( data );
    return temp;
  }

  else if(data < root->data ) {
    root->left = insert( root->left, data );
    if( abs( height(root->left)- height(root->right) ) == 2 ) {
      if( data < root->left->data )
        root = treatLeftLeft( root );
      else
        root = treatLeftRight( root );
    }
  }

  else if( data > root->data ) {
    root->right = insert( root->right, data );
    if( abs( height(root->left)- height(root->right) ) == 2 ) {
      if( data < root->right->data )
        root = treatRightRight( root );
      else
        root = treatRightLeft( root );
    }    
  }
  root->height = max( height(root->left), height(root->right) );
  return root;
}

void levelOrder( tNode* pRoot ) {
  queue<tNode*> Q;

  tNode* temp = NULL;
  Q.push( pRoot );
  while( !Q.empty() ) {
    temp = Q.front(), Q.pop();

    cout << temp->data << " ";

    if( temp->left )
      Q.push( temp->left );
    if( temp->right )
      Q.push( temp->right );
  }
  while( !Q.empty() ) Q.pop();
  cout << endl;
}

int _count = 0;
tNode* constructAVL( int h ){
  if( h <= 0 ) 
    return NULL;
  tNode* temp = new tNode(++_count);
  temp->left = constructAVL( h-1 ); 
//  temp->data = ++_count;
  temp->right = constructAVL( h-2 );
  temp->height = h;
  return temp;
}

void inOrder( tNode* root ){
  if( root ){
    inOrder( root->left );
    cout <<    root->data << " ";
    inOrder(root->right );
  }
}

int main() {
  tNode* root = new tNode(3);
  
//  root = insert( root , 5);
 // root = insert( root , 4);
  //root = insert( root , 3);
  //root = insert( root , 2);
 // root = insert( root , 1);
root =   constructAVL(4);
  levelOrder( root );

  cout<<"inor";
  cout<<endl;
  inOrder(root);
  return 0;
}
