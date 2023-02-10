#include <iostream>
#include <limits>

int main() {
    std::cout << "unsigned char min: " << (int)std::numeric_limits<unsigned char>::min() << std::endl;
    std::cout << "unsigned char max: " << (int)std::numeric_limits<unsigned char>::max() << std::endl;
    std::cout << "unsigned char size: " << sizeof(unsigned char) << " bytes" << std::endl;
    std::cout << "unsigned int min: " << std::numeric_limits<unsigned int>::min() << std::endl;
    std::cout << "unsigned int max: " << std::numeric_limits<unsigned int>::max() << std::endl;
    std::cout << "unsigned int size: " << sizeof(unsigned int) << " bytes" << std::endl;
    std::cout << "unsigned long min: " << std::numeric_limits<unsigned long>::min() << std::endl;
    std::cout << "unsigned long max: " << std::numeric_limits<unsigned long>::max() << std::endl;
    std::cout << "unsigned long size: " << sizeof(unsigned long) << " bytes" << std::endl;
    std::cout << "float min: " << std::numeric_limits<float>::min() << std::endl;
    std::cout << "float max: " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "float size: " << sizeof(float) << " bytes" << std::endl;
    std::cout << "double min: " << std::numeric_limits<double>::min() << std::endl;
    std::cout << "double max: " << std::numeric_limits<double>::max() << std::endl;
    std::cout << "double size: " << sizeof(double) << " bytes" << std::endl;
    return 0;
}
