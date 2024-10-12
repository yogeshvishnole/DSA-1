#include <iostream>
#include <cstring>
using namespace std;

// TODO Execise - implement all below 5 functions by yourself

int main()
{

    // Inbuilt functions

    // 1. strlen - to find the length of the string
    // 2. strcmp - to compare two strings
    // 3. strcpy - to copy one string into another
    // 4. strncpy - tocopy first n characters of one string into the another string
    // 5. strcat -  to concatenate two strings

    // All above functions are defined in the cstring header file

    /*     // strlen Example

        char str[100];

        cout << "Enter the string: ";
        cin >> str;
        cout << "Length of string is: " << strlen(str) << endl; */

    /*   // strcmp example

      // Working - It compares two string if they are same or equal it returns 0 otherwise it returns non zero value,
      //  which is equal to the difference of first non matching characters

      char str[100], str2[100];
      cout << "Enter str1 : ";
      cin >> str;
      cout << "Enter str2 : ";
      cin >> str2;
      if (!strcmp(str, str2))
      {

          cout << "Equal";
      }
      else
      {

          cout << "Not Equal";
      } */

    /*    // strcpy example
       // working and signature strcpy(dest_str,source_str) contents of source_str are copied to dest_str with \0 character

       char str[100], str2[100];
       cout << "Enter str1 : ";
       cin >> str;
       cout << "Enter str2 : ";
       cin >> str2;
       strcpy(str, str2);
       cout << "Str1 after copy : " << str << endl;
       cout << "Str2 after copy : " << str2 << endl; */

    /*     // strncpy example
        // working and signature strncpy(dest_str,source_str,n) contents of source_str are copied to dest_str till n characters only
        // and \0 character will not copied if it is not in n characters, if n is greater than soure string character till \0 characters
        // will get copied

        char str[100], str2[100];
        cout << "Enter str1 : ";
        cin >> str;
        cout << "Enter str2 : ";
        cin >> str2;
        strncpy(str, str2, 3);
        cout << "Str1 after n characters copied from str2 : " << str << endl;
        cout << "Str2 after copy : " << str2 << endl; */

    /*  // strcat example
     // working and signature strcat(dest_str,source_str) contents of source_str are concatenated into dest_str t

     char str[100], str2[100];
     cout << "Enter str1 : ";
     cin >> str;
     cout << "Enter str2 : ";
     cin >> str2;
     strcat(str, str2);
     cout << "Str1 after concatenation of str2 : " << str << endl;
     cout << "Str2  : " << str2 << endl; */
}