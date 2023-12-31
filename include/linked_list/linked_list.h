#pragma once
#include <iostream>
#include <stdexcept>
#include <random>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

namespace Tlink {

	template<typename T>
	struct Node {
		Node<T>* _next;
		T _data;
		Node(const T& data, Node<T>* next = nullptr) : _data(data), _next(next) {}
	};

	template<typename T>
	class LinkedList {
		Node<T>* _head;
	public:
		LinkedList() : _head(nullptr) {}

		LinkedList(size_t size, size_t* size_word) : _head(nullptr) {
			size_t i = 0;
			for (size, i; size != 0; --size, i++) {
				random_device rd;
				mt19937 generator(rd());
				uniform_int_distribution<int> distribution('a', 'z');
				string rand_str(size_word[i], '\0');
				for (auto& dis : rand_str)
					dis = distribution(generator);

				push_tail(rand_str);
			}

		}

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

		Node<T>* get_head() const {
			return _head;
		}

		size_t size() {
			Node<T>* ptr = _head;
			size_t size = 0;
			while (ptr) {
				ptr = ptr->_next;
				size++;
			}
			return size;
		}

		LinkedList& operator=(LinkedList a) {
			swap(a);
			return*this;
		}

		void swap(LinkedList& a) {
			std::swap(_head, a._head);
		}


		void push_head(const T& data) {
			_head = new Node<T>(data, _head);
		}

		void push_tail(const T& data) {
			if (!_head) {
				this->push_head(data);
				return;
			}
			Node<T>* ptr = _head;
			while (ptr->_next) {
				ptr = ptr->_next;
			}
			ptr->_next = new Node<T>(data);
		}

		void push_head(LinkedList a) {
			a.push_tail(*this); 
			swap(a);
		}

		void push_tail(const LinkedList& a) {
			Node<T>* ptr = a._head;
			while (ptr) {
				this->push_tail(ptr->_data);
				ptr = ptr->_next;
			}
		}

		void pop_head() {
			if (!_head) {
				throw out_of_range("List emplty, but you are trying delete data.");
			}
			Node<T>* ptr = _head;
			_head = _head->_next;
			delete ptr;
			ptr = nullptr;
		}

		void pop_tail() {
			if (!_head) {
				throw out_of_range("List emplty, but you are trying delete data.");
			}
			if (!_head->_next) {
				delete _head;
				_head = nullptr;
				return;
			}
			Node<T>* ptr = _head;
			while (ptr->_next->_next) {
				ptr = ptr->_next;
			}
			Node<T>* temp = ptr;
			delete ptr->_next;
			temp->_next = nullptr;

		}

		const T& operator[](size_t index) const {
			auto ptr = _head;
			while (index > 0 && ptr) {
				ptr = ptr->_next;
				index--;
			}
			if (!ptr) {
				throw std::out_of_range("Index out of range");
			}
			return ptr->_data;
		}

		T& operator[](size_t index) {
			auto ptr = _head;
			while (index > 0 && ptr) {
				ptr = ptr->_next;
				index--;
			}
			if (!ptr) {
				throw std::out_of_range("Index out of range");
			}
			return ptr->_data;

		}
		void deelte_node(const T& data) {
			Node<T>* ptr = _head;
			Node<T>* ptr1 = nullptr;
			while (_head && _head->_data == data) {
				_head = ptr->_next;
				delete ptr;
				ptr = _head;
			}

			while (ptr) {
				if (ptr->_data == data) {
					ptr1->_next = ptr->_next;
					delete ptr;
					ptr = ptr1->_next;
				}
				else {
					ptr1 = ptr;
					ptr = ptr->_next;
				}
			}

		}

		ostream& print(ostream& os = cout) const {
			Node<T>* ptr = _head;
			while (ptr) {
				os << ptr->_data << '|';
				ptr = ptr->_next;
			}
			os << endl;
			return os;
		}
	};

	template <typename T>
	ostream& print(const LinkedList<T>& a, ostream& os = cout) {
		Node<T>* ptr = a.get_head();
		while (ptr) {
			os << ptr->_data << '/';
			ptr = ptr->_next;
		}
		os << endl;
		return os;
	}

	string add_string(const LinkedList<string>& a) {
		std::ostringstream oss;
		Node<string>* ptr = a.get_head();
		oss << ptr->_data << ":/";
		ptr->_next;
		while (ptr) {
			oss<<ptr->_data<< '/';
			ptr = ptr->_next;
		}
		string str = oss.str();
		return str;
	}

	string re_string(string a) {
		a = "C:/laba/test5.txt";
		return a;
	}




	

}
