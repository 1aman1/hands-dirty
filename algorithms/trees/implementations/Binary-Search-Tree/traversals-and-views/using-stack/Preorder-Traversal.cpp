vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> result;  
    stack<TreeNode *> s; 
    s.push(A); 
  
    while ( !s.empty() ) { 
        TreeNode *TreeNode = s.top(); 
        result.push_back(TreeNode->val); 
        s.pop(); 
		if (TreeNode->right) 
            s.push(TreeNode->right); 
        if (TreeNode->left) 
            s.push(TreeNode->left); 
    } 
    return result;
} 
