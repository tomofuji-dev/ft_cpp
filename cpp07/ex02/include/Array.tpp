template <class T>
Array<T>::Array(unsigned int size) : size_(size), content_(new T[size_]()) {}

template <class T>
Array<T>::Array(const Array<T>& src) : size_(src.size_), content_(NULL) {
    *this = src;
}

template <class T>
Array<T>::~Array() {
    delete[] content_;
}

template <class T>
unsigned int Array<T>::size() const {
    return size_;
}

template <class T>
Array<T>& Array<T>::operator=(const Array<T>& rhs) {
    if (this == &rhs) { return *this; }
    
    T* tmp = content_;
    content_ = new T[rhs.size_];
    delete[] tmp;

    size_ = rhs.size_;
    for (unsigned int i = 0; i < rhs.size_; i++) {
        content_[i] = rhs.content_[i];
    }
    return *this;
}

template<typename T>
T& Array<T>::operator[](const std::size_t i) {
    if (static_cast<std::size_t>(size_) <= i) {
        throw std::out_of_range("index out of range");
    }
    return content_[i];
}

template<typename T>
const T& Array<T>::operator[](const std::size_t i) const {
    if (static_cast<std::size_t>(size_) <= i) {
        throw std::out_of_range("index out of range");
    }
    return content_[i];
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, const Array<T>& value) {
    stream << "[";
    for (unsigned int i = 0; i < value.size(); i++) {
        if (i > 0) {
            stream << ", ";
        }
        stream << value[i];
    }
    stream << "]";
    return stream;
}
