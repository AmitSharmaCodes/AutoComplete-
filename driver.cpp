//#include <iostream>
//#include "DictionaryTrie.hpp"
//#include "DictionaryHashtable.hpp"
//#include "DictionaryBST.hpp"
//using namespace std;
//
//int main()
//{
//
//	DictionaryTrie dic;
//	DictionaryHashtable dic2;
//	DictionaryBST dic3;
//
//
//	dic.insert("apple", 400);
//	dic.insert("append", 400);
//	dic.insert("apply", 30);
//	dic.insert("ambiant", 20);
//	dic.insert("apollo", 1);
//	dic.insert("app", 1000);
//	dic.insert("and", 10);
//	dic.insert("bat", 5);
//	dic.insert("blue", 5);
//
//	auto words = dic.predictCompletions("a", 10);
//
//	for (string s : words)
//		cout << s << endl;
//	
//	if (dic.find("apple"))
//		cout << "apple found" << endl;
//	if (dic.find("bat"))
//		cout << "bat found" << endl;
//	if (dic.find("blue"))
//		cout << "blue found" << endl;
//	if (!dic.find("blu"))
//		cout << "blu is not found" << endl;
//
//	if (!dic.insert("apple", 5))
//		cout << "apple cannot be inserted again" << endl;
//
//
//	return 0;
//}