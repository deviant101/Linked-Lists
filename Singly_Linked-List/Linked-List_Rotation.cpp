#include <iostream>
using namespace std;

class Node{
    public:
        int Data;
        Node *next;

        Node(int data=10){
            Data=data;
            next=nullptr;
        }
};

class LinkedList{
    private:
        Node *head;

    public:
        LinkedList(){
            head=nullptr;
        }

        void insert(int n){
            Node *newNode=new Node;
                newNode->Data=n;
            if(head==nullptr){
                head=newNode;
            }
            else{
                Node *ptr=head;
                while(ptr->next!=nullptr){
                    ptr=ptr->next;
                }
                ptr->next=newNode;
            }
        }

        void Print(){
            Node *ptr=head;
            while(ptr!=nullptr){
                cout<<ptr->Data<<" ";
                ptr=ptr->next;
            }
            cout<<endl;
        }

        void rotatePosition(int rotations){
            for(int i=0; i<rotations; ++i){
                Node *ptr=head;
                while(ptr->next->next!=nullptr){
                    ptr=ptr->next;
                }
                ptr->next->next=head;
                head=ptr->next;
                ptr->next=nullptr;
            }
        }

        ~LinkedList(){
            Node *ptr=nullptr;

            while(head!=nullptr){
                ptr=head;
                head=head->next;
                delete ptr;
            }
            if(head==nullptr)
                cout<<"LinkedList Deleted Successfully\n";
            else
                cout<<"Deletion Failed!!\n";

        }
};

int main(){

    LinkedList l1;
    l1.insert(1);
    l1.insert(2);
    l1.insert(3);
    l1.insert(4);
    l1.insert(5);
    l1.Print();
    l1.rotatePosition(2);
    l1.Print();

    return 0;
}