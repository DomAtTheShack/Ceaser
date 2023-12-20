#include <iostream>
#include <string>

char alpha[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
std::string Input;
int Key;


int find(const char arr[], char seek)
{
    for (int i = 0; i < 26; ++i)
    {
        if (arr[i] == (char)tolower(seek)) return i;
    }
    return -1;
}
std::string change(const std::string& str, int key, bool decode)
{

    char message[str.length() + 1];
    for(int i = 0; i < str.length(); i ++)
    {
        if(decode)
            message[i] = alpha[find(alpha,str[i]) + key];
        else
            message[i] = alpha[find(alpha,str[i]) + (key*-1)];
    }
    return message;
}
void displayMenu()
{
    std::cout << "Ceaser Cypher Decoder/Encoder" << std::endl
    <<  "1. Encode a Message " << '\n' << "2. Decode a Message" << '\n'
    << "3. End" << '\n' << "Choose: " << std::endl;
}
void encode()
{
    std::cout << "Enter your Message to encode: ";
    std::cin >> Input;
    std::cout << std::endl << "What is your Ceaser key(-25-25): ";
    std::cin >> Key;
    std::cout << std::endl;
    std::cout << "Message-> " << change(Input, Key, false)
    << " : Key-> " << Key << '\n';
}
void decode()
{
    std::cout << "Enter your Message to decode: ";
    std::cin >> Input;
    std::cout << std::endl << "What is your Ceaser key(-25-25): ";
    std::cin >> Key;
    std::cout << std::endl;
    std::cout << "Message-> " << change(Input, Key, true)
    << " : Key-> " << Key << '\n';
}


int main() {

    int choice = 0;
    while (choice != 3)
    {
        displayMenu();
        std::cin >> choice;
        std::cout << std::endl;
        switch (choice)
        {
            case 1:
                encode();
                break;
            case 2:
                decode();
                break;
            case 3:
                continue;
            default:
                std::cout << "Enter a Valid Choice!";
                continue;
        }
    }
    return 0;
}
