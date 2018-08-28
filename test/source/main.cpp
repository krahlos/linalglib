#include <iostream>

#include "cmatrix.h"
#include <gtest/gtest.h>

int main(int argc, char* argv[])
{    
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

struct CVectorTestsSingleVec : testing::Test
{
    LinAlg::Vector::CVector<float>* vec;

    CVectorTestsSingleVec()
    {
        vec = new LinAlg::Vector::CVector<float>(3);
    }

    virtual ~CVectorTestsSingleVec()
    {
        delete vec;
    }
};

TEST_F(CVectorTestsSingleVec, MemberTests)
{
    EXPECT_EQ(3, vec->get_dim());

    EXPECT_EQ(LinAlg::Vector::EVectorTypes::None, vec->get_type());

    EXPECT_EQ(0, vec->get_data(0));
    EXPECT_EQ(0, vec->get_data(1));
    EXPECT_EQ(0, vec->get_data(2));

    float* test_data = new float[3];
    test_data[0] = 0;
    test_data[1] = 0;
    test_data[2] = 0;

    float* vec_data = vec->get_data();

    EXPECT_EQ(test_data[0], test_data[0]);
    EXPECT_EQ(test_data[1], test_data[1]);
    EXPECT_EQ(test_data[2], test_data[2]);

    delete test_data, vec_data;
}