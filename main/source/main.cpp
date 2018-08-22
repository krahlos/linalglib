#include <iostream>

#include <cmatrix.h>
#include <cvector.h>

int main(int argc, const char * argv [])
{
    std::cout << "Hello @ LinAlg C++ Project" << std::endl;

    LinAlg::Vector::CVector<float> vec1(3);

    vec1.show();

    std::cout << "Good Bye!" << std::endl;    

    return 0;
}
