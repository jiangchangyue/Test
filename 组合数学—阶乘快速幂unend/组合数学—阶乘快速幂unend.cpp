//#include<bits/stdc++.h>
//using namespace std;
//typedef long long LL;
//
//LL exp_mod(LL a, LL b, LL p) {
//    LL res = 1;
//    while(b != 0) {
//        if(b&1) res = (res * a) % p;
//        a = (a*a) % p;
//        b >>= 1;
//    }
//    return res;
//}
//LL Comb(LL a, LL b, LL p) {
//    if(a < b)   return 0;
//    if(a == b)  return 1;
//    if(b > a - b)   b = a - b;
//
//    LL ans = 1, ca = 1, cb = 1;
//    for(LL i = 0; i < b; ++i) {
//        ca = (ca * (a - i))%p;
//        cb = (cb * (b - i))%p;
//    }
//    ans = (ca*exp_mod(cb, p - 2, p)) % p;
//    return ans;
//}
//LL Lucas(int n, int m, int p) {
//     LL ans = 1;
//
//     while(n&&m&&ans) {
//        ans = (ans*Comb(n%p, m%p, p)) % p;
//        n /= p;
//        m /= p;
//     }
//     return ans;
//}
//long long pow1(long long a,long long b)//aµÄb´Î·½ 
//{
//	
//	long long ans=1,base=a;
//	while(b!=0)
//	{
//		if(b&1!=0)
//			ans=ans*base;
//		base=base*base;
//		b=b>>1;
//	}
//	return ans;
//}
//long long f(long long n, long long m) 
//{
//        if (m > n)
//            return 1;
//        if (n == m || m == 0)
//            return 1;
//        if (m > n - m)
//            m = n - m;
//        long tmpi = 1, tmpn = 1, s1 = 1, s2 = 1, ans = 1;
//        for (int i = 1; i <= m; i++) {
//            tmpi = i;
//            tmpn = n - i + 1;
//            s1 = s1 * tmpi % 999101;
//            s2 = s2 * tmpn % 999101;
//        }
//        ans = s2 * pow1(s1, 999099) % 999101;
//        return ans % 999101;
//}
//int main()
//{
//	ll n,m,k;
//	
//}
//
//    public static void main(String[] args) {
//        Scanner sc = new Scanner(System.in);
//        BigInteger n = new BigInteger(sc.nextLine());
//        BigInteger m = new BigInteger(sc.nextLine());
//        int k = Integer.parseInt(sc.nextLine());
//        BigInteger md = new BigInteger("999101");
//        long Cnm = lucas(n, m, md).longValue() % 999101;
//        long sum = 0;
//        if (Cnm != 0) {
//            int[][] a = new int[k][k];
//            int h = 1;
//            for (int i = 0; i < k; i++) {
//                for (int j = 0; j < k; j++) {
//                    if (j >= h)
//                        a[i][j] = 0;
//                    else {
//                        if (j == 0 || j == h - 1)
//                            a[i][j] = 1;
//                        else {
//                            a[i][j] = (a[i - 1][j - 1] * (h - j) + a[i - 1][j]) % 999101;
//                        }
//                    }
//                }
//                h++;
//            }
//            long m1 = 1, n1 = 1;
//            long x = n.subtract(new BigInteger(k + ""))
//                    .mod(md.subtract(BigInteger.ONE)).longValue();
//            long n3 = pow1(2, x);
//            for (int i = k - 1; i >= 0; i--) {
//                n1 = n3 * pow1(2, i) % 999101;
//                m1 = m1
//                        * (n.subtract(new BigInteger((k - 1 - i) + "")).mod(md)
//                                .longValue()) % 999101;
//                sum = (sum + m1 * a[k - 1][i] * n1) % 999101;
//            }
//            sum = sum * Cnm % 999101;
//        }
//        System.out.println(sum);
//    }
//
//}

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int sum=0;
	for(int i=3;i<1000;i++)
	{
		if(i%3==0||i%5==0)
			sum+=sum;
	}
	cout<<sum<<endl;
	return 0;
}
