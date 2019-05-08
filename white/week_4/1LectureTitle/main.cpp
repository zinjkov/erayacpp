//
// Created by Zinkov on 25.04.2019.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Specialization {
    explicit Specialization(string sp) : specialization(move(sp)) {}
    string specialization;
};

struct  Course {
    explicit Course(string c) : course(move(c)) {}
    string course;
};

struct Week {
    explicit Week(string w) : week(move(w)) {}
    string week;
};

struct LectureTitle {
    LectureTitle(Specialization sp, Course c, Week w) :
     specialization(sp.specialization),
     course(c.course),
     week(w.week){}
    string specialization;
    string course;
    string week;
};

int main() {
    LectureTitle title(
            Specialization("C++"),
            Course("White belt"),
            Week("4th")
    );

//    LectureTitle title("C++", "White belt", "4th");

//    LectureTitle title(string("C++"), string("White belt"), string("4th"));
//
//    LectureTitle title = {"C++", "White belt", "4th"};
//
//    LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};
//
//    LectureTitle title(
//            Course("White belt"),
//            Specialization("C++"),
//            Week("4th")
//    );
//
//    LectureTitle title(
//            Specialization("C++"),
//            Week("4th"),
//            Course("White belt")
//    );
}