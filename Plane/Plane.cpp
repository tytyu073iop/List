#include "Plane.h"
#include <iostream>

size_t next_id = 0; //NOLINT

Plane::Plane() : id_(next_id++) {}

size_t Plane::GetId() const {
    return id_;
}

// Copy constructor
Plane::Plane(const Plane& other) : id_(other.id_), click(other.click) {
}

// Copy assignment operator
Plane& Plane::operator=(const Plane& other) {
    if (this != &other) {
        id_ = other.id_;
        click = other.click;
    }
    return *this;
}

// Parameterized constructor
Plane::Plane(size_t id) : id_(id) {
}

bool Plane::operator==(const Plane& other) const {
    return id_ == other.id_;
}

void Plane::Click() {
    click = true;
    // std::cout << "Clicked!";
}

bool Plane::IsClicked() const {
    return click;
}
