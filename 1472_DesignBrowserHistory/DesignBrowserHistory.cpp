// struct Node {
//     string val;
//     Node* prev=NULL;
//     Node* next=NULL;
// };
// class BrowserHistory {
// public:
// Node* curr=NULL;
//     BrowserHistory(string homepage) {
//         curr=new Node();
//         curr->val=homepage;
//     }
    
//     void visit(string url) {
//         Node* temp=new Node();
//         temp->val=url;
//         curr->next=temp;
//         temp->prev=curr;
//         curr=temp;
//     }
    
//     string back(int steps) {
//         while(curr->prev && steps>0)
//         {
//             curr=curr->prev;
//             steps--;
//         }
//         return curr->val;
        
//     }
    
//     string forward(int steps) {
//        while(curr->next&& steps>0)
//        {
//            curr=curr->next;
//            steps--;
//        } 
//        return curr->val;
//     }
// };

class BrowserHistory {
public:
    int index = 0 , n = 1;
    string list[101];
    BrowserHistory(string homepage) {
        list[index] = homepage;
    }

    void visit(string url) {
        list[++index] = url;
        n = index + 1;
    }

    string back(int steps) {

        index = index - steps > 0 ? index - steps : 0;

        return list[index];
    }

    string forward(int steps) {

        index = index + steps < n ? index + steps : n - 1;

        return list[index];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */