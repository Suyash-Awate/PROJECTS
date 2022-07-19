///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include<iostream>
using namespace std;

template<typename T>
struct s_node
{
	T data;
	struct s_node*next;
};

template<class T>
class SinglyLL
{
	private:
	   s_node <T>*first;
	   int size;
	   
	public:
	   SinglyLL();
	   void InsertFirst(T);
	   void InsertLast(T);
	   void InsertAtPos(T,int);
	   void DeleteFirst();
	   void DeleteLast();
	   void DeleteAtPos(int);
	   void Display();
	   int Count();
	  
};

template<class T>
SinglyLL<T>::SinglyLL()
	   {
		   first = NULL;
		   size = 0;
	   }

template<class T>	   
void SinglyLL<T>::InsertFirst(T no)
	   {
		   s_node<T> *newn = new s_node<T>;
		   
		   newn->data = no;
		   newn->next = NULL;
		   
		   if(first == NULL)
		   {
			   first = newn;
		   }
		   else
		   {
			   newn->next = first;
			   first = newn;
		   }
		   
		   size++;   
	   }

template<class T>	   
void SinglyLL<T>::InsertLast(T no)
	   {
		   s_node<T> *newn = new s_node<T>;
		   
		   newn->data = no;
		   newn->next = NULL;
		   
		   if(first == NULL)
		   {
			   first = newn;
		   }
		   else
		   {
			   s_node<T> *temp = first;
			   
			   while(temp->next!=NULL)
			   {
				   temp = temp->next;
			   }
			   temp->next = newn;
		   }
		   
		   size++;
	   }

template<class T>	   
void SinglyLL<T>::DeleteFirst()
	   {
		   s_node<T> *temp = first;
		   
		   if(first!=NULL)
		   {
			   first = first->next;
			   delete temp;
			   
			   size--;
		   }
	   }

template<class T>	   
void SinglyLL<T>::DeleteLast()
	   {
		   s_node<T> *temp = first;
		   
		   if(first==NULL)
		   {
			   return;
		   }
		   else if(first->next==NULL)
		   {
			   delete first;
			   first = NULL;
			   size--;
		   }
		   else
		   {
			   while(temp->next->next!=NULL)
			   {
				   temp = temp->next;
			   }
			   
			   delete temp->next;
			   temp->next = NULL;
			   size--;
		   }
	   }

template<class T>	   
void SinglyLL<T>::InsertAtPos(T no,int iPos)
        {
	        if((iPos<1)||(iPos>size+1))       //Filter for invalid position
	            {
		           printf("Invalid Position\n");
		           return;
	            }
	
	        if(iPos==1)                     //At first position
	            {
	             	InsertFirst(no);
	            }
	        else if(iPos==(size+1))          // At last position
	            {
	               	InsertLast(no);
	            }
	        else                        // Inbetween position
	            {
					int i = 0;
	            
				    s_node<T> *temp = first;
	              	s_node<T> *newn = new s_node<T>;
		
		            newn->data = no;
		            newn->next = NULL;
		
		            for(i=1;i<(iPos-1);i++)
		               {
		                   	temp = temp->next;
		               }
		
		            newn->next = temp->next;
		            temp->next = newn;
					
					size++;
	            }
				
        }

template<class T>	   
void SinglyLL<T>::DeleteAtPos(int iPos)
	   {
		   if((iPos<1)||(iPos>size))
		   {
			   printf("Invalid Position\n");
			   return;
		   }
		   
		   if(iPos==1)
		   {
			   DeleteFirst();
		   }
		   else if(iPos==size)
		   {
			   DeleteLast();
		   }
		   else
		   {
			   s_node<T> *temp = first;
			   int i = 0;
			   s_node<T> *targated = NULL;
			   
			   for(i=1;i<(iPos-1);i++)
			   {
				   temp = temp->next;
			   }
			   
			   targated = temp->next;
			   
			   temp->next = targated->next;
			   delete targated;
			   
			   size--;
		   }
	   }

