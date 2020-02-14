class Solution {
public:
    void trim(string &s)
    {
        if(s.empty() || s == "") 
            return;
        int start = 0, len = s.length(), end = len - 1;
        while(start < len && s[start] == ' ')
        {
            start++;
        }
        if(s[start] == '-' || s[start] == '+')
            start++;
        while(end >= 0 && s[end] == ' ')
        {
            end--;
        }
        s = s.substr(start, end - start + 1);
        if(s.find(' ') != string::npos)
            s = "";
    }
    bool isNumber(string s) {
        trim(s);
        if(s.empty() || s == "")
        {
            return false;
        }
        bool decimal = false, exp = false, num = false;
        int len = s.length(), i = 0;
        for(; i < len; i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                num = true;
            }
            else if(s[i] == 'e')
            {
                if(exp == true || num == false || i == len - 1)
                {
                    return false;
                }
                exp = true;
                decimal = false;
                if(s[i + 1] == '+' || s[i + 1] == '-')
                {
                    if(i + 1 == len - 1)
                    {
                        return false;
                    }
                    i++;
                }
            }
            else if(s[i] == '.')
            {
                if(decimal == true || exp == true)
                {
                    return false;
                }
                decimal = true;
            }
            else
            {
                return false;
            }
        }
        return num;
    }
};