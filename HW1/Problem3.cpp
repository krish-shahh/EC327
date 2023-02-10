#include <iostream>

int main() {
    float flt = 0;
    while (flt <= 200) {
        flt += 0.2;
    }

    std::cout << "The final value of flt is: " << flt << std::endl;
    return 0;
}
