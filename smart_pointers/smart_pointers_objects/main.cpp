#include "JarJar.h"
#include<memory>

std::unique_ptr<JarJar> create_uptr()
{
    return std::make_unique<JarJar>();
};

// Must pass unique pointer by reference 
// void make_use_uptr(std::unique_ptr<JarJar> j) is forbidden
void make_use_uptr(std::unique_ptr<JarJar>& j) 
{
    j->talk();
    std::cout << "Address at " << j.get() << std::endl;
    j.reset();
};

std::shared_ptr<JarJar> create_sptr()
{
    return std::make_shared<JarJar>();
};

// If the variable is passed by reference, the only copy will be deleted(reset)
// void make_use_sptr(std::shared_ptr<JarJar>& j) 
// Otherwise, a copy of the shared pointers is created and only the copy will be deleted(reset)
void make_use_sptr(std::shared_ptr<JarJar> j) 
{
    j->talk();
    std::cout << "Address at " << j.get() << std::endl;
    j.reset();
    std::cout << "Address at " << j.get() << std::endl;
    
};


int main()
{   
    auto j1 = create_sptr();
    make_use_sptr(j1);
    std::cout << j1.get() << std::endl;

    return 0;
}