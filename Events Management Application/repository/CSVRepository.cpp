//
// Created by Carla on 5/3/2023.
//
#include <fstream>
#include "CSVRepository.h"

CSVRepository::CSVRepository(const std::vector<Event> &list_of_events, const std::string &user_filename) {
    this->list_of_events = list_of_events;
    this->user_filename = user_filename;
}

vector<Event> CSVRepository::get_all_user_repository() {
    return this->list_of_events;
}

unsigned long long CSVRepository::get_number_of_elements() {
    return this->list_of_events.size();
}

unsigned long long CSVRepository::get_capacity() {
    return this->list_of_events.capacity();
}

void CSVRepository::add_user_repository(const Event &event) {
    this->list_of_events.push_back(event);
    this->write_to_file();
}

void CSVRepository::write_to_file() {
    ofstream fout(this->user_filename);
    if(!this->list_of_events.empty())
    {
        for(Event event: this->list_of_events)
            fout << event;
    }

    fout.close();
}

string &CSVRepository::get_filename() {
    return this->user_filename;
}

CSVRepository::~CSVRepository() = default;

