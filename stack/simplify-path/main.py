class Solution:
    def simplifyPath(self, path: str) -> str:
        n = len(path)
        stack = [""] * 3000       

        idx = 0
        end = 0
        tmp = ""

        while end <= n:
            if end == n or path[end] == "/":
                if tmp == "..":
                    if idx > 0:
                        idx -= 1
                elif tmp != "" and tmp != ".":
                    stack[idx] = "/" + tmp
                    idx += 1
                tmp = ""
            else:
                tmp += path[end]
            
            end += 1

        ans = ""
        for i in range(idx):
            ans += stack[i]

        return ans if len(ans) > 0 else "/"
