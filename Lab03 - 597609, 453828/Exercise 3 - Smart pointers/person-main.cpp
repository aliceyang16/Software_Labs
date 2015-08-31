// Note, specific namespace members are imported into the global namespace which is
// better practice than importing all of the members
// eg: "using std::string;", "using std::unique_ptr;" etc. rather than "using namespace std;"

#include <memory> // required for smart pointers
using std::unique_ptr;
//make_unique is not found in older versions of c++11 and c++14
//using std::make_unique;
using std::shared_ptr;
using std::make_shared;

#include <string>
#include <iostream>
using std::string;
using std::endl;
using std::cout;

#include "Person.h"

//Note that make_unique is a new feature so we needed to copy the code bellow
//to make the template of this member found in new c++11 and c++14 versions
template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

Person printName()
{
	Person thabo{"Thabo",12};
	cout << thabo.name() << endl;
	return thabo;
}

shared_ptr<Person> printName2()
{
	//create a shared pointer, pointing to the object Person{"Mayanne", 12} 
	auto maryanne_ptr = make_shared<Person>(Person{"Maryanne",12});
	//shared pointer calls the member function in the object it points to
	cout << maryanne_ptr->name() << endl;
	return maryanne_ptr;
} //shared pointer goes out of scope and the shared pointer reference counter is decremented 

void printName3(shared_ptr<Person> person_ptr)
{
	cout << person_ptr->name() << endl;
	return;
}


int main()
{
	//create a unique pointer, pointing to the object Person{"Sandile",15} 
	auto sandile_ptr = make_unique<Person>(Person{"Sandile",15});    

	//create an object Thabo
	auto thabo_in_main = printName();
	cout << thabo_in_main.name() << endl;
	
	//create a shared pointer, pointing to the object Person{"Mayanne", 12} 
	//reference number is 1
	auto person_ptr_in_main = printName2(); 
	
	//copy of pointer to the object Person{"Mayanne", 12} 
	//reference number is 2
	printName3(person_ptr_in_main);
	
	//unique pointer is made null; no longer points to object Person{"Sandile",15} but is reassigned 
	//to object Person{"Sandile2",11}
	sandile_ptr.reset(new Person{"Sandile2",11});
	cout << sandile_ptr->age() << endl;

	return 0;
}	//object Thabo is destroyed 
	//unique pointer goes out of scope and is destroyed 
	//shared pointer reference count is decremented by its 
	//assignment operator from 2 to 1 then to 0 and is destroyed 


