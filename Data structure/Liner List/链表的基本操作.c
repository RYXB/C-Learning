#include <stdio.h>
#include <stdlib.h>

//�����ڵ�ṹ
typedef struct Link {
    int elem; //�洢����Ԫ��
    struct Link *next;//ָ��ֱ�Ӻ��Ԫ�ص�ָ��
}link;

//����������ʹ�õĺ���
link *initLink();
//�������ĺ�����p������elem�ǲ���Ľ���������add�ǲ����λ��
link *insertElem(link * p, int elem, int add);
//ɾ�����ĺ�����p�����������add����ɾ���ڵ��λ��
link *delElem(link * p, int add);
//���ҽ��ĺ�����elemΪĿ������������ֵ
int selectElem(link * p, int elem);
//���½��ĺ�����newElemΪ�µ��������ֵ
link *replaceElem(link * p, int add, int newElem);
void display(link *p);

int main(){
    link *p =NULL;
    int address;
    //��ʼ������1��2��3��4��
    printf("��ʼ������Ϊ��\n");
    p = initLink();
    display(p);

    //�ڵ�4��λ�ò���Ԫ��5����1��2��3��5, 4��
    printf("�ڵ�4��λ�ò���Ԫ��5��\n");
    p = insertElem(p, 5, 4);
    display(p);

    //ɾ��Ԫ��3:��1��2��5, 4��
    printf("ɾ��Ԫ��3:\n");
    p = delElem(p, 3);
    display(p);

    //Ԫ��2��λ��Ϊ��2
    printf("����Ԫ��2��λ��Ϊ��\n");
    address = selectElem(p, 2);
    if (address == -1) {
        printf("û�и�Ԫ��");
    }
    else {
        printf("Ԫ��2��λ��Ϊ��%d\n", address);
    }

    //���ĵ�3��λ���ϵ�����Ϊ7:��1��2��7, 4��
    printf("���ĵ�3��λ���ϵ�����Ϊ7:\n");
    p = replaceElem(p, 3, 7);
    display(p);

    return 0;
}


//��������ĺ���
link *initLink(){
    link *p = (link*)malloc(sizeof(link));//����һ��ͷ���
    link *temp = p;//����һ��ָ��ָ��ͷ��㣬���ڱ�������(�����Ϊͷ���)
    int i  = 0;
    //��������
    for(i =1 ;i<5;i++){
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

//pΪԭ����elem��ʾ������Ԫ�أ�add��ʾ��Ԫ��Ҫ�����λ��
link *insertElem(link *p, int elem, int add) {
    link *temp = p;//������ʱ���temp
    link *c = NULL;
    int i = 0;
    //�����ҵ�Ҫ����λ�õ���һ�����
    for (i = 1;i< add ;i++){
        if(temp==NULL){
            printf("����λ����Ч\n");
            return p;
        }
        temp = temp->next;
    }
    //����������c
    c = (link*)malloc(sizeof(link));
    c->elem = elem;
    c->next = temp->next;
    temp->next = c;

    return p;
}

//pΪԭ����addΪҪɾ��Ԫ�ص�ֵ
link *delElem(link *p,int add){
    link *temp = p;
    link *del = NULL;
    int i = 0;
    for(i=1;i<add;i++){
        temp = temp->next;
    }
    del = temp->next;//��������һ��ָ��ָ��ɾ����㣬�Է���ʧ
    temp->next = temp->next->next;//ɾ��ĳ�����ķ������Ǹ���ǰһ������ָ����
    free(del);//�ֶ��ͷŸý�㣬��ֹ�ڴ�й©
    return p;
}

//pΪԭ����elem��ʾ������Ԫ�ء�
int selectElem(link *p,int elem){
    //�½�һ��ָ��t����ʼ��Ϊͷָ�� p
    link *t = p;
    int i = 1;
    //�½�һ��ָ��t����ʼ��Ϊͷָ�� p
    while (t->next){
        t = t->next;
        if(t->elem == elem){
            return i;
        }
        i++;
    }
    //����ִ�����˴�����ʾ����ʧ��
    return -1;
}

//���º��������У�add ��ʾ���Ľ���������е�λ�ã�newElem Ϊ�µ��������ֵ
link *replaceElem(link *p,int add,int newElem){
    int i = 0;
    link *temp = p;
    temp = temp->next;//�ڱ���֮ǰ��tempָ����Ԫ���
    //��������ɾ�����
    for(i = 1;i<add;i++){
        temp = temp->next;
    }
    temp->elem = newElem;
    return p;
}

void display(link *p){
    link *temp = p;//��tempָ������ָ��ͷ���
    //ֻҪtempָ��ָ��Ľ���next����Null����ִ�������䡣
    while(temp->next){
        temp = temp->next;//����ͷ���
        //������ÿ����㣬��ӡ�������Ӧ��ֵ
        printf("%d ", temp->elem);
    }
    printf("\n");
}


