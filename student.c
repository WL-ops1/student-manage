#include <stdio.h>
#define MAX 100
struct student{
  int id;
  char name[20];
  float score;
};
struct student stu[MAX];
  int count=0;
void add();
void show();
void search();
void modify();
void del();
void menu();
  int main()
{
    int choice;
    system("chcp 65001");
    while(1)
    {
        menu();
        printf ("请输入你想查询事项");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: add();break;
            case 2: show();break;
            case 3: search();break;
            case 4: modify();break;
            case 5: del();break;
            case 6: printf("退出系统!\n");
            return 0;
            default:printf("输入错误，重新输入!\n");
        }
    }
    return 0;
}
//菜单
void menu()
     {
        printf("学生信息管理系统平台\n");
        printf("1.添加学生信息\n");
        printf("2.查询学生\n");
        printf("3.按学号、学号查询学生成绩\n");
        printf("4.修改学生信息\n");
        printf("5.删除学生信息\n");
        printf("6.退出学生信息管理系统平台\n");
     }
//添加学生信息
void add()
     {
        if(count>=MAX)
        {
            printf("学生数量已满，无法再次添加\n");
            return;
        }
        printf("请输入学生学号\n");
        scanf("%d",&stu[count].id);
        printf("请输入学生姓名\n");
        scanf("%s",&stu[count].name);
        printf("请输入学生成绩\n");
        scanf("%f",&stu[count].score);
        count++;
        printf("恭喜,添加成功!\n");
     }
//查询学生信息
void show()
     {
        if(count ==0)
        {
            printf("未查询到该生信息\n");
            return;
        }
        printf("\n学生学号\t学生姓名\t考试成绩\n");
        for(int i = 0;i < count;i++)
        {
            printf("%d\t\t%s\t\t%.1f\n",stu[i].id,stu[i].name,stu[i].score);
        }
     }
//寻找学生信息
void search()
     {
        char name[20];
        int id,i,flag = 0;
        printf("请输入要查询的姓名\n");
        scanf("%s",&name);
        printf("请输入要查询的学号\n");
        scanf("%d",&id);
        for(i = 0;i < count;i++)
        {
            if(stu[i].id == id)
            {
                printf("查询到:%d\t%s\t%.1f\n",stu [i].id,stu[i].name,stu[i].score);
                flag = 1;
                break;
            }
        }
        if(!flag)
          printf("未查询到该生信息!\n");
     }
//修改学生信息
void modify()
     {
        int id,i,flag=0;
        float newScore;
        printf("请输入要修改的学生学号:\n");
        scanf("%d",&id);
        for(i = 0;i < count;i++)
        {
            if(stu[i].id == id)
            {
                printf("输入新信息:\n");
                scanf("%f",&newScore);
                stu[i].score = newScore;
                flag = 1;
                printf("修改成功！\n");
                break;
            }
        }
        if(!flag)
          printf("未查询到该生\n");
    }
//删除学生信息
void del()
     {
        int id,i,j,flag = 0;
        printf("请输入要删除的学生信息\n");
        scanf("%d",&id);
        for(i = 0;i < count;i++)
        {
            if(stu[i].id == id)
            {
                for(j = i;j < count - 1;j++)
                {
                    stu[j]=stu[j+1];
                }
                count--;
                flag = 1;
                printf("删除成功！\n");
                break;
            }
        }
        if(!flag)
        printf("未查询到该生\n");
     }

            



            

    



     



