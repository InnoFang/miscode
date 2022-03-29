/*
 * @FileName   : skiplist.hpp 
 * @CreateAt   : 2022/3/28
 * @Author     : Inno Fang
 * @Email      : innofang@outlook.com
 * @Description: 
 */

#ifndef KV_LITE_SKIP_LIST_HPP
#define KV_LITE_SKIP_LIST_HPP

#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <mutex>
#include <fstream>

namespace inno {

std::string STORE_FILE = "store/dumpFile";
std::string delimiter = ":";
std::mutex mtx;

template <typename K, typename V>
class SkipList {
public:
    class Node {
    public:
        friend class SkipList;

    public:
        Node() = default;
        Node(K k, V v, int);
        ~Node() = default;
        K get_key() const;
        V get_value() const;
        void set_value(V);
        int get_level() const;

    private:
        K _key;
        V _value;
        int _level;
        Node **_forward;      // linear array to hold pointers to next node of different level
    };

public:
    explicit SkipList(int);
    ~SkipList();
    int get_random_level();
    int insert_element(K, V);
    void display_list();
    bool search_element(K);
    bool delete_element(K);
    void dump_file();
    void load_file();
    int size() const;

private:
    void get_key_value_from_string(const std::string &str, std::string *key, std::string *value);
    bool is_valid_string(const std::string &str);

private:
    int _max_level;             // maximum level of the skip list
    int _element_count;         // current element count of this skip list
    int _skip_list_level;       // current level of skip list

    Node *_header;              // pointer to header node

