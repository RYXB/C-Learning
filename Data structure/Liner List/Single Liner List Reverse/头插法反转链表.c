#include <stdio.h>
#include <stdlib.h>

//�����ڵ�ṹ
typedef struct Link {
    int elem; //�洢����Ԫ��
    struct Link *next;//ָ��ֱ�Ӻ��Ԫ�ص�ָ��
}link;

//����������ʹ�õĺ���
link *initLink();
//��ʼ������
link *head_reverse(link *p);
//��ת
void display(link *p);
//����չʾ����

int main(){
    link *p =NULL;
    printf("��ʼ������Ϊ��\n");
    p = initLink();
    display(p);

    printf("������ת�����\n");
    p = head_reverse(p);
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

link *head_reverse(link *p){
    link *head = p;
    link *new_head = NULL;
    link *temp = NULL;

    if(head == NULL || head->next == NULL){
        return head;
    }

    while(head!=NULL){
        temp = head;
        //�� temp �� head ��ժ��
        head = head->next;
        //�� temp ���뵽 new_head ��ͷ��
        temp->next = new_head;
        new_head = temp;
    }
    return new_head;
}

void display(link *p){
    link *temp = p;
    while(temp){
        printf("%d ", temp->elem);
        temp = temp->next;
    }
    printf("\n");
}
