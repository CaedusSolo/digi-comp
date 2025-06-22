#include "quiz_loader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;

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