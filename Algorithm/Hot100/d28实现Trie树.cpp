#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class TrieNode
{
public:
    TrieNode()
        : is_end(false)
    { }
    unordered_map<char, TrieNode *> child;
    bool is_end;
};

class Trie
{
public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode* node = root;
        for(auto& c : word)
        {
            auto it = node->child.find(c);
            if(it != node->child.end())
                // 这个字符已经存在，移动到这个节点
                node = it->second;
            else
            {
                // 添加节点索引并移动
                node->child[c] = new TrieNode();
                node = node->child[c];
            }
        }
        // 给最后一个节点添加标记
        node->is_end = true;
    }

    bool search(string word)
    {
        TrieNode* node = SearchPrefix(word);
        return node != nullptr && node->is_end;
    }

    bool startsWith(string prefix)
    {
        return SearchPrefix(prefix) != nullptr;
    }

private:
    TrieNode* SearchPrefix(string prefix)
    {
        TrieNode* node = root;
        for(auto& c : prefix)
        {
            auto it = node->child.find(c);
            if(it == node->child.end())
                return nullptr;
            node = node->child[c];
        }
        return node;
    }

private:
    TrieNode *root; // 初始节点为空
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */