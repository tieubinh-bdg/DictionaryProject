#pragma once
#include <string>
#include <vector>
#include <iostream>;
using namespace std;

struct Item {
	string key;
	string value;
	Item(string key, string value) {
		this->key = key;
		this->value = value;
	}

};

class Dictionary {
private:
	vector<Item*> list;
public:
	Dictionary();
	~Dictionary();
	void Display();
	void Add(string key, string value);
	void Clear();
	void Remove(string key);
	bool ContainsKey(string key);
	bool ContainsValue(string key);
};

