#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class p94c {
public:
    // Constructor with given name and no friends
    p94c(const string& name) : name_(name) {}

    // Adds p as a friend of this person
    void befriend(p94c* p) {
        if (!is_friend(p)) {
            friends_.push_back(p);
        }
    }

    // Removes p as a friend of this person
    void unfriend(p94c* p) {
        auto it = find(friends_.begin(), friends_.end(), p);
        if (it != friends_.end()) {
            friends_.erase(it);
        }
    }

    // Returns a string with the names of all friends separated by spaces
    string get_friend_names() const {
        string result;
        for (const auto& friend_ptr : friends_) {
            result += friend_ptr->name_ + " ";
        }
        return result;
    }

private:
    string name_;
    vector<p94c*> friends_;

    // Returns true if p is already a friend of this person
    bool is_friend(p94c* p) const {
        return find(friends_.begin(), friends_.end(), p) != friends_.end();
    }
};
