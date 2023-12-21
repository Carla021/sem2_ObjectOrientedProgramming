//
// Created by Carla on 5/4/2023.
//

#ifndef A6_CARLA021_1_VALIDATORS_H
#define A6_CARLA021_1_VALIDATORS_H

#pragma once

#include "../domain/domain.h"

class ValidationException: public std::exception {
private:
    string message;
public:
    explicit  ValidationException(string& message);
    const char *what() const noexcept override;
};

class EventValidator{
public:
    EventValidator();
    bool validate_string(const string& input);
    void validate_title(const string& input);
    void validate_description(const string& input);
    void validate_date_and_time(Datetime);
    void validate_number_of_people(int number_of_people);
    void validate_link(const string& link);
    ~EventValidator();
};

#endif //A6_CARLA021_1_VALIDATORS_H
