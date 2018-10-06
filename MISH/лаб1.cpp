#include <iostream>

using namespace std;

struct X{
    int a;
    X* next;
    bool enter_num();
    bool check_deg();
};



bool X::enter_num(){
    cin >> a;
    if(a == 0)
        return(false);
    else
        return(true);
}

bool X::check_deg(){
    if(a && !(a&(a-1)) ) 
        return(true);
    else
        return(false); 
}

int count_nods(X* head){
    
    X* node = head;
    int summ = 0;
    int summ_deg = 0;
    while(node!=NULL){
        summ += node->a;
        if(node->check_deg()){
            summ_deg += 1;
        }
        node = node->next;
        
    }
    cout << "summ : " << summ << endl;
    cout << "summ_deg : " << summ_deg << endl;
    return(0);
}

int main(){
    X* head = NULL;
    X* node = NULL;
    X* buf = NULL;
    bool flag = 1;
    while(flag){
    
        if(head == NULL){
            head = new X;
            head->next = NULL;
            node = head;
            cout << "enter_num : ";
            flag = node->enter_num();
        }
        else{
            buf = node;
            node = new X;
            buf->next = node;
            cout << "enter_num : ";
            flag = node->enter_num();
        }
    }
    
    count_nods(head);
    
    return(0);
}
