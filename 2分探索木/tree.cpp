/*    Binary search tree   */
#include "tree.h"

BSTree::BSTree(){
    root = NULL;
}

/*	add data	*/
void BSTree::add(dType Data) {
	node* n;
	/* If root node not exist, this data is root */
	if( root == NULL ) {
	    n = new node();
		root = n; 		/*Allocate root node */
		root->left = root->right = NULL;
		root->data = Data;
		std::cout << "Added " << root->data << std::endl;
		return;
	}

	node* p = root;  /* Start from root */
	while( p != NULL ) {
		if (Data == p->data ) {
			std::cout << "Same data exist." << std::endl;
			return;  /* failed (same data exist) */
		}
		if (Data < p->data ) {
		    if (p->left != NULL) {
			    p = p->left;  /* go left */
			} else { 
			    n = new node();
			    n->data = Data;                   /* copy data */
			    n->left = n->right = NULL; /*  added data has no child */
			    p->left = n;
				return;
			}
		} else {
		    if (p->right != NULL) {
			    p = p->right; /* go right */
			} else { 
			    n = new node();
			    n->data = Data;                   /* copy data */
			    n->left = n->right = NULL; /*  added data has no child */
			    p->right = n;
		    	std::cout << "Added " << n->data << std::endl;
				return;
			}
		}
	}
}

/* remove smallest data*/
node* BSTree::remove_min(node** p) {
	node* x;
	
	while((*p)->left != NULL ) {
		p = &(*p)->left; 
	}
	
	x= *p; 
	*p = (*p)->right; 
	return x;
}

/* Remove data */
void BSTree::remove(dType Data) {
	node* n;

	node** p;
	p = &root;
	while( *p != NULL ) {
		if( Data == (*p)->data ){
			n = *p;
			if((*p)->left == NULL && (*p)->right == NULL ) {
			    *p = NULL;
			} else if ((*p)->left == NULL) {
				*p = n->right;
			} else if ((*p)->right == NULL) { 
			    *p = n->left;
			} else {
				*p = remove_min(&n->right);
				(*p)->right = n->right;
				(*p)->left = n->left;
			}
			if (n == root)
				root = *p;
			std::cout << "Removed " << n->data << std::endl;
			delete n;
			return;   /* Remove succeed */
		}
		if (Data < (*p)->data) {
			p = &(*p)->left; 
		} else {
			p = &(*p)->right; 
		}
	}
	std::cout << "Data " << Data << " is not found.\n";
	return;  // Data to remove is not found 
}

/* Search data */
void BSTree::search(dType Data){
	node* n = root; 
	while(n != NULL) {
		if (Data == n->data) {
			std::cout << "Data " << Data << " exist." << std::endl;
			return; 
		}
		if (Data < n->data) {
		    if (n->left == NULL) {
				std::cout << "Data " << Data << " is not found." << std::endl;
				return; 
			} else {
			    n = n->left;
			}
		} else {
			if (n->right == NULL) {
				std::cout << "Data " << Data << " is not found." << std::endl;
				return; 
			} else {
				n = n->right;
			}
		}
	}
	std::cout << "Data " << Data << " is not found." << std::endl;
	return;
}

void BSTree::removeAll(node* n) {
	bool rootFlg = false;
    if (n != NULL) {
		if (n == root)
			rootFlg = true;
        removeAll(n->left);
        removeAll(n->right);
		delete n; 
		if (rootFlg == true)
			root = NULL;
    }
}

node* BSTree::getRoot() {
	if (root == NULL) 
		return NULL;
    node* n = root;
    return n;
}

void BSTree::view(node* n, int depth) {
	if (n->left != NULL) {
		depth++;
		view(n->left, depth);
		depth--;
	}
	for (int k=0; k<depth; k++)
	    std::cout << "  ";
	std::cout << n->data << std::endl;
	if (n->right != NULL) {
		depth++; 
		view(n->right, depth);
		depth--;
	}
}

BSTree::~BSTree(){
    removeAll(root);
}
