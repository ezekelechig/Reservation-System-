#include <iostream>
#include <ctime>
#include <chrono>
#include <fstream>
#include <string>
#include <array>
#include <typeinfo>
#include <stdio.h>


using namespace std;
//Stack class implementation begins here
struct Snode
{
    string data;
    Snode* next;
};

class Stack
{
    private:
        int size;  
    public:
    Snode* top;
    Stack()
    {
        size = 0;
        top = NULL;
    }    
    void Push(string x)
    {
        Snode* newNode = new Snode();
        Snode* temp;
        newNode->data = x;
        newNode->next = NULL;
        if(top == NULL) top = newNode;
        else
        {
            temp = top;
            top = newNode;
            newNode->next = temp;
        }
        size++;
    }
    void displayStack()
    {
        Snode* temp;
        if(top == NULL) cout<<"Stack is empty, No Logs to display!\n";
        else
        {
            cout<<"The Following logs are in the Stack:\n";
            temp = top;
            while(temp != NULL)
            {
                cout<<temp->data<<"\n";
                temp = temp->next;
            }
        }
    }
    void Pop()
    {
        Snode* temp;
        if(top == NULL)
        {
            cout<<"Stack is Empy!, No Logs to display\n";
        }
        else
        {
            temp = top;
            top = top->next;
            delete temp;
        }
        size--;
    }
    void Top()
    {
        cout<<"Top of Stack is:\n";
        cout<< top->data << "\n";
    }
    void isEmpty()
    {
        cout<<"isEmpty?: ";
        if(top == NULL) cout<<"TRUE\n";
        else cout<<"FALSE\n";
    }
    void getSize()
    {
        cout<<"Size of Stack is:" <<size <<endl;
    }
};
//Stack class implementation ends here
//Implementation of Flight class starts here
class Flight{

    private:  
        string departure_city;
        string arrival_city; 
        string airport;
        string destination;
        string cabinclass[3];
        string departure_time;
        string arrival_time;
    public:
        string name;
        string fnumber;

        Flight(){};

        Flight(string _name, string _fnumber)
        {
            this->name = _name;
            this->fnumber = _fnumber;  //error in assignment
        }
    
    void setdeparture_city(string _city)
    {
        this->departure_city = _city;
    }

    string getdeparture_city()
    {
        return this->departure_city;
    }

    void setarrival_city(string _arrival)
    {
        this->arrival_city = _arrival;
    }
    string getarrival_city()
    {
        return this->arrival_city;
    }

    void setairport(string _airport)
    {
        this->airport = _airport;
    }
    string getairport()
    {
        return this->airport;
    }

    void setdestination(string _destination)
    {
        this->destination = _destination;

    }

    string getdestination()
    {
        return this->destination;
    }

  void setcabinclass()
  {
      this->cabinclass[0] = "Economy";
      this->cabinclass[1] = "FirstClass";
      this->cabinclass[2] = "Business";
  }

 string getcabinclass(string _cclass)
  {
      for(int i = 0; i < 3; i++)
      {
          if(this->cabinclass[i] == _cclass) return _cclass;
      }
      return "Invalid input";
    }
 void setDeparturetime(string dtime)
 {
     this->departure_time = dtime;
 }
 string getDeparturetime()
 {
     return this->departure_time;
 }
 void setArrivaltime(string atime)
 {
     this->arrival_time = atime;
 }
 string getArrivaltime()
 {
     return this->arrival_time;
 }
friend std::istream &operator >> (std::istream &in, Flight& data);
};
//Implementation of Flight class end here

    //Operator overloading of "<<" for the Flight class
    std::ostream& operator << (std:: ostream &out, Flight& data)
    {
        out << data.name << ": ";
        out << data.fnumber << ": ";
        out << " flying from "<< data.getdeparture_city() <<" departing at: "<< data.getDeparturetime()<< " --> ";
        out << " to " << data.getdestination() <<" arriving at: " <<data.getArrivaltime()<< " : ";
        out << "cabin class selected: " <<data.getcabinclass("Economy") << ": ";
        return out;
    }
    //Operator overloading of ">>" for the Flight class
    std::istream &operator >> (std::istream &in, Flight& datain)
    {
        cout<< "Enter Flight Name :\n";
        in >> datain.name; 
        cout<< "Enter Flight Number :\n";
        in >> datain.fnumber;
        cout<< "Enter Departure City :\n";
        in>> datain.departure_city;
        cout<< "Enter Departure Time (time-zone-week-month-day):\n";
        in >> datain.departure_time;
        cout<< "Enter Destination :\n";
        in >> datain.destination;
        cout<< "Arrival Time (time-zone-week-month-day): \n";
        in>> datain.arrival_time;
        cout<< "Cabin Class :\n";
        in >> datain.cabinclass[2];
        return in;
    }
    
    
