#ifndef PROJEKT_DATA_H
#define PROJEKT_DATA_H

#include <string>

class Data
{
    std::string move;

public:
    Data *prev;
    Data *next;
    Data(std::string _move) : prev(nullptr), next(nullptr)
    {
        move = _move;
    }
};

class DualList
{
    Data *head;
public:
    DualList() : head(nullptr)
    {
    }

    void AddElement(std::string data)
    {
        if (head == nullptr)
        {
            head=new Data(data);
        }
        else
        {
            Data *iterator = head;
            while (iterator->next)
            {
                iterator=iterator->next;
            }
            Data* x=new Data(data);
            iterator->next=x;
            x->prev=iterator;
        }
    }

    void DeleteElement()
    {

    }

    Data &operator[](int i)
    {
        Data* iterator=head;
        int j=1;
        while(iterator->next)
        {
            j++;
            iterator=iterator->next;
        }

        if((i>0)&&(i<j))
        {
            iterator=head;
            int k=1;
            while(iterator->next)
            {
                if(i==k)
                {
                    return *iterator;
                }
                iterator=iterator->next;
            }
        }
    }
    Data &operator()(int ruch,std::string color)
    {
        int i=ruch*2;
        if(color=="black")
        {
            i++;
        }
        Data* iterator=head;
        int j=1;
        while(iterator->next)
        {
            j++;
            iterator=iterator->next;
        }
        if((i>0)&&(i<j))
        {
            iterator=head;
            int k=1;
            while(iterator->next)
            {
                if(i==k)
                {
                    return *iterator;
                }
                iterator=iterator->next;
            }
        }
    }

};

#endif PROJEKT_DATA_H
