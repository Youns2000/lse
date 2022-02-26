namespace gad
{
    template <typename T>
    class Edge
    {
    public:
        Edge(T* data);
        bool is_oriented();
        
    private:
        long id_;
        T* data;
        bool oriented;
    };
}