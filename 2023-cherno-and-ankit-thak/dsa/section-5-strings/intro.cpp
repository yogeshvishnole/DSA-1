/*
String class/datatype and its utility methods and functions + array of strings using vector
 */

#include <iostream>
using namespace std;

int main()
{
    /*  string s = "abc";
     cout << s << endl;
     // string data type is same as character arrays with additional powers like you do niot have to deal
     // with \0 character for terminations and also it provides a lot of utility methods, string type is internally
     // implemented using character arrays only */

    /*  string s2;
     s2 = "def";
     cout << s2 << endl; */

    /*  // Dynamically creating  a string (lets create a string in heap memory)
     string *sp = new string;
     *sp = "hello";
     cout << *sp << endl; */

    /*    //  Array of strings using vector
       vector<string> v;
       v.push_back(s);
       v.push_back("hello");

       for (int i = 0; i < v.size(); i++)
       {

           cout << v[i] << endl;
           // Lets sort the strings
           sort(v[i].begin(), v[i].end()); // sort function sorts the strings in lexical order

           cout << v[i] << endl;
       } */

    /*     // taking strings as input from user
        string sinput;
        // cin>>sinput; - not prefereable because space is delimiter
        // cin.getline(string,length,delimiter) -  cannot used because string type does not require length
        getline(cin, sinput); // special function for string inputs */
    /*
        // strings as arrays
        // we can treat strings as arrays
        string sarr = "abc";
        sarr[0] = 'd';
        cout << sarr << endl; */

    /*     // strings with + operator (string concatentaion)
        // + operators concatenates the two or more string
        string s = "abc";
        string s4 = "";
        s4 += "hello" + s;
        cout << s4 << endl;

        // length and size of string
        cout << s4.length() << endl;
        cout << s4.size() << endl;
        // above two functions has the same functionality */

    /*    // substr function - returns a new sub string

       // in first way - with single arg
       string s = "abcde";
       cout << s.substr(3) << endl; // will return a new sub  string starting from 3 index of s to the last index

       // in second way
       string s2 = "abcdefgh";
       cout << s.substr(3, 2) << endl; // will return a new sub string starting from 3 index till next 2 index say 4 (3 and 4) */

    /*     // find function
        string s = "abcabc";
        cout << s.find("bc") << endl; // will return the index of first occurence of "bc" in s that is 1 */

    /*  // to_string function
     // converts a number to string
     int x = 10;
     string s = to_string(x);
     s[1] = '5';
     cout << s << endl; */

    /*  // push_back function
     // adds a character to the end of the string
     string s = "abc";
     s.push_back('d');
     cout << s << endl; */

    // stoi function
    // converts a string to integer
    string s = "123";
    int x = stoi(s);
    cout << x << endl;
}