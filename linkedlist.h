#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;
class IndexOutOfBound{
                private:
                        int start = 0;
                        int end;
                        int index;
                        string problem;
                        string solution;
                public:
                        IndexOutOfBound(int start, int end, int index, string problem, string solution){
                                this->start = start;
                                this->end = end;
                                this->index = index;
                                this->problem = problem;
                                this->solution = solution;
                        }
                        void print(){
                                cout<<"start: "<<start<<endl;
                                cout<<"End: "<<end<<endl;
                                cout<<"Index: "<<index<<endl;
                                cout<<"Problem: "<<problem<<endl;
                                cout<<"Solution: "<<solution<<endl;
                        }

                        void getSolution(){
                                cout<<"Solution: "<<solution<<endl;
                        }
                        void getProblem(){
                                cout<<"Problem: "<<problem<<endl;
                        }


        };
//----class Node start----
        template <typename T>
        struct Node{
                public:
                        T value;
                        Node* next;
 			      Node* prev;
                        Node(T x){
                                value = x;
                                next = nullptr;
                                prev = nullptr;//null pointer NULL
                }

        };

//----class Node end----
template <typename T>
class LinkedList{
        private:
                Node<T>* head;
                Node<T>* tail;
                int length = 0;
        public:
                //----non-argument constructor start----
                LinkedList(){
                        head = nullptr;
                        tail = nullptr;

                }
                //----constructor end----

        //----destructor start(deletes all elements after running the program , to remove memory leaks)----
        ~LinkedList(){
                cout<<"---call of destructor---"<<endl;
                if(head != nullptr){
                        while(head != tail){
                                        head = head->next;
                                        delete head->prev;
                        }
                        delete head;
        	    }
	  }
        //----destructor end----
                //----is empty start(checks linked list to find out if it's empty)----
		    bool isEmpty(){
                        if(head == nullptr){
                                return true;
                        }else{
                                return false;
                        }
                }
                //----is empty end----

                //----addFront start(creates element and adds it from the front of linked list by (value))----
                void addFront(T val){
                        Node<T>* temp = new Node<T>(val);
                        if(tail==nullptr){
                                head = temp;
				tail = temp;
                        }else{
                                head->prev = temp;
                                temp->next = head;
                                head = temp;
                        }
                        length++;
                }
                //----addFront end----

                //----print Reverce start(prints all elements of linked list Reverce)----
                void printRev(){
                Node<T>* t = tail;
                        while(t!=nullptr){
                                cout<<t->value<<endl;
                                t = t->prev;
                        }
                }
                //----print reverce end----

                //----remove Back start(removes elements from the Back of linked list)----
                bool removeBack(){
                        bool b = false;
                        if(head == nullptr){
                                return false;
                        }else if(head == tail){
                                delete head;
                                head = nullptr;
                                tail = nullptr;
                                length--;
                                return true;
                        }else{
                                tail = tail->prev;
                                delete tail->next;
                                tail->next = nullptr;
                                length--;
                                return true;
                        }

                }
                //----remove Back end----

                //----remove Front start(removes elements from the front of linked list)----
                bool removeFront(){
                        bool c = false;
                        if(head == nullptr){
                                return false;
                        }else if(head == tail){
                                delete head;
                                head = nullptr;
                                tail = nullptr;
                                length--;
                                return true;
                        }else{
                                head = head->next;
                                delete head->prev;
                                head->prev = nullptr;
                                length--;
                                return true;
                        }

                }
                //----remove Front end----

                //----operator== start(finds element by index)----
                T operator[](int hamar){
                        if(hamar<0 || hamar>=length){
                                IndexOutOfBound x(0, length, hamar, "You have crossed the border", "Enter an index in the border of linkedlist");
                                throw x;
                        }

                        Node<T>* p = head;
                        for(int i = 0;i<hamar;i++){
                                p = p->next;
                        }
                        return  p->value;
 		    }
                //----operator== end----

                //----find start(finds element by value)----
                bool find(T tiv){
                Node<T>* t = head ;
                        while(t!=nullptr){
                                if(t->value == tiv){
                                        return true;
                                }
                                t = t->next;

                        }
                        return false;
                }
                //----find end----

                //----remove start(removes element by index)----
                void remove(int hamar){
                        Node<T>* p = head;
                        for(int i = 1;i<hamar;i++){
                                p = p->next;
                        }
                        p->prev->next = p->next;
                        p->next->prev = p->prev;
                        delete p;

                }
                //----remove end----

                //----add start(creats element and adds it in linked list by value and index)----
                void add(T val, int hamar){
                        Node<T>* p = new Node<T>(val);
                        Node<T>* it = head;
                                for(int i = 1;i<hamar;i++){
                                        it = it->next;
                                }
                                it->prev->next = p;
				p->prev = it->prev;
                                p->next = it;
                                it->prev = p;
                }
                //----add end----
		
		void merge(LinkedList& a){
                if(a.head!=nullptr){
                        tail->next=a.head;
                        a.head->prev=tail;
                        a.head=nullptr;
                        tail=a.tail;
                        a.tail=nullptr;
                        for(Node<T>* temp=head;temp->next!=nullptr;temp=temp->next){
                                if(temp->value > temp->next->value){
                                        T c = temp->value;
                                        temp->value=temp->next->value;
                                        temp->next->value=c;
                                        temp=head;
                                	}
                        	}
               	 	}
	        }
		void insertionSort(){
               		bool change = false;
               		if(tail->value < head->value){
                       		 Node<T>* temp=tail->prev;
               	       		 tail->next=head;
                       		 head->prev=tail;
                       		 temp->next=nullptr;
                        	 tail->prev=nullptr;
                        	 head=tail;
                        	 tail=temp;
                         	 change=true;
               		}
                for(Node<T>* temp = tail;temp!=head;temp=temp->prev){
                        if(temp->value < head->value && temp!=tail){
                                temp->prev->next=temp->next;
                                temp->next->prev=temp->prev;
                                temp->next=head;
                                head->prev=temp;
                                head=temp;
                        }else{
                                for(Node<T>* temp1=head;temp1!=temp;temp1=temp1->next){
                                        if(temp->value < temp1->next->value){
                                                if(temp==tail){
                                                        tail=temp->prev;
                                                        temp->prev->next=nullptr;
                                                        temp->prev=temp1;
                                                        temp->next=temp1->next;
                                                        temp1->next->prev=temp;
                                                        temp1->next=temp;
                                                        change=true;
                                                        break;
                                                }
                                                temp->prev->next=temp->next;
                                                temp->next->prev=temp->prev;
                                                temp->prev=temp1;
                                                temp->next=temp1->next;
                                                temp1->next->prev=temp;
                                                temp1->next=temp;
                                                change =true;
                                                break;
                                        }
                                }
                        }
                }
                if(change){
                        insertionSort();
                }
        }
		friend ostream& operator<<(ostream& tpel, const LinkedList& linked){
                        Node<T>* temp = linked.head;
			cout<<"------"<<endl;
                        while(temp!=nullptr){
                                cout<<temp->value<<endl;
                                temp = temp->next;
                        }
			return tpel;
                }
		friend istream& operator>>(istream& lcnel,LinkedList& linked){
                        T val;
                        lcnel>>val;
                        Node<T>* temp= new Node<T>(val);
                        if(linked.head==nullptr){
                                linked.head = linked.tail = temp;
                        }else{
                                linked.tail->next=temp;
                                temp->prev=linked.tail;
                                linked.tail=temp;
                        }
                        linked.length++;
                        return lcnel;
                }
			
};

#endif
