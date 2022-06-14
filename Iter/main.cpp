#include <iostream>




class Stack {
    int arr[10];
    int k;

public:
    friend class StackIter;

    Stack()
    {
        k = -1;
    }

    void push(int ind) { arr[++k] = ind; }
    int pop() { return arr[k--]; }
    bool isEmpty() { return k = -1; }
};




class StackIter {
    const Stack& arr1;
    int i1;

public:
    StackIter(const Stack& a) : arr1(a)
    {
        i1 = 0;
    }
    void operator++() { ++i1; }
    bool operator()() { return i1 != arr1.k + 1; }
    int operator *() { return arr1.arr[i1]; }
};




bool operator == (const Stack& i, const Stack& j)
{
    StackIter to_i(i), to_j(j);

    for (; to_i(); (++to_i, ++to_j))

        if (*to_i != *to_j)     break;

    return !to_i() && !to_j();
}






int main()
{
    Stack first_stack;

    for (int i = 1; i < 5; i++) first_stack.push(i);

    Stack second_stack(first_stack), third_stack(first_stack), fourth_stack(first_stack);

    third_stack.pop();
    fourth_stack.push(10);

    std::cout << "first_stack == second_stack? "; std::cout << (first_stack == second_stack) << std::endl;
    std::cout << "first_stack == third_stack? "; std::cout << (first_stack == third_stack) << std::endl;
    std::cout << "first_stack == fourth_stack? "; std::cout << (first_stack == fourth_stack) << std::endl;


    return 0;
}

