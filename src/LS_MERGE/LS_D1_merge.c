#include<stdio.h>
#include<math.h>
#include<malloc.h>

int arr_node[1000];    //random nodes array
int q,p,r,no_of_node,pt;
int a,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,temp;
int prime[20000];
int count=0,zp=0,z1,z2;
int countt=0;
int k;
int i,j;
int count1=0,***key_set,irr_poly[3],add_poly[3],mul_poly[3],vector[1000][2],poly_a[3],poly_b[3],poly_x[3];
//int key_set_stat[11201][150];
int **key_set_stat;
int *key_ES;
int time;
//int merge_node,z,merge_set[6000][10];
int **merge_key_set,merge_node;
int flag1=0,merge_k;

void merge_initialize()
{
    merge_key_set=(int**)malloc(merge_node*sizeof(int*));
    for(a1=0;a1<merge_node;a1++)
    {
        merge_key_set[a1]=(int*)malloc((2*k)*sizeof(int));
    }
}
void merge_p()
{
    merge_initialize();
    merge_k=0;
    for(a4=0; a4<p-4; a4=a4+2)                          //this is for 0 to p-3
    {
        for(a5=1; a5<p; a5++)
        {
            for(a6=0; a6<k; a6++)
            {
                merge_key_set[merge_k][a6]=key_set_stat[a4*p+a5][a6];

                merge_key_set[merge_k][a6+k]=key_set_stat[(a4+1)*p+(a5-1)][a6];

//                printf("k(%d,%d)(%d,%d)  ",key_set[a4*p+a5][a6][0],key_set[a4*p+a5][a6][1],key_set[(a4+1)*p+(a5-1)][a6][0],key_set[(a4+1)*p+(a5-1)][a6][1]);

                //printf("m(%d,%d)(%d,%d)  ",merge_key_set[merge_k][a6][0],merge_key_set[merge_k][a6][1],merge_key_set[merge_k][a6+k][0],merge_key_set[merge_k][a6+k][1]);
            }
            merge_k++;
        }
        for(a7=0; a7<k; a7++)
        {
            merge_key_set[merge_k][a7]=key_set_stat[a4*p+0][a7];

            merge_key_set[merge_k][a7+k]=key_set_stat[(a4+1)*p+(p-1)][a7];
            //printf("(%d,%d)  (%d,%d)",key_set[a4*p+0][a7][0],key_set[a4*p+0][a7][1],key_set[(a4+1)*p+(p-1)][a7][0],key_set[(a4+1)*p+(p-1)][a7][1]);
        }
        merge_k++;
    }
    for(a8=0; a8<p-4; a8=a8+2)                               //handling last 3 rows without last 3X3   0 to p-4
    {
        for(a9=0; a9<k; a9++)
        {
            merge_key_set[merge_k][a9]=key_set_stat[(p-3)*p+a8][a9];

            merge_key_set[merge_k][a9+k]=key_set_stat[(p-1)*p+(a8+1)][a9];
            //printf("(%d,%d)(%d,%d)",key_set[(p-3)*p+a8][a9][0],key_set[(p-3)*p+a8][a9][1],key_set[(p-1)*p+(a8+1)][a9][0],key_set[(p-1)*p+(a8+1)][a9][1]);
        }
        merge_k++;

        //printf("M(%d)::",merge_k);
        for(a10=0; a10<k; a10++)
        {
            merge_key_set[merge_k][a10]=key_set_stat[(p-2)*p+a8][a10];

            merge_key_set[merge_k][a10+k]=key_set_stat[(p-3)*p+(a8+1)][a10];
            //printf("(%d,%d)(%d,%d)",key_set[(p-3)*p+(a8+1)][a10][0],key_set[(p-3)*p+(a8+1)][a10][1],key_set[(p-2)*p+a8][a10][0],key_set[(p-2)*p+a8][a10][1]);
            //printf("(%d)(%d,%d)(%d,%d)",merge_key_set[merge_k][a10][0],merge_key_set[merge_k][a10][1],merge_key_set[merge_k][a10+k][0],merge_key_set[merge_k][a10+k][1]);
        }
        merge_k++;

        //printf("\nM(%d)::",merge_k);
        for(a11=0; a11<k; a11++)
        {
            merge_key_set[merge_k][a11]=key_set_stat[(p-2)*p+(a8+1)][a11];

            merge_key_set[merge_k][a11+k]=key_set_stat[(p-1)*p+a8][a11];
            //printf("(%d,%d)(%d,%d)",merge_key_set[merge_k][a11][0],merge_key_set[merge_k][a11][1],merge_key_set[merge_k][a11+k][0],merge_key_set[merge_k][a11+k][1]);
        }
        merge_k++;
        //printf("%d,",merge_k);
    }


//merging last 3X3
    for(a9=0; a9<k; a9++)
    {
        merge_key_set[merge_k][a9]=key_set_stat[(p-3)*p+(p-3)][a9];

        merge_key_set[merge_k][a9+k]=key_set_stat[(p-1)*p+(p-2)][a9];
    }
    merge_k++;

    for(a9=0; a9<k; a9++)
    {
        merge_key_set[merge_k][a9]=key_set_stat[(p-3)*p+(p-2)][a9];

        merge_key_set[merge_k][a9+k]=key_set_stat[(p-2)*p+(p-3)][a9];
    }
    merge_k++;

    for(a9=0; a9<k; a9++)
    {
        merge_key_set[merge_k][a9]=key_set_stat[(p-3)*p+(p-1)][a9];

        merge_key_set[merge_k][a9+k]=key_set_stat[(p-2)*p+(p-2)][a9];
    }
    merge_k++;

    for(a9=0; a9<k; a9++)
    {
        merge_key_set[merge_k][a9]=key_set_stat[(p-2)*p+(p-1)][a9];

        merge_key_set[merge_k][a9+k]=key_set_stat[(p-1)*p+(p-3)][a9];
    }
    merge_k++;
}
void merge_np()
{
    merge_initialize();
    merge_k=0;
    for(a4=0; a4<p-4; a4=a4+2)                                                      //merging apart from last 3 rows
    {
        for(a5=0; a5<p; a5++)
        {
            if((a5%pt)!=0)
            {
                for(a6=0; a6<k; a6++)
                {
                    merge_key_set[merge_k][a6]=key_set_stat[a4*p+a5][a6];

                    merge_key_set[merge_k][a6+k]=key_set_stat[(a4+1)*p+(a5-1)][a6];
                    //printf("(%d,%d)(%d,%d)",merge_key_set[merge_k][a6][0],merge_key_set[merge_k][a6][1],merge_key_set[merge_k][a6+k][0],merge_key_set[merge_k][a6+k][1],merge_k);
                }
                merge_k++;
                //printf("\n<(%d,%d)  (%d,%d)>",a4,a5,a4+1,a5-1);
            }
            if((a5%pt)==0)
            {
                for(a7=0; a7<k; a7++)
                {
                    merge_key_set[merge_k][a7]=key_set_stat[a4*p+a5][a7];

                    merge_key_set[merge_k][a7+k]=key_set_stat[(a4+1)*p+(a5+(pt-1))][a7];
                }
                merge_k++;
                //printf("\n<(%d,%d)  (%d,%d)>",a4,a5,a4+1,a5+(pt-1));
            }
        }
    }
    //printf("%d",merge_k);
    for(a8=0; a8<p-4; a8=a8+2)                               //handling last 3 rows without last 3X3   0 to p-4
    {
        for(a9=0; a9<k; a9++)
        {
            merge_key_set[merge_k][a9]=key_set_stat[(p-3)*p+a8][a9];

            merge_key_set[merge_k][a9+k]=key_set_stat[(p-1)*p+(a8+1)][a9];
        }
        //printf("\n");
        merge_k++;

        //printf("M(%d)::",merge_k);
        for(a10=0; a10<k; a10++)
        {
            merge_key_set[merge_k][a10]=key_set_stat[(p-2)*p+a8][a10];

            merge_key_set[merge_k][a10+k]=key_set_stat[(p-3)*p+(a8+1)][a10];
            //printf("(%d,%d)(%d,%d)",key_set[(p-3)*p+(a8+1)][a10][0],key_set[(p-3)*p+(a8+1)][a10][1],key_set[(p-2)*p+a8][a10][0],key_set[(p-2)*p+a8][a10][1]);
            //printf("(%d)(%d,%d)(%d,%d)",merge_key_set[merge_k][a10][0],merge_key_set[merge_k][a10][1],merge_key_set[merge_k][a10+k][0],merge_key_set[merge_k][a10+k][1]);
        }
        merge_k++;

        //printf("\nM(%d)::",merge_k);
        for(a11=0; a11<k; a11++)
        {
            merge_key_set[merge_k][a11]=key_set_stat[(p-2)*p+(a8+1)][a11];

            merge_key_set[merge_k][a11+k]=key_set_stat[(p-1)*p+a8][a11];
            //printf("(%d,%d)(%d,%d)",merge_key_set[merge_k][a11][0],merge_key_set[merge_k][a11][1],merge_key_set[merge_k][a11+k][0],merge_key_set[merge_k][a11+k][1]);
        }
        merge_k++;
        //printf("%d,",merge_k);

    }
    //merging last 3X3
    for(a9=0; a9<k; a9++)
    {
        merge_key_set[merge_k][a9]=key_set_stat[(p-3)*p+(p-3)][a9];

        merge_key_set[merge_k][a9+k]=key_set_stat[(p-1)*p+(p-2)][a9];
    }
    merge_k++;

    for(a9=0; a9<k; a9++)
    {
        merge_key_set[merge_k][a9]=key_set_stat[(p-3)*p+(p-2)][a9];

        merge_key_set[merge_k][a9+k]=key_set_stat[(p-2)*p+(p-3)][a9];
    }
    merge_k++;

    for(a9=0; a9<k; a9++)
    {
        merge_key_set[merge_k][a9]=key_set_stat[(p-3)*p+(p-1)][a9];

        merge_key_set[merge_k][a9+k]=key_set_stat[(p-2)*p+(p-2)][a9];
    }
    merge_k++;

    for(a9=0; a9<k; a9++)
    {
        merge_key_set[merge_k][a9]=key_set_stat[(p-2)*p+(p-1)][a9];

        merge_key_set[merge_k][a9+k]=key_set_stat[(p-1)*p+(p-3)][a9];
    }
    merge_k++;
}

