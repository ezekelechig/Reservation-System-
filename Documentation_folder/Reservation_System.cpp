#include <iostream>
#include <string>

using namespace std;

class Flight{

    private:  
        string departure_city;
        string arrival_city; 
        string airport;
        string destination;
        std::string cabinclass[3];

    public:
        string name;
        int number;

        // Flight()
        // {
        //     cabinclass = NULL;
        // }

        Flight(string name, int number)
        {
            this->name = name;
            this->name = number;
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
      cabinclass[0] = "Economy";
      cabinclass[1] = "FirstClass";
      cabinclass[2] = "Business";

  }


};

int main()
{
    Flight plain1("Spirit", 12345);
    plain1.setdeparture_city("Houston");
    cout<<plain1.setcabinclass()<<endl;

    return 0;
}