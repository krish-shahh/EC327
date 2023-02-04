/*
    Write a program that reads two times in military format (0900, 1730) and prints the number of hours and minutes between the two times. 
    For extra credit, implement a case where the first time is later than the second time.
*/

#include <iostream>
#include <chrono>
#include <ctime>

#include <iostream>
#include <cmath>

int main() {
    int first_time, second_time;
    std::cout << "Enter first time (in military format, e.g. 0900): ";
    std::cin >> first_time;
    std::cout << "Enter second time (in military format, e.g. 1730): ";
    std::cin >> second_time;

    int first_hours = first_time / 100;
    int first_minutes = first_time % 100;
    int second_hours = second_time / 100;
    int second_minutes = second_time % 100;

    int total_minutes_first = first_hours * 60 + first_minutes;
    int total_minutes_second = second_hours * 60 + second_minutes;
    int difference;

    if (total_minutes_first <= total_minutes_second) {
        difference = total_minutes_second - total_minutes_first;
    } else {
        difference = 1440 - (total_minutes_first - total_minutes_second);
    }

    int hours = std::floor(difference / 60);
    int minutes = difference % 60;

    std::cout << "The difference between the times is: " << hours << " hours and " << minutes << " minutes" << std::endl;

    return 0;
}

