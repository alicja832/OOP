#pragma once
#include <vector>
#include <ostream>
template<typename T,int n,int m>class Matrix
{
    public:
    /**
     * @brief Construct a new Matrix object
     * 
     */
    Matrix()
    {
        for(int i=0;i<n;i++)
        {
            v.push_back(new T[m]);
        }
    }
    Matrix(T a):Matrix()
    {
        reset(a);
    }
    /**
     * @brief 
     * add two Matrixes if there the same size
     * @tparam Type 
     * @tparam i 
     * @tparam j 
     * @param a 
     */
    template<typename Type>void add(Matrix<Type,n,m>& a);
    //everything is equal to value
    void reset(T value);
    //acces to values
    T& at(int i,int j);
    //template function 
    template<int i,int j>T& at();
    //ostrem operator
    private:
    std::vector<T*> v;

};
template<typename T,int n,int m>void Matrix<T,n,m>::reset(T value)
{

        for(auto i:v)
        {
            for(int j=0;j<m;j++)
                i[j]=value;
        }
    
}
template<typename T,int n,int m>T& Matrix<T,n,m>::at(int i,int j)
{
    return v[i][j];
}
template<typename T,int n,int m>
template<int i,int j> 
T& Matrix<T,n,m>::at()
{
    return v[i][j];
}
template<typename T,int n,int m>
template<typename Type>
void Matrix<T,n,m>::add(Matrix<Type,n,m>& a)
{
   
    for(int k=0;k<n;k++)
    {
        for(int l=0;l<m;l++)
            v[k][l]+=static_cast<T>(a.at(k,l));
    }

}
template<typename T,int n,int m>std::ostream& operator<<(std::ostream& o, Matrix<T,n,m> a)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            o<<a.at(j,i)<<" ";
        }
        o<<std::endl;
    }
    return o;
}