#pragma once
#include <vector>
#include "../domain/domain.h"

class Repository
{
private:
    vector<Event> repository_list_of_events;
    string filename;

public:
    Repository();
    explicit Repository(const std::string& filename);
    void start_elements_for_repository();
    vector<Event> get_all_repository();
    unsigned long long get_number_elements();
    unsigned long long get_capacity();
    virtual bool add_repository(Event event);
    int find_events_by_title(const string& title);
    void delete_repository(int index_to_delete);
    void update_repository(int update_index, const Event& new_event);
    Event get_event_by_index_repository(int index);

    void read_from_file_repository();
    void write_to_file_repository();

    ~Repository();
};

class RepositoryException: public std::exception {
private:
    std::string message;
public:
    explicit RepositoryException(std::string& _message);

    const char *what() const noexcept override;
};