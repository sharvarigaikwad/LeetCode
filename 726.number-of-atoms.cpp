class Solution {
public:
    string countOfAtoms(string formula) {
        string res;
        int pos = 0;
        map<string, int> cur_count=countHelper(formula, pos, formula.length());
        for(auto p: cur_count)
        {
            res += p.first;
            res += p.second > 1 ? to_string(p.second) :"";
        }
        return res;
    }
    map<string, int> countHelper(string &formula, int& pos, int len)
    {
        int t_c = 0;
        map<string, int> cnts;
        while(pos < len && formula[pos] != ')')
        {
            t_c = 0;
            if(formula[pos] == '(')
            {
                pos++;
                map<string, int> inter=countHelper(formula, pos, len);
                pos++;
                while(pos<len && formula[pos] >= '0' && formula[pos] <= '9')
                {
                    t_c = 10*t_c + (formula[pos]-'0');
                    pos++;
                }
                for(auto p: inter)
                {
                    cnts[p.first]=cnts[p.first] + (p.second*t_c);
                }
            }
            else
            {
                string name = string(1,formula[pos]);
                if(formula[pos+1] >= 'a' && formula[pos+1] <= 'z')
                {
                    pos++;
                    name+= formula[pos];
                }
                if(formula[pos+1] >= '0' && formula[pos+1] <= '9')
                {
                    pos++;
                    t_c = formula[pos]-'0';
                    pos++;
                    while(pos<len && formula[pos] >= '0' && formula[pos] <= '9')
                    {
                        t_c = 10*t_c + (formula[pos]-'0');
                        pos++;
                    }
                }
                else
                {
                    pos++;
                    t_c = 1;
                }
                cnts[name] += t_c;
                
            }
            
        }
        return cnts;
    }
};