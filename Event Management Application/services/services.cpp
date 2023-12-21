//
// Created by Carla on 3/29/2023.
//
#include "services.h"
#include "../repository/fake_repository.h"

#include <utility>

Service::Service(Repository& repo): repository(repo) {}

vector<Event> Service::get_all_service() {
    return this->repository.get_all_repository();
}

unsigned long long Service::get_number_elements_service() {
    return this->repository.get_number_elements();
}

unsigned long long Service::get_capacity_service() {
    return this->repository.get_capacity();
}

int Service::find_events_by_title_service(const string &title) {
    return this->repository.find_events_by_title(title);
}

int Service::add_service(const string& title, string description, Datetime datetime, int number_of_people, string link) {
    if(this->find_events_by_title_service(title) != -1)
        return 1;

    this->repository.add_repository(Event(title, std::move(description), datetime, number_of_people, std::move(link)));
    return 0;
}

int Service::delete_service(const string& title) {
    int delete_index = this->repository.find_events_by_title(title);
    if(delete_index == -1)
        return 1;
    else {
        this->repository.delete_repository(delete_index);
        return 0;
    }
}

int Service::update_service(const string& title_event_to_be_updated, string new_title, string new_description,
                            Datetime new_date_time, int new_number_of_people, string new_link) {
    int index_to_event_to_be_updated = this->repository.find_events_by_title(title_event_to_be_updated);
    if(index_to_event_to_be_updated == -1)
        return 1;
    Event new_event = Event(std::move(new_title), std::move(new_description), new_date_time, new_number_of_people, std::move(new_link));
    this->repository.update_repository(index_to_event_to_be_updated, new_event);
    return 0;
}

Event Service::get_event_by_index_service(int index) {
    return this->repository.get_event_by_index_repository(index);
}

Service::~Service() = default;

