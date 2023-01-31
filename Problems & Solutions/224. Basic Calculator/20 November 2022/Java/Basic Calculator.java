class Solution {
    public int calculate(String s) {
        int sign = 1;
		int ans = 0;
		Stack<Integer> stack = new Stack<Integer>();
		for (int i = 0; i < s.length(); i++) {
			if (Character.isDigit(s.charAt(i))) {
				int sum = s.charAt(i) - '0';
				while (i + 1 < s.length() && Character.isDigit(s.charAt(i + 1))) {
					sum = sum * 10 + s.charAt(i + 1) - '0';
					i++;
				}
				ans += sum * sign;
			} else if (s.charAt(i) == '+') {
				sign = 1;
			} else if (s.charAt(i) == '-') {
				sign = -1;
			} else if (s.charAt(i) == '(') {
				stack.push(ans);
				stack.push(sign);
				ans = 0;
				sign = 1;
			} else if (s.charAt(i) == ')') {
				ans = ans * stack.pop() + stack.pop();
			}

		}
		return ans;
    }
}