#ifndef QUIZ_LOGIC_H
#define QUIZ_LOGIC_H

#include "quiz_loader.h"
using namespace std;

// define the structure of how the result will be stored
struct QuizResult {
    int score;
    int totalQuestions;
};

// function prototype for runQuiz (implementation in quiz_logic.cpp)
QuizResult runQuiz(const vector<Question>& quiz);

#endif