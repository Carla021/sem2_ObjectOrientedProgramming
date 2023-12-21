#include "domain.h"
#include "dateTime.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> divide_line_in_elements(const string& str, char delimiter)
{
    vector<string> result;
    stringstream ss(str);
    string token;
    while(getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

Event::Event(string title, string description, Datetime dateTime, int number_of_people, string link)
{
    this->title = std::move(title);
    this->description = std::move(description);
    this->dateTime = dateTime;
    this->number_of_people = number_of_people;
    this->link = std::move(link);
}

string Event::get_title() {
    return this->title;
}

string Event::get_description() {
    return this->description;
}

Datetime Event::get_date_and_time() {
    return this->dateTime;
}

int Event::get_number_of_people() const {
    return this->number_of_people;
}

void Event::set_number_of_people(int new_number) {
    this->number_of_people = new_number;
}

string Event::get_link() {
    return this->link;
}

string Event::toString() const {
    string minutes = to_string(this->dateTime.get_minutes());
    return this->title + "," + this->description + "," + to_string(this->dateTime.get_day()) + "." + to_string(this->dateTime.get_month()) + "." + to_string(this->dateTime.get_year()) + "." + to_string(this->dateTime.get_hour()) + "." + minutes + "," +
           to_string(this->number_of_people) + "," + this->link;
}

istream &operator>>(istream &is, Event &event) {
    string line;
    getline(is, line);

    vector<string> data_of_an_event = divide_line_in_elements(line, ',');
    if(data_of_an_event.size() != 5)
        return is;

    event.title = data_of_an_event[0];
    event.description = data_of_an_event[1];
    event.number_of_people = stoi(data_of_an_event[3]);
    event.link = data_of_an_event[4];

    vector<string> date_time = divide_line_in_elements(data_of_an_event[2], '.');
    if(date_time.size() != 5)
        return is;

    event.dateTime = Datetime(stod(date_time[0]), stod(date_time[1]), stod(date_time[2]), stod(date_time[3]), stod(date_time[4]));


    return is;
}

ostream &operator<<(ostream &os, const Event &event) {
    os << event.title << "," << event.description << "," << to_string(event.dateTime.get_day()) + "." + to_string(event.dateTime.get_month()) + "." + to_string(event.dateTime.get_year()) + "." + to_string(event.dateTime.get_hour()) + "." << to_string(event.dateTime.get_minutes()) << "," << to_string(event.number_of_people) << "," << event.link << "\n";

    return os;
}

Event::~Event() = default;

