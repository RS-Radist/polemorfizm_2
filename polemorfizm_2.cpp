//Создать базовый класс список. Реализовать на базе списка стек и очередь с виртуальными функциями вставки и вытаскивания.
//Заметь! Это задание самостоятельное, не относиться к заданию, контейнеры.

#include <iostream>
using namespace std;
class List
{
public:
    virtual void Push(int x)
    {}
    virtual void Pop()
    {}
    virtual void Show()
    {}
    
};
class Stack : public List
{
private:
    int stack[10];
    int size;
public:
    Stack() : size(0)
    {}
    int GetSize()
    {
        return size;
    }
    void Push(int x)
    {
        if (size<10)
        {
            stack[size] = x;
            size++;
        }
        else
        {
            std::cout << "Stack overflow!\n";
        }
    }
    
    void Pop()
    {
        size--;
        if (size==-1)
        {
            std::cout<<"список пуст";
        }
        
    }
    int Peek()
    {
        if (size==0)
        {
            std::cout<< "Вершины нет";
            return -1;
        }
        return stack[size];
    }
    bool Emptiness()
    {
        if (size==0)
        {
            std::cout<<"Стек пустой";
            return false;
        }
        else
            std::cout<<"Стек полный";
        return true;
    }
    
    void Show()
    {
        for (int i=0;i<size;++i)
        {
            cout<<stack[i]<<" ";
        }
    }
    
    
};
class Queue : public List
{
    private:
        
        int size;
        int arr[10];
        int end,begin;
    public:
        Queue():size(0)
        {}
        void Push(int x)
        {
            if (size==0){
                arr[0]=x;
                size++;
            }
            else
            {
                int temp[size];
                int k=1;
                for (int i=0;i<size;++i)
                {
                    temp[k]=arr[i];
                    k++;
                }
                temp[0]=x;
                for (int i=0;i<size+1;++i)
                {
                    arr[i]=temp[i];
                }
                size++;
            }
        }
        void Show()
        {
            for (int i=0;i<size;++i)
            {
                cout<<arr[i]<<" ";
            }
        }
        void End()
        {
            int max=-1;
            for (int i=0;i<size;++i)
            {
                if (max<i)
                {
                    end=arr[i];
                }
            }
            cout<<end;
        }
        void Begin()
        {
            begin=arr[0];
            cout<<begin;
        }
        void Pop()
        {
            if (size==0)
            {
                cout<<"Очередь пустая";
                return;
            }
            int temp[size-1];
            int k=0;
            for (int i=0;i<size;++i)
            {
                temp[k]=arr[i+1];
                k++;
            }
            size--;
            for (int i=0;i<size;++i)
            {
                arr[i]=temp[i];
            }
        }
        int ClearQueue()
        {
            //Нужно сдедать
            return 0;
        }
   
};

int main()
{
      Queue queue;
      queue.Push(5);
      queue.Push(30);
//    qu.Push(50);
//    qu.Pop();
//    qu.Show();
    
      Stack stack;
      stack.Push(550);
      stack.Push(50);
//    st.Push(60);
//    st.Push(70);
//    st.Pop();
//    st.Show();
    
    
    List* list;
    list=&stack;
    list->Push(10);
    list->Pop();
    list->Show();
    cout<<endl;
    list=&queue;
    list->Push(10);
    list->Pop();
    list->Show();
    
}
