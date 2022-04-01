#include <iostream>
using namespace std;

void print(int a[],int n,int i){
    cout<<"��"<<i+1<<"�ˣ�";
    for(int j=0;j<8;j++){
        cout<<a[j]<<" ";
    }
    cout<<endl;
}

/**
 * �������Сindex
 *
 * @return i �����index
 */
int SelectMinKey(int a[],int n,int i){
    int k = i;
    for(int j=i+1;j<n;++j){
        if(a[j]<a[k]){
            k = j;
        }
    }
    return k;
}

/**
 * ��ѡ������
 *
 */
void SimpleSelectSort(int a[],int n){
    int key,temp;
    for(int i=0;i<n;++i){
        key = SelectMinKey(a,n,i); //ѡȡ��СԪ�ص�index
        if(key != i){//������swap�㷨
            temp = a[i];
            a[i] = a[key];
            a[key] = temp;
        }
        print(a,n,i);
    }
}

int main(){
    int a[8] = {3,1,5,7,2,4,9,6};
    cout<<"��ʼֵ��";
    for(int j=0;j<8;++j){
        cout<<a[j]<<" ";
    }
    cout<<endl<<endl;
    SimpleSelectSort(a,8);
    print(a,8,8);
}
