//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include "DictionaryTrie.hpp"
//#include "DictionaryHashtable.hpp"
//#include "DictionaryBST.hpp"
//#include "util.hpp"
//
//using namespace std;
//
//int main()
//{
//
//	DictionaryTrie dic;
//	ifstream in;
//	
//	
//		in.open("C:\\Users\\ashar_000\\Desktop\\sd.txt", ios::binary);
//		Utils::load_dict(dic, in);
//		in.close();
//	auto words = dic.predictCompletions("o", 10);
//	auto words2 = dic.predictCompletionsExhaustive("o", 10);
//
//	/*dic.insert("a", 600);
//	dic.insert("app", 2);
//	dic.insert("apply", 3);
//	dic.insert("apples", 500);
//	dic.insert("appitite", 500);
//	dic.insert("abc", 700);
//	dic.insert("what", 5000);
//	dic.insert("apples and", 1000);*/
//	//for (string s : words)
//	//	cout << s << endl;
//	//cout << endl;
//	//for (string s : words2)
//	//	cout << s << endl;
//
//
//	return 0;
//}