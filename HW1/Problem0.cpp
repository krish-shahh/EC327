#include <iostream>
#include <limits>

using namespace std;

int main() {
    cout << "unsigned char min: " << (int) numeric_limits<unsigned char>::min() <<  endl;
    cout << "unsigned char max: " << (int) numeric_limits<unsigned char>::max() <<  endl;
    cout << "unsigned char size: " << sizeof(unsigned char) << " bytes" <<  endl;
    cout << "unsigned int min: " <<  numeric_limits<unsigned int>::min() <<  endl;
    cout << "unsigned int max: " <<  numeric_limits<unsigned int>::max() <<  endl;
    cout << "unsigned int size: " << sizeof(unsigned int) << " bytes" <<  endl;
    cout << "unsigned long min: " <<  numeric_limits<unsigned long>::min() <<  endl;
    cout << "unsigned long max: " <<  numeric_limits<unsigned long>::max() <<  endl;
    cout << "unsigned long size: " << sizeof(unsigned long) << " bytes" <<  endl;
    cout << "float min: " <<  numeric_limits<float>::min() <<  endl;
    cout << "float max: " <<  numeric_limits<float>::max() <<  endl;
    cout << "float size: " << sizeof(float) << " bytes" <<  endl;
    cout << "double min: " <<  numeric_limits<double>::min() <<  endl;
    cout << "double max: " <<  numeric_limits<double>::max() <<  endl;
    cout << "double size: " << sizeof(double) << " bytes" <<  endl;
  return 0;
}
