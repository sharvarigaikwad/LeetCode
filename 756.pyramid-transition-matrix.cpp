class Solution {
public:
    string characters[7] = {"A", "B", "C", "D", "E", "F", "G"};
    
    bool checkPossibility(string bottom, map<int, int> allow, string sofar, int start)
    {
        
        bool result;
        if(bottom.size() <= 1)
        {
            return true;
        }
        if(start == bottom.size() - 1)
        {
            return checkPossibility(sofar, allow, "", 0);
        }
        int a = bottom.at(start) - 'A';
        int b = bottom.at(start + 1) - 'A';
        int key = (1 << a) | (1 << (8 + b));
        if(allow.count(key) < 1)
        {
            return false;
        }
        int c = allow[key], i;
        for(i = 0; i < 7 ; i++)
        {
            if(c & (1 << i))
            {
                result = checkPossibility(bottom, allow, sofar+characters[i], start + 1);
                if(result)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        map<int, int> allow;
        int a, b, c, key;
        if(bottom.size() == 0)
        {
            return true;
        }
        if(allowed.size() == 0)
        {
            return false;
        }
        for(string s: allowed)
        {
            a = s.at(0) - 'A';
            b = s.at(1) - 'A';
            c = s.at(2) - 'A';
            key = (1 << a) | (1 << (b + 8));
            if(allow.count(key) == 0) allow[key] = 0;
            allow[key] = allow[key] | (1 << c);
        }
        return checkPossibility(bottom, allow, "", 0);
    }
};