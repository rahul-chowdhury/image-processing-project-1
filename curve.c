#include<stdio.h>
#include<stdlib.h>
typedef struct array
{
int x,y;
char c;
int t;
}curve;
int x,y,n=0,count=1;
void right(curve a[0][n])
{
printf("i am in right function\n");

a[x+1][y].c='.';
x=x+1;
a[x][y].t=count++;printf("value of x=%d and value of y=%d\n",x,y);
}
void left(curve a[0][n])
{printf("i am in left function\n");

a[x-1][y].c='.';
x=x-1;
a[x][y].t=count++;printf("value of x=%d and value of y=%d\n",x,y);
}
void up(curve a[0][n])
{printf("i am in up function\n");
a[x][y-1].c='.';
y=y-1;
a[x][y].t=count++;printf("value of x=%d and value of y=%d\n",x,y);
}
void down(curve a[0][n])
{printf("i am in down function\n");
a[x][y+1].c='.';
y=y+1;
a[x][y].t=count++;printf("value of x=%d and value of y=%d\n",x,y);
}
char rot(curve pre,curve cur,curve nex)
{
if((cur.x-pre.x==0)&&(nex.x-cur.x==1)&&(nex.y-cur.y==0)&&(cur.y-pre.y==-1))
	return 'c';
if((cur.x-pre.x==1)&&(nex.x-cur.x==0)&&(nex.y-cur.y==1)&&(cur.y-pre.y==0))
	return 'c';
if((cur.x-pre.x==0)&&(nex.x-cur.x==-1)&&(nex.y-cur.y==0)&&(cur.y-pre.y==1))
	return 'c';
if((cur.x-pre.x==-1)&&(nex.x-cur.x==0)&&(nex.y-cur.y==-1)&&(cur.y-pre.y==0))
	return 'c';
if((cur.x-pre.x==1)&&(nex.x-cur.x==0)&&(nex.y-cur.y==-1)&&(cur.y-pre.y==0))
	return 'a';
if((cur.x-pre.x==0)&&(nex.x-cur.x==1)&&(nex.y-cur.y==0)&&(cur.y-pre.y==1))
	return 'a';
if((cur.x-pre.x==-1)&&(nex.x-cur.x==0)&&(nex.y-cur.y==1)&&(cur.y-pre.y==0))
	return 'a';
if((cur.x-pre.x==0)&&(nex.x-cur.x==-1)&&(nex.y-cur.y==0)&&(cur.y-pre.y==-1))
	return 'a';
}
int main()
{
FILE *file=fopen("graph","w");
srand(time(NULL));
int a,b,i,j,k,inia,inib;
curve pre,nex,pre1,nex1,pre2,nex2;
char pos[8];
printf("enter array dimension:");
scanf("%d",&n);
n++;
curve c[n][n];
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		c[i][j].x=i;
		c[i][j].y=j;
		if((i==0)||(j==0)||(i==n-1)||(j==n-1))
			c[i][j].c='.';
		else
			c[i][j].c=' ';
c[i][j].t=0;
	}
}
printf("enter starting address,x and y coordinates respectively,separated by a space: ");
scanf("%d %d",&x,&y);
inia=x;
inib=y;
fprintf(file,"%d,%d\n",x,y);
c[x][y].c='.';
c[x][y].t=count++;
b=rand()%4;
if(b==0)
	right(c);
if(b==1)
	left(c);
if(b==2)
	up(c);
if(b==3)
	down(c);
