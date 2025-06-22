#include "quiz_logic.h"
#include <iostream>
#include <cctype> 
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

QuizResult runQuiz(const vector<Question>& quiz) {
    int score = 0;
    char userAnswer;

    cout << "Welcome to the Digital Survival Skills Quiz!" << endl;
    cout << "Ready to take on the challenge?" << endl;

    vector<Question> shuffledQuiz = quiz;

    // Shuffle the full question set randomly
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(shuffledQuiz.begin(), shuffledQuiz.end(), default_random_engine(seed));

    // Only use first 15 questions
    vector<Question> selectedQuestions(shuffledQuiz.begin(), shuffledQuiz.begin() + min(15, (int)shuffledQuiz.size()));

    for (int i = 0; i < selectedQuestions.size(); i++) {
        const Question& question = selectedQuestions[i];

        cout << "Q" << i + 1 << ": " << question.question << endl;
        cout << "A) " << question.optionA << "\n";
        cout << "B) " << question.optionB << "\n";
        cout << "C) " << question.optionC << "\n";
        cout << "D) " << question.optionD << "\n";

        while (true) {
            cout << "Your answer (A/B/C/D): ";
            cin >> userAnswer;

            // check for termination by user (ctrl d, ctrl z, ctrl c)
            if (cin.eof()) {
                cout << "\nProgram terminated by user. Exiting..." << endl;
                return {score, static_cast<int>(selectedQuestions.size())};  
            }

            // Check for other input errors
            if (!cin) {
                cin.clear(); // clear error flags
                cin.ignore(10000, '\n'); // discard bad input
                cout << "Invalid input. Please enter only A, B, C or D.\n";
                continue;
            }

            userAnswer = toupper(userAnswer);

            if (userAnswer == 'A' || userAnswer == 'B' || userAnswer == 'C' || userAnswer == 'D') {
                break;
            }
            cout << "Invalid input. Please enter only A, B, C or D.\n";
        }

        if (userAnswer == question.correctAnswer) {
            cout << "CORRECT! " << question.explanation << endl << endl;
            score++;
        }
        else {
            cout << "WRONG! The correct answer is: " << question.correctAnswer << ". \n";
            cout << "Explanation: " << question.explanation << endl << endl;
        }
    }
    return {score, static_cast<int>(selectedQuestions.size())};
}