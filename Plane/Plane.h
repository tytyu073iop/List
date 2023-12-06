#pragma once

#include <cstddef>
class Plane {
private:
    size_t id_;
    // static size_t next_id; //NOLINT: for functon;
    bool click = false;
public:
    Plane();
    [[nodiscard]] size_t GetId() const;
    bool operator==(const Plane&) const;
    Plane(const Plane&);
    Plane& operator=(const Plane&);
    explicit Plane(size_t id);
    void Click();
    bool IsClicked() const;
};
