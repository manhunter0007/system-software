#include<stdio.h>
int main()
{
int f,p,i,j,k,fault=0,avail,position,rpos;
printf("Enter the no of pages in reference string:");
scanf("%d",&p);
printf("Enter the no of frames:");
scanf("%d",&f);
int frame[f],pages[p],time[f];
printf("Enter the refernce string:");
for(i=0;i<p;i++)
{
scanf("%d",&pages[i]);
}
for(i=0;i<f;i++)
{
frame[i]=-1;
}
printf("Ref string\tframes\n");
for(i=0;i<p;i++)
{
printf("%d\t\t",pages[i]);
avail=0;
for(k=0;k<f;k++)
{
if(frame[k]==pages[i])
avail=1;
else if(frame[k]==-1 && avail!=1)
{
avail=-1;
position=k;
break;
}
}
if(avail==0)
{
for(k=0;k<f;k++)
{
for(j=i-1;j>=0;j--)
{
if(pages[j]==frame[k])
{
rpos=j;
break;
}
}
time[k]=i-rpos;
}
position=0;
for(k=1;k<f;k++)
{
if(time[k]>time[position])
position=k;
}
frame[position]=pages[i];
fault++;
for(k=0;k<f;k++)
printf("%d",frame[k]);
}
else if(avail==-1)
{
frame[position]=pages[i];
fault++;
for(k=0;k<f;k++)
printf("%d",frame[k]);
}
else
{
for(k=0;k<f;k++)
printf("%d",frame[k]);
}
printf("\n");
}
printf("Page fault:%d\nPage hit:%d\n",fault,p-fault);
}
