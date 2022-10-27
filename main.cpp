#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
using namespace std;

int main() {
  enum fields {Word, WORD_FIELDS};
  const int numOfWords = 4;
      const string Words[4] = {"programming", "computer", "software", "hardware"};
  const string Hints[4] = {"This is what sofware engineers do",
                         "This is made of a bunch of components in a case",
                         "This is a technical term for a program.",
                         "These are the components that make up your computer"};
  
  srand(static_cast<unsigned int>(time(0))); //seeding random number
  
  int choice = (rand() % numOfWords); // creating random number
  string theWord = Words[choice]; // words to guess
  string theHint = Hints[choice]; // hint for the word

  string jumble = theWord; // jumbled version of the word

  int length = jumble.size(); // getting the length of the string
  for (int i = 0; i < length; i++){ // creating for loop to iterate through theWord. 
    int index1 = (rand() % length); // creating random number for our index
    int index2 = (rand() % length);
    char temp = jumble[index1];
    jumble[index1] = jumble[index2];
    jumble[index2] = temp;
  }

  cout << "\t\t\tWelcome to Word Jumble!\n\n";
  cout <<"Unscramble the letters to solve the mystery word.\n\n";
  cout <<"Enter 'hint' for a hint\n\n";
  cout <<"Enter 'quit' to quit the game\n\n";
  cout <<"\nHere is your scrambled word. Good Luck!\n\n " << jumble;
  string guess;
  cout << "\n\nguess: ";
  cin >> guess;

  while((guess != theWord) && (guess != "quit")){
    if (guess == "hint"){
      cout << "\n" << theHint;
       
    }
    else{

      cout <<"... here's another try";
    }

    cout <<"\n\nYour guess: ";
    cin >> guess;


    }

  if (guess == theWord){
    cout << "\nYou have guessed correctly!";
    //score += 1;
  }
  cout << "...Thank you for playing." << endl;
  return 0;
  



  }