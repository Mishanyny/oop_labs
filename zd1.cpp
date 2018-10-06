#include <iostream>
#include <math.h>

using namespace std;


struct X
{
    int number;
    X* p_next;
    void set_num_from_keyboard();
    bool check_grade_of_num_two();

};


void X::set_num_from_keyboard()
{
    cout<<"Enter the num."<<endl;
    cin>>number;
};


bool X::check_grade_of_num_two()
{
    if (number && !(number & (number-1))) return true;
    else return false;
};


void count(X* p_head)
{
    X* itr = p_head;
    int sum = 0;
    int grad = 0;
    while (itr != NULL)
    {
        sum += itr->number;
        if (itr->check_grade_of_num_two()) grad++;
        X* buf = itr;

        itr = itr->p_next;
        delete buf;
    };

    cout<<"stepeni 2:"<<grad<<endl;
    cout<<"sum:"<<sum<<endl;
        

}


int main()
{
    X* p_head = NULL;

    while (true)
    {
        X* p_current = new X;
        p_current->set_num_from_keyboard();
        if (p_head == NULL)
            {
                p_head = p_current;
                p_current->p_next = NULL;
            }
        else
            {
                p_current->p_next = p_head;
                p_head = p_current;
            };
        if (p_current->number == 0) break;

    };
    
    count(p_head);

    return 0;
};

