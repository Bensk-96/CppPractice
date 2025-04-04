#include<iostream>

class JarJar
{
public:
    JarJar() {std::cout << "Construct JarJar at " << this << std::endl;}

    void talk() {std::cout << "JarJar is talking" << std::endl;;}

    ~JarJar() {std::cout << "Deleting JarJar at " << this << std::endl;}

};