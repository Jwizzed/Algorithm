//
// Created by Krittin Setdhavanich on 20/4/2023 AD.
//
//
//
//#include <iostream>
//
//using namespace std;
//
//class PriorityQueue
//{
//public:
//    virtual void insert(int val) = 0;
//    virtual int extract_min() = 0;
//};
//
//class Heap : public PriorityQueue
//{
//private:
//    int h[1000];
//    int h_size;
//
//    void heap_swap(int pos_a, int pos_b) {
//        int temp = h[pos_a];
//        h[pos_a] = h[pos_b];
//        h[pos_b] = temp;
//    }
//
//    // heapify up starting from index pos
//    void heapify_up(int pos)
//    {
//        int parent = (pos - 1) / 2;
//        while (h[pos] < h[parent]) {
//            heap_swap(pos, parent);
//            pos = parent;
//            parent = (pos - 1) / 2;
//        }
//    }
//
//
//// heapify down starting from index pos
//    void heapify_down(int pos)
//    {
//        int left_pos = 2 * pos + 1;
//        int right_pos = 2 * pos + 2;
//        while (left_pos < h_size){
//            if (right_pos < h_size){
//                if (h[pos] < h[left_pos] && h[pos] < h[right_pos]) {
//                    break;
//                }
//                else if (h[left_pos] < h[right_pos]) {
//                    heap_swap(pos, left_pos);
//                    pos = left_pos;
//                }
//                else {
//                    heap_swap(pos, right_pos);
//                    pos = right_pos;
//                }
//            }
//            else {
//                if (h[pos] < h[left_pos]) {
//                    break;
//                }
//                else {
//                    heap_swap(pos, left_pos);
//                    pos = left_pos;
//                }
//            }
//            left_pos = 2 * pos + 1;
//            right_pos = 2 * pos + 2;
//        }
//    }
//
//public:
//    Heap()
//    {
//        h_size = 0;
//    }
//    void insert(int val)
//    {
//        h[h_size] = val;
//        h_size++;
//        heapify_up(h_size-1);
//    }
//    int extract_min()
//    {
//        int s = h[0];
//        h[0] = h[h_size-1];
//        h_size--;
//        heapify_down(0);
//        return s;
//    }
//};
//
//int main()
//{
//    Heap h;
//    int n;
//    string operation;
//    cin >> n;
//    for (int i = 0; i < n; i++)
//    {
//        cin >> operation;
//        if (operation == "insert") {
//            int val;
//            cin >> val;
//            h.insert(val);
//        } else if (operation == "extract-min") {
//            cout << h.extract_min() << endl;
//        }
//    }
//    return 0;
//}
