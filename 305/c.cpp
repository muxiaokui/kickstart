/*author: JerryYan
  data:0306
  from:google kickstart 0305C
  comment:这个题目比赛时没做出来，只知道肯定要二分，赛后问了下突然就懂了。
  给你一个空间和一堆星球，然后问你找两个正方体把球都包起来的话，至少正方体要多大，正方体是正的，不能斜着放
  其实先转成二维就能明白，二维的话，两个体只能是左上右下或者左下右上，就是要对着放，因为对左下点而言，最难包进去的显然是右上点
  加一个维度，其实效果一样的，左右，上下，前后，一共只有4种，左上前和右下后，左上后和右下前，左下前和右上后还有左下后和右上前
  所以二分下长度，然后直接判断是否大家都在里面就好了。
  所以说，三维不会就先想二维嘛- -

  顺便看了下别人代码，学了个 ::s[0]表示全局变量的s,这个感觉很好玩啊
  */



#include <stdio.h>
#include <iostream>
const int N = 2002;
const int INF = ~0u >>2;//u是无符号整数,这里表示的是1e9左右的极限
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
