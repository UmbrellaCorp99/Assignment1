#include <string>

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
    bool value = true;
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