#include<bits\stdc++.h>
using namespace std;


int main(){
    deque<int> dq={1,2,3,4,5};

    cout<<"Front element : "<< dq.front()<<endl;
    cout<<"Back element : "<< dq.back()<<endl;

    for(auto it=dq.begin();it!=dq.end();it++){
        cout<<*it<<"  ";
    }

    // traversing in reverse
     for(auto it=dq.rbegin();it!=dq.rend();it++){
        cout<<*it<<"  ";
    }
    return 0;
}