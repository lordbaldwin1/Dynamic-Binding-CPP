//Zachary Springer
//CS202
//Karla Fant
//The purpose of this program is to manage monsters as well as their defense and attack skills
//This is done with a BST to manage the different monsters and then an array of DLLs for the 
//monsters attacks and defenses. Dynamic binding is used as well as operator overloading
//The purpose of this specific file is to test the member functions of the classes in header.h
//which are writted in functions.cpp
#include "header.h"


int main()
{
    //Creating list objects
    bst my_bst;
    adll my_adll;

    //Variables to be passed into the create entry function
    //to be copied into dynamic memory

    char name[50];
    char active[50];
    char vfriends[50];
    char transform[50];
    char food[50];
    char zfriends[50];
    char wfriends[50];
    char mname[50];
    char siphon[50];
    char magic[50];
    char consume[50];
    char rip[50];
    char speed[50];
    char thrash[50];
    
    char searchname[50];

    int option = 0;
//Prompts to the user
    cout<<"1. Enter in a New Vampire"<<endl;
    cout<<"2. Remove a Monster"<<endl;
    cout<<"3. Display all Monsters"<<endl;
    cout<<"4. Retrieve information on a monster"<<endl;
    cout<<"5. Enter in a New Zombie"<<endl;
    cout<<"6. Enter in a New Werewolf"<<endl;
    cout<<endl;
    cout<<"7. Enter in a Vampire's stats"<<endl;
    cout<<"8. Enter in a Zombie's Stats"<<endl;
    cout<<"9. Enter in a Werewolf's Stats"<<endl;
    cout<<"10. Retrieve information on a monster's stats"<<endl;
    cout<<"11. Remove a Monster's Stats"<<endl;
    cout<<"12. Display All Monster's Skills"<<endl;

    cin>>option;
    cin.ignore(100, '\n');

    while(option >=1 && option <= 14)
    {
        if(option==1)
        {
            //Interting a new vampire
            monster * ptr = new vampire;

            cout<<"Vampire Name: ";
            cin.get(name, 50);
            cin.ignore(50, '\n');

            cout<<"When is this vampire active?: ";
            cin.get(active, 50);
            cin.ignore(50, '\n');

            cout<<"Who is this vampire friends with?: ";
            cin.get(vfriends, 50);
            cin.ignore(50, '\n');

            ptr->create_entry(name, active, vfriends);

            //my_bst.insert(name, ptr);
            my_bst += ptr; //overloaded operator

            //my_bst.display_all();
            cout<<my_bst; //overlaoded operator
        }
        if(option==2)
        {
            //Removing a monster of any type
            cout<<"Enter a Monster Name to Remove Them: ";
            cin.get(searchname, 50);
            cin.ignore(50, '\n');

            //my_bst.remove(searchname);
            my_bst -= searchname; //overloaded operator

            //my_bst.display_all();
            cout<<my_bst; //overloaded operator
        }
        if(option==3)
        {
            //Displays the entire bst
            //my_bst.display_all();
            cout<<my_bst; //overloaded operator
        }
        if(option==4)
        {
            //Retrieves a monster based on name
            cout<<"Enter a monster's name to retrieve information about them: ";
            cin.get(searchname, 50);
            cin.ignore(50, '\n');

            my_bst.retrieve(searchname);
        }
        if(option==5)
        {
            //Inserts a new zombie to the bst
            monster * ptr = new zombie;
            cout<<"Zombie Name: ";
            cin.get(name, 50);
            cin.ignore(50, '\n');

            cout<<"What is this zombie's favorite food?: ";
            cin.get(food, 50);
            cin.ignore(50, '\n');

            cout<<"Who is this zombie friends with?: ";
            cin.get(zfriends, 50);
            cin.ignore(50, '\n');

            ptr->create_entry(name, food, zfriends);

            //my_bst.insert(name, ptr);
            my_bst += ptr; //overloaded operator

            //my_bst.display_all();
            cout<<my_bst; //overloaded operator
        }
        if(option==6)
        {
            //Instert a new werewolf into the bst
            monster * ptr = new werewolf;
            cout<<"Werewolf Name: ";
            cin.get(name, 50);
            cin.ignore(50, '\n');

            cout<<"When does this werewolf transform?: ";
            cin.get(transform, 50);
            cin.ignore(50, '\n');

            cout<<"Who is this werewolf friends with?: ";
            cin.get(wfriends, 50);
            cin.ignore(50, '\n');

            ptr->create_entry(name, transform, wfriends);

            //my_bst.insert(name, ptr);
            my_bst += ptr; //overloaded operator

            //my_bst.display_all();
            cout<<my_bst; //overloaded operator
        }
        if(option==7)
        {
            //Inserts new vampire stats into the array of dlls
            monsterstats * sptr = new vstats;
            
            cout<<"Vampire Name: ";
            cin.get(mname, 50);
            cin.ignore(50, '\n');

            cout<<"What siphon abilities does this vampire have?: ";
            cin.get(siphon, 50);
            cin.ignore(50, '\n');

            cout<<"What other magic abilities does this vampire have?: ";
            cin.get(magic, 50);
            cin.ignore(50, '\n');

            sptr->create_entry(mname, siphon, magic);
            
            int index = 0;

            //my_adll.insert(index, sptr);
            my_adll += sptr; //overloaded operator

            //my_adll.display_all();
            cout<<my_adll; //overloaded operator
        }
        if(option == 8)
        {
            //Insert a new zombie into the array of dll
            monsterstats * sptr = new zstats;

            cout<<"Zombie Name: ";
            cin.get(mname, 50);
            cin.ignore(50, '\n');

            cout<<"What consume abilities does this zombie have?: ";
            cin.get(consume, 50);
            cin.ignore(50, '\n');

            cout<<"What rip abilities does this zombie have?: ";
            cin.get(rip, 50);
            cin.ignore(50, '\n');

            sptr->create_entry(mname, consume, rip);

            int index = 1;

            //my_adll.insert(index, sptr);
            my_adll += sptr; //overloaded operator

            //my_adll.display_all();
            cout<<my_adll; //overloaded operator
        }
        if(option == 9)
        {
            //Inserts a new werewolf into the array
            monsterstats * sptr = new wstats;

            cout<<"Werewolf Name: ";
            cin.get(mname, 50);
            cin.ignore(50, '\n');
            
            cout<<"What speed does this werewolf move at?: ";
            cin.get(speed, 50);
            cin.ignore(50, '\n');

            cout<<"What thrash abilities does this werewolf have?: ";
            cin.get(thrash, 50);
            cin.ignore(50, '\n');

            sptr->create_entry(mname, speed, thrash);

            int index = 2;

            //my_adll.insert(index, sptr);
            my_adll += sptr; //overloaded operator

            //my_adll.display_all();
            cout<<my_adll; //overloaded operator
        }
        if(option == 10)
        {
            //Retrieves a monsters stats based on name
            cout<<"Enter a monster's name to retrieve information about their stats: ";
            cin.get(searchname, 50);
            cin.ignore(50, '\n');

            my_adll.retrieve(searchname);
        }
        if(option==11)
        {
            //Removes any monsters stats
            cout<<"Enter a monster name to remove their stats: ";
            cin.get(searchname, 50);
            cin.ignore(50, '\n');

            //my_adll.remove(searchname);
            my_adll -= searchname; //overloaded operator

            //my_adll.display_all();
            cout<<my_adll; //overloaded operator
        }
        if(option==12)
        {
            //my_adll.display_all();
            cout<<my_adll; //overloaded operator
        }
        
        cout<<"1. Enter in a New Vampire"<<endl;
        cout<<"2. Remove a Monster"<<endl;
        cout<<"3. Display All Monsters"<<endl;
        cout<<"4. Retrieve information on a monster"<<endl;
        cout<<"5. Enter in a New Zombie"<<endl;
        cout<<"6. Enter in a New Werewolf"<<endl;
        cout<<endl;
        cout<<"7. Enter in a Vampire's Stats"<<endl;
        cout<<"8. Enter in a Zombie's Stats"<<endl;
        cout<<"9. Enter in a Werewolf's Stats"<<endl;
        cout<<"10. Retrieve information on a monster's stats"<<endl;
        cout<<"11. Remove a Monster's Stats"<<endl;
        cout<<"12. Display All Monster's Skills"<<endl;

        cin>>option;
        cin.ignore(100, '\n');
        cout<<endl;
    }

return 0;
}
