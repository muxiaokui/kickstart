/*author: JerryYan
  data:0305
  from:google kickstart 0305A
  comment:�������ƹ�ʽ��Ȼ�����Ƹ���ʽ��
  ��n*m���������ж��������Σ������ο�����б�ŵġ�
  ����һ��sum(k=1,2...m-1  ,k*(n-k)*(m-k));
  ��չ���ϲ��ͳ����ˣ�˳����ŵ�ƽ���͹�ʽn*(n+1)*(2n+1)/6
  ������(n*(n+1)/2)^2
  Ȼ��С���ݹ��ˣ������ݹ��ˣ����˺þ�������û����Ԫ��˳�ָ�ϰ������Ԫ
  ��Ԫ����b*b1 = 1 mod M;b1����b����Ԫ����
  �÷���a/b = ? mod M��ʱ������a̫��Ҫȡģ������ֱ���㣬���Ա��뻯��Ϊ�˷�
 Ȼ�����ʱ���÷���С����֤����b^M-1 =1 mod M Ȼ����ͺ��ˣ��������ڻ�������չŷ�������

 ����ע������˳��û��Ҫ����ô�ࣨ����* /%���ȼ�һ����
 */ 

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

long long mo;


using namespace std;

void  Euild(long long  a, long long  b,long long &x,long long &y)  // x �� a ���� b �ĳ˷���Ԫ (a�ǳ�����b��mod)
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
