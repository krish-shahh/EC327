/*
Write a program that reads in three integers and prints “in order” if they are sorted in ascending or descending order, or “not in order” otherwise.
*/

#include <iostream>

int main() {
  int num1, num2, num3;

  std::cout << "Enter first integer: ";
  std::cin >> num1;
  std::cout << "Enter second integer: ";
  std::cin >> num2;
  std::cout << "Enter third integer: ";
  std::cin >> num3;

  if (num1 <= num2 && num2 <= num3) {
    std::cout << "In order (ascending)" << std::endl;
  } else if (num1 >= num2 && num2 >= num3) {
    std::cout << "In order (descending)" << std::endl;
  } else {
    std::cout << "Not in order" << std::endl;
  }

  return 0;
}



