#ifndef QUIZ_LOADER_H
#define QUIZ_LOADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

struct Question {
    string question;
    string optionA, optionB, optionC, optionD;
    char correctAnswer;
    string explanation;
};

vector<Question> loadQuestions(const string& filename);


#endif