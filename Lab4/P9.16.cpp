#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Letter {
public:
    Letter(string from, string to) : from_{from}, to_{to} {}
    
    void add_line(string line) {
        body_.push_back(line);
    }
    
    string get_text() {
        string text = "Dear " + to_ + ":\n\n";
        for (const auto& line : body_) {
            text += line + "\n";
        }
        text += "\nSincerely,\n\n" + from_;
        return text;
    }
    
private:
    string from_;
    string to_;
    vector<string> body_;
};

