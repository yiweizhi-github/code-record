/*������������ʱ�临�Ӷ�O(nlogn)���ռ临�Ӷ�O(logn)*/
void quicksort(vector<int>& arr, int l, int r){
    if(l>=r)
        return;
    int i = l, j = r, key = arr[i];
    while(i<j){
        while(i<j&&arr[j]>key)
            j--;
        if(i<j){
            arr[i] = arr[j];
            i++;
        }
        while(i<j&&arr[i]<key)
            i++;
        if(i<j){
            arr[j] = arr[i];
            j--;
        }
    }
    arr[i] = key;
    quicksort(arr, l, i-1);
    quicksort(arr, i+1, r);
}
