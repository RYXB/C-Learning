#include <stdio.h>
#include <stdlib.h>

//����Ľ�㣬�����ṹ���ʾ����Ϊָ�����������
typedef struct Link{
    char elem; //����������
    struct Link *next; //����ָ����ָ��ֱ�Ӻ��Ԫ��
}link;//linkΪ�ڵ�����ÿ���ڵ㶼��һ�� link �ṹ��

//(1)����ĳ�ʼ��
//����һ���洢 {1,2,3,4} ����ͷ�ڵ������
link *initLink1(){
    int i;
    link *p = NULL;//����ͷָ��
    link *temp = (link*)malloc(sizeof(link));//������Ԫ�ڵ�
    //��Ԫ����ʼ��
    temp->elem = 1;
    temp->next = NULL;
    p = temp;//ͷָ��ָ����Ԫ�ڵ�
    //�ӵڶ����ڵ㿪ʼ����
     for (i = 2; i < 5; i++){
        //����һ���½ڵ㲢��ʼ��
        link *a = (link*)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        //��temp�ڵ����½�����a�ڵ㽨���߼���ϵ
        temp->next = a;
        //ָ��tempÿ�ζ�ָ������������һ���ڵ㣬��ʵ���� a�ڵ㣬����дtemp=aҲ��
        temp = temp->next;
     }
      //���ؽ����Ľڵ㣬ֻ����ͷָ�� p���ɣ�ͨ��ͷָ�뼴���ҵ���������
      return p;
}
void display1(link *p) {
    link *temp = p;//��tempָ������ָ��ͷ���
    //ֻҪtempָ��ָ��Ľ���next����Null����ִ�������䡣
    while (temp) {
        printf("%d ", temp->elem);
        temp = temp->next;
    }
    printf("\n");
}


//(2)����ĳ�ʼ��
//����һ���洢 {1,2,3,4} �Һ�ͷ�ڵ������
link *initLink2(){
    int i;
    link *p = (link*)malloc(sizeof(link));//����һ��ͷ���
    link *temp = p;//����һ��ָ��ָ��ͷ��㣬
    //��������
     for (i = 1; i < 5; i++){
        //����һ���½ڵ㲢��ʼ��
        link *a = (link*)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        //��temp�ڵ����½�����a�ڵ㽨���߼���ϵ
        temp->next = a;
        //ָ��tempÿ�ζ�ָ������������һ���ڵ㣬��ʵ���� a�ڵ㣬����дtemp=aҲ��
        temp = temp->next;
     }
      //���ؽ����Ľڵ㣬ֻ����ͷָ�� p���ɣ�ͨ��ͷָ�뼴���ҵ���������
      return p;
}
void display2(link *p){
    link* temp=p;//��tempָ������ָ��ͷ���
    //ֻҪtempָ��ָ��Ľ���next����Null����ִ�������䡣
    while (temp->next) {
        temp=temp->next;
        printf("%d ",temp->elem);
    }
    printf("\n");
}

int main() {
    link*p = NULL;
    //��ʼ������1��2��3��4��
    printf("��ʼ������Ϊ��\n");
    //p = initLink1();
    //display1(p);
    p = initLink2();
    display2(p);

    return 0;
}