void initialize()
{
    int a1,a2;
    key_set=(int***)malloc(no_of_node*sizeof(int**));
    for(a1=0; a1<no_of_node; a1++)
    {
        key_set[a1]=(int**)malloc(k*sizeof(int*));
        for(a2=0; a2<k; a2++)
        {
            key_set[a1][a2]=(int*)malloc(2*sizeof(int));
        }
    }

    key_set_stat=(int**)malloc(no_of_node*sizeof(int*));
    for(a1=0;a1<no_of_node;a1++)
    {
        key_set_stat[a1]=(int*)malloc(k*sizeof(int));
    }
    key_ES=(int*)malloc(no_of_node*sizeof(int));
}

float nc2(int n)
{
    float a;
    a=n*(n-1)*0.5;
    return a;
}

int transfer_key(int ***key)
{
    int a;
    a=***key+(**(*(key+1)))*p;
    return a;
}
void vectorize(int p)
{
    int pt=sqrt(p),i;
    for(i=0; i<pt; i++)                //vector ax+b
    {
        for(j=0; j<pt; j++)
        {
            vector[i*pt+j][0]=j;      //b
            vector[i*pt+j][1]=i;      //a
        }
    }
}

int get_x_bar(int x,int pt)
{
    int i;
    int x_bar;
    for(i=0; i<pt; i++)
    {
        if((x+i)%pt==0)
        {
            x_bar=i;
            break;
        }
    }
    return x_bar;
}

