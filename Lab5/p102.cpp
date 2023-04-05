#include <ctime>
#include <iostream>
#include <string>

using namespace std;

class Clock {
private:
    int alarm_hours = -1;
    int alarm_minutes = -1;
    bool alarm_set = false;

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

    string get_time() {
        int hours = get_hours();
        int minutes = get_minutes();
        string am_pm = (hours < 12) ? "AM" : "PM";
        if (hours > 12) hours -= 12;
        if (hours == 0) hours = 12;
        char buffer[9];
        sprintf(buffer, "%02d:%02d %s", hours, minutes, am_pm.c_str());

        if (alarm_set && hours >= alarm_hours && minutes >= alarm_minutes) {
            alarm_set = false;
            cout << "Alarm!" << endl;
            return string(buffer) + " \u23F0";
        }

        return string(buffer);
    }

    void set_alarm(int hours, int minutes) {
        alarm_hours = hours;
        alarm_minutes = minutes;
        alarm_set = true;
        cout << "Alarm set for " << hours << ":" << minutes << endl;
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

    c.set_alarm(3, 42);

    for (int i = 0; i < 10; i++) {
        cout << "Current (NY) time: " << c.get_time() << endl;
        cout << "California time: " << wc.get_time() << endl;
        // Wait for 1 second
        clock_t start_time = clock();
        while (clock() - start_time < CLOCKS_PER_SEC);
    }

    return 0;
}
