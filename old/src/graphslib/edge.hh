#pragma once

template <typename T>
class Edge
{
public:
    Edge<T>(T src, T data, T dest) : src_(src), dest_(dest), data_(data){}

    friend std::ostream& operator<<(std::ostream& os, const Edge<T>& e)
    {
        os << "(" << e.src_ << ", " << e.data_ << ", " << e.dest_ << ")";
        return os;
    }

    T src_;
    T dest_;
    T data_;
};