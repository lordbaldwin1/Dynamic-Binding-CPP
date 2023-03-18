//Zachary Springer
//This is the header file
//it contains #includes and class interfaces which hold
//the member functions which are defined/implemented in functions.cpp
//and called in main.cpp

#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
using namespace std;

//This is the base class for all of the monsters
//it is an abstract base class as well
class monster
{
    public:
        //Non virtual
        monster();
        virtual ~monster();
        
        void connectleft(monster * connection);
        void connectright(monster * connection);
        monster *& goleft();
        monster *& goright();
        char * getname();

        int comparename(char * searchname);
        int compareremove(char * searchname);

        //Virtual
        virtual int delete_entry()=0;
        virtual int create_entry(char *, char *, char *)=0;
        virtual int display()=0;
        //virtual int copy_entry(monster *& copy_from)=0;
        virtual int copy_const(monster *)=0;
        virtual monster * newmonster()=0;

    protected:
        monster * left;
        monster * right;
        char * name;

};
//This is a vampire class derived from the base monster class
class vampire : public monster
{
    public:
        vampire();
        ~vampire();
        vampire(const vampire & copy_from);

        vampire & operator=(const vampire &);


        int delete_entry();
        int create_entry(char * name, char * active, char * vfriends);
        int display();
        //int copy_entry(monster *& copy_from);
        monster * newmonster();
        int copy_const(monster * root);


    protected:
        char * active;
        char * vfriends;
};
//This is the binary search tree class which manages the data structure
//It also has a few overloaded operators that make the client
//program simpler to use
class bst
{
    public:
        bst();
        ~bst();
        bst(const bst & source);
        
        friend ostream & operator<<(ostream &, bst &);
        bst & operator+=(monster *);
        bst & operator-=(char *);
        
        int insert(char * searchname, monster * ptr);
        int insert(char * searchname, monster *& root, monster * ptr);

        int display_all();
        int display_all(monster * root);

        int remove(char * searchname);
        int remove(char * searchname, monster *& root);

        int retrieve(char * searchname);
        int retrieve(char * searchname, monster * root);

        int remove_all(monster *& root);

        void copy_tree(monster *, monster *&);

    protected:
        monster * root;
};
//This zombie class is derived from the monster class and 
//is used to manage a zombies data
class zombie : public monster
{
    public:
        zombie();
        ~zombie();
        zombie(const zombie & copy_from);

        zombie & operator=(const zombie &);


        int delete_entry();
        int create_entry(char * name, char * food, char * zfriends);
        int display();
        monster * newmonster();
        int copy_const(monster * root);

    protected:
        char * food;
        char * zfriends;
};
//This werewolf class is derived from the monster class and
//is used to manage a werewolf's data
class werewolf : public monster
{
    public:
        werewolf();
        ~werewolf();
        werewolf(const werewolf & copy_from);

        werewolf & operator=(const werewolf &);
        

        int delete_entry();
        int create_entry(char * name, char * transform, char * wfriends);
        int display();
        monster * newmonster();
        int copy_const(monster * root);


    protected:
        char * transform;
        char * wfriends;
};

//-----------------------------------MONSTER ATTACKS/DEFENSES-----------------------
//This is the abstract base class for the monster's stats
class monsterstats
{
    public:
        //Non virtual
        monsterstats();
        virtual ~monsterstats();

        void connectnext(monsterstats * connection);
        monsterstats *& gonext();
        void connectprev(monsterstats * connection);
        monsterstats *& goprev();
        char * getmname();
        
        int compareremove(char * searchname);

        //Virtual
        virtual int delete_entry()=0;
        virtual int create_entry(char *, char *, char *)=0;
        virtual int display()=0;


        virtual int copy_const(monsterstats *)=0;
        virtual monsterstats * newmonsterstats()=0;


    protected:
        monsterstats * next;
        monsterstats * prev;
        char * mname;


};
//This class if for vampires stats and manages vstats data
//it is derived from monsterstats
class vstats : public monsterstats
{
    public:
        vstats();
        ~vstats();
        vstats(const vstats & copy_from);

        vstats & operator=(const vstats &);

        int create_entry(char * mname, char * siphon, char * magic);
        int display();
        int delete_entry();
        monsterstats * newmonsterstats();
        int copy_const(monsterstats * ptr);

    protected:
        char * siphon;
        char * magic;

};
//This class is also derived from monsterstats and is used to manage
//a zombie's stats
class zstats : public monsterstats
{
    public:
        zstats();
        ~zstats();
        zstats(const zstats & copy_from);

        zstats & operator=(const zstats &);

        int create_entry(char * mname, char * consume, char * rip);
        int display();
        int delete_entry();
        monsterstats * newmonsterstats();
        int copy_const(monsterstats * ptr);

    protected:
        char * consume;
        char * rip;

};
//This class is used to manage a werewolf's stats
class wstats : public monsterstats
{
    public:
        wstats();
        ~wstats();
        wstats(const wstats & copy_from);

        wstats & operator=(const wstats &);

        int create_entry(char * mname, char * speed, char * thrash);
        int display();
        int delete_entry();
        monsterstats * newmonsterstats();
        int copy_const(monsterstats * ptr);

    protected:
        char * speed;
        char * thrash;

};
//This class manages the array of DLLs
//it also has overloaded operators to make the
//use of its functions in main more straight forward
class adll
{
    public:
        adll(int size = 3);
        ~adll();
        adll(const adll & source);

        friend ostream & operator<<(ostream &, adll &);
        adll & operator+=(monsterstats *);
        adll & operator-=(char *);
        
        int insert(int index, monsterstats * ptr);
        int insert(int index, monsterstats ** & array, monsterstats * ptr, monsterstats * temp);

        int display_all();
        int display_all(monsterstats ** array, int & i);
        int display_all(monsterstats ** array, int & i, monsterstats * temp);

        int retrieve(char * searchname);
        int retrieve(monsterstats ** array, int & i, char * searchname);
        int retrieve(monsterstats ** array, int & i, char * searchname, monsterstats * temp);

        int remove(char * searchname);
        int remove(monsterstats ** & array, int & i, char * searchname);
        int remove(monsterstats ** & array, int & i, char * searchname, monsterstats * & temp);

        int remove_all(monsterstats ** & array, int & i);
        int remove_all(monsterstats ** & array, int & i, monsterstats * & temp);

        void copy_adll(monsterstats ** array, monsterstats ** & destarray, int & i);
        void copy_adll(monsterstats ** array, monsterstats ** & destarray, int & i, monsterstats *& temp, monsterstats *& desttemp);

    protected:
        monsterstats ** array;
};
