
// 1 based indexing

struct DSU{
    vll p;
    ll n , connected;
    vll sz;
 
    void init(ll n){
        p.resize(n+1);
        iota(p.begin(), p.end(), 0);
        sz.assign(n+1, 1);
        connected = n;
    }
 
    ll get(ll x) {
        if(x == p[x]){
            return x;
        }
        return p[x]=get(p[x]);
    }
 
    ll getsz(ll u)
	{
		return sz[get(u)];
	}
 
    bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if(x == y) return false;
 
        connected--; 
 
        if(sz[x] > sz[y])
			swap(x, y);
 
		sz[y] += sz[x];
		sz[x] = 0;
		p[x] = p[y];
        return true;
    }
};
