#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

namespace Tlink{

	template<typename T>
	struct Node {
		Node* _next;
		T _data;
		Node(const T& data, Node<T>* next = nullptr) : _data(data), _next(next) {}
	};

	template<typename T>
	class LinkedList {
		Node<T>* _head;
	public:
		LinkedList() : _head(nullptr) {}
		LinkedList(const LinkedList& a) : _head(nullptr) {
			Node<T>* ptr = a._head;
			while (ptr) {
				push_tail(ptr->_data);
				ptr = ptr->_next;
			}
		}
		~LinkedList() {
			while (_head)
			{
				Node<T>* ptr = _head;
				_head = _head->_next;
				delete ptr;
			}
		}
		LinkedList& operator=(LinkedList a) {
			swap(a);
			return* this;
		}
		void swap(LinkedList& a) {
			std::swap(_head, a._head);
		}
		void push_head(const T& data) {
			_head = new Node<T>(data, _head);
		}
		void push_tail(const T& data) {
			if (!_head) {
				_head= new Node<T>(data);
				return;
			}
			Node<T>* ptr = _head;
			while (ptr->_next) {
				ptr = ptr->_next;
			}
			ptr->_next = new Node<T>(data);
		}
		void pop_head() {
			Node<T>* ptr = _head;
			_head = _head->_next;
			delete ptr;
			ptr = nullptr;
		}
		//void delete_node(T data) {
		//	Node<T>* ptr = _head;
		//	while (ptr) {
		//		if (ptr->_data == data) {

		//		}
		//	}
		//}
		//void push_head(LinkedList& a) {
		//	Node<T>* ptr = a._head;
		//	while (ptr->_next) {
		//		ptr = ptr->_next;
		//	}
		//	ptr->_next = _head;
		//	_head = a._head;
		//}
		ostream& print(ostream& os = cout) const {
			Node<T>* ptr = _head;
			while (ptr) {
				os << ptr->_data << '|';
				ptr=ptr->_next;
			}
			os << endl;
			return os;
		}
	};
}