void addpoly(int *polya,int *polyb)
{
    int i;
    for(i=2; i>=0; i--)
    {
        *(add_poly+i)=*(polya+i)+*(polyb+i);
    }
}

void mulpoly(int *polya,int *polyb)
{
    int i;
    for(i=2; i>=0; i--)
    {
        for(j=2; j>=0; j--)
        {
            *(mul_poly+(i+j))=*(mul_poly+(i+j))+(*(polya+i))*(*(polyb+j));
        }
    }
}
int isprime(int x)
{
    int a,a1,count;
    count=0;
    for(a1=1; a1<=(x/2); a1++)
    {
        if(a1!=1)
        {
            if((x%a1)==0)
                count+=1;
        }
    }
    if(count==0)
    {
        return 1;
    }
    else
        return 0;
}

void random(int n)
{
    int x,y,j,f;
    for(x=0; x<n; x++)
    {
        y=(abs(x*x+x+1))%n;
        if(x==0)
            arr_node[0]=y;
        else
        {
            while(1)
            {
                f=0;
                for(j=0; j<x; j++)
                {
                    if(arr_node[j]==y)
                        f=1;
                }
                if(f==0)
                {
                    arr_node[x]=y;
                    break;
                }
                else
                {
                    y=(y+1)%n;
                }
            }
        }
    }
}
void main()
{
    FILE* fp;
    fp=fopen("ls_mb.txt","a");
    fprintf(fp,"-----------------------------------------------\n");
    fprintf(fp,"             start of program                  \n");
    fprintf(fp,"-------------------------------------------------");
    printf("Enter no of nodes:");
    scanf("%d",&no_of_node);
    printf("\nTotal nodes in the network: %d",no_of_node);
    fprintf(fp,"\nTotal nodes in the network: %d",no_of_node);
    merge_node=no_of_node/2;
    printf("\nMerge node in teh network : %d",merge_node);
    for(a=2; a<200; a++)
    {
        count=0;
        for(a1=1; a1<=(a/2); a1++)
        {
            if(a1!=1)
            {
                if((a%a1)==0)
                    count+=1;
            }
        }
        if(count==0)
        {
            prime[zp]=a;
            prime[++zp]=a*a;
            zp++;
        }
    }
    temp=0;
    for (i=0; i<zp-1; i++)
    {
        for (j=0; j<zp-1-i; j++)
        {
            if (prime[j]>prime[j+1])
            {
                temp=prime[j];
                prime[j]=prime[j+1];
                prime[j+1]=temp;
            }
        }
    }
    temp=0;

//finding q for given n where k=(q*q)
    for(z1=0; z1<zp; z1++)
    {
        z2=prime[z1];
        temp=z2*z2;
        if(no_of_node<=temp)
        {
            p=prime[z1];
            break;
        }
    }
    for(z1=0; z1<zp; z1++)
    {
        z2=prime[z1];
        temp=z2*z2;
        if(merge_node<=temp)
        {
            r=prime[z1];
            break;
        }
    }
    if(isprime(p)==1)
        pt=p;
    if(isprime(p)==0)
        pt=sqrt(p);
    int r1=r*r;
    float r1c2=r1*(r1-1)*0.5;
    // fprintf(fp,"\nqt : %d\n",pt);
    printf("\n p=%d",p);
    printf("\n r=%d",r);
    printf("\nenter value of k(2-%d) (keys per node)",p);
    scanf("%d",&k);
    fprintf(fp,"\nkeys per node : %d",k);
    fprintf(fp,"\nr : %d",r);
    int x=r+1;
    float px=(float) k/x;
    //printf("\npx: %f",px);
    //fprintf(fp,"\npx: %f",px);
    //printf("\nnodes: \n");
    //fprintf(fp,"\n p=%d",p);
    //fprintf(fp,"\nnodes: \n");
    a1=0;
    a2=0;
    a3=0;
    initialize();
// calculating keys
    int l_t;
    if(isprime(p)==1)
    {
        for(a1=0; a1<p; a1++)  //a:a1 b:a2 x:a3 key(x,ax+b mod p)
        {
            for(a2=0; a2<p; a2++)
            {
                for(a3=0; a3<k; a3++)
                {
                    key_set[a1*p+a2][a3][0]=a3;
                    key_set[a1*p+a2][a3][1]=((a1*a3)+a2)%p;
                }
            }
        }
    }

    else
    {
        vectorize(p);
        printf("\nEnter the irreducable polynomial in z(%d)(From higher to lower degree)",pt);
        for(l_t=2; l_t>=0; l_t--)
        {
            printf("\nX^%d:",l_t);
            scanf("%d",&irr_poly[l_t]);
        }
        for(a1=0; a1<p; a1++)  //a:a1 b:a2 x:a3 key(x,ax+b mod p)
        {
            for(a2=0; a2<p; a2++)
            {
                for(a3=0; a3<k; a3++)
                {
                    key_set[a1*p+a2][a3][0]=a3;

                    poly_a[0]=vector[a1][0];
                    poly_a[1]=vector[a1][1];

                    poly_b[0]=vector[a2][0];
                    poly_b[1]=vector[a2][1];

                    poly_x[0]=vector[a3][0];
                    poly_x[1]=vector[a3][1];

                    mulpoly(poly_a,poly_x);
                    addpoly(mul_poly,poly_b);
                    //printf("\n %dX^2+%dX+%d + %dX+%d=%dX^2+%dX+%d",mul_poly[2],mul_poly[1],mul_poly[0],poly_b[1],poly_b[0],add_poly[2],add_poly[1],add_poly[0]);

                    add_poly[0]=add_poly[0]%pt;
                    add_poly[1]=add_poly[1]%pt;
                    add_poly[2]=add_poly[2]%pt;

                    //printf("\n %dX^2+%dX+%d",add_poly[2],add_poly[1],add_poly[0]);

                    while(1)
                    {
                        if((add_poly[2]-irr_poly[2]<0)||(add_poly[1]-irr_poly[1]<0)||(add_poly[0]-irr_poly[0]<0))
                            break;
                        else
                            add_poly[2]=add_poly[2]-irr_poly[2];
                        add_poly[1]=add_poly[1]-irr_poly[1];
                        add_poly[0]=add_poly[0]-irr_poly[0];
                    }

                    //printf("\n %dX^2+%dX+%d",add_poly[2],add_poly[1],add_poly[0]);

                    if((add_poly[2]!=0)&&(add_poly[1]!=0)&&(add_poly[0]==0))   //const 0
                    {
                        add_poly[1]=add_poly[1]+add_poly[2]*irr_poly[1];
                        add_poly[0]=add_poly[2]*get_x_bar(irr_poly[0],pt);
                        add_poly[2]=0;
                    }

                    if((add_poly[2]!=0)&&(add_poly[1]==0)&&(add_poly[0]!=0))     //X 0
                    {
                        add_poly[1]=add_poly[2]*irr_poly[1];
                        add_poly[0]=add_poly[0]+add_poly[2]*get_x_bar(irr_poly[0],pt);
                        add_poly[2]=0;
                    }

                    if((add_poly[2]!=0)&&(add_poly[1]==0)&&(add_poly[0]==0))        //const,X 0
                    {
                        add_poly[1]=add_poly[2]*irr_poly[1];
                        add_poly[0]=add_poly[2]*get_x_bar(irr_poly[0],pt);
                        add_poly[2]=0;
                    }

                    add_poly[0]=add_poly[0]%pt;
                    add_poly[1]=add_poly[1]%pt;
                    add_poly[2]=add_poly[2]%pt;

                    //printf("\n %dX^2+%dX+%d",add_poly[2],add_poly[1],add_poly[0]);

                    if((add_poly[2]==0)&&(add_poly[1]==0)&&(add_poly[0]==0))          //all 0
                    {
                        key_set[a1*p+a2][a3][1]=0;
                    }


                    if((add_poly[2]==0)&&(add_poly[1]!=0)&&(add_poly[0]!=0))       //X^2 0
                    {
                        key_set[a1*p+a2][a3][1]=add_poly[1]*pt+add_poly[0];
                    }

                    if((add_poly[2]==0)&&(add_poly[1]!=0)&&(add_poly[0]==0))        //X^2, const 0
                    {
                        key_set[a1*p+a2][a3][1]=add_poly[1]*pt;
                    }

                    if((add_poly[2]==0)&&(add_poly[1]==0)&&(add_poly[0]!=0))         //X^2,X 0
                    {
                        key_set[a1*p+a2][a3][1]=add_poly[0];
                    }



                    for(l_t=2; l_t>=0; l_t--)
                    {
                        add_poly[l_t]=0;
                        mul_poly[l_t]=0;
                    }
                }
            }
        }
    }
//print keys
    //fprintf(fp,"\n");
    printf("\n");
    //convert keys to single number
    for(a1=0; a1<p; a1++)
    {
        for(a2=0; a2<p; a2++)
        {
            for(a3=0; a3<k; a3++)
            {
                key_set_stat[a1*p+a2][a3]=key_set[a1*p+a2][a3][0]+key_set[a1*p+a2][a3][1]*p;
            }
        }
    }

    /*for(a1=0; a1<p; a1++)
    {
        for(a2=0; a2<p; a2++)
        {
            for(a3=0; a3<k; a3++)
            {
                printf("%d, ",key_set_stat[a1*p+a2][a3]);
            }
            printf("\n");
        }
    }*/
    if(isprime(p)==0)
    merge_np();
    else
    merge_p();


    // calculate E(s) and V(s)
    int compromised_node,a4,compromised[500];
    printf("Enter number of compromised nodes");
    scanf("%d",&compromised_node);
    fprintf(fp,"\nCompromised nodes:%d",compromised_node);
    int unique_key=0;
    float broken_links,total_links,es;
    for(time=0; time<100; time++)                             //runtime
    {
        unique_key=0;
        for(a4=0; a4<compromised_node; a4++)
        {
            compromised[a4]=(rand()+27*(time+1))%merge_node;
        }
        int compromised_keys[200000];
        count1=0;
        for(a1=0; a1<compromised_node; a1++)
        {
            //printf("C%d",compromised[a1]);
            for(a2=0; a2<2*k; a2++)
            {
                compromised_keys[count1]=merge_key_set[compromised[a1]][a2];
                //printf("%d,",compromised_keys[count1]);
                count1+=1;
            }
            //printf("\n");
        }
        //printf("\ncount1=%d",count1);
        //E(s) calculation

        for(a1=0; a1<merge_node; a1++)
        {
            key_ES[a1]=0;
        }
        for(a1=0; a1<count1; a1++)
        {
            key_ES[compromised_keys[a1]]++;
        }
        for(a1=0; a1<merge_node; a1++)
        {
            if(key_ES[a1]!=0)
                unique_key++;
        }
        //printf("\n U:%d",unique_key);
        broken_links=(float)unique_key*nc2(p);
        total_links=(float)p*k*nc2(r);
        //printf("\n%f",(broken_links/total_links));
        es+=broken_links/total_links;
    }
    printf("\nes::%f",es/100);                          //times
    fprintf(fp,"\nes::%f",es/100);
    free(key_ES);

    fprintf(fp,"-----------------------------------------------\n");
    fprintf(fp,"             end of program                  \n");
    fprintf(fp,"-------------------------------------------------");
}
