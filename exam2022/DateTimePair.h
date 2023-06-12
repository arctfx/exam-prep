#ifndef EXAM_PREP_DATETIMEPAIR_H
#define EXAM_PREP_DATETIMEPAIR_H

#include "DatePair.h"
#include "TimePair.h"

const char* DATE_TIME_PAIR = "(DateTimePair)";

class DateTimePair : public DatePair, public TimePair {
public:
    DateTimePair(const char* key, char* date, char* time) : DatePair(key, date), TimePair(key, time) {

    }
    ~DateTimePair() {
        free();
    }
    DateTimePair(const DateTimePair& other) : DatePair(other.m_key, other.m_value), TimePair(other.m_key, other.m_value) {

    }
    DateTimePair& operator=(const DateTimePair& other) {
        free();
        this->copy(other.m_key, other.m_value);
    }

    char* toString() override {
        char* res = new char[strlen(DATE_TIME_PAIR)+SEPARATORS_SIZE+ strlen(m_key)+ strlen(m_value) + 1];
        strcpy(res, DATE_TIME_PAIR);
        strcat(res, LEFT_SEPARATOR);
        strcat(res,m_key);
        strcat(res, MID_SEPARATOR);
        strcat(res,m_value);
        strcat(res, RIGHT_SEPARATOR);
    }

private:
    void free() override {
        delete[] m_key;
        m_key = nullptr;
    }
    void copy(const char* _key, char* _value) override = 0;
    void copy(const char* _key, char* _date, char* _time) {
        DatePair::copy(_key, _date);
        TimePair::copy(_key, _time);
    }
};


#endif //EXAM_PREP_DATETIMEPAIR_H
