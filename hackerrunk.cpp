// topic
//https://www.hackerrank.com/interview/interview-preparation-kit/arrays/challenges

//problem 5
//https://www.hackerrank.com/challenges/crush/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays
long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long long> diff(n + 2, 0);

    for (auto &q : queries) {
        int a = q[0], b = q[1], k = q[2];
        diff[a] += k;
        diff[b + 1] -= k;
    }

    long long cur = 0, mx = 0;
    for (int i = 1; i <= n; i++) {
        cur += diff[i];
        mx = max(mx, cur);
    }
    return mx;
}

//problem 4
//https://www.hackerrank.com/challenges/minimum-swaps-2/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays

int minimumSwaps(vector<int> arr) {
    int swaps = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        while (arr[i] != i + 1) {
            swap(arr[i], arr[arr[i] - 1]);
            swaps++;
        }
    }

    return swaps;
}

//problem 3
//https://www.hackerrank.com/challenges/new-year-chaos/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays

void minimumBribes(vector<int> q) {
    int n = q.size();
    long long bribes = 0;

    for (int i = 0; i < n; i++) {
        if (q[i] - (i + 1) > 2) {
            cout << "Too chaotic" << endl;
            return;
        }
        for (int j = max(0, q[i] - 2); j < i; j++) {
            if (q[j] > q[i]) bribes++;
        }
    }

    cout << bribes << endl;
}

//problem 2
//https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays

vector<int> rotLeft(vector<int> a, int d) {
    int n = a.size();
    vector<int> res(n);

    for (int i = 0; i < n; i++) {
        res[i] = a[(i + d) % n];
    }

    return res;
}

//problem 1
//https://www.hackerrank.com/challenges/2d-array/copy-from/484798060?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays

int hourglassSum(vector<vector<int>> arr) {
    int current = INT_MIN;
    for(int i = 0; i < arr.size()/2 + 1; i++) {
        for(int j = 0; j < arr[i].size()/2 + 1; j++) {
            int upper_val = arr[i][j] + arr[i][j+1] + arr[i][j + 2];
            int mid_val = arr[i + 1][j + 1];
            int lower_val = arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j + 2];
            int temp = lower_val + mid_val + upper_val;
            if (temp > current) current = temp;
        }
    }

    return current;
}



//  topic 2
//https://www.hackerrank.com/interview/interview-preparation-kit/warmup/challenges

//problem 1
//https://www.hackerrank.com/challenges/sock-merchant/copy-from/486041017?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup
int sockMerchant(int n, vector<int> ar) {
    unordered_map<int, int> count;
    int pairs = 0;

    for (int i = 0; i < n; i++) {
        count[ar[i]]++;

        if (count[ar[i]] % 2 == 0) {
            pairs++;
        }
    }

    return pairs;
}

//problem 2
//https://www.hackerrank.com/challenges/counting-valleys/copy-from/485021572?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup

int countingValleys(int steps, string path) {
    int level = 0;
    int valley = 0;
    for(auto& a : path){
        if(a == 'D') {
            if(level == 0) {
                valley++;
            }
            level--;
        }
        if(a == 'U') {
            level++;
        }
    }

    return valley;
}

//problem 3
//https://www.hackerrank.com/challenges/jumping-on-the-clouds/copy-from/485029816?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup

int jumpingOnClouds(vector<int> c) {
    int jumps = 0;
    int i = 0;
    int n = c.size();

    while (i < n - 1) {
        if (i + 2 < n && c[i + 2] == 0) {
            i += 2;
        } else {
            i++;
        }
        jumps++;
    }

    return jumps;
}

//problem 4
//https://www.hackerrank.com/challenges/repeated-string/copy-from/485036621?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=warmup

long repeatedString(string s, long n) {
    long count = 0;

    for (char c : s) {
        if (c == 'a') count++;
    }

    long full = n / s.length();
    long remainder = n % s.length();

    count *= full;

    for (int i = 0; i < remainder; i++) {
        if (s[i] == 'a') count++;
    }

    return count;
}

//  topic 3
//https://www.hackerrank.com/interview/interview-preparation-kit/linked-lists/challenges

//problem 1
//https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=linked-lists

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* temp = llist;
    SinglyLinkedListNode* added = new SinglyLinkedListNode(data);
    for(int i = 1; i < position;i++){
        temp = temp->next;
    }
    if(temp->next == NULL) {
        temp->next = added;
    }else{
        added->next = temp->next;
        temp->next = added;
    }
    return llist;
}

//problem 2
//https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=linked-lists

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode* head = llist;
    DoublyLinkedListNode* current = new DoublyLinkedListNode(data);
    if(llist == NULL) {
        return current;
    }
    if(data < llist->data) {
        current -> next = llist;
        llist->prev = current;
        return current;
    }
    while(llist->next != NULL) {
        if(llist->data <= data && llist->next->data >= data) {
            current->next = llist->next;
            llist->next = current;
            current->prev = llist;
            llist->next->prev = current;
            break;
        }

        llist = llist->next;
    }

    if(llist->data < data){
        current->prev = llist;
        llist->next = current;
    }

    return head;
}

//problem 3
//https://www.hackerrank.com/challenges/reverse-a-doubly-linked-list/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=linked-lists

DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    DoublyLinkedListNode* current = llist;
    DoublyLinkedListNode* temp = nullptr;

    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    if (temp != nullptr) {
        llist = temp->prev;
    }

    return llist;
}

//problem 4
//https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=linked-lists

int findMergeNode(SinglyLinkedListNode* head1,
                  SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* p1 = head1;
    SinglyLinkedListNode* p2 = head2;

    while (p1 != p2) {
        p1 = (p1 == NULL) ? head2 : p1->next;
        p2 = (p2 == NULL) ? head1 : p2->next;
    }

    return p1->data;
}

//problem 5
//https://www.hackerrank.com/challenges/ctci-linked-list-cycle/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=linked-lists

bool has_cycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}