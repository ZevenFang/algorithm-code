//
// Created by Zeven Fang on 2017/4/30.
//

#ifndef ALGORITHM_STUDENT_H
#define ALGORITHM_STUDENT_H

#include <iostream>

using namespace std;

struct Student{

    string name;
    int score;

    bool operator<(Student &other){
        return score == other.score ? name < other.name : score < other.score;
    }

    friend ostream&operator<<(ostream &os, const Student &student){
        os<<"Student: "<<student.name<<" "<<student.score<<endl;
        return os;
    }


};

#endif //ALGORITHM_STUDENT_H
