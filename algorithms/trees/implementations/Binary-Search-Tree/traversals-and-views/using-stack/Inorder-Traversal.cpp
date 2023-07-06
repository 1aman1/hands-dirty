vector<int> Solution::inorderTraversal(TreeNode* A) {    
    stack<TreeNode *> s; 
    TreeNode *curr = A; 
    vector<int> result;
    
    while( curr || !s.empty() ) { 
        while (curr) { 
            s.push(curr); 
            curr = curr->left; 
        } 
        curr = s.top(); 
        s.pop(); 
        result.push_back(curr->val); 
        curr = curr->right; 
    }
    return result;
}
