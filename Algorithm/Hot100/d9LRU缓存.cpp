#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Node
{
public:
    Node(int num = 0) : val(num), next(nullptr), prev(nullptr) {}
    int val;
    int _key;
    Node *next;
    Node *prev;
};

class List
{
public:
    // 初始化双向链表
    List()
    {
        head->next = head;
        head->prev = head;
    }
    Node *GetRemove() { return head->next; }
    // 移除
    void Remove()
    {
        Node *remove = head->next;
        Node *Next = remove->next;
        head->next = Next;
        Next->prev = head;
        delete remove;
    }
    // 移动
    void Move(Node *node)
    {
        Node *tail = head->prev;
        if (tail == node)
            return;
        Node *left = node->prev;
        Node *right = node->next;
        left->next = right;
        right->prev = left;
        tail->next = node;
        node->prev = tail;
        node->next = head;
        head->prev = node;
    }
    // 插入
    void Insert(Node *newNode)
    {
        Node *tail = head->prev;

        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;

        head->prev = newNode;
    }

private:
    // 哨兵头节点
    Node *head = new Node(-1);
};

class LRUCache
{
public:
    LRUCache(int capacity) : _capacity(capacity), _len(0) {}

    int get(int key)
    {
        auto it = _mp.find(key);
        // 没找到，返回-1
        if (it == _mp.end())
            return -1;
        else
        {
            // 先移动
            _list.Move(it->second);
            return it->second->val;
        }
    }

    void put(int key, int value)
    {
        // 先看是不是已有的
        auto it = _mp.find(key);
        // 没有，要执行插入逻辑
        if (it == _mp.end())
        {
            _len++;
            // 新节点
            Node *newNode = new Node(value);
            newNode->_key = key;
            _mp[key] = newNode;
            if (_len > _capacity)
            {
                // 先移除
                _mp.erase(_list.GetRemove()->_key); //
                _list.Remove();
                _len--;
                // 后插入
                _list.Insert(newNode);
            }
            else
                _list.Insert(newNode); // 直接在结尾插入
        }
        // 已有，修改值，并移动到结尾
        else
        {
            // 修改
            it->second->val = value;
            // 移动
            _list.Move(it->second);
        }
    }

private:
    int _len;
    int _capacity;
    List _list;
    unordered_map<int, Node *> _mp;
};