template<class T>	   
void SinglyLL<T>::Display()
	   {
		   s_node<T> *temp = first;
		   
		   while(temp!=NULL)
		   {
			   cout<<temp->data<<"\t";
			   temp = temp->next;
		   }
		   cout<<"\n";
	   }

template<class T>	   
int SinglyLL<T>::Count()
	   {
		   return size;
	   }


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


template<class T>
class SinglyCL
{
	private:
	   s_node<T> *first;
	   s_node<T> *last;
	   int size;
	   
	public:
	   SinglyCL();
	   void InsertFirst(T);
	   void InsertLast(T);
	   void InsertAtPos(T,int);
	   void DeleteFirst();
	   void DeleteLast();
	   void DeleteAtPos(int);
	   void Display();
	   int Count();
	  
};

       template<class T>
       SinglyCL<T>::SinglyCL()
	   {
		   first = NULL;
		   last = NULL;
		   size = 0;
	   }
	   
	   template<class T>
	   void SinglyCL<T>::Display()
	   {
		   s_node<T> *temp = first;
		   
		   if((first==NULL)&&(last==NULL))
		   {
			   return;
		   }
		   
		   do
		   {
			   cout<<"| "<<temp->data<<" |"<<"->";
			   temp = temp->next;
		   }while(temp!=last->next);
		   cout<<"\n";
	   }
	   
	   template<class T>
	   int SinglyCL<T>::Count()
	   {
		   return size;
	   }
	   
	   template<class T>
	   void SinglyCL<T>::InsertFirst(T no)
	   {
		   s_node<T> *newn = new s_node<T>;
		   
		   newn->data = no;
		   newn->next = NULL;
		   
		   if((first==NULL)&&(last==NULL))
		   {
			   first = newn;
			   last = newn;
		   }
		   else
		   {
			   newn->next = first;
			   first = newn;
		   }
		   last->next = first;
		   size++;
	   }
	   
	   template<class T>
	   void SinglyCL<T>::InsertLast(T no)
	   {
		   s_node<T> *newn = new s_node<T>;
		   
		   newn->data = no;
		   newn->next = NULL;
		   
		   if((first==NULL)&&(last==NULL))
		   {
			   first = newn;
			   last = newn;
		   }
		   else
		   {
			   last->next = newn;
			   last = newn;
		   }
		   last->next = first;
		   size++;
	   }
	   
	   template<class T>
	   void SinglyCL<T>::InsertAtPos(T no,int iPos)
	   {
		   if((iPos<1)||(iPos>(size+1)))    // filter
		   {
			   return;
		   }
		   
		   if(iPos==1)
		   {
			   InsertFirst(no);
		   }
		   else if(iPos==size+1)
		   {
			   InsertLast(no);
		   }
		   else
		   {
			   s_node<T> *newn = new s_node<T>;
			   newn->data = no;
			   newn->next = NULL;
			   
			   s_node<T> *temp = first;
			   
			   for(int i=1;i<(iPos-1);i++)
			   {
				   temp = temp->next;
			   }
			   
			   newn->next = temp->next;
			   temp->next = newn;
			   
			   size++;
		   }
	   }
	   
	   template<class T>
	   void SinglyCL<T>::DeleteFirst()
	   {
		   if((first==NULL)&&(last==NULL))
		   {
			   return;
		   }
		   else if(first==last)
		   {
			   delete first;
			   first = NULL;
			   last = NULL;
		   }
		   else
		   {
			   first = first->next;
			   delete last->next;
			   last->next = first;
		   }
		   size--;
	   }
	   
	   template<class T>
	   void SinglyCL<T>::DeleteLast()
	   {
		   s_node<T> *temp = first;
		   
		   if((first==NULL)&&(last==NULL))
		   {
			   return;
		   }
		   else if(first==last)
		   {
			   delete first;
			   first = NULL;
			   last = NULL;
		   }
		   else
		   {
			   while((temp->next)!=last)
			   {
				   temp = temp->next;
			   }
			   
			   delete last;
			   last = temp;
			   last->next = first;
		   }
		   size--;
	   }
	   
	   template<class T>
	   void SinglyCL<T>::DeleteAtPos(int iPos)
	   {
		   if((iPos<1)||(iPos>size))
		   {
			   return;
		   }
		   
		   if(iPos==1)
		   {
			   DeleteFirst();
		   }
		   else if(iPos==size)
		   {
			   DeleteLast();
		   }
		   else
		   {
			   s_node<T> *temp = first;
			   
			   for(int i=1;i<(iPos-1);i++)
			   {
				   temp = temp->next;
			   }
			   
			   s_node<T> *targated = temp->next;
			   temp->next = targated->next;
			   delete targated;
			   
			   size--;			   
		   }
	   }  
	   
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




