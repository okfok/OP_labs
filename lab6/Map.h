#ifndef LAB6_MAP_H
#define LAB6_MAP_H

#include <iostream>
#include <utility>


template<typename Data>
class Node {
    std::string _key;
    Data _data;

public:

    Node(std::string key, Data data) : _key(std::move(key)), _data(data) {};

    Data value() { return _data; }

    std::string key() { return _key; }

};

template<typename Data>
class Map {
    int _size;
    int _count = 0;
    Node<Data> **_nodes;
public:
    // Constructors
    explicit Map(int size = 50);

    Map(Map &);

    ~Map();
    // hash

    int hash(const std::string &key);
    // data editing

    void resize(int size);

    void clear();

    void add(std::string key, Data data);

    void add(Node<Data> *node);

    Data find(std::string key);

    Data del(std::string key);

    // Iterator

    class Iterator {
        Node<Data> **m_ptr;

    public:
        explicit Iterator(Node<Data> **ptr) : m_ptr(ptr) {}

        Node<Data> *operator*() { return *m_ptr; }

        Node<Data> **operator->() { return m_ptr; }

        Node<Data> *get() { return *m_ptr; }


        Iterator &operator++();

        Iterator &operator++(int);

        void next() { operator++(); }


        friend bool operator==(const Iterator &a, const Iterator &b) { return a.m_ptr == b.m_ptr; };

        friend bool operator!=(const Iterator &a, const Iterator &b) { return a.m_ptr != b.m_ptr; };
    };

    Iterator begin();

    Iterator end();


};


#endif //LAB6_MAP_H