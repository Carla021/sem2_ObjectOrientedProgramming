#pragma once
#include "../repository/repository.h"

class Service
{
private:
    Repository& repository;

public:
    explicit Service(Repository& repo);
    vector<Event> get_all_service();
    unsigned long long get_number_elements_service();
    unsigned long long get_capacity_service();
    int add_service(const string& title, string description, Datetime datetime, int number_of_people, string link);
    int delete_service(const string& title);
    int update_service(const string& title_event_to_be_updated, string new_title, string new_description, Datetime new_date_time, int new_number_of_people, string new_link);
    int find_events_by_title_service(const string& title);
    Event get_event_by_index_service(int index);

    ~Service();
};
