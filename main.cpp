#include <iostream>
#include <string>

char alpha[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
std::string Input;
int Key;

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
    // Calculate the new position.
    int newPos;
    if (decode)
    {
        newPos = find(alpha, Input[cPos]) - Key;
    }
    else
    {
        newPos = find(alpha, Input[cPos]) + Key;
    }

    // Use modulus operation to keep the newPos within bounds.
    if (newPos < 0)
    {
        newPos += 26;
    }
    else
    {
        newPos %= 26;
    }

    return newPos;
}

std::string change(bool decode)
{
    std::string message;
    for (int i = 0; i < Input.length(); i++)
    {
        if (Input[i] == ' ')
        {
            message += ' ';
            continue;
        }

        int specialKey = checkBounds(i, decode);
        message += islower(Input[i]) ? alpha[specialKey] : tolower(alpha[specialKey]);
    }
    return message;
}



void bruteForce()
{
    for (int i = -25; i <= 25; i++)
    {
        Key = i;
        std::string Str = change(true).substr(0, Input.length());
        std::cout << "Message-> " << Str
                  << " : Key-> " << Key << '\n';
    }
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

void checkKey()
{
    while(Key == 0 || Key > 25 || Key < -25)
    {
        std::cout << "Invalid Key!" << '\n';
        std::cin.clear();
        std::cout << "Enter new key: ";
        std::cin >> Key;
        std::cout << '\n';
    }
}

void encode()
{
    std::cout << "Enter your Message to encode: ";
    std::getline(std::cin >> std::ws, Input);

    std::cout << "What is your Caesar key (-25 to 25): ";
    std::cin >> Key;

    checkKey();

    std::string Str = change(false);

    std::cout << "Message-> " << Str << " : Key-> " << Key << '\n';
}

void decode()
{
    std::cout << "Enter your Message to decode: ";
    std::getline(std::cin >> std::ws, Input);

    std::cout << "What is your Caesar key (-25 to 25) Key 0 to brute force: ";
    std::cin >> Key;

    if(Key == 0)
    {
        bruteForce();
        return;
    }

    checkKey();

    std::string Str = change(true);

    std::cout << "Message-> " << Str << " : Key-> " << Key << '\n';
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
