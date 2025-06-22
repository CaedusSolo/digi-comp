#include <iostream>
#include "quiz_loader.h"
#include "quiz_logic.h"
using namespace std;

int main() {
    // call loadQuestions to get the questions
    vector<Question> quiz = loadQuestions("quiz.txt");

    // call runQuiz to start the quiz loop
    QuizResult result = runQuiz(quiz);

    // display final score
    cout << "Quiz Complete! Your final score: " << result.score << "/" << result.totalQuestions;

    return 0;
}