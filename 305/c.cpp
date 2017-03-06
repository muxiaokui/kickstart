/*author: JerryYan
  data:0306
  from:google kickstart 0305C
  comment:�����Ŀ����ʱû��������ֻ֪���϶�Ҫ���֣�����������ͻȻ�Ͷ��ˡ�
  ����һ���ռ��һ������Ȼ��������������������򶼰������Ļ�������������Ҫ��������������ģ�����б�ŷ�
  ��ʵ��ת�ɶ�ά�������ף���ά�Ļ���������ֻ�����������»����������ϣ�����Ҫ���ŷţ���Ϊ�����µ���ԣ����Ѱ���ȥ����Ȼ�����ϵ�
  ��һ��ά�ȣ���ʵЧ��һ���ģ����ң����£�ǰ��һ��ֻ��4�֣�����ǰ�����º����Ϻ������ǰ������ǰ�����Ϻ������º������ǰ
  ���Զ����³��ȣ�Ȼ��ֱ���ж��Ƿ��Ҷ�������ͺ��ˡ�
  ����˵����ά����������ά��- -

  ˳�㿴���±��˴��룬ѧ�˸� ::s[0]��ʾȫ�ֱ�����s,����о��ܺ��氡
  */



#include <stdio.h>
#include <iostream>
const int N = 2002;
const int INF = ~0u >>2;//u���޷�������,�����ʾ����1e9���ҵļ���
int x[N];
int y[N];
int z[N];
int r[N];
int xmin,ymin,zmin,xmax,ymax,zmax;
int n;
using namespace std;

bool check(int x1,int x2,int y1,int y2,int z1,int z2,int x3,int x4,int y3,int y4,int z3,int z4){
	for(int i=0;i<n;i++){
		bool in1 =  x1<=x[i]-r[i] && x2>=x[i]+r[i] && 	y1<=y[i]-r[i] && y2>=y[i]+r[i] && z1<=z[i]-r[i] && z2>=z[i]+r[i] ;
		bool in2 =  x3<=x[i]-r[i] && x4>=x[i]+r[i] && 	y3<=y[i]-r[i] && y4>=y[i]+r[i] && z3<=z[i]-r[i] && z4>=z[i]+r[i] ;
		if(!in1 && !in2){
			return false;
		}
	}
	return true;

}


bool test(int t){
	return check(xmin,xmin+t,ymin,ymin+t,zmin,zmin+t,xmax-t,xmax,ymax-t,ymax,zmax-t,zmax) ||
	       check(xmin,xmin+t,ymin,ymin+t,zmax-t,zmax,xmax-t,xmax,ymax-t,ymax,zmin,zmin+t) ||
	       check(xmin,xmin+t,ymax-t,ymax,zmin,zmin+t,xmax-t,xmax,ymin,ymin+t,zmax-t,zmax) ||
	       check(xmin,xmin+t,ymax-t,ymax,zmax-t,zmax,xmax-t,xmax,ymin,ymin+t,zmin,zmin+t) ;


}

int main()
{
	freopen("C-large-practice.in","r",stdin);
	freopen("clo","w",stdout);
	int T;
	scanf("%d",&T);

	for(int cs=1;cs<=T;cs++){
		xmin = ymin =zmin = INF;
		xmax = ymax= zmax = -INF;

		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d %d %d %d",&x[i],&y[i],&z[i],&r[i]);
			xmin = min(xmin,x[i]-r[i]);
			xmax = max(xmax,x[i]+r[i]);
			ymin = min(ymin,y[i]-r[i]);
			ymax = max(ymax,y[i]+r[i]);
			zmin = min(zmin,z[i]-r[i]);
			zmax = max(zmax,z[i]+r[i]);
		}


		int l=0,r=INF;
		while(l!=r){
			int t=(l+r)/2;
			if(test(t))r=t;
			else l=t+1;
		}
		printf("Case #%d: %d\n",cs,l);

	}

	return 0;
}
