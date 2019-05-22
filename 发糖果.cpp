//.表示空房子，s表示商店，h表示居民房
//在t时间内给所有邻居发糖
//求开始所带最小糖数
#include <iostream>
#include<string.h>
#include<string>
#include<algorithm>
#include<map>
#include<stack>
#include<set>
using namespace std;
const int N = 1e6 + 100;
const int M = 1e4 + 100;

int m,n,k,h;

string s;

char s1[100];
stack<int> S;
stack<int> x;
int a[M];
int b[N];
set<int> ss;

bool check(int k) {
    h = 0;
    for(int i = 0;i < n;i++){
        char ch = s[i];
        if(ch == '.')   continue;
        if(ch == 'S') {
                k++;
            continue;
        }


        if(k) k--;
        else{
                int flag = 0;
            int len1 = N;
            int len2 = N;
            for(int j = i-1;j > 0;j--){
                if(s[j] == 'S'){
                    len1 = 2*(i-j);
                    flag = 1;
                    break;
                }
            }
             for(int j = i+1;j < n;j++){
                if(s[j] == 'S'){
                    len2 = 2*(j-i);
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)   return true;
            h += min(len1,len2);
        }
    }
    h += (n-1);
    if(h <= m) return false;
    return true;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m >> s;
        int l = -1;
        int r = n+1;
        while(r-l > 1) {
            int mid = (l+r) / 2;
            if(check(mid))
                l = mid;
            else
                r = mid;
        }
        if(l == r)  cout << -1 << endl;
        else cout << r<< endl;

    }
    return 0;
}
