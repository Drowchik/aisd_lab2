#include <gtest/gtest.h>
#include "linked_list/linked_list.h"

using namespace std;
using namespace Tlink;

TEST(LinkedTest, push_head) {
	LinkedList<int> a;
	a.push_head(5);
	a.push_head(4);
	a.push_head(3);
	EXPECT_EQ(a[0], 3);
	EXPECT_EQ(a[1], 4);
	EXPECT_EQ(a[2], 5);
}

TEST(LinkedTest, push_tail) {
	LinkedList<int> a;
	a.push_tail(5);
	a.push_tail(4);
	a.push_tail(3);
	EXPECT_EQ(a[0], 5);
	EXPECT_EQ(a[1], 4);
	EXPECT_EQ(a[2], 3);
}

TEST(LinkedTest, Constructor_copy) {
	LinkedList<int> a;
	a.push_tail(5);
	a.push_tail(4);
	a.push_tail(3);
	LinkedList<int> c(a);
	EXPECT_EQ(c[0], 5);
	EXPECT_EQ(c[1], 4);
	EXPECT_EQ(c[2], 3);
}

TEST(LinkedTest, push_head_list) {
	LinkedList<int> a;
	a.push_tail(5);
	a.push_tail(4);
	a.push_tail(3);
	LinkedList<int> c;
	c.push_tail(1);
	c.push_tail(2);
	c.push_tail(0);
	c.push_head(a);

	EXPECT_EQ(c[0], 5);
	EXPECT_EQ(c[1], 4);
	EXPECT_EQ(c[2], 3);
	EXPECT_EQ(c[3], 1);
}

TEST(LinkedTest, push_tail_list) {
	LinkedList<int> a;
	a.push_tail(5);
	a.push_tail(4);
	a.push_tail(3);
	LinkedList<int> c;
	c.push_tail(1);
	c.push_tail(2);
	c.push_tail(0);
	c.push_tail(a);

	EXPECT_EQ(c[0], 1);
	EXPECT_EQ(c[1], 2);
	EXPECT_EQ(c[2], 0);
	EXPECT_EQ(c[3], 5);
}

TEST(LinkedTest, pop_head_list) {
	LinkedList<int> a;
	EXPECT_THROW(a.pop_head(), out_of_range);
}

TEST(LinkedTest, pop_head_list1) {
	LinkedList<int> a;
	a.push_tail(5);
	a.push_tail(4);
	a.push_tail(3);
	a.pop_head();
	EXPECT_EQ(a[0], 4);
	EXPECT_EQ(a[1], 3);
}


TEST(LinkedTest, pop_tail_list) {
	LinkedList<int> a;
	EXPECT_THROW(a.pop_tail(), out_of_range);
}

TEST(LinkedTest, pop_tail_list1) {
	LinkedList<int> a;
	a.push_tail(5);
	a.push_tail(4);
	a.push_tail(3);
	a.pop_tail();
	EXPECT_EQ(a[0], 5);
	EXPECT_EQ(a[1], 4);
}

TEST(LinkedTest, pop_tail_list2) {
	LinkedList<int> a;
	a.push_tail(5);
	a.pop_tail();
	EXPECT_THROW(a[0], out_of_range);
}

TEST(LinkedTest, pop_tail_list3) {
	LinkedList<int> a;
	a.push_tail(5);
	a.push_tail(4);
	a.push_tail(3);
	a.pop_tail();
	EXPECT_EQ(a[1], 4);
	EXPECT_THROW(a[2], out_of_range);
}

TEST(LinkedTest, delete_node) {
	LinkedList<int> c;
	c.push_head(5);
	c.push_head(5);
	c.push_head(7);
	c.push_head(7);
	c.push_head(5);
	c.push_head(5);
	c.push_head(7);
	c.push_head(5);
	c.push_head(7);
	c.push_head(5);
	c.deelte_node(5);
	EXPECT_EQ(c[0], 7);
	EXPECT_EQ(c[1], 7);
	EXPECT_EQ(c[2], 7);
	EXPECT_EQ(c[3], 7);
	EXPECT_THROW(c[4], out_of_range);

}

TEST(LinkedTest, size) {
	LinkedList<int> c;
	EXPECT_EQ(c.size(), 0);
	c.push_head(5);
	EXPECT_EQ(c.size(), 1);
	c.push_head(5);
	c.push_head(7);
	c.push_head(7);
	c.push_head(5);
	c.push_head(7);
	c.push_head(5);
	c.push_head(7);
	c.push_head(5);
	EXPECT_EQ(c.size(), 9);
}
