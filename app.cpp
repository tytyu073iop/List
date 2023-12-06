#include "List.h"
#include <iostream>

size_t counter = 0; //NOLINT

int main() {
    List l;
    size_t n = 0;
    std::cout << "How many planes?";
    std::cin >> n;
    while (n--) { //NOLINT: obvious
        l.push_back(Plane());
    }
    std::cout << "list have planes with id's: ";
    {
        const List& lc(l); 
        lc.for_each([](const Plane& p){ std::cout << p.GetId() << " "; });
    }
    std::cout << '\n';
    std::cout << "Pushing plane back" << '\n';
    l.push_back(Plane());
    std::cout << "Pushing plane forward\n";
    l.push_forward(Plane());
    std::cout << "list have planes with id's: ";
    l.for_each([](const Plane& p){ std::cout << p.GetId() << " "; });
    std::cout << '\n';
    std::cout << "poping back\n";
    l.pop_back();
    std::cout << "poping forward\n";
    l.pop_forward();
    {
        size_t const q = 3; // (std::rand() % n);
        std::cout << "poping " << q << " plane\n";
        try {
            l.pop(Plane(q));
        } catch (List::Errors) {
            std::cout << "NO PLANE!\n";
        }
    }
    {
        size_t i = 0;
        std::cout << "What plane to get? ";
        std::cin >> i;
        try {
            std::cout << i <<'\n';
            auto [c, p] = l.get_item(Plane(i));
            std::cout << "With " << c << " tries, we found " << p.GetId() << " Plane\n";
        } catch (List::Errors) {
            std::cout << "NO PLANE!\n";
        }
    }
    std::cout << "list have planes with id's: ";
    l.for_each([](const Plane& p){ std::cout << p.GetId() << " "; });
    std::cout << '\n';
    std::cout << "Clicking Planes\n";
    l.for_each([](Plane& p){ p.Click(); counter++; });
    std::cout << "Clicked " << counter << " times";
    return 0;
}
