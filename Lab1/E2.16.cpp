/*
    Write a program that reads two times in military format (0900, 1730) and prints the number of hours and minutes between the two times.
*/

#include <iostream>

int main() {
    int first_time, second_time, duration_in_minutes;
    std::cout << "Please enter the first time: ";
    std::cin >> first_time;
    std::cout << "Please enter the second time: ";
    std::cin >> second_time;

    if (first_time <= second_time) {
        duration_in_minutes = (second_time - first_time) % 2400;
    } else {
        duration_in_minutes = (2400 - first_time + second_time) % 2400;
    }

    int hours = duration_in_minutes / 100;
    int minutes = duration_in_minutes % 100;

    std::cout << hours << " hours " << minutes << " minutes" << std::endl;

    return 0;
}


