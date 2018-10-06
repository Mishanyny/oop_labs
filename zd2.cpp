#include <iostream>

using namespace std;


class DinArr
{

    public:
    int size;
    DinArr();
    DinArr(int len);
    ~DinArr();
    void key_input();
    friend void avarage(const DinArr& obj);
    
    int operator[](int i)const;
       
    private:
    int* arr;

};


DinArr::DinArr()
{
    size = 0;
    arr = NULL;
}


DinArr::DinArr(int len)
{
    size = len;
    arr = new int[size];
}

DinArr::~DinArr()
{
    if (arr!=NULL)
    {   
        delete arr;
    }
}


int DinArr::operator[](int i) const
{
    return arr[i];
}


void DinArr::key_input()
{
    for(int i=0; i<size; i++)
    {
        cout<<"enter a["<<i<<"]:";
        cin>>arr[i];
        cout<<endl;
    }
}


void avarage(const DinArr& obj)
{
    int amount = 0;
    for(int i=0; i<obj.size; i++)
    {
        amount += obj.arr[i];
    }
    int avarage = amount / obj.size;
    cout<<"Avarage:"<<avarage<<endl;
}


void found_min(const DinArr& obj)
{
    int min = obj[0];
    for(int i=1; i<obj.size; i++)
    {
        if(obj[i]<min)
        {
            min = obj[i];
        }
    }

    cout<<"Min:"<<min<<endl;
}


int main()
{
    DinArr array(5);
    array.key_input();
    avarage(array);
    found_min(array);
    
    return 0;
}
