//
// Created by Carla on 5/18/2023.
//

#ifndef A89_CARLA021_FAKE_REPOSITORY_H
#define A89_CARLA021_FAKE_REPOSITORY_H

#include "repository.h"

class FakeRepository: public Repository{
private:
    vector<Event> fakeRepositoryListOfEvents;

public:
    explicit FakeRepository();

    bool add_repository(Event event) override;

    ~FakeRepository();
};

void test_fake_repository();

#endif //A89_CARLA021_FAKE_REPOSITORY_H
