#include <vector>

/*�����򣬹������ѣ���ת��Ϊ�������飬ʱ�临�Ӷ�O(nlogn)���ռ临�Ӷ�O(1)*/

void heapsort(vector<int>& arr, int i, int n){//�����򣬴�Ϊ����
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

void heap_init(vector<int>& arr){//�������ѣ���ÿһ���ڵ��ֵ���������������ӽڵ��ֵ��
    int n = arr.size();
    for(int i=n/2-1;i>=0;--i)
        heapsort(arr, i, n);
}

void heap_to_asc(vector<int>& arr){//�������ʾ������ת�����������飬��������Ԫ��arr[0]�Ƶ����
    int tmp, n = arr.size();
    for(int i=n-1;i>=1;--i){
        tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        heapsort(arr, 0, i);
    }
}
