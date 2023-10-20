#include "src/linked_list.cpp"
#include <iostream>
using namespace std;
using namespace Tlink;

void sum(LinkedList<int>& a) {
	LinkedList<int> c;
	c.push_head(7);
	c.push_head(7);
	c.push_head(7);
	a.push_head(c);
}
int main() {


	return 0;
}
