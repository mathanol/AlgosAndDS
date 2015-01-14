#ifndef _LIST_H
#define _LIST_H 

#include <iostream>
#include <vector>

using namespace std; 

template <class Key, class Data>
class ListNode {

	public:
		ListNode(Key key, Data data, ListNode<Key, Data> *next); 
		ListNode<Key, Data> *next; 
		Key key; 
		Data data; 
}; 

template <class Key, class Data>
ListNode<Key,Data>::ListNode(Key key, Data data, ListNode<Key, Data>* next) {
	this->key  = key; 
	this->data = data; 
	this->next = next; 
}

template <class Key, class Data>
class ListST {
		
	public:
		ListST(); 
		ListNode<Key, Data>* head; 
		void put(Key key, Data data);
		Data get(Key key);
		void del(Key key); 
		int N;
		vector<Key> keys(); 
		bool contains(Key key); 
}; 

template <class Key, class Data>
ListST<Key, Data>::ListST() { 
	head = NULL;
	N = 0; 
}

template <class Key, class Data>
void ListST<Key, Data>::put(Key key, Data data) { 
	
	ListNode<Key, Data> *n = head; 
	while(n != NULL) {
		if (n->key == key) {
			n->data = data; 
			return;
		}
		n = n->next;
	}

	n = new ListNode<Key,Data>(key, data, head); 
	N++; 
	head = n; 

}; 

template <class Key, class Data>
Data ListST<Key, Data>::get(Key key) { 

	ListNode<Key, Data> *n = head; 
	while(n != NULL) {
		if (n->key == key)
			return n->data; 
		n = n->next; 
	}
	throw "Key not Found"; 
}

template <class Key, class Data>
void ListST<Key, Data>::del(Key key) {

	ListNode<Data, Key> *n = head; 
	while(n != NULL) { 
		if (n->key == key) {
			if (n == head)
				head = n->next; 
			delete n;
			N--; 
		}
		n = n->next; 
	}
	
}

template <class Key, class Data> 
bool ListST<Key, Data>::contains(Key key) { 

	ListNode<Key, Data> *n = head; 
	while(n != NULL) { 
		if (n->key == key) 
			return true; 
		n = n->next; 
	}
	
	return false; 
}

template <class Key, class Data>
vector<Key> ListST<Key, Data>::keys() { 
	vector<Key> v; 
	
	ListNode<Key, Data> *n = head; 
	while(n != NULL) { 
		v.push_back(n->key); 
		n = n->next; 
	}
	
	return v; 
}

	


#endif 
