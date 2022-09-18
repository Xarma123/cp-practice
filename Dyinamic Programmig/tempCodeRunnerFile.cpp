 // code here
        lol c = N;
        lol s = 0;
        while (c--)
            s += arr[c];

        if (s % 2 != 0)
            return false;
        s = s / 2;

        bool dp[N + 1][s + 1];

        for (lol i = 1; i <= s; i++)
        {
            dp[0][i] = false;
        }

        for (lol i = 0; i <= N; i++)
        {
            dp[i][0] = true;
        }

        for (lol i = 1; i <= N; i++)
        {
            for (lol j = 1; j <= s; j++)
            {

                if (j - arr[i - 1] >= 0)
                {

                    dp[i][j] = dp[i - 1][j - arr[i - 1]];
                }
                if (!dp[i][j])
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[N][s];
    }