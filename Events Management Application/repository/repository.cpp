//
// Created by Carla on 3/29/2023.
//
#include "repository.h"

#include <utility>
#include <fstream>

RepositoryException::RepositoryException(std::string &_message) : message(_message){}

const char* RepositoryException:: what() const noexcept {
    return message.c_str();
}

Repository::Repository() {
    this->filename = "";
}

Repository::Repository(const std::string& filename) {
    this->filename = filename;
    this->read_from_file_repository();
}

void Repository::start_elements_for_repository() {
    Event event1 = Event("UNTOLD", "music festival", Datetime(3, 8, 2023, 17, 20), 999999, "https://untold.com/");
    Event event2 = Event("NEVERSEA", "music festival", Datetime(6, 7, 2023, 17, 10), 555555, "https://neversea.com/");
    Event event3 = Event("ELECTRIC CASTLE", "music festival", Datetime(19, 7, 2023, 17, 50), 888889, "https://electriccastle.ro/");
    Event event4 = Event("SUMMER WELL", "music festival", Datetime(11, 8, 2023, 12, 30), 789665, "https://summerwell.ro/");
    Event event5 = Event("Street FOOD festival", "food festival", Datetime(25, 5, 2022, 11, 30), 56, "https://visitcluj.ro/events/street-food-festival-2/");
    Event event6 = Event("SAGA", "music festival", Datetime(23, 7, 2023, 23, 25), 876543, "https://www.sagafestival.com/tickets/?gclid=CjwKCAjwue6hBhBVEiwA9YTx8BUp66aQR");
    Event event7 = Event("Sports Festival", "sport festival", Datetime(4, 6, 2023, 12, 0), 98765, "https://www.sportsfestival.com/aleargaPentruCluj/?gclid=CjwKCAjwue6hB");
    Event event8 = Event("Vest Fest", "music festival", Datetime(16, 6, 2023, 18, 0), 56, "https://vestfest.ro/");
    Event event9 = Event("TIFF", "film festival", Datetime(9, 6, 2023, 12, 50), 98765, "https://tiff.ro/");
    Event event10 = Event("Retro Music Festival", "music festival", Datetime(7, 8, 2023, 15, 5), 3500, "http://retromusicfestival.ro/");

    this->repository_list_of_events.push_back(event1);
    this->repository_list_of_events.push_back(event2);
    this->repository_list_of_events.push_back(event3);
    this->repository_list_of_events.push_back(event4);
    this->repository_list_of_events.push_back(event5);
    this->repository_list_of_events.push_back(event6);
    this->repository_list_of_events.push_back(event7);
    this->repository_list_of_events.push_back(event8);
    this->repository_list_of_events.push_back(event9);
    this->repository_list_of_events.push_back(event10);

}

vector<Event> Repository::get_all_repository() {
    //return reinterpret_cast<DynamicArray *>(this->repository_list_of_events->elems_getter());
    if(this->repository_list_of_events.empty())
    {
        string error;
        error += string("The database is empty!");
        if(!error.empty())
            throw RepositoryException(error);
    }
    return this->repository_list_of_events;
}

unsigned long long Repository::get_number_elements() {
    if(this->repository_list_of_events.empty())
    {
        string error;
        error += string("The database is empty!");
        if(!error.empty())
            throw RepositoryException(error);
    }
    return this->repository_list_of_events.size();
}

unsigned long long Repository::get_capacity() {
    return this->repository_list_of_events.capacity();
}

bool Repository::add_repository(Event event) {
    int existing = this->find_events_by_title(event.get_title());
    if(existing != -1)
    {
        string error;
        error += string("The event already exists!");
        if(!error.empty())
            throw RepositoryException(error);
    }
    this->repository_list_of_events.push_back(event);
    this->write_to_file_repository();
    return true;
}

int Repository::find_events_by_title(const string& title) {
    int searched_index = -1;
    int index = 0;
    unsigned long long length = this->get_number_elements();
    while(index < length && searched_index == -1)
    {
        Event some_event = this->repository_list_of_events[index];
        string other_title = some_event.get_title();
        if(other_title == title)
            searched_index = index;
        index++;
    }
    return searched_index;
}

void Repository::delete_repository(int index_to_delete) {
    if(index_to_delete == -1)
    {
        string error;
        error += string("the dog does not exists!");
        if(!error.empty())
            throw RepositoryException(error);
    }
    this->repository_list_of_events.erase(this->repository_list_of_events.begin() + index_to_delete);
    this->write_to_file_repository();
}

void Repository::update_repository(int update_index, const Event& new_event) {
    if(update_index == -1)
    {
        string error;
        error += string("the event does not exist!");
        if(!error.empty())
            throw RepositoryException(error);
    }
    this->repository_list_of_events[update_index] = new_event;
    this->write_to_file_repository();
}

Event Repository::get_event_by_index_repository(int index) {
    return this->repository_list_of_events[index];
}

void Repository::read_from_file_repository() {
    ifstream file(this->filename);

    //if(!file.is_open())
    //    throw FileException("The file could not be opened!");

    Event event;
    while(file >> event)
        this->repository_list_of_events.push_back(event);

    file.close();
}

void Repository::write_to_file_repository() {
    ofstream file(this->filename);
    //if(!file.is_open())
    //  throw FileException("the file could not be opened!");

    for(const auto& event : this->repository_list_of_events)
        file << event;

    file.close();
}

Repository::~Repository() = default;

