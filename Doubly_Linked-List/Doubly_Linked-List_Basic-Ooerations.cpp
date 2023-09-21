#include <iostream>
using namespace std;

class Student{
    public:
        string StudentID;
        string StudentName;
        double CGPA;
        int Age;

        Student(string stdId="111", string stdName="XYZ", double gpa=2.5, int age=18){

            StudentID=stdId;
            StudentName=stdName;
            CGPA=gpa;
            Age=age;
        }
        void Display(){

            cout<<"Student ID: "<<StudentID<<endl
                <<"Student Name: "<<StudentName<<endl
                <<"Student CGPA: "<<CGPA<<endl
                <<"Student Age: "<<Age<<endl
                <<"-------------------------------"<<endl;
        }
};

class Node{
    public:
        Student data;
        Node* next;
        Node* prev;

        Node(){
            next=nullptr;
            prev=nullptr;
        }
        ~Node(){ }
};

class LinkedList{
    private:
        Node* head;
        Node* tail;
    public:
        LinkedList(){
	        head=nullptr;
	        tail=nullptr;
    	}
        void insert(const Student &data){

            Node* newNode=new Node;
            newNode->data.StudentID = data.StudentID;     //= overload || copy constructor
            newNode->data.StudentName = data.StudentName;
            newNode->data.CGPA = data.CGPA;
            newNode->data.Age = data.Age;

            if(head==nullptr){
                head=newNode;
                tail=newNode;
            }
            else{
                tail->next=newNode;
                newNode->prev=tail;
                tail=newNode;
            }
        }

        void remove(string id){
            if(head!=nullptr){

                Node *ptr=head;
                while(ptr!=nullptr){
                    if(ptr->data.StudentID==id){
                        if(ptr->prev==nullptr && ptr->next!=nullptr){       //1st node of Linked List
                            Node *delNode=ptr;
                            head=ptr->next;
                            head->prev==nullptr;
                            delete delNode;
                            return;
                        }
                        else if(ptr->next==nullptr && ptr->prev!=nullptr){      //last node of Linked List
                            Node *delNode=ptr;
                            tail=ptr->prev;
                            tail->next=nullptr;
                            delete delNode;
                            return;
                        }
                        else{
                            Node* delNode=ptr;              //from middle nodes
                            ptr->prev->next=ptr->next;
                            ptr->next->prev=ptr->prev;
                            delete delNode;
                            return;
                        }
                    }
                    ptr=ptr->next;
                }
            }
            else
                cout<<"\nLinked List is Empty\n\n";
        }

        void updateGPA(double gpa, string id){
            Node *temp=head;
            while(temp!=nullptr){
                if(temp->data.StudentID==id){
                    temp->data.CGPA=gpa;
                    return;
                }
                temp=temp->next;
            }
            cout<<"\nStudent ID does not exist!\n\n";
        }

        void clear(){
            Node *ptr=nullptr;
            while(head!=nullptr){
                ptr=head;
                head=head->next;
                delete ptr;
            }
            head=nullptr;
            tail=nullptr;
        }

        bool isEmpty(){
            if(head==nullptr && tail==nullptr)
                return true;
            else
                return false;
        }

        void Display(){

            if(head==nullptr && tail==nullptr)
                cout<<"\nLinkedList is Empty\n";
            else{
                Node *temp = head;
                while(temp->next!=nullptr){     //temp!=nullptr

                    temp->data.Display();
                    temp=temp->next;
                }
                temp->data.Display();
            }
                
        }
/*
        void sort(){
            Node *temp1=head;
            while(temp1->next!=nullptr){
                Node *temp2=temp1->next;
                while(temp2!=nullptr){
                    if(temp1->data.CGPA>temp2->data.CGPA)
                        temp2=temp2->next;
                }
                temp1=temp1->next;
            }
        }
*/
};


int main(){

    Student e1("123","Student-1",3.2,18);
    Student e2("456","Student-2",3.0,19);
    Student e3("789","Student-3",2.8,20);

    LinkedList l1;
    l1.insert(e1);
    l1.insert(e2);
    l1.insert(e3);
    l1.Display();

    cout<<"\nChecking Empty: "<<l1.isEmpty()<<"\n\n";

    l1.updateGPA(3.5,"123");

    l1.remove("456");
    l1.Display();

    l1.clear();
    cout<<"\nChecking Empty: "<<l1.isEmpty()<<"\n\n";

    return 0;
}

