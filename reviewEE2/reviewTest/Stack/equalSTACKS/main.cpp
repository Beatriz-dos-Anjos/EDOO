#include <iostream>
#include <string>
#include <stack>
using namespace std;

string Palindromes(string s)
{
    int i = 0;
    stack<char> PalStack;
    for (i = 0; i < s.size(); i++)
    {
        PalStack.push(s[i]);
    }
    string invert;
    while (PalStack.size())
    {
        invert += PalStack.top(); // pega o topo
        PalStack.pop();           // depois remove
    }
    if (s == invert)
    {
        return "Yes";
    }
    else
    {
        return "No";
    }
}
