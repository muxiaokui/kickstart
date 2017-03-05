/*author: JerryYan
  data:0305
  from:google kickstart 0305A
  comment:首先是推公式，然后再推个公式。
  求n*m的网格中有多少正方形，正方形可以是斜着的。
  先推一个sum(k=1,2...m-1  ,k*(n-k)*(m-k));
  再展开合并就出来了，顺便记着点平方和公式n*(n+1)*(2n+1)/6
  立方和(n*(n+1)/2)^2
  然后小数据过了，大数据跪了，查了好久想起来没做逆元，顺手复习了下逆元
  逆元就是b*b1 = 1 mod M;b1就是b的逆元啦。
  用法是a/b = ? mod M的时候，由于a太大要取模，不能直接算，所以必须化除为乘法
 然后算的时候用费马小定理证明的b^M-1 =1 mod M 然后搞搞就好了，不过现在基本用扩展欧几里得算

 还有注意运算顺序，没必要加那么多（），* /%优先级一样的
 */ 

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

long long mo;


using namespace std;

void  Euild(long long  a, long long  b,long long &x,long long &y)  // x 是 a 关于 b 的乘法逆元 (a是除数，b是mod)
{
    if(0 == b){
        x = 1, y = 0;
        return ;
    }
    Euild(b, a%b, x, y);
    long long  flag = x;
    x = y;
    y = flag - a/b * y;
}

int main(){
	freopen("A-large-practice.in","r",stdin);
	freopen("aso","w",stdout);
	int T;
	cin>>T;
	long long n,m;
	long long x,y;
	mo = 1e9+7;
	Euild(2,mo,x,y);
	long long ni2 = x;
	if(ni2<0)ni2+=mo;
	Euild(6,mo,x,y);
	long long ni6 = x;


	for(int cs=1;cs<=T;cs++){
		cin>>n>>m;
		if(n<m)swap(n,m);
		long long ans=0;
		ans = n*m%mo * m%mo *(m-1)%mo*ni2%mo;

		ans = ans- ( (m-1)*(2*m-1)%mo * ((n+m)*m%mo) %mo)*ni6%mo;

		ans = ans+  ((m-1)*m%mo*ni2%mo*(m-1)%mo*m%mo*ni2%mo);
		ans = ans%mo;
		if(ans<0)ans+=mo;
		cout<<"Case #"<<cs<<": "<<ans<<endl;

	}


	return 0;
}
