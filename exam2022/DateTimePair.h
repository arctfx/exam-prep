#ifndef EXAM_PREP_DATETIMEPAIR_H
#define EXAM_PREP_DATETIMEPAIR_H

#include "DatePair.h"
#include "TimePair.h"

class DateTimePair : public DatePair, public TimePair {
public:
    DateTimePair(const char* key, char* date, char* time) : DatePair(key, date), TimePair(key, time) {

    }
    ~DateTimePair() {
        free();
    }
    DateTimePair(const DateTimePair& other) : DatePair(other), TimePair(other) {

    }
    DateTimePair& operator=(const DateTimePair& other) {
        free();
        this->copy(other.m_key, other.m_value);
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
