#ifndef _MYTERM_H_
#define _MYTERM_H_
#ifndef _MYPOLYNOMIAL_H_
#define _MYPOLYNOMIAL_H_
#include <list>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class myPolynomial;
class myTerm {
public:
    myTerm(int c = 0, unsigned e = 0);
    myTerm(const myTerm &term);
    bool operator == (const myTerm& term) const;
    bool operator != (const myTerm& term) const;
    bool operator < (const myTerm& term) const;
    myTerm operator - () const;
    int getCoeff() const { return coeff; }
    unsigned getExp() const { return exp; }
    void setCoeff(int c) { coeff = c; }
    void setExp(unsigned e) { exp = e; }
    myTerm ddx() const;
    friend ostream& operator <<(ostream &outStream, const myTerm& term);
    friend myPolynomial;
private:
    int coeff;
    unsigned exp; 
};
#endif _MYTERM_H_

class myPolynomial {
public:
    myPolynomial(int c = 0, unsigned e = 0);
    myPolynomial(int nTerms, int mono[]);
    myPolynomial(const myPolynomial &poly);
    bool operator == (const myPolynomial &poly) const;
    bool operator != (const myPolynomial &poly) const;
    myPolynomial& operator += (const myPolynomial &poly);
    myPolynomial& operator -= (const myPolynomial &poly);
    myPolynomial& operator *= (const myPolynomial &poly);
    myPolynomial& operator *= (int k);
    myPolynomial operator -() const;
    myPolynomial operator *(int k) const;
    myPolynomial operator +(const myPolynomial &poly) const;
    myPolynomial operator -(const myPolynomial &poly) const;
    myPolynomial operator *(const myPolynomial &poly) const;
    long operator() (int x) const; 
    int getDegree() const;
    unsigned getNumTerms() const; 
    myPolynomial ddx() const;
    friend myPolynomial operator *(int k, const myPolynomial &poly);
    friend ostream& operator <<(ostream &outStream, const myPolynomial &poly);
    friend int compare(myTerm &a, myTerm &b);
    static const myPolynomial ZERO;
    static const myPolynomial ONE;
    static const myPolynomial X;
private:
    int degree;
    int nterm;
    myTerm polynomial[51];
};
#endif

myTerm::myTerm(int c, unsigned e) : coeff(c), exp(e) {}
myTerm::myTerm(const myTerm &term) : coeff(term.coeff), exp(term.exp) {}
bool myTerm::operator == (const myTerm& term) const {
    return (coeff == term.coeff && exp == term.exp);
}
bool myTerm::operator != (const myTerm& term) const {
    return !(*this==term);
}
bool myTerm::operator < (const myTerm& term) const {
    return exp > term.exp;
}
myTerm myTerm::operator - () const {
    return myTerm(-coeff, exp);
}
myTerm myTerm::ddx() const {
    if (exp == 0) {
        return myTerm(0, 0);
    }
    return myTerm(exp*coeff, exp-1);
}
ostream& operator <<(ostream &outStream, const myTerm& term) {
    if (term.exp == 0) {
        if (term.coeff == 0) {
            return outStream;
        }
        else {
            return outStream << term.coeff;
        }
    }
    if (term.coeff == 0) {
        return outStream;
    } 
    if (term.coeff == 1) {
        outStream << "x";
    }
    else if (term.coeff == -1) {
        outStream << "-x";
    }
    else {
        outStream << term.coeff << "x";
    }
    if (term.exp == 1) {
        return outStream;
    }
    else {
        return outStream << "^" << term.exp;
    }
}

const myPolynomial myPolynomial::ZERO(0);
const myPolynomial myPolynomial::ONE(1, (unsigned)0);
const myPolynomial myPolynomial::X(1, 1);

