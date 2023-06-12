#ifndef EXAM_PREP_STRINGPAIR_H
#define EXAM_PREP_STRINGPAIR_H

#include "Pair.h"

const char* STRING_PAIR = "(StringPair)";

class StringPair : public Pair<char*> {
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

    char* toString() override {
        char* res = new char[strlen(STRING_PAIR)+SEPARATORS_SIZE+ strlen(m_key)+ strlen(m_value) + 1];
        strcpy(res, STRING_PAIR);
        strcat(res, LEFT_SEPARATOR);
        strcat(res,m_key);
        strcat(res, MID_SEPARATOR);
        strcat(res,m_value);
        strcat(res, RIGHT_SEPARATOR);
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
