#include "quiz_logic.h"
#include <iostream>
#include <cctype> 
using namespace std;

int runQuiz(const vector<Question>& quiz) {
    int score = 0;
    char userAnswer;

    cout << "Welcome to the Digital Survival Skills Quiz!" << endl;
    cout << "Ready to take on the challenge?" << endl;

    for (int i = 0; i < quiz.size(); i++) {
        const Question& question = quiz[i];

        cout << "Q" << i + 1 << ": " << question.question << endl;
        cout << "A) " << question.optionA << "\n";
        cout << "B) " << question.optionB << "\n";
        cout << "C) " << question.optionC << "\n";
        cout << "D) " << question.optionD << "\n";

        cin >> userAnswer;
        userAnswer = toupper(userAnswer);

        if (userAnswer == question.correctAnswer) {
            cout << "CORRECT! " << question.explanation << endl << endl;
            score++;
        }
        else {
            cout << "WRONG! The correct answer is: " << question.correctAnswer << ". \n";
            cout << "Explanation: " << question.explanation << endl << endl;
        }
    }
    return score;
}