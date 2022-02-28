#include<bits/stdc++.h>
using namespace std;

void tokenizer(string text,vector<string> &tokens)
{
    string T;
    stringstream ss(text);
    while(getline(ss,T,' '))
    {
        tokens.push_back(T);
    }
}

void rStrip(string &text)
{
    text=text.substr(1,text.size()-1);
}

vector<string> n_gram(vector<string> &tokens, int n)
{
    int st=0,en=n-1;
    vector<string> gram;
    while(en<tokens.size())
    {
        string temp="";
        for(int i=st;i<=en;i++)
        {
            temp=temp+" "+tokens[i];
        }
        rStrip(temp);
        gram.push_back(temp);
        temp="";
        st++;
        en++;
    }
    return gram;
}


int main()
{
    int n=5;
    string text="I want to learn data science";
    vector<string> tokens;
    tokenizer(text,tokens);
    vector<string> gram=n_gram(tokens,n);
    for(auto i:gram)
    {
        cout<<i<<endl;
    }
    return 0;
}