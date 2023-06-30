#include<iostream>
#include<climits>
using namespace std;

class tNode{
public:
  short data;
  tNode* left;
  tNode* right;
 
  tNode(int x):data(x), left(NULL), right(NULL)
  {}
};

tNode* insert( tNode* pRoot, int value ){
  if( !pRoot ){
    tNode* temp = new tNode(value);
    return temp;
  }
  else if( value < pRoot->data ){
    pRoot->left = insert( pRoot->left, value );
  }
  else if( value > pRoot->data ){
    pRoot->right = insert( pRoot->right, value );
  }
  return pRoot; 
}

tNode* findSuccessor( tNode* pRoot ){
  tNode* temp = pRoot;
  while( temp->left != NULL )
    temp = temp->left;
  return temp;
}

tNode* deleteNode( tNode* pRoot, int value ){
  if( !pRoot )
    return pRoot;
  else if( value < pRoot->data )
    pRoot->left = deleteNode(pRoot->left, value );
  else if( value > pRoot->data ) 
    pRoot->right = deleteNode( pRoot->right, value );
  else{
    if( pRoot->right == NULL ){//right child is NULL
      tNode* copyOfLeftNode = pRoot->left;
      delete( pRoot );
      return copyOfLeftNode;
    }
    else if( pRoot->left == NULL){
      tNode* copyOfRightNode = pRoot->right;
      delete( pRoot );
      return copyOfRightNode;
    }
    else{
      tNode* copy = findSuccessor( pRoot->right );
      pRoot->data = copy->data;
      pRoot->right = deleteNode( pRoot->right, copy->data );
    }
  }
  return pRoot;
}

tNode* inOrder2(tNode* pRoot){
  if( !pRoot )
    return NULL;
  if( pRoot->left )
    inOrder2( pRoot->left );
  cout << pRoot->data << " ";
  return inOrder2( pRoot->right );
}



void inOrder(tNode* pRoot, const int min, const int max){
  if( pRoot ){
    inOrder( pRoot->left, min, max );
    if( pRoot->data > min && pRoot->data < max)
      cout << pRoot->data << " ";
    inOrder( pRoot->right ,min, max );
  }
}

int main(){
  /*       5
   *     3   7
   *   1  4 6  8
   *  0 2 
   * */
  tNode* root = new tNode(5);
  insert(root, 3);
  insert(root, 7);
  insert(root, 1);
  insert(root, 4);
  insert(root, 6);
  insert(root, 8);
  insert(root, 0);
  insert(root, 2);  
  //  insert(root, 8);
  // root = deleteNode( root , 3);
  inOrder2( root );
  cout << endl;
 // inOrder(root );
  return 0;
}
