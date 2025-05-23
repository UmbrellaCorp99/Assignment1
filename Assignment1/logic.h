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
    string scrambler(string word);
    //Takes in a word and scrambles it
    //Returns a scrambled version of the parameter
    void end();
    //Displays the endgame information
private:
    int numCorrect,             //the number of correct words
        smallWordLength,       //length of word arrays
        mediumWordLength,
        largeWordLength;
    string smallWords[50];   //array of words of length 4-5
    string mediumWords[50];   //array of words of length 6-7
    string largeWords[50];   //array of words of length 8+   
};//end class logic

logic::logic() {

}

void introduction::introduction() {

}

void createLists::createLists() {

}

bool playGame::playGame() {

}

string scrambler::scrambler(string word) {

}

void end::end() {

}