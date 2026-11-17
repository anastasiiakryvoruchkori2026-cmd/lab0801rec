#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

//рекурсивний метод

// // Дано літерний рядок, який містить послідовність символів s[0], ..., s[n], ...

// 1. Вияснити, чи є в цій послідовності такі елементи s[i–1] , s[i+1]
// що s[i–1] – це літера ('n'), а s[i+1] – буква ('o'),

// 2. Замінити кожну трійку символів s[i–1] , s[i] , s[i+1] – таких, що s[i–1] –
// це літера ('n'), а s[i+1] –  буква ('o') парою зірочок "**".


using namespace std;

bool includeNO(char* s, int i)
{
	if (strlen(s) < 3)
		return false;

	if (s[i + 1] != '\0')
	{
		if (s[i - 1] == 'n' && s[i + 1] == 'o')
			return true;
		else
			return includeNO(s, i + 1);
	}
	else
		return false;
}

char* change(char* dest, const char* s, char* t, int i)
{
    if (s[i] != '\0' && s[i + 1] != '\0' && s[i + 2] != '\0')
    {
        if (s[i] == 'n' && s[i + 2] == 'o')
        {
            strcat(t, "**");
            return change(dest, s, t + 2, i + 3);
        }
        else
        {
            *t++ = s[i++];
            *t = '\0';
            return change(dest, s, t, i);
        }
    }
    else
    {
        strcpy(t, s + i);
        return dest;
    }
}

int main()
{
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    if (includeNO(str, 1))
        cout << "The string has a group of 'n  o'" << endl;
    else
        cout << "The string doesn't have a group of 'n  o'" << endl;

    char* dest1 = new char[strlen(str) + 1];
    dest1[0] = '\0';

    char* dest2 = change(dest1, str, dest1, 0);

    cout << "Original string (str)   : " << str << endl;
    cout << "Modified string (result): " << dest2 << endl;

    return 0;
}