#include <structures.h>
#include "HashTable.h"

template <typename K, typename V>
HashNode<K, V>::HashNode(const K& key, const V& value)
    : m_key(key)
    , m_value(value)
    , m_next(nullptr) {
}

template <typename K, typename V>
HashNode<K, V>::~HashNode() {
    m_next = nullptr;
}

// ----------------------------------------------------------------------------
template <typename K, typename V, typename F>
HashTable<K, V, F>::HashTable(size_t size)
    : m_size(size)
    , m_table(new HashNode<K, V>*[size])
    , m_hash_fun() {
}

template <typename K, typename V, typename F>
HashTable<K, V, F>::~HashTable() {
    for (size_t i = 0; i < m_size; ++i) {
        HashNode<K, V>* entry = m_table[i];
        while (entry != nullptr) {
            HashNode<K, V>* prev = entry;
            entry = entry->getNext();
            delete prev; prev = nullptr;
        }
        m_table[i] = nullptr;
    }
    delete [] m_table; m_table = nullptr;
}

template <typename K, typename V, typename F>
const V& HashTable<K, V, F>::operator[](const K& key) const {
    auto position = m_hash_fun(key);
    HashNode<K, V>* entry = m_table[position];
    while (entry != nullptr) {
        if (entry->getKey() == key) {
            return entry->getValue();
        }
        entry = entry->getNext();
    }
    throw NoSuchElementException();
}

template <typename K, typename V, typename F>
V& HashTable<K, V, F>::operator[](const K &key) {
    auto position = m_hash_fun(key);
    HashNode<K, V>* entry = m_table[position];
    while (entry != nullptr) {
        if (entry->getKey() == key) {
            return entry->getValue();
        }
        entry = entry->getNext();
    }
    throw NoSuchElementException();
}

template <typename K, typename V, typename F>
void HashTable<K, V, F>::put(const K& key, const V& value) {
    auto position = m_hash_fun(key);
    HashNode<K, V>* prev = nullptr;
    HashNode<K, V>* entry = m_table[position];

    while (entry != nullptr && entry->getKey() != key) {
        prev = entry;
        entry = entry->getNext();
    }

    if (entry == nullptr) {
        entry = new HashNode<K, V>(key, value);
        if (prev == nullptr) {
            m_table[position] = entry;
        } else {
            prev->setNext(entry);
        }
    } else {
        entry->setValue(value);
    }
}

template <typename K, typename V, typename F>
void HashTable<K, V, F>::remove(const K& key) {
    auto position = m_hash_fun(key);
    HashNode<K, V>* prev = nullptr;
    HashNode<K, V>* entry = m_table[position];

    while (entry != nullptr && entry->getKey() != key) {
        prev = entry;
        entry = entry->getNext();
    }

    if (entry == nullptr) {
        // key not found
        return;
    } else {
        if (prev == nullptr) {
            // remove first bucket
            m_table[position] = entry->getNext();
        } else {
            prev->setNext(entry->getNext());
        }
        delete entry;
    }
}
