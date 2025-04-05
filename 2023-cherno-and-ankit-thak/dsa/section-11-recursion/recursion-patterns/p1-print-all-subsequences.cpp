/*
Refer the video and article of striver-
https://www.youtube.com/watch?v=AxNNVECce8c&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=6

https://takeuforward.org/data-structure/power-set-print-all-the-possible-subsequences-of-the-string/

Intuition: Since we are generating subsets two cases will be possible, either you can pick the 
character or you cannot pick the character and move to the next character.

Maintain a temp string (say f),which is empty initally.
Now you have two options,either you can pick the character or not pick the character and move 
to the next index.
Firstly we pick the character at ith index and then move to the next index.(f + s[i])
If the base condition is hit,i.e i==s.length() ,then we print the temp string and return.
Now while backtracking we have to pop the last character since now we have to implement 
the non-pick condition and then move to next index.
*/

#include<bits/stdc++.h>
using namespace std;
void solve(int i, string s, string &f) {
	if (i == s.length()) {
		cout << f << " ";
		return;
	}
	//picking 
	f = f + s[i];
	solve(i + 1, s,  f);
	//poping out while backtracking
	f.pop_back();
	solve(i + 1, s,  f);
}
int main() {
	string s = "abc";
	string f = "";
	cout<<"All possible subsequences are: "<<endl;
	solve(0, s, f);
}