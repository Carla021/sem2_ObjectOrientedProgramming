//
// Created by Carla on 4/15/2023.
//
#include "user_repository.h"
#include <fstream>

#include <utility>

UserException::UserException(std::string &_message): message(_message) {}

const char* UserException::what() const noexcept {
    return message.c_str();
}

UserRepository::UserRepository() = default;

UserRepository::UserRepository(vector<Event> list_of_events) {
    this->list_of_events = std::move(list_of_events);
}

vector<Event> UserRepository::get_all_user_repository() {
    return this->list_of_events;
}

unsigned long long UserRepository::get_number_of_elements() {
    return this->list_of_events.size();
}

unsigned long long UserRepository::get_capacity() {
    return this->list_of_events.capacity();
}

void UserRepository::add_user_repository(const Event& event) {
    this->list_of_events.push_back(event);
}

int UserRepository::find_events_by_title_user_repository(const string &title) {
    int searched_index = -1;
    int index = 0;
    unsigned long long length = this->get_number_of_elements();
    while(index < length && searched_index == -1)
    {
        Event some_event = this->list_of_events[index];
        string other_title = some_event.get_title();
        if(other_title == title)
            searched_index = index;
        index++;
    }
    return searched_index;
}

void UserRepository::delete_user_repository(int index_to_delete) {
    this->list_of_events.erase(this->list_of_events.begin() + index_to_delete);
}

Event UserRepository::get_event_by_index_user_repository(int index) {
    return this->list_of_events[index];
}

UserRepository::~UserRepository() = default;

