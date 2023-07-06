Node *FindDeepestNode(Node* pRoot ) {
	if( !pRoot )
		return;
	Node* temp = NULL;
	queue<Node* > Q;
	Q.push( pRoot );
	while( !Q.empty() ) {
		temp = Q.front(), Q.pop();
		if( temp->left )
			Q.push(temp->left);
		if( temp->right )
			Q.push(temp->right);
	}
	//empty the stack
	return temp;
}