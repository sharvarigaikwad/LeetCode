class Solution {
public:
    
    struct WordInfo
    {
        vector<string> dict_keys;
        int distance;
    };
    
    int findLength(string begin, string end, map<string, WordInfo> wordMap, map<string, vector<string>> dict)
    {
        wordMap[begin].distance = 1;
        queue<string> q;
        q.push(begin);
        string cur_word;
        if(wordMap[begin].dict_keys.empty())
        {
            vector<string> list;
            for(int i = 0; i < begin.length(); i++)
            {
                cur_word = begin;
                cur_word.replace(i, 1, "*");
                list.push_back(cur_word);
            }
            wordMap[begin].dict_keys = move(list);
        }

        string word;
        WordInfo wordInfo;
        int cur_distance;
        while(!q.empty())
        {
            word = q.front();
            q.pop();
            wordInfo = wordMap[word];
            cur_distance = wordInfo.distance + 1;
            for(string key: wordInfo.dict_keys)
            {
                vector<string> adj_words = dict[key];
                for(string adj_word: adj_words)
                {
                    if(adj_word == end)
                    {
                        return cur_distance;
                    }
                    if(wordMap[adj_word].distance == -1)
                    {
                        wordMap[adj_word].distance = cur_distance;
                        q.push(adj_word);
                    }
                }
            }
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<string>> dict;
        map<string, WordInfo> wordMap;
        string cur_word;
        int len, i;
        len = wordList[0].length();
        for(auto word: wordList)
        {
            vector<string> list;
            for(i = 0; i < len; i++)
            {
                cur_word = word;
                cur_word.replace(i, 1, "*");
                list.push_back(cur_word);
                dict[cur_word].push_back(word);
            }
            WordInfo wordInfo;
            wordInfo.dict_keys = move(list);
            wordInfo.distance = -1;
            wordMap[word] = wordInfo;
        }

        return findLength(beginWord, endWord, wordMap, dict);
    }
};