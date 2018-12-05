#ifndef SFF_HASH_TABLE_H_
#define SFF_HASH_TABLE_H_

#include "constants.h"
#include "types.h"

template <typename K, typename V>
class HashNode final {
public:
    HashNode(const K& key, const V& value);
    ~HashNode();

    inline const K& getKey() const { return m_key; }
    inline const V& getValue() const { return m_value; }
    inline HashNode* const getNext() const { return m_next; }

    inline void setValue(const V& value) { m_value = value; }
    inline void setNext(HashNode* const next) { m_next = next; }

private:
    K m_key;
    V m_value;
    HashNode* m_next;  // next node with the same key
};

// ----------------------------------------------------------------------------
template <typename K>
struct HashFun {
    inline size_t operator()(const K& key) const {
        return reinterpret_cast<size_t>(key) % TABLE_SIZE;
    }
};

template <>
struct HashFun<Key> {
    inline size_t operator()(const Key& key) const {
        return (key - '0') % TABLE_SIZE;
    }
};

// ----------------------------------------------------------------------------
template <typename K, typename V, typename F = HashFun<K>>
class HashTable final {
public:
    HashTable(size_t size = TABLE_SIZE);
    virtual ~HashTable();

    const V& operator [](const K& key) const;
    V& operator [](const K& key);

    void put(const K& key, const V& value);
    void remove(const K& key);

private:
    size_t m_size;
    HashNode<K, V>** m_table;
    F m_hash_fun;
};

#endif  // SFF_HASH_TABLE_H_
