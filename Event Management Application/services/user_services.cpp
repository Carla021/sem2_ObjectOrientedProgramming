//
// Created by Carla on 4/15/2023.
//

#include "user_services.h"
#include "../repository/HTMLRepository.h"
#include "../repository/CSVRepository.h"

#include <utility>
#include <algorithm>


UserService::UserService(Repository& repository1, UserRepository* user_repository1): repository(repository1) {
    this->user_repository = user_repository1;
}

UserService::UserService(Repository &repository1): repository(repository1) {}

vector<Event> UserService::get_all_user_service() {
    return this->user_repository->get_all_user_repository();
}

unsigned long long UserService::get_capacity_user_service() {
    return this->user_repository->get_capacity();
}

unsigned long long UserService::get_number_of_elements_user_service() {
    return this->user_repository->get_number_of_elements();
}

void UserService::add_user_service(Event event) {
    event.set_number_of_people(event.get_number_of_people() + 1);
    this->user_repository->add_user_repository(event);
    //this->repository->get_event_by_index_repository(this->repository->find_events_by_title(event.get_title())).set_number_of_people(event.get_number_of_people() + 1);
}

/*
void UserService::order_events_chronologically(Event* valid_events, int length) {

    for(int index = 0; index < length - 1; index++)
        for(int index2 = index + 1; index2 < length; index2++)
        {
            Event event1, event2;
            event1 = valid_events[index];
            event2 = valid_events[index2];
            if(check_if_an_event_is_after_another(event1, event2) == 1)
            {
                swap(event1, event2);
            }
        }
}*/
/*
void UserService::merge(vector<Event> events_to_be_sorted, unsigned long long left, unsigned long long middle, unsigned long long right)
{
    int number_of_first_part_of_events = middle - left + 1;
    int number_of_second_part_of_events = right - middle;

    vector<Event> left_part_of_events;
    vector<Event> right_part_of_events;

    for(int index = 0; index < number_of_first_part_of_events; index++)
        left_part_of_events.push_back(events_to_be_sorted[left + index]);
    for(int index = 0; index < number_of_second_part_of_events; index++)
        right_part_of_events.push_back(events_to_be_sorted[middle + index + 1]);

    int index1 = 0, index2 = 0, index3 = left;
    while(index1 < number_of_first_part_of_events && index2 < number_of_second_part_of_events)
    {
        if(check_if_an_event_is_after_another(left_part_of_events[index1], right_part_of_events[index2]) <= 0)
        {
            events_to_be_sorted[index3] = left_part_of_events[index1];
            index1++;
        } else {
            events_to_be_sorted[index3] = right_part_of_events[index2];
            index2++;
        }
        index3++;
    }

    while(index1 < number_of_first_part_of_events)
    {
        events_to_be_sorted[index3] = left_part_of_events[index1];
        index1++;
        index3++;
    }

    while(index2 < number_of_second_part_of_events)
    {
        events_to_be_sorted[index3] = right_part_of_events[index2];
        index2++;
        index3++;
    }
}

void UserService::merge_sort(const vector<Event>& events_to_be_sorted, unsigned long long left, unsigned long long right)
{
    if(left < right)
    {
        unsigned long long middle = left + (right - left) / 2;
        merge_sort(events_to_be_sorted, left, middle);
        merge_sort(events_to_be_sorted, middle + 1, right);

        merge(events_to_be_sorted, left, middle, right);
    }
}

void UserService::order_events_chronologically(vector<Event> valid_events) {
    sort(valid_events.begin(), valid_events.end(), check_if_an_event_is_after_another);
}
*/

int UserService::find_events_by_title_user_service(const string &title) {
    return this->user_repository->find_events_by_title_user_repository(title);
}

int UserService::delete_user_service(const string& title) {
    int delete_index = this->user_repository->find_events_by_title_user_repository(title);
    if(delete_index == -1)
        return 1;
    else {
        this->user_repository->delete_user_repository(delete_index);
        get_event_by_index_user_service(delete_index).set_number_of_people(get_event_by_index_user_service(delete_index).get_number_of_people() - 1);
        return 0;
    }
}

Event UserService::get_event_by_index_user_service(int index) {
    return this->user_repository->get_event_by_index_user_repository(index);
}


vector<Event> UserService::filter_events(int month) {
/*
    if(month != -1) {
        for (int index = 0; index < this->repository->get_number_elements(); index++)
            if (this->repository->get_event_by_index_repository(index).get_date_and_time().get_month() == month)
                filtered_events.add_element(this->repository->get_event_by_index_repository(index));
    } else {
        filtered_events = *this->order_events_chronologically().get_all_repository();
    }

    if(month != -1 && (month >= 1 && month <= 12))
    {
        for(int index = 0; index < this->repository->get_number_elements(); index++)
        {
            Event  event = this->repository->get_event_by_index_repository(index);
            if(event.get_date_and_time().get_month() == month)
            {
                this->user_repository->list_of_filtered_events->add_element(event);
            }
        }

    }
*/
    int index;
    vector<Event> valid_events;
    int length = this->repository.get_number_elements();
    if(month == -1)
    {
        vector<Event> list_of_all_events = repository.get_all_repository();
        for(index = 0; index < length; index++)
        {
            Event event = list_of_all_events[index];
            valid_events.push_back(event);
        }
        //this->order_events_chronologically(valid_events);
        sort(valid_events.begin(), valid_events.end(), check_if_an_event_is_after_another);
    } else {
        vector<Event> list_of_all_events = repository.get_all_repository();
        for(index = 0; index < length; index++)
        {
            Event event = list_of_all_events[index];
            if(event.get_date_and_time().get_month() == month)
            {
                valid_events.push_back(event);
            }
        }
    }
    return valid_events;
}

void UserService::repository_type(const string& file_type) {
    if(file_type == "csv")
    {
        vector<Event> user_list;
        string user_file = "CSV.txt";
        auto* csv_repository = new CSVRepository{user_list, user_file};
        this->user_repository = csv_repository;
    } else if(file_type == "html")
    {
        vector<Event> user_list;
        string user_file = "events.html";
        auto* html_repository = new HTMLRepository{user_list, user_file};
        this->user_repository = html_repository;
    } else {
        string error;
        error += string("The filename is invalid!");
        if(!error.empty())
            throw UserException(error);
    }
}

string &UserService::get_file_service() {
    return this->user_repository->get_filename();
}

UserService::~UserService() = default;

bool check_if_an_event_is_after_another(Event &event1, Event &event2) {
    if(event1.get_date_and_time().get_year() > event2.get_date_and_time().get_year())
        return false;
    if(event1.get_date_and_time().get_year() < event2.get_date_and_time().get_year())
        return true;
    if(event1.get_date_and_time().get_month() > event2.get_date_and_time().get_month())
        return false;
    if(event1.get_date_and_time().get_month() < event2.get_date_and_time().get_month())
        return true;
    if(event1.get_date_and_time().get_day() > event2.get_date_and_time().get_day())
        return false;
    if(event1.get_date_and_time().get_day() < event2.get_date_and_time().get_day())
        return true;
    if(event1.get_date_and_time().get_hour() > event2.get_date_and_time().get_hour())
        return false;
    if(event1.get_date_and_time().get_hour() < event2.get_date_and_time().get_hour())
        return true;
    if(event1.get_date_and_time().get_minutes() > event2.get_date_and_time().get_minutes())
        return false;
    if(event1.get_date_and_time().get_minutes() < event2.get_date_and_time().get_minutes())
        return true;

    return true;
}