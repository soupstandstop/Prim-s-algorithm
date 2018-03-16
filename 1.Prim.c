#include<stdio.h>
#include<stdlib.h>

#define node_range 51  
#define edge_range 201  

int edge[edge_range][3];  
int key[node_range]={0},key_save[node_range]={0},node_p[node_range]={0};

int node_num=0,edge_num=0,source=0,weight=0;  
void prim();  

int main()
{
	for(int i=0;i<node_range;i++)
	{
		key[i]=10000; //source至每點的距離，初值為無限大
		key_save[i]=-1; //所有點初始都是in union V
	}  

	scanf("%d%d",&node_num,&edge_num); //輸入真正的點數，邊數

	for(int i=1;i<=edge_num;i++)
		scanf("%d%d%d",&edge[i][0],&edge[i][1],&edge[i][2]); //輸入Vi,Vj,w(i,j)

	scanf("%d",&source);  //輸入起點

	prim(); //呼叫Prim

	printf("\n");
	for(int i=1;i<=node_num;i++) //將每一點的父點印出來
		printf("%d ",node_p[i]);
	printf("\n");  

	for(int i=1;i<=node_num;i++)
		weight += key_save[i]; //將每一點的weight加總印出來
	printf("%d\n",weight);

	system("pause");
	return 0;
}

void prim()
{
	key[source]=0;  
	node_p[source]=0;  

	int c_loop=0;  
	while(c_loop!=node_num)  
	{
		int min=1;  
		for(int i=1;i<=node_num;i++)
		{
			if(key[i]<key[min]) //run1先找source出來，
				min = i;
		}

		key_save[min]=key[min]; //run1將source丟入union U

		for(int i=1;i<=edge_num;i++)  
		{
			if(edge[i][0]==min)  
			{
				if(key_save[edge[i][1]]==-1)  //如果edge[i][1]還在union V
				{
				    if(key[edge[i][1]]>edge[i][2]) 
					{
					    key[edge[i][1]] = edge[i][2];  
						node_p[edge[i][1]]=min;  
					}
				}
			}
			if(edge[i][1]==min)  
			{
				if(key_save[edge[i][0]]==-1)  
				{
				    if(key[edge[i][0]]>edge[i][2]) 
					{
					    key[edge[i][0]] = edge[i][2]; 
						node_p[edge[i][0]]=min; 
					}
				}
			}
		}

		key[min]=10000;  
		c_loop++;  
	}
}
