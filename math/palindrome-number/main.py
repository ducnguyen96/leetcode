class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False

        reverse = 0
        xcopy = x

        while xcopy > 0:
            reverse = reverse * 10 + xcopy % 10
            xcopy //= 10

        return reverse == xcopy
