#include "util.hpp"
#include "DictionaryBST.hpp"

/* Create a new Dictionary that uses a BST back end */
DictionaryBST::DictionaryBST(){}

/* Insert a word into the dictionary. */
bool DictionaryBST::insert(std::string word)
{
	bool test;
	if (find(word))
		return false;

	btree.insert(word);
	return true;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryBST::find(std::string word) const
{

	set<string>::iterator iter = btree.find(word);
	if (iter == btree.end())
		return false;
	return true;
}

/* Destructor */
DictionaryBST::~DictionaryBST(){}
