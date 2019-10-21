class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        head = NULL;
        tail = NULL;
        stored = 0;
    }
    
    int get(int key) {
        map<int, Node*>::iterator itr;
        if(hashmap.count(key) == 0)
        {
            return -1;
        }
        itr = hashmap.find(key);
        Node * temp = (itr->second);
        if(tail == temp)
        {
            return temp->val;
        }
        if(head == temp)
        {
            head = temp->next;
        }
        else
        {
            temp->prev->next = temp->next;
        }
        temp->next->prev = temp->prev;
        tail->next = temp;
        temp->prev = tail;
        temp->next = NULL;
        tail = temp;
        return temp->val;
    }
    
    void put(int key, int value) {
        map<int, Node*>::iterator itr;
        Node * temp;
        if(hashmap.count(key) > 0)
        {
            itr = hashmap.find(key);
            itr->second->val = value;
            temp = itr->second;
            if(temp == tail)
            {
                return ;
            }
            if(head == temp)
            {
                head = temp->next;
            }
            else
            {
                temp->prev->next = temp->next;
            }
            temp->next->prev = temp->prev;
            tail->next = temp;
            temp->prev = tail;
            temp->next = NULL;
            tail = temp;
            return;
        }
        if(stored == cap)
        {
            temp = head;
            head = head->next;
            if(head)
            {
                head->prev = NULL;
                temp->next = NULL;
            }
            hashmap.erase(temp->key);
			delete temp;
        }
        else
        {
            stored++;
        }
        temp = new Node(key, value);
        if(head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        hashmap.insert(make_pair(key, temp));
    }
    
private:
    int cap, stored;
    struct Node {
        int key, val;
        struct Node *prev, *next;
        Node(int k, int v) : key(k), val(v), prev(NULL), next(NULL){}
    };
    map<int, Node *> hashmap;
    Node *head, *tail;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */