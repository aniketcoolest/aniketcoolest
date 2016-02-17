#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<iostream.h>
#include<fstream.h>
#include<string.h>

class student
{
	public: char name[10];
		char usn[10];
		char age[5];
		char sem[5];
		char branch[5];
		char buffer[45];
};

fstream file;
student s;

void writerecord()
{
	file.open("student.txt",ios::app);
	if(!file)
	{
		cout<<"cannot open the file in append mode";
		exit(1);
	}
	cout<<"\nenter the student name = ";
	cin>>s.name;
	cout<<"\nenter the usn = ";
	cin>>s.usn;
	cout<<"\nenter the age = ";
	cin>>s.age;
	cout<<"\nenter the sem = ";
	cin>>s.sem;
	cout<<"\nenter the branch = ";
	cin>>s.branch;
	//packing the information
	strcpy(s.buffer,s.name);
	strcat(s.buffer,"|");
	strcat(s.buffer,s.usn);
	strcat(s.buffer,"|");
	strcat(s.buffer,s.age);
	strcat(s.buffer,"|");
	strcat(s.buffer,s.sem);
	strcat(s.buffer,"|");
	strcat(s.buffer,s.branch);

	int count=strlen(s.buffer);
	for(int k=0;k<45-count;k++)
		strcat(s.buffer,"!");
	strcat(s.buffer,"\n");
	file<<s.buffer;  //writing the packed information to buffer
	file.close();
}

void search()
{
	char usn[10];
	char extra[45];
	file.open("student.txt",ios::in);
	if(!file)
	{
		cout<<"\nunable to open the file in read mode";
		exit(0);
	}
	cout<<"\nenter the record's usn you want to search = ";
	cin>>usn;

	//unpacking the record

	while(!file.eof())
	{
		file.getline(s.name,10,'|');
		file.getline(s.usn,10,'|');
		file.getline(s.age,5,'|');
		file.getline(s.sem,5,'|');
		file.getline(s.branch,5,'!');
		file.getline(extra,45,'\n');

		if(strcmp(s.usn,usn)==0)
		{
			cout<<"\nrecord found";
			cout<<"\n"<<s.name<<"\t"<<s.usn<<"\t";
			cout<<s.age<<"\t"<<s.sem<<"\t"<<s.branch;
			file.close();
			getch();
			return;
		}
	}
	cout<<"\nrecord not found";
	file.close();
	getch();
}

void displayFile()
{
	int i;
	char extra[45];
	file.open("student.txt",ios::in);

	if(!file)
	{
		cout<<"\ncannot open the file in read mode";
		getch();
		exit(1);
	}
	i=0;
	cout<<"\n\nNAME\t\tUSN\t\tAGE\t\tSEM\t\tBRANCH\n";
	cout<<"----\t\t---\t\t---\t\t---\t\t------\n";

	while(!file.eof())
	{
		file.getline(s.name,10,'|');
		file.getline(s.usn,10,'|');
		file.getline(s.age,5,'|');
		file.getline(s.sem,5,'|');
		file.getline(s.branch,5,'!');
		file.getline(extra,45,'\n');
		printf("\n%s\t\t%s\t\t%s\t\t%s\t\t%s",s.name,s.usn,s.age,s.sem,s.branch);
		i++;
	}
	file.close();
	getch();
}

void modify()
{
	char usn[10];
	char buffer[45];
	char extra[45];
	int i;
	int j;
	student s[20];

	file.open("student.txt",ios::in);
	if(!file)
	{
		cout<<"\nunable to open the file in input mode";
		getch();
		exit(1);
	}
	cout<<"\nenter the usn of the record to be modified\n";
	cin>>usn;
	cout<<"\n";

	i=0;
	while(!file.eof())
	{
		file.getline(s[i].name,10,'|');
		file.getline(s[i].usn,10,'|');
		file.getline(s[i].age,5,'|');
		file.getline(s[i].sem,5,'|');
		file.getline(s[i].branch,5,'!');
		file.getline(extra,45,'\n');
		i++;
	}
	i--;

	for(j=0;j<i;j++)
	{
		if(strcmp(usn,s[j].usn)==0)
		{
			cout<<"\nthe old values of the record with usn"<<usn<<"are";
			cout<<"\nname = "<<s[j].name;
			cout<<"\nusn = "<<s[j].usn;
			cout<<"\nage = "<<s[j].age;
			cout<<"\nsem = "<<s[j].sem;
			cout<<"\nbranch = "<<s[j].branch;

			cout<<"\n\nenter the new values\n";
			cout<<"\nname = ";
			cin>>s[j].name;
			cout<<"\nusn = ";
			cin>>s[j].usn;
			cout<<"\nage = ";
			cin>>s[j].age;
			cout<<"\nsem = ";
			cin>>s[j].sem;
			cout<<"\nbranch = ";
			cin>>s[j].branch;
			break;
		}
	}

	if(j==i)
	{
		cout<<"\nthe record with usn " <<usn<< "is not present ";
		getch();
		return;
	}
	file.close();

	file.open("student.txt",ios::out);
	if(!file)
	{
		cout<<"\nunable to open the file in output mode";
		getch();
		return;
	}

	for(j=0;j<i;j++)
	{
		strcpy(buffer,s[j].name);
		strcat(buffer,"|");
		strcat(buffer,s[j].usn);
		strcat(buffer,"|");
		strcat(buffer,s[j].age);
		strcat(buffer,"|");
		strcat(buffer,s[j].sem);
		strcat(buffer,"|");
		strcat(buffer,s[j].branch);

		int count=strlen(buffer);
		for(int k=0;k<45-count;k++)
			strcat(buffer,"!");
		strcat(buffer,"\n");
		file<<buffer;
	}
	file.close();
}

void main()
{
	int choice;
	while(1)
	{
		clrscr();
		cout<<"\n 0 : exit";
		cout<<"\n 1 : write to file";
		cout<<"\n 2 : display the file";
		cout<<"\n 3 : modify the file";
		cout<<"\n 4 : search";
		cout<<"\n\n enter the choice : ";
		cin>>choice;

		switch(choice)
		{
			case 1: writerecord();
				break;

			case 2: displayFile();
				break;

			case 3: modify();
				break;

			case 4: search();
				break;

			case 0: exit(0);

			default:cout<<"\ninvalid input...";
				break;
		}
	}
}
