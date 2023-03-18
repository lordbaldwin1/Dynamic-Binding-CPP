//Zachary Springer
//This file is for the classes member functions
//These functions are called in main and the classes which
//hold these functions are in header.h

#include "header.h"
//Constructor for the base class
monster::monster()
{
    left = NULL;
    right = NULL;
    name = NULL;
}
//Destructor for the base class
monster::~monster()
{
    delete name;
}
//Constructor for the vampire derived class
vampire::vampire()
{
    name = NULL;
    active = NULL;
    vfriends = NULL;
}
//Destructor for the vampire derived class
vampire::~vampire()
{
    //I just set them to NULL here instead of deleting because
    //I have a delete_entry function that I call to delete the 
    //data within an object in my remove functions 
    //as well as my destructor
    name = NULL;
    active = NULL;
    vfriends = NULL;
}
//constructor for the zombie derived class
zombie::zombie()
{
    name = NULL;
    food = NULL;
    zfriends = NULL;
}
//destructor for the zombie derived class
zombie::~zombie()
{
    name = NULL;
    food = NULL;
    zfriends = NULL;
}
//constructor for the zombie derived class
werewolf::werewolf()
{
    name = NULL;
    transform = NULL;
    wfriends = NULL;
}
//destructor for the werewolf derived class
werewolf::~werewolf()
{
    name = NULL;
    transform = NULL;
    wfriends = NULL;
}
//assignment operator for the vampire class
//since it manages dynamic memory
vampire & vampire::operator=(const vampire & v2)
{
    if(this == &v2) //checks for self assignment
        return *this;
    if(name) //if there is already data delete it so no memory leaks
        delete [] name;
    name = new char[strlen(v2.name)+1]; //then perform a deep copy1
    strcpy(name, v2.name);

    if(active)
        delete [] active;
    active = new char[strlen(v2.active)+1];
    strcpy(active, v2.active);

    if(vfriends)
        delete [] vfriends;
    vfriends = new char[strlen(v2.vfriends)+1];
    strcpy(vfriends, v2.vfriends);

    return *this;
}
//assignment operator for the zombie class
//since it manages dynamic memory
zombie & zombie::operator=(const zombie & z2)
{
    if(this == &z2)
        return *this;
    if(name)
        delete [] name;
    name = new char[strlen(z2.name)+1];
    strcpy(name, z2.name);

    if(food)
        delete [] food;
    food = new char[strlen(z2.food)+1];
    strcpy(food, z2.food);

    if(zfriends)
        delete [] zfriends;
    zfriends = new char[strlen(z2.zfriends)+1];
    strcpy(zfriends, z2.zfriends);

    return *this;
}
//assignment operator for the werewolf class
//since it manages dynamic memory
werewolf & werewolf::operator=(const werewolf & w2)
{
    if(this == &w2)
        return *this;
    if(name)
        delete [] name;
    name = new char[strlen(w2.name)+1];
    strcpy(name, w2.name);

    if(transform)
        delete [] transform;
    transform = new char[strlen(w2.transform)+1];
    strcpy(transform, w2.transform);

    if(wfriends)
        delete [] wfriends;
    wfriends = new char[strlen(w2.wfriends)+1];
    strcpy(wfriends, w2.wfriends);

    return *this;
}
//copy constructor for the vampire class
vampire::vampire(const vampire & copy_from)
{
    name = new char[strlen(copy_from.name)+1]; //just performs a deep copy for all of vampires data
    strcpy(name, copy_from.name);

    active = new char[strlen(copy_from.active)+1];
    strcpy(active, copy_from.name);

    vfriends = new char[strlen(copy_from.vfriends)+1];
    strcpy(vfriends, copy_from.vfriends);
}
//copy constructor for the zopmbioe class
zombie::zombie(const zombie & copy_from)
{
    name = new char[strlen(copy_from.name)+1];
    strcpy(name, copy_from.name);

    food = new char[strlen(copy_from.food)+1];
    strcpy(food, copy_from.food);

    zfriends = new char[strlen(copy_from.zfriends)+1];
    strcpy(zfriends, copy_from.zfriends);
}
//copy constructor for the werewolf class
werewolf::werewolf(const werewolf & copy_from)
{
    name = new char[strlen(copy_from.name)+1];
    strcpy(name, copy_from.name);

    transform = new char[strlen(copy_from.transform)+1];
    strcpy(transform, copy_from.transform);

    wfriends = new char[strlen(copy_from.wfriends)+1];
    strcpy(wfriends, copy_from.wfriends);
}
//used to connect up nodes in the bst
void monster::connectleft(monster * connection)
{
    left = connection; //sets left to a passed in pointer
}
//used to connect up nodes in the bst
void monster::connectright(monster * connection)
{
    right = connection; //sets reight to a p[aseed in pointer
}
//getter for bst left pointer
monster *& monster::goleft()
{
    return left; //returns left pointer
}
//getter for bst right pointer
monster *& monster::goright()
{
    return right; //returns right pointer
}
//Copy Constructor for BST just a wrapper for the copy tree function
bst::bst(const bst & source)
{
    monster * destroot = NULL;
    copy_tree(source.root, destroot);
}
//Copy tree functioin which cop[ies the entire bst
void bst::copy_tree(monster * root, monster *& destroot)
{
    if(!root)
        destroot = NULL;
    else
    {
        destroot = root->newmonster(); //create a new object of the correct type
        destroot->copy_const(root); //copy the data
        copy_tree(root->goleft(), destroot->goleft()); //traverse
        copy_tree(root->goright(), destroot->goright()); //traverse
    }
    return;
}
//creates a new vampire object
monster * vampire::newmonster()
{
    return new vampire; //returns a new vamp[ire object
}
//copies data for the new vampire objhect
int vampire::copy_const(monster * root)
{
    name = new char[strlen(root->getname())+1]; //performs a deep copy
    strcpy(name, root->getname());

    active = new char[strlen(root->getname())+1];
    strcpy(active, root->getname());

    vfriends = new char[strlen(root->getname())+1];
    strcpy(vfriends, root->getname());
    return 1;
}
//getter for the name of a monster
char * monster::getname()
{
    return name; //returns the name
}
//creates a new zombie object and returns it
monster * zombie::newmonster()
{
    return new zombie;
}
//copies zombie data for the copy constructor
int zombie::copy_const(monster * root)
{
    name = new char[strlen(root->getname())+1];
    strcpy(name, root->getname());

    food = new char[strlen(root->getname())+1];
    strcpy(food, root->getname());

    zfriends = new char[strlen(root->getname())+1];
    strcpy(zfriends, root->getname());

    return 1;
}
//creates a new werewolf object
monster * werewolf::newmonster()
{
    return new werewolf;
}
//copies werewolf data for the copy constructor
int werewolf::copy_const(monster * root)
{
    name = new char[strlen(root->getname())+1];
    strcpy(name , root->getname());

    transform = new char[strlen(root->getname())+1];
    strcpy(transform, root->getname());

    wfriends = new char[strlen(root->getname())+1];
    strcpy(wfriends, root->getname());

    return 1;
}
    

