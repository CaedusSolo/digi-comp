#include <iostream>
#include "quiz_loader.h"
#include "quiz_logic.h"
using namespace std;

int main() {
    // call loadQuestions to get the questions
    vector<Question> quiz = loadQuestions("quiz.txt");

    // call runQuiz to start the quiz loop
    QuizResult result = runQuiz(quiz);

    int score = result.score;
    int totalQuestions = result.totalQuestions ? result.totalQuestions : 15;

    // display final score
    cout << "Quiz Complete! Your final score: " << score << "/" << totalQuestions << ". \n";

    return 0;
}