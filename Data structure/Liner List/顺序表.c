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
