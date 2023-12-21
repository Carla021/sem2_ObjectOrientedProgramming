#pragma once

#include "dateTime.h"
#include <string>
#include <vector>

using namespace std;

class Event
{
private:
    string title;
    string description;
    Datetime dateTime;
    int number_of_people;
    string link;

public:
    explicit Event(string title = "", string description = "", Datetime datetime = Datetime(), int number_of_people = 0, string link = "");

    string get_title();
    string get_description();
    Datetime get_date_and_time();
    int get_number_of_people() const;
    string get_link();

    ~Event();

    //void accessLink();

    string toString() const;

    void set_number_of_people(int new_number);

    friend istream& operator>>(istream& is, Event& event);
    friend ostream& operator<<(ostream& os, const Event& event);

};

vector<string> divide_line_in_elements(const string& str, char delimiter);



