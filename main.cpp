//Dr_T Unit 2 COSC-1437 Starter 
/* Task -

Top level solution folder: C_STL_Library_YourLastName

create a single main.cpp that contains code samples and implementations of each of the following topics */

#include <iostream>
#include <vector>
#include <stack>
#include <cassert>
#include <algorithm> 
#include <string>
#include <set>
#include <utility>
#include <map>
using namespace std; 

//******Function prototype from Predicate Algorithm***
 bool less_than_7(int);

//*******From map::insert ***
typedef map<string, int> MapT; //default constructor - creates an empty map opject
typedef MapT::const_iterator MapIterT;//iterator to point to MapT

//******Vectors as class members
//Credit https://www.geeksforgeeks.org/passing-vector-constructor-c/ clarifications added
class MyClassVector1 
{ 
  private:  
      vector<int> vec; 
  public: 
      MyClassVector1(vector<int> v)  //parameterized constructor
      { 
        vec = v; 
      } 
      void print() 
      { 
          /// print the value of vector 
          for (int i = 0; i < vec.size(); i++) 
              cout << vec[i] << " "; 
              
      } 
};

class MyClassVector2
{
  private:
      vector<int> vec2;
  public:
      MyClassVector2 (vector<int> v2)
      {
        vec2 = v2;
      }
      void print()
      {
        for (int i = 0; i < vec2.size(); i++)
            cout<<vec2[i] << " ";
          
      }
};

class MyClassVector3
{
  private:
      vector<int> vec3;
  public:
      MyClassVector3 (vector<int> &arr)
            : vec3(arr){}
      void print()
      {
        for (int i = 0; i < vec3.size(); i++)
            cout<<vec3[i] << " ";
      }
};