    std::ofstream _file_writer;
    std::ifstream _file_reader;
};

template<typename K, typename V>
SkipList<K, V>::Node::Node(const K k, const V v, int level)
    : _key(k)
    , _value(v)
    , _level(level) {

    _forward = new Node*[level + 1];
    memset(_forward, 0, sizeof(Node*) * (level + 1));
}

template<typename K, typename V>
K SkipList<K, V>::Node::get_key() const {
    return _key;
}

template<typename K, typename V>
V SkipList<K, V>::Node::get_value() const {
    return _value;
}

template<typename K, typename V>
void SkipList<K, V>::Node::set_value(V value) {
    _value = value;
}

template<typename K, typename V>
int SkipList<K, V>::Node::get_level() const {
    return _level;
}


template<typename K, typename V>
SkipList<K, V>::SkipList(int max_level)
    : _max_level(max_level)
    , _skip_list_level(0)
    , _element_count(0) {

    K k;
    V v;
    _header = new Node(k, v, _max_level);
}

template<typename K, typename V>
SkipList<K, V>::~SkipList() {
    if (_file_writer.is_open()) {
        _file_writer.close();
    }
    if (_file_reader.is_open()) {
        _file_writer.close();
    }
    delete _header;
}

template<typename K, typename V>
int SkipList<K, V>::get_random_level() {
    int k = 1;
    while (rand() % 2) {
        ++ k;
    }
    k = (k < _max_level) ? k : _max_level;
    return k;
}

template<typename K, typename V>
int SkipList<K, V>::insert_element(K key, V value) {
    mtx.lock();

    Node *current = _header;

    Node *update[_max_level + 1];
    memset(update, 0, sizeof(Node*) * (_max_level + 1));

    for (int i = _skip_list_level; i >= 0; -- i) {
        while (current->_forward[i] != nullptr && current->_forward[i]->get_key() < key) {
            current = current->_forward[i];
        }
        update[i] = current;
    }

    current = current->_forward[0];

    if (current != nullptr && current->get_key() == key) {
        std::cout << "key: " << key << ", exists" << std::endl;
        mtx.unlock();
        return 1;
    }

    if (current == nullptr || current->get_key() != key) {
        int random_level = get_random_level();

        if (random_level > _skip_list_level) {
            for (int i = _skip_list_level + 1; i < random_level + 1; ++ i) {
                update[i] = _header;
            }
            _skip_list_level = random_level;
        }

        Node* inserted_node = new Node(key, value, random_level);

        for (int i = 0; i <= random_level; ++ i) {
            inserted_node->_forward[i] = update[i]->_forward[i];
            update[i]->_forward[i] = inserted_node;
        }
        std::cout << "Successfully inserted key: " << key << ", value: " << value << std::endl;
        ++ _element_count;
    }

    mtx.unlock();
    return 0;
}

template<typename K, typename V>
void SkipList<K, V>::display_list() {
    std::cout << "\n*****Skip List*****" << std::endl;
    for (int i = 0; i <= _skip_list_level; ++ i) {
        Node *node = _header->_forward[i];
        std::cout << "Level " << i << ": ";
        while (node != nullptr) {
            std::cout << node->get_key() << ":" << node->get_value() << ";";
            node = node->_forward[i];
        }
        std::cout << std::endl;
    }
}

template<typename K, typename V>
bool SkipList<K, V>::search_element(K key) {
    std::cout << "search_element -------------------" << std::endl;
    Node *current = _header;

    for (int i = _skip_list_level; i >= 0; -- i) {
        while (current->_forward[i] && current->_forward[i]->get_key() < key) {
            current = current->_forward[i];
        }
    }

    current = current->_forward[0];

    if (current && current->get_key() == key) {
        std::cout << "Found key: " << key << ", value: " << current->get_value() << std::endl;
        return true;
    }

    std::cout << "Not Found Key:" << key << std::endl;
    return false;
}

template<typename K, typename V>
bool SkipList<K, V>::delete_element(K key) {
    mtx.lock();
    Node *current = this->_header;
    Node *update[_max_level + 1];
    memset(update, 0, sizeof(Node*)* (_max_level + 1));

    for (int i = _skip_list_level; i >= 0; -- i) {
        while (current->_forward[i] != nullptr && current->_forward[i]->get_key() < key) {
            current = current->_forward[i];
        }
        update[i] = current;
    }

    current = current->_forward[0];
    if (current != nullptr && current->get_key() == key) {
        for (int i = 0; i <= _skip_list_level; ++ i) {
            if (update[i]->_forward[i] != nullptr) {
                break;
            }

            update[i]->_forward[i] = current->_forward[i];
        }

        while (_skip_list_level > 0 && _header->_forward[_skip_list_level] == 0) {
            -- _skip_list_level;
        }

        std::cout << "Successfully deleted key " << key << std::endl;
        -- _element_count;
    }

    mtx.unlock();
    return false;
}

template<typename K, typename V>
void SkipList<K, V>::dump_file() {
    std::cout << "dump_file ----------------" << std::endl;
    _file_writer.open(STORE_FILE);
    Node *node = _header->_forward[0];

    while (node != nullptr) {
        _file_writer << node->get_key() << ":" << node->get_value() << "\n";
        std::cout << node->get_key() << ":" << node->get_value() << ";\n";
        node = node->_forward[0];
    }

    _file_writer.flush();
    _file_writer.close();
}

template<typename K, typename V>
void SkipList<K, V>::load_file() {
    std::cout << "load_file ---------------" << std::endl;
    _file_reader.open(STORE_FILE);
    std::string line;
    std::string *key = new std::string();
    std::string *value = new std::string();
    while (getline(_file_reader, line)) {
        get_key_value_from_string(line, key, value);
        if (key->empty() || value->empty()) {
            continue;
        }
        insert_element(*key, *value);
        std::cout << "key: " << *key << "value:" << *value << std::endl;
    }
    _file_reader.close();
}

template<typename K, typename V>
int SkipList<K, V>::size() const {
    return _element_count;
}

template<typename K, typename V>
void SkipList<K, V>::get_key_value_from_string(const std::string &str, std::string *key, std::string *value) {
    if (!is_valid_string(str)) {
        return;
    }
    size_t d = str.find(delimiter);
    *key = str.substr(0, d);
    *value = str.substr(d + 1, str.length());
}

template<typename K, typename V>
bool SkipList<K, V>::is_valid_string(const std::string &str) {
    return !str.empty() && str.find(delimiter) != std::string::npos;
}


}

#endif //KV_LITE_SKIP_LIST_HPP
