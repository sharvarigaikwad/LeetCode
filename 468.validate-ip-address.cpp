class Solution {
public:
    string validateIPv4(string IP)
    {
        stringstream ss;
        ss.str(IP);
        string item;
        char delim = '.', c;
        int itm_len, i, cnt = 0;
        if(count(IP.begin(), IP.end() , delim) != 3)
        {
            return "Neither";
        }
        while(getline(ss, item, delim))
        {
            cnt++;
            itm_len = item.length();
            if(item.length() > 3 || itm_len < 1 || (itm_len > 1 && item[0] == '0'))
            {
                return "Neither";
            }
            for(i = 0; i < itm_len; i++)
            {
                c = item[i];
                if(c < '0' || c > '9')
                {
                    return "Neither";
                }
            }
            int value = atoi(item.c_str());
            if(value < 0 || value > 255)
            {
                return "Neither";
            }
        }
        if(cnt != 4)
        {
            return "Neither";
        }
        return "IPv4";
    }
    string validateIPv6(string IP)
    {
        stringstream ss;
        ss.str(IP);
        char c,  delim = ':';
        string item;
        int itm_len, i, cnt = 0;
        if(count(IP.begin(), IP.end() , delim) != 7)
        {
            return "Neither";
        }
        while(getline(ss, item, delim))
        {
            cnt++;
            itm_len = item.length();
            if(itm_len > 4 || itm_len < 1)
            {
                return "Neither";
            }
            for(i = 0; i < itm_len; i++)
            {
                c = item[i];
                if(!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')))
                {
                    return "Neither";
                }
            }
        }
        if(cnt != 8)
        {
            return "Neither";
        }
        return "IPv6";
    }
    string validIPAddress(string IP) {
        auto pos = IP.find(".");
        if(pos != string::npos)
        {
            return validateIPv4(IP);
        }
        pos = IP.find(":");
        if(pos != string::npos)
        {
            return validateIPv6(IP);
        }
        return "Neither";
    }
};