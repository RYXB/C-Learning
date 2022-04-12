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
link *recursive_reverse(link *p);
//��ת
void display(link *p);
//����չʾ����

int main(){
    link *p =NULL;
    printf("��ʼ������Ϊ��\n");
    p = initLink();
    display(p);

    printf("������ת�����\n");
    p = recursive_reverse(p);
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

link *recursive_reverse(link *p){
    link *head = p;
    //�ݹ�ĳ���
    if (head == NULL || head->next == NULL) // ������ֻ��һ����㣬 ֱ�ӷ���ͷָ��
    {
        return head;
    }else{
        //һֱ�ݹ飬 �ҵ����������һ���ڵ�
        link *new_head = recursive_reverse(head->next);
        //������˳�ʱ�� new_head ��ָ�򶼲��䣬 һֱָ��ԭ���������һ���ڵ㣻
        //�ݹ�ÿ�˳�һ�㣬 ������ head ָ���ָ�򶼻ᷢ���ı䣬 ��ָ����һ���ڵ㡣
        //ÿ�˳�һ�㣬 ����Ҫ�ı� head->next �ڵ�ָ�����ָ�� ͬʱ�� head ��ָ�ڵ��ָ����Ϊ NULL��
        head->next->next=head;
        head->next = NULL;
        //ÿһ��ݹ������ ��Ҫ���µ�ͷָ�뷵�ظ���һ�㡣 �ɴˣ� ���ɱ�֤�����ݹ�����У� �ܹ�һֱ�ҵõ�������ı�ͷ��
        return new_head;
    }
}



void display(link *p){
    link *temp = p;
    while(temp){
        printf("%d ", temp->elem);
        temp = temp->next;
    }
    printf("\n");
}
