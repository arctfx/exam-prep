#ifndef EXAM_PREP_DATEPAIR_H
#define EXAM_PREP_DATEPAIR_H

#include "Pair.h"

const char* DEFAULT_DATE = "01.01.0001";

//Трябва класовете да са в различни header файлове

struct Date { //dd/mm/yyyy
    Date() {
        m_date = new char[strlen(DEFAULT_DATE)+1];
        strcpy(m_date, DEFAULT_DATE);
        m_day = 1;
        m_month = 1;
        m_year = 1;
    }

    Date(const char* date) {
        if(!setDate(date)) {
            Date();
        }
    }
    ~Date() {
        free();
    }
    Date(const Date& other) {
        copy(other);
    }
    Date& operator=(const Date& other) {
        free();
        copy(other);
    }
    Date(Date&& other) noexcept {
        copy(other);
        other.free();
    }
    Date& operator=(Date&& other) noexcept {
        free();
        copy(other);
        other.free();
    }

    bool setDate(const char* date) { //return false if the input date is invalid
        //validation
        m_date = new char[strlen(date) + 1];
        strcpy(m_date, date);
    }

    const char* getDate() {
        return m_date;
    }
protected:
    void free() {
        delete[] m_date;
        m_date = nullptr;
    }

    void copy(const Date& other) {
        m_date = new char[strlen(other.m_date) + 1];
        strcpy(m_date, other.m_date);
        m_day = other.m_day;
        m_month = other.m_month;
        m_year = other.m_year;

    }
private:
    char* m_date;
    unsigned m_day;
    unsigned m_month;
    unsigned m_year;
};

class DatePair : protected Pair<Date> {
public:
    DatePair(const char* key, Date value) {
        m_key = new char[strlen(key) + 1];
        strcpy(m_key, key);

        m_value = value;
    }
    ~DatePair() {
        this->free();
    }
    DatePair(const DatePair& other) {
        this->copy(other.m_key, other.m_value);
    }
    DatePair& operator=(const DatePair& other) {
        this->free();
        this->copy(other.m_key, other.m_value);
    }

protected:
    void free() override {
        delete[] m_key;
        m_key = nullptr;
    }

    void copy(const char* _key, Date _value) override {
        m_key = new char[strlen(_key) + 1];
        strcpy(m_key, _key);

        m_value = _value;
    }
};


#endif //EXAM_PREP_DATEPAIR_H
