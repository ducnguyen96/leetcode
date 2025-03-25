function simplifyPath(path: string): string {
  const n = path.length;
  const stack = Array(3000);

  let idx = 0;
  let tmp = "";
  let end = 0;

  while (end <= n) {
    if (end === n || path[end] == "/") {
      if (tmp === "..") {
        if (idx > 0) idx--;
      } else if (tmp !== "." && tmp !== "") {
        stack[idx] = "/" + tmp;
        idx++;
      }
      tmp = "";
    } else {
      tmp += path[end];
    }

    end++;
  }

  let ans = "";
  for (let i = 0; i < idx; i++) {
    ans += stack[i];
  }

  return ans.length ? ans : "/";
}
