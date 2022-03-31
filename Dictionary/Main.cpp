#include "Main.h"

int main() {
	Dictionary<int, string>* dic = new Dictionary<int, string>();
	dic->Add(1, "One");
	dic->Add(2, "Two");
	dic->Add(3, "Three");
	dic->Add(2, "Four");
	dic->Display();
	cout << "Exist Key: " << (dic->ContainsKey(3) ? "Exist" : "Not exist") << endl;
	cout << "Exist Value: " << (dic->ContainsValue("3") ? "Exist" : "Not exist") << endl;
	dic->Remove(1);
	dic->Display();
	dic->Clear();
	dic->Display();

	delete dic;
}