template<typename T>
struct d_node
{
	T data;
	struct d_node*next;
	struct d_node*prev;
};

template<class T>
class DoublyLL
{
	private:
	   d_node<T> *first;
	   int size;
	   
	public:
	    DoublyLL();
		void InsertFirst(T);
		void InsertLast(T);
		void InsertAtPos(T,int);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int);
		void Display();
		int Count();
	  
};

template<class T>
 DoublyLL<T>::DoublyLL()
	   {
		   first = NULL;
		   size = 0;
	   }

template<class T>	   
void DoublyLL<T>::InsertFirst(T no)
	   {
		   d_node<T> *newn = new d_node<T>;
		   
		   newn->data = no;
		   newn->next = NULL;
		   newn->prev = NULL;
		   
		   if(first == NULL)
		   {
			   first = newn;
		   }
		   else
		   {
			   newn->next = first;
			   first->prev = newn;
			   
			   first = newn;
		   }
		   
		   size++;   
	   }
	   
template<class T>
void DoublyLL<T>::InsertLast(T no)
	   {
		   d_node<T> *newn = new d_node<T>;
		   
		   newn->data = no;
		   newn->next = NULL;
		   newn->prev = NULL;
		   
		   if(first == NULL)
		   {
			   first = newn;
		   }
		   else
		   {
			   d_node<T> *temp = first;
			   
			   while(temp->next!=NULL)
			   {
				   temp = temp->next;
			   }
			   temp->next = newn;
			   newn->prev = temp;
		   }
		   
		   size++;
	   }

template<class T>	   
void DoublyLL<T>::DeleteFirst()
	   {
		   d_node<T> *temp = first;
		   
		   if(first==NULL)
		   {
			   return;
		   }
		   else if(first->next==NULL)
		   {
			   delete temp;
			   first = NULL;
			   
			   size--;
		   }
		   else
		   {
			   first = first->next;
			   delete temp;
			   first->prev = NULL;
			   
			   size--;
		   }
	   }

template<class T>	   
void DoublyLL<T>::DeleteLast()
	   {
		   d_node<T> *temp = first;
		   
		   if(first==NULL)
		   {
			   return;
		   }
		   else if(first->next==NULL)
		   {
			   delete first;
			   first = NULL;
			   size--;
		   }
		   else
		   {
			   while(temp->next->next!=NULL)
			   {
				   temp = temp->next;
			   }
			   
			   delete temp->next;
			   temp->next = NULL;
			   size--;
		   }
	   }

template<class T>	   
void DoublyLL<T>::InsertAtPos(T no,int iPos)
        {
	        if((iPos<1)||(iPos>size+1))       //Filter for invalid position
	            {
		           printf("Invalid Position\n");
		           return;
	            }
	
	        if(iPos==1)                     //At first position
	            {
	             	InsertFirst(no);
	            }
	        else if(iPos==(size+1))          // At last position
	            {
	               	InsertLast(no);
	            }
	        else                        // Inbetween position
	            {
					int i = 0;
	                d_node<T> *newn = new d_node<T>;
					d_node<T> *temp = first;
		
		            newn->data = no;
		            newn->next = NULL;
					newn->prev = NULL;
		
		            for(i=1;i<(iPos-1);i++)
		               {
		                   	temp = temp->next;
		               }
		
		            newn->next = temp->next;
					temp->next->prev = newn;
		            temp->next = newn;
					newn->prev = temp;
					
					size++;
	            }
				
        }