ostream& operator <<(ostream &outStream, const myPolynomial& poly) {
    bool compare = false;
    if (poly == myPolynomial::ZERO) {
        return outStream << 0;
    }
    outStream<< poly.polynomial[0];

    if (poly.polynomial[0].getCoeff() != 0) {
        compare = true;
    }

    for(int i = 1; i < poly.nterm; i++) {
        if (poly.polynomial[i].getCoeff() != 0) {
            compare = true;
        }
        if (poly.polynomial[i].getCoeff() > 0) {
            outStream<<'+';
        }
        outStream << poly.polynomial[i];
    }
    if (compare == false) {
        return outStream << '0';
    }
    return outStream;
}
myPolynomial::myPolynomial(int c, unsigned e):nterm(1) {
    polynomial[0].coeff = c, polynomial[0].exp = e;
}
myPolynomial::myPolynomial(int nTerms, int mono[]) : nterm(nTerms) {
    for (int i = 0; i < nterm; i++) {
        polynomial[i].coeff=mono[2 * i], polynomial[i].exp=mono[2 * i + 1];
    }
    sort(polynomial, polynomial + nterm);
    if (nTerms == 1 && polynomial[0].coeff == 0 && polynomial[0].exp == 0) {
        degree = 0;
    }
    else {
        degree = polynomial[0].exp;
    }
}
myPolynomial::myPolynomial(const myPolynomial &poly):nterm(poly.nterm), degree(poly.degree) {
    for (int i = 0; i < nterm; i++) {
        polynomial[i].coeff = poly.polynomial[i].coeff, polynomial[i].exp = poly.polynomial[i].exp;
    }
}
bool myPolynomial::operator == (const myPolynomial &poly) const {
    if (nterm != poly.nterm) {
        return false;
    }
    for (int i = 0; i < nterm; i++) {
        if (polynomial[i].coeff != poly.polynomial[i].coeff || polynomial[i].exp != poly.polynomial[i].exp) {
            return false;
        }
    }
    return true;
}
bool myPolynomial::operator != (const myPolynomial &poly) const {
    return !(*this == poly);
}
myPolynomial& myPolynomial::operator += (const myPolynomial &poly) {
    return *this = *this + poly;
}
myPolynomial& myPolynomial::operator -= (const myPolynomial &poly) {
    return *this = *this - poly;
}
myPolynomial& myPolynomial::operator *= (const myPolynomial &poly) {
    return *this = *this * poly;
}   
myPolynomial& myPolynomial::operator *= (int k) {
    return *this = *this * myPolynomial(k, (unsigned) 0);
}
myPolynomial myPolynomial::operator -() const {
    myPolynomial answer(*this);
    for(int i=0; i<nterm; i++)
        answer.polynomial[i].coeff*=-1;
    return answer;
}
myPolynomial myPolynomial::operator *(int k) const {
    return *this * myPolynomial(k, (unsigned) 0);
}
myPolynomial myPolynomial::operator +(const myPolynomial &poly) const {
    int arr[102]={ 0 };
    int a = 0, b = 0, size = 0;
    for(size; a != nterm && b != poly.nterm; size++) {
        if (polynomial[a].exp > poly.polynomial[b].exp) {
            arr[2 * size] = polynomial[a].coeff, arr[2 * size + 1] = polynomial[a].exp, a++;
        }
        else if (polynomial[a].exp < poly.polynomial[b].exp) {
            arr[2 * size] = poly.polynomial[b].coeff, arr[2 * size + 1] = poly.polynomial[b].exp, b++;
        }
        else {
            arr[2 * size] = polynomial[a].coeff + poly.polynomial[b].coeff, arr[2 * size + 1] = polynomial[a].exp, a++, b++;
        }    
    }
    while(a != nterm) {
        arr[2 * size] = polynomial[a].coeff, arr[2 * size + 1] = polynomial[a].exp, a++, size++;
    }
    while(b != poly.nterm) {
        arr[2 * size] = poly.polynomial[b].coeff, arr[2 * size + 1] = poly.polynomial[b].exp, b++, size++;
    }
    return myPolynomial(size, arr);
}
myPolynomial myPolynomial::operator -(const myPolynomial &poly) const {
    return *this + (-poly);
}
myPolynomial myPolynomial::operator *(const myPolynomial &poly) const {
    myPolynomial answer(0, (unsigned) 0);
    for(int i = 0; i < nterm; i++) {
        myPolynomial temp(poly);
        for(int j = 0; j < poly.nterm; j++) {
            temp.polynomial[j].coeff *= polynomial[i].coeff;
            temp.polynomial[j].exp += polynomial[i].exp;
        }
        answer += temp;
    }
    return answer;
}
long myPolynomial::operator() (int x) const {
    long answer=0;
    for (int i = 0; i < nterm; i++) {
        answer += polynomial[i].coeff * (long)pow(x, polynomial[i].exp);
    }
    return answer;
}
int myPolynomial::getDegree() const {
    return degree;
}
unsigned myPolynomial::getNumTerms() const {
    return nterm;
}
myPolynomial myPolynomial::ddx() const {
    myPolynomial answer(*this);
    for (int i = 0; i < nterm; i++) {
        answer.polynomial[i] = polynomial[i].ddx();
    }
    return answer;
} 
myPolynomial operator *(int k, const myPolynomial &poly) {
    return myPolynomial(k, (unsigned) 0) * poly;
}


