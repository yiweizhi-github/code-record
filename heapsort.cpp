#include <vector>

/*堆排序，构建最大堆，并转化为升序数组，时间复杂度O(nlogn)，空间复杂度O(1)*/

void heapsort(vector<int>& arr, int i, int n){//堆排序，此为最大堆
    int tmp, j = 2*i+1;
    while(j<n){
        if(j+1<n&&arr[j]<arr[j+1])
            j++;
        if(arr[i]>arr[j])
            return;
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
        i = j;
        j = 2*i+1;
    }
}

void heap_init(vector<int>& arr){//构建最大堆（即每一个节点的值都大于它的所有子节点的值）
    int n = arr.size();
    for(int i=n/2-1;i>=0;--i)
        heapsort(arr, i, n);
}

void heap_to_asc(vector<int>& arr){//把数组表示的最大堆转化成升序数组，即把最大的元素arr[0]移到最后
    int tmp, n = arr.size();
    for(int i=n-1;i>=1;--i){
        tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        heapsort(arr, 0, i);
    }
}
