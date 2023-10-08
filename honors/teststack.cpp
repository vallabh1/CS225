// #include "stack.cpp"
#include <iostream>
#include <vector>
#include <stack>
template <class T>
class stack{
    public:

    stack(){
        return;
    }
    void push(T data){
        stackvector.push_back(data);
        return;
    }

    void pop(){
        stackvector.pop_back();
        return;
    }

    T top(){
        return stackvector.back();
    }

    bool empty(){
        return stackvector.empty();
    }

    void showstack(){
        if(empty()){
            std::cout<<"The stack is empty"<<std::endl;
        }
        else{
            std::cout<<"Contents of your stack are:"<<std::endl;
            for(auto it = stackvector.rbegin(); it != stackvector.rend(); ++it){
                std::cout<<(*it)<<std::endl;
            }
        }
    }

    private:
    std::vector<T> stackvector;
};

void loopstdstack(std::stack<int> stdstack){
    for(int i = 0;i<0xfffffff;i++){
        stdstack.push(i%2);
    stdstack.pop();
    }
    stdstack.push(9);
    std::cout<<stdstack.top();
}
void loopmystack(stack<int> stack){
    
    for(int i = 0;i<0xfffffff;i++){
        stack.push(i%2);
    stack.pop();
    }
    stack.push(9);
    std::cout<<stack.top();
}

int main(){
    stack<int> st1;
    std::stack<int> stdstack;
    loopstdstack(stdstack);
    loopmystack(st1);
    

    
    return 1;
}
