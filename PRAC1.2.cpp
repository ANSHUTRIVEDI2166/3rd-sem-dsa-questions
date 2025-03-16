#include<iostream>
using namespace std;

int LongestWordLength(string str)
{
    int i,Curr_Len=0,res=0;
    int n = str.length();
    for(i=0;i<n;i++)
    {
        if(str[i]!=' ')
        {
            Curr_Len++;
        }
        else
        {
            res=max(res,Curr_Len);
            Curr_Len=0;
        }
    }

    return max(res,Curr_Len);
}

int main()
{
    string s;
    getline(cin,s);
    cout<<LongestWordLength(s);
}
