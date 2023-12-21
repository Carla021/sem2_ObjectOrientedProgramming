#ifndef A45_USER_SERVICES_H
#define A45_USER_SERVICES_H

#pragma once
#include "../repository/user_repository.h"
#include "../repository/repository.h"

class UserService{
private:
    Repository& repository;
    UserRepository* user_repository;

public:
    UserService(Repository& repository, UserRepository* user_repository);
    explicit UserService(Repository& repository1);
    vector<Event> get_all_user_service();
    unsigned long long get_capacity_user_service();
    unsigned long long get_number_of_elements_user_service();
    void add_user_service(Event event);
    Event get_event_by_index_user_service(int index);
    // static void order_events_chronologically(vector<Event>);
    int delete_user_service(const string&);
    int find_events_by_title_user_service(const string& title);
    vector<Event> filter_events(int month);

    /*
    static void merge_sort(const vector<Event>& events_to_be_sorted, unsigned long long left, unsigned long long right);

    static void merge(vector<Event> events_to_be_sorted, unsigned long long left, unsigned long long middle, unsigned long long right);
     */

    void repository_type(const string& file_type);

    string& get_file_service();

    ~UserService();
};

bool check_if_an_event_is_after_another(Event&, Event&);

#endif //A45_USER_SERVICES_H