//copies data into a vampire pointer to make it ready to be inserted
int vampire::create_entry(char * vampirename, char * vampireactive, char * vampirefriends)
{
    name = new char[strlen(vampirename)+1]; //just performs a deep copy
    strcpy(name, vampirename);

    active = new char[strlen(vampireactive)+1];
    strcpy(active, vampireactive);

    vfriends = new char[strlen(vampirefriends)+1];
    strcpy(vfriends, vampirefriends);

    return 1;
}
//the same as the last but for zombie
int zombie::create_entry(char * zombiename, char * zombiefood, char * zombiefriends)
{
    name = new char[strlen(zombiename)+1];
    strcpy(name, zombiename);

    food = new char[strlen(zombiefood)+1];
    strcpy(food, zombiefood);

    zfriends = new char[strlen(zombiefriends)+1];
    strcpy(zfriends, zombiefriends);
    return 1;
}
//the same as the last but for werewolf
int werewolf::create_entry(char * werename, char * weretransform, char * werefriends)
{
    name = new char[strlen(werename)+1];
    strcpy(name, werename);

    transform = new char[strlen(weretransform)+1];
    strcpy(transform, weretransform);

    wfriends = new char[strlen(werefriends)+1];
    strcpy(wfriends, werefriends);
    return 1;
}
//displays a vampires data
int vampire::display()
{
    cout<<"Vampire Name: "<<name<<endl; //simply outputs the data
    cout<<"Vampire Activity Time: "<<active<<endl;
    cout<<"Vampire Friends: "<<vfriends<<endl;
    cout<<endl;
    return 1;
}
//displays a zombies data
int zombie::display()
{
    cout<<"Zombie Name: "<<name<<endl;
    cout<<"Zombie's Favorite Food: "<<food<<endl;
    cout<<"Zombie's Friends: "<<zfriends<<endl;
    cout<<endl;
    return 1;
}
//displays a werewolfs data
int werewolf::display()
{
    cout<<"Werewolf Name: "<<name<<endl;
    cout<<"When this werewolf transforms: "<<transform<<endl;
    cout<<"Werewolf's Friends: "<<wfriends<<endl;
    cout<<endl;
    return 1;
}
//deletes a vampired data
int vampire::delete_entry()
{
    delete [] name; //simply deletes the data
    delete [] active;
    delete [] vfriends;
    return 1;
}
//deletes a zoimbies data
int zombie::delete_entry()
{
    delete [] name;
    delete [] food;
    delete [] zfriends;
    return 1;
}
//deletes a werewolfs data
int werewolf::delete_entry()
{
    delete [] name;
    delete [] transform;
    delete [] wfriends;
    return 1;
}
//constructor for the bst class just setting root to NULL
bst::bst()
{
    root = NULL;
}
//destructor for the bst which acts as a wrapper to the remove_all nodes function
bst::~bst()
{
    remove_all(root);
}
//removes all nodes from the bsts
int bst::remove_all(monster *& root)
{
    if(!root) return 0;

    remove_all(root->goleft()); //traverses through the list

    remove_all(root->goright());

    root->delete_entry(); //deletes the entry, then deletes the node, then sets the previous next pointer to null
    delete root;
    root = NULL;

    return 1;
}
//+= operator for the bst which inserts a passed in ptr into the tree
bst & bst::operator+=(monster * ptr)
{
    cout<<"re-enter the name of the monster (case sensitive, sorry this is poorly designed): "; //this is designed very poorly but I wasn't sure how else to get 
    char searchname[50];                                                                        //the name into the insert function to traverse the BST
    cin.get(searchname, 50);
    cin.ignore(50, '\n');

    insert(searchname, ptr); //calls the insert function
    return *this;
}
 //wrapper for insert function   