void testSimpleCase();
void testDataFromFile();
int main(void) {
    testSimpleCase();
    testDataFromFile();
    return 0;
}
void testSimpleCase() {
    cout << myPolynomial::ZERO << endl;
    cout << myPolynomial::ONE << endl;
    cout << myPolynomial::X << endl;
    myPolynomial p0, p1(1), p2(1, 1), p3(3, 5);
    int testData4[10] = {1, 0, 1, 1, 1, 2, 1, 3, 1, 4};
    int testData5[10] = {-1, 0, -1, 1, -1, 2, -1, 3, -1, 4};
    int testData6[10] = {1, 0, -1, 1, 1, 2, -1, 3, 1, 4};
    int testData7[10] = {2, 2, 5, 5, 4, 4, 1, 1, 3, 3};
    int testData8[12] = {1, 1000000000, 1, 100000000, 1, 1000000, 1, 10000, 1, 100, 1, 0};
    myPolynomial p4(5, testData4);
    myPolynomial p5(5, testData5);
    myPolynomial p6(5, testData6);
    myPolynomial p7(5, testData7);
    myPolynomial p8(6, testData8);
    myPolynomial p9(p7);
    cout << p0 << endl << p1 << endl << p2 << endl;
    cout << p4 << endl << p8 << endl;
    cout << p9 << endl;
    cout << p8.getDegree() << " " << p8.getNumTerms() << endl;
    cout << p1(2) << " " << p2(2) << " " << p3(2) << " " << p4(2) << " " << endl;
    cout << p5(3) << " " << p6(3) << " " << p7(3) << " " << p9(3) << " " << endl;
    cout << (p7 == p9) << " " << (p7 != p9) << endl;
    cout << myPolynomial::ZERO.ddx() << endl;
    cout << myPolynomial::ONE.ddx() << endl;
    cout << myPolynomial::X.ddx() << endl;
    cout << p4.ddx() << endl;
    cout << p8.ddx() << endl;
    cout << -myPolynomial::ZERO << endl;
    cout << -p4 << endl;
    cout << 3*myPolynomial::ZERO << endl;
    cout << 3*myPolynomial::ONE << endl;
    cout << myPolynomial::X*3 << endl;
    cout << 3*p4 << " " << p4*3 << endl;
    cout << 0*p5 << " " << p5*5 << endl;
    cout << p4 + p5 << endl;
    cout << p6 - p7 << endl;
    cout << p8 * p9 << endl;
    myPolynomial tmp1(p4), tmp2, tmp3, tmp4;
    tmp4 = tmp3 = tmp2 = tmp1;
    cout << (tmp1 += p5) << endl;
    cout << (tmp2 -= p5) << endl;
    cout << (tmp3 *= p5) << endl;
    cout << (tmp4 *= 3) << endl;
}
void testDataFromFile() {
    ifstream infile("input.txt");
    int numTestCases;
    infile >> numTestCases;
    for (int i = 0; i < numTestCases; i++) {
        int numTerms, terms[100];
        infile >> numTerms;
        for (int j = 0; j < numTerms; j++) {
            infile >> terms[2*j] >> terms[2*j+1];
        }
        myPolynomial p1(numTerms, terms);
        infile >> numTerms;
        for (int j = 0; j < numTerms; j++) {
            infile >> terms[2*j] >> terms[2*j+1];
        }
        myPolynomial p2(numTerms, terms);
        cout << p1 << endl << p2 << endl;
        cout << p1.getDegree() << " " << p2.getNumTerms() << endl;
        cout << p1.ddx() << endl << p2.ddx() << endl;
        cout << (p1 == p2) << " " << (p1 != p2) << endl;
        cout << p1(1) << endl;
        cout << -p1 + p1 * 2 * p2 - p2 * 2 + 3 * p1 << endl;
        myPolynomial p3(myPolynomial::ZERO), p4(myPolynomial::ONE), p5(myPolynomial::X);
        p3 += p1;
        p4 -= p2;
        p5 *= p4;
        p5 *= 2;
        cout << p5 << endl;
    }
}