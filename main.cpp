#include <iostream>
#include "quiz_loader.h"
#include "quiz_logic.h"
using namespace std;

int main() {
    vector<Question> quiz = loadQuestions("quiz.txt");

    int score = runQuiz(quiz);
    cout << "Quiz Complete! Your final score: " << score << "/" << quiz.size();

    return 0;
}