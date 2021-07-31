#include<bits/stdc++.h>
using namespace std;
int n,q,c,x,y,i,cnt=0;
vector<int> L,in,out,BIT,V;
vector<long long> arr;
vector<int>G[100000];


void update(int idx,int val){

	while(idx<=n){
		BIT[idx]+=val;
		idx+=(idx&(-idx));
	}
}

int query(int idx){
	int sum=0;
	while(idx>0){
		sum+=BIT[idx];
		idx-=(idx&(-idx));
	}
	return sum;
}

void dfs(int u,int lev=0){

	L[u]=lev;
	V[u]=true;
	in[u]=++cnt;
	for(auto it=G[u].begin();it!=G[u].end();++it){
		if(!V[*it]){
			dfs(*it,lev+1);
		}
	}
	out[u]=cnt;
}


int main(){

	cin >> n >> q;

	arr.resize(n+1);
	V.resize(n+1);
	L.resize(n+1);
	in.resize(n+1);
	out.resize(n+1);
	BIT.resize(n+1);
	for(i=1;i<=n;i++)
		cin >> arr[i];
	for(i=1;i<n;i++){
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1);
	for(i=1;i<=n;i++){
		if(arr[i]==0)
			update(in[i],1);
	}
	while(q--){

        int k,x;
		cin>>k>>x;
		int ans=query(out[x]);
        ans-=query(in[x]-1);
        cout << ans<<endl;

	}
	return 0;
}
