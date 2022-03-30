#include "Main.h"

int main() {
	Dictionary* list = new Dictionary();
	list->Add("1", "One");
	list->Add("3", "Three");
	list->Add("2", "Two");
	list->Add("2", "Four");
	list->Display();
	cout << "Exist Key: " << list->ContainsKey("3") << endl;
	cout << "Exist Value: " << list->ContainsValue("3") << endl;
	//list->Remove("2");
	//list->Display();
	//list->Clear();
	//list->DisPlay();

	delete list;
}