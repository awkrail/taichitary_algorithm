#include "taichitary.h"

int main(){

    priority_queue<int> PQ;

    PQ.push(1);
    PQ.push(8);
    PQ.push(3);
    PQ.push(5);

    cout << PQ.top() << endl;

    PQ.pop();

    cout << PQ.top() << endl;
    
}