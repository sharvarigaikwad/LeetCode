class Solution {
public:
    void get_perms(vector<vector<char>> &entries, string prefix, int idx, vector<string> &result)
    {
        vector<char> this_entry = entries[idx];
        if(idx == entries.size() - 1)   
        {
            for(char c: this_entry)
            {
                result.push_back(prefix+c);
            }
            return;
        }
        for(char c: this_entry)
        {
            get_perms(entries, prefix+c, idx+1, result);
        }
    }
    vector<string> expand(string S) {
        vector<vector<char>> entries;
        char c;
        int i, len = S.length();
        vector<char> v;
        vector<string> result;
        if(len == 0)
        {
            return result;
        }
        i = 0;
        while(i < len)
        {
            c = S[i];
            if(c == '{' || c == '}')
            {
                if(v.size())
                {
                    entries.push_back(move(v));
                    v.clear();
                }
            }
            else if(c == ',')
            {
                i++;
                v.push_back(S[i]);
            }
            else
            {
                if(v.size())
                {
                    entries.push_back(move(v));
                    v.clear();
                }
                v.push_back(c);
            }
            i++;
        }
        if(v.size())
        {
            entries.push_back(move(v));
            v.clear();
        }
        len = entries.size();
        for(i = 0; i < len; i++)
        {
            vector<char> entry = entries[i];
            if(entry.size() > 1)
            {
                sort(entry.begin(), entry.end());
                entries[i].clear();
                entries[i] = move(entry);
            }
        }
        get_perms(entries, "", 0, result);
        return result;
    }
};