#include "definitions.hpp"
#include <cctype>
#include <ctime>

int main() {
  std::cout << "****************** HANGMAN ******************\n";
  // startup_animation();
  print_state(lives);
  srand(time(0));
  std::string used_letters = "";

  std::string computer_choice = wordlist[rand() % wordlist.size()];
  while (!isValid(computer_choice)) {
    computer_choice = wordlist[rand() % wordlist.size()];
  }

  std::string display_string(computer_choice.size(), '_');

  for (int i = 0; i < computer_choice.size(); ++i) {
    if (rand() % 2 == 1) {
      if (rand() % 3 == 0 ||
          rand() % 3 == 1) { // 66% chance a word is revealed :)
        display_string[i] = computer_choice[i];
      }
    } else {
      if (rand() % 3 == 0) { // 33% chance a word is revealed
        display_string[i] = computer_choice[i];
      }
    }
  }
  while (display_string != computer_choice) {
    std::cout << "\nGuess the word: " << display_string << " ("
              << computer_choice.size() << " characters)\n";
    if (used_letters.size() <= 2) {
      std::cout << "Used letter: " << used_letters << "\nEnter your guess: ";
    } else {
      std::cout << "Used letters: " << used_letters << "\nEnter your guess: ";
    }
    char guess, display_guess;
    std::cin >> guess;
    if (isalpha(guess)) {
      guess = tolower(guess);
      display_guess = toupper(guess);
      used_letters += display_guess;
      used_letters += " ";
      // sort(used_letters.begin(), used_letters.end()); //for the time being i
      // won't sort these neither will i do union(); to remove the repetitions
    } else {
      std::cout << "--> Enter letters only <--";
    }
    bool found = false;
    for (int i = 0; i < computer_choice.size(); ++i) {
      if (computer_choice[i] == guess) {
        display_string[i] = guess;
        found = true;
      }
    }

    if (!found) {
      if (lives > 2) {
        std::cout << "\nIncorrect guess. " << lives - 1
                  << " lives remaining.\n";
      } else if (lives == 2) {
        std::cout << "\nIncorrect guess. " << "1 life remaining.\n";
      }
      lives--;
      print_state(lives);
    }
    if (lives == 0) {
      break;
    }
  }

  if (lives == 0) {
    std::cout << "\nYou lost!\nCorrect answer was '" << computer_choice
              << "'\n";
  } else {
    std::cout << "\nCongratulations! You guessed the word: '" << computer_choice
              << "'\n";
  }
  return 0;
} // by the genius HassanIQ777