template<class T>	   
void DoublyLL<T>::DeleteAtPos(int iPos)
	   {
		   if((iPos<1)||(iPos>size))
		   {
			   printf("Invalid Position\n");
			   return;
		   }
		   
		   if(iPos==1)
		   {
			   DeleteFirst();
		   }
		   else if(iPos==size)
		   {
			   DeleteLast();
		   }
		   else
		   {
			   d_node<T> *temp = first;
			   int i = 0;
			   d_node<T> *targated = NULL;
			   
			   for(i=1;i<(iPos-1);i++)
			   {
				   temp = temp->next;
			   }
			   
			   targated = temp->next;
			   
			   temp->next = targated->next;
			   targated->next->prev = temp;
			   delete targated;
			   
			   size--;
		   }
	   }

template<class T>	   
void DoublyLL<T>::Display()
	   {
		   d_node<T> *temp = first;
		   
		   while(temp!=NULL)
		   {
			   cout<<temp->data<<"\t";
			   temp = temp->next;
		   }
		   cout<<"\n";
	   }

template<class T>	   
int DoublyLL<T>::Count()
	   {
		   return size;
	   }


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




template<class T>
class DoublyCL
{
	private:
	    d_node<T> *first;
		d_node<T> *last;
		int size;
		
    public:
	    DoublyCL()
		{
			first = NULL;
			last = NULL;
			size = 0;
		}
		
		void Display();
		int Count();
		void InsertFirst(T no);
		void InsertLast(T no);
		void InsertAtPos(T no,int iPos);
		void DeleteFirst();
		void DeleteLast();
		void DeleteAtPos(int iPos);
};

template<class T>
void DoublyCL<T>::Display()
{
	d_node<T> *temp = first;
	
	for(int i=1;i<=size;i++)
	{
		cout<<"| "<<temp->data<<" | -> ";
		temp = temp->next;
	}
	cout<<"\n";
}

template<class T>
int DoublyCL<T>::Count()
{
	return size;
}

template<class T>
void DoublyCL<T>::InsertFirst(T no)
{
	d_node<T> *newn = new d_node<T>;
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
	
	if((first==NULL)&&(last==NULL))
	{
		first = newn;
		last = newn;
	}
	else
	{
		newn->next = first;
		first->prev = newn;
		first = newn;
	}
	
	last->next = first;
	first->prev = last;
	size++;
}

template<class T>
void DoublyCL<T>::InsertLast(T no)
{
	d_node<T> *newn = new d_node<T>;
	newn->data = no;
	newn->next = NULL;
	newn->prev = NULL;
	
	if((first==NULL)&&(last==NULL))
	{
		first = newn;
		last = newn;
	}
	else
	{
		last->next = newn;
		newn->prev = last;
		last = newn;
	}
	
	last->next = first;
	first->prev = last;
	size++;
}

template<class T>
void DoublyCL<T>::InsertAtPos(T no,int iPos)
{
	if((iPos<1)||(iPos>(size+1)))
	{
		cout<<"Invalid input\n";
		return;
	}
	
	if(iPos==1)
	{
		InsertFirst(no);
	}
	else if(iPos==size+1)
	{
		InsertLast(no);
	}
	else
	{
		d_node<T> *newn = new d_node<T>;
		newn->data = no;
		newn->next = NULL;
		newn->prev = NULL;
		
		d_node<T> *temp = first;
		
		for(int i=1;i<(iPos-1);i++)
		{
			temp = temp->next;
		}
		
		newn->next = temp->next;
		newn->next->prev = newn;
		temp->next = newn;
		newn->prev = temp;
		
		size++;
	}
}

template<class T>
void DoublyCL<T>::DeleteFirst()
{
	if((first==NULL)&&(last==NULL))
	{
		return;
	}
	else if(first==last)
	{
		delete first;
		first = NULL;
		last = NULL;
	}
	else
	{
		first = first->next;
		delete last->next;
		
		first->prev = last;
	    last->next = first;
	}
	
	size--;
}

