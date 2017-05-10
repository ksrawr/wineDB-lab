
#include <iostream>
#include <typeinfo>
using namespace std;

/* 
 * Example of Linked List in template format
 * 
 * You must implement function:void insertAtBack( const NODETYPE &, int);
 * 
 * */
 

template< typename T > class List; // forward declaration

template< typename NODETYPE  >
class ListNode 
{

public:
   friend class List< NODETYPE >; // make List a friend
   ListNode( const NODETYPE & ); // constructor
   NODETYPE getData() const; // return the data in the node

   // set nextPtr to nPtr
   void setNextPtr( ListNode *nPtr ) 
   { 
      nextPtr = nPtr; 
   } // end function setNextPtr
   
   // return nextPtr
   ListNode *getNextPtr() const 
   { 
      return nextPtr; 
   } // end function getNextPtr

private:
   NODETYPE data; // data
   int key; // used for key for the list
   ListNode *nextPtr; // next node in the list
}; // end class ListNode

// constructor
template< typename NODETYPE >
ListNode< NODETYPE >::ListNode( const NODETYPE &info )
{
   data = info;
   nextPtr = 0;
} // end constructor

// return a copy of the data in the node
template< typename NODETYPE >
NODETYPE ListNode< NODETYPE >::getData() const 
{ 
   return data; 
} // end function getData


template< typename NODETYPE  >
class List 
{
public:
   List(); // default constructor
   List( const List< NODETYPE > & ); // copy constructor
   ~List(); // destructor

   void insertAtFront( const NODETYPE &, int );
   void insertAtBack( const NODETYPE &, int );
   bool removeFromFront( NODETYPE & );
   bool removeFromBack( NODETYPE & );
   bool isEmpty() const;
   void print() const;
   void printPtrFunc(   );
   NODETYPE * getInfo(int myKey);
      // return nextPtr
   ListNode< NODETYPE >  *getFirstPtr() const 
   { 
      return firstPtr; 
   } // end function getNextPtr
   
 protected:
   ListNode< NODETYPE > *firstPtr; // pointer to first node
   ListNode< NODETYPE > *lastPtr; // pointer to last node

   // Utility function to allocate a new node
   ListNode< NODETYPE > *getNewNode( const NODETYPE &, int );
}; // end class template List

// default constructor
template< typename NODETYPE >
List< NODETYPE >::List() 
{ 
   firstPtr = lastPtr = 0; 
} // end constructor

// copy constructor
template< typename NODETYPE >
List< NODETYPE >::List( const List<NODETYPE> &copy )
{
   firstPtr = lastPtr = 0; // initialize pointers

   ListNode< NODETYPE > *currentPtr = copy.firstPtr;

   // insert into the list
   while ( currentPtr != 0 ) 
   {
      insertAtBack( currentPtr->data );
      currentPtr = currentPtr->nextPtr;
   } // end while
} // end List copy constructor

// destructor
template< typename NODETYPE >
List< NODETYPE >::~List()
{
   if ( !isEmpty() ) // List is not empty
   {
      cout << "Destroying nodes ...\n";

      ListNode< NODETYPE > *currentPtr = firstPtr;
      ListNode< NODETYPE > *tempPtr;

      while ( currentPtr != 0 ) // delete remaining nodes
      {
         tempPtr = currentPtr;
//         cout << tempPtr->data << ' ';
         currentPtr = currentPtr->nextPtr;
         delete tempPtr;
      } // end while
   } // end if

   cout << "\nAll nodes destroyed\n\n";
} // end destructor

// Insert a node at the front of the list
template< typename NODETYPE >
void List< NODETYPE >::insertAtFront( const NODETYPE &value,
  int key)
{
   ListNode<NODETYPE> *newPtr = getNewNode( value, key );

   if ( isEmpty() ) // List is empty
      firstPtr = lastPtr = newPtr;
   else // List is not empty
   {
      newPtr->nextPtr = firstPtr;
      firstPtr = newPtr;
   } // end else
} // end function insertAtFront

