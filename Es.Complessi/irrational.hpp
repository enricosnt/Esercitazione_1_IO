#pragma once
template<typename I> requires std::is_floating_point<I>;
class Irrational
{
    /* Private members */
    I m_reale;
	I m_imm;
    

public:
    /* Default constructor */
    Irrational()
        : m_reale(0), m_imm(0) {}
    Irrational(I reale, I imm): m_reale(reale), m_imm(imm) {}
    
	I reale() const {
        return m_reale;
    }
  
    I imm() const {
        return m_imm;
    }
    
    
	Irrational<I> coniugato()const{
		 return Irrational<I>(m_reale,-m_imm);
	 }
    
	Irrational<I>& operator+=(const Irrational<I>& other) {
        m_reale += other.m_reale;
        m_imm += other.m_imm;
        return *this;
    }

	Irrational<I> operator+(const Irrational<I>& other) const {
        Irrational<I> ret = *this;
        ret += other;
        return ret;
    }
	 
	Irrational<I>& operator*=(const Irrational<I>& other) {
        I Reale = m_reale * other.m_reale - m_imm * other.m_imm;
        I Immaginaria = m_reale * other.m_imm + m_imm * other.m_reale;
        m_reale = Reale;
        m_imm = Immaginaria;
        return *this;
    }
	
	Irrational<I> operator*(const Irrational<I>& other) const {
        Irrational<I> ret = *this;
        ret *= other;
        return ret;
    }
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


