/*
Write the followind classes in C++:
- An abstract class Hash that has a method that calculates a hash from a string and returns the appropriate number type;
- Derive from this class several classes that can calculate a hash from:
  - counting the number of vowels in the string;
  - counting the number of consonants in the string;
  - adding the ascii codes of each character;
  - add together the chars as: each vowel will be mutiplied by 10, each consonant will be mutiplied by 11, each other
char will be mutiplied by 12;
- A class HashManager that keeps a list of hashes with names:
  - has the appropriate operators implemented;
  - has a function print_hashes that prints the name of the hash and the hash for each hash;
- Organize the code in the following way:
  - a .h and a .cpp (where is needed) for each class;
  - a main.cpp for the main function;
*/

#include "Headers/HashManager.h"
#include "Headers/VowelsHash.h"
//#include "Headers/ConsonantsHash.h"
//#include "Headers/AsciiHash.h"
//#include "Headers/EasyHash.h"

int main() {
    HashManager hashes;
    hashes["count_vowels"]    = new CountVowelsHash();
//    hashes["count_consonant"] = new CountConsonantHash();
//    hashes["count_ascii"]     = new CountAsciiHash();
//    hashes["easy_ascii"]      = new EasyHash();

    hashes.print_hashes("Did you ever hear the tragedy of Darth Plagueis the Wise?");
}

/*
How are points divided:
- Define abstract class 1p
    - corectly defined class + function (no implementation) 0.3p
    - fully implemented corectly 1p
- Define derived classes 1.25p for each, in total 5p
    - for each derived class 1p:
        - 0.1p only for definition
        - 0.4p definition + inheritance
        - 0.8p defining required methods / members (no implementation)
        - 1.25 p fully implemented ( + correct access modifier)
- Define the class HashManager 2p
    - 0.7 storing the hashes
        - 0.3 for only the definition
        - 0.7 full correct implementation
    - 0.65 for implementing operator
        - 0.25 for only the definition
        - 0.65 full correct implementation
    - 0.65 for print_hashes
        - 0.25 for only the definition
        - 0.65 full correct implementation
- 1p for using .cpp and .h files
- 1p compiling and running correctly (with all the required code)
*/