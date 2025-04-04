#include<iostream>
#include<memory>
#include<string>

/* The Route class contains two variables current location (std::string) and next location (Route)*/
/* The Route class has method to set and print the next location */
/* Use weak pointers to avoid circular reference of shared pointers */

class Route
{
private:
    std::string m_location;
    // std::shared_ptr<Route> m_next_location;
    // using std::shared_ptr leads to circular reference, objects can't be desctruted when the scope is over
    // weak pointers do not own reference to shared pointers 
    // when shared pointers are out of scope, only weak pointers left, weak pointers will be deleted
    // weak pointers are copyable like shared pointers 
    // must convert to shared pointers before use
    std::weak_ptr<Route> m_next_location;
public:
    Route(std::string location) 
    : m_location(location)
    {
        std::cout << "Constructing " << m_location << " at " << this << std::endl;
    }

    void setNextLocation(std::shared_ptr<Route> nextLocation)
    {
        m_next_location = nextLocation;
    }

    std::string getName()
    {
        return m_location;
    }

    void printNextLocation(){
        // converted to shared pointers before usage
        // m_next_location.lock() : if weak pointer is empty, return empty shared pointers
        // std::shared_ptr<Route>(m_next_location) : if weak pointer is empty, throws std::bad_weak_ptr
        std::string nextLocation = m_next_location.lock()->getName(); 
        std::cout << "The next location after " << m_location <<  " is " << nextLocation << std::endl;
    }

    ~Route()
    {
        std::cout << "Deleting " << m_location << " at " << this << std::endl;
    } 

};