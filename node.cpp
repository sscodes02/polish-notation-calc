#include <iostream>
#include "node.h"
using namespace std;

    Node::Node(bool sentinel){
        is_sentinel=sentinel;
        next=NULL;
        prev=NULL;
    }
    Node::Node(int v, Node* nxt, Node* prv){
        is_sentinel=false;
        value=v;
        next=nxt;
        prev=prv;

    }
    bool Node:: is_sentinel_node(){
      if(is_sentinel){
        return true;
      }
      else{
        return false;
      }
    }
    int Node:: get_value(){
        return value;
    }