class Solution {
public:
   void setDefault(int visited[], int len)
   {
       for(int i = 0; i < len; i++)
       {
           visited[i] = -1;
       }
   }
    bool allSet(int visited[], int total_words)
    {
        for(int i = 0; i < total_words; i++)
        {
            if(visited[i] == -1)
            {
                return false;
            }
        }
        return true;
    }
    void setDefaultTill(int visited[], int len, int max_val)
    {
        for(int i = 0; i < len; i++)
        {
            if(visited[i] <= max_val)
            {
                visited[i] = -1;
            }
        }
    }
    int findSmallest(int visited[], int len)
    {
        int smallest = len - 1;
        for(int i = 0; i < len; i++)
        {
            if(visited[i] < visited[smallest])
            {
                smallest = i;
                //cout<< " new smallest = " << i << endl;
            }
        }
        return smallest;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> positions;
        vector<vector<int>> word_position;
        int total_words = words.size(), strlen = s.size(), i, j;
        vector<string>::iterator res;
        if(total_words == 0 || strlen == 0)
        {
            return positions;
        }
        int word_len = words[0].size();
        int visited[total_words] = {-1};
        if(strlen < word_len * total_words)
        {
            return positions;
        }
        
        for(i = 0; i < strlen; i++)
        {
            res = find(words.begin(), words.end(), s.substr(i, word_len));
            if(res == words.end())
            {
                word_position.push_back({-1});
            }
            else 
            {
                vector<int> temp;
                while(res != words.end())
                {
                    temp.push_back(distance(words.begin(), res));
                    res = find(res+1, words.end(),s.substr(i, word_len));
                }
                word_position.push_back(temp);
            }
        }
        /*for(i = 0; i < strlen; i++)
        {
            cout << word_position[i] << " ";
        }
        cout << endl;*/
        for(j = 0; j < word_len; j++)
        {
            setDefault(visited, total_words);
            //cout << "j = " << j << endl;
            for(i = j; i < strlen; i += word_len)
            {
                //cout << " i = " << i;
                if(word_position[i][0] == -1)
                {
                    //cout << "wordpos = -1, cleared\n";
                    setDefault(visited, total_words);
                    continue;
                }
                vector<int> temp = word_position[i];
                int cur_small = 0, itr = 0;
                while(itr < temp.size() && visited[temp[itr]] != -1)
                {
                    if(visited[temp[itr]] < visited[temp[cur_small]])
                    {
                        cur_small = itr;
                    }
                    itr++;
                }
                //cout << cur_small << " vs " << itr << " to be replaced!\n";
                if(itr == temp.size())
                {
                    //cout << "word already visited, cleared till "<< visited[temp[cur_small]]  <<"\n";
                    setDefaultTill(visited, total_words, visited[temp[cur_small]]);
                    visited[temp[cur_small]] = i;
                }
                else
                {
                    visited[temp[itr]] = i;
                    //cout << "word_position[i] is " << temp[itr] << endl;
                    if(allSet(visited, total_words))
                    {
                        int smallest  = findSmallest(visited, total_words);
                        positions.push_back(visited[smallest]);
                        //cout << "   added and erased "<< visited[smallest] << endl;
                        visited[smallest] = -1;
                    }
                }
            }
        }
        return positions;
    }
};