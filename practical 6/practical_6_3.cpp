#include<iostream>
#include<stack>
using namespace std;
int precedence(char c)
{
    if(c == '^')
        return 3;
    if(c == '*' || c == '/')
        return 2;
    if(c == '+' || c == '-')
        return 1;
    return -1;
}
string InfixtoPostfix(string s)
{
    stack<char> ch;
    string result = "";
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(')
        {
            ch.push(s[i]);
        }
        else if(s[i] == ')')
        {
            while(!ch.empty() && ch.top() != '(')
            {
                result += ch.top();
                ch.pop();
            }
            if(!ch.empty())
                ch.pop();
        }
        else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
        {
            while(!ch.empty() && ch.top() != '(' &&
                  precedence(s[i]) <= precedence(ch.top()))
            {
                result += ch.top();
                ch.pop();
            }
            ch.push(s[i]);
        }
        else
        {
            result += s[i];
        }
    }
    while(!ch.empty())
    {
        result += ch.top();
        ch.pop();
    }
    return result;
}
int main()
{
    string exp1 = "3+4*2";
    string exp2 = "(3+4)*2";
    cout << "Infix expression:" << endl;
    cout << "1. " << exp1 << endl;
    cout << "2. " << exp2 << endl;
    cout << "Postfix expression:" << endl;
    cout << "1. " << InfixtoPostfix(exp1) << endl;
    cout << "2. " << InfixtoPostfix(exp2) << endl;
    return 0;
}
