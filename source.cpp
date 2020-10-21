using namespace std;
#include<iostream>
#include<conio.h>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
struct sona
{
	int id;
	char name[45];
	char contact[15];
	char email_id[45];
};
sona obj;

int getid()
{
	int id=0;
	sona obj;
	ifstream file("sona.dat",ios::binary);
	while(file)
	{
		file.read((char *)&obj,sizeof(obj));
		if(file.eof())
		break;
		
	}
	id=obj.id;
	id++;
	return id;
}
void readdata()
{
	cin.ignore();
	cout<<"\n\n\t\t--------------------------------------------------------------";
	cout<<"\n\n\t\t\t\tEnter the name:  ";
	cin.getline(obj.name,45);
	cout<<"\t\t\t\tEnter the contact number:  ";
	cin.getline(obj.contact,15);
	cout<<"\t\t\t\tEnter the email_id:  ";
	cin.getline(obj.email_id,45);
	obj.id=getid();
}
void add()
{
	system("color 40");
	readdata();
	ofstream file("sona.dat",ios::binary|ios::app);
	file.write((char *)&obj,sizeof(obj));
	cout<<"\n\n\t\t--------------------------------------------------------------";
	cout<<"\n\t\t\t\tYour Data saved successfully";
	getch();
}

void display()
{
    system("color Ad");
    cout<<"\n\t\t\t\t\t**************************************************\n\t\t\t\t\t\t\tHELLO FRNDS!\n\tWELCOMING YOU HERE.\n\tSONALI  IS VERY GLAD TO SEE U ON THIS PLACE.....";
    cout<<"\n\n\tHere you will be able to save the details like Name of a person, their contacts and email id"
	<<"\n\n\t-------------------------------------------------------------------------------------------------------------------";
    cout<<" \n\n\n\t\t\t\t\t....................RECORDS ARE .....................";
    cout<<"\n\n \t\tid"<<setw(28)<<"Name"<<setw(15)<<"Contact"<<setw(25)<<"Email_id";
    cout<<"\n\n\t\t***************************************************************************************";
	ifstream file("sona.dat",ios::binary);
	while(file)
	{
	
	    file.read((char *)&obj,sizeof(obj));
	    if(file.eof())
	        break;
	    cout<<"\n\n\t\t"<<obj.id<<"\t"<<setw(22)<<obj.name<<"\t"<<setw(15)<<obj.contact<<"    "<<setw(25)<<obj.email_id;
	}
	cout<<"\n\n\t\t***************************************************************************************";
	cout<<"\n\n\t-------------------------------------------------------------------------------------------------------------------\n";
	cout<<"\n\n\n\n\t\t\t\t Press Any key to continue.................\n\n";
	getch();

}
void delete1()
{
    system("color A1");
    sona obj;
    int data;
    int found=0;
    cout<<"Enter the data that you want to delete ";
     cin>>data;

    char con='n';
    ifstream file("sona.dat",ios::binary);
    ofstream fl("temp.dat",ios::binary|ios::out);
    while(file)
    {
        if(file.eof())
            break;
        file.read((char *)&obj,sizeof(obj));

    if(obj.id==data)
    {

        found=1;
        cout<<" Do you Want to delete (y/n)";
        cin>>con;
        if(con=='n' ||con=='N')
            fl.write((char *)&obj,sizeof(obj));
        break;
    }
    else
        fl.write((char *)&obj,sizeof(obj));

    }
    if(found==1)
    {
        while(file)
        {

            file.read((char *)&obj,sizeof(obj));
           if(file.eof())
            break;
            fl.write((char *)&obj,sizeof(obj));

        }
        fl.close();
        file.close();
        remove("sona.dat");
        rename("temp.dat","sona.dat");
        cout<<" Data Deleted Successfully ";

    }
    else
        cout<<" Data Not Found ";

      cout<<"\n\n\n\t Press Any key to Continueeeeeeeeeeee............";
      getch();

    }
    
    
void sonali()
{
    cout<<" \n\n\n\t\t................ Thanku  to visit My Program  .....................";
    cout<<"\n\n\n\n\n\n\n\n\n\n\t\t ................Press Any key to exit from program ............";
    system("color 2f");
    getch();
}


int main()
{
	
	char i='0';
	while(i!='5')
	{
		system("cls");
		system("color 81");
			cout<<"\n\t---------------------------------------------------------------------";
		    cout<<"\n\n\t 1-> For Add the Record";
		    cout<<"\n\n\t 2-> For Display the Record";
		    cout<<"\n\n\t 3-> For Delete the Record";
		    cout<<"\n\n\t 4-> For Exit";
		    cout<<"\n\n\t---------------------------------------------------------------------";
		    cout<<"\n\n\n\t Enter your choice ";
		    cin>>i;
		    switch(i)
		    {
		
		    case '1':
		    	system("cls");
		        add();
		        break;
		    case '2':
		    	system("cls");
		        display();
		        break;
		    case '3':
		    	system("cls");
			    delete1();
			    break;
		    case '4':
		    	system("cls");
		        sonali();
		        exit(1);
		        break;
		    default:
		        cout<<" Wrong choice Try Again !!!!!!\n\n\n\t Press Any Key to continue...........";
		        getch();
		    }
	}
	
	
}
