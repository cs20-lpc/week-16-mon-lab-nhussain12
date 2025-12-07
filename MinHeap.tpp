template <typename T>
void MinHeap<T>::siftUp(int i) {
    // TODO: Move element at index i upward until heap property restored
    while (i > 0) {
        int p = parent(i);

        if (data[i] >= data[p]) {
            break;
        }

        swap(data[i], data[p]);

        i = p;
    }
}

template <typename T>
void MinHeap<T>::siftDown(int i) {
    // TODO: Move element at index i downward until heap property restored
    while (true) {
        int smallest = i;
        int l = left(i);
        int r = right(i);

        if (l < data.size() && data[l] < data[smallest]) {
            smallest = l;
        }

        if (r < data.size() && data[r] < data[smallest]) {
            smallest = r;
        }

        if (smallest == i) {
            break;
        }

        swap(data[i], data[smallest]);
        i = smallest;
    }
}

template <typename T>
void MinHeap<T>::insert(const T& value) {
    // TO DO: insert a value into the heap
    data.push_back(value);

    siftUp(size() - 1);
}

template <typename T>
T MinHeap<T>::removeRoot() {
    T rootValue;
    // TODO: Implement removing the root element.
    // Case Handling
    if (data.empty()) {
        throw string("removeRoot: error, empty tree");
    }

    rootValue = data[0];
    swap(data[0], data[size()-1]);
    data.pop_back();
    
    if (!empty()) {
        siftDown(0);
    }
    
    return rootValue;
}

template <typename T>
void MinHeap<T>::removeAt(int index) {
    if (index < 0 || index >= size())
        throw runtime_error("Invalid index");

    swap(data[index], data.back());
    data.pop_back();

    // Return if index WAS the last value in the array
    if (index > size()) {
        return;
    }

    // TODO: Attempt sift-up then 
    siftUp(index);

    // sift-down to restore heap property
    siftDown(index);
}
