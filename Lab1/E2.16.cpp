/*
    Write a program that reads two times in military format (0900, 1730) and prints the number of hours and minutes between the two times. 
    For extra credit, implement a case where the first time is later than the second time.
*/

#include <iostream>
#include <chrono>
#include <ctime>

int main() {
    int firstTime, secondTime;
    std::cout << "Enter first time (in military format): ";
    std::cin >> firstTime;
    std::cout << "Enter second time (in military format): ";
    std::cin >> secondTime;

    int duration;
    if (firstTime > secondTime) {
        duration = 2400 - (firstTime - secondTime);
    } else {
        duration = secondTime - firstTime;
    }

    int hours = duration / 100;
    int minutes = duration % 100;

    std::cout << "The duration between the times is " << hours << " hours and " << minutes << " minutes." << std::endl;

    return 0;
}
