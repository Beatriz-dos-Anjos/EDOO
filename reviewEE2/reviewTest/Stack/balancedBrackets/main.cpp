#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;
string balanced(string s)
{
    stack<char> Brackets;
    int i = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            Brackets.push(s[i]);
        }
        if (s[i] == '}' || s[i] == ']' || s[i] == ')')
        {
            // lógica da pilha correta
            char topo = Brackets.top();
            if ((s[i] == ')' && topo == '(') ||
                (s[i] == ']' && topo == '[') ||
                (s[i] == '}' && topo == '{'))
            {
                Brackets.pop();
            }
            else
            {
                return "No";
            }
        }
    }
    if (Brackets.empty())
    {
        return "Valid";
    }
}

int evaluateRPN(vector<string> tokens)
{
    stack<int> Operands;

    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
        {
            Operands.push(stoi(tokens[i]));
        }
        else
        {
            int b = Operands.top();
            Operands.pop();
            int a = Operands.top();
            Operands.pop();
            int result;

            if (tokens[i] == "+")
                result = a + b;
            else if (tokens[i] == "-")
                result = a - b;
            else if (tokens[i] == "*")
                result = a * b;
            else if (tokens[i] == "/")
                result = a / b;

            Operands.push(result);
        }
    }

    return Operands.top();
}

string simulateBrowser(vector<string> commands)
{
    stack<string> BackSites;
    stack<string> NextSites;
    string current = "Home"; // Página inicial

    for (int i = 0; i < commands.size(); i++)
    {
        if (commands[i].substr(0, 6) == "visit")
        {
            // Extrai a URL após "visit "
            string url = commands[i].substr(6);
            BackSites.push(current);   // Salva a página atual
            current = url;             // Vai para a nova página
            while (!NextSites.empty()) // Limpa o histórico de "avançar"
            {
                NextSites.pop();
            }
        }
        else if (commands[i] == "back" && !BackSites.empty())
        {
            NextSites.push(current);   // Salva a atual no "forward"
            current = BackSites.top(); // Volta uma página
            BackSites.pop();
        }
        else if (commands[i] == "forward" && !NextSites.empty())
        {
            BackSites.push(current);   // Salva a atual no "back"
            current = NextSites.top(); // Avança uma página
            NextSites.pop();
        }
    }
}
string reverseWords(string frase)
{
    int t = frase.length();
    int i = 0;
    stack<string> Palavras;
    string palavra = "";
    string invertida = "";
    while (i < t)
    {
        if (frase[i] != ' ')
        {
            palavra += frase[i];
        }
        else
        {
            Palavras.push(palavra);
            palavra.clear();
        }

        i++;
    }

    if (palavra != "")
    {
        Palavras.push(palavra);
    }
    while (Palavras.size() != 0)
    {
        string topo = Palavras.top();
        invertida += topo;
        Palavras.pop();
        if (!Palavras.empty())
        {
            invertida += " ";
        }
    }

    return invertida;
}
