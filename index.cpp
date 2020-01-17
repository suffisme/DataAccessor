#include<fstream>
#include<stdio.h>
#include<iostream>
#include<cstring>

using namespace std;
class STUDENT
{int ST_ID;
char ST_Name[50];
float ST_Marks;
public:
int GETST_ID()
{return ST_ID;
}
void ReadDetails()
{cout<<"Enter Student ID \n";
cin>>ST_ID;
cout<<"Enter Name of Student \n";
gets(ST_Name);
cout<<"Enter Marks \n";
cin>>ST_Marks;
}
void ShowDetails()
{cout<<"ID student "<<ST_ID<<endl;
cout<<"Student Name "<<ST_Name<<endl;
cout<<"Student Marks "<<ST_Marks<<endl;}
void ADDRECORD()
{fstream fin;
fin.open("Student.dat",ios::in|ios::binary|ios::app);
STUDENT S;
S.ReadDetails();
fin.write((char*)&S,sizeof(S));;
fin.close();
}
void SEARCH(int id)
{ STUDENT S;
int flag=0;
fstream fin;
fin.open("Student.dat",ios::in|ios::binary|ios::app) ;
while(fin.read((char*)&S,sizeof(S)))
{
if(id==S.GETST_ID())

{S.ShowDetails();
cout<<endl;
flag=1;
}
} fin.close();
if(flag!=1) cout<<"No match Found";
}
void DELETE()
{int dID,choice3;
STUDENT S;
label2:
cout<<"Enter The Student ID whose record is to be DELETED \n";
cin>>dID;
fstream fin2;
fin2.open("temp.dat",ios::out|ios::binary|ios::in|ios::app);
fstream fin;
fin.open("Student.dat",ios::in|ios::binary|ios::app);
while(fin.read((char*)&S,sizeof(S)))
{ if(dID==S.GETST_ID())
{S.ShowDetails();
}
else
fin2.write((char*)&S,sizeof(S)) ;
}
cout<<"Do You Want to continue (1 for YES and 0 for NO) \n";
cin>>choice3;
if(choice3==0)
{ goto label2;
} else if(choice3==1)
{
fin2.close();
fin.close();
remove("Student.dat");
rename("temp.dat","Student.dat");
ShowRecord();
}
}
void MODIFY()
{
cout<<"Enter new details "<<endl;
int NewID;

char Newname[20];
float Newmarks;
cout<<"Enter new Student ID"<<endl;
cin>>NewID;
cout<<"Enter new Student's name"<<endl;
gets(Newname);
cout<<"Enter new Student's marks"<<endl;
cin>>Newmarks;
ST_ID=NewID;
strcpy(ST_Name,Newname);
ST_Marks=Newmarks;
}
};
void ShowRecord()
{STUDENT S;
fstream fin;
fin.open("Student.dat",ios::in|ios::binary|ios::app) ;
while(fin.read((char*)&S,sizeof(S)))
{S.ShowDetails();
cout<<endl;
} fin.close();
}
int main()
{label:
STUDENT S;
int choice,sID;
char choice2;
cout<<"Enter Your Choice"<<endl;
cout<<"1.Add Record of Student \n 2.Search for Student \n 3. Delete a particular record \n 4.Modify
a record "<<endl;
cin>>choice;
if(choice==1)
{
S.ADDRECORD();
cout<<"Do you want to see all records (Y) \n";
cin>>choice2;
if(choice2=='Y' || choice2=='y')
ShowRecord();
cout<<endl;

goto label;
}
else
if(choice==2)
{ cout<<"Enter the Student ID "<<endl;
cin>>sID;
S.SEARCH(sID);
cout<<endl;
goto label;
}
else
if(choice==3)
{ S.DELETE();
cout<<endl;

goto label;
}
else
if (choice==4)
{
fstream fin;
fin.open("Student.dat",ios::in|ios::out|ios::binary|ios::app);
fin.seekg(0);
int MID,location;
cout<<"Enter id to modify "<<endl;
cin>>MID;
while(fin.read((char*)&S,sizeof(S)))
{location=fin.tellg();
if(MID==S.GETST_ID())
{ S.MODIFY();
fin.seekg(location);
fin.write((char*)&S,sizeof(S));
}
}
fin.close();
ShowRecord();
cout<<endl;

goto label;
}
else return 0;
}
