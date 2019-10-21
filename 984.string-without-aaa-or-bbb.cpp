class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string str;
        string c[2] = {"a", "b"};
        if(B > A)
        {
			int temp = A;
			A = B;
			B = temp;
            c[0] = "b";
            c[1] = "a";
		}
        while(A > 0 && B > 0 && A > B)
        {
            if(A - 2 >= B - 1 && (A - 2 > 0) && (B - 1 >= 0))
            {
                str += c[0] + c[0] + c[1] ;
                A -= 2;
                B -= 1;
            }
            else if(A - 2 >= B - 2  && (A - 2 > 0) && (B - 2 >= 0))
            {
                str += c[0] + c[0] + c[1] + c[1] ;
                A -= 2;
                B -= 2;
            }
            else
            {
                str += c[0] + c[1] ;
                A -= 1;
                B -= 1;
            }
        }
        while(A == B && A > 0 )
        {
            if(A >= 2)
            {
                str += c[0] + c[0] + c[1] + c[1] ;
                A -= 2;
                B -= 2;
            }
            else
            {
                str += c[0] + c[1] ;
                A--; B--;
            }
        }
        while(A)
        {
            str += c[0] ;
            A--;
        }
        return str;
    }
};