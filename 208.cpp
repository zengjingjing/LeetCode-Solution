/****************************************************************************************************
Solution:
考察前序树/字典树的概念，实现很容易，就是一个26叉树
******************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TrieNode 
{
public:
	// Initialize your data structure here.
	TrieNode()
	{
		for(int i = 0; i< 26; i++)
			children[i] = NULL;
		end = false;
	}


public:
	TrieNode *children[26];
	char ch;
	bool end;
};

class Trie 
{
public:
	Trie()
	{
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word)
	{
		if(search(word))return;
		int size = word.size();
		TrieNode * temp = root;
		for(int i = 0; i < size; i++)
		{
			int index = word[i] - 'a';
			if(temp->children[index] == NULL)
			{
				temp->children[index] = new TrieNode();
				temp->children[index]->ch = word[i];
			}
			temp = temp->children[index];			
		}
		temp->end = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) 
	{
		int size = word.size();
		TrieNode * temp = root;
		for(int i = 0; i < size; i++)
		{
			int index = word[i] - 'a';
			if(temp->children[index] != NULL && temp->children[index]->ch == word[i])
				temp = temp->children[index];
			else
				return false;
		}
		return temp->end;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix)
	{
		int size = prefix.size();
		TrieNode * temp = root;
		for(int i = 0; i < size; i++)
		{
			int index = prefix[i] - 'a';
			if(temp->children[index] != NULL && temp->children[index]->ch == prefix[i])
				temp = temp->children[index];
			else
				return false;
		}
		return true;
	}
	bool IsLeaf(TrieNode * node)
	{
		for(int i = 0; i < 26; i++)
			if(node->children[i] != NULL)
				return false;
		return true;
	}

private:
	TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");


void test()
{
	Trie trie;
	trie.insert("abc");
	if(trie.search("ab"))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	trie.insert("ab");
	if(trie.search("ab"))
		cout << "true" << endl;
	else
		cout << "false" << endl;

}

int main()
{
	test();
	system("pause");
	return 1;
}
