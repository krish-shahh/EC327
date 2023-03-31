#include <ctime>
#include <iostream>
#include <string>

using namespace std;

class Clock {
public:
    virtual int get_hours() const {
        time_t current_time = time(0);
        tm* local_time = localtime(&current_time);
        return local_time->tm_hour;
    }

    int get_minutes() const {
        time_t current_time = time(0);
        tm* local_time = localtime(&current_time);
        return local_time->tm_min;
    }

    string get_time() const {
        int hours = get_hours();
        int minutes = get_minutes();
        string am_pm = (hours < 12) ? "AM" : "PM";
        if (hours > 12) hours -= 12;
        if (hours == 0) hours = 12;
        char buffer[9];
        sprintf(buffer, "%02d:%02d %s", hours, minutes, am_pm.c_str());
        return string(buffer);
    }
};

class WorldClock : public Clock {
private:
    int time_offset;

public:
    WorldClock(int offset) : time_offset(offset) {}

    int get_hours() const override {
        int hours = Clock::get_hours() + time_offset;
        if (hours >= 24) hours -= 24;
        if (hours < 0) hours += 24;
        return hours;
    }

};

int main() {
    Clock c;
    cout << "Current (NY) time: " << c.get_time() << endl;

    WorldClock wc(-3); // California is 3 hours behind NY
    cout << "California time: " << wc.get_time() << endl;

    return 0;
}
