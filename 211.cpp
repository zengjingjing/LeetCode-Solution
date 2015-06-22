/****************************************************************************************************
Solution:
考察前序树/字典树的概念，实现很容易，就是一个26叉树
深度优先遍历，我觉得我还是要总结一下，这一次虽然一次AC，但是感觉总是要想好几分钟才能弄清楚。
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


class WordDictionary 
{
public:

	
	WordDictionary()
	{
		root = new TrieNode();
	}
	
	// Adds a word into the data structure.
	void addWord(string word)
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

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word)
	{
		
		return JudgeExist(root, word, 0);
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

	bool JudgeExist(TrieNode* root, const string& word, int start)
	{
		if(start == word.size())
		{
			return root->end;
		}
		else
		{
			if(word[start] != '.')
			{
				int index = word[start] - 'a';
				if(root->children[index] == NULL || root->children[index]->ch != word[start])
					return false;
				else
					return JudgeExist(root->children[index], word, start + 1);

			}
			else
			{
				bool flag = false;
				for(int i = 0; i < 26; i++)
				{
					if(root->children[i])
						flag = flag || JudgeExist(root->children[i], word, start + 1); 
				}
				return flag;
			}
		}
	}


private:
	TrieNode* root;
};


void test()
{
	WordDictionary dict;
	dict.addWord("abc");
	if(dict.search("ab.."))
		cout << "true" << endl;
	else
		cout << "false" << endl;
	dict.addWord("ab");
	if(dict.search("ab"))
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
