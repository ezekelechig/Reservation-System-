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

};
class User{
    private:
        int id;
        string name;
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

};
    std::ostream& operator << (std:: ostream &out, Flight& data)
    {
        out << data.name << ": ";
        out << data.number << ": ";
        out << data.getdeparture_city()<< ": ";
        out << data.getcabinclass("Economy") << ": ";
        return out;
    }
    std::ostream& operator << (std:: ostream &out2, User& data2)
    {
        out2 << data2.getUserId() << ": ";
        out2 << data2.getUserName() << ": ";
        return out2;
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
        void searchFlight(Flight x)
        {
            Node* temp = head;
            if(head == NULL)
            {
                cout<<"Flight Not Found!" <<endl;
            }
            else
            {
                while (temp != NULL)
                {
                    if(temp->data.number == x.number) 
                    {
                        cout<<x<<endl;
                        return;
                    }
                    temp = temp->next;
                }
                
                cout<<"Flight Not Found!"<<endl;
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
        int size;
    public:
        UserBST()
        {
            this->root = NULL;
            size = 0;
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
        size++;
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

};

//::::::::::::::::::::::::::::::ENDS::::::::::::::::LINKEDLIST IMPLEMENTATION::::::::::::::::::::::::::::::::::::

int main()
{
//::::::::Flight Instances :::::::::::::::::::::
    Flight plain1("SpiritAirline", 12345);
    Flight plain2("AricAirline", 65876);
    Flight plain3("AirPeace",11111);
    plain1.setdeparture_city("Houston");
    plain2.setdeparture_city("Lagos-Nigeria");
    plain1.setcabinclass();
    cout<<plain1.name<<endl;
    cout<<plain1.getcabinclass("Business")<<endl;

//::::::::::::User Instances:::::::::::::::::::::::

    User user1(1000, "Kelechi Eze");
    User user2(999, "Busayo Busayo");
    cout<<user1.getUserId()<<endl;

 //::::::::::::::LINKEDLIST:::::::::::::::::::::::::
    FlightLinkedList flightlist;
    flightlist.addToList(plain1);
    flightlist.addToList(plain2);
    flightlist.addToList(plain3);
    flightlist.displayFlight();
    flightlist.getSize();
    flightlist.searchFlight(plain3);
    flightlist.deleteFlight(plain3);
    flightlist.searchFlight(plain3);
    
 //::::::::::::::END::::::::::::::::::::::::::::::::

 //::::::::::::::BST IMPLEMENTATION:::::::::::::::::
    UserBST bst;
    node* root;
    root = bst.insertUser(root, user1);
    bst.insertUser(root, user2);
    bst.displayBST(root);



    return 0;
}