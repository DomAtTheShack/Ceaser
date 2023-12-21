#include <iostream>
#include <string>
#include <limits>

char alpha[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
std::string Input;
int Key;

void checkBounds();

int find(const char arr[], char seek)
{
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] == (char)tolower(seek))
            return i;
    }
    return -1;
}

int checkBounds(int cPos, bool decode)
{
    if (decode)
    {
        if (find(alpha, Input[cPos]) + (Key) > 25)
        {
            return (find(alpha, Input[cPos]) + Key) - 26;
        }
        else
        {
            return find(alpha, Input[cPos] + Key);
        }
    }
    else
    {
        if (find(alpha, Input[cPos]) + (Key * -1) < 0)
        {
            return (find(alpha, Input[cPos]) + (Key * -1)) + 26;
        }
        else
        {
            return find(alpha, Input[cPos]) + (Key * -1);
        }
    }
}

std::string change(bool decode)
{
    char message[Input.length()];
    for (int i = 0; i < Input.length(); i++)
    {
        int specialKey = checkBounds(i, decode);
        if (Input[i] == ' ')
        {
            message[i] = ' ';
            continue;
        }
        message[i] = alpha[specialKey];
    }
    return message;
}

void displayMenu()
{
    std::cout << std::endl
              << "Ceaser Cypher Decoder/Encoder" << std::endl
              << "1. Encode a Message " << '\n'
              << "2. Decode a Message" << '\n'
              << "3. End" << '\n'
              << "Choose: " << std::endl;
}

void encode()
{
    std::cout << "Enter your Message to encode: ";
    std::cin.ignore(); // Ignore the newline character from previous input
    std::getline(std::cin, Input);

    std::cout << "What is your Caesar key (-25 to 25): ";
    std::cin >> Key;

    std::string Str = change(false).substr(0, Input.length());

    std::cout << "Message-> " << Str
              << " : Key-> " << Key << '\n';
}

void decode()
{
    std::cout << "Enter your Message to decode: ";
    std::cin.ignore(); // Ignore the newline character from previous input
    std::getline(std::cin, Input);

    std::cout << std::endl
              << "What is your Caesar key (-25 to 25): ";
    std::cin >> Key;
    std::cout << std::endl;

    std::string Str = change(true).substr(0, Input.length());

    std::cout << "Message-> " << Str
              << " : Key-> " << Key << '\n';
}

int main()
{
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
