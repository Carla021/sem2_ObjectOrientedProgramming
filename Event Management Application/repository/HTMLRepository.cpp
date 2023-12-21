//
// Created by Carla on 5/3/2023.
//
#include <fstream>
#include "HTMLRepository.h"

HTMLRepository::HTMLRepository(const std::vector<Event>& list_of_events, const std::string &user_filename) {
    this->list_of_events = list_of_events;
    this->user_filename = user_filename;
}

vector<Event> HTMLRepository::get_all_user_repository() {
    return this->list_of_events;
}

unsigned long long HTMLRepository::get_number_of_elements() {
    return this->list_of_events.size();
}

unsigned long long HTMLRepository::get_capacity() {
    return this->list_of_events.capacity();
}

void HTMLRepository::add_user_repository(const Event &event) {
    this->list_of_events.push_back(event);
    this->write_to_file();
}

void HTMLRepository::write_to_file() {
    ofstream fout(this->user_filename);
    fout << "<!DOCTYPE html>\n<html><head><title>Events List</title></head><body>\n";
    fout << "<table border=\"1\">\n";
    fout << "<tr><td>Title</td><td>Description</td><td>Date and time</td><td>Number of people</td><td>link</td>\n";
    for(Event event: this->list_of_events)
    {
        string date_time;
        date_time = to_string(event.get_date_and_time().get_day()) + "." + to_string(event.get_date_and_time().get_month()) + "." + to_string(event.get_date_and_time().get_year()) + " " + to_string(event.get_date_and_time().get_minutes()) + ":" + to_string(event.get_date_and_time().get_hour());
        fout << "<tr><td>" << event.get_title() << "</td>"
             << "<td>" << event.get_description() << "</td>"
             << "<td>" << date_time << "</td>"
             << "<td>" << event.get_number_of_people() << "</td>"
             << "<td><a href=\"" << event.get_link() << "\">" << event.get_link() << "</a></td>" << '\n';
    }
    fout << "</table></body></html>";
    fout.close();
}

std::string &HTMLRepository::get_filename() {
    return this->user_filename;
}

HTMLRepository::~HTMLRepository() = default;

