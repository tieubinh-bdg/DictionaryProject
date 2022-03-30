#pragma once
#include <string>
#include <vector>
#include <iostream>;
using namespace std;

template <typename T>
struct Item {
	string key;
	T value;
	Item(string key, T value) {
		this->key = key;
		this->value = value;
	}

};
template <typename T>
class Dictionary {
private:
	vector<Item<T>*> list;
public:

	Dictionary();
	~Dictionary();
	void Display();
	void Add(string key, T value);
	void Clear();
	void Remove(string key);
	bool ContainsKey(string key);

	bool ContainsValue(T value);
};

template <typename T>
Dictionary<T>::Dictionary() {
	this->list = {};
}
template <typename T>
Dictionary<T>::~Dictionary() {
	//vector<Item*>().swap(this->list); //Way 1
	//list.shrink_to_fit();	//Way 2
	//loop Way 3
	for (int i = 0; i < this->list.size(); i++) {
		delete this->list[i];
	}

}
template <typename T>
void Dictionary<T>::Display() {
	for (auto x : this->list) {
		cout << "{ " << x->key << ", " << x->value << " }" << endl;
	}

}
template <typename T>
void Dictionary<T>::Add(string key, T value) {
	Item<T>* newItem = new Item(key, value);
	bool flag = true;
	for (auto x : this->list) {
		if (x->key == key) {
			flag = false;
			break;
		}
	}

	if (flag) {
		this->list.push_back(newItem);
	}
}

template <typename T>
void Dictionary<T>::Clear() {
	this->list.clear();
}

template <typename T>
void Dictionary<T>::Remove(string key) {
	for (int i = 0; i < this->list.size(); i++)
	{
		if (this->list[i]->key == key) {
			delete this->list[i]; //release memory then erase
			this->list.erase(this->list.begin() + i);
			break;
		}
	}
}

template <typename T>
bool Dictionary<T>::ContainsKey(string key) {
	bool flag = false;
	for (auto x : this->list) {
		if (x->key == key) {
			flag = true;
			break;
		}
	}

	return flag;
}

template <typename T>
bool Dictionary<T>::ContainsValue(T value) {
	bool flag = false;
	for (auto x : this->list) {
		if (x->value == value) {
			flag = true;
			break;
		}
	}

	return flag;
}
