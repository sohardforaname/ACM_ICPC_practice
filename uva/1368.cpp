#include<stdio.h>    
#include<string.h>    
int m, n;    
int main() 
{    
	int t;  scanf("%d", &t);    
	while(t--)
	{    
		int A, T, G, C;    
		int max, cnt,i,j;    
		char RNA[1005];    //新数组。    
		char DNA[55][1005];    
		scanf("%d%d", &m, &n);    
		for(i = 0; i < m; i++)    
			scanf("%s", DNA[i]);      
		for(i = 0; i < n; i++) {    
			A=C=G=T=max=0;    
			for(j = 0; j < m; j++) 
			{           
				if(DNA[j][i] == 'A')    
					A++;    
				if(DNA[j][i] == 'T')    
					T++;    
				if(DNA[j][i] == 'G')    
					G++;    
				if(DNA[j][i] == 'C')    
					C++;    
			}    
			if(A > max) 
			{              //为新数组纵向赋值。    
				max = A;    
				RNA[i] = 'A';    
			}    
			if(C > max) 
			{    
				max = C;    
				RNA[i] = 'C';    
			}    
			if(G > max) 
			{    
				max = G;    
				RNA[i] = 'G';    
			}    
			if(T > max) 
			{    
				max = T;    
				RNA[i] = 'T';    
			}    
		}    
		RNA[n] = '\0';            //数组以'\0'结尾。    
		cnt = 0;    
		for(i = 0; i < n; i++)    
			for(j = 0; j < m; j++)    
				if(RNA[i] != DNA[j][i])    
					cnt++;                    //比较新DNA与原来的不同。    
		puts(RNA);    
		printf("%d\n", cnt);    
	}    
	return 0;    
}   
