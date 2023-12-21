//
// Created by Carla on 5/4/2023.
//

#include "validators.h"

ValidationException::ValidationException(string &_message): message(_message) {}

const char *ValidationException::what() const noexcept {
    return message.c_str();
}

EventValidator::EventValidator() = default;

bool EventValidator::validate_string(const string &input) {
    for(char letter : input)
        if(isdigit(letter) != false)
            return false;
    return true;
}

void EventValidator::validate_title(const string &input) {
    string errors;
    if(!validate_string(input))
        errors += string("The title input contains digits!");
    if(input.length() == 0)
        errors += string("The title is empty!");
    if(!errors.empty())
        throw ValidationException(errors);
}

void EventValidator::validate_description(const string &input) {
    string errors;
    if(!validate_string(input))
        errors += string("The description input contains digits!");
    if(input.length() == 0)
        errors += string("The description is empty!");
    if(!errors.empty())
        throw ValidationException(errors);
}

void EventValidator::validate_date_and_time(Datetime datetime) {
    string errors;
    if(datetime.get_day() < 1 || datetime.get_day() > 31 || datetime.get_month() < 1 || datetime.get_month() > 12)
        errors += string("The date is not valid!");
    if(!errors.empty())
        throw ValidationException(errors);
}

void EventValidator::validate_number_of_people(int number_of_people) {
    string errors;
    if(number_of_people < 1)
        errors += string("The number of people is not valid!");
    if(!errors.empty())
        throw ValidationException(errors);
}

void EventValidator::validate_link(const string &link) {
    string errors;
    if(link.length() == 0)
        errors += string("The link input is empty!");
    if(link.find("www") == -1 && link.find("http") == -1)
        errors += string("The link is not a valid one!");
    if(!errors.empty())
        throw  ValidationException(errors);
}

EventValidator::~EventValidator() = default;