//::::::::::::::::::::::::::::::BEGINS::::::::::::::LINKEDLIST IMPLEMENTATION::::::::::::::::::::::::::::::::::::
struct Node
{
    Flight data;
    struct Node* next;
};

class FlightLinkedList // : Flight
{
    private:
        Node* head;
        Node* tail;
        int size;
    public:
        FlightLinkedList()
        {
            head = tail = NULL;
            size = 0;
        }
    void addToList(Flight x)
    {
        Node* newFlight = new Node();
        newFlight->data = x;
        newFlight->next = NULL;
        if(head == NULL)
        {
            head = tail = newFlight;
        } 
        else
        {
            tail->next = newFlight;
            tail = newFlight;
        }
        size++;  
    }
    void getSize()
    {
        cout<< "Size of FlightLinkedList Data Store is: " << size <<endl;
    }
    void displayFlight()
    {
        Node*temp = head;
        if(head == NULL) cout<<"List is Empty" <<endl;
        else
        {
            cout<<"The FlightLinkedList Contains the Following Flight: " <<endl;
            while(temp!= NULL)
            {
                cout<< temp->data <<endl;
                temp = temp->next;
            }
        }
    }
        bool searchFlight(string x, string y)
        {
            Node* temp = head;
            if(head == NULL)
            {
                //cout<<"Flight Not Found!" <<endl;
                return head;
            }
            else
            {
                bool flag = false;
                while (temp != NULL)
                {
                    if(temp->data.getdeparture_city() == x && temp->data.getdestination() == y) 
                    {
                        flag = true;
                        cout<< "Flight Found!" <<endl;
                        cout<<"Name of Flight: "<< temp->data <<endl;
                        temp = temp->next;
                    }
                    else 
                    {
                        temp = temp->next;
                    }
                    
                }
                return flag;
               
            }
                    // cout<<"Flight Not Found!"<<endl;
                    // return false;
        }
        bool searchFlight2(Flight x)
        {
            Node* temp = head;
            if(head == NULL)
            {
                cout<<"Flight Not Found!" <<endl;
                return head;
            }
            else
            {
                while (temp != NULL)
                {
                    if(temp->data.fnumber == x.fnumber) 
                    {
                        cout<< "Flight Found!" <<endl;
                        cout<<"Name of Flight: "<< x <<endl;
                        return true;
                    }
                    temp = temp->next;
                }
                
                cout<<"Flight Not Found!"<<endl;
                return false;
            }
            
        }
        Flight* searchforbook(string x)
        {
            Node* temp = head;
            if(head == NULL)
            {
                cout<<"Flight with the id Not Found!" <<endl;
                return NULL;
            }
            else
            {
                while (temp != NULL)
                {
                    if(temp->data.fnumber == x) 
                    {
                        //cout<< "Display if Founnd!\n";
                        //cout<<temp->data <<endl;
                        return &temp->data;
                    }
                    temp = temp->next;
                }
                
               
            }
            return NULL;

        }

        void deleteFlight(string x)
        {
            if(head == NULL)
            {
                cout<<"There no Flight Added Yet!" <<endl;
                return;
            }
            else if(head->data.fnumber == x)
            {
                Node* temp1 = head;
                head = head->next;
                temp1 = NULL;
                delete temp1;
            }
            else
            {
                Node* temp2 = head; Node* target = head;
                while(target != NULL)
                {
                    if(target->data.fnumber == x)
                    {
                        temp2->next = target->next;
                        target = NULL;
                        return;
                    }
                    temp2 = target;
                    target = temp2->next;
                }
            }
            size--;
        }
};//End of linked list implementation

class ScheduleFlight : public Flight, public FlightLinkedList // Implementation of schedule class
{
    private:
        FlightLinkedList y;
    public:
        FlightLinkedList getList()
        {
            return this->y;
        }
        // ScheduleFlight()
        // {
        //     //FlightLinkedList();
        // }
        void setSchedule(Flight x)
        {
            if(y.searchFlight2(x)== true)
            {
                cout<<"Schedule Already Exist"<<endl;
            }
            else
            {
                y.addToList(x);
                cout<<"Schedule Added Successfully"<<endl;
            }
        }
        void viewSchedule()
        {
            y.displayFlight();
            
        }

