#include <stdio.h>
#include <stdlib.h> //malloc()��exit()
#define Size 5 //��Size���к궨�壬��ʾ˳�������ռ�Ĵ�С

typedef struct Table{
    int * head;//������һ����Ϊhead�ĳ��Ȳ�ȷ�������飬Ҳ�С���̬���顱
    int length;//��¼��ǰ˳���ĳ���
    int size;//��¼˳������Ĵ洢����
}table;

table initTable(){
    table t;
    t.head = (int*)malloc(Size*sizeof(int));//����һ���յ�˳�����̬����洢�ռ�
    if(!t.head) //�������ʧ�ܣ�������ʾ��ֱ���˳�����
    {
        printf("��ʼ��ʧ��");
        exit(0);
    }
    t.length = 0;//�ձ�ĳ��ȳ�ʼ��Ϊ0
    t.size = Size; //�ձ�ĳ�ʼ�洢�ռ�ΪSize
    return t;
}

//���뺯�������У�elemΪ�����Ԫ�أ�addΪ���뵽˳����λ��
table addTable(table t,int elem,int add)
{
    int i;
    //�жϲ��뱾���Ƿ�������⣨�������Ԫ��λ�ñ����ű�ĳ���+1���������ȣ���β����������
    //���߲����λ�ñ������ڣ�������Ϊ��ʾ���Զ��˳���
    if(add > t.length+1||add<1){
        printf("����λ��������");
        return t;
    }
    //���������ʱ��������Ҫ��˳����Ƿ��ж���Ĵ洢�ռ��ṩ�������Ԫ�أ����û�У���Ҫ����
    if(t.length >= t.size){
        t.head = (int *)realloc(t.head,(t.size+1)*sizeof(int));
        if(!t.head){
            printf("�洢����ʧ��");
        }
        t.size +=1;
    }
    //�����������Ҫ���Ӳ���λ�ÿ�ʼ�ĺ���Ԫ�أ��������
    for(i=t.length-1;i>=add -1;i--){
        t.head[i+1] = t.head[i];
    }
    //������ɺ�ֱ�ӽ��������Ԫ�أ���ӵ�˳������Ӧλ��
    t.head[add-1] = elem;
    //���������Ԫ�أ����Գ���+1
    t.length++;
    return t;
}

table delTable(table t,int add){
    int i;
    if(add > t.length|| add<1){
        printf("��ɾ��Ԫ�ص�λ������");
        exit(0);
    }
    //��ɾ��Ŀ��Ԫ�غ�������Ԫ����ǰ�ƶ�1��λ��
    for(i=add;i<t.length;i++){
        t.head[i-1] = t.head[i];
    }
    t.length--;
    return t;
}

//���Һ��������У�elem��ʾҪ���ҵ�����Ԫ�ص�ֵ
//��ǰ���õ�˳�����
int selectTable(table t,int elem){
    int i;
    for(i=0;i<t.length-1;i++){
        if(t.head[i] == elem){
            return i+1;
        }
    }
    return -1;//�������ʧ�ܣ�����-1
}

//���ĺ��������У�elemΪҪ���ĵ�Ԫ�أ�newElemΪ�µ�����Ԫ��
//1.�ҵ�Ŀ��Ԫ�أ�
//2.ֱ���޸ĸ�Ԫ�ص�ֵ
table repalceTable(table t,int elem,int newElem){
    int add = selectTable(t,elem);
    t.head[add - 1] = newElem;//���ڷ��ص���Ԫ����˳����е�λ�ã�����-1���Ǹ�Ԫ���������е��±�
    return t;
}

//����չʾ���Ա�
void displayTable(table t){
    int i;
    for(i=0;i<t.length;i++){
        printf("%d ", t.head[i]);
    }
    printf("\n");
}

int main(){
    int i,add;
    //��ʼ����
    table t1 = initTable();
    //[1,size]�����Ԫ��
    for(i=1;i<Size;i++){
        t1.head[i-1] = i;
        t1.length++;
    }

    printf("ԭ˳���\n");
    displayTable(t1);
    //1 2 3 4 5

    printf("ɾ��Ԫ��1:\n");
    t1 = delTable(t1, 1);
    displayTable(t1);
    //2 3 4 5

    printf("�ڵ�2��λ�ò���Ԫ��5:\n");
    t1 = addTable(t1, 5, 2);
    displayTable(t1);
    //2 5 3 4 5

    printf("����Ԫ��3��λ��:\n");
    add = selectTable(t1, 3);
    printf("%d\n", add);
    //3

    printf("��Ԫ��3��Ϊ6:\n");
    t1 = repalceTable(t1, 3, 6);
    displayTable(t1);
    return 0;
    //2 5 6 4 5
}
