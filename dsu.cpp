const int N = 2e5+9;
int n;
std::vector<int> parent(3*N);
std::vector<int> s(3*N);


void make_set(int v){ //to make new node
        parent[v]=v;
        s[v]=1;
}

int find_set(int v){ // to find parent
        if(parent[v]==v){
                return v;
        }
        return parent[v] = find_set(parent[v]); //path compression
}       

void union_set(int a, int b){ // to unite sets/nodes
        a=find_set(a);
        b=find_set(b);

        if(a!=b){
                if(s[a] < s[b]){ //by this a become bigger then we merge smaller b in bigger a
                        swap(a,b);
                }
                parent[b]=a;
                s[a] += s[b]; //union by size
        }
}
