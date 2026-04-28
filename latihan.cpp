#include <bits/stdc++.h>
using namespace std;

int precendence(char op){
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    else return 0;
}

bool isoperator(char c){
    return(c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string intopost(string infix){
    stack<int> st;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++){
        char c = infix[i];
        if (isalnum(c)){
            postfix += c;
        }
        else if (c == '(') st.push(c);
        else if (c == ')'){
            while(!st.empty() && st.top() != '('){
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else if (isoperator(c)){
            while (!st.empty() && precendence(st.top()) >= precendence(c)){
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()){
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int main(){
    string infix;
    cout << "Masukkan infix: ";
    cin >> infix;
    string postfix = intopost(infix);
    cout << "Postfix: " << postfix << endl;
    return 0;
}