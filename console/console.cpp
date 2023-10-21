#include "linked_list/linked_list.h"
#include <iostream>
using namespace std;
using namespace Tlink;

void sum(LinkedList<int>& a) {
	LinkedList<int> c;
	c.push_head(5);
	c.push_head(7);
	c.push_head(5);
	c.push_head(5);
	a.push_head(c);
}
int main() {
	LinkedList<int> c;
	c.push_head(5);
	c.push_head(5);
	c.push_head(7);
	c.push_head(7);
	c.push_head(5);
	c.push_head(7);
	c.push_head(5);
	c.push_head(7);
	c.push_head(5);
	c.deelte_node(5);
	c.print();
	return 0;
}
