class IdealString
{
    int L;
    int[][] memo;

public:
    String construct(int L)
    {
        this.L = L;
        String ans = "";
        int nxt = 0;
        Queue<Character> q = new LinkedList();
        memo = new int[L + 1][L + 1];
        while (ans.length() < L)
        {
            if (can(ans.length() + 1, q.size() - 1))
            {
                ans += q.poll();
                continue;
            }
            char c = (char)('A' + nxt++);
            for (int i = 0; i < ans.length(); i++)
                q.add(c);
            ans += c;
            if (!can(ans.length(), q.size()))
                return "";
        }
        return ans;
    }
    boolean can(int len, int left)
    {
        if (left < 0)
            return false;
        if (len == L)
            return left == 0;
        if (left + len > L)
            return false;
        if (memo[len][left] != 0)
            return memo[len][left] == 1;
        if ((can(len + 1, left + len)) || (left > 0 && can(len + 1, left - 1)))
        {
            memo[len][left] = 1;
            return true;
        }
        memo[len][left] = 2;
        return false;
    }
};