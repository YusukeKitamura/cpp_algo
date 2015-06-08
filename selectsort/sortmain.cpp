/*    Selection sort    */
#include "selectsort.h"

int main(void) {
    selectsort obj;

    std::cout << "Before:";
    obj.view();

    obj.sort();

    std::cout <<"After: ";
    obj.view();
	
    return EXIT_SUCCESS;
}
