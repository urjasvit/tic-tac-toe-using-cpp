#include<iostream>
#include<stdlib.h>

using namespace std;
//game class for initializing matrix & having two friend functions
class game
{
    public:
           char a[3][3];//character array
           char x;
           int k=1;
           game()
             {
               if(k==1)
                 x='X';//player1
               else
                  x='O';//player2
              //initializing positions of array
              a[0][0]='1';
              a[0][1]='2';
              a[0][2]='3';
              a[1][0]='4';
              a[1][1]='5';
              a[1][2]='6';
              a[2][0]='7';
              a[2][1]='8';
              a[2][2]='9';
             }
           friend void print();
           friend void check();

};

//class game_chance to give chance accordingly & checking for winning
class game_chance:protected game //protected inheritance
  {
         int pos;
    public:
         int chance(int);//function to give chance
         void check();//friend function declaration
         void print();//friend function declaration
  };
  void game_chance ::print()//friend function definition for printing basic array & giving instructions
   {
                 cout<<"\nTWO player game \nPLAYER 1=X \nPLAYER 2=O\n";
                 cout<<"\nenter X & O according to the position in which to you want to enter\n";
                 int j;
                 for(int i=0;i<3;i++)
                 {
                   for(j=0;j<3;j++)
                    {
                      cout<<a[i][j]<<"_|_";
                    }
                 cout<<"\n";
                 }
  }
  void game_chance ::check()//friend function definition for checking winning combination for both players
  {
           if(a[0][0]=='X'&&a[0][1]=='X'&&a[0][2]=='X')
            {
              cout<<"PLAYER1 WINS!!!";
              exit(1);
            }
           else if(a[1][0]=='X'&&a[1][1]=='X'&&a[1][2]=='X')
            {
               cout<<"PLAYER1 WINS!!!";
               exit(1);
            }
           else if(a[2][0]=='X'&&a[2][1]=='X'&&a[2][2]=='X')
            {
                cout<<"PLAYER1 WINS!!!";
                exit(1);
            }
            else if(a[0][0]=='O'&&a[0][1]=='O'&&a[0][2]=='O')
            {
                cout<<"PLAYER2 WINS!!!";
                exit(1);
            }
            else if(a[1][0]=='O'&&a[1][1]=='O'&&a[1][2]=='O')
            {
                cout<<"PLAYER2 WINS!!!";
                exit(1);
            }
            else if(a[2][0]=='O'&&a[2][1]=='O'&&a[2][2]=='O')
            {
                cout<<"PLAYER2 WINS!!!";
                exit(1);
            }
            else if(a[0][0]=='X'&&a[1][0]=='X'&&a[2][0]=='X')
            {
                cout<<"PLAYER1 WINS!!!";
                exit(1);
            }
            else if(a[1][0]=='O'&&a[1][1]=='O'&&a[1][2]=='O')
           {
                cout<<"PLAYER2 WINS!!!";
                exit(1);
           }
            else if(a[0][1]=='X'&&a[1][1]=='X'&&a[2][1]=='X')
           {
                cout<<"PLAYER1 WINS!!!";
                exit(1);
           }
           else if(a[0][1]=='O'&&a[1][1]=='O'&&a[2][1]=='O')
           {
                cout<<"PLAYER2 WINS!!!";
                exit(1);
           }
           else if(a[0][2]=='X'&&a[1][2]=='X'&&a[2][2]=='X')
           {
                cout<<"PLAYER1 WINS!!!";
                exit(1);
           }
           else if(a[0][2]=='O'&&a[1][2]=='O'&&a[2][2]=='O')
           {
                cout<<"PLAYER2 WINS!!!";
                exit(1);
           }
           else if(a[0][0]=='O'&&a[1][1]=='O'&&a[2][2]=='O')
           {
                cout<<"PLAYER2 WINS!!!";
                exit(1);
           }
           else if(a[0][0]=='X'&&a[1][1]=='X'&&a[2][2]=='X')
           {
                cout<<"PLAYER1 WINS!!!";
                exit(1);
           }
           else if(a[0][2]=='X'&&a[1][1]=='X'&&a[2][0]=='X')
          {
                cout<<"PLAYER1 WINS!!!";
                exit(1);
          }
          else if(a[0][2]=='O'&&a[1][1]=='O'&&a[2][0]=='O')
          {
               cout<<"PLAYER2 WINS!!!";
               exit(1);
          }
  }
  int game_chance::chance(int t)//function definition to alternate chances to players
  {
               int flag=0;//flag variable to avoid overlapping
               if(t==1)
                 x='X';//initialing player1 with X
               else x='O';//initialing player2 with O
               cout<<"enter position";
               cin>>pos;
               switch(pos)//for writing X or O on entered position
               { //if condition when position entered does not contain X or O
                 //else condition when entered position already has X or O(overlapping)
                   case 1:if(a[0][0]=='1')
                             a[0][0]=x;
                          else
                             flag=1;
                          break;
                   case 2:if(a[0][1]=='2')
                             a[0][1]=x;
                          else
                             flag=1;
                          break;
                   case 3:if(a[0][2]=='3')
                             a[0][2]=x;
                          else
                             flag=1;
                          break;
                   case 4:if(a[1][0]=='4')
                             a[1][0]=x;
                          else
                             flag=1;
                          break;
                   case 5:if(a[1][1]=='5')
                             a[1][1]=x;
                          else
                             flag=1;
                          break;
                   case 6:if(a[1][2]=='6')
                             a[1][2]=x;
                          else
                             flag=1;
                          break;
                   case 7:if(a[2][0]=='7')
                             a[2][0]=x;
                          else
                             flag=1;
                          break;
                   case 8:if(a[2][1]=='8')
                             a[2][1]=x;
                          else
                             flag=1;
                          break;
                   case 9:if(a[2][2]=='9')
                             a[2][2]=x;
                          else
                             flag=1;
                          break;
                   default:cout<<"sorry";//if position entered is out of bound
                            flag=1;
                           break;
                 }
            return flag;//returning flag value to variable l(main function body)
          }
//main function
int main()
 {
    int l;//variable to store return value from class member function
    game_chance player1;// derived class object
    for(int i=0;i<=10;i++)
    {
        player1.print();//friend function call to print current status of game
        player1.check();//friend function call to check whether any of player has won
        switch(i)//switch case to give alternate chances to player 1 & 2
          {
              //do while loop to give player chance till he enters correct position(overlapping included)
           case 1:do
                  l=player1.chance(1);
                  while(l==1);
                  break;
           case 2:do{
                    l=player1.chance(2);
                    }
                  while(l==1);
                 break;
           case 3:do
                  l=player1.chance(1);
                  while(l==1);
                  break;
           case 4:do{
                  l= player1.chance(2);
                  }
                  while(l==1);
                  break;
           case 5:do
                  l=player1.chance(1);
                  while(l==1);
                  break;
           case 6:do{
                  l= player1.chance(2);}
                  while(l==1);
                  break;
           case 7:do
                  l=player1.chance(1);
                  while(l==1);
                  break;
           case 8:do{
                  l= player1.chance(2);}
                  while(l==1);
                  break;
           case 9:do
                  l=player1.chance(1);
                  while(l==1);
                  break;
          }
       system("cls");//to clear screen
     }
     return 0;
  }
