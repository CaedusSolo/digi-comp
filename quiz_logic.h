#ifndef QUIZ_LOGIC_H
#define QUIZ_LOGIC_H
#include "quiz_loader.h"
using namespace std;

struct QuizResult {
    int score;
    int totalQuestions;
};

QuizResult runQuiz(const vector<Question>& quiz);

#endif