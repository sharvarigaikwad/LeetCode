class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> n1, n2;
        string res, temp_res;
        int sum, mult, carry = 0;
        if(num1 == "0" || num2 == "0")
            return "0";
        for(char c: num1)
        {
            n1.push_back(c - '0');
        }
        for(char c: num2)
        {
            n2.push_back(c - '0');
        }
        reverse(n1.begin(), n1.end());
        reverse(n2.begin(), n2.end());
        
        vector<int> carries(n2.size(), 0);
        int n1_i = 0, n2_j = 0, k;
        for(k = 1; k < n1.size()+n2.size(); k++)
        {
            sum = carry;
            carry = 0;
            n2_j = 0; n1_i = k - 1;
            for(n2_j = 0; n2_j < k; n2_j++, n1_i--)
            {
                if(n1_i < n1.size() && n2_j < n2.size())
                {
                    mult = n1[n1_i] * n2[n2_j];
                    if(carries[n2_j])
                    {
                        mult += carries[n2_j];
                    }
                    if(mult >= 10)
                    {
                        sum += mult%10;
                        carries[n2_j] = mult/10;
                        if(n1_i == n1.size() - 1)
                        {
                            carry += mult/10;
                        }
                    }
                    else
                    {
                        sum += mult;
                        carries[n2_j] = 0;
                    }
                }
            }
            if(sum >= 10)
            {
                carry += sum / 10;
                sum = sum % 10;
            }
            
            temp_res = ('0' + sum);
            res = temp_res + res;
        }
        if(carry > 0)
        {
            temp_res = ('0' + carry) ;
            res = temp_res + res;
        }
        return res;
    }
};