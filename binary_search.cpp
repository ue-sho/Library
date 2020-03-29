//めぐる式二分探索
bool isOK(int index, int key) {
    if (a[index] >= key) return true;
    else return false;
}

int binary_search(int key){

    ll ng = -1, ok = LLONG_MAX-1;
    while(abs(ok - ng) > 1){
        ll mid = (ok + ng) / 2;

        if(isOK(mid, key)){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }
    return ok;
}
