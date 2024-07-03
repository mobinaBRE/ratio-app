#include <iostream>
using namespace std;
class kasr {
	private:
		int num,den;
	public:
		friend bool operator<(kasr a,kasr b);
		friend bool operator>(kasr a,kasr b);
		friend bool operator>=(kasr a,kasr b);
		friend bool operator<=(kasr a,kasr b);
		friend bool operator!=(kasr a,kasr b);
		friend bool operator==(kasr a,kasr b);
		friend kasr operator+(kasr a,kasr b);
		friend kasr operator-(kasr a,kasr b);
		friend kasr operator/(kasr a,kasr b);
		friend kasr operator*(kasr a,kasr b);
		kasr() {
			num=0;
			den=1;
		}
		void set(int n,int d) {
			if(d==0)
				d=1;
			if(n<0)
				n=-n;
			int bmm;
			if(n>d) {
				for(int i=1; i<=d; i++) {
					if(n%i==0 && d%i==0)
						bmm=i;
				}
			} else if(d>n) {
				for(int i=1; i<=n; i++) {
					if(n%i==0 && d%i==0)
						bmm=i;
				}
			}
			num=n/bmm;
			den=d/bmm;
		}
		void sade() {
			int bmm;
			if(num>den) {
				for(int i=1; i<=den; i++) {
					if(num%i==0 && den%i==0)
						bmm=i;
				}
			} else if(den>num) {
				for(int i=1; i<=num; i++) {
					if(num%i==0 && den%i==0)
						bmm=i;
				}
			}
			num=num/bmm;
			den=den/bmm;
		}
		kasr operator=(kasr a) {
			num=a.num;
			den=a.den;
			return *this;
		}
		void print() {
			cout<<num<<"/"<<den<<"\n";
		}
};
kasr operator+(kasr a,kasr b) {
	kasr c;
	c.den=a.den*b.den;
	c.num=a.num*b.den+a.den*b.num;
	c.sade();
	return c;
}
kasr operator-(kasr a,kasr b) {
	kasr c;
	c.den=a.den*b.den;
	c.num=a.num*b.den-a.den*b.num;
	c.sade();
	return c;
}
kasr operator*(kasr a,kasr b) {
	kasr c;
	c.den=a.den*b.den;
	c.num=a.num*b.num;
	c.sade();
	return c;
}
kasr operator/(kasr a,kasr b) {
	kasr c;
	c.den=a.den*b.num;
	c.num=a.num*b.den;
	c.sade();
	return c;
}
bool operator>(kasr a,kasr b) {
	if(a.num*b.den>a.den*b.num)
		return true;
	else if(a.num*b.den<a.den*b.num)
		return false;
}
bool operator<(kasr a,kasr b) {
	if(a.num*b.den>a.den*b.num)
		return false;
	else if(a.num*b.den<a.den*b.num)
		return true;
}
bool operator<=(kasr a,kasr b) {
	if(a.num*b.den>=a.den*b.num)
		return false;
	else if(a.num*b.den<=a.den*b.num)
		return true;
}
bool operator>=(kasr a,kasr b) {
	if(a.num*b.den>=a.den*b.num)
		return true;
	else if(a.num*b.den<=a.den*b.num)
		return false;
}
bool operator==(kasr a,kasr b) {
	if(a.num*b.den==a.den*b.num)
		return true;
	else
		return false;
}
bool operator!=(kasr a,kasr b) {
	if(a.num*b.den!=a.den*b.num)
		return true;
	else
		return false;
}

int main() {
	kasr a,b,c;
	int n,d,s,x;
	cout<<" a : \n num = ";
	cin>>n;
	cout<<" den = ";
	cin>>d;
	a.set(n,d);
	cout<<" b : \n num = ";
	cin>>n;
	cout<<" den = ";
	cin>>d;
	b.set(n,d);
menu:
	cout<<"which one ? \n1)+  2)-  3)/  4)*";
	cin>>x;
	switch(x) {
		case 1:
			c=a+b;
			c.print();
			break;
		case 2:
			cout<<"1)a-b  2)b-a :";
			cin>>s;
			if(s==1) {
				c=a-b;
				c.print();
			} else if(s==2) {
				c=b-a;
				c.print();
			}
			break;
		case 3:
			cout<<"1)a/b  2)b/a :";
			cin>>s;
			if(s==1) {
				c=a/b;
				c.print();
			} else if(s==2) {
				c=b/a;
				c.print();
			}
			break;
		case 4:
			c=a*b;
			c.print();
			break;
	}
	cout<<"1) go to menu  2)exit :";
	cin>>s;
	if(s==1)
		goto menu;
	else
		return 0;
}
