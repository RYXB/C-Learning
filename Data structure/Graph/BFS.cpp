#include<iostream>
#include<queue>

using namespace std;
/*һЩ���Ķ���*/
queue<char> q;				//����һ�����У�ʹ�ÿ⺯��queue
#define	                    //��ʾ��󶥵����
bool visited[MVNum];		//����һ��visited���飬��¼�ѱ����ʵĶ���

/*�ڽӾ���洢��ʾ*/
typedef struct AMGraph
{
	char vexs[MVNum];            //�����
	int arcs[MVNum][MVNum];      //�ڽӾ���
	int vexnum, arcnum;          //��ǰ�Ķ������ͱ���
}AMGraph;

