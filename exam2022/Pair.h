#ifndef EXAM_PREP_PAIR_H
#define EXAM_PREP_PAIR_H

#include <cstring>

template <typename T>
class Pair {
public:
    Pair() = default;
    virtual ~Pair() = 0;
    Pair(const Pair& other) = delete;
    Pair& operator=(const Pair& other) = delete;

protected:
    virtual void free() {
        delete[] m_key;
        m_key = nullptr;
    }

    virtual void copy(const char* _key, const T _value) = 0;

    //Полета
    char* m_key;
    T m_value;
};


#endif //EXAM_PREP_PAIR_H
