template <typename T>
T Add(T n1, T n2)
{
	return n1+n2;
}

template<typename T>
class maths
{
public:
	maths(T n1, T n2);
	T add(){return n1+n2;}
	T sub(){return n1>=n2?n1-n2:n2-n1;}
	T mul(){return n1*n2;}
	T dev(){return n2 > 0?n1/n2: 0;}

private:
	T n1;
	T n2;
};