#pragma once

//template<typename I> requires std::integral<I>
/*I gcd(I a, I b) {
    if (b == 0)
       return a;

    return gcd(b, a%b);
}

/* A class modeling a rational number. Remember that a class is the same of
 * a struct but all of its members are private by default. */
template<typename I> requires std::is_floating_point<I>;
class Irrational
{
    /* Private members */
    I m_reale;
	I m_imm;
    
    /* Private method */
    void adjust_signs(void) {
        if (m_imm >= 0)
            return;

        m_imm = -m_imm;
	}

public:
    /* Default constructor */
    Irrational()
        : m_reale(0), m_imm(0)
    {}
    
    /* User-defined constructor. This is marked `explicit` to avoid
     * making a "converting constructor". Without `explicit`, if we
     * assign an object of type I (which is `int` in our case) to a
     * rational, the "converting constructor" gets called. Take a
     * look to the point (3) in rational.cpp.
     */
    /*explicit Irrational(I n)
        : m_num(n), m_den(1)
    {
        std::cout << "converting constructor called" << std::endl;
    }
	
    //
    /* User-defined constructor. Takes two parameters, numerator and
     * denominator */
    Irrational(I reale, I imm)
        : m_reale(reale), m_imm(imm)
    {}
    
    /* Return the numerator. The `const` means that this function does
     * not modify the instance on which it is called.
     */
	I reale(void) const {
        return m_reale;
    }
    
    /* Return the denominator. The `const` means that this function does
     * not modify the instance on which it is called.
     */
    I imm(void) const {
        return m_imm;
    }
    
    /* Simplify, i.e. 3/6 -> 1/2 */
    /*void simplify(void) {
        I g = gcd(m_num, m_den);
        m_num /= g;
        m_den /= g;
        adjust_signs();
    }
    
    /* Define the += operator between rationals. When you do
     * 
     *  r1 += r2
     *
     * this function gets called. Notice that this function
     * takes only one parameter: we take the instance `other`
     * and we add it to the instance on which += is called.
     */
	 Irrational coniugato()const{
		 return Irrazional(m_reale,-m_imm);
	 }
    /*rational& operator+=(const rational& other) {
        I a = m_num;
        I b = m_den;
        I c = other.m_num;
        I d = other.m_den;
        m_num = a*d + b*c;
        m_den = b*d;
        simplify();
        return *this;
	}
	*/
	Irrational& operator+=(const Irrational& other) {
        m_reale += other.m_reale;
        m_imm += other.m_imm;
        return *this;
    }

	/* Define operator+ in terms of operator +=. Notice that + does
	 * not modify the instance on which is called, therefore is marked
	 * const (the second const). */
	 Irrational operator+(const Irrational& other) const {
        Irrational ret = *this;
        ret += other;
        return ret;
    }
	 
	/*rational operator+(const rational& other) const {
        rational ret = *this;
        ret += other;
        return ret;
    }

    /* Define the += operator between a rational on the left
     * and an I on the right. When you do
     * 
     *  r1 += i
     *
     * this function gets called. Notice that this function
     * takes only one parameter: we take the instance `other`
     * and we add it to the instance on which += is called.
     */
     /*rational& operator+=(const I& other) {
        m_num += other*m_den;
        simplify();
        return *this;
	}
	*/
	Irrational& operator*=(const Irrational& other) {
        I Reale = m_real * other.m_reale - m_imm * other.m_imm;
        I Immaginaria = m_reale * other.m_imm + m_imm * other.m_reale;
        m_reale = Reale;
        m_imm = Immaginaria;
        return *this;
    }
	/* Define operator+ in terms of operator +=. Notice that + does
	 * not modify the instance on which is called, therefore is marked
	 * const (the second const). */
	/*rational operator+(const I& other) const {
        rational ret = *this;
        ret += other;
        return ret;
    }
    */
	Irrational operator*(const Irrational& other) const {
        Irrational ret = *this;
        ret *= other;
        return ret;
    }
    /* This is the UNARY minus. It computes the opposite: r2 = -r1; Notice
     * that the UNARY minus does not modify the instance on which is called,
     * therefore it is marked const.
     */
    /*rational operator-() const {
        return rational(-m_num, m_den);
    }
    
    /* Exercise: implement the BINARY minus */
    
    /* Comparison operator between rationals */
    /*bool operator<(const rational& other) const {
        I a = m_num;
		I b = m_den;
        I c = other.m_num;
        I d = other.m_den;

        return a*d < b*c;
	}
*/
}
template <typename I> requires std::is_floating_point<I>
std::ostream& operator<<(std::ostream& os, const Irrational<I>& c) {
    os << c.reale();  
    if (c.imm() >= 0)
        os << "+" << c.imm() << "i";
    else
        os << c.imm() << "i";
    return os;
}
/* This operator is defined outside the rational class and is needed
 * to compute the sum of an I on the left and a rational<I> on the
 * right. */
/*template<typename I>
Irrational<I>
operator+(const I& i, const rational<I>& r)
{
    return r + i;
}

/* Free function (not member of rational) computing the absolute value
 * of a rational. Note how it uses the UNARY minus we implemented before
 */
/*template<typename I>
rational<I>
abs(const rational<I>& r) {
    if (r < rational<I>(0))
        return -r;

    return r;
}

/* Free function to compute the inverse of a rational */
/*template<typename I>
rational<I> inv(const rational<I>& r) {
    return rational<I>(r.den(), r.num());
}

/* Overload of <<, to make the rationals printable. */
/*template<typename I>
std::ostream&
operator<<(std::ostream& os, const rational<I>& r) {
    if (r.den() != 1)
        os << r.num() << "/" << r.den();
    else
        os << r.num();

    return os;
}

