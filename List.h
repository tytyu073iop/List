#pragma once

#include "Plane/Plane.h"
#include <utility>

class List { //NOLINT: Move constructor
public:
    List();
    List(const List&);
    List& operator=(const List&);
    ~List();
    void push_forward(const Plane&);
    void push_back(const Plane&);
    Plane pop_forward();
    Plane pop_back();
    Plane pop(const Plane& value);
    std::pair<size_t, Plane> get_item(const Plane& value);
    void for_each(void(Plane&));
    void for_each(void(const Plane&)) const;
    enum class Errors {
        No_value
    };
private:
    struct Item {
        Plane info;
        Item* next;
    };
    Item* first;
    // my funcs
    Item* find_pre_back();
    Item* find_back();
    // kolhoz
    void erase();
    void add(const List&);
};
