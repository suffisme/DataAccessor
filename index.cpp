#include<bits/stdc++.h>

using namespace std;

void ShowRecord();

class STUDENT
{int ST_ID;
char ST_Name[50];
float ST_Marks;
public:
int GETST_ID()
{return ST_ID;
}
void ReadDetails()
{cout<<"\tEnter Student ID : ";
cin>>ST_ID;
cout<<" \tEnter Name of Student (Separated by Underscore) : ";
cin>>ST_Name;
cout<<"\tEnter SGPA : ";
cin>>ST_Marks;
}

void ShowDetails()
{
cout<<"\tID student : "<<ST_ID<<"\n";
cout<<"\tStudent Name : "<<ST_Name<<"\n";
cout<<"\tStudent SGPA : "<<ST_Marks<<"\n";
}

void ADDRECORD()
{
fstream fin;
fin.open("Student.dat",ios::in|ios::binary|ios::app);
STUDENT S;
S.ReadDetails();
fin.write((char*)&S,sizeof(S));;
fin.close();
}


void SEARCH(int id)
{ 
STUDENT S;
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
if(flag!=1) cout<<"\t***No match Found***";
}

void DELETE()
{int dID,choice3;
STUDENT S;
int ff=0;
label2:
cout<<"\tEnter The Student ID whose record is to be DELETED : ";
cin>>dID;
fstream fin2;
fin2.open("temp.dat",ios::out|ios::binary|ios::in|ios::app);
fstream fin;
fin.open("Student.dat",ios::in|ios::binary|ios::app);
while(fin.read((char*)&S,sizeof(S)))
{ if(dID==S.GETST_ID())
{ cout<<"\n\tDATA FOUND : "<<endl;
ff=1;
S.ShowDetails();
}
else
fin2.write((char*)&S,sizeof(S)) ;
}
if(ff==0)
{
cout<<"\n\tDATA NOT FOUND\n\n";
}
else
{
cout<<"\n\tDo You Want to continue (1 for YES and 0 for NO) : ";
cin>>choice3;
if(choice3==1)
{
fin2.close();
fin.close();
remove("Student.dat");
rename("temp.dat","Student.dat");
cout<<endl;
}
}
}
void MODIFY()
{
cout<<"\tEnter new details \n\n";
int NewID;

char Newname[20];
float Newmarks;
cout<<"\tEnter new Student ID : ";
cin>>NewID;
cout<<"\tEnter new Student's Name : ";
cin.getline(Newname,20);
cout<<"\tEnter new Student's SGPA : ";
cin>>Newmarks;
ST_ID=NewID;
strcpy(ST_Name,Newname);
ST_Marks=Newmarks;
}
};
void ShowRecord()
{STUDENT S;
fstream fin;
int ff=0;
fin.open("Student.dat",ios::in|ios::binary|ios::app) ;

while(fin.read((char*)&S,sizeof(S)))
{
	ff=1;
S.ShowDetails();
cout<<endl;
} fin.close();
if(ff==0)
cout<<"\tNO DATA FOR NOW\n";
}
int main()
{
	cout<<"\t\t***STUDENT'S RECORD***\n";
label:
STUDENT S;
int choice,sID;
char choice2;
cout<<"\tEnter Your Choice"<<endl;
cout<<"\t1.Add Record of Student \n\t2.Search for Student \n\t3. Delete a particular record \n\t4.Modify a record \n\t5. See All Records\n\t";
cin>>choice;
if(choice==1)
{
S.ADDRECORD();
cout<<"\tDo you want to see all records (Y) : ";
cin>>choice2;
if(choice2=='Y' || choice2=='y')
ShowRecord();
cout<<endl;
cout<<endl<<endl;
goto label;
}
else
if(choice==2)
{ cout<<"\tEnter the Student ID : ";
cin>>sID;
S.SEARCH(sID);
cout<<endl;cout<<endl<<endl;
goto label;
}
else
if(choice==3)
{ S.DELETE();
cout<<endl;
cout<<endl<<endl;
goto label;
}
else
if (choice==4)
{
fstream fin;
fin.open("Student.dat",ios::in|ios::out|ios::binary|ios::app);
fin.seekg(0);
int MID,location;
cout<<"\tEnter id to modify : ";
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
cout<<endl<<endl;
goto label;
}
else if(choice==5)
{
ShowRecord();
cout<<endl<<endl;
goto label;
}else  return 0;
}
