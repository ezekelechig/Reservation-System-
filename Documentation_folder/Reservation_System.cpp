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
    std::ostream& operator << (std:: ostream &out, Flight& data)
    {
        out << data.name << ": ";
        out << data.number << ": ";
        out << data.getdeparture_city()<< ": ";
        out << data.getcabinclass("Economy") << ": ";
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

};

//::::::::::::::::::::::::::::::ENDS::::::::::::::::LINKEDLIST IMPLEMENTATION::::::::::::::::::::::::::::::::::::

int main()
{
    Flight plain1("SpiritAirline", 12345);
    Flight plain2("AricAirline", 65876);
    plain1.setdeparture_city("Houston");
    plain2.setdeparture_city("Lagos-Nigeria");
    plain1.setcabinclass();
    cout<<plain1.name<<endl;
    cout<<plain1.getcabinclass("Business")<<endl;

 //::::::::::::::LINKEDLIST:::::::::::::::::::::::::
    FlightLinkedList flightlist;
    flightlist.addToList(plain1);
    flightlist.addToList(plain2);
    flightlist.displayFlight();
    flightlist.getSize();
    
 //::::::::::::::END::::::::::::::::::::::::::::::::


    return 0;
}