#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename V>
class MapNode
{
public:
    string key;
    V value;
    MapNode *next;

    MapNode(string key, V value) : key(key), value(value), next(nullptr) {}
    ~MapNode() { delete next; }
};

template <typename V>
class mymap
{

    MapNode<V> **buckets;
    int count;
    int numBuckets;

    int getBucketIndex(string key)
    {
        int hashCode = 0;
        int base = 1;
        int p = 37;

        for (int i = key.size(); i >= 0; i--)
        {
            hashCode += key[i] * base;
            base = base * p;
            hashCode = hashCode % numBuckets;
            base = base * numBuckets;
        }
        return hashCode % numBuckets;
    }

    void rehash()
    {
        MapNode<V> **temp = buckets;
        buckets = new MapNode<V> *[2 * numBuckets];
        for (int i = 0; i < 2 * numBuckets; i++)
        {
            buckets[i] = nullptr;
        }
        int oldBucketSize = numBuckets;
        numBuckets *= 2;
        count = 0;
        for (int i = 0; i < oldBucketSize; i++)
        {
            MapNode<V> *head = temp[i];
            while (head != nullptr)
            {
                string key = head->key;
                V val = head->value;
                insert(key, val);
                head = head->next;
            }
        }

        for (int i = 0; i < oldBucketSize; i++)
        {
            delete temp[i];
        }

        delete[] temp;
    }

public:
    mymap()
    {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V> *[numBuckets];
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = nullptr;
        }
    }

    ~mymap()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i];
        }
        delete[] buckets;
    }

    int size()
    {
        return count;
    }

    V getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];

        while (head != nullptr)
        {
            if (head->key == key)
            {

                return head->value;
            }
            head = head->next;
        }

        return 0;
    }

    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];

        while (head != nullptr)
        {
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        MapNode<V> *newNode = new MapNode<V>(key, value);
        newNode->next = buckets[bucketIndex];
        buckets[bucketIndex] = newNode;
        count++;

        double loadFactor = ((1.0 * count) / numBuckets);
        if (loadFactor > 0.7)
        {
            rehash();
        }
    }

    V remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];

        MapNode<V> *prevNode = head;

        if (head)
        {
            if (head->key == key)
            {
                buckets[bucketIndex] = head->next;
                V headVal = head->value;
                head->next = nullptr;
                delete head;
                count--;
                return headVal;
            }
            else
            {
                head = head->next;
            }
        }

        while (head != nullptr)
        {
            if (head->key == key)
            {
                prevNode->next = head->next;
                V headVal = head->value;
                head->next = nullptr;
                delete head;
                count--;
                return headVal;
            }
            prevNode = head;
            head = head->next;
        }
        return 0;
    }

    double getLoadFactor()
    {
        return (1.0 * count) / numBuckets;
    }
};

int main()
{
    mymap<int> ourmap;
    for (int i = 0; i < 10; i++)
    {

        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = i + 1;
        ourmap.insert(key, value);
        cout << ourmap.getLoadFactor() << endl;
    }

    cout << ourmap.size() << endl;

    ourmap.remove("abc1");
    ourmap.remove("abc6");
    for (int i = 0; i < 10; i++)
    {

        char c = '0' + i;
        string key = "abc";
        key = key + c;
        cout << "Key" << " " << key << " " << "Value" << " " << ourmap.getValue(key) << endl;
    }
    cout << ourmap.size() << endl;
}