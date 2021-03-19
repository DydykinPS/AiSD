#pragma once
#include <string>
#include <iostream>
using namespace std;

template<class T>
struct Link
{
	T val;
	Link* next;
	Link<T>(T _val = "", Link* _next = NULL) :val(_val), next(_next) {}
	void setNext(Link<T>* _next) { next = _next; }
	void delNext() { next = nullptr; }
};

template<class T>
class Iterator {
	Link<T>* t;
public:
	Iterator<T>(Link<T>* _t) :t(_t) {}

	bool hasNext() {
		return t != NULL;
	}

	T& next() {
		if (!hasNext())throw - 1;
		T& val = t->val;
		t = t->next;
		return val;
	}

	T& val() {
		if (!hasNext())throw - 1;
		T& val = t->val;
		return val;
	}
};

template<class T>
class List
{	
	Link<T>* first;
public:
	List() : first(nullptr) {}
	List(const List& list) { *this = list; }
	List& operator= (const List<T>& list)
	{
		if (first) this->~List();
		Link<T>* p = list.first;
		Link<T>* p1 = nullptr;
		while (p)
		{
			Link<T>* tmp = new Link<T>(p->val);
			if (!first) // Копирование первого элемента
			{
				first = tmp;
				p1 = tmp;
			}
			else // Копирование остальных элементов
			{
				p1->next = tmp;
				p1 = p1->next;
			}
			p = p->next;
		}
		return *this;
	}
	~List()
	{
		while (first)
		{
			Link<T>* tmp = first->next;
			delete first;
			first = tmp;
		}
	}
	void addFirst(T val) {
		Link<T>* p_new;
		p_new = new Link<T>(val, first);
		first = p_new;
	}

	void delFirst() {
		if (first == nullptr) throw - 1;
		Link<T>* p;
		p = first;
		first = first->next;
		delete p;
	}

	void addLast(T val) {
		if (first == nullptr) addFirst(val);
		else {
			Link<T>* p_new = new Link<T>(val);
			Link<T>* t = first;
			while (t->next != nullptr)
				t = t->next;
			t->setNext(p_new);
		}
	}

	void delLast() {
		Link<T>* p, * p1;
		p = first;
		while (p->next->next != nullptr)
			p = p->next;
		p1 = p->next;
		p->delNext();
		delete p1;
	}
	bool isEmpty() { return !first; }
	T pop()
	{
		if (first)
		{
			T val = first->val;
			Link<T>* tmp = first->next;
			delete first;
			first = tmp;
			return val;
		}
		throw - 1;
	}
	size_t size()
	{
		size_t count = 0;
		Link<T>*p = first;
		while (p)
		{
			count++;
			p = p->next;
		}
		return count;
	}
	friend std::ostream& operator<< (std::ostream& o, const List& list)
	{
		Link<T>*p = list.first;
		if (!p) o << "List is empty";
		while (p)
		{
			o << p->val;
			p = p->next;
		}
		o << '\n';
		return o;
	}
	Iterator<T> getIterator() {
		return Iterator<T>(first);
	}

	bool operator==(const List& l) {
		Link<T>* p1, * p2;
		p1 = first;
		p2 = l.first;
		while (p1 != nullptr && p2 != nullptr) {
			if (p1->val != p2->val) return false;
			p1 = p1->next;
			p2 = p2->next;
		}
		if ((p1 == nullptr && p2 != nullptr) || (p1 != nullptr && p2 == nullptr)) return false;
		return true;
	}
};

