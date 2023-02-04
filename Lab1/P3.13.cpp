#include <iostream>
#include <string>

std::string roman_numeral(int num) {
  std::string result;
  std::string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
  int decimal[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  for (int i = 0; num != 0; i++) {
    while (num >= decimal[i]) {
      result += roman[i];
      num -= decimal[i];
    }
  }
  return result;
}

int main() {
  int value;
  std::cout << "Enter a number: ";
  std::cin >> value;
  std::cout << "The corresponding Roman numeral is: " << roman_numeral(value) << std::endl;
  return 0;
}