int bst::insert(char * searchname, monster * ptr)
{
    return insert(searchname, root, ptr);
}
//traverses to the correct spot and inserts the passed in pointer to the list
int bst::insert(char * searchname, monster *& root, monster * ptr)
{
    if(!root)
    {
        root = ptr; //if at the right spot connect up the list
        root->connectleft(NULL);
        root->connectright(NULL);
        return 1;
    }
    if(root->comparename(searchname)) //binary search
        insert(searchname, root->goleft(), ptr);
    else
        insert(searchname, root->goright(), ptr);
    return 1;
}
//comparison function for the binary search tree traversal
int monster::comparename(char * searchname)
{
    if(strcmp(searchname, name) < 0)
        return 1;
    else
        return 0;
}
//output operator to display the entire bst
ostream & operator<<(ostream &o, bst & my_bst)
{
    my_bst.display_all();
    return o;
}
//display all functionm wrapper
int bst::display_all()
{
    if(!root) return 0; //if theres no list get out!
    return display_all(root);
}
//display all function that loops through and displays in order
int bst::display_all(monster * root)
{
    if(!root) return 0;

    display_all(root->goleft());
    root->display();
    display_all(root->goright());
    return 1;
}
//compare function to see if there is a match in order to remove it
int monster::compareremove(char * searchname)
{
    if(strcmp(searchname, name)==0)
        return 1;
    else
        return 0;
}
/*
int vampire::copy_entry(monster *& copy_from)
{
    if(!copy_from) return 0;

    if(name)
        delete [] name;
    name = new char[strlen(copy_from->name)+1];
    strcpy(name, copy_from->name);

    if(active)
        delete [] active;
    active = new char[strlen(copy_from->active)+1];
    strcpy(name, copy_from->active);

    if(vfriends)
        delete [] vfriends;
    vfriends = new char[strlen(copy_from->vfriends)+1];
    strcpy(name, copy_from->vfriends);

    return 1;
}
*/
//-= operator to remove from the bst
bst & bst::operator-=(char  * searchname)
{
    remove(searchname);//calls the remove function passing in searchname
    return *this;
}
//remove function for the bst wrapper
int bst::remove(char * searchname)
{
    if(!root) return 0;

    return remove(searchname, root);
}
//goes through to find a match in the bst then removes it
//this function is sort of incomplete because I couldn't figure out how to handle the
//in order successor as it applies to dynamic binding since the in order successor
//could be a different class object than the node being removed
int bst::remove(char * searchname, monster *& root)
{
        if(!root) return 0;
        remove(searchname, root->goleft()); //traverse the list

        remove(searchname, root->goright());

        if(root->compareremove(searchname)) //if there is a match
        {
            if(!root->goleft() && !root->goright()) //if left is null and right is null
            {
                root->delete_entry();
                delete root;
                root = NULL;
            }
            else if(!root->goright() && root->goleft()) //if right is null but left isnt
            {
                monster * hold = root->goleft();
                root->delete_entry();
                delete root;
                root = hold;
            }
            else if(!root->goleft() && root->goright()) //if left is null but right isnt
            {
                monster * hold = root->goright();
                root->delete_entry();
                delete root;
                root = hold;
            }
            /*
            else
            {
                monster * current = root->goright();
                if(!current->goleft() && !current->goright())
                {
                    root->copy_entry(current);
                    root->goright()->delete_entry();
                    delete root->goright();
                    root->connectright(NULL);
                }
                else if(!current->goleft() && current->goright())
                {
                    root->copy_entry(current);
                    monster * hold = current->goright();
                    root->goright()->delete_entry();
                    delete root->goright();
                    root->connectright(hold);
                }
                else
                {
                    monster * prev;
                    while(current->goleft())
                    {
                        prev = current;
                        current = current->goleft();
                    }
                    monster * hold = current->goright();
                    root->copy_entry(current);
                    current->delete_entry();
                    delete current;
                    prev->connectleft(hold);
                }
            }
            */
        }
        return 1;
}
//Retrieve function wrapper
int bst::retrieve(char * searchname)
{
    if(!root) return 0;

    return retrieve(searchname, root);
}
//Retrieve function that takes in a searchname and displays anything that matches the name
int bst::retrieve(char * searchname, monster * root)
{
    if(!root) return 0;

    if(root->compareremove(searchname)) //if there is a match
    {
        cout<<"Match found!"<<endl; //display it
        root->display();
    }

    retrieve(searchname, root->goleft());
    retrieve(searchname, root->goright());

    return 1;
}
//--------------MONSTER STATS FUNCTIONS-----------------
//NOTE!: most of these functions are very similar so I'm going
//to just comment on functions that are different from ones that
//have already been explained

