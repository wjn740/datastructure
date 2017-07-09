#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTEX_NUM 20
typedef int InfoType;
typedef char VertexType;

struct ArcNode
 {
   int adjvex; // 该弧所指向的顶点的位置
   struct ArcNode *nextarc; // 指向下一条弧的指针
   InfoType *info; // 网的权值指针
 }; // 表结点

 typedef struct
 {
   VertexType data; // 顶点信息
   struct ArcNode *firstarc; // 第一个表结点的地址,指向第一条依附该顶点的弧的指针
 }VNode,AdjList[MAX_VERTEX_NUM]; // 头结点

 struct ALGraph
 {
   AdjList vertices;
   int vexnum,arcnum; // 图的当前顶点数和弧数
   int kind; // 图的种类标志
 };
int LocateVex(struct ALGraph *__G, char name)
{
	int i;
	for (i=0;i<__G->vexnum;i++) {
		if(__G->vertices[i].data == name) {
			return i;
		}
	}
	return -1;
}

void CreateALGraph(struct ALGraph *_G)
{
	int i,j;
	VertexType data;
	char va,vb;
	struct ArcNode *p;
	int k;
	InfoType w;
	printf("请输入图的类型：(有向图0,有向网1，无向图2，无向网3)");
	scanf("%d",&_G->kind);
	_G->kind%=4;
	printf("请输入顶点的数量，边的数量：");
	scanf("%d,%d",&_G->vexnum,&_G->arcnum);
	_G->vexnum%=20;
	
	getchar();
	for (i=0;i<_G->vexnum;i++)	{
		printf("please type the name of cities:");
		scanf("%c",&data);
		_G->vertices[i].data = data;
		_G->vertices[i].firstarc = NULL;
	}

	for(k=0;k<_G->arcnum;k++) {
		printf("请输入<权重，a点，b点>：");
		scanf("%d,%c,%c",&w,&va,&vb);
		i=LocateVex(_G,va);
		j=LocateVex(_G,vb);
		if (i==-1||j==-1) {
			printf("no that city\n");
			k--;
			continue;
		}
		p=(struct ArcNode*)malloc(sizeof(struct ArcNode));
		p->adjvex=j;
		p->info=(int *)malloc(sizeof(int));
		*(p->info) = w;
		p->nextarc=_G->vertices[i].firstarc;
		_G->vertices[i].firstarc = p;
		
	}
}

void show(struct ALGraph *_G)
{
	int i;
	struct ArcNode *p;
	for (i=0;i<_G->vexnum;i++) {	
		printf("_G->vertices[%d].data:%c",i,_G->vertices[i].data);
		if (_G->vertices[i].firstarc) {
			printf("---->");
			p=_G->vertices[i].firstarc;
			while(p) {
				printf("adjvex:%d,info:%d,next-->",p->adjvex,*(p->info));
				p=p->nextarc;
			}
			printf("NULL\n");
		}
	}
}
int main(int argc,char **argv)
{
	struct ALGraph G;
	CreateALGraph(&G);
	printf("\n======================================================\n");
	show(&G);
	return 0;
}
