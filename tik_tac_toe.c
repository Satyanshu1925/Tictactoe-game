#include<stdio.h>
#include<stdlib.h>
int i,j,a,b,player,pos,cnt;
char arr[9][11],ch;
void print();
void game();
void convert(int);
void enter(int,int);
void test();
void check();
void main()
{
    printf("Player one please enter your symbol X or O \t");
    scanf("%c",&ch);
    if(ch=='X' || ch=='x')
        {
            cnt=0;
            player=1;
        }
    else if (ch=='O' || ch=='o')
        {
            cnt=1;
            player =1;
        }
    else
    {
        printf("You have not entered proper symbol\nSo, I had given X to the player one\n");
        cnt=0;
        player = 1;
    }
    printf("You need to enter the position \n");
    printf("your positions are\n1\t2\t3\n4\t5\t6\n7\t8\t9\n");
    for(i=0;i<9;i++)
    {
     for(j=0;j<11;j++)
     {
          if((i==2||i==5)&&(j!=3 && j!=7))
            arr[i][j]='_';
          else if(j==3 || j==7)
            arr[i][j]='|';
          else
            arr[i][j]=' ';
     }
    }
    game();
}

void game()
{
    print();
    if(player==1)
    {
        printf("\nplayer one turn\n Enter your position \t");
        player++;
    }
    else
    {
        printf("\nplayer two turn\n Enter your position \t");
        player--;
    }
    scanf("%d",&pos);
    if(pos<1||pos>9)
     {
         printf("No position found \n");
         game();
     }
     convert(pos);
     enter(a,b);
     test();
}
void print()
{
    for(i=0;i<9;i++)
    {
        for(j=0;j<11;j++)
            printf("%c",arr[i][j]);
            printf("\n");
    }
}
void convert(int pos)
{
    switch(pos)
    {
      case 1: a=1,b=1;
                break;
      case 2: a=1,b=5;
                break;
      case 3: a=1,b=9;
                break;
      case 4: a=4,b=1;
                break;
      case 5: a=4,b=5;
                break;
      case 6: a=4,b=9;
                break;
      case 7: a=7,b=1;
                break;
      case 8: a=7,b=5;
                break;
      case 9: a=7,b=9;
                break;
    }
}
void enter(int a,int b)
{
    if(arr[a][b]=='|'||arr[a][b]=='_'||arr[a][b]==' ')
    {
        if(cnt%2==0)
            {
                arr[a][b]='X';
                cnt++;
            }
        else
           {
                arr[a][b]='O';
                cnt++;
           }
    }
    else
    {
        printf("Sorry position is occupied\n");
        if(player==2)
            player=1;
        if(player==1)
            player=2;
        game();
    }
}
void test()
{
    if((arr[1][1]=='X' && arr[1][5]=='X' && arr[1][9]=='X' )||(arr[4][1]=='X' && arr[4][5]=='X' && arr[4][9]=='X' )||(arr[7][1]=='X' && arr[7][5]=='X' && arr[7][9]=='X' )||(arr[1][1]=='X' && arr[4][1]=='X' && arr[7][1]=='X' )||(arr[1][5]=='X' && arr[4][5]=='X' && arr[7][5]=='X' )||(arr[1][9]=='X' && arr[4][9]=='X' && arr[7][9]=='X' )||(arr[1][1]=='X' && arr[4][5]=='X' && arr[7][9]=='X' )||(arr[1][1]=='X' && arr[4][5]=='X' && arr[7][1]=='X' ))
    {
         printf("Player one wins");
         exit(0);
    }
     if((arr[1][1]=='O' && arr[1][5]=='O' && arr[1][9]=='O' )||(arr[4][1]=='O' && arr[4][5]=='O' && arr[4][9]=='O' )||(arr[7][1]=='O' && arr[7][5]=='O' && arr[7][9]=='O' )||(arr[1][1]=='O' && arr[4][1]=='O' && arr[7][1]=='O' )||(arr[1][5]=='O' && arr[4][5]=='O' && arr[7][5]=='O' )||(arr[1][9]=='O' && arr[4][9]=='O' && arr[7][9]=='O' )||(arr[1][1]=='O' && arr[4][5]=='O' && arr[7][9]=='O' )||(arr[1][1]=='O' && arr[4][5]=='O' && arr[7][1]=='O' ))
    {
        printf("Player two wins");
        exit(0);
    }
    check();
}
void check()
{
 if(arr[1][1]!=' '&&arr[1][5]!=' '&&arr[1][9]!=' '&&arr[4][1]!=' '&&arr[4][5]!=' '&&arr[4][9]!=' '&&arr[7][1]!=' '&&arr[7][5]!=' '&&arr[7][9]!=' ')
 {
     print();
     printf("\nNo one wins\n");
     exit(0);
 }
 game();
}
