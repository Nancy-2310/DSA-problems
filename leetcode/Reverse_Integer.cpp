class Solution {
public:
    int reverse(int x) {
        long long a = x;
        if(a < 0) a = -a;
        long long ans = 0;  
        while(a > 0){
            int rem = a % 10;
            ans = ans * 10 + rem;
            a = a/10;
        }
        if(ans > INT_MAX || ans < INT_MIN) return 0;
        if(x < 0) return -ans;
        return ans;
    }
};