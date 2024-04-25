#include<string>
#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;
class Hotel
{
    char name[50],address[50],phone[50];
    int room_no;
public:
    void add_customer();
    void Display();
    void modify();
    void delete_customer();
    void Exit();
    int getroom()
    {
        return room_no;
    }
}h;
int main()
{
    int ch=0,i;
    cout<<"\n\t\t=====================================";
    cout<<"\n\t\t       WELCOME TO HOTEL ROYALS";
    cout<<"\n\t\t=====================================\n";
    do
    {
        cout<<"\n\n\t\t\t MAIN MENU";
        cout<<"\n\t==================================================";
                cout<<"\n\t\tPress 1 to BOOK A ROOM";
                cout<<"\n\t\tPress 2 to DELETE CUSTOMER RECORD";
                cout<<"\n\t\tPress 3 to DISPLAY ALL ROOMS ALLOTTED";
                cout<<"\n\t\tPress 4 to Exit";
           cout<<"\n\t==================================================\n";
        cout<<"\n\n\t Enter your choice (1-4) : ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            system("cls");
            h.add_customer();
            break;
        case 2:
            system("cls");
            h.delete_customer();
            break;
        case 3:
            system("cls");
            h.Display();
            break;
        case 4:
            h.Exit();
            break;
        default:
            cout<<" ! Invalid Input...\n";
        }
    }
    while(ch!=4);
    return (0);
}
void Hotel::add_customer()
{
    int i;
    ofstream file;
    file.open("Hotel_record.txt", ios::app);
    cout<<"\n Enter Details \n";
    cout<<"===================\n";
    cout<<"\nEnter The Room Number: ";
        cin>>room_no;
        if(room_no==getroom())
        {
            cout<<"\nThis room is already booked.";

        }
        else
        {
            cout<<"\nEnter The Customer's name: ";
        fflush(stdin);
        cin.getline(name,30);
        cout<<"\nEnter The Customer's address: ";
        cin.getline(address,50);
        cout<<"\nEnter The Customer's phone : ";
        cin.getline(phone,10);
        file.write((char*)&h,sizeof(h));
        file.close();
        cout<<"\t\t\n\nCustomer details added Successfully...";
        }
}
void Hotel::Display()
{
    ifstream file;
    file.open("Hotel_record.txt", ios::in);
     file.seekg(0);
    if (!file)
    {
        cout << "\n\t...File not created !...";
        return;
    }
        cout<<"\n\n\t\tCUSTOMER LIST\n\n";
          cout<<"=============================================================================\n";
          cout<<"Room No  "<<"\t\t"<<"Name"<<"\t\t\t"<<"Address"<<"\t\t"<<"Phone"<<endl;
          cout<<"=============================================================================\n";
    while(file.read((char*)&h,sizeof(h)))
    {
       cout<<room_no<<"\t\t\t";
	 	cout<<name<<"\t\t ";
	 	cout<<address<<"\t\t\t\t";
	 	cout<<phone<<endl;
    }
    file.close();
    return;
}
void Hotel::delete_customer()
{
    ifstream file;
    file.open("Hotel_record.txt", ios::in);
    file.seekg(0);
    ofstream fout;
    fout.open("temp.txt",ios::out);
    int Target;
    int Found=0;
    if (!file)
    {
        cout << "\n\t...File not created...!";
        return;
    }
    Display();
    cout<<"\nEnter the room no to delete : ";
    cin>>Target;
    while(file.read((char*)&h,sizeof(h)))
    {
        if(Target!=room_no)
        {
            fout.write((char*)&h,sizeof(h));
        }
    }
    file.close();
    fout.close();
    remove("Hotel_record.txt");
    char oldname[] = "temp.txt";
    char newname[] = "Hotel_record.txt";/* Deletes the file if exists */
    if (rename(oldname, newname) != 0)
        cout<<"\n Error not find ";
    else
        cout << "\nSuccessfully Deleted !!!!!!";
        cout<<"\n--------------------------------------------------------------------------------------------------------------------------------------------\n";
}
void Hotel::Exit()
{
    system("cls");
    exit(0);
}
