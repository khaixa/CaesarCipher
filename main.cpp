#include <iostream>
#include <string>

std::string decrpytCaesarCipher(const std::string& ciphertext, int shift){
    std::string decrpytedText = "";

    for(char ch : ciphertext){
        if (isalpha(ch)){
            char base = isupper(ch) ? 'A' : 'a';
            decrpytedText += (ch - base - shift + 26) % 26 + base;
        }else{
            decrpytedText += ch;
        }
    }

    return decrpytedText;

}

int main(){
    std::string ciphertext;
    std::cout << "Please enter the ciphertext: ";
    std::getline(std::cin, ciphertext);

    for (int shift =1; shift <= 25; ++shift){
        std::string decryptedText = decrpytCaesarCipher(ciphertext, shift);
        std::cout << "Shift " << shift << ": " << decryptedText << '\n';
    }
    
    return 0;
}