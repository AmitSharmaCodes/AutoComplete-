#include "util.hpp"
#include "DictionaryTrie.hpp"

/* Create a new Dictionary that uses a Trie back end */
DictionaryTrie::DictionaryTrie() : root(0){}

/* Insert a word with its frequency into the dictionary.
 * Return true if the word was inserted, and false if it
 * was not (i.e. it was already in the dictionary or it was
 * invalid (empty string) */
bool DictionaryTrie::insert(std::string word, unsigned int freq)
{
	if (find(word))
		return false;

	//start at top
	TNode* current = root;
	bool accepted = false;
	bool isword;
	//go through each letter in the string
	for (int i = 0; i < word.length(); i++)
	{
		//if this is the end of the word
		isword = false;
		if (i == (word.length() - 1))
			isword = true;
		//get current character
		char currentChar = word.at(i);

		if (root == NULL) {
			root = new TNode(currentChar, isword);
			current = root;
			
		}
		//keep on going through the list til a node is accepted
		//for the character
		while (true)
		{
			if (accepted)
			{
				if(current->middle == NULL)
					current->middle = new TNode(currentChar, isword, freq);
				current = current->middle;
				accepted = false;
			}

			if (currentChar < current->text)
			{
				if (current->left == NULL)
					current->left = new TNode(currentChar, isword, freq);
				current = current->left;
			}
			else if (currentChar > current->text)
			{
				if (current->right == NULL)
					current->right = new TNode(currentChar, isword, freq);
				current = current->right;
			}
			else
			{
				if (isword) {
					current->isWord = true;
					current->freq = freq;
				}
				accepted = true;
				break;
			}
		}
	}
	return true;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryTrie::find(std::string word) const
{
	TNode* current = root;
	for (int i = 0; i < word.length(); i++)
	{
		bool isword = false;
		if (i == word.length() - 1)
			isword = true;

		char currentChar = word.at(i);
		while (true)
		{
			if (current == NULL) {
				return false;
			}
			else if (currentChar < current->text) {
				current = current->left;
			}
			else if (currentChar > current->text) {
				current = current->right;
			}
			else {
				if (isword && current->isWord)
					return true;

				current = current->middle;
				break;
			}
		
		}
	}
}

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
std::vector<std::string> DictionaryTrie::predictCompletions(std::string prefix, unsigned int num_completions)
{
  std::vector<std::string> words;
  return words;
}

/* Destructor */
DictionaryTrie::~DictionaryTrie(){}

//bool TNode::operator<(const TNode & other) const
//{
//	if (other.text < text)
//		return true;
//}

