/*
This problem is interesting and its solution as well, you can look out the video in
 future if you dont get the soln by looking at it.

 Given input char array or string "abc"
 Out put print all of its ssubsequences
 subsequences of "abc" are - "","a","ab","abc","b","bc","c","ac"
 so number of subsequences = 2 raise to the power number of characters
 because there are two possibilities for every character either we need to include it
 or exclude it.
 so for "abc" = 2*2*2 = 8 subsequences
 */

#include <iostream>
#include <vector>
using namespace std;

// To understand the below function draw the recursion treee and see that all subsequences
// are present at the root of the tree when string length is 0 thats why we are printing in the
// base case only, changing the nodes of the tree (means order of include and exclude) will
// reverse the order of printing
void printSubsequences(string str, string output)
{

    // Base case
    if (str.length() == 0)
    {
        cout << '"' << output << '"' << endl;
        return;
    }

    // If I swap the below two func calls order of printing will be different

    // Exclude the character from the output
    printSubsequences(str.substr(1), output);
    // Include the character in the inpiut
    printSubsequences(str.substr(1), output + str[0]);
}

// Same function using the character array
void printSubsequences2(char arr[], char output[], int i)
{
    if (arr[0] == '\0')
    {
        output[i] = '\0';
        cout << '"' << output << '"' << endl;
        return;
    }

    // Exclude the character from output
    printSubsequences2(arr + 1, output, i);
    // include the character in output
    output[i] = arr[0];
    printSubsequences2(arr + 1, output, i + 1);
}

void storeAllSubsequences(string str, string output, vector<string> &v)
{
    if (str.length() == 0)
    {
        v.push_back(output);
        return;
    }

    // Exclude the character from the output
    storeAllSubsequences(str.substr(1), output, v);
    // Include the character in the output
    storeAllSubsequences(str.substr(1), output + str[0], v);
}

int main()
{
    string str = "abc";
    string output = "";
    printSubsequences(str, output);

    char arr[] = "abc";
    char output2[100] = "";
    printSubsequences2(arr, output2, 0);

    string str2 = "abc";
    string output3 = "";
    vector<string> v;

    storeAllSubsequences(str2, output3, v);

    for (auto el : v)
    {
        cout << '"' << el << '"' << endl;
    }
}