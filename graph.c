#include <stdio.h>

#define MAXSIZE 64
typedef char vtype;
typedef int adjtype;

typedef struct{
	vtype V[MAXSIZE];
	adjtype A[MAXSIZE][MAXSIZE];
	int count;
}mgraph;

int locate(mgraph G, vtype name)
{
	int i;
	for(i=0;i<MAXSIZE;i++) {
		if (G.V[i]==name)
			return i;
	}
	return -1;
}

int
main(int argc, char **argv)
{
	mgraph G;
	int c;
	int n=0;
	int u,v,d;
	int i,j;
	while((c=getchar())!='#' && n<MAXSIZE) {
		G.V[n++]=c;
	}
	G.count=n;
	fflush(stdout);
	//clear adjarray
	for(i=0;i<MAXSIZE;i++)
		for(j=0;j<MAXSIZE;j++)
			G.A[i][j]=-1;
	
	while(1) {
		scanf("%c,%c=%d",&u,&v,&d);
		if (u=='#'||v=='#') {
			break;
		}
		i=locate(G,u);
		j=locate(G,v);
		if (i==-1 || j==-1) {
			printf("There is no that city\n");
			continue;
		}
		G.A[i][j]=d;
	}

	for(i=0;i<G.count;i++)
		for(j=0;j<G.count;j++)
			if(j==G.count-1) {
				printf("A[%d][%d]=%d\n",i,j,G.A[i][j]);
			}else {
				printf("A[%d][%d]=%d\t",i,j,G.A[i][j]);
			}
	return 0;
}
