void insert( Node* root, int data) {
	Node* newNode = new Node(data);
	queue<Node*> Q;
	Q.push(root);
	while( !Q.empty() ) {
		Node* temp = Q.front(), Q.pop();
		if( temp->left )
			Q.push(temp->left);
		else{
			temp->left = newNode;
			Q.erase();
			return ;
		}
		if( temp->right )
			Q.push(temp->right);
		else{
			temp->right = newNode;
			Q.erase();
			return ;
		}
		
	}
	Q.delete();
	//return ;
}