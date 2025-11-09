#include <iostream>
using namespace std;

struct MaxPQ {
    int *a;
    int cap;
    int n;

    MaxPQ(int capacity) {
        cap = capacity;
        a = new int[cap];
        n = 0;
    }

    ~MaxPQ() {
        delete[] a;
    }

    bool empty() const { return n == 0; }
    int size() const { return n; }

    void swapInt(int &x, int &y) {
        int t = x; x = y; y = t;
    }

    void swim(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (a[p] < a[i]) {
                swapInt(a[p], a[i]);
                i = p;
            } else break;
        }
    }

    void sink(int i) {
        while (true) {
            int l = 2*i + 1, r = 2*i + 2, m = i;
            if (l < n && a[l] > a[m]) m = l;
            if (r < n && a[r] > a[m]) m = r;
            if (m == i) break;
            swapInt(a[i], a[m]);
            i = m;
        }
    }

    bool push(int x) {
        if (n == cap) return false;
        a[n] = x;
        swim(n);
        n++;
        return true;
    }

    int top() const {
        return a[0];
    }

    void pop() {
        if (n == 0) return;
        swapInt(a[0], a[n-1]);
        n--;
        if (n > 0) sink(0);
    }
};

int main() {
    MaxPQ pq(100);
    pq.push(5);
    pq.push(1);
    pq.push(3);
    pq.push(10);
    pq.push(7);
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";
    return 0;
}
