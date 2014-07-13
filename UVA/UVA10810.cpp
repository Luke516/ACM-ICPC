#include<stdio.h>

int ans;

void Combine(int l,int mid,int r,int ary[],int buf[])
{
  int i,j,cnt,ni,nj;

  i=l,j=mid+1,cnt=0,ni=j-i,nj=r-mid;
  while(i<=mid&&j<=r){
    if(ary[j]<ary[i]){
        buf[cnt++]=ary[j++];
        ans=ans+ni;
    } 
    else{
        buf[cnt++]=ary[i++];
        ni--;
    }
  }
  while(i<=mid){
      buf[cnt++]=ary[i++];
  }
  while(j<=r){
      buf[cnt++]=ary[j++];
  } 

  for(i=l;i<=r;i++){
      ary[i]=buf[i-l];
  }
}


void MergeSort(int l,int r,int ary[],int buf[])
{

  if(l==r) return;

 
  int mid=(l+r)/2;
  MergeSort(l,mid,ary,buf);
  MergeSort(mid+1,r,ary,buf);
  Combine(l,mid,r,ary,buf);
}

int main(void)
{
  int i,n,ary[500000],buf[500000];
  while(scanf("%d",&n)!=EOF){
      if(n!=0){
      for(i=0;i<n;i++){
          scanf("%d",&ary[i]);
      }
      MergeSort(0,n-1,ary,buf);
      for(i=0;i<n;i++){
      }
      printf("%d\n",ans);
      ans=0;}
  }
  return 0;
  
}