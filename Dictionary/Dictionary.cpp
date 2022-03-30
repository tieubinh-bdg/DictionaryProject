#include "Dictionary.h"
#include <iostream>
using namespace std;

Dictionary::Dictionary() {
	this->list = {};
}

Dictionary::~Dictionary() {
	//vector<Item*>().swap(this->list); //Way 1
	//list.shrink_to_fit();	//Way 2
	//loop Way 3
	for (int i = 0; i < this->list.size(); i++) {
		delete this->list[i];
	}

}

void Dictionary::Display() {
	for (auto x : this->list) {
		cout << "{ " << x->key << ", " << x->value << " }" << endl;
	}

}

void Dictionary::Add(string key, string value) {
	Item* newItem = new Item(key, value);
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

void Dictionary::Clear() {
	this->list.clear();
}

void Dictionary::Remove(string key) {
	for (int i = 0; i < this->list.size(); i++)
	{
		if (this->list[i]->key == key) {
			delete this->list[i]; //release memory then erase
			this->list.erase(this->list.begin() + i);
			break;
		}
	}
}

bool Dictionary::ContainsKey(string key) {
	bool flag = false;
	for (auto x : this->list) {
		if (x->key == key) {
			flag = true;
			break;
		}
	}

	return flag;
}

bool Dictionary::ContainsValue(string value) {
	bool flag = false;
	for (auto x : this->list) {
		if (x->value == value) {
			flag = true;
			break;
		}
	}

	return flag;
}
