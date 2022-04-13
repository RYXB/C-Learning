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
link *local_reverse(link *p);
//��ת
void display(link *p);
//����չʾ����


int main(){
    link *p =NULL;
    printf("��ʼ������Ϊ��\n");
    p = initLink();
    display(p);

    printf("������ת�����\n");
    p = local_reverse(p);
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

link *local_reverse(link *p){
    link *head = p;
    link *beg = NULL;
    link *end = NULL;

    if(head==NULL||head->next==NULL){
        return head;
    }
    beg = head;
    end = head->next;

    while(end!=NULL){
       //�� end ��������ժ��
       beg->next = end->next;
       //�� end �ƶ�������ͷ
       end->next = head;
       head = end;

       //���� end ��ָ�� ����ָ�� beg ���һ���ڵ㣬 Ϊ��ת��һ���ڵ���׼��
       end = beg->next;
    }
    return head;
}

void display(link *p){
    link *temp = p;
    while(temp){
        printf("%d ", temp->elem);
        temp = temp->next;
    }
    printf("\n");
}
