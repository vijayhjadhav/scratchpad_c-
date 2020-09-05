template<class T>
class maths
{
public:
	//maths():n1(n1), n2(n2){};
	maths(T n1, T n2):n1(n1), n2(n2){};
	T add(){return n1+n2;}
	T sub(){return n1>=n2?n1-n2:n2-n1;}
	T mul(){return n1*n2;}
	T dev(){return n2 > 0?n1/n2: 0;}

private:
	T n1;
	T n2;
};

