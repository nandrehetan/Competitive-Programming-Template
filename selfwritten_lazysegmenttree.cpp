struct node{
        int lazy;
        int sum;
        node(){
                lazy=0;
                sum=0;
        }
};

node merge(node a,node b){
        node ans;
        ans.sum=a.sum+b.sum;
        return ans;
}

node st[4*200200];
int arr[200200];

void push(int ind,int l,int r){
        if(st[ind].lazy != 0){
                //If there is laze , apply and push down

                //Apply logic
                st[ind].sum += (r-l+1)*st[ind].lazy;

                //Push-down logic if not leaf
                if(l!=r){
                        st[2*ind] += st[ind].lazy;
                        st[2*ind+1] += st[ind].lazy;
                }
        }

        //clear the lazy
        st[ind].lazy=0;
}

void build(int ind,int l,int r){
        if(l==r){
                st[ind].sum=arr[l];
                st[ind].lazy=0;
                return;
        }
        int mid=(l+r)/2;
        build(2*ind,l,mid);
        build(2*ind+1,mid+1,r);
        st[ind]=merge(st[2*ind] + st[2*ind+1]);
}

void update(int ind,int l,int r,int ql,int qr,int val){

        push(ind,l,r);

        if(l>rq || lq>r){
                return;
        }

        if(lq<=l && r<=rq){
                st[ind].lazy += val;
                push(ind,l,r);
                return;
        }

        int mid=(l+r)/2;
        update(2*ind,l,mid,ql,qr,val);
        update(2*ind+1,mid+1,rql,qr,val);
        st[ind]=merge(st[2*ind],st[2*ind+1]);
}

node query(int ind,int l,int r,int ql,int qr){

        if(l>rq || lq>r){
                return node();
        }

        if(lq<=l && r<=rq){
                return st[ind].sum;
        }

        int mid=(l+r)/2;
        return merge(query(2*ind,l,mid,ql,qr),query(2*ind+1,mid+1,ql,qr));
}
