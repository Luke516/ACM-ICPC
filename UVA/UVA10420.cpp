/*
 * uva10420.c
 *
 *  Created on: 2014/1/24
 *      Author: LukeWu
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct country{
	char name[75];
	int num;
};

int compare(const void *a,const void *b)
{
	struct country *c=(struct country *)a,*d=(struct country *)b;
	char *aa=c->name,*bb=d->name;
	return strcmp(aa,bb);
}

int main()
{
   _Bool flag=1;
   int N,n=0,i,j;
   char str[100],s[100];
   struct country c[2001];
   scanf("%d",&N);
   //printf("N:%d",N);
   gets(s);
   for(i=0;i<N;i++){
       //scanf("%[^\n]",s);
       gets(s);
       //printf("--%s--  ",s);
       sscanf(s,"%s",str);
       //printf("~%s~\n",str);
       flag=1;
       for(j=0;j<n;j++){
           if(strcmp(c[j].name,str)==0){
               c[j].num++;
               flag=0;
           }

       }
       if(flag==1){
           strcpy(c[n].name,str);
           c[n].num=1;
           //c[n].num++;
           n++;
       }
   }
   //scanf(" %s",s);
   /*gets(s);
   printf("--%s--  ",s);
   sscanf(s,"%s",str);
   printf("~%s~\n",str);
    flag=1;
    for(j=0;j<n;j++){
        if(strcmp(c[j],str)==0){
            num[j]++;
            flag=0;
        }

    }
    if(flag==1){
        strcpy(c[n],str);
        num[n]++;
        n++;
    }
*/
   qsort(c,n,sizeof(struct country),compare);
   for(i=0;i<n;i++){
       printf("%s %d\n",c[i].name,c[i].num);
   }
   return 0;
}



