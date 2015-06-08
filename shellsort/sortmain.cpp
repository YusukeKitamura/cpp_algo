/*    Shell sort    */
#include "shellsort.h"

int main(void) {
    shellsort obj;

    std::cout << "Before:";
    obj.view();

    obj.sort();

    std::cout <<"After: ";
    obj.view();
	
    return EXIT_SUCCESS;
}
