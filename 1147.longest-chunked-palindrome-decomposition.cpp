class Solution {
public:
    int longestDecomposition(string text) {
        int len = text.length();
        if(len <= 1)
        {
            return len;
        }
        char c = text[0];
        for(int j = len-1; j >= (len)/2; j--)
        {
            if(text[j] == c && strcmp(text.substr(0, len-j).c_str(), text. substr(j).c_str()) == 0)
            {
                text = text.substr(len-j, 2*j - len);
                return 2+longestDecomposition(text);
            }
        }
        return 1;
    }
};