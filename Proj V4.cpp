//ตอนนี้แต่งสีให้แล้ว ละก็ทำ leader bard ให้แล้ว ละก็เปลี่ยน ASCII ของ how to play และstart ละก็ ทำ user ให้แล้ว เรียบร้อยยย
// BUG แต่ว่ามีปัญหาตรงที่เวลาหลัง leader bard แล้ว มันจะถามว่า ต้องการเล่นอีกครั้งไหม พอบอกว่าใข่มันจะเด้องออกแล้วให้0คะแนนทันทีเลย  เรียบร้อยย



//ทำ leader bard ของหัวข้อที่ 5 เพิ่ม และ หลังจากที่เราแพ้ในหัวข้อที่5ให้โชว สตริง ว่าเราแพ้  เรียบร้อยย

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

string Name[5];
string topic;
int choice;
int totalQuestions;
int score;

// Structure to store question data
struct Question {
    string questionText;
    string options[100];
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



void shuffleQuestions(Question questions[], int numQuestions) {
    srand(time(nullptr));
    for (int i = 0; i < numQuestions; ++i) {
        int randomIndex = rand() % numQuestions;
        swap(questions[i], questions[randomIndex]);
    }
}






// Function to ask a question and get user's answer
bool askQuestion(const Question& question) {
     ////////////////////////////
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
    system("color 0A");
    cout << "    _.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._.-=-._\n"
         << ".-'---      - ---     --     ---   -----   - --       ----  ----   -     ---`-.\n"
         << " )                                                                           (\n"
         << "(                           L E A D E R   B A R D                             )\n"
         << " )                                                                           (\n"
         << "(     1.     " << "Jeson" << ": " << "9" << "/" << "10" << endl
         << " )                                                                           (\n"
         << "(                                                                             )\n"
         << " )    2.     " << Name[0] << ": " << score << "/" << totalQuestions << endl
         << "(                                                                             )\n"
         << " )                                                                            (\n"
         << "(   *New*    " << Name[1] << ": " << score << "/" << totalQuestions << endl                                                                   
         << " )                                                                           (\n"
         << "(___       _       _       _       _       _       _       _       _       ___)\n"
         << "    `-._.-' (___ _) (__ _ ) (_   _) (__  _) ( __ _) (__  _) (__ _ ) `-._.-'\n"
         << "            `-._.-' (  ___) ( _  _) ( _ __) (_  __) (__ __) `-._.-'\n"
         << "                    `-._.-' (__  _) (__  _) (_ _ _) `-._.-'\n"
         << "                            `-._.-' (_ ___) `-._.-'\n"
         << "                                    `-._.-'\n";

    cout << "Do you want to start a QUIZ again? (Yes/No)" << endl;
    string playAgain;
    cin >> playAgain;
    if(playAgain == "Yes" || playAgain == "yes"){
        score = 0;
        menu();
    } else if(playAgain == "No" || playAgain == "no"){
        cout << "OK, Goodbye! ";
    }
}


// Function to start the game
void start() {
	if (cin.get() == '\n') {
	system("cls");
    system("color 0A");
    cout << "\nI N F O R M A T I O N   T A B L E\n\n";
    cout << "\tWhat is your name? " <<endl;
    std::cout << "    .       .\n"
                 "   |\\_---_/|\n"
                 "  /   o_o   \\\n"
                 " |     U     |\n"
                 " \\   ._I_.  /\n"
                 "   `-_____-'\n";

    getline(cin, Name[0]);
    cout << "Which topic would you like to play?" << endl;
    cout << "[1]. Animal World" << endl;
    cout << "[2]. science" << endl;
    cout << "[3]. mathematics" << endl;
    cout << "[4]. geography" << endl;
    cout << "[5]. Gamemode 3 life" << endl;
    do {
        cout << "Choose which topic you want to play: ";
        cin >> topic;
        cin.clear();
    } while (topic != "1" && topic != "2" && topic != "3"&& topic != "4"&& topic != "5");
    string response;
    cout << "Are you ready to take the Quiz " << Name[0] << "? (Yes/No): ";
    cin >> response;
    if (response == "Yes" || response == "yes") {
        cout << "OK, Good Luck!!!"<< Name[0] << endl;
    } else {
        cout << "OK. Goodbye "<< Name[0] <<"." << endl;
        exit(0);
    }
}
}
// Function to display how to play instructions
void howToPlay() {
    system("cls");
    system("color 0E");
    std::cout << "                     ,---.           ,---.         \n"
                 "                    / /\"`\\.---\"\"\"---./,'\"\\ \\        \n"
                 "                    \\ \\    _       _    / /        \n"
                 "                     `./  / __   __ \\  \\,'         \n"
                 "                      /    /_O)_(_O\\    \\          \n"
                 "                      |  .-'  ___  `-.  |          \n"
                 "                   .--|       \\_/       |--.       \n"
                 "                 ,'    \\   \\   |   /   /    `.     \n"
                 "                /       `.  `--^--'  ,'       \\    \n"
                 "             .-\"\"\"\"\"\"-.    `--.___.--'     .-\"\"\"\"\"\"-.  \n"
                 ".-----------/         \\------------------/         \\--------------.\n"
                 "| .---------\\         /----------------- \\         /------------. |\n"
                 "| |          `-`--`--'                    `--'--'-'             | |\n"
                 "| | 1. CHOOSE THE TOPIC QUESTIONS YOU ARE INTERESTED IN PLAYING.| |\n"
                 "| |                                                             | |\n"
                 "| | 2. YOU WILL EARN 10 POINTS WHEN YOU ANSWER THE CORRECT      | |\n"
                 "| |    QUESTION.                                                | |\n"
                 "| |                                                             | |\n"
                 "| | 3. ADDITIONALLY, YOU WILL HAVE SOME HINTS WHICH             | |\n"
                 "| |    YOU CAN USE FROM THE 8TH QUESTION.                       | |\n"
                 "| |    IF THE ANSWER IS CORRECT WHEN YOU ARE USING HINTS,       | |\n"
                 "| |    YOU WILL ONLY GET 1 POINT.                               | |\n"
                 "| |                                                             | |\n"
                 "| | 4. AFTER PLAYING, THE SYSTEM WILL SORT THE SCORE.           | |\n"
                 "| |_____________________________________________________________| |\n"
                 "|_________________________________________________________________|\n"
                 "                   )__________|__|__________(                \n"
                 "                  |            ||            |                \n"
                 "                  |____________||____________|                \n"
                 "                    ),-----.(      ),-----.(                  \n"
                 "                  ,'   ==.   \\    /  .==    `.                \n"
                 "                 /            )  (            \\               \n"
                 "                 `==========='    `==========='               \n";

   
    system("pause");
}



// Function to handle quiz logic
void quiz() {
    // Array of questions Animal World
    Question questions[] = {
        {"Which animal spends 90persent of its day sleeping?", {"Koala bear", "Panda bear", "Polar bear", "Grizzly bear"}, 1},
        {"Which animal is the fastest land animal?", {"Cheetah", "Leopard", "Tiger", "Ostrich"}, 1},
        {"Which animal has the longest lifespan in the world?", {"Tortoise", "Blue Whale", "Dolphin", "White shark"}, 1},
        {"Which animal species is most at risk of extinction?", {"Owl", "Heron", "Kiwi bird", "Hummingbird"}, 3},
        {"Which animal is highly intelligent with a high IQ?", {"Dog", "Cat", "Dolphin", "Fox"}, 3},
        
        {"Which animal is not fish?", {"salmon", "shark", "puffer fish", "whale"}, 4},
        {"Which animal dose not have lungs?", {"frogs", "snail", "octopus", "elephant"}, 3},
        {"how many hearts does an octopus have?", {"0", "1", "3", "2"}, 3},
        {"how many legs dose spider have?", {"4", "6", "8", "10"}, 3},
        {"Which animal is reptiles?", {"frogs", "Cat", "Dolphin", "snake"}, 4},
        {"Which animal is Amphibians?", {"salamander", "Cat", "Dolphin", "alligator"}, 1},
        {"Which animal is Mammals?", {"pigeon", "salamander", "Dolphin", "snake"}, 3},
        {"Which animal dose not have spine?", {"turtle", "salamander", "Dolphin", "octopus"}, 4},
        {"Which animal is cold-blooded animals?", {"Dog", "Cat", "Dolphin", "salmon"}, 4},
        {"which animal has the most population?", {"Insects", "Fish", "Birds", "Human"}, 1}
    };
   
    int numQuestions = sizeof(questions) / sizeof(questions[0]);
    int score = 0;
    shuffleQuestions(questions, numQuestions);
    // Iterate through each question
    for (int i = 0; i < 10; ++i) {
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
    displayScore(score, 10);
}

void quiz2() {
    // Array of questions วิทยาศสาตน์
    Question questions[] = {
        {"What did Isaac Newton discover?", {"X-ray", "Law of Gravitation", "Calculator", "Electricity"}, 2},
        {"Which mineral is essential for bones?", {"Carbon", "Chlorine", "Calcium", " Sodium"}, 3},
        {"Where are white blood cells produced?", {"Kidney", " Heart", " Spleen", "Bone marrow"}, 4},
        {"Earth is the ____ planet in the solar system.", {"2", "3", "4", "5"}, 2},
        {"The chemical symbol for the element Phosphorus is:", {"F", "Fe", "P", "K"}, 3},
        
        {"The chemical symbol for water is:", {"H2O", "CO2", "NO2", "H2O2"}, 1},
        {"How many colors do rainbow have", {"5", "8", "7", "6"}, 3},
        {"how many teeth do adults have?", {"34", "32", "30", "28"}, 2},
        {"Which food group is flour in ?", {"protein", "carbohydrates", "Fat", "vitamin"}, 2},
        {"How long is 1 rotation of the Earth in hours?", {"12", "18", "30", "24"}, 4},
        {"which gas do plants absorb for photosynthesis?", {"argon", "Oxygen", "Nitrogen", "Carbon dioxide"}, 4},
        {"what happen if weight on moon", {"decreases", "increase", "same", "all correct"}, 1},
        {"water turn to ice at what temperature?", {"50 degree Celsius", "100 degree Celsius", "0 degree Celsius", "150 degree Celsius"}, 3},
        {"which planet has the most moons?", {"Saturn", "Neptune", "Mars", "Mercury"}, 1},
        {"which planet closest to the sun?", {"Mars", "jupiter ", "Mercury", "uranus"}, 3}
    };
    
    int numQuestions = sizeof(questions) / sizeof(questions[0]);
    int score = 0;
    shuffleQuestions(questions, numQuestions);
    // Iterate through each question
    for (int i = 0; i < 10; ++i) {
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
    displayScore(score, 10);
}

void quiz3() {
    // Array of questions คณิต
    Question questions[] = {
        {"2x + 5 when x = 2", {"4", "6", "7", "9"}, 4},
        {"√625 + 50 - 20", {"65", "75", "55", "85"}, 3},
        {"7 x 7 - 3", {"46", "47", "45", "49"}, 1},
        {"6 + 3 - 4 + 2", {"6", "7", "8", "9"}, 2},
        {"7 + 6 + 4 + 7", {"21", "23", "24", "26"}, 3},
        
        {"378/0", {"0", "378", "1", "undefined"}, 4},
        {"2x2x2x2/4", {"2", "4", "8", "0"}, 2},
        {"10persent of 139", {"12.5", "13.9", "10", "13.99"}, 2},
        {"What is least common multiple of 3 and 12", {"21", "24", "12", "36"}, 3},
        {"What is greatest common factor of 36 and 4", {"4", "36", "24", "2"}, 1},
        {"1+1+1+1+1+1+1+1+1+1*2", {"11", "20", "5", "12"}, 1},
        {"sin 30° equal", {"1", "2", "0", "0.5"}, 4},
        {"size of rectangle that length=10  width=30 ", {"300", "40", "250", "400"}, 1},
        {"2+2", {"0", "4", "1", "5"}, 2},
        {"321x123", {"39483", "38755", "48653", "32123"}, 1}
    };
     
    int numQuestions = sizeof(questions) / sizeof(questions[0]);
    int score = 0;
    shuffleQuestions(questions, numQuestions);
    // Iterate through each question
    for (int i = 0; i < 10; ++i) {
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
    displayScore(score, 10);
}
void quiz4() {
    // Array of questions ภูมิศาสตร์
    Question questions[] = {
        {"How many continents are there on Earth?", {"4", "6", "7", "9"}, 3},
        {"Which is the largest ocean in the world?", {"Indian Ocean", " Pacific Ocean", " Atlantic Ocean", " Arctic Ocean"}, 2},
        {"Which continent is the largest in size?", {"Asia", " Europe", "North America", " Antarctica"}, 1},
        {"Which continent has the largest population?",{"Asia", " Europe", "North America", " Antarctica"}, 1},
        {"How many oceans are there in total?", {"4", "5", "6", "7"}, 3},
        
        {"what is capital city of france?", {"Paris", "Rome", "London", "Berlin"}, 1},
        {"what largest country in the world?", {"Russia", "china", "india", "USA"}, 1},
        {"what is largest population country in the world?", {"Russia", "china", "india", "USA"}, 3},
        {"which country is in asia?", {"france", "germany", "russia", "spain"}, 3},
        {"which continent did Christopher Columbus accidentally found?", {"Asia", "Europe", "america", " Africa"}, 3},
        {"which continent is Thailand locate?", {"Asia", "Europe", "Australia", " Africa"}, 1},
        {"which country has same name as a continent?", {"Asia", "Europe", "Australia", " Africa"}, 3},
        {"which one is the smallest continent?", {"Australia", "North America", "South america", "Asia"}, 1},
        {"which country mount everest located?", {"Nepal", "china", "india", "Sri Lanka"}, 1},
        {"what country have hawaii?", {"england", "China", "russia", "USA"}, 4}
        
    };

    int numQuestions = sizeof(questions) / sizeof(questions[0]);
    int score = 0;
    shuffleQuestions(questions, numQuestions);
    // Iterate through each question
    for (int i = 0; i < 10; ++i) {
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
    displayScore(score, 10);
}

void quiz3l() {
    // Array of questions ภูมิศาสตร์
    Question questions[] = {
        {"How many continents are there on Earth?", {"4", "6", "7", "9"}, 3},
        {"Which is the largest ocean in the world?", {"Indian Ocean", " Pacific Ocean", " Atlantic Ocean", " Arctic Ocean"}, 2},
        {"Which continent is the largest in size?", {"Asia", " Europe", "North America", " Antarctica"}, 1},
        {"Which continent has the largest population?",{"Asia", " Europe", "North America", " Antarctica"}, 1},
        {"How many oceans are there in total?", {"4", "5", "6", "7"}, 3},
        {"what is capital city of france?", {"Paris", "Rome", "London", "Berlin"}, 1},
        {"what largest country in the world?", {"Russia", "china", "india", "USA"}, 1},
        {"what is largest population country in the world?", {"Russia", "china", "india", "USA"}, 3},
        {"which country is in asia?", {"france", "germany", "russia", "spain"}, 3},
        {"which continent did Christopher Columbus accidentally found?", {"Asia", "Europe", "america", " Africa"}, 3},
        {"which continent is Thailand locate?", {"Asia", "Europe", "Australia", " Africa"}, 1},
        {"which country has same name as a continent?", {"Asia", "Europe", "Australia", " Africa"}, 3},
        {"which one is the smallest continent?", {"Australia", "North America", "South america", "Asia"}, 1},
        {"which country mount everest located?", {"Nepal", "china", "india", "Sri Lanka"}, 1},
        {"what country have hawaii?", {"england", "China", "russia", "USA"}, 4},
        
        {"2x + 5 when x = 2", {"4", "6", "7", "9"}, 4},
        {"√625 + 50 - 20", {"65", "75", "55", "85"}, 3},
        {"7 x 7 - 3", {"46", "47", "45", "49"}, 1},
        {"6 + 3 - 4 + 2", {"6", "7", "8", "9"}, 2},
        {"7 + 6 + 4 + 7", {"21", "23", "24", "26"}, 3},
        {"378/0", {"0", "378", "1", "undefined"}, 4},
        {"2x2x2x2/4", {"2", "4", "8", "0"}, 2},
        {"10persent of 139", {"12.5", "13.9", "10", "13.99"}, 2},
        {"What is least common multiple of 3 and 12", {"21", "24", "12", "36"}, 3},
        {"What is greatest common factor of 36 and 4", {"4", "36", "24", "2"}, 1},
        {"1+1+1+1+1+1+1+1+1+1*2", {"11", "20", "5", "12"}, 1},
        {"sin 30° equal", {"1", "2", "0", "0.5"}, 4},
        {"size of rectangle that length=10  width=30 ", {"300", "40", "250", "400"}, 1},
        {"2+2", {"0", "4", "1", "5"}, 2},
        {"321x123", {"39483", "38755", "48653", "32123"}, 1},
        
         {"What did Isaac Newton discover?", {"X-ray", "Law of Gravitation", "Calculator", "Electricity"}, 2},
        {"Which mineral is essential for bones?", {"Carbon", "Chlorine", "Calcium", " Sodium"}, 3},
        {"Where are white blood cells produced?", {"Kidney", " Heart", " Spleen", "Bone marrow"}, 4},
        {"Earth is the ____ planet in the solar system.", {"2", "3", "4", "5"}, 2},
        {"The chemical symbol for the element Phosphorus is:", {"F", "Fe", "P", "K"}, 3},
        {"The chemical symbol for water is:", {"H2O", "CO2", "NO2", "H2O2"}, 1},
        {"How many colors do rainbow have", {"5", "8", "7", "6"}, 3},
        {"how many teeth do adults have?", {"34", "32", "30", "28"}, 2},
        {"Which food group is flour in ?", {"protein", "carbohydrates", "Fat", "vitamin"}, 2},
        {"How long is 1 rotation of the Earth in hours?", {"12", "18", "30", "24"}, 4},
        {"which gas do plants absorb for photosynthesis?", {"argon", "Oxygen", "Nitrogen", "Carbon dioxide"}, 4},
        {"what happen if weight on moon", {"decreases", "increase", "same", "all correct"}, 1},
        {"water turn to ice at what temperature?", {"50 degree Celsius", "100 degree Celsius", "0 degree Celsius", "150 degree Celsius"}, 3},
        {"which planet has the most moons?", {"Saturn", "Neptune", "Mars", "Mercury"}, 1},
        {"which planet closest to the sun?", {"Mars", "jupiter ", "Mercury", "uranus"}, 3},
        
        {"Which animal spends 90persent of its day sleeping?", {"Koala bear", "Panda bear", "Polar bear", "Grizzly bear"}, 1},
        {"Which animal is the fastest land animal?", {"Cheetah", "Leopard", "Tiger", "Ostrich"}, 1},
        {"Which animal has the longest lifespan in the world?", {"Tortoise", "Blue Whale", "Dolphin", "White shark"}, 1},
        {"Which animal species is most at risk of extinction?", {"Owl", "Heron", "Kiwi bird", "Hummingbird"}, 3},
        {"Which animal is highly intelligent with a high IQ?", {"Dog", "Cat", "Dolphin", "Fox"}, 3},
        {"Which animal is not fish?", {"salmon", "shark", "puffer fish", "whale"}, 4},
        {"Which animal dose not have lungs?", {"frogs", "snail", "octopus", "elephant"}, 3},
        {"how many hearts does an octopus have?", {"0", "1", "3", "2"}, 3},
        {"how many legs dose spider have?", {"4", "6", "8", "10"}, 3},
        {"Which animal is reptiles?", {"frogs", "Cat", "Dolphin", "snake"}, 4},
        {"Which animal is Amphibians?", {"salamander", "Cat", "Dolphin", "alligator"}, 1},
        {"Which animal is Mammals?", {"pigeon", "salamander", "Dolphin", "snake"}, 3},
        {"Which animal dose not have spine?", {"turtle", "salamander", "Dolphin", "octopus"}, 4},
        {"Which animal is cold-blooded animals?", {"Dog", "Cat", "Dolphin", "salmon"}, 4},
        {"which animal has the most population?", {"Insects", "Fish", "Birds", "Human"}, 1}
    };
    

    int numQuestions = sizeof(questions) / sizeof(questions[0]);
    int life = 3;
    int cquiz = 0;
    shuffleQuestions(questions, numQuestions);
    // Iterate through each question
    for (int i = 0; i < 60; ++i) {
        cout << "\n************ Question " << i + 1 << " ************" << "       -||" << life << " life remaining||-" << endl;
        if (askQuestion(questions[i])) {
            cout << "Correct!" << endl;
            cquiz++;
        } else {
            cout << "Incorrect!" << endl;
            life--;
        }
        
        if (life == 0) {
    cout << "oooooo   oooo                            oooo                         .  " << endl;
    cout << " `888.   .8'                             `888                       .o8  " << endl;
    cout << "  `888. .8'    .ooooo.  oooo  oooo        888   .ooooo.   .oooo.o .o888oo" << endl;
    cout << "   `888.8'    d88' `88b `888  `888        888  d88' `88b d88(  \"8   888  " << endl;
    cout << "    `888'     888   888  888   888        888  888   888 `" << "Y88b.    888  " << endl;
    cout << "     888      888   888  888   888        888  888   888 o.  )88b   888 . " << endl;
    cout << "    o888o     `Y8bod8P'  `V88V\"V8P'      o888o `Y8bod8P' 8\"\"888P'   \"888\"" << endl;
            break;
        }
    
      if (life >=35) {
    cout << "oooooo   oooo                                              o8o             " << endl;
    cout << " `888.   .8'                                               `\"'             " << endl;
    cout << "  `888. .8'    .ooooo.  oooo  oooo       oooo oooo    ooo oooo  ooo. .oo.  " << endl;
    cout << "   `888.8'    d88' `88b `888  `888        `88. `88.  .8'  `888  `888P\"Y88b " << endl;
    cout << "    `888'     888   888  888   888         `88..]88..8'    888   888   888 " << endl;
    cout << "     888      888   888  888   888          `888'`888'     888   888   888 " << endl;
    cout << "    o888o     `Y8bod8P'  `V88V\"V8P'          `8'  `8'     o888o o888o o888o" << endl;
        }
        // Pause for 2 seconds before displaying the next question
        this_thread::sleep_for(chrono::seconds(2));
    }

    // Display final score
   cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
cout << "  (¯`·.¸¸.·´¯`·.¸¸.·´¯¯`·.¸¸.·´¯`·.¸¸.·´¯¯`·.¸¸.·´¯`·.¸¸.·´¯)" << endl;
cout << "  ( \\                                                       // )" << endl;
cout << " ( \\ )                                                       ( / )" << endl;
cout << "( ) (          You answered " << cquiz << " questions correctly           ) ( )" << endl;
cout << " ( / )                                                         ( \\ )" << endl;
cout << "  ( /                                                         \\ )" << endl;
cout << "   (_.·´¯`·.¸¸.·´¯`·.¸__.·´¯`·.¸¸.·´¯`·.¸_.·´¯`·.¸¸.·´¯`·.¸__)" << endl;


}

// Function to display the main menu
void menu() {
    system("cls");
    system("color 0A");
    cout << "\t\t\t\t  █     █░▓█████  ██▓     ▄████▄   ▒█████   ███▄ ▄███▓▓█████ " << endl;
    cout << "\t\t\t\t ▓█░ █ ░█░▓█   ▀ ▓██▒    ▒██▀ ▀█  ▒██▒  ██▒▓██▒▀█▀ ██▒▓█   ▀ " << endl;
    cout << "\t\t\t\t ▒█░ █ ░█ ▒███   ▒██░    ▒▓█    ▄ ▒██░  ██▒▓██    ▓██░▒███   " << endl;
    cout << "\t\t\t\t ░█░ █ ░█ ▒▓█  ▄ ▒██░    ▒▓▓▄ ▄██▒▒██   ██░▒██    ▒██ ▒▓█  ▄ " << endl;
    cout << "\t\t\t\t ░░██▒██▓ ░▒████▒░██████▒▒ ▓███▀ ░░ ████▓▒░▒██▒   ░██▒░▒████▒" << endl;
    cout << "\t\t\t\t ░ ▓░▒ ▒  ░░ ▒░ ░░ ▒░▓  ░░ ░▒ ▒  ░░ ▒░▒░▒░ ░ ▒░   ░  ░░░ ▒░ ░" << endl;
    cout << "\t\t\t\t   ▒ ░ ░   ░ ░  ░░ ░ ▒  ░  ░  ▒     ░ ▒ ▒░ ░  ░      ░ ░ ░  ░" << endl;
    cout << "\t\t\t\t   ░   ░     ░     ░ ░   ░        ░ ░ ░ ▒  ░      ░      ░   " << endl;
    cout << "\t\t\t\t     ░       ░  ░    ░  ░░ ░          ░ ░         ░      ░  ░" << endl;
    cout << "\t\t\t\t  ░                       ░                                   " << endl;
    cout << endl;
    cout << "\t\t\t\t░\t\tWelcome to the Quiz Game!\t░\t\t\t\t\t\t\t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t\t░ 1. Start Game\t\t\t\t░\t\t\t\t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t░\t  2. How to Play\t\t░\t\t\t\t\t\t\t\t\t\t" << endl;
    cout << "\t\t\t\t\t\t  3. Exit\t\t░\t\t\t\t\t\t\t\t\t\t" << endl;
    cout << "\t\t\t\t░\t░\tEnter your choice: ";
    cin >> choice;
}
// Main function
int main() {
    menu();
  
    switch (choice) {
        case 1:
            start();
            if(topic == "1") {
                quiz();
            } else if(topic == "2") {
                quiz2();
            } else if(topic == "3") {
                quiz3();
            } else if(topic == "4") {
                quiz4();
            } else if(topic == "5") {
                quiz3l();
            }
            break;
        case 2:
            howToPlay();
            main(); // Go back to main menu
            break;
        case 3:
            cout << "Exiting the game..." << endl;
            cout << "\t\t " << endl;
            cout << "\t\tOK your scor here, Goodbye I hop you enjoy this game " << endl;
            std::cout << "    .       .\n"
                 "   |\\_---_/|\n"
                 "  /   o_o   \\\n"
                 " |     U     |\n"
                 " \\   ._I_.  /\n"
                 "   `-_____-'\n";
            return 0;
        default:
            cout << "Invalid choice. Please enter 1, 2, 3 or 4." << endl;
            main(); // Go back to main menu
            break;
    }
    
    // After the quiz is completed, display the final score
    if(topic != "5"){displayScore(score, totalQuestions);}
    
    return 0;
}
