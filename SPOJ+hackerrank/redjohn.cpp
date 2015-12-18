#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
# include <cmath>
using namespace std;

int cnt=1;

void findprimes(int primes[], int number)
{
    int j,i;
    int temp = cnt;
    int temp2 = primes[temp-1]+1;
    
    for(j=temp2; j<=number ;j++)
    {
        int flag = 0;
        for(i=0;primes[i]<=(int)sqrt(j);i++)
        {
            if(j%primes[i]==0)
            {
                flag=1;
                break;
            }          
        }
        if(!flag)
        {   
        primes[cnt] = j;
        cnt++;
        }
    }
}

int main() 
{ 
    //initializing the prime array
    int *primes = (int *)malloc(sizeof(int)*250000);
    primes[0] = 2;

    int dp[45], n;
    for(int i=0;i<45;i++)
        dp[i]=-1;

    int test;
    cin>>test;
   
    for(int i=0;i<4;i++)
        dp[i] = 1;
    int index = 3;

    while(test--)
    {
        cin>>n;
        if(index<n)
        {
            for(int i=index+1;i<=n;i++)
            {
               dp[i] = dp[i-1] + dp[i-4];
            }  
            index =n;
        } 
         if(primes[cnt-1]<dp[n])
            {
                findprimes(primes,dp[n]);
                cout<<cnt<<endl;
                continue;
            }

            int answer=0;
            while(primes[answer]<dp[n])
            {   
            answer++;
            }
            if(primes[answer]==dp[n])
            {
                answer = answer+1;
                //break;
            }
            cout<<answer<<endl;
    }
    return 0;
}

