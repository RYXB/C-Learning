#include <stdio.h>
#include <stdlib.h>
//�ο���https://blog.csdn.net/m0_62436868/article/details/123174059

//�����ڵ�ṹ
typedef struct Link {
    int elem; //�洢����Ԫ��
    struct Link *next;//ָ��ֱ�Ӻ��Ԫ�ص�ָ��
}link;

//����������ʹ�õĺ���
link *initLink();
//��ʼ������
link *iteration_reverse(link *p);
//��ת
void display(link *p);
//����չʾ����

int main(){
    link *p =NULL;
    printf("��ʼ������Ϊ��\n");
    p = initLink();
    display(p);

    printf("������ת�����\n");
    p = iteration_reverse(p);
    display(p);
}
//��������ĺ�������ͷ��㣩
link *initLink(){
    int i;
    link *p = NULL;//����ͷָ��
    link *temp = (link*)malloc(sizeof(link));//������Ԫ�ڵ�
    //��Ԫ����ʼ��
    temp->elem = 1;
    temp->next = NULL;
    p = temp;//ͷָ��ָ����Ԫ�ڵ�
    //��������
    for(i =2 ;i<5;i++){
        //�����ڵ㲢��ʼ��
        link *a = (link*)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        //�����½ڵ���ֱ��ǰ���ڵ���߼���ϵ
        temp->next = a;
        temp = temp->next;
    }
    return p;
}

//������ת���� head Ϊ��ͷ�ڵ������ͷָ��
link *iteration_reverse(link *p){
    link *head = p;
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        return head;
    }
    link *beg = head;
    link *mid = head->next;
    link *end = mid->next;

    beg->next = NULL;//ͷ�巨
    //һֱ����
    while(mid!=NULL)
    {
        mid ->next= beg;
        beg = mid;
        mid = end;
        if(end !=NULL){
            end = end->next;
        }
    }
     return beg;
}

void display(link *p){
    link *temp = p;
    while(temp){
        printf("%d ", temp->elem);
        temp = temp->next;
    }
    printf("\n");
}
