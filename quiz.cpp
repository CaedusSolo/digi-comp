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

vector<Question> loadQuestions(const string& filename) {
    vector<Question> quiz;
    ifstream file(filename);
    if (!file) {
        cerr << "Failed to open file.\n";
        return quiz;
    }

    string line;
    Question q;
    while (getline(file, line)) {
        if (line.rfind("Q:", 0) == 0) q.question = line.substr(3);
        else if (line.rfind("A)", 0) == 0) q.optionA = line.substr(2);
        else if (line.rfind("B)", 0) == 0) q.optionB = line.substr(2);
        else if (line.rfind("C)", 0) == 0) q.optionC = line.substr(2);
        else if (line.rfind("D)", 0) == 0) q.optionD = line.substr(2);
        else if (line.rfind("ANSWER:", 0) == 0) q.correctAnswer = toupper(line[8]);
        else if (line.rfind("EXPLANATION:", 0) == 0) {
            q.explanation = line.substr(12);
            quiz.push_back(q);
        }
    }
    return quiz;
}

int main() {
    vector<Question> quiz = loadQuestions("quiz.txt");
    if (quiz.empty()) {
        cout << "No questions loaded.\n";
        return 1;
    }

    int score = 0;
    char userAnswer;
    cout << "Welcome to the Digital Survival Skills Quiz!\n\n";

    for (size_t i = 0; i < quiz.size(); ++i) {
        const Question& q = quiz[i];
        cout << "Q" << i + 1 << ": " << q.question << "\n";
        cout << "A) " << q.optionA << "\n";
        cout << "B) " << q.optionB << "\n";
        cout << "C) " << q.optionC << "\n";
        cout << "D) " << q.optionD << "\n";
        cout << "Your answer (A/B/C/D): ";
        cin >> userAnswer;
        userAnswer = toupper(userAnswer);

        if (userAnswer == q.correctAnswer) {
            cout << "✅ Correct! " << q.explanation << "\n\n";
            score++;
        } else {
            cout << "❌ Wrong! The correct answer was " << q.correctAnswer << ". " << q.explanation << "\n\n";
        }
    }

    cout << "Quiz finished! You scored " << score << " out of " << quiz.size() << ".\n";
    return 0;
}
