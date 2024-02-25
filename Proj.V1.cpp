#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

// Question structure to store question, options, and correct answer
struct Question {
    string questionText;
    string options[4];
    int correctOption;
};

// Function to shuffle options (except the correct one)
void shuffleOptions(Question& question) {
    srand(time(nullptr));
    for (int i = 0; i < 3; ++i) {
        int randomIndex = rand() % 4;
        swap(question.options[i], question.options[randomIndex]);
    }
}

// Function to display question, options, and get user's answer
bool askQuestion(Question& question) {
    shuffleOptions(question); // Shuffle options (except the correct one)
    cout << question.questionText << endl;
    for (int i = 0; i < 4; ++i) {
        cout << i+1 << ". " << question.options[i] << endl;
    }
    cout << "Enter your choice (1-4): ";
    int userChoice;
    cin >> userChoice;
    cin.ignore(); // Ignore newline character in input buffer
    // Check if user's answer is correct
    return userChoice == question.correctOption;
}

// Function to shuffle questions
void shuffleQuestions(Question questions[], int numQuestions) {
    srand(time(nullptr));
    for (int i = 0; i < numQuestions; ++i) {
        int randomIndex = rand() % numQuestions;
        swap(questions[i], questions[randomIndex]);
    }
}

// Function to display score
void displayScore(int score, int totalQuestions) {
    cout << "\n************ Quiz Ended ************" << endl;
    cout << "Your final score is: " << score << "/" << totalQuestions << endl;
}

int main() {
    // Array of questions
    Question questions[] = {
        {"What is the capital of France?", {"Paris", "London", "Berlin", "Rome"}, 1},
        {"What is 2 + 2?", {"3", "4", "5", "6"}, 2},
        {"What is the largest mammal?", {"Elephant", "Blue Whale", "Giraffe", "Hippo"}, 2},
        {"What is the chemical symbol for water?", {"H2O", "CO2", "N2O", "HCl"}, 1}
    };

    // Shuffle questions
    int numQuestions = sizeof(questions) / sizeof(questions[0]);
    shuffleQuestions(questions, numQuestions);

    int score = 0; // Initialize score to 0

    // Iterate through each question
    for (int i = 0; i < numQuestions; ++i) {
        cout << "\n************ Question " << i+1 << " ************" << endl;
        if (askQuestion(questions[i])) {
            cout << "Correct!" << endl;
            score++;
        } else {
            cout << "Incorrect!" << endl;
        }
        // Pause for 2 seconds before displaying the next question
        this_thread::sleep_for(chrono::seconds(2));
    }

    // Display final score
    displayScore(score, numQuestions);

    return 0;
}
