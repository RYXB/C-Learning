#include<iostream>
using namespace std;

/*����˼�룺

1��ѡ��һ����׼Ԫ��,ͨ��ѡ���һ��Ԫ�ػ������һ��Ԫ��,

2��ͨ��һ�����򽲴�����ļ�¼�ָ�ɶ����������֣�����һ���ּ�¼��Ԫ��ֵ���Ȼ�׼Ԫ��ֵС����һ���ּ�¼�� Ԫ��ֵ�Ȼ�׼ֵ��

3����ʱ��׼Ԫ�������ź�������ȷλ��

4��Ȼ��ֱ���������ּ�¼��ͬ���ķ���������������ֱ��������������*/

void print(int a[],int n){
    for(int j=0;j<n;j++){
        cout<<a[j]<<" ";
    }
    cout<<endl;
}

int partition(int a[],int low, int high){
    int pivotKey = a[low];//��׼Ԫ��

    while (low < high){//�ӱ�����˽�������м�ɨ��
        while(low < high && a[high] >= pivotKey){
            --high;//��high ��ָλ����ǰ���������ൽlow+1 λ�á����Ȼ�׼Ԫ��С�Ľ������Ͷ�
        }
        a[low] = a[high];
        while(low < high && a[low] <=pivotKey){
            ++low;
        }
        a[high] =a[low];
    }
    a[low] = pivotKey;
    print(a,10);
    return low;
}


void QuickSort(int a[],int low,int high){
    if(low < high){
        int privotLoc = partition(a,low,high);//����һ��Ϊ��
        QuickSort(a,low,privotLoc - 1);//�ݹ�Ե��ӱ�ݹ�����
        QuickSort(a,privotLoc+1,high);//�ݹ�Ե��ӱ�ݹ�����
    }
}

int main(){
    int a[10] = {3,1,5,7,2,4,9,6,10,8};
    cout<<"��ʼֵ��";
    print(a,10);
    QuickSort(a,0,9);
    cout<<"�����";
    print(a,10);
}
