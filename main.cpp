#include <iostream>
#include <string>

char alpha[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
std::string Input;

void displayMenu()
{
    std::cout << "Ceaser Cypher Decoder/Encoder" << std::endl
    <<  "1. Encode a Message " << '\n' << "2. Decode a Message" << '\n'
    << "3. End" << '\n' << "Choose: " << std::endl;
}
void encode()
{
    std::cout << "Enter your Value to encode: ";
    std::cin >> Input;
}
void decode()
{

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
            default:
                std::cout << "Enter a Valid Choice!";
                continue;
        }
    }
    return 0;
}
