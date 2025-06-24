#ifndef QUIZ_LOADER_H
#define QUIZ_LOADER_H

#include <vector>
#include <string>
using namespace std;

// define the structure of each question
struct Question {
    string question;
    string optionA, optionB, optionC, optionD;
    char correctAnswer;
    string explanation;
};

// function prototype to load the questions (implementation in quiz_loader.cpp)
vector<Question> loadQuestions(const string& filename);


#endif