int main() 
{
    /****Section_Name***Vectors*/ 
    //Write the base code for: 5. std::vector example
    vector<double> vd; //vd elments are floating point numbers
    vector<int> vi; //vi elements are integer numbers 
    vector<string> vs; //vs elements are string objects 

    //Expand this code to:

    //add 3 elements to the vd vector
    vd.push_back(1.1);
    vd.push_back(2.6);
    vd.push_back(3.14);
    vd.push_back(55.4); 

    //add 3 elements to the vi vector
    vi.push_back(5);
    vi.push_back(-7);
    vi.push_back(99);
  
   // add 3 elements to the vs vector
    vs.push_back("Beethoven");
    vs.push_back("Scott Joplin");
    vs.push_back("Hildegard von Bingen");
  
   // display the 3 elements in the vd vector
   cout << "\nValues in vd: \n"; 
   for(double vals : vd)
   {
     cout << vals << endl; 
   }
   cout << "\nAnother way to print vector: " << endl; 
   for(int i = 0; i < vd.size(); i++)
   {
     cout << vd[i] << endl; 
   }

    //display the 3 elements in the vi vector
 cout << "\nValues in vi: \n"; 
   for(int vals : vi)
   {
     cout << vals << endl; 
   }
   cout << "\nAnother way to print vector: " << endl; 
   for(int i = 0; i < vi.size(); i++)
   {
     cout << vi[i] << endl; 
   }
  
  // display the 3 elements in the vs vector
    cout << "\nValues in vs: \n"; 
   for(string vals : vs)
   {
     cout << vals << endl; 
   }
   cout << "\nAnother way to print vector: " << endl; 
   for(int i = 0; i < vs.size(); i++)
   {
     cout << vs[i] << endl; 
   }
    /****Section_Name***Vector_as_Class_Member*/ 
    //Credit https://www.geeksforgeeks.org/passing-vector-constructor-c/

  //passing vector object to constructor
   cout << "\nVector_as_Class_Member" << endl; 
    vector<int> vec; 
        for (int i = 1; i <= 5; i++) 
            vec.push_back(i); 
        MyClassVector1 obj(vec); 
        obj.print(); 

  //initializing vector object using initializer list
cout << "\nVector_as_Class_Member2" << endl;
   vector<int> vec2;
    for (int i = 2; i <= 6; i++)
        vec2.push_back(i);
    MyClassVector2 obj2(vec2);
    obj2.print();

  //initialize a vector reference
cout << "\nVector_as_Class_Member3" << endl; 
  vector<int> vec3; 
      for (int i = 3; i <= 7; i++) 
            vec3.push_back(i); 
        MyClassVector3 obj3(vec3); 
        obj3.print();

    /****Section_Name***STL_Iterators*/ 
  //an iterator is like a vector and is used to access data stored in a container like a vector
 cout << "\nSTL Iterators" << endl;
  vector<int> vint;
  vint.push_back(10);
  vint.push_back(20);
  vint.push_back(30);
  vint.push_back(99);
  vint.push_back(45);
  vint.push_back(-20);
  vint.push_back(350);
  vint.push_back(2);
  vint.push_back(-99);
  vint.push_back(25);

  //display elements of the vector
  vector<int>::iterator it; //request iterator appropriate for class
  for(it = vint.begin(); it != vint.end(); ++it) //the range item.begin(), item.end() is the entire container
  {
    //like pointer, iterator is dereferenced to access VALUE of element pointed by it
    cout << " " << *it;
  }

    /****Section_Name*** Stack*/
//need <stack> header
  cout << "\nStack" << endl;
//a stack is a data structure where the last element inserted is the first element retrieved (LIFO - Last in first out)
  stack<int> st;

  st.push(100); // push 100 into the "back" (top) of the stack
  //need <cassert> header
  assert(st.size() == 1 ); // verify one element is on the stack
  assert(st.top() == 100);//verify the element value

  st.top() = 456; //assign new value
  assert(st.top() == 456);

  st.pop(); // remove element from stack
  assert(st.empty() == true);//needs Boolean isEmpty to prevent errors when pop operation attempted on empty stack

    /****Section_Name**** Set*/
  //need #include <set>
  //a set contains a collection of unique values in a specific order
  cout << "\nSet" << endl;
  set<int> iset;

  iset.insert(11);//add elements using insert() member function
  iset.insert(-11);
  iset.insert(55);
  iset.insert(22);
  iset.insert(22);//all elements of a set must be unique so 22 will only be added once
  if (iset.find(55) != iset.end()) { //is value already stored?
    iset.insert(55);
  }
  assert(iset.size() == 4);
  set<int>::iterator itset; //use iterator to access elements in the set
  for(itset = iset.begin(); itset != iset.end(); itset++)
    {
      cout << " " << *itset;//elements automatically stored in ascending order
    }

    /****Section_Name****Pair_Structure*/
  cout << "\nPair Structure" << endl;
//a pair is a container that only contains 2 elements (makes sense)
//uses <utility> header

  pair<string, string> strstr; //add elements
  strstr.first = "Hello";
  strstr.second = "World";

  pair<int, string> intstr; //add elements
  intstr.first = 1;
  intstr.second = "one";

  pair<string, int> strint("two", 2); //add elements in more compact way
  assert(strint.first == "two"); //verify elements are in the pair
  assert (strint.second == 2);
  
    /****Section_Name**** Map_Insert*/
  cout << "\nMap Insert" << endl;
  //a map is an associative container that holds unique pairs of keys and values
  //each element is a combination of the key and mapped values - iterators access both at the same time
  //use <map> header

  MapT amap;
  pair<MapIterT, bool> result = amap.insert(make_pair( "Fred", 45));
//insert() inserts a pair object into the map
  
  assert(result.second == true);
  assert(result.first->second == 45);
  result = amap.insert(make_pair("Fred", 54));
  //Fred was already in the map and result.first simply points there now
  assert(result.second == false);
  assert(result.first->second == 45);

    /****Section_Name****Map_Summary*/
    //Write the code as presented in: 16. Map summary
cout << "\nMap Summary" << endl;
  map<string, string> phone_book;
  phone_book["411"] = "Directory"; //411 is they key and Directory is the value
  phone_book["911"] = "Emergency";
  phone_book["508-678-2811"] = "BCC";
  //find(key) searches for an element with a specific key. If found, the fuction returns an iterator to it.
  //insert(pair) inserts a pair as an object to the map. If an element with the specified key already exists then it does nothing
  if(phone_book.find("411") != phone_book.end()){
    phone_book.insert(make_pair(string("411"), string("Directory")));
  }
  assert(phone_book.size() == 3); //size() returns the number of elements in the container
  //use iterator to specify range (begining to end) and print the map (in alphabetical order)
  map<string, string>::const_iterator mapIt;
  for(mapIt = phone_book.begin(); mapIt != phone_book.end(); ++mapIt){
    cout << " " << mapIt->first << " " << mapIt->second << endl;
  }
  //loop executes as long as the iterator does not point to the end of the map
  //the update expression increments the iterator and moves it to the next element
  //can be simplified with range based for loop
  //prints key (first) and then value(second)
  //accessed in order of keys
  
    /****Section_Name**** Sort_Algorithm*/
  cout << "\nSort Algorithm" << endl;
  //sort the range between two iterators in ascending order
  //iterators must be random access
  
  int arr[100];//array of integers with 100 elements
  sort(arr, arr + 100); //sort array from first to last element

  
  vector <int> v1;//added <int> to remove error because it required template arguments
  sort(v1.begin(), v1.end());//sort vector from beginning to end

    /****Section_Name****Predicate_Algorithm*/
    cout << "\nPredicate Algorithm" << endl;
//a function returning a bool is a predicate
//function def is below main()
  vector <int> vpa;//vector declaration
  //count_if(iterator1, iterator2, function)
  //iterator 1 and 2 mark the range of elements and function argument is the address of the function that accepts an element as its argument returns true or false
  int count_less = count_if(vpa.begin(), vpa.end(), less_than_7);

  
      return 0; 
 }

//Function definition from Predicate Algorithm
  bool less_than_7(int value) {
    
    return value < 7;
    };