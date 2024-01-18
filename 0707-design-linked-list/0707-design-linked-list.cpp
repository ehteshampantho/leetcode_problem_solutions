class MyLinkedList {
public:
    list<int> l;
    MyLinkedList() {
        
    }
    
    int get(int index) {
       if(index >= l.size()) return -1;
        else{
            int ans = *next(l.begin(),index);
            cout<< ans << " ";
            return ans;
        }
    }
    
    void addAtHead(int val) {
        l.push_front(val);
        cout << l.front() << " ";
    }
    
    void addAtTail(int val) {
        l.push_back(val);
        cout<< l.back() << " ";
    }
    
    void addAtIndex(int index, int val) {
        if(index == 0){
            addAtHead(val);
        }
        else if(index <= l.size()){
            l.insert(next(l.begin(),index),val);
            cout << *next(l.begin(),index) << " ";
        }
    }
    
    void deleteAtIndex(int index) {
        if(index < l.size()){
            l.erase(next(l.begin(),index));
        }
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */