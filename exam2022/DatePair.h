#ifndef EXAM_PREP_DATEPAIR_H
#define EXAM_PREP_DATEPAIR_H

#include "Pair.h"

const char* DATE_PAIR = "(DatePair)";
const char* DEFAULT_DATE = "01.01.0001";

class DatePair : virtual public Pair<char*> {
public:
    DatePair(const char* key, char* value) {
        m_key = new char[strlen(key) + 1];
        strcpy(m_key, key);

        if (!setValidated(value)) {
            m_value = new char[strlen(DEFAULT_DATE) + 1];
            strcpy(m_value, DEFAULT_DATE);
        }
    }

    ~DatePair() {
        free();
    }

    DatePair(const DatePair& other) {
        this->copy(other.m_key, other.m_value);
    }

    DatePair& operator=(const DatePair& other) {
        free();
        this->copy(other.m_key, other.m_value);
    }

    char* toString() override {
        char* res = new char[strlen(DATE_PAIR)+SEPARATORS_SIZE+ strlen(m_key)+ strlen(m_value) + 1];
        strcpy(res, DATE_PAIR);
        strcat(res, LEFT_SEPARATOR);
        strcat(res,m_key);
        strcat(res, MID_SEPARATOR);
        strcat(res,m_value);
        strcat(res, RIGHT_SEPARATOR);
    }


protected:
    void copy(const char* _key, char* _value) override {
        m_key = new char[strlen(_key) + 1];
        strcpy(m_key, _key);

        m_value = new char[strlen(_value) + 1];
        strcpy(m_value, _value);
    }

private:
    bool setValidated(const char* date) { //return false if the input date is invalid
        //validation
        m_value = new char[strlen(date) + 1];
        strcpy(m_value, date);

        return true;
    }
};


#endif //EXAM_PREP_DATEPAIR_H
