vector<int> Solution::postorderTraversal(TreeNode* A) {
	stack<TreeNode*> S;
	vector<int> result;
	TreeNode* prev = NULL;
	do {
		while( A ){
			S.push( A );
			A = A->left;
		}
		while( A == NULL && !S.empty() ) {
			A = S.top();
			if(A->right == NULL || A->right == prev ){
				result.push_back(A->val);
				S.pop();
				prev = A;
				A = NULL;
			}
			else
				A = A->right;
		}
	} while( !S.empty() );
  return result;
}
