#include "linked_list/linked_list.h"
#include <iostream>
#include <string>
using namespace std;
using namespace Tlink;



int main() {
    size_t b[5] {1, 5, 3, 4, 5};
    LinkedList<string> a(5, b);
    print(a);
    return 0;

}
