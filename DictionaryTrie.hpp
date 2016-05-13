/**
 *  CSE 100 PA3 C++ Autocomplete
 *  Authors: Jor-el Briones, Christine Alvarado
 */

#ifndef DICTIONARY_TRIE_HPP
#define DICTIONARY_TRIE_HPP

#include <vector>
#include <string>
#include <unordered_map>

/**
 *  The class for a dictionary ADT, implemented as a trie
 *  You may implement this class as either a mulit-way trie
 *  or a ternary search trie, but you must use one or the other.
 *
 */
using namespace std;


class TNode
{

public:

	bool isWord;
	TNode* left;
	TNode* right;
	TNode* middle;
	char text;
	string wholeWord;
	unsigned int maxFreq;
	unsigned int freq;

	TNode(char c, bool word, unsigned int freq = 0);

	// Less-than comparison, so TNode will work in std::priority_queue
	
	bool operator<(const TNode& other) const;
};

//This is a function class for the priority queue that handles
//the words themselves, where frequency is important
//usually only maxfreq is compared
class TNodeComp
{
public:
	bool operator()(TNode* lhs, TNode* rhs) const {
		return lhs->freq > rhs->freq;
	}
};

class TNodeCompMaxFreq
{
public:
	bool operator()(TNode* lhs, TNode* rhs) const {
		return lhs->maxFreq < rhs->maxFreq;
	}
};

class DictionaryTrie
{
public:

  /* Create a new Dictionary that uses a Trie back end */
  DictionaryTrie();

  /* Insert a word with its frequency into the dictionary.
   * Return true if the word was inserted, and false if it
   * was not (i.e. it was already in the dictionary or it was
   * invalid (empty string) */
  bool insert(std::string word, unsigned int freq);

  /* Return true if word is in the dictionary, and false otherwise */
  bool find(std::string word) const;

  /* Return up to num_completions of the most frequent completions
   * of the prefix, such that the completions are words in the dictionary.
   * These completions should be listed from most frequent to least.
   * If there are fewer than num_completions legal completions, this
   * function returns a vector with as many completions as possible.
   * If no completions exist, then the function returns a vector of size 0.
   * The prefix itself might be included in the returned words if the prefix
   * is a word (and is among the num_completions most frequent completions
   * of the prefix)
   */
  std::vector<std::string>
  predictCompletions(std::string prefix, unsigned int num_completions);

  /* Destructor */
  ~DictionaryTrie();


  

private:
	TNode* root;

	static void deleteAll(TNode* n);
	TNode* findPrefix(std::string prefix);
};



#endif // DICTIONARY_TRIE_HPP
