include<iostream>
include<string>
include<cmath>
int main(string s)
{
    char* chars=(char*)s.c_str();
    return max(calc(chars, 0, 1, s.length(), '('), calc(chars, s.length() -1, -1, -1, ')'));
}
int calc(char* chars , int i ,  int flag,int end, char cTem)
{
    int max = 0, sum = 0, currLen = 0,validLen = 0;
    for (;i != end; i += flag) 
    {
        sum += (chars[i] == cTem ? 1 : -1);
        currLen ++;
        if(sum < 0)
        {
            max = max > validLen ? max : validLen;
            sum = 0;
            currLen = 0;
            validLen = 0;
        }
        else if(sum == 0)
        {
            validLen = currLen;
        }
    }
    return max > validLen ? max : validLen;
}
