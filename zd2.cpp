#include <iostream>

using namespace std;


class DinArr
{

    public:
    int size;

    DinArr();
    DinArr(int len);
    DinArr(DinArr &arr);
    ~DinArr();

    int operator[](int i)const;
    int operator[](int i);
    DinArr operator=(DinArr array);

    void key_input();

    friend void avarage(const DinArr& obj);
       
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


DinArr::DinArr(DinArr &array)
{
    arr = new int[array.size];
    size = array.size;

    for(int i=0; i<array.size; i++)
    {
        arr[i] = array.arr[i];
    }
    
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


int DinArr::operator[](int i)
{
    return arr[i];
}


DinArr DinArr::operator=(DinArr array)
{
    delete this->arr;

    this->arr = new int[array.size];
    this->size = array.size;
    
    for(int i=0; i<array.size; i++)
    {
        this->arr[i] = array.arr[i];
    }
    
    return *this;
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
    //copy constructor
    DinArr array_two = array;

    avarage(array_two);
    found_min(array_two);
    
    DinArr new_array(7);
    new_array.key_input();
    avarage(new_array);
    found_min(new_array);
    
    array =  new_array;

    avarage(array);
    found_min(array);    
    
    return 0;
}
