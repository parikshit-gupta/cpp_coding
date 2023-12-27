#include <vector>
using namespace std;

class min_heap
{
public:
    vector<int> v;
    int size;

    min_heap()
    {
        size = 0;
    }

    min_heap(min_heap const &h)
    {
        for (int i = 0; i < h.size; i++)
        {
            this->v[i] = h.v[i];
        }
        this->size = h.size;
    }

    int get_size()
    {
        return size;
    }

    void insert(int i)
    {
        v.push_back(i);
        size++;
        int CI = size - 1; // current index
        if (CI == 0)
        {
            return;
        }
        if (CI > 0)
        {
            int PI = (CI - 1) / 2; // parent index of current index
            // up-heapification
            while (v[CI] < v[PI])
            {
                // swapping the elements
                int temp = v[PI];
                v[PI] = v[CI];
                v[CI] = temp;
                CI = PI;
                PI = (CI - 1) / 2;
            }
        }
        return;
    }

    int get_min()
    {
        if (size==0)
        {
            cout<<"heap empty"<<endl;
            return -1;
        }
        return v[0];
    }

    int delete_min()
    {
        if (size==0)
        {
            cout<<"heap empty"<<endl;
            return -1;
        }
        int temp = v[0];
        v[0] = v[size - 1];
        v[size - 1] = temp;
        v.pop_back();
        size--;

        int pi = 0;
        int ci = 0;

        // down-heapification
        while (true)
        {
            int ci1 = (2 * pi + 1);//child index 1
            int ci2 = (2 * pi + 2);//child index 2
            if (ci1 < size && ci2 >= size)
            {
                ci = ci1;
            }
            if (ci2 < size && ci1 >= size)
            {
                ci = ci2;
            }
            if (ci1 < size && ci2 < size)
            {
                if (v[ci1] > v[ci2])
                {
                    ci = ci2;
                }
                else
                {
                    ci = ci1;
                }
            }
            if (ci1 >= size && ci2 >= size)
            {
                return temp;
            }
            if (v[pi] >= v[ci])
            {
                int temp1 = v[ci];
                v[ci] = v[pi];
                v[pi] = temp1;
                pi = ci;
            }
            else
            {
                return temp;
            }
        }
    }
};