//Omar Rodrigo Sorchini Puente A01749389
//Eva Denisse Vargas Sosa A01377098
//Emilio Campuzano Mejía A01378948

#include <iostream>
#include "stack.h"
#include <regex>
#include <vector>
#include <cctype>
#include <string>
#include <stdexcept>

using namespace std;

void split(const string& input, vector<string>& vec)
{
    regex exp(R"((\d+)|(\s)|(.))");
    smatch match;
    string s = input;

    while(regex_search(s, match, exp)) {
        if (match[2] == "") {
            vec.push_back(match[0]);
        }
        s = match.suffix();
    }
}

bool balanced_brackets(const string& expr)
{   Stack<char> stack1;
    //push abre
    //pop cierra
    for (int i = 0; i < expr.size(); ++i){
        if (expr[i]=='[' || expr[i]=='{' || expr[i]=='('){
            stack1.push(expr[i]);

        }
        else if(expr[i]==']' || expr[i]=='}' || expr[i]==')'){
            if(stack1.is_empty()){
                return false;
            }
            if (expr[i] == ']' && stack1.peek() == '['){
                stack1.pop();
            }
            else if (expr[i] == '}' && stack1.peek() == '{'){
                stack1.pop();
            }
            else if (expr[i] == ')' && stack1.peek() == '('){
                stack1.pop();
            }
            else {
                return false;
            }

        }
    }
    if (stack1.is_empty()){
        return true;
    }
    else {
        return false;
    }
}

int postfix_evaluation(const string& expr)
{
    Stack<int> stack2;
    vector<string> vec;
    split(expr, vec);

    for (int i = 0;i<vec.size();++i)
    {
        if (isdigit(vec[i][0])){
            stack2.push(stoi(vec[i]));
        }
        else if (vec[i] == "+" || vec[i] == "-" || vec[i] == "*" || vec[i] == "/"){
            if (stack2.size()<2){
                throw runtime_error("Runtime Error");
            }
            if (vec[i] == "+"){
                int a = stack2.pop();
                int b = stack2.pop();
                int c = a+b;
                stack2.push(c);
            }
            else if (vec[i] == "-"){
                int a = stack2.pop();
                int b = stack2.pop();
                int c = b-a;
                stack2.push(c);
            }
            else if (vec[i] == "*"){
                int a = stack2.pop();
                int b = stack2.pop();
                int c = a*b;
                stack2.push(c);
            }
            else if (vec[i] == "/"){
                int a = stack2.pop();
                int b = stack2.pop();
                int c = b/a;
                stack2.push(c);
            }
            else {
                throw runtime_error("Runtime Error");
            }
        }
    }
    if (stack2.size() == 1){
        return stack2.pop();
    }
    else {
        throw runtime_error("Runtime Error");
    }
}



int main()
{

    //Parte 1
    //Casos verdaderos
    cout << "Parte1" << endl;
    cout << balanced_brackets("") << endl;
    cout << balanced_brackets("(7)") << endl;
    cout << balanced_brackets("[]{}()([]{})")<< endl;
    cout << balanced_brackets("[({(([[{}][{}][{}]]))})]")<< endl;
    //Casos falsos
    cout << balanced_brackets("{)")<< endl;
    cout << balanced_brackets("]({})")<< endl;
    cout << balanced_brackets("((((")<< endl;
    cout << balanced_brackets("))))")<< endl;
    cout << balanced_brackets("(]{)[}") << endl;
    cout << balanced_brackets("[]{}()[]{})([])")<< endl;
    cout << balanced_brackets("[[({(([[{}][{}][{}]]))})]")<< endl;

    //Parte 2
    cout << "Parte2"<< endl;
    cout << (42 == postfix_evaluation("42")) << endl;
    cout << (26 == postfix_evaluation("20 6 +")) << endl;
    cout << (14 == postfix_evaluation("20 6 -")) << endl;
    cout << (120 == postfix_evaluation("20 6 *")) << endl;
    cout << (3 == postfix_evaluation("20 6 /")) << endl;
    cout << (8 == postfix_evaluation("1 5 2 * 20 6 / - +")) << endl;
    cout << (108 == postfix_evaluation("4 8 15 16 23 42 + + + + +")) << endl;

    return 0;
}