#include "gtest/gtest.h"
#include "../List.h"
#include <string>

TEST(ListTest, PushAndPop) { //NOLINT
    // FAIL();
    List list;
    Plane const plane1;
    Plane const plane2;
    Plane const plane3;

    // Test push_forward
    list.push_forward(plane1);
    ASSERT_EQ(list.get_item(plane1).second.GetId(), plane1.GetId());
    EXPECT_EQ(list.get_item(plane1).first, 1);

    list.push_back(plane3);



    // Test push_back
    list.push_back(plane2);

    ASSERT_EQ(list.get_item(plane2).second.GetId(), plane2.GetId());
    EXPECT_EQ(list.get_item(plane2).first, 3);



    // Test pop_forward
    Plane popped_plane = list.pop_forward();
    ASSERT_EQ(popped_plane.GetId(), plane1.GetId());

    // Test pop_back
    popped_plane = list.pop_back();
    ASSERT_EQ(popped_plane.GetId(), plane2.GetId());

    popped_plane = list.pop(plane3);

    ASSERT_EQ(popped_plane.GetId(), plane3.GetId());
   

}

std::string s; //NOLINT

void ClickPlane(Plane& p) {
    p.Click();
}

void PrintId(const Plane& p) {
    s += std::to_string(p.GetId());
}

TEST(ListTest, ForEach) { // NOLINT
    List list;
    Plane const plane1(1);
    Plane const plane2(2);
    list.push_forward(plane1);
    list.push_back(plane2);

    // Test for_each with a lambda that increments the id of each Plane
    // list.for_each( [](Plane& p){ p.Click(); }); 
    list.for_each(ClickPlane);
    // ASSERT_TRUE(list.pop_back().IsClicked());
    // std::cout << "passedpop";
    EXPECT_TRUE(list.get_item(plane1).second.IsClicked());
    EXPECT_TRUE(list.get_item(plane2).second.IsClicked());
    const List clist(list);
    // clist.for_each( [](const Plane& p){ s += std::to_string(p.GetId()); });
    clist.for_each(PrintId);
    EXPECT_EQ(s, "12");
}

TEST(ListTest, SingleItem) { //NOLINT
    List example;
    example.push_back(Plane(0));
    List list(example);
    EXPECT_EQ(list.pop(Plane(0)), Plane(0));
    list = example;
    EXPECT_EQ(list.pop_back().GetId(), 0);
    list = example;
    EXPECT_EQ(list.pop_forward().GetId(), 0);
    list = example;
    EXPECT_THROW(list.pop(Plane(2)), List::Errors);
}

TEST(ListTest, throw) { //NOLINT
    List list;
    EXPECT_THROW(list.pop_back(), List::Errors);
    EXPECT_THROW(list.pop_forward(), List::Errors);
    EXPECT_THROW(list.pop(Plane()), List::Errors);
    EXPECT_THROW(list.get_item(Plane()), List::Errors);
    list.for_each([](Plane& p){});
    list.for_each([](const Plane& p){});
}
