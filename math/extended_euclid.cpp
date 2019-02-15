#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vvii vector<vii>
#define vll vector<ll>
#define vpll vector<pll>
#define MOD 1000000007
#define EPS 1e-8
#define mem(x,y) memset(x,y,sizeof x)
#define INF 100000000
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define sortv(v) sort(v.begin(),v.end())
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define PI acos(-1.0)
#define FI freopen("in.txt","r",stdin)
#define FO freopen("out.txt","w",stdout)
#define debug(x) cout<<"WTH: "<<x<<endl
#define fof(i,x,y) for(int i=x;i<=(int)y;i++)
#define fob(i,x,y) for(int i=x;i>=(int)y;i--)

template<class T>
class compare{
public:
    bool operator()(pair<T,T> x,pair<T,T> y){
        if(x.second==y.second){
            return x.first<y.first;
        }
        return x.second<y.second;
    }
};

template<class T>
ostream& operator<<(ostream &os,const pair<T,T> &a){
    os<<a.ff<<" "<<a.ss;
}

template<class T> pair<T,T> operator+(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff+b.ff,a.ss+b.ss}; }
template<class T> pair<T,T> operator-(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff-b.ff,a.ss-b.ss}; }
template<class T> pair<T,T> operator*(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff*b.ff,a.ss*b.ss}; }
template<class T> pair<T,T> operator%(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff%b.ff,a.ss%b.ss}; }
template<class T,class U> pair<T,T> operator+(const pair<T,T> &a,const U &b){ return { a.ff+b,a.ss+b}; }
template<class T,class U> pair<T,T> operator*(const pair<T,T> &a,const U &b){ return { a.ff*b,a.ss*b}; }

int Set(int N,int pos) { return N=N|(1<<pos); }
int reset(int N,int pos){ return N=N&~(1<<pos);}
bool check(int N,int pos){  return (bool) (N&(1<<pos));}

///=======================================template=======================================///

///Extended Euclid
int gcd(int a,int b, int &x, int &y){
    if(b==0){
        y=0;
        x=1;
        return a;
    }

    int x1,y1;
    int d=gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return d;
}

///one solution of ax+by=c

bool find_one_solution(int a,int b,int c,int &x0,int &y0,int &g){
    g=gcd(abs(a),abs(b),x0,y0);

    if(c%g) return false;

    x0*=c/g;
    y0*=c/g;
    if(a<0) x0=-x0;
    if(b<0) y0=-y0;
    return true;
}

void shift_solution(int &x,int &y,int a,int b,int cnt){
    x+=cnt*b;
    y-=cnt*a;
}

///range: minx<=x<=maxx,miny<=y<=maxy

int find_all_solutions(int a,int b,int c,int minx,int maxx,int miny,int maxy){
    int x,y,g;
    if(!find_one_solution(a,b,c,x,y,g))
        return 0;

    a/=g,b/=g;

    int sign_a=a>0? 1:-1;
    int sign_b=b>0? 1:-1;

    shift_solution(x,y,a,b,(minx-x)/b);

    if(x<minx)
        shift_solution(x,y,a,b,sign_b);
    if(x>maxx)
        return 0;
    int lx1=x;

    shift_solution(x,y,a,b,(maxx-x)/b);

    if(x>maxx)
        shift_solution(x,y,a,b,-sign_b);
    int rx1=x;

    shift_solution(x,y,a,b,-(miny-y)/a);
    if(y<miny)
        shift_solution(x,y,a,b,-sign_a);
    if(y>maxy)
        return 0;
    int lx2=x;

    shift_solution(x,y,a,b,-(maxy-y)/a);
    if(y>maxy)
        shift_solution(x,y,a,b,sign_a);

    int rx2=x;

    if(lx2>rx2)
        swap(lx2,rx2);

    int lx=max(lx1,lx2);
    int rx=min(rx1,rx2);
    if(lx>rx) return 0;

    return (rx-lx)/abs(b) +1;

    ///solutions can be found
    ///x=lx+k*b and y from ax+by=c: iterate!
}

int main()
{
    //FI;FO;
    FASTIO;

    int a,b,c;
    while(cin>>a>>b>>c){
        int x,y,g;
        bool flag=find_one_solution(a,b,c,x,y,g);
        if(flag) cout<<x<<" "<<y<<" "<<g<<endl;
        else cout<<"No solution"<<endl;
    }

    return 0;
}
