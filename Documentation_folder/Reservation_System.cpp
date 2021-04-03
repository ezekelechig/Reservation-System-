#include <iostream>
#include <string>
#include <array>

using namespace std;

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
        int number;

        Flight(){};

        Flight(string name, int number)
        {
            this->name = name;
            this->number = number;  //error in assignment
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

};

    std::ostream& operator << (std:: ostream &out, Flight& data)
    {
        out << data.name << ": ";
        out << data.number << ": ";
        out << " flying from "<< data.getdeparture_city() <<" departing at: "<< data.getDeparturetime()<< " --> ";
        out << " to " << data.getdestination() <<" arriving at: " <<data.getArrivaltime()<< " : ";
        out << "cabin class selected: " <<data.getcabinclass("Economy") << ": ";
        return out;
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
                cout<<"Flight Not Found!" <<endl;
                return head;
            }
            else
            {
                while (temp != NULL)
                {
                    if(temp->data.getdeparture_city() == x || temp->data.getdestination() == y) 
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
                    if(temp->data.number == x.number) 
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
        void deleteFlight(Flight x)
        {
            if(head == NULL)
            {
                cout<<"There no Flight Added Yet!" <<endl;
                return;
            }
            else if(head->data.number == x.number)
            {
                Node* temp1 = head;
                head = head->next;
                temp1 = NULL;
            }
            else
            {
                Node* temp2 = head; Node* target = head;
                while(target != NULL)
                {
                    if(target->data.number == x.number)
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
};
class ScheduleFlight //: public Flight, FlightLinkedList
{
    private:
        FlightLinkedList y;
    public:
        FlightLinkedList getList()
        {
            return this->y;
        }
        ScheduleFlight()
        {
            FlightLinkedList();
        }
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

        void deleteSchedule(Flight x)
        {
            if(y.searchFlight2(x) == true)
            {
                y.deleteFlight(x);
                cout<<"Schedule Successfully deleted!"<<endl;
            }
            else
            {
                cout<<"Schedule you are attempting to delete does not exist!" <<endl;
            }
        }

};
class Booking : ScheduleFlight
{
    private:
        int Bid;
    public:
        Booking(){};
        Booking(int Bid)
        {
            this->Bid = Bid;
        }
    bool bookingSearch(Flight x)
    {
        if(getList().searchFlight2(x) == true)
        {
            cout<<x<<endl;
            return true;
        }
        else
        {
            cout<<"Flight Not Found!" <<endl;
            return false;
        }
    }
};
class User : Booking
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

};
std::ostream& operator << (std:: ostream &out2, User& data2)
    {
        out2 << data2.getUserId() << ": ";
        out2 << data2.getUserName() << ": ";
        return out2;
    }

struct node
{
    User data;
    node* left;
    node* right;
};

class UserBST
{
    private:
        node* root;
        int size2;
    public:
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
    bool searchUser2(node* root, int user_id)
    {
        if(root == NULL)
        {
            cout<<"Not Found!"<<endl;
            return false;
        }
        else if(root->data.getUserId() == user_id)
        {
            cout<< "Found User => " << user_id << endl;
            return true;
        }
        else if(user_id < root->data.getUserId())
        {
            return searchUser2(root->left, user_id);
        }
        else
        {
            return searchUser2(root->right,user_id);
        }
        return 0;
        
    }
    bool searchUser3(node* root, int user_id, string pwd)
    {
        if(root == NULL)
        {
            cout<<"Not Found!"<<endl;
            return 0;
        }
        else if(user_id == root->data.getUserId() && pwd == root->data.getPassword())
        {
            cout<< "Found User in search-3"<< endl;
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



};
class UserAccount//: public User, UserBST
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
        if(x.searchUser2(root, user_id))
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
    
};

class Admin : ScheduleFlight, UserBST
{
    private:
        int adminId;
        string adminName;
    public:
        Admin(int adminId, string adminName)
        {
            this->adminId = adminId;
            this->adminName = adminName;
        }  
};

//::::::::::::::::::::::::::::::ENDS::::::::::::::::LINKEDLIST IMPLEMENTATION::::::::::::::::::::::::::::::::::::

int main()
{

//::::::::Flight Instances :::::::::::::::::::::
    Flight plain1("SpiritAirline", 12345);
    Flight plain2("AricAirline", 65876);
    Flight plain3("AirPeace",11111);
    plain1.setdeparture_city("Houston");
    plain2.setdeparture_city("Lagos");
    plain1.setcabinclass();
    plain1.setDeparturetime("2:00pm CDT, Wednessday July 7");
    plain1.setArrivaltime("1:00 pm WAP, Thursday July 8");
    plain1.setdestination("Lagos-Nigeria");
    plain2.setdestination("Houston Texas-USA");
    cout<<plain1.name<<endl;
    cout<<plain1.getcabinclass("Business")<<endl;

//::::::::::::User Instances:::::::::::::::::::::::

    User user1(1000, "Kelechi Eze");
    User user2(500, "Busayo Busayo");
    User user3(1500, "Kemi Kemi");
    User user4(250, "Philip Philip");
    User user5(750, "Julia Julia");
    User user6(1250, "Steph Steph");
    User user7(1750, "Susan Susan");
    user1.setpassWord("xxxx");
    cout<<user1.getUserId()<<endl;

 //::::::::::::::LINKEDLIST:::::::::::::::::::::::::
    FlightLinkedList flightlist;
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
    node* root;
    root = bst.insertUser(root, user1);
    bst.insertUser(root, user2);
    bst.insertUser(root, user3);
    bst.insertUser(root, user4);
    bst.insertUser(root, user5);
    bst.insertUser(root, user6);
    //bst.insertUser(root, user7);
    bst.displayBST(root);
    cout<<"Displaying minimum"<<endl;
    cout<<bst.getMin(root)->data<<endl;
    //bst.searchUser(root, user2);
    //bst.searchUser(root, user3);
    bst.removeUser(root, user1);
    cout<<"Displaying what is remaining after deleting user2" <<endl;
    bst.displayBST(root);
    bst.getSize();
    //::::::::::::::::::Testing FlightSchedule Class:::::::::
    ScheduleFlight SF;
    SF.setSchedule(plain1);
    SF.setSchedule(plain2);
    SF.viewSchedule();
    SF.deleteSchedule(plain3);
    Admin adminA(1, "Guy Pearson");
    Booking book(1);
    UserAccount UA;  // Instantiated user account
    UA.creatAccount("Mary", "x6xx", 1111);
    UA.creatAccount("Kelechi", "$1ka", 2000);
    UA.creatAccount("Kelechi", "$1ka", 2000);
    UA.creatAccount("John", "#fun3", 2500);
    
    
    string x;
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

    cout<< "WELCOME!" <<endl;

    cout<< "PLEASE SELECT USER TYPE FROM THE OPTIONS BELOW" <<endl;

    cout<< "OPTION 1: User" << endl;

    cout<< "OPTION 2: Admin" <<endl;

    cin>> option;
    if(option == 1)
    {
        string option, cont = "yes";
        string search1, search2, ptb, username, password, accq; int userID;
        cout<<"ARE YOU A REGISTERED USER? (select  if you are a registered user, else select no) " <<endl;
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
                    cout<<"Account Creation Failed!" <<endl;
                }
                else option = "yes";
            }
        }
        
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
                while(cont == "yes")
                {
                    cout<< "Proceed to search flights"<<endl;
                    cout<< "Please enter departure city and hit enter: " ;
                    cin>>search1;
                    cout << "Please enter arrival city and hit enter: ";
                    cin>>search2;
                    if(flightlist.searchFlight(search1, search2) == true)
                    {
                        cout<< "Proceed to booking" <<endl;
                        cout << "Do you want to proceed to booking?" <<endl;
                        cin>> ptb;
                        cout<<"Please enter flightId"<<endl;
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
                cout<< "User not found"<<endl;
            }
            
        }  
    }
    
    
    return 0;
}