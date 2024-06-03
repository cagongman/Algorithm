#include <string>
#include <vector>

using namespace std;

bool IsBracket(char front, char back)
{
    if (front == '(' && back == ')') return true;
    if (front == '[' && back == ']') return true;
    if (front == '{' && back == '}') return true;
    return false;
}

bool IsBracketString(string str)
{
    if (str.empty())
        return true;

    bool loop = false;
    for (int i = 1; i < str.size(); ++i)
    {
        if (IsBracket(str[i - 1], str[i]))
        {
            str.erase(i - 1, 2);
            loop = true;
        }
    }

    if (loop)
        return IsBracketString(str);
    return false;
}

int solution(string s) {
    int answer = 0;
    int loopCount = s.size();

    for (int i = 0; i < loopCount; ++i)
    {
        if (IsBracketString(s))
            ++answer;

        char front = s.front();
        s.erase(0, 1);
        s.push_back(front);
    }

    return answer;
}