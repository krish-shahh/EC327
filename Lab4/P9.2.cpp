#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
public:
    // Constructor with given name and no friends
    Person(const string& name) : name_(name) {}

    // Adds p as a friend of this person
    void befriend(const Person& p) {
        if (!is_friend(p)) {
            friends_.push_back(p.name_);
        }
    }

    // Removes p as a friend of this person
    void unfriend(const Person& p) {
        auto it = find(friends_.begin(), friends_.end(), p.name_);
        if (it != friends_.end()) {
            friends_.erase(it);
        }
    }

    // Returns a string with the names of all friends separated by spaces
    string get_friend_names() const {
        string result;
        for (const auto& friend_name : friends_) {
            result += friend_name + " ";
        }
        return result;
    }

private:
    string name_;
    vector<string> friends_;

    // Returns true if p is already a friend of this person
    bool is_friend(const Person& p) const {
        return find(friends_.begin(), friends_.end(), p.name_) != friends_.end();
    }
};
