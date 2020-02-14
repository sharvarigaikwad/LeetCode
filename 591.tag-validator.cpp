class Solution {
public:
    bool isValidTag(string tag)
    {
        int len = tag.length(), i;
        if(len > 9 || len < 1)
            return false;
        for(i = 0; i < len; i++)
        {
            if(tag[i] < 'A' || tag[i] > 'Z')
                return false;
        }
        return true;
    }
    bool isValid(string code) {
        stack<string> tags;
        int len = code.length();
        int i;
        auto last_pos = code.find("<"), pos = code.find(">", last_pos);
        if(!len)
        {
            return true;
        }
        if(last_pos == string::npos)
        {
            return false;
        }
        i = last_pos;
        char c;
        while(i < len && last_pos != string::npos)
        {
            c = code[last_pos+1];
            pos = code.find(">", last_pos);
            if(pos == -1)
            {
                return false;
            }
            if(c == '/')
            {
                if(tags.empty())
                {
                    return false;
                }
                string tagname = code.substr(last_pos+2, pos-last_pos-2);
                if(tags.top()!=tagname)
                {
                    return false;
                }
                tags.pop();
                i = pos+1;
            }
            else if(c == '!')
            {
                if(tags.empty())
                {
                    return false;
                }
                if(code.substr(last_pos, 9) != "<![CDATA[")
                {
                    return false;
                }
                pos = code.find("]]>", last_pos);
                if(pos == -1)
                {
                    return false;
                }
                i = pos+3;
            }
            else
            {
                string tagname = code.substr(last_pos+1, pos-last_pos-1);
                if(isValidTag(tagname))
                {
                    if(tags.empty() && last_pos != 0)
                    {
                        return false;
                    }
                    tags.push(tagname);
                }
                else
                {
                    //cout << tagname << " is not valid\n";
                    return false;
                }
                i = pos+1;
            }
            last_pos = code.find("<", pos);
        }
        if(i != len)
        {
            return false;
        }
        return tags.empty() ? true : false;
    }
};