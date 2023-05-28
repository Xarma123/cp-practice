 else if (j == v + i - 1)
            {
                a[j] = j * 1ll * j + a[j - i];
            }
            else
            {
                a[j] = j * 1ll * j + a[j - i - 1] + a[j - i] - a[j - i - (i - 1)];
            }