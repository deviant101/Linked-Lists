#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(){
            data=99;
            next=nullptr;
        }
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

        void insert(int val){
            if(head==nullptr){
                Node* newNode=new Node;     //inserts at start/head when LinkedList is empty
                newNode->data=val;
                head=newNode;
                tail=newNode;
            }
            else{
                Node* newNode=new Node;     //inserts at end/tail when LinkedList has any no. of nodes
                newNode->data=val;
                tail->next=newNode;
                tail=newNode;
            }
        }

        int search(int val){
            Node* temp=head;
            int count=0;
            while(temp!=nullptr){
                ++count;
                if(temp->data==val)
                    return count;

                temp=temp->next;
            }
            return -1;
        }

        void deleteNode(int pos){
            Node* temp=head;
            if(pos==1){                 //for Node deletion from start
                Node* temp=head;
                head=head->next;
                delete temp;
                cout<<"\nDeletion Successful\n\n";
                return;
            }
            else{
                int count=0;
                while(temp!=nullptr){   //for Node deletion from 2 to last node
                    ++count;
                    if(count+1==pos){
                        Node* delNode=temp->next;
                        // cout<<temp->next->next<<endl;    //for checking addresses
                        temp->next=temp->next->next;
                        delete delNode;
                        cout<<"\nDeletion Successful\n\n";
                        return;
                    }
                    temp=temp->next;
                }
                cout<<"\nIncorrect Position Passed\n\n";
                return;
            }
        }

        void deleteAll(){       //deleteall can also be put in Destructor
            if(head==nullptr)
                cout<<"\nLinkedList Already Empty\n\n";
            else{
                while(head!=nullptr){
                    Node* temp=head;    //temp points to head node for deletion purposes
                    head=head->next;    //moving head to next node
                    delete temp;        //deleting node which was head before moving head to next node
                }
                cout<<"\nSuccessfully Deleted LinkedList\n\n";
            }
        }

        void Display(){
            Node* temp=head;    
            while(temp!=nullptr){
                cout<<"Data: "<<temp->data<<endl;
                temp=temp->next;
            }
        }
};

int main(){

    LinkedList l1;
    l1.Display();
    l1.insert(10);
    l1.insert(20);
    l1.insert(30);
    l1.insert(40);
    cout<<"Search Index Result: "<<l1.search(30)<<endl;
    l1.Display();
    l1.deleteNode(2);
    cout<<"Search Index Result: "<<l1.search(30)<<endl;     //index of 30 will be changed after node deletion before it
    l1.Display();
    l1.deleteAll();
    l1.Display();

    return 0;
}