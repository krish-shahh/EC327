/*
    Write a program that reads two times in military format (0900, 1730) and prints the number of hours and minutes between the two times. For extra credit, implement a case where the first time is later than the second time.
*/

#include <iostream>
#include <cstdlib>

void time_difference(std::string time1, std::string time2) {
    // Convert the times to minutes
    int minutes1 = stoi(time1.substr(0, 2)) * 60 + stoi(time1.substr(2));
    int minutes2 = stoi(time2.substr(0, 2)) * 60 + stoi(time2.substr(2));
    
    // Calculate the difference in minutes
    int difference = 0;
    if (minutes2 >= minutes1) {
        difference = minutes2 - minutes1;
    } else {
        difference = 1440 - (minutes1 - minutes2); // 1440 (24*60) is the total number of minutes in a day
    }
    
    // Convert the difference to hours and minutes
    int hours = difference / 60;
    int minutes = difference % 60;
    
    // Print the result
    std::cout << hours << " hours and " << minutes << " minutes" << std::endl;
}

int main() {
    std::string time1, time2;
    
    std::cout << "Enter the first time (in military format): ";
    std::cin >> time1;
    
    std::cout << "Enter the second time (in military format): ";
    std::cin >> time2;
    
    time_difference(time1, time2);
    
    return 0;
}




