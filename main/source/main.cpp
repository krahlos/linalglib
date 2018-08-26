#include <iostream>

#include <cmatrix.h>

int main(int argc, const char * argv [])
{
    std::cout << "Hello @ LinAlg C++ Project" << std::endl;

    LinAlg::Vector::CVector<float> vec1(3), vec2(3);

    vec1.set_value(0, 1.0);
    vec1.set_value(1, 2.0);
    vec1.set_value(2, 3.0);

    vec2.set_value(0, 1.0);
    vec2.set_value(1, 2.0);
    vec2.set_value(2, 3.0);

    vec1.show();
    vec2.show();

    LinAlg::Vector::CVector<float> vec3 = vec1 + vec2;

    std::cout << "vec3: " << vec3.to_string() << std::endl;

    std::cout << "Good Bye!" << std::endl;    

    return 0;
}
