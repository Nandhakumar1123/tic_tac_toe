#include<iostream>
using namespace std;
int pointcheck(char b[3][3]);
void table(char e[3][3]);
void point(int ,int);
void table(char e[3][3])
{
  int i,j;
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      cout<<"   "<<e[i][j];
      if(j!=2)
      cout<<"  |";
    } 
       cout<<"\n";
      if(i!=2)
       cout<<"_"<<endl;
    }
     
  }
int pointcheck(char b[3][3])
{
 int row1,col1;
 for(row1=0;row1<3;row1++)
 {
 //row
   col1=0;
     if('X'==b[row1][col1]&& b[row1][col1+1]==b[row1][col1+2]&&b[row1][col1+2]=='X')
      return 1;
     else if('O'==b[row1][col1]&& b[row1][col1+1]==b[row1][col1+2]&&b[row1][col1+2]=='O')
       return 2;
      
       }
       //coloumn
       for(col1=0;col1<3;col1++)
       {
       row1=0;
     if('X'==b[row1][col1]&& b[row1+1][col1]==b[row1+2][col1]&&b[row1+2][col1]=='X')
       return 1; 
     else if('O'==b[row1][col1]&& b[row1+1][col1]==b[row1+2][col1]&&b[row1+2][col1]=='O')
        return 2;
     
         }
         //diagonal.
    if('X'==b[0][0]&& b[1][1]==b[2][2]&&b[1][1]=='X'||'X'==b[2][0]&& b[1][1]==b[0][2]&&b[1][1]=='X')
        return 1;
   else if('O'==b[0][0]&& b[1][1]==b[2][2]&&b[1][1]=='O'||'O'==b[2][0]&& b[1][1]==b[0][2]&&b[1][1]=='O')
         return 2;
       
   return 0;  
       }
  void point(int x,int o,int d)
  {
  
     if(o<x)
       cout<<"PLAYER X WINS"<<endl;
     else if(o>x)
       cout<<"PLAYER O WINS"<<endl;
     else if(d>0)
         cout<<"THE MATCH IS DRAW "<<endl;
     
      }
int main()
{
  int row,col,k=0,r=1,rep=0,xco=0,oco=0,d=0,li;
  char a[3][3]={'1 ','2 ',' 3','4 ','5 ',' 6','7 ','8 ','9'},c='X';
  cout<<"### WELCOME TO THE TIC TAC TOE GAME ###\n PLAYER 1-X\n PLAYER 2-O"<<endl;
  table(a);
  while(r)
  {
   for(li=0;li<9;li++)
   {
       cout<<c<<" TURN"<<endl;
       cout<<"ENTER THE ROW AND COLOUMN"<<endl;
       cin>>row>>col;
       a[row][col]=c;
       table(a);
       k=pointcheck(a);
      if(k==1)
       {
       xco++;
        point(k,0,d);
        break;
        }
        else if(k==2)
        {
         oco++;
         point(0,k,d);
         break;
         }
        c=(c=='X')?'O':'X';
         
       if(li==8)
       {
         d++;
         point(0,0,d);
       }
      
      }
         
       cout<<"### DO YOU WANT TO CONTINUE ###\n CONTINUE->1\n EXIT->0"<<endl;
     for(row=0;row<3;row++)
     {
    for(col=0;col<3;col++)
    {
     a[row][col]=' ';
     }
     }
     c='X';
       cin>>r;
       rep++;
       if(r!=0)
       cout<<"MATCH-"<<rep+1<<endl;
       if(r==0)
       {
        cout<<"TOTAL MATCHES "<<rep<<endl;
        cout<<"PLAYER X WINS -"<<xco<<" TIMES"<<endl;
        cout<<"PLAYER O WINS -"<<oco<<" TIMES"<<endl;
        cout<<"MATCHES DRAW -"<<d<<" TIMES"<<endl;
        }
  }
   return 0;
}
