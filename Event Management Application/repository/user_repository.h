#ifndef A45_USER_REPOSITORY_H
#define A45_USER_REPOSITORY_H

#pragma once
#include <vector>
#include "../domain/domain.h"

class UserRepository {

protected:
    vector<Event> list_of_events;
    string user_filename;

public:
    explicit UserRepository(vector<Event>);
    UserRepository();
    virtual vector<Event> get_all_user_repository();
    virtual unsigned long long get_number_of_elements();
    virtual unsigned long long get_capacity();
    virtual void add_user_repository(const Event&);
    int find_events_by_title_user_repository(const string& title);
    void delete_user_repository(int index_to_delete);
    Event get_event_by_index_user_repository(int index);

    virtual void write_to_file()=0;
    virtual std::string& get_filename()=0;

    ~UserRepository();
};

class UserException: public std::exception {
private:
    std::string message;
public:
    explicit  UserException(std::string& _message);

    const char *what() const noexcept override;
};

#endif //A45_USER_REPOSITORY_H
