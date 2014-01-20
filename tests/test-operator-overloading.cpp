class OpTest
{
public:
	int j;
	OpTest(int i) : j(i) { }

	// Binary method
 	OpTest operator -(const OpTest& b) const
	{
		return OpTest(j - b.j);
	}

	// Unary method
	OpTest operator -()
	{
		return OpTest(-j);
	}

	// Function call method
	void operator ()()
	{
		j++;
	}

	int operator ()(int kk, int ll)
	{
		kk++;
		ll++;
	}

	// Prefix increment
	int operator++()
	{
		j++;
	}
	
	// Postfix increment (with dummy int to mark it as postfix)
	int operator++(int)
	{
		j++;
	}
};

// Binary function
OpTest operator +(const OpTest& a, const OpTest& b)
{
	return OpTest(a.j + b.j);
}

// Binary function (with built-in type on left)
OpTest operator +(int a, const OpTest& b)
{
	return OpTest(a + b.j);
}

// Unary function
OpTest operator +(const OpTest& a)
{
	return OpTest(-a.j);
}

// Pre decrement
int operator--(OpTest& b)
{
	b.j--;
}

// Post decrement
int operator--(OpTest& b, int)
{
	b.j--;
}


void OpTestTest()
{
	OpTest a(1);
	OpTest b(2);
	OpTest c = a + b;
	OpTest d = b - a;
	OpTest e = +a;
	OpTest f = -a;
	OpTest g = 5 + b;
	++f;
	f++;
	--g;
	g--;
	f();
	f(1, 2);
}

