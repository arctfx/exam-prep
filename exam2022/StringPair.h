#ifndef EXAM_PREP_STRINGPAIR_H
#define EXAM_PREP_STRINGPAIR_H

#include "Pair.h"

class StringPair : protected Pair<char*> {
public:
    StringPair(const char* key, const char* value) {
        m_key = new char[strlen(key) + 1];
        strcpy(m_key, key);

        m_value = new char[strlen(value) + 1];
        strcpy(m_value, value);
    }
    ~StringPair() {
        this->free();
    }
    StringPair(const StringPair& other) {
        this->copy(other.m_key, other.m_value);
    }
    StringPair& operator=(const StringPair& other) {
        this->free();
        this->copy(other.m_key, other.m_value);
    }

protected:
    void free() override {
        delete[] m_key;
        m_key = nullptr;

        delete[] m_value;
        m_value = nullptr;
    }

    void copy(const char* _key, char* _value) override {
        m_key = new char[strlen(_key) + 1];
        strcpy(m_key, _key);

        m_value = new char[strlen(_value) + 1];
        strcpy(m_value, _value);
    }
};


#endif //EXAM_PREP_STRINGPAIR_H
