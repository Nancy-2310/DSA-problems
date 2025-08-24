class Solution {
public:
 int reverse(int x) {
    long long ans = 0;
    int num = abs(x);

    while (num > 0) {
        int rem = num % 10;
        ans = ans * 10 + rem;
        num /= 10;
    }

    if (ans > INT_MAX) return 0;
    return (x < 0) ? -ans : ans;
}

bool isPalindrome(int x) {
    if (x < 0) return false; // negatives can't be palindromes
    return x == reverse(x);
}
};