// Insert a node at the back of the list
template< typename NODETYPE >
void List< NODETYPE >::insertAtBack( const NODETYPE &value,
  int key)
{
  
  /*
   * YOU MUST IMPLEMENT THIS FUNCTION AS 
   * PART OF THIS LAB
   * */
  
  
  
  
} // end function insertAtBack

// Delete a node from the front of the list
template< typename NODETYPE >
bool List< NODETYPE >::removeFromFront( NODETYPE &value )
{
   if ( isEmpty() ) // List is empty
      return false; // delete unsuccessful
   else 
   {
      ListNode< NODETYPE > *tempPtr = firstPtr;

      if ( firstPtr == lastPtr )
         firstPtr = lastPtr = 0;
      else
         firstPtr = firstPtr->nextPtr;

      value = tempPtr->data; // data being removed

      delete tempPtr;
      return true; // delete successful
   } // end else
} // end function removeFromFront

// delete a node from the back of the list
template< typename NODETYPE >
bool List< NODETYPE >::removeFromBack( NODETYPE &value )
{
	
	/*
	 * Implement this function.  Use removeFromFront as an
	 * example in implemeting this function
	 * */
	 
	 
   if ( isEmpty() )
      return false; // delete unsuccessful
   else 
   {
      ListNode< NODETYPE > *tempPtr = lastPtr;

      if ( firstPtr == lastPtr )
         firstPtr = lastPtr = 0;
      else 
      {
		  
         ListNode< NODETYPE > *currentPtr = firstPtr;

	/*  this is where you need add more code
	 * First, you need to start from the beginning of the linked list,
	 * and traverse until the node before the last node.
	 * 
	 * Once you got to the node before the last node, you need to 
	 * point the node before last node to the last node so you can 
	 * remove the last node
	 * 
	 * */
	 
  
      // your codes here
      // more codes
  
      } // end else

      value = tempPtr->data;
      delete tempPtr;
      return true; // delete successful
   } // end else
} // end function removeFromBack

// Is the List empty?
template< typename NODETYPE >
bool List< NODETYPE >::isEmpty() const 
{ 
   return firstPtr == 0; 
} // end function isEmpty

// Return a pointer to a newly allocated node
template< typename NODETYPE >
ListNode< NODETYPE > *List< NODETYPE >::getNewNode(
   const NODETYPE &value, int)
{
   ListNode< NODETYPE > *ptr = new ListNode< NODETYPE >( value );
   return ptr;
} // end function getNewNode

// Display the contents of the List
template< typename NODETYPE >
void List< NODETYPE >::print() const
{
   if ( isEmpty() ) // empty list
   {
      cout << "The list is empty\n\n";
      return;
   } // end if

   ListNode< NODETYPE > *currentPtr = firstPtr;

   cout << "The list is: ";

   while ( currentPtr != 0 ) // display elements in list
   {
       int i;
       string s;
       double d;
       char c;
       if (typeid(currentPtr->data).name() == typeid(i).name() ||
           typeid(currentPtr->data).name() == typeid(d).name() ||
           typeid(currentPtr->data).name() == typeid(s).name() ||
           typeid(currentPtr->data).name() == typeid(c).name())
       {
        // data value is a simple data type and can be printed
        cout << currentPtr->data << ' ';
       }
       else {
         cout <<"Can't print - Not a simple data type (int, string, char, double)\n";
       }
      currentPtr = currentPtr->nextPtr;
   } // end while

   cout << "\n\n";
} // end function print

   
// Display the contents of the List
template< typename NODETYPE >
NODETYPE * List< NODETYPE >::getInfo(int myKey)
{
   if ( isEmpty() ) // empty list
   {
      cout << "The list is empty\n\n";
      return NULL;
   } // end if

   ListNode< NODETYPE > *currentPtr = firstPtr;

   cout << "The list is: ";

   while ( currentPtr != 0 ) // display elements in list
   {
        if (currentPtr->key == myKey )  // found
           return (& currentPtr->data);
 
      currentPtr = currentPtr->nextPtr;
   } // end while

   return NULL;  // can't find
} // end function print



