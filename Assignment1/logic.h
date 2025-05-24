#include <string>
#include <fstream>

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
                        break;
                    }
                }
            }
            else if ((word.length() == 6 || word.length() == 7)) {
                for (int i = 0; i < mediumWords->length() - 1; i++) {
                    if (mediumWords[i].empty()) {
                        mediumWords[i] = word;
                        break;
                    }
                }
            }
            else if (word.length() >= 8) {
                for (int i = 0; largeWords->length() - 1; i++) {
                    if (largeWords[1].empty()) {
                        largeWords[i] = word;
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
    }
    return value;
}

bool logic::playGame() {
    bool value = true;
    return value;
}

std::string logic::scrambler(std::string word) {
    std::string value = "";
    return value;
}

void logic::end() {

}