int f=1;
do
{
fprintf(file,"%d,%d\n",x,y);
printf("i am in do loop for %d time\n",f++);
printf("value of x=%d and value of y=%d\n",x,y);
pos[0]=c[x-1][y-1].c;
pos[1]=c[x][y-1].c;
pos[2]=c[x+1][y-1].c;
pos[3]=c[x+1][y].c;
pos[4]=c[x+1][y+1].c;
pos[5]=c[x][y+1].c;
pos[6]=c[x-1][y+1].c;
pos[7]=c[x-1][y].c;


if(count==2)
{
if((inia==x)&&(inib==y-1))
{
up(c);
continue;
}
if((inia==x)&&(inib==y+1))
{
down(c);
continue;
}if((inia==x+1)&&(inib==y))
{
right(c);
continue;
}if((inia==x-1)&&(inib==y))
{
left(c);
continue;
}
}

int block=0;
for(i=1;i<8;i=i+2)
{
	if(pos[i]=='.')
		block++;
}
if(block==4)
	{printf("i am breaking");break;}
if(c[x][y].t-c[x][y+1].t==1)//up
{


printf("i am in block up %d\n",count);
printf("value of x=%d and value of y=%d\n",x,y);

	if(block==3)
	{
		for(i=1;i<8;i=i+2)
		{
			if(pos[i]==' ')
				break;
		}
		if(i==1) {up(c);continue;}
		if(i==3) {right(c);continue;}
		if(i==7) {left(c);continue;}
	}
	if(block==2)
	{
		if(pos[3]=='.')
		{

			if(pos[0]!='.')
			{
				b=rand()%2;
				if(b==0)
				{
					left(c);
					continue;
				}
				if(b==1)
				{
					up(c);
					continue;
				}
			}
			pre=(c[x-2][y-1].t<c[x-1][y-2].t)?c[x-2][y-1]:c[x-1][y-2];
			nex=(c[x-2][y-1].t<c[x-1][y-2].t)?c[x-1][y-2]:c[x-2][y-1];

			if(rot(pre,c[x-1][y-1],nex)=='a')
			{
			left(c);
			continue;
			}
			else
			{
			up(c);
			continue;
			}


		}

		if(pos[7]=='.')
		{
			if(pos[2]!='.')
					{
						b=rand()%2;
						if(b==0)
						{
							right(c);
							continue;
						}
						if(b==1)
						{
							up(c);
							continue;
						}
					}
					pre=(c[x+1][y-2].t<c[x+2][y-1].t)?c[x+1][y-2]:c[x+2][y-1];
					nex=(c[x+1][y-2].t<c[x+2][y-1].t)?c[x+2][y-1]:c[x+1][y-2];

					if(rot(pre,c[x+1][y-1],nex)=='a')
					{
					up(c);
					continue;
					}
					else
					{
					right(c);
					continue;
					}
		}

		if(pos[1]=='.')
		{
			if(pos[2]=='.')
			{
				pre=(c[x+1][y-2].t<c[x+2][y-1].t)?c[x+1][y-2]:c[x+2][y-1];
				nex=(c[x+1][y-2].t<c[x+2][y-1].t)?c[x+2][y-1]:c[x+1][y-2];

				if(rot(pre,c[x+1][y-1],nex)=='a')
				{
				up(c);
				continue;
				}
				else
				{
				right(c);
				continue;
				}
			}
			if(pos[0]=='.')
			{
				pre=(c[x-2][y-1].t<c[x-1][y-2].t)?c[x-2][y-1]:c[x-1][y-2];
				nex=(c[x-2][y-1].t<c[x-1][y-2].t)?c[x-1][y-2]:c[x-2][y-1];

				if(rot(pre,c[x-1][y-1],nex)=='a')
				{
				left(c);
				continue;
				}
				else
				{
				up(c);
				continue;
				}
			}
		}

	}
	if(block==1)
	{
		if(pos[0]=='.' && pos[2]=='.')
		{
			if(c[x-1][y-1].t<c[x+1][y-1].t)
			{
				left(c);
				continue;

			}
			else
			{
				right(c);
				continue;
			}
		}
		else if(pos[0]=='.')
		{
			pre=(c[x-2][y-1].t<c[x-1][y-2].t)?c[x-2][y-1]:c[x-1][y-2];
			nex=(c[x-2][y-1].t<c[x-1][y-2].t)?c[x-1][y-2]:c[x-2][y-1];

			if(rot(pre,c[x-1][y-1],nex)=='a')
			{
			left(c);
			continue;
			}
			else
			{
				b=rand()%2;
				if(b==0)
				{
					up(c);
					continue;
				}
				else
				{
					right(c);
					continue;
				}
			}
		}
		else if(pos[2]=='.')
		{
				pre=(c[x+1][y-2].t<c[x+2][y-1].t)?c[x+1][y-2]:c[x+2][y-1];
				nex=(c[x+1][y-2].t<c[x+2][y-1].t)?c[x+2][y-1]:c[x+1][y-2];

				if(rot(pre,c[x+1][y-1],nex)=='a')
				{
				b=rand()%2;
					if(rand==0)
					{
					up(c);
					continue;
					}
					else
					{
					left(c);
					continue;
					}
				}
				else
				{
				right(c);
				continue;
				}
		}
		else
		{
			b=rand()%3;
			if(b==0)
			{
				right(c);
				continue;
			}
			if(b==1)
			{
				left(c);
				continue;
			}
			if(b==2)
			{
				up(c);
				continue;
			}
		}
	}
}

if(c[x][y].t-c[x-1][y].t==1)//right
{
printf("i am in block right %d\n",count);printf("value of x=%d and value of y=%d\n",x,y);

	if(block==3)
    	{
    		for(i=1;i<8;i=i+2)
    		{
    			if(pos[i]==' ')
    				break;
    		}
    		if(i==1) {up(c);continue;}
    		if(i==3) {right(c);continue;}
    		if(i==5) {down(c);continue;}
    	}
    	if(block==2)
    	{
    		if(pos[5]=='.')
    		{

    			if(pos[2]!='.')
    			{
    				b=rand()%2;
    				if(b==0)
    				{
    					left(c);
    					continue;
    				}
    				if(b==1)
    				{
    					up(c);
    					continue;
    				}
    			}
    			pre=(c[x+1][y-2].t<c[x+2][y-1].t)?c[x+1][y-2]:c[x+2][y-1];
    			nex=(c[x+1][y-2].t<c[x+2][y-1].t)?c[x+2][y-1]:c[x+1][y-2];

    			if(rot(pre,c[x+1][y-1],nex)=='a')
    			{
    			up(c);
    			continue;
    			}
    			else
    			{
    			right(c);
    			continue;
    			}


    		}

    		if(pos[1]=='.')
    		{
    			if(pos[4]!='.')
    					{
    						b=rand()%2;
    						if(b==0)
    						{
    							down(c);
    							continue;
    						}
    						if(b==1)
    						{
    							right(c);
    							continue;
    						}
    					}
    					pre=(c[x+2][y+1].t<c[x+1][y+2].t)?c[x+2][y+1]:c[x+1][y+2];
    					nex=(c[x+2][y+1].t<c[x+1][y+2].t)?c[x+1][y+2]:c[x+2][y+1];

    					if(rot(pre,c[x+1][y+1],nex)=='a')
    					{
    					right(c);
    					continue;
    					}
    					else
    					{
    					down(c);
    					continue;
    					}
    		}

    		if(pos[3]=='.')
    		{
    			if(pos[4]=='.')
    			{
    				pre=(c[x+1][y-2].t<c[x+2][y-1].t)?c[x+1][y-2]:c[x+2][y-1];
                        			nex=(c[x+1][y-2].t<c[x+2][y-1].t)?c[x+2][y-1]:c[x+1][y-2];

    				if(rot(pre,c[x+1][y+1],nex)=='a')
    				{
    				right(c);
    				continue;
    				}
    				else
    				{
    				down(c);
    				continue;
    				}
    			}
    			if(pos[2]=='.')
    			{
    				pre=(c[x+2][y+1].t<c[x+1][y+2].t)?c[x+2][y+1]:c[x+1][y+2];
                        					nex=(c[x+2][y+1].t<c[x+1][y+2].t)?c[x+1][y+2]:c[x+2][y+1];

    				if(rot(pre,c[x+1][y-1],nex)=='a')
    				{
    				up(c);
    				continue;
    				}
    				else
    				{
    				right(c);
    				continue;
    				}
    			}
    		}

    	}
    	if(block==1)
    	{
    		if(pos[2]=='.' && pos[4]=='.')
    		{
    			if(c[x+1][y-1].t<c[x+1][y+1].t)
    			{
    				up(c);
    				continue;

    			}
    			else
    			{
    				down(c);
    				continue;
    			}
    		}
    		else if(pos[2]=='.')
    		{
    			pre=(c[x+1][y-2].t<c[x+2][y-1].t)?c[x+1][y-2]:c[x+2][y-1];
    			nex=(c[x+1][y-2].t<c[x+2][y-1].t)?c[x+2][y-1]:c[x+1][y-2];

    			if(rot(pre,c[x+1][y-1],nex)=='a')
    			{
    			up(c);
    			continue;
    			}
    			else
    			{
    				b=rand()%2;
    				if(b==0)
    				{
    					right(c);
    					continue;
    				}
    				else
    				{
    					down(c);
    					continue;
    				}
    			}
    		}
    		else if(pos[4]=='.')
    		{
    				pre=(c[x+2][y+1].t<c[x+1][y+2].t)?c[x+2][y+1]:c[x+1][y+2];
    				nex=(c[x+2][y+1].t<c[x+1][y+2].t)?c[x+1][y+2]:c[x+2][y+1];

    				if(rot(pre,c[x+1][y+1],nex)=='a')
    				{
    				b=rand()%2;
    					if(rand==0)
    					{
    					right(c);
    					continue;
    					}
    					else
    					{
    					up(c);
    					continue;
    					}
    				}
    				else
    				{
    				down(c);
    				continue;
    				}
    		}
    		else
    		{
    			b=rand()%3;
    			if(b==0)
    			{
    				down(c);
    				continue;
    			}
    			if(b==1)
    			{
    				up(c);
    				continue;
    			}
    			if(b==2)
    			{
    				right(c);
    				continue;
    			}
    		}
    	}
}

if(c[x][y].t-c[x][y-1].t==1)//down
{
printf("i am in block down %d\n",count);printf("value of x=%d and value of y=%d\n",x,y);

	if(block==3)
    	{
    		for(i=1;i<8;i=i+2)
    		{
    			if(pos[i]==' ')
    				break;
    		}
    		if(i==5) {down(c);continue;}
    		if(i==3) {right(c);continue;}
    		if(i==7) {left(c);continue;}
    	}
    	if(block==2)
    	{
    		if(pos[7]=='.')
    		{

    			if(pos[4]!='.')
    			{
    				b=rand()%2;
    				if(b==0)
    				{
    					right(c);
    					continue;
    				}
    				if(b==1)
    				{
    					down(c);
    					continue;
    				}
    			}
    			pre=(c[x+2][y+1].t<c[x+1][y+2].t)?c[x+2][y+1]:c[x+1][y+2];
    			nex=(c[x+2][y+1].t<c[x+1][y+2].t)?c[x+1][y+2]:c[x+2][y+1];

    			if(rot(pre,c[x+1][y+1],nex)=='a')
    			{
    			right(c);
    			continue;
    			}
    			else
    			{
    			down(c);
    			continue;
    			}


    		}

    		if(pos[3]=='.')
    		{
    			if(pos[6]!='.')
    					{
    						b=rand()%2;
    						if(b==0)
    						{
    							left(c);
    							continue;
    						}
    						if(b==1)
    						{
    							down(c);
    							continue;
    						}
    					}
    					pre=(c[x-1][y+2].t<c[x-2][y+1].t)?c[x-1][y+2]:c[x-2][y+1];
    					nex=(c[x-1][y+2].t<c[x-2][y+1].t)?c[x-2][y+1]:c[x-1][y+2];

    					if(rot(pre,c[x-1][y+1],nex)=='a')
    					{
    					down(c);
    					continue;
    					}
    					else
    					{
    					left(c);
    					continue;
    					}
    		}

    		if(pos[5]=='.')
    		{
    			if(pos[6]=='.')
    			{
    				pre=(c[x-1][y+2].t<c[x-2][y+1].t)?c[x-1][y+2]:c[x-2][y+1];
                        					nex=(c[x-1][y+2].t<c[x-2][y+1].t)?c[x-2][y+1]:c[x-1][y+2];

    				if(rot(pre,c[x-1][y+1],nex)=='a')
    				{
    				down(c);
    				continue;
    				}
    				else
    				{
    				left(c);
    				continue;
    				}
    			}
    			if(pos[4]=='.')
    			{
    				pre=(c[x+2][y+1].t<c[x+1][y+2].t)?c[x+2][y+1]:c[x+1][y+2];
                        			nex=(c[x+2][y+1].t<c[x+1][y+2].t)?c[x+1][y+2]:c[x+2][y+1];

    				if(rot(pre,c[x+1][y+1],nex)=='a')
    				{
    				right(c);
    				continue;
    				}
    				else
    				{
    				down(c);
    				continue;
    				}
    			}
    		}

    	}
    	if(block==1)
    	{
    		if(pos[4]=='.' && pos[6]=='.')
    		{
    			if(c[x+1][y+1].t<c[x-1][y+1].t)
    			{
    				right(c);
    				continue;

    			}
    			else
    			{
    				left(c);
    				continue;
    			}
    		}
    		else if(pos[4]=='.')
    		{
    			pre=(c[x+2][y+1].t<c[x+1][y+2].t)?c[x+2][y+1]:c[x+1][y+2];
                    			nex=(c[x+2][y+1].t<c[x+1][y+2].t)?c[x+1][y+2]:c[x+2][y+1];

    			if(rot(pre,c[x+1][y+1],nex)=='a')
    			{
    			right(c);
    			continue;
    			}
    			else
    			{
    				b=rand()%2;
    				if(b==0)
    				{
    					down(c);
    					continue;
    				}
    				else
    				{
    					left(c);
    					continue;
    				}
    			}
    		}
    		else if(pos[6]=='.')
    		{
    				pre=(c[x-1][y+2].t<c[x-2][y+1].t)?c[x-1][y+2]:c[x-2][y+1];
                        					nex=(c[x-1][y+2].t<c[x-2][y+1].t)?c[x-2][y+1]:c[x-1][y+2];

    				if(rot(pre,c[x-1][y+1],nex)=='a')
    				{
    				b=rand()%2;
    					if(rand==0)
    					{
    					down(c);
    					continue;
    					}
    					else
    					{
    					right(c);
    					continue;
    					}
    				}
    				else
    				{
    				left(c);
    				continue;
    				}
    		}
    		else
    		{
    			b=rand()%3;
    			if(b==0)
    			{
    				left(c);
    				continue;
    			}
    			if(b==1)
    			{
    				right(c);
    				continue;
    			}
    			if(b==2)
    			{
    				down(c);
    				continue;
    			}
    		}
    	}
}

if(c[x][y].t-c[x+1][y].t==1)//left
{
printf("i am in block left %d\n",count);printf("value of x=%d and value of y=%d\n",x,y);
printf("pos0=%c pos1=%c pos2=%c pos3=%c pos4=%c pos5=%c pos6=%c pos7=%c bleck=%d\n",pos[0],pos[1],pos[2],pos[3],pos[4],pos[5],pos[6],pos[7],block);
	if(block==3)
        	{
        		for(i=1;i<8;i=i+2)
        		{
        			if(pos[i]==' ')
        				break;
        		}
        		if(i==1) {up(c);continue;}
        		if(i==7) {left(c);continue;}
        		if(i==5) {down(c);continue;}
        	}
        	if(block==2)
        	{
        		if(pos[1]=='.')
        		{

        			if(pos[6]!='.')
        			{
        				b=rand()%2;
        				if(b==0)
        				{
        					right(c);
        					continue;
        				}
        				if(b==1)
        				{
        					down(c);
        					continue;
        				}
        			}
        			pre=(c[x-1][y+2].t<c[x-2][y+1].t)?c[x-1][y+2]:c[x-2][y+1];
        			nex=(c[x-1][y+2].t<c[x-2][y+1].t)?c[x-2][y+1]:c[x-1][y+2];

        			if(rot(pre,c[x-1][y+1],nex)=='a')
        			{
        			down(c);
        			continue;
        			}
        			else
        			{
        			left(c);
        			continue;
        			}


        		}

        		if(pos[5]=='.')
        		{
        			if(pos[0]!='.')
        					{
        						b=rand()%2;
        						if(b==0)
        						{
        							up(c);
        							continue;
        						}
        						if(b==1)
        						{
        							left(c);
        							continue;
        						}
        					}
        					pre=(c[x-2][y-1].t<c[x-1][y-2].t)?c[x-2][y-1]:c[x-1][y-2];
        					nex=(c[x-2][y-1].t<c[x-1][y-2].t)?c[x-1][y-2]:c[x-2][y-1];

        					if(rot(pre,c[x-1][y-1],nex)=='a')
        					{
        					left(c);
        					continue;
        					}
        					else
        					{
        					up(c);
        					continue;
        					}
        		}

        		if(pos[7]=='.')
        		{
        			if(pos[0]=='.')
        			{
        				pre=(c[x-2][y-1].t<c[x-1][y-2].t)?c[x-2][y-1]:c[x-1][y-2];
                                					nex=(c[x-2][y-1].t<c[x-1][y-2].t)?c[x-1][y-2]:c[x-2][y-1];

        				if(rot(pre,c[x-1][y-1],nex)=='a')
        				{
        				left(c);
        				continue;
        				}
        				else
        				{
        				up(c);
        				continue;
        				}
        			}
        			if(pos[6]=='.')
        			{
        				pre=(c[x-1][y+2].t<c[x-2][y+1].t)?c[x-1][y+2]:c[x-2][y+1];
                                			nex=(c[x-1][y+2].t<c[x-2][y+1].t)?c[x-2][y+1]:c[x-1][y+2];

        				if(rot(pre,c[x-1][y+1],nex)=='a')
        				{
        				down(c);
        				continue;
        				}
        				else
        				{
        				left(c);
        				continue;
        				}
        			}
        		}

        	}
        	if(block==1)
        	{
        		if(pos[6]=='.' && pos[0]=='.')
        		{
        			if(c[x-1][y+1].t<c[x-1][y-1].t)
        			{
        				down(c);
        				continue;

        			}
        			else
        			{
        				up(c);
        				continue;
        			}
        		}
        		else if(pos[6]=='.')
        		{
        			pre=(c[x-1][y+2].t<c[x-2][y+1].t)?c[x-1][y+2]:c[x-2][y+1];
                            			nex=(c[x-1][y+2].t<c[x-2][y+1].t)?c[x-2][y+1]:c[x-1][y+2];

        			if(rot(pre,c[x-1][y+1],nex)=='a')
        			{
        			down(c);
        			continue;
        			}
        			else
        			{
        				b=rand()%2;
        				if(b==0)
        				{
        					left(c);
        					continue;
        				}
        				else
        				{
        					up(c);
        					continue;
        				}
        			}
        		}
        		else if(pos[0]=='.')
        		{
        				pre=(c[x-2][y-1].t<c[x-1][y-2].t)?c[x-2][y-1]:c[x-1][y-2];
                                					nex=(c[x-2][y-1].t<c[x-1][y-2].t)?c[x-1][y-2]:c[x-2][y-1];

        				if(rot(pre,c[x-1][y-1],nex)=='a')
        				{
        				b=rand()%2;
        					if(rand==0)
        					{
        					left(c);
        					continue;
        					}
        					else
        					{
        					down(c);
        					continue;
        					}
        				}
        				else
        				{
        				up(c);
        				continue;
        				}
        		}
        		else
        		{
        			b=rand()%3;
        			if(b==0)
        			{
        				up(c);
        				continue;
        			}
        			if(b==1)
        			{
        				down(c);
        				continue;
        			}
        			if(b==2)
        			{
        				left(c);
        				continue;
        			}
        		}
        	}

}



}while((x!=inia)||(y!=inib));
printf("x=%d y=%d\n",x,y);
printf("a=%d b=%d\n",inia,inib);
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if((i==0)||(j==0)||(i==n-1)||(j==n-1))
	c[i][j].c=' ';
}
}
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("%d ",c[j][i].t);

}printf("\n");
}
fprintf(file,"%d,%d\n",inia,inib);
return 0;
}
