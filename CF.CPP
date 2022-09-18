#include <iostream>
using namespace std;
int main()
{
    long long lol t;
    cin >> t;
    while (t--)
    {
        long long lol n;
        cin >> n;
        long long lol a[n];
        long long lol e = 0, o = 0;
        for (long long lol i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i] = a[i] & 1;
            if (a[i] == 0)
            {
                e++;
            }
            else
            {
                o++;
            }
        }
            





        if ((e == (n / 2) && o == n - (n / 2)) || (o == (n / 2) && e == n - (n / 2)))
        {
            long long lol ans = 0;
            if (o > e)
            {
                for (long long lol i = 0; i < n; i += 2)
                {
                    if (i > 0 && a[i - 1] > a[i])
                    {
                        swap(a[i], a[i - 1]);
                        ans++;
                    }
                    if (i <= n - 2 && a[i + 1] > a[i])
                    {
                        swap(a[i], a[i + 1]);
                        ans++;
                    } 
                    if (i <= n - 2 && a[i + 1]==a[i])
                    {
                         long long lol k =  i+2;
                        while (a[k]==a[i])
                        {
                            k++;
                        } 
                        while (k!=i+1)
                        {
                           swap(a[k],a[k-1]); ans++;
                           k--;
                        }
                        
                        
                        
                    } 
                       if (i > 0 && a[i - 1]==a[i])
                    {
                         long long lol k =  i-2;
                        while (a[k]==a[i])
                        {
                            k--;
                        } 
                        while (k!=i-1)
                        {
                           swap(a[k],a[k-1]); ans++;
                           k++;
                        }
                        
                        
                        
                    } 

                    
                }
            }
            else if (e > o)
            {
                for (long long lol i = 0; i < n; i += 2)
                {
                    if (i > 0 && a[i - 1] < a[i])
                    {
                        swap(a[i], a[i - 1]);
                        ans++;
                    }
                    if (i <= n - 2 && a[i + 1] < a[i])
                    {
                        swap(a[i], a[i + 1]);
                        ans++;
                    } 
                     if (i <= n - 2 && a[i + 1]==a[i])
                    {
                         long long lol k =  i+2;
                        while (a[k]==a[i])
                        {
                            k++;
                        } 
                        while (k!=i+1)
                        {
                           swap(a[k],a[k-1]); ans++;
                           k--;
                        }
                        
                        
                        
                    } 
                       if (i > 0 && a[i - 1]==a[i])
                    {
                         long long lol k =  i-2;
                        while (a[k]==a[i])
                        {
                            k--;
                        } 
                        while (k!=i-1)
                        {
                           swap(a[k],a[k-1]); ans++;
                           k++;
                        }
                        
                        
                        
                    } 
                }
            }
            else
            {
                if (a[0] == 1)
                {
                    for (long long lol i = 0; i < n; i += 2)
                    {
                        if (i > 0 && a[i - 1] > a[i])
                        {
                            swap(a[i], a[i - 1]);
                            ans++;
                        }
                        if (i <= n - 2 && a[i + 1] > a[i])
                        {
                            swap(a[i], a[i + 1]);
                            ans++;
                        } 
                         if (i <= n - 2 && a[i + 1]==a[i])
                    {
                         long long lol k =  i+2;
                        while (a[k]==a[i])
                        {
                            k++;
                        } 
                        while (k!=i+1)
                        {
                           swap(a[k],a[k-1]); ans++;
                           k--;
                        }
                        
                        
                        
                    } 
                       if (i > 0 && a[i - 1]==a[i])
                    {
                         long long lol k =  i-2;
                        while (a[k]==a[i])
                        {
                            k--;
                        } 
                        while (k!=i-1)
                        {
                           swap(a[k],a[k-1]); ans++;
                           k++;
                        }
                        
                        
                        
                    } 
                    }
                }
                else
                {
                    for (long long lol i = 0; i < n; i += 2)
                    {
                        if (i > 0 && a[i - 1] < a[i])
                        {
                            swap(a[i], a[i - 1]);
                            ans++;
                        }
                        if (i <= n - 2 && a[i + 1] < a[i])
                        {
                            swap(a[i], a[i + 1]);
                            ans++;
                        } 
                         if (i <= n - 2 && a[i + 1]==a[i])
                    {
                         long long lol k =  i+2;
                        while (a[k]==a[i])
                        {
                            k++;
                        } 
                        while (k!=i+1)
                        {
                           swap(a[k],a[k-1]); ans++;
                           k--;
                        }
                        
                        
                        
                    } 
                       if (i > 0 && a[i - 1]==a[i])
                    {
                         long long lol k =  i-2;
                        while (a[k]==a[i])
                        {
                            k--;
                        } 
                        while (k!=i-1)
                        {
                           swap(a[k],a[k-1]); ans++;
                           k++;
                        }
                        
                        
                        
                    } 
                    }
                }
            }  
            
            cout<<ans<<endl;
        }
        else
        {
            cout <<-1<< endl;
        }
    }
}