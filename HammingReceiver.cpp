#include<iostream>
using namespace std;

int main()
{
    int input[7], c1, c2, c3, c, actual[4], decValue =  0, base = 1;

    cout << "Enter received message bits one by one: ";

    for (int i = 0; i < 7; i++)
    {
        cin >> input[i];
    }

    c1 = input[6] ^ input[4] ^ input[2] ^ input[0];
    c2 = input[5] ^ input[4] ^ input[1] ^ input[0];
    c3 = input[3] ^ input[2] ^ input[1] ^ input[0];
    c = c3 * 4 + c2 * 2 + c1 ;

    if (c == 0)
        cout << "\nThere is no error.";
    else
    {
        cout << "\nLocation of the Error: " << 7 - c + 1;
        cout << "\nCorrect message is: ";
        
            if (input[7 - c] == 0)
            {
                input[7 - c] = 1;
            }
            else
            {
                input[7 - c] = 0;
            }
        
        for (int i = 0; i < 7; i++)
        {
            cout << input[i];
        }
    }

    actual[0] = input[6];
    actual[1] = input[5];
    actual[2] = input[4];
    actual[3] = input[2];

    for (int i = 0; i < 4; i++)
    {
        decValue += actual[i] * base;
        base = base * 2;
    }

    cout << "\nDecimal value of original message: " << decValue << endl << endl;

    return 0;

}
