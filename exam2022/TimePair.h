#ifndef EXAM_PREP_TIMEPAIR_H
#define EXAM_PREP_TIMEPAIR_H

#include "Pair.h"

const char* TIME_PAIR = "(TimePair)";
const char* DEFAULT_TIME = "00:00";

class TimePair : virtual public Pair<char*> {
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

    char* toString() override {
        char* res = new char[strlen(TIME_PAIR)+SEPARATORS_SIZE+ strlen(m_key)+ strlen(m_value) + 1];
        strcpy(res, TIME_PAIR);
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
    bool setValiTimed(const char* Time) { //return false if the input Time is invalid
        //validation
        m_value = new char[strlen(Time) + 1];
        strcpy(m_value, Time);

        return true;
    }
};


#endif //EXAM_PREP_TIMEPAIR_H