template< typename NODETYPE >
void printNoteInfo (  List< NODETYPE > & nodeList)
{   
   NODETYPE *wp;
   wp = (NODETYPE *) nodeList.getInfo(0); //get node based on key
   wp->printInfo();
 
 
   ListNode< NODETYPE > *currentPtr;
     
   currentPtr =  nodeList.getFirstPtr();
   
   cout << "The node list is: \n";
   //print out all the info in linked list
   while ( currentPtr != 0 ) // display elements in list
   {
      wp = (NODETYPE *) currentPtr; //convert to correct data type
      wp->printInfo();
      currentPtr = currentPtr->getNextPtr();
   } // end while
}   
         

   
/*
 * This is an example of person.
 * You can easily adept this for Wine program
 * 
 * I din't separate .cpp and .h files in this example.
 * 
 * HOWEVER, In your lab, you MUST separate implementation
 * file (.cpp source code) from the header file (.h) file.
 * 
 * */
 
class Person
{
public:
   Person();
   Person(string pname, int page);
   void set_name(string n) {name = n;};
   void set_age(int a) {age = a;};
   void set_info(string n, int a) {name = n; age=a;};
   string get_name() const;
   int get_age() const;
   void printInfo() { cout <<"Name: "<<name;
                    cout << "\tAge: "<<age<<endl; };
private:
   string name;
   int age; /* 0 if unknown */
};

Person::Person()
{
}

Person::Person(string pname, int page)
{
   name = pname;
   age = page;
}

string Person::get_name() const
{
   return name;
}

int Person::get_age() const
{
   return age;
}


void printPersonInfo(List< Person > & personList)
{
   Person *f;
   f = (Person *) personList.getInfo(0); //get node based on key
   f->printInfo();
 
 
    ListNode< Person > *currentPtr;
     
   currentPtr =  personList.getFirstPtr();
   
   cout << "The Employee list is: \n";
   //print out all the info in linked list
   while ( currentPtr != 0 ) // display elements in list
   {
      f = (Person *) currentPtr; //convert to correct data type
      f->printInfo();
      currentPtr = currentPtr->getNextPtr();
   } // end while
  
}


int main()
{
   int key;
   List< int > list1; // storage for first list
   List< int > list2; // storage for second list


// assign intger into first list, from 1 to 5 
   /*
    * Use insertAtBack function to add to linked list
    * YOU MUST USE insertAtBack in the wine lab, so YOU NEED TO
    * COMPLETE the insertAtBack methold.
    * */
    
   for (int i=0; i <5;  i++)
   {
	  key = i;  // key is an unique value, like your ID
    list1.insertAtBack( i, key );
 //     list1.insertAtBack( i, key ); //YOU MUST IMPLEMENT THIS FUNCTION
   }
   
    
   
   // call function print to print the list
   list1.print();

   // assign from 5 to 10 into second list
      /*
    * Use insertAtFront function to add to linked list
    * */
   for (int i=5; i<10;   i++ )
   {
	  key = i;  // key is an unique value, like your ID
      list2.insertAtFront( i, key );
   }
   list2.print();



	/*
	 * Following code could be adept for your Wine program to 
	 * place data into the linked list.
	 * 
	 * You must use insertAtBack() function to place wine info 
	 * into the linked list
	 * */
	 
	 
   Person p;
   List< Person > personList;
 
   
   p.set_info("Ron", 22);
   personList.insertAtFront( p,0 );
   p.set_info("Sha", 30);
   personList.insertAtFront( p,1 );	
   p.set_info("John", 35);
   personList.insertAtFront( p,2 );	

   printNoteInfo (personList);

   // remove last node from Linked List
   // you need to implement removeFromBack method function
   
   // personList.removeFromBack(p);

   personList.removeFromFront(p);  // remove the first node
   printNoteInfo (personList);  
   
} // end main





