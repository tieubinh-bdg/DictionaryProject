#pragma once
#include <string>
#include <vector>
#include <iostream>;
using namespace std;

template <class TKey, class TValue>
struct Item {
	TKey key;
	TValue value;
	Item(TKey key, TValue value) {
		this->key = key;
		this->value = value;
	}
};

template <class TKey, class TValue>
class Dictionary {
private:
	vector<Item<TKey, TValue>*> list;
public:
	Dictionary();
	~Dictionary();
	void Display();
	void Add(TKey key, TValue value);
	void Clear();
	void Remove(TKey key);
	bool ContainsKey(TKey key);
	bool ContainsValue(TValue value);
};

template <class TKey, class TValue>
Dictionary<TKey, TValue>::Dictionary() {
	this->list = {};
}

template <class TKey, class TValue>
Dictionary<TKey, TValue>::~Dictionary() {
	/*
		vector<Item*>().swap(this->list); //Way 1
		list.shrink_to_fit();	//Way 2
		loop Way 3
	*/
	for (int i = 0; i < this->list.size(); i++) {
		delete this->list[i];
	}
}

template <class TKey, class TValue>
void Dictionary<TKey, TValue>::Display() {
	for (auto x : this->list) {
		cout << "{ " << x->key << ", " << x->value << " }" << endl;
	}
}

template <class TKey, class TValue>
void Dictionary<TKey, TValue>::Add(TKey key, TValue value) {
	Item<TKey, TValue>* newItem = new Item<TKey, TValue>(key, value);
	//Check dupblicate
	if (!this->ContainsKey(key)) {
		this->list.push_back(newItem);
	}
}

template <class TKey, class TValue>
void Dictionary<TKey, TValue>::Clear() {
	this->list.clear();
}

template <class TKey, class TValue>
void Dictionary<TKey, TValue>::Remove(TKey key) {
	bool stopFlag = false;
	for (int i = 0; !stopFlag && i < this->list.size(); i++)
	{
		if (this->list[i]->key == key) {
			delete this->list[i]; //release memory then erase
			this->list.erase(this->list.begin() + i);
			stopFlag = true;
		}
	}
}

template <class TKey, class TValue>
bool Dictionary<TKey, TValue>::ContainsKey(TKey key) {
	for (auto x : this->list) {
		if (x->key == key) {
			return true;
		}
	}

	return false;
}

template <class TKey, class TValue>
bool Dictionary<TKey, TValue>::ContainsValue(TValue value) {
	for (auto x : this->list) {
		if (x->value == value) {
			return true;
		}
	}

	return false;
}
