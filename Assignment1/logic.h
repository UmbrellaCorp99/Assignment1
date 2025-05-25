#include <string>
#include <fstream>
#include <algorithm>
#include <time.h>

class logic {
public:
    logic();
    //constructor
    void introduction();
    //Provides a basic introduction to the user
    bool createLists();
    //Opens a file and reads in the list of words that can be scrambled
    //Returns: true if words inserted and false if not
    bool playGame();
    //Carries out the actual word scrambling
    //Returns: true if user wins and false if not
    std::string scrambler(std::string word);
    //Takes in a word and scrambles it
    //Returns a scrambled version of the parameter
    void end();
    //Displays the endgame information
private:
    int numCorrect,             //the number of correct words
        smallWordLength,       //length of word arrays
        mediumWordLength,
        largeWordLength;
    std::string smallWords[50];   //array of words of length 4-5
    std::string mediumWords[50];   //array of words of length 6-7
    std::string largeWords[50];   //array of words of length 8+   
};//end class logic

logic::logic() {

}

void logic::introduction() {
    std::cout << "Welcome to the unscramble game! \nIn this game, you will have to guess 5 scrambled words \nincreasing in difficulty before the 60 second timer runs out. \nLet's begin!\n" << std::endl;
}

bool logic::createLists() {
    bool value = false;
    std::ifstream inputfile;
    inputfile.open("dictionary.txt");
    if (inputfile.is_open()) {
        std::string word;
        while (std::getline(inputfile, word)) {
            if (word.length() == 4 || word.length() == 5) {
                for (int i = 0; i < smallWords->length() - 1; i++) {
                    if (smallWords[i].empty()) {
                        smallWords[i] = word;
                        smallWordLength++;
                        break;
                    }
                }
            }
            else if ((word.length() == 6 || word.length() == 7)) {
                for (int i = 0; i < mediumWords->length() - 1; i++) {
                    if (mediumWords[i].empty()) {
                        mediumWords[i] = word;
                        mediumWordLength++;
                        break;
                    }
                }
            }
            else if (word.length() >= 8) {
                for (int i = 0; largeWords->length() - 1; i++) {
                    if (largeWords[1].empty()) {
                        largeWords[i] = word;
                        largeWordLength++;
                        break;
                    }
                }
            }
        }
        value = true;
        inputfile.close();
    }
    else {
        std::cout << "File could not be found" << std::endl;
        exit(0);
    }
    return value;
}

bool logic::playGame() {
    bool result = false;
    std::string guess = "";
    std::string words[50];
    while (guess != smallWords[0]) {
        std::cout << "1) " + scrambler(smallWords[0]) << std::endl;
        std::cin >> guess;
        if (guess == smallWords[0]) {
            numCorrect++;
            continue;
        }
        else {
            std::cout << "Incorrect. Try again." << std::endl;
        }
        guess = "";
    }
    while (guess != smallWords[1]) {
        std::cout << "2) " + scrambler(smallWords[1]) << std::endl;
        std::cin >> guess;
        if (guess == smallWords[1]) {
            numCorrect++;
            continue;
        }
        else {
            std::cout << "Incorrect. Try again." << std::endl;
        }
        guess = "";
    }
    while (guess != mediumWords[0]) {
        std::cout << "3) " + scrambler(mediumWords[0]) << std::endl;
        std::cin >> guess;
        if (guess == mediumWords[0]) {
            numCorrect++;
            continue;
        }
        else {
            std::cout << "Incorrect. Try again." << std::endl;
        }
        guess = "";
    }
    while (guess != mediumWords[1]) {
        std::cout << "4) " + scrambler(mediumWords[1]) << std::endl;
        std::cin >> guess;
        if (guess == mediumWords[1]) {
            numCorrect++;
            continue;
        }
        else {
            std::cout << "Incorrect. Try again." << std::endl;
        }
        guess = "";
    }
    while (guess != largeWords[0]) {
        std::cout << "5) " + scrambler(largeWords[0]) << std::endl;
        std::cin >> guess;
        if (guess == largeWords[0]) {
            numCorrect++;
            continue;
        }
        else {
            std::cout << "Incorrect. Try again." << std::endl;
        }
        guess = "";
    }
    std::cout << "All good so far!" << std::endl;
    if (numCorrect == 5) {
        result = true;
    }
    return result;
}

std::string logic::scrambler(std::string word) {
    random_shuffle(word.begin(), word.end());
    return word;
}

void logic::end() {
    printf("\nScore: %i", numCorrect);
    if (numCorrect == 0) {
        std::cout << "\nMaybe just stick to scrambling eggs, yeah?" << std::endl;
    }
    else if (numCorrect == 1) {
        std::cout << "\nHey, one point is better than nothing!" << std::endl;
    }
    else if (numCorrect == 2) {
        std::cout << "\nYou got the same score as my cat!" << std::endl;
    }
    else if (numCorrect == 3) {
        std::cout << "\nNot too shabby!" << std::endl;
    }
    else if (numCorrect == 4) {
        std::cout << "\nLook at the big brain on Brad!" << std::endl;
    }
    else if (numCorrect == 5) {
        std::cout << "\nHoly smokes, a perfect score. You sure you're not cheating?" << std::endl;
    }
    std::cout << "\nThanks for playing!" << std::endl;
}