template<class T>
void DoublyCL<T>::DeleteLast()
{
	if((first==NULL)&&(last==NULL))
	{
		return;
	}
	else if(first==last)
	{
		delete first;
		first = NULL;
		last = NULL;
	}
	else
	{
		last = last->prev;
		delete last->next;
		
		first->prev = last;
	    last->next = first;
	}
	size--;
}

template<class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
	if((iPos<1)||(iPos>size))
	{
		cout<<"Invalid input\n";
		return;
	}
	
	if(iPos==1)
	{
		DeleteFirst();
	}
	else if(iPos==size)
	{
		DeleteLast();
	}
	else
	{
		d_node<T> *temp = first;
		
		for(int i=1;i<(iPos-1);i++)
		{
			temp = temp->next;
		}
		
		temp->next = temp->next->next;
		delete temp->next->prev;
		temp->next->prev = temp;
		
		size--;
	}
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Stack


template<class T>
class Stack     // Singly Linear Linked List
{
private:
    s_node <T>*first;
    int size;
    
public:
    Stack();
	void push(T);
	T pop();
	void Display();
	int Count();
};

    template<class T>
    Stack<T>::Stack()
    {
        first = NULL;
        size = 0;
    }
    
	template<class T>
    void Stack<T>::push(T no)   // InsertFirst()
    {
		s_node <T>*newn = new s_node <T>;
		
		newn->data = no;
		newn->next = NULL;
		
		if(first==NULL)
		{
			first = newn;
		}
		else
		{
			newn->next = first;
			first = newn;
		}
		size++;
	}
	
	template<class T>
    T Stack<T>::pop()   // DeleteFirst()
    {
		T no;
		s_node <T>*temp = first;
		
		if(first==NULL)          //(size==0)
		{
			cout<<"Stack is empty\n";
			return -1;
		}
		
		if(first->next==NULL)     //(size==1)
		{
			no = first->data;
			delete first;
			first = NULL;
		}
		else
		{
			no = first->data;
			first = first->next;
			delete temp;
		}
		
		size--;
		
		return no;
	}
    
	template<class T>
    void Stack<T>::Display()
    {
		s_node <T>*temp = first;
		
		cout<<"Elements of stack:\n";
		
		while(temp!=NULL)
		{
			cout<<"| "<<temp->data<<" |\n";
			temp = temp->next;
		}
		cout<<"\n";
	}
    
	template<class T>
    int Stack<T>::Count()
    {
        return size;
    }



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//Queue



template<class T>
class Queue     // Singly Linear Linked List
{
private:
    s_node <T>*first;
    int size;
    
public:
    Queue();
	void Enqueue(T);
	T Dequeue();
	void Display();
	int Count();
    
};

    template<class T>
    Queue<T>::Queue()
    {
        first = NULL;
        size = 0;
    }
    
	template<class T>
    void Queue<T>::Enqueue(T no)   // InsertLast()
    {
        s_node <T>*newn = new s_node <T>;
		
		newn->data = no;
		newn->next = NULL;
		
		if(size==0)
		{
			first = newn;
		}
		else
		{
			s_node <T>*temp = first;
			while(temp->next!=NULL)
			{
				temp = temp->next;
			}
			temp->next = newn;
		}
		size++;
    }
    
	template<class T>
    T Queue<T>::Dequeue()   // DeleteFirst()
    {
        T no;
		s_node <T>*temp = first;
		
		if(first==NULL)          //(size==0)
		{
			cout<<"Queue is empty\n";
			return -1;
		}
		
		if(first->next==NULL)     //(size==1)
		{
			no = first->data;
			delete first;
			first = NULL;
		}
		else
		{
			no = first->data;
			first = first->next;
			delete temp;
		}
		
		size--;
		
		return no;
    }
    
	template<class T>
    void Queue<T>::Display()
    {	
	    s_node <T>*temp = first;
		cout<<"Elements of Queue:\n";
		
		for(int i=1;i<=size;i++,temp = temp->next)
		{
			cout<<"| "<<temp->data<<" | ->";
		}
		cout<<"\n";
	}
    
	template<class T>
    int Queue<T>::Count()
    {
        return size;
    }






//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


























	