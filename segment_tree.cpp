const int N = 2*1e5+1;
int tree[4*N];

void build(int arr[],int v, int left, int right){
        if(left==right){
                tree[v]=arr[left];
                return;
        }else{
                int mid = (left+right)/2;
                build(arr,2*v,left,mid);
                build(arr,2*v+1,mid+1,right);
                tree[v]=min(tree[2*v],tree[2*v+1]);
        }
        
}

int query(int v,int left,int right,int ql,int qr){
        
        //Query range is completely outside
        if(qr<left || ql>right){
                return INT_MAX;
        }

        //Query range is withing range
        if(ql <= left && qr >= right){
                return tree[v];
        }

        int mid = (left+right)/2;

        int p1 = query(2*v,left,mid,ql,qr);
        int q1 = query(2*v+1,mid+1,right,ql,qr);

        return min(p1,q1);
}

void update(int v, int left, int right, int pos, int new_val){
        if(left==right){
                tree[v]=new_val;
        }else{
                int mid = (left+right)/2;
                if(pos <= mid){
                        update(2*v,left,mid,pos,new_val);
                }else{
                        update(2*v+1,mid+1,right,pos,new_val);
                }
                tree[v]=min(tree[2*v],tree[2*v+1]);

        }
}