        void deleteSchedule(string x)
        {
            if(y.searchforbook(x) != NULL)
            {
                y.deleteFlight(x);
                cout<<"Schedule Successfully deleted!"<<endl;
            }
            else
            {
                cout<<"Schedule you are attempting to delete does not exist!" <<endl;
            }
        }
        bool searchSchedule(string dep, string des)
        {
            if(y.searchFlight(dep, des))
            {
                return 1;
            }
            else return 0;
        }
        Flight* Search4booking(string _x)
        {
            return y.searchforbook(_x);
        }

};// End of implementation of the schedule class
class Booking : public ScheduleFlight // Implementationn of the booking class
{
    private:
        int Bid;
    public:
        Booking(){};
        Booking(int Bid)
        {
            this->Bid = Bid;
        }
    // Flight bookingSearch(string xx)
    // {
    //     return Search4booking(xx);
    // }
};//End of implementation of the booking class
class User //Impmementation of the user class
{
    private:
        int id;
        string name;
        string password;
    public:
        User(){}; // imserted implicit constructor for user
        User(int id, string name)
        {
            this->id = id;
            this->name = name;
        }
    int getUserId()
        {
            return this->id;
        }
        string getUserName()
        {
            return this->name;
        }
        void setpassWord(string _pwd)
        {
            this->password = _pwd;
        }
        string getPassword()
        {
            return this->password;
        }
    // void book(Flight book)
    
    friend std::istream &operator >> (std::istream &in2, User& datain2);
};//End of user class
std::ostream& operator << (std:: ostream &out2, User& data2)// Operator overloading of "<<" for user class
    {
        out2 << data2.getUserId() << ": ";
        out2 << data2.getUserName() << ": ";
        return out2;
    }
std::istream &operator >> (std::istream &in2, User& datain2)// Operator overloading of ">>" for user class
    {
        cout<< "Enter User ID :\n";
        in2 >> datain2.id;
        cout<< "Enter User Name: \n";
        in2 >> datain2.name;
        cout<< "Set Temporary password for User:\n";
        in2>> datain2.password;
        return in2;
    }
struct node
{
    User data;
    node* left;
    node* right;
};

class UserBST //Implementation of BST begins here
{
    private:
        node* root;
        int size2;
    public:
        //UserBST(){};
        //node* root;
        UserBST()
        {
            this->root = NULL;
            size2 = 0;
        }
     node* creatNode()
     {
         node* newNode = new node();
         return newNode;
     }
     node* insertUser(node *root, User x)
     {
        if(root == NULL)
        {
            root = creatNode();
            root->data = x;
            root->left = root->right = NULL;
        }
        else if(x.getUserId() <= root->data.getUserId())
        {
            root->left = insertUser(root->left, x);
        }
        else
        {
            root->right = insertUser(root->right, x);
        }
        return root;
     }

     void displayBST(node* root)
     {
         if(root == NULL)
         {
             return;
         }
         else
         {
             
             displayBST(root->left);
             cout<<root->data<<endl;
             displayBST(root->right);
         }  
     }
    
    void searchUser(node* root, User x)
    {
        if(root == NULL)
        {
            cout<<"Not Found!"<<endl;
            return;
        }
        else if(root->data.getUserId() == x.getUserId())
        {
            cout<< "Found User => " << x << endl;
        }
        else if(x.getUserId() < root->data.getUserId())
        {
            return searchUser(root->left, x);
        }
        else
        {
            return searchUser(root->right,x);
        }
        
    }
    User* searchUser2(node* root, int user_id)
    {
        if(root == NULL)
        {
            //cout<<"Not Found!"<<endl;
            return NULL;
        }
        else if(root->data.getUserId() == user_id)
        {
            //cout<< "Found User => " << user_id << endl;
            return &root->data;
        }
        else if(user_id < root->data.getUserId())
        {
            return searchUser2(root->left, user_id);
        }
        else
        {
            return searchUser2(root->right,user_id);
        }
        return NULL;
        
    }
    bool searchUser3(node* root, int user_id, string pwd)
    {
        if(root == NULL)
        {
            //cout<<"Not Found!"<<endl;
            return 0;
        }
        else if(user_id == root->data.getUserId() && pwd == root->data.getPassword())
        {
            //cout<< "Found User in search-3"<< endl;
            return 1;
        }
        else if(user_id < root->data.getUserId())
        {
            return searchUser3(root->left, user_id, pwd);
        }
        else
        {
            return searchUser3(root->right,user_id,pwd);
        }
        return 0;
    }
    node* getMin(node* root)
    {
        if(root == NULL)
        {
            cout<< "There is no minimum value in an empty tree"<<endl;
            return root;
        }
        else
        {
            if(root->left == NULL) return root;
            return getMin(root->left);
        }
        
    }
    node* removeUser(node* root, User x)
    {
        if(root == NULL)
        {
            cout<< "BST is empty!"<< endl;
        }
        else if(x.getUserId() < root->data.getUserId())  
        {
             root->left = removeUser(root->left, x);
        }
        else if(x.getUserId() > root->data.getUserId())
        {
            root->right = removeUser(root->right, x);
        }
       
        else
        {
            // case 1: when we are deleting a leave node
            if(root->left == NULL && root->right == NULL)
            {
                delete root;
                root = NULL;
            }
            // case 2: when we are deleting a node with only one child
            else if(root->left == NULL)
            {
                node* temp = root;
                root = root->right;
                delete temp;
            }
            else if(root->right == NULL)
            {
                node* temp = root;
                root = root->left;
                delete temp;
            }
            // case 3: When we are deleting a node with 2 children
            else
            {
                node * temp = getMin(root->right);
                root->data = temp->data;
                root->right = removeUser(root->right, temp->data);
            }
            
        }
        return root;
    }
    void getSize()
    {
        cout<<"The current size of the BST is: " <<endl;
        cout << size2 <<endl;
    }



};// End of BST Class

