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

struct ArcNode* searchShortest(struct ALGraph *__G, char *visited, char name)
{
  int i;
  struct ArcNode *p;
  struct ArcNode *q=NULL;
  int d;
  i=LocateVex(__G, name);
  p=__G->vertices[i].firstarc;
  while(p) {
    if (visited[p->adjvex] == 0) {
      d = *(p->info);
      q=p;
    } 
    p=p->nextarc;
  }
  p=__G->vertices[i].firstarc;
  while (p) {
    if (d > *(p->info) && visited[p->adjvex] == 0) {
      d = *(p->info);
      q=p;
    } 
    p=p->nextarc;
  }
  return q;
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
	getchar();

	for(k=0;k<_G->arcnum;k++) {
		printf("请输入<权重，a点，b点>：");
		scanf("%d,%c,%c",&w,&va,&vb);
    getchar();
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
				printf("adjvex:%c,info:%d,next-->",_G->vertices[p->adjvex].data,*(p->info));
				p=p->nextarc;
			}
			printf("NULL\n");
		}
	}
}

void dijkstra(struct ALGraph *G, char *visited, char name)
{
    int i;
    int vexnum=G->vexnum;
    struct ArcNode *q;
    i=LocateVex(G, name);
#if 0
    visited[i]=1;
    vexnum--;
    printf("%c\n", G->vertices[i].data);
#endif

    while(vexnum--) {
      q=searchShortest(G, visited, name);
      if (q==NULL) {
        continue;
      }
      printf("%d\n", q->adjvex);
      visited[q->adjvex]=1;
      printf("%c:%d\n", G->vertices[q->adjvex].data, *(q->info));
      name=G->vertices[q->adjvex].data;
    }
    
}
int main(int argc,char **argv)
{
	struct ALGraph G;
  char *visited;
	CreateALGraph(&G);
	printf("\n======================================================\n");
	show(&G);

  visited=(char *)malloc(G.vexnum);
  dijkstra(&G, visited, 'p');
  free(visited);
	return 0;
}
