#include<iostream>
using namespace std;

void convert(int decimal, int base)
{
    if (decimal == 0)
        return;
     
    int x = decimal % base;
    decimal /= base;
    
    if (x < 0)
        decimal += 1;
    
    convert(decimal, base);
    
    int number = ((x < 0) ? (x + (base * -1)) : x);
    cout << number;
    
    return;
}

int main()
{
    int data[10], input[10], decValue = 0;
    int c, c1, c2, c3, i, decimal, base;
    
    cout << "Enter a decimal: ";
    cin >> decimal;
    cout << "Enter a base to convert to: ";
    cin >> base;
    
    if (decimal != 0)
    {
        cout << endl << decimal << " in base 10 is ";
        convert(decimal, base);
        cout << " in base " << base << endl << endl;
    }
    else
    {
        cout << "0" << endl;
    }
 
    cout << "Enter binary message bits one by one: ";
    cin >> data[0];
    cin >> data[1];
    cin >> data[2];
    cin >> data[4];
 
    data[6] = data[0] ^ data[2] ^ data[4];
    data[5] = data[0] ^ data[1] ^ data[4];
    data[3] = data[0] ^ data[1] ^ data[2];
 
    cout << "\nEncoded data is\n";
    for(int i = 0; i < 7; i++)
    {
        cout << data[i];
    }
    
    cout << "\n\nEnter received message bits one by one\n";
    for(int i = 0; i < 7; i++)
    {
        cin >> input[i];
    }

    c1 = input[6] ^ input[4] ^ input[2] ^ input[0];
    c2 = input[5] ^ input[4] ^ input[1] ^ input[0];
    c3 = input[3] ^ input[2] ^ input[1] ^ input[0];
    c = c3 * 4 + c2 * 2 + c1;
 
    if(c == 0)
    {
        cout << "\nThere is no error.\n";
    }
    else
    {
        cout << "\nError on position " << 7 - c + 1 << endl;
        cout << "\nData sent: ";
 
        for(i = 0; i < 7; i++)
        {
            cout << data[i];
        }
        
        cout << "\nData received: ";
        for(i = 0; i < 7; i++)
        {
            cout << input[i];
        }
        
        cout << "\n\nCorrect message is ";
        if(input[7 - c] == 0)
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
        
        cout << endl;
    }
    return 0;
}
