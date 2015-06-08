/*    Binary search tree   */
#include "tree.h"

int main(void) {
    BSTree tree;
	
    while (1) {
		int  Command;
		dType Data;
	
        std::cout << "1:add 2:remove 3:remove all 4:search 5:view 0:finish " << std::endl;
        std::cin >> Command;
		
        if (Command == FINISH)
		    break;

		switch( Command ) {
		case ADD:  				// Add
			std::cout << "Input data to add" << std::endl;
			std::cin >> Data;
			tree.add(Data);
			break;
		case REMOVE:  			// Remove
			std::cout << "Input data to remove" << std::endl;
			std::cin >> Data;
			tree.remove(Data);
			break;
		case REMOVEALL:		// Remove all node
		    tree.removeAll(tree.getRoot());
			std::cout << "Removed all data." << std::endl;
			break;
		case SEARCH:  			// Search
			std::cout << "Input data to search" << std::endl;
			std::cin >> Data;
			tree.search(Data);
			break;
		case VIEW:  				//View tree
			if (tree.getRoot() == NULL) {
				std::cout << "Tree is empty." << std::endl;
				break;
			}
		    std::cout << "Tree:\n";
		    tree.view(tree.getRoot(), 0);
			break;
			
		default:
			std::cout << "Command incorrect." << std::endl;
			break;
		}
		
	}
	
	return EXIT_SUCCESS;
}
