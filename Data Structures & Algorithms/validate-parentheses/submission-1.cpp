class Solution {
public:
    bool isValid(string s) {
        stack<char> temp;
        for(char c: s)
        {
            if(c == '(' || '{' || '[')
            {
                temp.push(c);
            }
            else if(c == ')' || '}' || ']')
            {
                if( (temp.top() == '(' && c == ')') ||
                    (temp.top() == '{' && c == '}') ||
                    (temp.top() == '[' && c == ']'))
                {
                    temp.pop();
                }
                else return false;

            }
        }
        return true;
    }
};
