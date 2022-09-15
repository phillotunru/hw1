#include "split.h"
#include "split.cpp"
#include<bits/stdc++.h>

int main(){
   Node* p = new Node(1, nullptr);
   Node* cur = p;
   for (int i = 2; i < 10; i++ ){
     cur->next = new Node(i, nullptr);
     cur = cur->next;
   }
   Node* a;
   Node* b;
   split(p, a, b);
   delete p;
   while(!(a==nullptr)){
     cout << a->value;
     Node* temp = a->next;
     delete a;
     a = temp;
     
   }
   cout << endl;
   while(!(b==nullptr)){
     cout << b->value;
     Node* temp = b->next;
     delete b;
     b = temp;
   }
  
}
