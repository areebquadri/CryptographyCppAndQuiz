#include<dos.h>
#include<iostream>
#include<fstream>
#include<ctype.h>
#include<cstring>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<windows.h>

#include<unordered_map>
#include<ctime>
#include <cstdlib>
#include <unistd.h>

using namespace std;
			   // by muhammad areeb quadri

//*************************************Cryptography-code*****************************
void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }



char keytxt[25];
// the encryption function
void cryptography(char infostr[],char keytxt[])
{
  
   unordered_map<char,char> abc_key;
   for(int i=0;i<26;i++){
    abc_key[char(int('a')+ i)]=keytxt[i];
   }

  cout<<endl;

  for(int i=0;i<strlen(infostr);i++)
  {
      cout<<abc_key[infostr[i]];
      
  }

  }

  void decodeit(char infostr[],char keytxt[])
{
  
    unordered_map<int,char> key_abc;
    for(int i=0;i<26;i++){
      key_abc[int(keytxt[i])] = char(int('a')+ i);
      
    }

  cout<<endl;
  //puts(keytxt);

  for(int i=0;i<strlen(infostr);i++)
  {
   
    cout<<key_abc[int(infostr[i])];

  }

  }

//***************************************------*****************************

//***************************************Quiz-code-begins*******************************************
 char ans;
  int chk[10]; int ret=0;

//This function extracts a ques. from a selected file. (for Quiz)

void extrque(int f)
{

 int guess,pick;
 int count=0;
 char c;

 come:
  srand((unsigned) time(0));
    int t = 1 + (rand() % 30);

 guess=t*198;       //3 line occupy 198 charspace

 if(f==1)
 {
    ifstream ext("nan.dat",ios::in);
    ext.seekg(0);
    ext.seekg(guess);
    ext.get(c);     //extracting ans which i have written in file
    ans=c;         //for getting answer of ques. from ans file.
    ext.seekg(guess+1);
     while(1)
    { ext.get(c);
      if(count==3)break;  //the whole ques and 4 opt occupy 3 lines in file
      if(c=='*')count++;
      else
    {
    cout<<c;
    }

    }
 }
 else if(f==2)
  {
   cout<<">>>>>>>>";
  }


  }
 

    char ex;

//This function play and calculate user result.

