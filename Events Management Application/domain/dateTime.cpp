#include "dateTime.h"

Datetime::Datetime(int day, int month, int year, int hour, int minutes)
{
    this->day = day;
    this->month = month;
    this->year = year;
    this->hour = hour;
    this->minutes = minutes;
}

int Datetime::get_day() const {
    return day;
}

int Datetime::get_month() const {
    return month;
}

int Datetime::get_year() const {
    return year;
}

int Datetime::get_hour() const {
    return hour;
}

int Datetime::get_minutes() const {
    return minutes;
}

Datetime::Datetime():day{0}, month{0}, year{0}, hour{0}, minutes{0}
{

}

string Datetime::toStringDT() {
    return to_string(this->day) + "." + to_string(this->month) + "." + to_string(this->year) + "." + to_string(this->hour) + "." + to_string(this->minutes);
}

