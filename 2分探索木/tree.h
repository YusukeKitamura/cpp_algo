/*    Binary search tree   */
#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <cstdlib>
#include <cstring>

typedef int dType;				// Data type
enum Command {
    FINISH,
    ADD,
    REMOVE,
	REMOVEALL,
	SEARCH,
	VIEW
};

/* node */
typedef struct node {
	dType data;					// Data
	node* left;					// Left child
	node* right;					// Right child
}Node;

class BSTree {
private:
	node* root; 							 /* root node */
public:
    BSTree();
    void add(dType Data);				/*	add data	*/
    node* remove_min(node** n); 		/* remove smallest data*/
    void remove(dType Data);			/* remove data */
	void removeAll(node* n);			// Remove all data
    void search(dType Data);			/* Search data */
	node* getRoot();
	void view(node* n, int depth);								// View list
	~BSTree();
};

#endif
