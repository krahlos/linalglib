#include <iostream>

#include "cmatrix.h"
#include "cvector.h"
#include <gtest/gtest.h>

int main(int argc, char* argv[])
{    
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

TEST(CVectorTests, MemberGetterTests)
{
    LinAlg::Vector::CVector<float> vec(3);
    EXPECT_EQ(3, vec.get_dim());

    EXPECT_EQ(LinAlg::Vector::EVectorTypes::None, vec.get_type());

    EXPECT_EQ(0, vec.get_value(0));
    EXPECT_EQ(0, vec.get_value(1));
    EXPECT_EQ(0, vec.get_value(2));
}