void play(int mc)
{
  system("cls");

  if(mc==1)

{    //........
   int zro=0;
   int one=0;
   char userans;
   char resp='y';
   int scboard[70];
   int k=0;
    int fru=0;

 while((fru!=10)&&(fru!=20)&&(fru!=30))
 {  begin:
    system("cls"); 
    
     gotoxy(25,5);
      cout<<"Q U E S T I O N: "<<(one+zro)+1;
      gotoxy(1,8);

     extrque(1);
     cout<<"\nEnter opion no.:";
     cin>>userans;
     if(userans==ans)
    {
     cout<<"\nYOU ARE RIGHT!";
     one++;
     scboard[k]=1;
     k++;

    }
    else
   {
     cout<<"\nIncorrect";
     usleep(1000000);
     cout<<"\nCorrect option is:"<<ans;
     zro++;
     scboard[k]=0;
     k++;
   }

  cout<<endl<<"ENTER y:";
  cin>>resp;
     fru++;

 }

 system("cls"); 
 usleep(500000);
 int run=(zro+one);
 cout<<"\n\n\n\tS C O R E\n\n\n";
 cout<<"Score board:";
 for(int d=0;d<run;d++)
  cout<<scboard[d]<<" ";
  cout<<endl<<endl;
 cout<<endl<<"Number of right answers:"<<one;
 cout<<endl<<"\n\nNumber of wrong answers:"<<zro;
 float perc=(float)(one*100)/run;
 cout<<endl<<"\n\nPercentage score:"<<perc<<"%";
//......
cout<<"\nenter y or Y to play again:";
cin>>ex;
if((ex=='y')||(ex=='Y'))
goto begin;

}
else         //******************Crpyptography-code-continues************************
if(mc==2)
{
  cout<<endl;
  int cho=0;
  int i,j;
  char inpkey[100];
  come:
  cout<<"1.ENCRYPT THE INFORMATION"<<endl;
  cout<<"2.DYCRYPT THE CIPHER"<<endl;
  cin>>cho;


   if(cho==1)

  {

    cout<<"\nGENERATE THE KEY:";
    cout<<"\nENTER YOUR KEY (Enter any word or phrase)MUST BE LONG:";
   // cout<<"\nas length of key directly proportional to security:\n ";
    cout<<"\n";
    cin>>inpkey;
				     int extr=0;
    for(i=0;inpkey[i]!='\0';i++)
   {

      for(j=i+1;j<strlen(inpkey);j++)
     {
       if(inpkey[i]==inpkey[j])
       {
       inpkey[j]='&';   extr++;
       }

     }
   }
     for(i=0;inpkey[i]!='\0';i++)
     {
      //cout<<inpkey[i];
     }
		int es=0;
    
     for(int q=0;q<(strlen(inpkey));q++)
     {
       if(inpkey[q]!='&')
       {
       keytxt[es]=inpkey[q];
       es++;
       }

     }
       cout<<endl;
       cout<<"\ntotal alphabets in your key:\n";
       for(int fj=0;keytxt[fj]!='\0';fj++)
       cout<<keytxt[fj];

    cout<<endl;
     char init='a';
     init=init+es;
     for(es;es<26;es++)
     {keytxt[es]=init;
     init++;
     }
	     char num=(char) '1';      // making encrption more complex for decoder
   for(int it=25;it>=0;it--)            
   {  for(int oi=0;oi<26;oi++)
      if((keytxt[oi]==keytxt[it])&&(oi!=it))
     { keytxt[it]=num;num++;
     }

   }


     cout<<endl<<"Final key(encrypted code can not be decrypted easily by brute force)";
    cout<<endl;
    int fj;
    for(fj=0;keytxt[fj]!='\0';fj++)
       cout<<keytxt[fj];


    //prompting user to enter the string that has to be encrypt
   usleep(1000000);
   char infostr[50];
   cout<<"\n\n\n\n\nEnter the information or string that has to be encrypt:";
   cout<<endl;
   cin>>infostr;
   cout<<endl<<"GENERATED CIPHER:\n";
   cryptography(infostr,keytxt);
   char back;
   cout<<"\n\nPress Enter then Press B or b to go back:";cin>>back;
   if(back=='b')
   goto come;


}
if(cho==2)
{ char infostr[50];
  cout<<"Enter the string to be decrypted:";
  cin>>infostr;
  cout<<endl<<"Enter the key to decrypt:";
  char enckey[100];
  cin>>enckey;

    for(int i=0;enckey[i]!='\0';i++)
   {

      for(int j=i+1;j<strlen(enckey);j++)
     {
       if(enckey[i]==enckey[j])
       {
       enckey[j]='&';
       }

     }
   }
		int es=0;
     for(int q=0;q<(strlen(enckey));q++)
     {
       if(enckey[q]!='&')
       {
       keytxt[es]=enckey[q];
       es++;
       }

     }
       cout<<endl;


    cout<<endl;
     char init='a';
     init=init+es;
     for(es;es<26;es++)
     {keytxt[es]=init;
     init++;
     }
	     char num=(char) '1';      // making encrption more complex for decoder
   for(int it=25;it>=0;it--)           // more no. of possibilities
   {  for(int oi=0;oi<26;oi++)
      if((keytxt[oi]==keytxt[it])&&(oi!=it))
     { keytxt[it]=num;num++;
     }

   }


      cout<<endl<<"THE ORIGINAL STRING IS:\n";
     decodeit(infostr,keytxt); char back;
     cout<<"\n\npress b to go back:";cin>>back;
     if(back=='b')
     goto come;

}

}
  //********************Cryptography-code-ends************************************
}


int main()
{

system("cls"); 
int ch,mc;
gotoxy(37,11);
cout<<"\n\t*********SELECT**********";
cout<<"\n1.QUIZ"<<"\n2.CRYPTOGRAPHY:CIPHER AND DECIPHER";
cout<<"\nENTER YOUR CHOICE:";
cin>>ch;
if(ch==1)
{
 system("cls");
 cout<<"\n\t\tQuiz Menu";
 cout<<"\n\t**********************";
 usleep(1000000);
  play(1);

}
else
{
 system("cls");
 play(2);

}

return 0;

}