//These constructors and destructors are the same as the previous ones
monsterstats::monsterstats()
{
    next = NULL;
    prev = NULL;
    mname = NULL;
}
monsterstats::~monsterstats()
{
    delete mname;
}
vstats::vstats()
{
    mname = NULL;
    siphon = NULL;
    magic = NULL;
}
vstats::~vstats()
{
    mname = NULL;
    siphon = NULL;
    magic = NULL;
}
zstats::zstats()
{
    mname = NULL;
    consume = NULL;
    rip = NULL;
}
zstats::~zstats()
{
    mname = NULL;
    consume = NULL;
    rip = NULL;
}
wstats::wstats()
{
    mname = NULL;
    speed = NULL;
    thrash = NULL;
}
wstats::~wstats()
{
    mname = NULL;
    speed = NULL;
    thrash = NULL;
}
//These copy constructors are the same as the previous ones
vstats::vstats(const vstats & copy_from)
{
    mname = new char[strlen(copy_from.mname)+1];
    strcpy(mname, copy_from.mname);

    siphon = new char[strlen(copy_from.siphon)+1];
    strcpy(siphon, copy_from.siphon);

    magic = new char[strlen(copy_from.magic)+1];
    strcpy(magic, copy_from.magic);
}
zstats::zstats(const zstats & copy_from)
{
    mname = new char[strlen(copy_from.mname)+1];
    strcpy(mname, copy_from.mname);

    consume = new char[strlen(copy_from.consume)+1];
    strcpy(consume, copy_from.consume);

    rip = new char[strlen(copy_from.rip)+1];
    strcpy(rip, copy_from.rip);
}
wstats::wstats(const wstats & copy_from)
{
    mname = new char[strlen(copy_from.mname)+1];
    strcpy(mname, copy_from.mname);

    speed = new char[strlen(copy_from.speed)+1];
    strcpy(speed, copy_from.speed);

    thrash = new char[strlen(copy_from.thrash)+1];
    strcpy(thrash, copy_from.thrash);
}
//These setters and getters are the same as the previous ones
//except that now they are for prev and next instead of
//left and right
void monsterstats::connectnext(monsterstats * connection)
{
    next = connection;
}
void monsterstats::connectprev(monsterstats * connection)
{
    prev = connection;
}
monsterstats *& monsterstats::goprev()
{
    return prev;
}
monsterstats *& monsterstats::gonext()
{
    return next;
}
//same as last, checks for a match
int monsterstats::compareremove(char * searchname)
{
    if(strcmp(searchname, mname)==0)
        return 1;
    else
        return 0;
}
//These create entry do the same as the previous ones, deep copy into pointer
//to be passed into insert function
int vstats::create_entry(char * vname, char * vsiphon, char * vmagic)
{
    mname = new char[strlen(vname)+1];
    strcpy(mname, vname);

    siphon = new char[strlen(vsiphon)+1];
    strcpy(siphon, vsiphon);

    magic = new char[strlen(vmagic)+1];
    strcpy(magic, vmagic);

    return 1;
}
int zstats::create_entry(char * zname, char * zconsume, char * zrip)
{
    mname = new char[strlen(zname)+1];
    strcpy(mname, zname);

    consume = new char[strlen(zconsume)+1];
    strcpy(consume, zconsume);

    rip = new char[strlen(zrip)+1];
    strcpy(rip, zrip);

    return 1;
}
int wstats::create_entry(char * wname, char * wspeed, char * wthrash)
{
    mname = new char[strlen(wname)+1];
    strcpy(mname, wname);

    speed = new char[strlen(wspeed)+1];
    strcpy(speed, wspeed);

    thrash = new char[strlen(wthrash)+1];
    strcpy(thrash, wthrash);

    return 1;
}
//These displays are also the same as the previous ones
//they simply output the data
int vstats::display()
{
    cout<<"Vampire Name: "<<mname<<endl;
    cout<<"Vampire Siphon Skill: "<<siphon<<endl;
    cout<<"Vampire Magic Skill: "<<magic<<endl;
    cout<<endl;

    return 1;
}
int zstats::display()
{
    cout<<"Zombie Name: "<<mname<<endl;
    cout<<"Zombie Consume Skill: "<<consume<<endl;
    cout<<"Zombie Rip Skill: "<<rip<<endl;
    cout<<endl;

    return 1;
}
int wstats::display()
{
    cout<<"Werewolf Name: "<<mname<<endl;
    cout<<"Werewolf Speed Skill: "<<speed<<endl;
    cout<<"Werewolf Thrash Skill: "<<thrash<<endl;
    cout<<endl;
    
    return 1;
}
//These delete_entry functions are the same
//they simply delete the data
int vstats::delete_entry()
{
    delete [] mname;
    delete [] siphon;
    delete [] magic;
    return 1;
}
int zstats::delete_entry()
{
    delete [] mname;
    delete [] consume;
    delete [] rip;
    return 1;
}
int wstats::delete_entry()
{
    delete [] mname;
    delete [] speed;
    delete [] thrash;
    return 1;
}
//These assignment operators are the same as well
//they check for self assignment and existing data
//and then deep copy
vstats & vstats::operator=(const vstats & v2)
{
    if(this == &v2)
        return *this;
    if(mname)
        delete [] mname;
    mname = new char[strlen(v2.mname)+1];
    strcpy(mname, v2.mname);

    if(siphon)
        delete [] siphon;
    siphon = new char[strlen(v2.siphon)+1];
    strcpy(siphon, v2.siphon);

    if(magic)
        delete [] magic;
    magic = new char[strlen(v2.magic)+1];
    strcpy(magic, v2.magic);

    return *this;
}
zstats & zstats::operator=(const zstats & z2)
{
    if(this == &z2)
        return *this;
    if(mname)
        delete [] mname;
    mname = new char[strlen(z2.mname)+1];
    strcpy(mname, z2.mname);

    if(consume)
        delete [] consume;
    consume = new char[strlen(z2.consume)+1];
    strcpy(consume, z2.consume);

    if(rip)
        delete [] rip;
    rip = new char[strlen(z2.rip)+1];
    strcpy(rip, z2.rip);
    
    return *this;
}
wstats & wstats::operator=(const wstats & w2)
{
    if(this==&w2)
        return *this;
    if(mname)
        delete [] mname;
    mname = new char[strlen(w2.mname)+1];
    strcpy(mname, w2.mname);

    if(speed)
        delete [] speed;
    speed = new char[strlen(w2.speed)+1];
    strcpy(speed, w2.speed);

    if(thrash)
        delete [] thrash;
    thrash = new char[strlen(w2.thrash)+1];
    strcpy(thrash, w2.thrash);

    return *this;
}
//Constructor for the ADLL class
adll::adll(int size)
{
    array = new monsterstats * [size]; //allocate an array of size 3
    array[0] = NULL; //initialize the indices
    array[1] = NULL;
    array[2] = NULL;
}
//insert function for the adll
int adll::insert(int index, monsterstats * ptr)
{
    if(!array[index]) //if the list is empty
    {
        array[index] = ptr;
        array[index]->connectnext(NULL);
        array[index]->connectprev(NULL);
        return 1;
    }
    else
    {
        monsterstats * temp = array[index]; //temp pointer to traverse a linked list
        return insert(index, array, ptr, temp);
    }
}
//insert function for adll
int adll::insert(int index, monsterstats ** & array, monsterstats * ptr, monsterstats * temp)
{
    if(!temp) return 0;

    if(!temp->gonext())
    {
        temp->gonext() = ptr;
        temp->gonext()->connectnext(NULL);
        temp->gonext()->connectprev(NULL);
        return 1;
    }

    return insert(index, array, ptr, temp->gonext()); //traverse list and inserts in correct spot
}
//display all function
int adll::display_all()
{
    int i = 0;
    if(!array[0] && !array[1] && !array[2])
        return 0;
    else
        return display_all(array, i);
}
//display all function
int adll::display_all(monsterstats ** array, int & i)
{
    if(i > 2) return 0;

    monsterstats * temp = array[i]; //temp pointer to traverse a linkedlist
    display_all(array, i, temp);

    return display_all(array, ++i);
}
//display all function
int adll::display_all(monsterstats ** array, int & i, monsterstats * temp)
{
    if(!temp) return 0;

    temp->display(); //loops through a linked list and displays its data

    return display_all(array, i, temp->gonext());
}
//retrieve wrapper
int adll::retrieve(char * searchname)
{
    int i = 0;
    if(!array[0] && !array[1] && !array[2])
        return 0;
    else
        return retrieve(array, i, searchname);
}
//retrieve function that traverses the indices of the array and calls
//a function to traverse the linked list
int adll::retrieve(monsterstats ** array, int & i, char * searchname)
{
    if(i > 2) return 0;

    monsterstats * temp = array[i];
    retrieve(array, i, searchname, temp);

    return retrieve(array, ++i, searchname);
}
//retrieve function that traverse a linked list and retrieves it
int adll::retrieve(monsterstats ** array, int & i, char * searchname, monsterstats * temp)
{
    if(!temp) return 0;

    if(temp->compareremove(searchname))
    {
        cout<<"Match found!"<<endl;
        temp->display();
    }

    return retrieve(array, i, searchname, temp->gonext());
}
//remove function that was for some reasaon incredibly annoying to write
//this is the wrapper
int adll::remove(char * searchname)
{
    int i = 0;
    if(!array[0] && !array[1] && !array[2])
        return 0;

    if(array[0] && !array[0]->gonext() && array[0]->compareremove(searchname)) //I have no clue why but I needed all of these cases
    {
        array[0]->delete_entry();
        delete array[0];
        array[0] = NULL;
        return 1;
    }
    if(array[1] && !array[1]->gonext() && array[1]->compareremove(searchname))
    {
        array[1]->delete_entry();
        delete array[1];
        array[1] = NULL;
        return 1;
    }
    if(array[2] && !array[2]->gonext() && array[2]->compareremove(searchname))
    {
        array[2]->delete_entry();
        delete array[2];
        array[2] = NULL;
        return 1;
    }

    if(array[0] && array[0]->gonext() && array[0]->compareremove(searchname))
    {
        monsterstats * hold = array[0]->gonext();
        array[0]->delete_entry();
        delete array[0];
        array[0] = hold;
        return 1;
    }
    if(array[1] && array[1]->gonext() && array[1]->compareremove(searchname))
    {
        monsterstats * hold = array[1]->gonext();
        array[1]->delete_entry();
        delete array[1];
        array[1] = hold;
        return 1;
    }
    if(array[2] && array[2]->gonext() && array[2]->compareremove(searchname))
    {
        monsterstats * hold = array[2]->gonext();
        array[2]->delete_entry();
        delete array[2];
        array[2] = hold;
        return 1;
    }
    return remove(array, i, searchname);
}
//remove function that traverses the array and sets up temp to traverse list
int adll::remove(monsterstats ** & array, int & i, char * searchname)
{
    if(i > 2) return 0;
    
    monsterstats * temp = array[i];
    if(temp)
        remove(array, i, searchname, temp);

    return remove(array, ++i, searchname);
}
//traverses list to remove if theres a match
int adll::remove(monsterstats ** & array, int & i, char * searchname, monsterstats * & temp)
{
    if(!temp) return 0;

    remove(array, i, searchname, temp->gonext()); //recursive call to traverse

    if(temp->compareremove(searchname)) //if theres a match remove it
    {
        monsterstats * hold = temp->gonext();
        temp->delete_entry();
        delete temp;
        temp = hold;
    }
    return 1;
}

