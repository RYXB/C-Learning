#include<iostream>
using namespace std;

/*��ͳð��������ÿһ���������ֻ���ҵ�һ�����ֵ����Сֵ
���ǿ���������ÿ�������н�������ͷ�������ð�ݵķ���һ�ο��Եõ���������ֵ(����ߺ���С��)
�Ӷ�ʹ������������������һ�롣*/

void print(int a[],int n,int i){
    cout<<"��"<<i+1<<"�ˣ�";
    for(int j=0;j<n;j++){
        cout<<a[j]<<" ";
    }
    cout<<endl;
}

void BubbleSortTwoNeedle(int a[],int n){
    int low = 0;
    int high = n-1;
    int temp,j;
    while(low < high){
        for (j=low;j<high;++j){//����ð��,�ҵ������
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
         --high;//�޸�highֵ, ǰ��һλ
        for(j=high;j>low;--j){//����ð��,�ҵ���С��
            if(a[j]<a[j-1]){
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
            }
        }
        ++low;//�޸�lowֵ,����һλ
        print(a,n,j);
    }
}

int main(){
    int a[8] = {49,38,65,97,76,13,27,49};
    cout<<"��ʼֵ��";
    for(int j=0;j<8;++j){
        cout<<a[j]<<" ";
    }
    cout<<endl<<endl;
    BubbleSortTwoNeedle(a,8);
}
