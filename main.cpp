#include <iostream>
#include "quiz_loader.h"
#include "quiz_logic.h"
using namespace std;

int main() {
    vector<Question> quiz = loadQuestions("quiz.txt");

    QuizResult result = runQuiz(quiz);
    cout << "Quiz Complete! Your final score: " << result.score << "/" << result.totalQuestions;

    return 0;
}