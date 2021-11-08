#pragma once

#include <map>
#include <iostream>
#include <cassert>

template<typename T, T DefVal>
class Element {
public:
    static constexpr T _default = DefVal;

    Element() {};
    size_t size() const { return matrix.size();}
    auto& operator[](const std::size_t& pos) {
        pair.second = pos;
        return *this;
    }
    auto& operator = (const T& other) {
        if (other != _default) {
            matrix[pair] = other;
        }
        else {
            auto it = matrix.find(pair);
            if (it != matrix.end())
                matrix.erase(it->first);
        }
        return *this;
    }
    void set(const std::size_t& row) { pair.first = row; }

    auto begin() { return matrix.begin(); };
    
    auto end() { return matrix.end(); }

    operator auto() { return get(); }
private:
    std::map<std::pair<std::size_t, std::size_t>, T> matrix;
    std::pair<std::size_t, std::size_t> pair;

    auto get() const {
        auto it = matrix.find(pair);
        if (it != matrix.end())
            return it->second;
        return DefVal;
    }
};

template <typename T>
class m_iterator {
    using  out_iterator = typename std::map<std::pair<std::size_t, std::size_t>, T>::iterator;
public:
    m_iterator(out_iterator iteratr);
    ~m_iterator();
    bool operator!=(m_iterator<T> const& other) const;
    bool operator==(m_iterator<T> const& other) const;
    auto operator*() const;
    auto operator++();
private:
    out_iterator iterator;
};


template<typename T>
m_iterator<T>::m_iterator(out_iterator iteratr) : iterator(iteratr) {}

template<typename T>
m_iterator<T>::~m_iterator() {}

template<typename T>
bool m_iterator<T>::operator != (m_iterator<T> const& other) const {
    return iterator != other.iterator;
}

template<typename T>
bool m_iterator<T>::operator==(m_iterator<T> const& other) const {
    return iterator == other.iterator;
}

template<typename T>
auto m_iterator<T>::operator*() const {
    return std::make_tuple(iterator->first.first,
        iterator->first.second,
        iterator->second
    );
}

template<typename T>
auto m_iterator<T>::operator++()
{
    iterator++;
    return *this;
}

template<typename T, int DefValue>
class SparceMatrix {
public:
    SparceMatrix() = default;
    SparceMatrix(const SparceMatrix& other) = delete;

    SparceMatrix& operator=(const T& rMat) {
        if (this == rMat)
            return *this;
        cells = rMat.cells;
        return *this;
    }

    size_t size() const { return cells.size(); }

    T begin() { return m_iterator<T>(cells.begin()); }

    T end() { return m_iterator<T>(cells.end()); }

    auto& operator [] (const std::size_t& row) {
        cells.set(row);
        return cells;
    }
private:
    Element<T, DefValue> cells;
};