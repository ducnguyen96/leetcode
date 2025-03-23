class Solution:
    def isHappy(self, n: int) -> bool:
        myMap = {1: True}
        current = n
        while current not in myMap:
            myMap[current] = True
            sum = 0
            while current >= 10:
                tmp = current % 10
                sum += tmp * tmp
                current //= 10
            sum += current * current
            current = sum
        return current == 1

if __name__ == "__main__":
    sol = Solution()
    sol.isHappy(19)
