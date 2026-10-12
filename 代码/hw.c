# include <stdio.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>

//先定义数据结构
//单词，包括单词内容，还有出现次数(单纯的结构，不用链表存，不然查询比较困难)
typedef struct word{
    char w[20];
    int count;
}word;
//文件，包括文件名字，单词列表(处理过的单词，这个用数组存储),单词数量(方便后面计算)
typedef struct file{
    char name[20];
    word words[200];
    int wnum;
}file;
//将所有内容变成小写，去除后缀录入结果
struct word *smallword(char *s)
{
    struct word *w1 = (struct word*)malloc(sizeof(struct word));
    strcpy(w1->w,s);
    for(int i = 0;i < strlen(s);i++)
    {
        if(w1->w[i] >= 'A' && w1->w[i] <= 'Z')
        {
            w1->w[i] = w1->w[i] + 32;
        }
    }
    w1->count = 1;
    return w1;
}
//下面是去后缀,s/es/ing/ed
struct word *basicword(char *s)
{
    struct word *w1 = (struct word*)malloc(sizeof(struct word));
    int l=strlen(s);
    strcpy(w1->w,s);
    //ies
    if(l > 3 && w1->w[l-1] == 's' && w1->w[l-2] == 'e' && w1->w[l-3] == 'i')
    {
        w1->w[l-3] = 'y';
        w1->w[l-2] = '\0';
    }
    //es
    else if(l > 2 && w1->w[l-1] == 's' && w1->w[l-2] == 'e')
    {
        w1->w[l-2] = '\0';
    }
    //s
    else if(l > 1 && w1->w[l-1] == 's')
    {
        w1->w[l-1] = '\0';
    }
    //ing
    else if(l > 3 && w1->w[l-1] == 'g' && w1->w[l-2] == 'n' && w1->w[l-3] == 'i')
    {
        w1->w[l-3] = '\0';
    }
    //ied
    else if(l > 3 && w1->w[l-1] == 'd' && w1->w[l-2] == 'e' && w1->w[l-3] == 'i')
    {
        w1->w[l-3] = 'y';
        w1->w[l-2] = '\0';
    }
    //ed
    else if(l > 2 && w1->w[l-1] == 'd' && w1->w[l-2] == 'e')
    {
        w1->w[l-2] = '\0';
    }
    w1->count = 1;
    return w1;    
}
//根据两个结果找到总体合集
file *allfile(file *f1,file *f2)
{
    int count = 0;
    file *f3 = (file*)malloc(sizeof(file));
    for(int i =0;i < f1->wnum;i++)
    {
        f3->words[count] = f1->words[i];
        count++;
    }
    for(int j = 0;j < f2->wnum;j++)
    {
        int found = 0;
        for(int k = 0;k < count;k++)
        {
            if(strcmp(f2->words[j].w,f3->words[k].w) == 0){
                found = 1;
                break;
            }
        }
        if(found == 0)
        {
            f3->words[count] = f2->words[j];
            count++;
        }
    }
    f3->wnum = count;
    return f3;
}
//根据内容和合集找到向量
int *vector(file *f1,file *f3)
{
    int *v = (int*)malloc(sizeof(int)*f3->wnum);
    for(int i = 0;i < f3->wnum;i++)
    {
        int flag = 0;
        for(int j = 0;j < f1->wnum;j++)
        {
            if(strcmp(f3->words[i].w,f1->words[j].w) == 0)
            {
                v[i]=f1->words[j].count;
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            v[i] = 0;
        }
    }
    return v;
}
//计算向量结果
float result(int *v1,int *v2,int len)
{
    float r3 = 0;
    for(int i = 0;i < len;i++)
    {
        r3 += v1[i]*v2[i];
    }
    float r1 = 0;
    for(int i = 0;i < len;i++)
    {
        r1 += v1[i]*v1[i];
    }    
    float r2 = 0;
    for(int i = 0;i < len;i++)
    {
        r2 += v2[i]*v2[i];
    }
    return r3/sqrt(r1)/sqrt(r2);
}
//计算arccos的结果输出
int main()
{
    int N;
    scanf("%d",&N);
    file files[100];
    for(int i = 0;i < N;i++)
    {
        scanf("%s",files[i].name);
        files[i].wnum = 0;
        char temp[100];
        while(scanf("%s",temp) != EOF)
        {
            if(strcmp(temp,"#") == 0)
            {
                break;
            }
            struct word *w1 = smallword(temp);
            struct word *w2 = basicword(w1->w);
            int found = 0;
            for(int j = 0;j < files[i].wnum;j++)
            {
                if(strcmp(files[i].words[j].w,w2->w) == 0)
                {
                    files[i].words[j].count++;
                    found = 1;
                    break;
                }
            }
            if(found == 0)
            {
                strcpy(files[i].words[files[i].wnum].w,w2->w);
                files[i].words[files[i].wnum].count = 1;
                files[i].wnum++;
            }
        }
    }
    int M;
    scanf("%d",&M);
    for(int i = 0;i < M;i++)
    {
        char q1[20],q2[20];
        scanf("%s %s",q1,q2);
        int qn1,qn2;
        int find1 = 0;
        int find2 = 0;
        for(int j= 0;j < N;j++)
        {
            if(strcmp(files[j].name,q1) == 0)
            {
                qn1 = j;
                find1 = 1;
            }
            if(strcmp(files[j].name,q2) == 0)
            {
                qn2 = j;
                find2 = 1;
            }            
            if(find1 && find2)
            {
                break;
            }
        }
        if(find1 && find2){
            file *f3 = allfile(&files[qn1],&files[qn2]);
            int *v1 = vector(&files[qn1],f3);
            int *v2 = vector(&files[qn2],f3);
            float res = result(v1,v2,f3->wnum);
            if(res > 1.0f){
                res = 1.0f;
            }
            if(res < -1.0f){
                res = -1.0f;
            }
            printf("Case %d: ",i+1);
            printf("%.3f\n",acos(res));
        }else{
            printf("Case %d: 0.000\n", i+1);
        }
    }
}