//めぐる式二分探索
bool isOK(int mid){
    if(true){
        return true;
    }
    else{
        return false;
    } 
}

int binary_search(int key){

    int ng = -1, ok = INT_MAX - 1;
    while(abs(ok - ng) > 1){
        int mid = (ok + ng) / 2;

        if(isOK(mid)){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }
    return ok;
}
