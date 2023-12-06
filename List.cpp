#include "List.h"
#include <iostream>
#include <utility>

List::List() : first(nullptr) {
    // std::cout << "in" << '\n';
}

void List::push_forward(const Plane& p) {
    Item* first_copy = first;
    first = new Item {.info = p, .next = first_copy};
}

List::Item* List::find_pre_back() {
    Item* current = first;
    if (current == nullptr || current->next == nullptr) {
        throw Errors::No_value;
    }
    while (current->next->next != nullptr) {
        current = current->next;
    }
    return current;
}

List::Item* List::find_back()  {
    try {
        return find_pre_back()->next;
    } catch (Errors) {
        if (first == nullptr) {
            throw Errors::No_value;
        }
        return first;
    }
}

void List::push_back(const Plane& p) {
    Item** i = nullptr;
    try {
        i = &find_back()->next;
    } catch (Errors) {
        i = &first;
    }
    *i = new Item {.info = p, .next = nullptr};
}

Plane List::pop_forward() {
    if (first == nullptr) {
        throw Errors::No_value;
    }
    Item* new_first = first->next;
    Plane const result = first->info;
    delete first;
    first = new_first;
    return result;
}

Plane List::pop_back() {
    Item* p = nullptr;
    try {
        p = find_pre_back();
    } catch(Errors) {
        if (first == nullptr) {
            throw Errors::No_value;
        }
        p = first;
        Plane const result = p->info;
        delete p;
        first = nullptr;
        return result;
    }
    Plane const result = p->next->info;
    delete p->next;
    p->next = nullptr;
    return result;
}

std::pair<size_t, Plane> List::get_item(const Plane& value) {
    Item* current = first;
    size_t counter = 0;
    if (current == nullptr) {
        throw Errors::No_value;
    }
    while(current->info != value) {
        counter++;
        if (current->next == nullptr) {
            throw Errors::No_value;
        }
        current = current->next;
    }
    counter++;
    std::pair<size_t, Plane> p;
    p.first = counter;
    p.second = current->info;
    return p;
}

Plane List::pop(const Plane& value) {
    Item* current = first;
    if (current == nullptr) {
        throw Errors::No_value;
    }
    if (current->next == nullptr) {
        Plane const result = current->info;
        if (result != value) {
            throw Errors::No_value;
        }
        delete current;
        first = nullptr;
        return result;
    }
    while(current->next->info != value) {
        if (current->next->next == nullptr) {
            throw Errors::No_value;
        }
        current = current->next;
    }
    Plane const result = current->next->info;
    Item* next = current->next->next;
    delete current->next;
    current->next = next;
    return result;
}

void List::for_each(void (func)(Plane&)) {
    for (Item* i = first; i != nullptr; i = i->next) {
        func(i->info);
    }
}

void List::for_each(void (func)(const Plane&)) const{
    for (Item* i = first; i != nullptr; i = i->next) {
        func(i->info);
    }
}

void List::erase() {
    while (first != nullptr) {
        pop_forward();
    }
}

List::~List() { //NOLINT: not throwing
    erase();   
}

void List::add(const List& l) {
    for (Item* i = l.first; i != nullptr; i = i->next) {
        push_back(i->info);
    }
}

List::List(const List& l) : first(nullptr) {
    add(l);
}

List& List::operator=(const List& l) {
    if (this != &l) {
        erase();
        add(l);
    }
    return *this;
}
