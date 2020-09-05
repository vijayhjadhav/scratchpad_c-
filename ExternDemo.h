//extern template class maths<int
template <typename T>
T Add(T n1, T n2)
{
	maths<T> temp(n1, n2);
	return temp.add();
}