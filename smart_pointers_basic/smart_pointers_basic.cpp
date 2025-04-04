#include<iostream>
#include<memory>

int main()
{

    /* 3 ways to initilize unique ptr and shared ptr */

    std::unique_ptr<int> uptr1(new int(1));

    auto uptr2 = std::make_unique<int>(2); // or std::unique_ptr<int> uptr2 = std::make_unique<int>(2);

    std::unique_ptr<int> uptr3;

    uptr3.reset(new int(3));

    std::cout << "Valule of uptr3 is " << *uptr3 << std::endl;

    std::cout << "Adress of uptr3 is " << uptr3.get() << std::endl;

    std::cout << "--------------------"  << std::endl;


    /* Casting a unique ptr to shared pointer */
    /* Unique ptr has exclusive ownership of an object, conversion means transfer of ownership from unique_ptr to shared_ptr */
    /* Safe because shared_ptr takes over ownership and unique_ptr releases ownership */

    std::cout << "Casting a unique ptr to shared ptr" << std::endl;

    std::cout << "Address of unique ptr is " << uptr1.get() << std::endl; //if this statement is after std::move, the address is 0 (nullptr)

    std::shared_ptr<int> sptr1 = std::move(uptr1);

    std::cout << "Address of shared ptr is " << sptr1.get() << std::endl;

    std::cout << "--------------------"  << std::endl;

    /* Casting a shared pointer to unique pointer is not possible */
    /* shared_ptr can have multiple ownership, violate exclusive ownership of unique_ptr */
    /* Can't compile */

    // std::shared_ptr<int>sptr2(new int(5));
    
    // std::unique_ptr<int> uptr4 = std::unique_ptr<int>(sptr2);

    /* use count of shared pointer*/

    std::cout << "Copying shared pointers" << std::endl;

    std::cout << "Copy 1st time" << std::endl;

    auto ptr1 = sptr1;

    std::cout << "Use count is " << sptr1.use_count() << std::endl;

    std::cout << "Copy 2nd time" << std::endl;

    auto ptr2 = sptr1;

    std::cout << "Use count is " << sptr1.use_count() << std::endl;

    std::cout << "reset 2 copies" << std::endl;

    ptr1.reset();
    ptr2.reset();
    sptr1.reset();

    std::cout << "Use count is " << sptr1.use_count() << std::endl;

    std::cout << "--------------------"  << std::endl;

    return 0;
}