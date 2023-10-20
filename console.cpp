#include "src/linked_list.cpp"
#include <iostream>
using namespace std;
using namespace Tlink;

int main() {
	LinkedList<int> a;
	LinkedList<int> c;
	a.push_head(5);
	a.push_head(6);
	a.push_head(7);
	a.print();
	a.pop_head();
	a.pop_head();
	a.print();
	c.push_head(3);
	c.push_tail(1);
	c.print();
	a.print();
	LinkedList<int> b(c);
	b.print();
	a = c;
	a.print();


	return 0;
}
