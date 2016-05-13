#include "util.hpp"
#include "DictionaryTrie.hpp"
#include <queue>

/* Create a new Dictionary that uses a Trie back end */
DictionaryTrie::DictionaryTrie(){
	root = nullptr;
}

/* Insert a word with its frequency into the dictionary.
 * Return true if the word was inserted, and false if it
 * was not (i.e. it was already in the dictionary or it was
 * invalid (empty string) */
bool DictionaryTrie::insert(std::string word, unsigned int freq)
{
	//if the word is already in the trie
	//then you dont have to insert it again
	if (find(word))
		return false;
	//empty strings are not inserted
	if (word.length() == 0)
		return false;
	//start at top
	TNode* current = root;
	bool isword;
	bool accepted = false;
	//go through each letter in the string
	for (unsigned int i = 0; i < word.length(); i++)
	{
		//if this is the end of the word
		isword = false;
		if (i == (word.length() - 1))
			isword = true;
		//get current character
		char currentChar = word.at(i);

		//if the root hasnt been assigned assign it to the first letter
		if (root == NULL) {
			root = new TNode(currentChar, isword, freq);
			current = root;
			
		}
		//keep on going through the list til a node is accepted
		//for the character
		
		while (true)
		{
			//if the last letter in the trie was accepted go down the middle
			//and update max Frequency
			if (accepted)
			{
				if(current->middle == NULL)
					current->middle = new TNode(currentChar, isword, freq);
				if (current->maxFreq < freq)
					current->maxFreq = freq;
				current = current->middle;
				accepted = false;
			}
			//if the current letter is less than the current node go left
			//update max frequency
			if (currentChar < current->text)
			{
				if (current->left == NULL)
					current->left = new TNode(currentChar, isword, freq);
				if (current->maxFreq < freq)
					current->maxFreq = freq;
				current = current->left;
			}
			//if the current letter is greater than the current node go right
			//update max frequency
			else if (currentChar > current->text)
			{
				if (current->right == NULL)
					current->right = new TNode(currentChar, isword, freq);
				if (current->maxFreq < freq)
					current->maxFreq = freq;
				current = current->right;
			}
			//the current letter is equal to the node, accept it
			//also check if this is the last letter, if so, this 
			//node denotes the end of a word
			else
			{
				if (isword) {
					current->isWord = true;
					current->freq = freq;
					current->wholeWord = word;
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
	for (unsigned int i = 0; i < word.length(); i++)
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
	return false;
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
	priority_queue<TNode *> que;
	priority_queue<TNode*, vector<TNode *>, TNodeComp> wordque;
	
	TNode* pre = findPrefix(prefix);
	if (pre == nullptr)
		return words;
	
	que.push(pre->middle);

	TNode* node;
	while (!que.empty())
	{
		node = que.top();
		que.pop();

		if (node->isWord)
		{
			wordque.push(node);
			if (wordque.size() == num_completions)
				break;
		}
		
		if (node->left != nullptr)
			que.push(node->left);
		if (node->middle != nullptr)
			que.push(node->middle);
		if (node->right != nullptr)
			que.push(node->right);
	}
	if (pre->isWord)
		wordque.push(pre);
	while (!wordque.empty() && words.size() < num_completions)
	{
		words.push_back(wordque.top()->wholeWord);
		wordque.pop();
	}
	return words;

}



/* Destructor */
DictionaryTrie::~DictionaryTrie(){
	deleteAll(root);
}

void DictionaryTrie::deleteAll(TNode * n)
{
	if (n == NULL)
		return;
	deleteAll(n->left);
	deleteAll(n->middle);
	deleteAll(n->right);
	delete n;
}

TNode * DictionaryTrie::findPrefix(std::string prefix)
{

	TNode* current = root;
	for (unsigned int i = 0; i < prefix.length(); i++)
	{

		char currentChar = prefix.at(i);
		while (true)
		{
			if (current == NULL) {
				return nullptr;
			}
			else if (currentChar < current->text) {
				current = current->left;
			}
			else if (currentChar > current->text) {
				current = current->right;
			}
			else {
				if (i == prefix.length() - 1)
					return current;

				current = current->middle;
				break;
			}

		}
	}
	return nullptr;
}

//bool TNode::operator<(const TNode & other) const
//{
//	if (other.text < text)
//		return true;
//}

TNode::TNode(char c, bool word, unsigned int fre)
{
	text = c;
	isWord = word;
	freq = fre;
	wholeWord = "";
	maxFreq = 0;
}

bool TNode::operator<(const TNode & other) const
{
	if (maxFreq != other.maxFreq)
		return maxFreq < other.maxFreq;
	return wholeWord < other.wholeWord;
}
