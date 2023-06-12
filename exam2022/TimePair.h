#ifndef EXAM_PREP_TIMEPAIR_H
#define EXAM_PREP_TIMEPAIR_H

#include "Pair.h"

const char* DEFAULT_TIME = "00:00";

class TimePair : virtual protected Pair<char*> {
public:
    TimePair(const char* key, char* value) {
        m_key = new char[strlen(key) + 1];
        strcpy(m_key, key);

        if (!setValiTimed(value)) {
            m_value = new char[strlen(DEFAULT_TIME) + 1];
            strcpy(m_value, DEFAULT_TIME);
        }
    }

    ~TimePair() {
        free();
    }

    TimePair(const TimePair& other) {
        this->copy(other.m_key, other.m_value);
    }

    TimePair& operator=(const TimePair& other) {
        free();
        this->copy(other.m_key, other.m_value);
    }

protected:
    void copy(const char* _key, char* _value) override {
        m_key = new char[strlen(_key) + 1];
        strcpy(m_key, _key);

        m_value = new char[strlen(_value) + 1];
        strcpy(m_value, _value);
    }

private:
    bool setValiTimed(const char* Time) { //return false if the input Time is invalid
        //validation
        m_value = new char[strlen(Time) + 1];
        strcpy(m_value, Time);

        return true;
    }
};


#endif //EXAM_PREP_TIMEPAIR_H
