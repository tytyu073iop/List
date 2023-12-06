#include "../Plane/Plane.h"
#include <gtest/gtest.h>

TEST(Plane, id) { //NOLINT
    Plane const a;
    Plane const b;
    Plane const c;
    EXPECT_EQ(a.GetId(), 0);
    EXPECT_EQ(b.GetId(), 1);
    EXPECT_EQ(c.GetId(), 2);
}

TEST(PlaneTest, GetId) { //NOLINT
    Plane const p(5);
    EXPECT_EQ(p.GetId(), 5);
}

TEST(PlaneTest, CopyConstructor) { //NOLINT
    Plane const p1(10);
    Plane const p2(p1); //NOLINT: I need it!
    EXPECT_EQ(p1.GetId(), p2.GetId());
}

TEST(PlaneTest, CopyAssignmentOperator) { //NOLINT
    Plane const p1(15);
    Plane const p2 = p1; //NOLINT: I need it!
    EXPECT_EQ(p1.GetId(), p2.GetId());
}

TEST(PlaneTest, ComparisonOperator) { //NOLINT
    Plane const p1(20);
    Plane const p2(20);
    EXPECT_TRUE(p1 == p2);
    {
        Plane const p1(20);
        Plane const p2(20);
        EXPECT_FALSE(p1 != p2);
    }
    {
        Plane const p1(20);
        Plane const p2(10);
        EXPECT_FALSE(p1 == p2);
        EXPECT_TRUE(p1 != p2);
    }
}

TEST(PlaneTest, Click) { //NOLINT
    Plane p;
    EXPECT_FALSE(p.IsClicked());
    p.Click();
    EXPECT_TRUE(p.IsClicked());
    Plane const a(p);
    EXPECT_TRUE(a.IsClicked());
    Plane b;
    b = p;
    EXPECT_TRUE(b.IsClicked());
}
