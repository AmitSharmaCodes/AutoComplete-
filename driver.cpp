#include <iostream>
#include "DictionaryTrie.hpp"
using namespace std;

int main()
{
	DictionaryTrie dic;
	dic.insert("apple", 5);
	dic.insert("bat", 5);
	dic.insert("blue", 5);
	if (dic.find("apple"))
		cout << "it works" << endl;
	if (dic.find("bat"))
		cout << "it works" << endl;
	if (dic.find("blue"))
		cout << "it works" << endl;
	return 0;
}