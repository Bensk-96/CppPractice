#include<iostream>
#include<memory>

class BaseClass
{
    std::string m_name;
public:
    BaseClass(std::string name)
    : m_name(name)
    {
        std::cout << "Constructing a BaseClass instance " << m_name << std::endl;
    }
    ~BaseClass() // Base class destructor of Member is not called without virtual
    {
        std::cout << "Destructing a BaseClass instance " << m_name << std::endl;
    }

};

class Derived : public BaseClass
{
private:
    std::unique_ptr<BaseClass> m_member;

public:
    Derived()
    : BaseClass("Derived"),
    m_member(new BaseClass("Member"))
    {
        std::cout << "Constructing Derived " <<  std::endl;    
    }
    ~Derived() // not called when BaseClass destructor is not virtual
    {
        std::cout << "Destructing Derived " <<  std::endl;     
    }
};

int main()
{
    // BaseClass* d = new Derived(); // without virtual destructor, destructor of derived class and member base class not called, memory leak
    // delete d;

    std::unique_ptr<BaseClass> d = std::make_unique<Derived>();

    // output when BaseClass destructor is not virtual 
    // Constructing a BaseClass instance Derived
    // Constructing a BaseClass instance Member
    // Constructing Derived 
    // Destructing a BaseClass instance Derived

    return 0;
}