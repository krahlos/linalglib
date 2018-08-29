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
    // get dimension
    EXPECT_EQ(3, vec->get_dim());

    // get type
    EXPECT_EQ(LinAlg::Vector::EVectorTypes::None, vec->get_type());

    // get single data
    EXPECT_EQ(0, vec->get_data(0));
    EXPECT_EQ(0, vec->get_data(1));
    EXPECT_EQ(0, vec->get_data(2));

    // get all data
    std::vector<float> test_data(3,0);

    std::vector<float>* vec_data = vec->get_data();

    size_t test_data_size = test_data.size();
    size_t vec_data_size = vec_data->size();

    EXPECT_EQ(test_data_size, vec_data_size);

    for(size_t i = 0; i < test_data_size; i++)
        EXPECT_EQ(test_data.at(i), vec_data->at(i));
}

TEST_F(CVectorTestsSingleVec, CopyOperatorTest)
{
    LinAlg::Vector::CVector<float> cop = *vec;

    EXPECT_EQ(cop.get_dim(), vec->get_dim());
    EXPECT_EQ(cop.get_type(), vec->get_type());

    std::vector<float>* cop_data = cop.get_data();

    std::vector<float>* vec_data = vec->get_data();

    size_t cop_data_size = cop_data->size();
    size_t vec_data_size = vec_data->size();

    EXPECT_EQ(cop_data_size, vec_data_size);

    for(size_t i = 0; i < cop_data_size; i++)
        EXPECT_EQ(cop_data->at(i), vec_data->at(i));
}

TEST_F(CVectorTestsSingleVec, CopyConstrustorTest)
{
    LinAlg::Vector::CVector<float> cop(*vec);

    EXPECT_EQ(cop.get_dim(), vec->get_dim());
    EXPECT_EQ(cop.get_type(), vec->get_type());

    std::vector<float>* cop_data = cop.get_data();

    std::vector<float>* vec_data = vec->get_data();

    size_t cop_data_size = cop_data->size();
    size_t vec_data_size = vec_data->size();

    EXPECT_EQ(cop_data_size, vec_data_size);

    for(size_t i = 0; i < cop_data_size; i++)
        EXPECT_EQ(cop_data->at(i), vec_data->at(i));
}

struct CVectorTestsMultiVec : testing::Test
{
    LinAlg::Vector::CVector<float> *vec1, *vec2;

    CVectorTestsMultiVec()
    {
        vec1 = new LinAlg::Vector::CVector<float>(3);
        vec2 = new LinAlg::Vector::CVector<float>(3);
    }

    virtual ~CVectorTestsMultiVec()
    {
        delete vec1, vec2;
    }
};

TEST_F(CVectorTestsMultiVec, OperatorTestPlus)
{

}

TEST_F(CVectorTestsMultiVec, OperatorTestMinus)
{
    
}