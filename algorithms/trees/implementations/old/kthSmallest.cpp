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

tNode* LCA( tNode* pRoot , tNode* A, tNode* B ){
  while( 1 ){
    if(( A->data < pRoot->data && pRoot->data < B->data ) || ( B->data < pRoot->data && A->data > pRoot->data ) )
      return pRoot ;
    if( A->data < pRoot->data )
      pRoot = pRoot->left;
    else
      pRoot = pRoot->right;
  }
}

int isBST( tNode* pRoot, int* prev ){
  if( !pRoot)
    return 1;
  if( !isBST(pRoot->left, prev ) )
    return 0;
  if( *prev > pRoot->data )
    return 0;
  *prev = pRoot->data;
  return (isBST(pRoot->right, prev ));
}


void inOrder(tNode* pRoot){
  if( pRoot ){
    inOrder( pRoot->left );
    cout << pRoot->data << " ";
    inOrder( pRoot->right );
  }
}
//inorder proceeding
tNode* kthElement( tNode* pRoot, int k, int *count ){
  if( !pRoot )
    return NULL;
  tNode* goToLeft = kthElement( pRoot->left, k, count );
  if( goToLeft )
    return goToLeft;
  if( k == ++(*count) )
    return pRoot;
  return kthElement( pRoot->right, k, count );
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
//  insert(root, 0);
  insert(root, 2);  
  //  insert(root, 8);
  // root = deleteNode( root , 3);
///  int prev = INT_MIN; 
//   tNode* A = new tNode(4);
  //tNode* B = new tNode(2);
 // cout<<isBST( root, &prev );
 // tNode* temp = LCA( root ,A, B);
  //cout<<"LCA" << temp->data <<endl;
  // inOrder( root );
  int c = 0;
  tNode* temp = kthElement( root, 4, &c); 

  cout <<temp->data<< endl;
  inOrder(root );
  return 0;
}
