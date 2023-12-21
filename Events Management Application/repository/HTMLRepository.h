//
// Created by Carla on 5/3/2023.
//

#ifndef A6_CARLA021_1_HTMLREPOSITORY_H
#define A6_CARLA021_1_HTMLREPOSITORY_H

#pragma once

#include "user_repository.h"
#include "../domain/domain.h"

class HTMLRepository: public UserRepository {
public:
    HTMLRepository(const std::vector<Event>& list_of_events, const std::string& user_filename);

    vector<Event> get_all_user_repository() override;

    unsigned long long get_number_of_elements() override;
    unsigned long long get_capacity() override;
    void add_user_repository(const Event&) override;
    void write_to_file() override;
    std::string& get_filename() override;

    ~HTMLRepository();
};


#endif //A6_CARLA021_1_HTMLREPOSITORY_H
