#include <iostream>

template <class K, class V>
struct pair{
    K key;
    V value;
};

template <class K, class V>
class Iterator {
    struct triplePair{
        K key;
        V value;
        int index;
    }triple;
    pair <K, V> *p;
    int index;
public:
    Iterator(pair <K, V> *p, int index) : p(p), index(index) {};
    bool operator!= (Iterator const it) {
        return p != it.p;
    }
    Iterator operator++(){
        index++;
        p++;
        return *this;
    }
    triplePair operator*() {
        triple.key = p->key;
        triple.value = p->value;
        triple.index = index;
        return triple;
    }
};

template <class K, class V>
class Map {
    pair<K, V> v[30];
    int size;
public:
    Map() {
        size = 0;
    }
    V& operator[] (K key) {
        for(int i = 0; i < size; i++) {
            if(v[i].key == key) {
                return v[i].value;
            }
        }
        v[size].key = key;
        v[size].value = {};
        size++;
        return v[size-1].value;
    }
    bool Get(const K& key, V& value) {
        for(int i = 0; i < size; i++) {
            if(v[i].key == key) {
                value = v[i].value;
                return true;
            }
        }
        return false;
    }
    bool Set(const K key, V value) {
        for(int i = 0; i < size; i++) {
            if(v[i].key == key) {
                v[i].value = value;
                return true;
            }
        }
        return false;
    }
    Iterator<K, V> begin() {
        Iterator<K, V> first(v, 0);
        return first;
    }
    Iterator<K, V> end() {
        Iterator<K, V> afterLast(v+size, size);
        return afterLast;
    }
    int Count() {
        return size;
    }
    void Clear() {
        size = 0;
    }
    bool Delete(const K& key) {
        for(int i = 0; i < size; i++) {
            if(v[i].key == key) {
                for(int j = i; j < size-1; j++) {
                  v[j] = v[j+1];
                }
                size--;
                return true;
            }
        }
        return false;
    }
    bool Exists(const K key) const {
        for(int i = 0; i < size; i++) {
            if(v[i].key == key) {
                return true;
            }
        }
        return false;
    }
    bool Includes(const Map<K,V>& map) {
//        for(int i = 0; i < size; i++) {
//            if(!map.Exists(v[i].key)) {
//                return false;
//            }
//        }
//        return true;
        for(int i = 0; i < map.size; i++) {
            bool isFound = false;
            for(int j = 0; j < size; j++) {
                if(v[j].key == map.v[i].key) {
                    isFound = true;
                    break;
                }
            }
            if(!isFound) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    const char *s;
    Map<int, const char *> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m.Set(10, "C--");
    m.Get(10, s);
    printf("%s\n", s);
    m.Delete(20);
    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m.Clear();
    printf("There are %d items in m\n", m.Count());
    m[10] = "C++";

    Map<int, const char *> b;
    b[10] = "C++";
    b[20] = "test";
    b[30] = "Poo";
    printf("%d", b.Includes(m));
    return 0;

}