//Useraccount class implementation
class UserAccount//: public User, UserBST // UserAccount Class
{
    private:
        UserBST x;
    public:
        
        UserAccount(){};
        node* root;

    UserBST getBST()
    {
        return this->x;
    }
    bool creatAccount(string user_name, string _password, int user_id)
    {
        if(x.searchUser2(root, user_id) != NULL)
        {
            cout<<"User Already Exist!" <<endl;
            return false;
        }
        else
        {
            User new_user(user_id, user_name);
            new_user.setpassWord(_password);
            root = x.insertUser(root, new_user);
            cout<<"Account Successfully Created!" <<endl;
            return true;
        }
    }

    bool logIn(int userid, string _pwd)
    {
       if(x.searchUser3(root, userid, _pwd))
       {
           return true;
       }
       else
       return 0;
    }

    void viewuseraccount()
    {
        x.displayBST(root);
    }

    void deleteUserAccount(int userid)
    {
       if(x.searchUser2(root, userid)!= NULL)
       {
           User y = *(x.searchUser2(root, userid));
           root = x.removeUser(root,y);
       }
       else
       {
         cout<<"ERROR Userid does not exit\n";
       }  
    }
    node* addUseraccount(User myuser)
    {
       return x.insertUser(root, myuser);
    }
    
}; //End of Useraccountclass

class Admin : public Booking, public UserBST, public UserAccount //Admin class begins here
{
    private:
        int adminId;
        string adminName;
    public:
        Admin(){}
        Admin(int adminId, string adminName)
        {
            this->adminId = adminId;
            this->adminName = adminName;
        }  
}; //Admin class ends here
string getTime() // Function to retreive time stamp for logging purposes
{
    auto mytime = chrono::system_clock::now();
    time_t my_time = chrono::system_clock::to_time_t(mytime);
    string t = ctime(&my_time);
    return t;
}
class Logging : public Stack // Start of Logging class
{
    public:
    Stack logs;
    fstream logfile;
    Logging()
    {
        //fstream logfile("mylogfile.txt", ios::in, ios::out);
    }
    string line;
    void writeLog(string mylog)
    {
        logfile.open("mylogfile.txt", ios::out | ios::app );
        if(logfile.is_open())
        {
            logfile << mylog <<endl;
        }
        logfile.close();
    }
    void readLog()
    {
        logfile.open("mylogfile.txt");
        logfile.seekg(ios::beg);
        if(logfile.is_open())
        {
            while(getline(logfile,line))
            {
                //cout<< line <<endl;
                logs.Push(line);
            }
            logfile.close();
        }
        else
        {
            cout<< "FILE ERROR!\n";
        }
    }
    void viewLogs()
    {
        logs.displayStack();
    }
    void clearLogs()
    {
        while(top != NULL)
        {
            logs.Pop();
        }
    }
}; // End of logging class
//::::::::::::::::::::::::::::::ENDS::::::::::::::::LINKEDLIST IMPLEMENTATION::::::::::::::::::::::::::::::::::::

