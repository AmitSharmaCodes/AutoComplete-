#include <iostream>
#include "DictionaryTrie.hpp"
#include "DictionaryHashtable.hpp"
#include "DictionaryBST.hpp"
using namespace std;

int main()
{

	DictionaryTrie dic;
	DictionaryHashtable dic2;
	DictionaryBST dic3;

	dic.insert("apple", 5);
	dic.insert("bat", 5);
	dic.insert("blue", 5);

	dic2.insert("apple");
	dic2.insert("bat");
	dic2.insert("blue");

	dic3.insert("apple");
	dic3.insert("bat");
	dic3.insert("blue");

	if (dic.find("apple"))
		cout << "it works" << endl;
	if (dic.find("bat"))
		cout << "it works" << endl;
	if (dic.find("blue"))
		cout << "it works" << endl;
	return 0;
}