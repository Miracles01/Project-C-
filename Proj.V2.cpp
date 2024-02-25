#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
#include <iomanip>

using namespace std;

// Function prototypes
void menu();
void start();
void howToPlay();
void quiz();

// Global variables
string playerName;
string topic;
int choice;

// Structure to store question data
struct Question {
    string questionText;
    string options[4];
    int correctOption;
};

// Function to shuffle options (except the correct one)
void shuffleOptions(Question& question) {
    srand(time(nullptr));
    int correctOptionIndex = question.correctOption - 1;
    int cheaker[4] = {0,0,0,0};
    cheaker[correctOptionIndex] = 1;
    for (int i = 0; i < 3; ++i) {
        int randomIndex = rand() % 4;
        swap(question.options[i], question.options[randomIndex]);
        swap(cheaker[i],cheaker[randomIndex]);
      
       
    }
   for(int j = 0; j < 4; ++j){
    if(cheaker[j]==1)question.correctOption = j+1;
    }
}

// Function to ask a question and get user's answer
bool askQuestion(const Question& question) {
    Question shuffledQuestion = question;
    shuffleOptions(shuffledQuestion); // Shuffle options
    cout << question.questionText << endl;
    for (int i = 0; i < 4; ++i) {
        cout << i + 1 << ". " << shuffledQuestion.options[i] << endl;
    }
    cout << "Enter your choice (1-4): ";
    int userChoice;
    cin >> userChoice;
    cin.ignore(); // Ignore newline character in input buffer
    return userChoice == shuffledQuestion.correctOption;
}

// Function to display final score
void displayScore(int score, int totalQuestions) {
    cout << "\n************ Quiz Ended ************" << endl;
    cout << "Your final score is: " << score << "/" << totalQuestions << endl;
}

// Function to start the game
void start() {
    cout << "\nI N F O R M A T I O N   T A B L E\n\n";
    cout << "What is your name? ";
    getline(cin, playerName);
    cout << "Which topic would you like to play?" << endl;
    cout << "[1]. ********" << endl;
    cout << "[2]. *********" << endl;
    cout << "[3]. ************" << endl;
    do {
        cout << "Choose which topic you want to play: ";
        cin >> topic;
        cin.clear();
    } while (topic != "1" && topic != "2" && topic != "3");
    string response;
    cout << "Are you ready to take the Quiz " << playerName << "? (Yes/No): ";
    cin >> response;
    if (response == "Yes" || response == "yes") {
        cout << "OK, Good Luck!!!" << endl;
    } else {
        cout << "OK. Goodbye." << endl;
        exit(0);
    }
}

// Function to display how to play instructions
void howToPlay() {
    system("cls");
    cout << "\t\t\t\t\t\t H  O  W  T  O  P  L  A  Y" << endl;
    cout << "   ___________________________________________________________________________________________" << endl;
    cout << " / \\                                                                                  ." << endl;
    cout << "|   |                                                                                        |." << endl;
    cout << " \\_| 1. CHOOSE THE TOPIC QUESTIONS YOU ARE INTERESTED IN PLAYING.                              |." << endl;
    cout << "    |                                                                                        |." << endl;
    cout << "    | 2. YOU WILL EARN 10 POINTS WHEN YOU ANSWER THE CORRECT QUESTION.                        |." << endl;
    cout << "    |                                                                                        |." << endl;
    cout << "    | 3. ADDITIONALLY, YOU WILL HAVE SOME HINTS WHICH YOU CAN USE FROM THE 8TH QUESTION.       |." << endl;
    cout << "    |    IF THE ANSWER IS CORRECT WHEN YOU ARE USING HINTS, YOU WILL ONLY GET 1 POINT.        |." << endl;
    cout << "    |                                                                                        |." << endl;
    cout << "    | 4. AFTER PLAYING, THE SYSTEM WILL SORT THE SCORE.                                      |." << endl;
    cout << "    |                                                                                        |." << endl;
    cout << "    |   _______________________________________________________________________________________|." << endl;
    cout << "    |  /                                                                                       /." << endl;
    cout << "    \\_/______________________________________________________________________________________/." << endl;
    cout << "\n\n";
    system("pause");
}

// Function to handle quiz logic
void quiz() {
    // Array of questions
    Question questions[] = {
        {"What is the capital of France?", {"Paris", "London", "Berlin", "Rome"}, 1},
        {"What is 2 + 2?", {"3", "4", "5", "6"}, 2},
        {"What is the largest mammal?", {"Elephant", "Blue Whale", "Giraffe", "Hippo"}, 2},
        {"What is the chemical symbol for water?", {"H2O", "CO2", "N2O", "HCl"}, 1}
    };

    int numQuestions = sizeof(questions) / sizeof(questions[0]);
    int score = 0;

    // Iterate through each question
    for (int i = 0; i < numQuestions; ++i) {
        cout << "\n************ Question " << i + 1 << " ************" << endl;
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
}

// Function to display the main menu
void menu() {
    system("cls");
    system("color 0A");
    cout << "\n\n\n\t\t\t\t   __      __   ___  | |   ___    ___    _ __ ___     ___  " << endl;
    cout << "\t\t\t\t   \\ \\ /\\ / /  / _ \\ | |  / __|  / _ \\  | '_ ` _ \\   / _ \\ " << endl;
    cout << "\t\t\t\t    \\ V  V /  |  __/ | | | (__  | (_) | | | | | | | |  __/ " << endl;
    cout << "\t\t\t\t     \\_/\\_/    \\___| |_|  \\___|  \\___/  |_| |_| |_|  \\___| " << endl;
    cout << endl;
    cout << "\t\t\t\t\t\tWelcome to the Quiz Game!\t\t\t\t\t\t\t\t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t\t  1. Start Game\t\t\t\t\t\t\t\t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t\t  2. How to Play\t\t\t\t\t\t\t\t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t\t  3. Exit\t\t\t\t\t\t\t\t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t\tEnter your choice: ";
    cin >> choice;
}

// Main function
int main() {
    menu();
    switch (choice) {
        case 1:
            start();
            quiz();
            break;
        case 2:
            howToPlay();
            main(); // Go back to main menu
            break;
        case 3:
            cout << "Exiting the game..." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
            main(); // Go back to main menu
            break;
    }
    return 0;
}