//Main begins here
int main()
{
  
 Logging mylogging;

//::::::::Flight Instances :::::::::::::::::::::
    Flight plain1("Spirit", "NK297");
    plain1.setdeparture_city("Houston");
    plain1.setcabinclass();
    plain1.setDeparturetime("2:00pm CDT, Wednessday July 7");
    plain1.setArrivaltime("1:00 pm WAP, Thursday July 8");
    plain1.setdestination("Lagos-Nigeria");
    mylogging.writeLog("Initialized flight object plain1 on " + getTime());
    Flight plain2("Spirit", "NK337");
    plain2.setdeparture_city("Sacramento");
    plain2.setcabinclass();
    plain2.setDeparturetime("6:15am, PDT, Monday July 5");
    plain2.setArrivaltime("10:40am, CDT, Monday July 5");
    plain2.setdestination("Houston");
    mylogging.writeLog("Initialized flight object plain2 on " + getTime());
    Flight plain3("UNITED", "UA2481");
    plain3.setdeparture_city("Dallas");
    plain3.setcabinclass();
    plain3.setDeparturetime("8:30am, PDT, Teusday July 6");
    plain3.setArrivaltime("9:46am, CDT, Monday July 5");
    plain3.setdestination("Houston");
    mylogging.writeLog("Initialized flight object plain3 on " + getTime());
    Flight plain4("UNITED", "UA206");
    plain4.setdeparture_city("New York");
    plain4.setcabinclass();
    plain4.setDeparturetime("7:30am, EDT, Monday July 5");
    plain4.setArrivaltime("10:18am, EDT, Monday July 5");
    plain4.setdestination("Houston");
    Flight plain5("FRONTIER", "F91280");
    plain5.setdeparture_city("Colorado");
    plain5.setcabinclass();
    plain5.setDeparturetime("7:30am, EDT, Monday July 6");
    plain5.setArrivaltime("10:18am, EDT, Monday July 6");
    plain5.setdestination("California");
    mylogging.writeLog("initialized flight object plain5 on " + getTime());
    Flight plain6("FRONTIER", "F95566");
    plain6.setdeparture_city("Houston");
    plain6.setcabinclass();
    plain6.setDeparturetime("7:30am, EDT, Monday July 6");
    plain6.setArrivaltime("10:18am, EDT, Monday July 6");
    plain6.setdestination("Colorado");
    mylogging.writeLog("Initialized flight object plain6 at " + getTime());
    Flight plain7("AmericanAilines", "AA1297");
    Flight plain8("AmericanAilines", "AA6735");
    Flight plain9("DELTA", "DL8881");
    Flight plain10("DELTA", "DL3508");

    //FlightLinkedList flightlist;
    ScheduleFlight SF;
    // SF.setSchedule(plain1);
    // SF.setSchedule(plain2);
    // SF.setSchedule(plain3);
    // SF.setSchedule(plain4);
    // SF.setSchedule(plain5);
    
    // cout<<plain1.name<<endl;
    //cout<<plain1.setcabinclass("Business")<<endl;
    Booking book(1);
    
//::::::::::::User Instances:::::::::::::::::::::::
    User user1(1000, "Kelechi Eze");
    User user2(500, "Busayo Busayo");
    User user3(1500, "Kemi Kemi");
    User user4(250, "Philip Philip");
    User user5(750, "Julia Julia");
    User user6(1250, "Steph Steph");
    User user7(1750, "Susan Susan");

    // user1.setpassWord("xxxx");
    // cout<<user1.getUserId()<<endl;

 //::::::::::::::LINKEDLIST:::::::::::::::::::::::::
   
    //flightlist.addToList(plain1);
    // flightlist.addToList(plain2);
    // flightlist.addToList(plain3);
    // flightlist.displayFlight();
    // flightlist.getSize();
    // flightlist.searchFlight(plain3);
    // flightlist.deleteFlight(plain3);
    // flightlist.searchFlight(plain3);
    
 //::::::::::::::END::::::::::::::::::::::::::::::::

 //::::::::::::::BST IMPLEMENTATION:::::::::::::::::
    UserBST bst;
    node* root = NULL;
    root = bst.insertUser(root, user1);
    bst.insertUser(root, user2);
    bst.insertUser(root, user3);
    bst.insertUser(root, user4);
    bst.insertUser(root, user5);
    bst.insertUser(root, user6);
    bst.insertUser(root, user7);
    // bst.displayBST(root);
    // cout<<"Displaying minimum"<<endl;
    // cout<<bst.getMin(root)->data<<endl;
    //bst.searchUser(root, user2);
    //bst.searchUser(root, user3);
    // bst.removeUser(root, user1);
    // cout<<"Displaying what is remaining after deleting user2" <<endl;
    // bst.displayBST(root); // commented out on 4pril 23, 2021
    // bst.getSize();// commented out on 4pril 23, 2021
    //::::::::::::::::::Testing FlightSchedule Class:::::::::
    
    //SF.setSchedule(plain1);
    //SF.setSchedule(plain2);
    // SF.viewSchedule();
    // SF.deleteSchedule(plain3);
    //:::::::::::::ADMIN INSTANTIATED HERE::::::::::::::::::::::

    UserAccount UA;  // Instantiated user account
    UA.creatAccount("Mary", "x6xx", 1111);
    mylogging.writeLog("Created user on " + getTime());
    UA.creatAccount("Kelechi", "$1ka", 2000);
    mylogging.writeLog("Created user on " + getTime());
    UA.creatAccount("Kelechi", "$1ka", 2000);
    mylogging.writeLog("Created user on " + getTime());
    UA.creatAccount("John", "#fun3", 2500);
    mylogging.writeLog("Created user on " + getTime());
    
    Admin adminA(1, "Guy Pearson");
    adminA.setSchedule(plain1);
    adminA.setSchedule(plain2);
    adminA.setSchedule(plain3);
    adminA.setSchedule(plain4);
    adminA.setSchedule(plain5);
    
    // adminA.Search4booking("NK337");
    // book.Search4booking("NK337");
    
    //adminA.viewSchedule(); // commented out on 4pril 23, 2021
    
    //adminA.viewSchedule();
    

    //::::::::::::::CREATEACCOUNT::::::::::::::::::::::::::::::::
   
    
    
    //string x;
    // if(book.bookingSearch(plain2) == true)
    // {
    //     cout<< "You can Proceed to book...."<<endl;
    //     cout<< "Do you want to proceed to booking?"<<endl;
    //     cin>> x;
    //     if(x== "yes")
    //     {
    //         cout<<"Begin Booking"<<endl;
    //     }

    // }
    
    int option;
    string launch;
    cout<<" ***************************************************************************************************************************************\n";
    cout<<"                                                                                                                                         \n";
    cout<<"                                                            WELCOME!                                                                 " <<endl;
    cout<<"                                                                                                                                          \n";
    cout<<" ****************************************************************************************************************************************\n";
    cout<<"CONTINUE TO LAUNCH APP?\n";
    cin>> launch;
    while(launch == "yes")
    {
    cout<< "PLEASE SELECT USER TYPE FROM THE OPTIONS BELOW" <<endl;

    cout<< "OPTION 1: User" << endl;

    cout<< "OPTION 2: Admin" <<endl;
     
    cin>> option;
    if(option == 1)
    {
        string option, cont = "yes";
        string search1, search2, ptb, flightId, username, password, accq, payopt, viewupcoming; int userID, mypayopt;
        cout<<"ARE YOU A REGISTERED USER? (select yes if you are a registered user, else select no) " <<endl;
        cin>>option;
    if(option == "no")
    {
        while(option != "yes")
        {

            cout<< "Do you want to create account? "<<endl;
            cin>>accq;
            if(accq == "yes")
            {
                cout<<"Enter username: "; cin>>username;
                cout<<"Enter password: "; cin>>password;
                cout<<"Enter userID: "; cin>> userID;
                if((UA.creatAccount(username, password, userID)) == false)
                {
                    mylogging.writeLog("Account Creation Failed!" + getTime());
                    cout<<"Account Creation Failed!" <<endl;
                }
                else option = "yes";
            }
        }
        cout<<"Do you want to Proceed to sign in?\n";
        cin>>launch;
    }
    else if(option == "yes")
    {
            cout<<"PLease Log in: " <<endl;
            cout<<"Enter UserID: "; 
            cin>>userID;
            cout<<"Enter Password: "; 
            cin>>password;

            if(UA.logIn(userID, password))
            {
                mylogging.writeLog("User with id " + to_string(userID) + " successfully logged in on " + getTime());
                while(cont == "yes")
                {
                    cout<< "Proceed to search flights"<<endl;
                    cout<< "Please enter departure city and hit enter: " ;
                    cin>>search1;
                    cout << "Please enter arrival city and hit enter: ";
                    cin>>search2;
                    if(adminA.searchSchedule(search1, search2) == true)
                    {
                        cout<< "Proceed to booking" <<endl;
                        cout << "Do you want to proceed to booking?" <<endl;
                        cin>> ptb;
                        cout<<"Please select flight by entering flightId"<<endl;
                        cin>>flightId;
                        //adminA.Search4booking(flightId);
                        cout<< *(adminA.Search4booking(flightId));
                        unsigned long int id = reinterpret_cast<unsigned long int>(&userID);
                        cout<<"Your Booking Id is: " << id <<"\n";
                        if(adminA.Search4booking(flightId) != NULL)
                        {
                            cout<<"Proceed to make Payment\n";
                            cout<<"Do you want to continue?\n";
                            cin>> payopt;
                            while(payopt == "yes")
                            {
                                cout<<"Please Select Payment Method\n";
                                cout<< "option 1: DEBIT CARD\n";
                                cout<< "option 2: CREDIT CARD\n";
                                cout<< "option 3: BITCOIN\n";
                                cin>>mypayopt;
                                if(mypayopt == 1)
                                {
                                    cout<<"Payment completed successfully using!\n";
                                    cout<< "Do you want to View your upcoming flight\n";
                                    cin>>viewupcoming;
                                    if(viewupcoming == "yes")
                                    {
                                        cout<< "CONGRATULATION ON YOUR RESERVATION, PLEASE SEE YOUR FLIGHT DETAILS BELOW \n";
                                        cout<< *(adminA.Search4booking(flightId)) <<" \n";
                                        cout<<endl;
                                        cout<<"Note! remember to check in on time to avoid additional charges!\n";
                                    }
                                    payopt = "no";
                                    cout << "Do you want to continue a new search?\n";
                                    cin>>cont;
                                }
                                else if(mypayopt == 2)
                                {
                                    cout<<"Payment completed using CREDIT CARD!\n";
                                    cout<< "Do you want to View your upcoming flight\n";
                                    cin>>viewupcoming;
                                    if(viewupcoming == "yes")
                                    {
                                        cout<< "CONGRATULATION ON YOUR RESERVATION, PLEASE SEE YOUR FLIGHT DETAILS BELOW \n";
                                        cout<< *(adminA.Search4booking(flightId)) <<" \n";
                                        cout<<endl;
                                        cout<<"Note! remember to check in on time to avoid additional charges!\n";
                                        
                                    }
                                    payopt = "no";
                                    cout << "Do you want to continue a new search?\n";
                                    cin>>cont;
                                }
                                else if(mypayopt == 3)
                                {
                                    cout<<"Payment completed successfully using BITCOIN!\n";
                                    cout<< "Do you want to View your upcoming flight\n";
                                    cin>>viewupcoming;
                                    if(viewupcoming == "yes")
                                    {
                                        cout<< "CONGRATULATION ON YOUR RESERVATION, PLEASE SEE YOUR FLIGHT DETAILS BELOW \n";
                                        cout<< *(adminA.Search4booking(flightId)) <<" \n";
                                        cout<<endl;
                                        cout<<"Note! remember to check in on time to avoid additional charges!\n";
                                    }
                                    payopt = "no";
                                    cout << "Do you want to continue a new search?\n";
                                    cin>>cont;
                                }
                                else
                                {
                                    mylogging.writeLog("User with id " + to_string(userID) + "Encountered Error while trying to complete payment on " + getTime());
                                    cout<<"Encountered Error, Please try another payment method!\n";
                                    cout<<"Do you want to contiue?\n";
                                    cin>>payopt;
                                }

                            }
                        }
    
                    }
                    else 
                    {
                        cout<< "Continue Searching for flight" <<endl;
                        cout<< "Do you want to continue?" <<endl;
                        cin>> cont;
                    }
                }
            }  
            else
            {
                mylogging.writeLog("User with id " + to_string(userID) + " Encountered Error while trying to Log in on " + getTime());
                cout<< "User not found"<<endl;
                option = "no";
                
            }
            
        }  
    }
    else
    {
        int admin_options; string cont2, proceed;
        cout<< "Welcome Admin!" <<endl;
        cout<< "Are you Admin?\n";
        cin>> proceed;
        while( proceed == "yes")
        {
        cout<< "Select one of the options below: " <<endl;
        cout<<" 1. Add or Set Flight Schedules "<<endl;
        cout<<" 2. View Existing Schedules " <<endl;
        cout<<" 3. Delete Schedule " <<endl;
        cout<<" 4. Manage User Accounts" <<endl;
        cout<<" 5. View Logs "<<endl;
        cin>>admin_options;

        if(admin_options == 1)
        {
            Flight myschedule;
            cout<<"Do you want to Proceed to set Flight Schedules"<<endl;
            cin>> cont2;
            while(cont2 != "no")
            {
                cout<< "Start Entering Flight Details\n";
                cin >> myschedule;
                adminA.setSchedule(myschedule);
                mylogging.writeLog("Admin successfully set schedule for flight number " + myschedule.fnumber + " on "+ getTime());
                cout<<"Do you want to continue to set another schedule? "<<endl;
                cin>>cont2;
            
            }
            string myanswer;
            cout<< "Do you want to log out?\n";
            cin>>myanswer;
            if(myanswer == "yes") proceed = "no";  
        }
        else if(admin_options == 2)
        {   string option;
            cout<<"Proceed to view existing Schedules"<<endl;
            cout<<"Do you want to proceed?"<<endl;
            cin>>option;
            if(option == "yes") adminA.viewSchedule();
            mylogging.writeLog("Admin successfully viewed scheduled on "+ getTime());
            string myanswer;
            cout<< "Do you want to log out?\n";
            cin>>myanswer;
            if(myanswer == "yes") proceed = "no";
        }
        else if(admin_options == 3)
        {   string option;
            string flightnum;
            cout<<"Proceed to Delete Schedules"<<endl;
            cout<<"Do you want to proceed?"<<endl;
            cin>>option;
            while(option == "yes")
            {
                cout<<"Enter the Flight to be deleted" <<"\n";
                cin>> flightnum;
                adminA.deleteSchedule(flightnum);
                mylogging.writeLog("Admin successfully deleted schedule for flight number " + flightnum + " on "+ getTime());
                cout<< "Do you want to delete another schedule\n";
                cin>> option;
            }
            string myanswer;
            cout<< "Do you want to log out?\n";
            cin>>myanswer;
            if(myanswer == "yes") proceed = "no";
        }
       
        else if(admin_options == 4)
        {
            string mychoice;
            cout<<"Proceed to manage user accounts"<<endl;
            cout<<"Do you want to proceed?"<<endl;
            cin>>mychoice;
                
            while(mychoice == "yes")
            {
                int choice1;
                cout<<"Select from the options \n";
                cout<< "Option 1: Delete User \n";
                cout<< "Option 2: Add User \n";
                cout<< "Option 3: View Users\n";
                cin>>choice1;
                if(choice1 == 1 )
                {
                    int IDtodelete;
                    User Usertodelete;
                    string answer;
                    cout<< "Do you want to proceed\n";
                    cin>>answer;
                    while(answer != "no")
                    {
                        cout<<"Enter ID of the user you want to delete\n";
                        cin>>IDtodelete;
                        if(adminA.searchUser2(root, IDtodelete) !=NULL)Usertodelete = *(adminA.searchUser2(root, IDtodelete));
                        else 
                        {
                            cout<<"ID does not exist\n";
                            mylogging.writeLog("Admin attempted to delete invalid User with id " + to_string(IDtodelete) + " on "+  getTime());
                        }
                        UA.deleteUserAccount(IDtodelete); //testing
                        // root = adminA.removeUser(root, Usertodelete );
                        mylogging.writeLog("User with id " + to_string(IDtodelete) + " was successfully deleted by Admin on" + getTime());
                        cout<<"Do you want to delete another user?\n";
                        cin>>answer;
                        
                    }
                    cout<<"Go back to options?\n";
                    cin>>mychoice;
                }
                else if(choice1 == 2)
                {
                    User usertoadd;
                    string user_add_option;
                    cout<<"Do you want to proceed to add user?\n";
                    cin>>user_add_option;
                    while(user_add_option == "yes")
                    {
                        cin>>usertoadd;
                        //root = adminA.insertUser(root,usertoadd);
                        root = UA.addUseraccount(usertoadd);//testing
                        mylogging.writeLog("User with id " + to_string(usertoadd.getUserId()) + "  was successfully added by Admin on " + getTime());
                        cout<<"Do you want to continue to add another user?\n";
                        cin>>user_add_option;
                    }
                    cout<<"Go back to options?\n";
                    cin>>mychoice;
                }
                else if(choice1 == 3)
                {
                    string viewusers;
                    cout<<"Do you want to proceed to view users?\n";
                    cin>>viewusers;
                    if(viewusers == "yes")
                    {
                        //adminA.displayBST(root);
                        UA.viewuseraccount();
                    }
                    cout<<"Go back to options?\n";
                    cin>>mychoice;
                }
            
        }
            string myanswer;
            cout<< "Do you want to log out?\n";
            cin>>myanswer;
            if(myanswer == "yes") proceed = "no";
        }
       
        else if(admin_options == 5)
        {
            string option;
            cout<<"Proceed to view logs? \n";
            cin>>option;
            cout<<"Please Enter choice?\n";
            cout <<"Option 1: View Logs\n";
            cout <<"Option 2: Clear Logs\n";
            
            while(option == "yes")
            {
                int choose;
                cin>>choose;
                if(choose == 1 ) 
                {
                mylogging.readLog();
                mylogging.viewLogs();
                cout<< "successfully viewed logs\n";
                // cout<<"Go back to options\n";
                // cin>>option;
                }
                else if(choose == 2)
                {
                    mylogging.clearLogs();
                    cout<<"successfully cleared logs\n";
                }
                option = "no";
            }
            string myanswer;
            cout<< "Do you want to log out?\n";
            cin>>myanswer;
            if(myanswer == "yes") proceed = "no";

        }
        

        
    }
}   
    }  
    return 0;
}
