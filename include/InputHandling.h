/**
* @author Hatash
* @date 2021-4
*/

#ifndef INPUTHANDLING_H_INCLUDED
#define INPUTHANDLING_H_INCLUDED

#include <iostream>
#include <cctype>
#include <string>

/**
* Implementation of InputHandling
*/
class InputHandling {
 public:
   /**
   * Default constructor
   */
  InputHandling() {}

  /**
  * Destructor
  */
  ~InputHandling() {}

  /**
  * checks if the user input is valid.
  * @param temp the string the user entered as response.
  * @return true if the response is valid, false otherwise
  */
  bool isLegalInt(const std::string temp) {
    bool valid = true;
    for (int i = 0; i < temp.size(); i++) {
      if (!std::isdigit(temp[i])) {
        valid = false;
        break;
      }
    }
    return valid;
  }

  /**
  * Clears the buffer stream.
  * @param userinput an istream used to read in user response.
  */
  void clearStream(std::istream& userInput) {
    while (userInput.peek() != '\n') {
      userInput.ignore();
    }
    userInput.ignore();
  }
};

#endif
