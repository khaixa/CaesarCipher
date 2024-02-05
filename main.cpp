#include <iostream>
#include <string>

std::string decrpytCaesarCipher(const std::string& ciphertext, int shift){
    std::string decrpytedText = "";

    for(char ch : ciphertext){
        // Check if its alphabet
        if (isalpha(ch)){
            // Determining base character
            char base = isupper(ch) ? 'A' : 'a';
            // Decryption using caesar cipher algo
            decrpytedText += (ch - base - shift + 26) % 26 + base;
        } else{
            decrpytedText += ch;
        }
    }

    return decrpytedText;
}

int main(){
    //Asking for amount of input
    int numMessages;

    do{
        std::cout << "Please enter the number of messages (1 to 4, or X to exit): ";
        std::string input;
        std::getline(std::cin, input);

        if (input == "X" || input == "x"){
            std::cout << "Exiting program. \n";
            return 0;
        } else{
            try{
                numMessages = std::stoi(input);
                    if(numMessages < 1 || numMessages > 4){
                        std::cout << "Invalid input. Please try again.\n";
                    }
            } catch (std::invalid_argument&){
                std::cout << "Invalid input. Please try again.\n";
            }
        }
    } while (numMessages < 1 || numMessages > 4);

    for(int i = 0; i < numMessages; ++i){
        std::string ciphertext;
        // User prompt for the ciphertext
        std::cout << "Please enter the ciphertext" << (i + 1) << ": ";
        std::getline(std::cin, ciphertext);
        // Brute-force attack
        for (int shift =1; shift <= 25; ++shift){
            std::string decryptedText = decrpytCaesarCipher(ciphertext, shift);
            std::cout << "Shift " << shift << ": " << decryptedText << '\n';
        }
        
    }

    return 0;
}