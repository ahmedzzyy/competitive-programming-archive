#include <unordered_map>

using namespace std;

// lruPtr -> ...nodes -> mostRecentlyUsedPtr
// map key -> nodePtr

class Node
{
public:
    int key;
    int value;
    Node *prev;
    Node *next;

    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
private:
    int capacity;
    unordered_map<int, Node *> cache;
    Node *leastRecentlyUsed;
    Node *mostRecentlyUsed;

    void remove(Node *node)
    {
        Node *prevNode = node->prev;
        Node *nextNode = node->next;
        if (prevNode)
            prevNode->next = nextNode;
        if (nextNode)
            nextNode->prev = prevNode;
    }

    void insertAtFront(Node *node)
    {
        Node *previousNode = mostRecentlyUsed->prev;

        previousNode->next = node;
        node->prev = previousNode;

        node->next = mostRecentlyUsed;
        mostRecentlyUsed->prev = node;
    }

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        cache.clear();

        leastRecentlyUsed = new Node(-1, -1);
        mostRecentlyUsed = new Node(-1, -1);

        leastRecentlyUsed->next = mostRecentlyUsed;
        mostRecentlyUsed->prev = leastRecentlyUsed;
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end())
            return -1;

        Node *node = cache[key];
        remove(node);
        insertAtFront(node);

        return node->value;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            Node *node = cache[key];
            node->value = value;
            remove(node);
            insertAtFront(node);
            return;
        }

        Node *newNode = new Node(key, value);
        insertAtFront(newNode);
        cache[key] = newNode;

        if (cache.size() > capacity)
        {
            Node *lruNode = leastRecentlyUsed->next;
            remove(lruNode);
            cache.erase(lruNode->key);
            delete lruNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */