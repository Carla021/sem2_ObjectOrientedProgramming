#pragma once

#include <string>

using namespace std;

class Datetime
{
private:
    int day;
    int month;
    int year;
    int hour;
    int minutes;

public:
    Datetime(int day, int month, int year, int hour, int minutes);

    Datetime();

    int get_day() const;
    int get_month() const;
    int get_year() const;
    int get_hour() const;
    int get_minutes() const;

    string toStringDT();
};