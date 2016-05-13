#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "DictionaryBST.hpp"
#include "DictionaryHashtable.hpp"
#include "DictionaryTrie.hpp"
#include "util.hpp"
using namespace std;

int main(int argc, char *argv[]) {

	if (argc < 5) {
		std::cout << "Incorrect number of arguments." << std::endl;
		exit(-1);
	}

	unsigned int min_size = atoi(argv[1]);
	unsigned int step_size = atoi(argv[2]);
	unsigned int num_iterations = atoi(argv[3]);
	string dictfile(argv[4]);
	ifstream in;

	in.open(dictfile, ios::binary);
	cout << "DictionaryTrie" << endl;
	for (int i = 0; i < num_iterations; i++)
	{
		DictionaryTrie dic;
		Utils::load_dict(dic, in, min_size + i * step_size);
		Timer time;
		time.begin_timer();
		for (int i = 0; i < 1000; i++) {
			dic.find("blasearcv");
			dic.find("bla32r");
			dic.find("sea2rcv");
			dic.find("zdfarcv");
			dic.find("aerq34");
			dic.find("..sdf");
			dic.find(";+df");
			dic.find("myma,oe");
			dic.find("hilolerskatesnowords");
			dic.find("justnonsensecannotbefound");
		}
		long long done = time.end_timer();
		done = done / 1000;
		cout << min_size + i * step_size << "\t" << done << endl;
	}
	in.close();
	cout << endl;

	in.open(dictfile, ios::binary);
	cout << "DictionaryBST" << endl;
	for (int i = 0; i < num_iterations; i++)
	{		
		DictionaryBST dic;
		Utils::load_dict(dic, in, min_size + i * step_size);
		Timer time;
		time.begin_timer();
		for (int i = 0; i < 1000; i++) {
			dic.find("blasearcv");
			dic.find("bla32r");
			dic.find("sea2rcv");
			dic.find("zdfarcv");
			dic.find("aerq34");
			dic.find("..sdf");
			dic.find(";+df");
			dic.find("myma,oe");
			dic.find("hilolerskatesnowords");
			dic.find("justnonsensecannotbefound");
		}
		long long done = time.end_timer();
		done = done / 1000;
		cout << min_size + i * step_size << "\t" << done << endl;
	}
	in.close();
	cout << endl;

	in.open(dictfile, ios::binary);
	cout << "DictionaryHashtable" << endl;
	for (int i = 0; i < num_iterations; i++)
	{
		DictionaryHashtable dic;
		Utils::load_dict(dic, in, min_size + i * step_size);
		Timer time;
		time.begin_timer();
		for (int i = 0; i < 1000; i++) {
			dic.find("blasearcv");
			dic.find("bla32r");
			dic.find("sea2rcv");
			dic.find("zdfarcv");
			dic.find("aerq34");
			dic.find("..sdf");
			dic.find(";+df");
			dic.find("myma,oe");
			dic.find("hilolerskatesnowords");
			dic.find("justnonsensecannotbefound");
		}
		long long done = time.end_timer();
		done = done / 1000;
		cout << min_size + i * step_size << "\t" << done << endl;
	}
	in.close();





	return 0;
}