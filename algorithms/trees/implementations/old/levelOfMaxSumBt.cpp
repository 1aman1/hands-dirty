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
  int curSum = 0, maxSum = INT_MIN, level = 1, maxLevel;

  tNode* temp;
  Q.push( pRoot );
  Q.push( NULL );

  while( !Q.empty() ){
    temp = Q.front(); Q.pop();

    if( temp == NULL ){
      if( curSum > maxSum ){
        maxSum = curSum;
        maxLevel = level;
      }
      curSum = 0;
      if( !Q.empty() ){
        ++level;
        Q.push( NULL );
      }
    }
    else{
      curSum += temp->data;
      if( temp->left )
        Q.push( temp->left );
      if( temp->right )
        Q.push( temp->right );
    }
  }
  cout << "level : " << maxLevel << endl << "Sum: " << maxSum << endl;
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


  levelOrder( root );
  return 0;
}
