#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    Student(const string& name) : name_(name), total_score_(0), num_quizzes_(0) {}

    string get_name() const {
        return name_;
    }

    void add_quiz(int score) {
        total_score_ += score;
        ++num_quizzes_;
    }

    int get_total_score() const {
        return total_score_;
    }

    double get_average_score() const {
        return static_cast<double>(total_score_) / num_quizzes_;
    }

private:
    string name_;
    int total_score_;
    int num_quizzes_;
};