//destructor that is a wrapper for fir remove all function
adll::~adll()
{
    int i = 0;

    remove_all(array, i);
    delete [] array;
}
//traverses array and sets up temp ptr
int adll::remove_all(monsterstats ** & array, int & i)
{
    if(i > 2) return 0;

    monsterstats * temp = array[i];

    remove_all(array, i, temp);

    remove_all(array, ++i);

    //delete array;
    return 1;
}
//traverses list and removes
int adll::remove_all(monsterstats ** & array, int & i, monsterstats *& temp)
{
    if(!temp) return 0;

    remove_all(array, i, temp->gonext());

    temp->delete_entry();
    delete temp;
    temp = NULL;
    return 1;
}
//copy const for array
adll::adll(const adll & source)
{
    monsterstats ** destarray;
    destarray[0] = NULL;
    destarray[1] = NULL;
    destarray[2] = NULL;
    
    int i = 0;

    copy_adll(source.array, destarray, i);
}
//traverse array
void adll::copy_adll(monsterstats ** array, monsterstats ** & destarray, int & i)
{
    if(i > 2) return;

    monsterstats * temp = array[i];
    monsterstats * desttemp = destarray[i];

    copy_adll(array, destarray, i, temp, desttemp);

    copy_adll(array, destarray, ++i);

    return;
}
//copies the list
void adll::copy_adll(monsterstats ** array, monsterstats ** & destarray, int & i, monsterstats *& temp, monsterstats *& desttemp)
{
    if(!temp)
    {
        desttemp = NULL;
        return;
    }

    desttemp = temp->newmonsterstats();
    desttemp->copy_const(temp);

    return copy_adll(array, destarray, i, temp->gonext(), desttemp->gonext());
}
//creates new vamp stats object
monsterstats * vstats::newmonsterstats()
{
    return new vstats;
}
//deep copy for copy const
int vstats::copy_const(monsterstats * temp)
{
    mname = new char[strlen(temp->getmname())+1];
    strcpy(mname, temp->getmname());

    siphon = new char[strlen(temp->getmname())+1];
    strcpy(siphon, temp->getmname());

    magic = new char[strlen(temp->getmname())+1];
    strcpy(magic, temp->getmname());

    return 1;
}
char * monsterstats::getmname()
{
    return mname;
}
monsterstats * zstats::newmonsterstats()
{
    return new zstats;
}
int zstats::copy_const(monsterstats * temp)
{
    mname = new char[strlen(temp->getmname())+1];
    strcpy(mname, temp->getmname());

    consume = new char[strlen(temp->getmname())+1];
    strcpy(consume, temp->getmname());

    rip = new char[strlen(temp->getmname())+1];
    strcpy(rip, temp->getmname());
    return 1;
}
monsterstats * wstats::newmonsterstats()
{
    return new wstats;
}
int wstats::copy_const(monsterstats * temp)
{
    mname = new char[strlen(temp->getmname())+1];
    strcpy(mname, temp->getmname());

    speed = new char[strlen(temp->getmname())+1];
    strcpy(speed, temp->getmname());

    thrash = new char[strlen(temp->getmname())+1];
    strcpy(thrash, temp->getmname());

    return 1;
}
//overloaded operators for the ADLL
ostream & operator<<(ostream & o, adll & my_adll)
{
    my_adll.display_all();
    return o;
}
adll & adll::operator-=(char * searchname)
{
    remove(searchname);
    return *this;
}
adll & adll::operator+=(monsterstats * ptr)
{
    cout<<"Are you entering a vampire (0), zombie (1), or a werewolf (2)? Type the corresponding number (sorry this is poorly designed): ";
    int index = 0;
    cin>>index;
    insert(index, ptr);

    return *this;
}








