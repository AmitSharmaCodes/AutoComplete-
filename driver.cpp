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
//		in.open("C:\\Users\\ashar\\Downloads\\shuffled_freq_dict.txt", ios::binary);
//		Utils::load_dict(dic, in, 120000);
//	
//	auto words = dic.predictCompletions("a", 10);
//	for (string s : words)
//		cout << s << endl;
//
//
//
//	return 0;
//}