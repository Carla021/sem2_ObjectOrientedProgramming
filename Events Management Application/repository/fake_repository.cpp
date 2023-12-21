//
// Created by Carla on 5/18/2023.
//

#include <cassert>
#include "fake_repository.h"
#include "../services/services.h"


FakeRepository::FakeRepository() {

}

bool FakeRepository::add_repository(Event event) {
    return true;
}

FakeRepository::~FakeRepository() = default;

void test_fake_repository() {
    FakeRepository fakeRepository;
    Service service {fakeRepository};

    assert(service.add_service("a", "b", Datetime(1,2,3,4,5), 54, "www") == 1);
    assert(service.add_service("aa", "bb", Datetime(11,22,33,44,55), 88, "www") == 1);

}
