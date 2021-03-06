#include <bits/stdc++.h>
using namespace std;

#define all(v)                      v.begin(), v.end()
#define Chrono                      chrono::steady_clock::now().time_since_epoch().count()
#define dist2D(x1, y1, x2, y2)            ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))
#define dist3D(x1, y1, z1, x2, y2, z2)    ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2))
#define EPS                         1e-15
#define eb                          emplace_back
#define endl                        "\n"
#define FastIO                      ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FI                          freopen("in.txt", "r", stdin)
#define FO                          freopen("out.txt", "w", stdout)
#define ff                          first
#define gt(i, x)                    get<i>(x)
#define INF              1000000000000000000
#define ld                          long double
#define ll                          long long
#define mem(x,y)                    memset(x, y, sizeof x)
#define mp                          make_pair
#define mt                          make_tuple
#define msi                         map<string, int>
#define mii                         map<int, int>
#define mis                         map<int, string>
#define MOD                         998244353
#define PI                          acos(-1.0)
#define PQ                          priority_queue
#define pb                          push_back
#define pib                         pair<int, bool>
#define pii                         pair<int, int>
#define iii                         pair<int, pii>
#define iiii                        pair<pii, pii>
#define pll                         pair<ll, ll>
#define present(c, x)               ((c).find(x) != (c).end())
#define sfi(x)                      scanf("%d", &x)
#define sfii(x,y)                   scanf("%d %d", &x, &y)
#define sfiii(x,y,z)                scanf("%d %d %d", &x, &y, &z)
#define siz(x)                      (int)x.size()
#define ss                          second
#define tii                         tuple<int, int>
#define tiii                        tuple<int, int, int>
#define tiiii                       tuple<int, int, int, int>
#define timeTaken                   endd = clock(); cerr << (double) (endd - beginn) / CLOCKS_PER_SEC * 1000 << endl
#define timeInit                    clock_t beginn = clock(), endd
#define ull                         unsigned long long
#define umsi                        unordered_map<string, int>
#define umii                        unordered_map<int, int>
#define umis                        unordered_map<int, string>
#define vb                          vector<bool>
#define vi                          vector<int>
#define vvi                         vector<vi>
#define vii                         vector<pii>
#define vvii                        vector<vii>
#define vll                         vector<ll>
#define vvll                        vector<vll>
#define vpll                        vector<pll>
#define bug(...)                    cerr << __LINE__ << " : (" << #__VA_ARGS__ << ") = ("; _Print(__VA_ARGS__);
template<class T> void _Print(T &&x) { cerr << x << ")" << endl; }
template<class T, class ...S> void _Print(T &&x, S &&...y) { cerr << x << ", "; _Print(y...); }

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
typedef tree<int,null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;

//os.order_of_key(v): returns how many elements strictly less than v
//os.find_by_order(k - 1): returns kth smallest element's iterator
*/

template<class T> class compare {
public:
    bool operator() (pair<T, T> &x, pair<T, T> &y) {
        if (x.first == y.first) {
            return x.ss > y.ss;
        }
        return x.ff > y.ff;
    }
};

template<class T> ostream &operator<<(ostream &os, const pair<T, T> &a) { return os << a.ff << " " << a.ss; }
ll power(ll a, int b) {
    ll po = 1;
    while (b) {
        if (b & 1)
            po *= a;
        a *= a;
        b >>= 1;
    }
    return po;
}

template<class T> pair<T, T> operator+(const pair<T, T> &a, const pair<T, T> &b) { return {a.ff + b.ff, a.ss + b.ss}; }
template<class T> pair<T, T> operator-(const pair<T, T> &a, const pair<T, T> &b) { return {a.ff - b.ff, a.ss - b.ss}; }
template<class T> pair<T, T> operator*(const pair<T, T> &a, const pair<T, T> &b) { return {a.ff * b.ff, a.ss * b.ss}; }
template<class T> pair<T, T> operator%(const pair<T, T> &a, const pair<T, T> &b) { return {a.ff % b.ff, a.ss % b.ss}; }
template<class T, class U> pair<T, T> operator+(const pair<T, T> &a, const U &b) { return {a.ff + b, a.ss + b}; }
template<class T, class U> pair<T, T> operator*(const pair<T, T> &a, const U &b) { return {a.ff * b, a.ss * b}; }

int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos){ return N = N & ~ (1 << pos); }
bool check(int N, int pos){ return (bool) (N & (1 << pos)); }

///=======================================template=======================================///

const int base_digits = 9;
const int base = 1000000000;

struct BigInt {
	int sign;
	vi a;
	
	//================Constructors================
	BigInt() : sign(1) {}
	BigInt(ll v) {
		*this = v;
	}
	
	BigInt& operator = (ll v) {
		sign = 1;
		if (v < 0) {
			sign = -1;
			v = -v;
		}
		a.clear();
		for (; v > 0; v /= base) {
			a.eb(v % base);
		}
		return *this;
	}
	
	BigInt(const string &s) {
		read(s);
	}
	
	//===============Input / Output==============
	
	void read(const string &s) {
		sign = 1;
		a.clear();
		int pos = 0;
		while (pos < siz(s) and (s[pos] == '-' or s[pos] == '+')) {
			if (s[pos] == '-')
				sign = -sign;
			++pos;
		}
		for (int i = siz(s) - 1; i >= pos; i -= base_digits) {
			int x = 0;
			for (int j = max(pos, i - base_digits + 1); j <= i; j++)
				x = x * 10 + s[j] - '0';
			a.eb(x);
		}
		trim();
	}
	
	friend istream& operator>>(istream &stream, BigInt &v) {
		string s;
		stream >> s;
		v.read(s);
		return stream;
	}
	
	friend ostream& operator<<(ostream &stream, const BigInt &v) {
		if (v.sign == -1 and !v.isZero())
			stream << '-';
		stream << (v.a.empty() ? 0 : v.a.back());
		for (int i = siz(v.a) - 2; i >= 0; i--) {
			stream << setw(base_digits) << setfill('0') << v.a[i];
		}
		return stream;
	}
	
	//===============Comparison================
	bool operator<(const BigInt &v) const {
		if (sign != v.sign)
			return sign < v.sign;
		if (siz(a) != siz(v.a)) 
			return sign * siz(a) < v.sign * siz(v.a);
		for (int i = siz(a) - 1; i >= 0; i--) {
			if (a[i] != v.a[i]) {
				return a[i] * sign < v.a[i] * sign;
			}
		}
		return false;
	}
	
	bool operator>(const BigInt &v) const {
		return v < *this;
	}
	bool operator<=(const BigInt &v) const {
		return !(v < *this);
	}
	bool operator>=(const BigInt &v) const {
		return !(*this < v);
	}
	bool operator==(const BigInt &v) const {
		return !(*this < v) and !(v < *this);
	}
	bool operator!=(const BigInt &v) const {
		return *this < v or v < *this;
	}
	
	friend int __compare_abs(const BigInt &x, const BigInt &y) {
		if (siz(x.a) != siz(y.a)) {
			return siz(x.a) < siz(y.a) ? -1 : 1;
		}
		for (int i = siz(x.a) - 1; i >= 0; i--) {
			if (x.a[i] != y.a[i]) 
				return x.a[i] < y.a[i] ? -1 : 1;
		}
		return 0;
	}
	
	//================Operators================= -x, +-/*
	
	BigInt operator-() const {
		BigInt res = *this;
		if (isZero())
			return res;
		res.sign = -res.sign;
		return res;
	}
	
	//sign ignored
	void __internal_add(const BigInt &v) {
		if (siz(a) < siz(v.a)) {
			a.resize(siz(v.a), 0);
		}
		for (int i = 0, carry = 0; i < siz(a) or carry; ++i) {
			if (i == siz(a))
				a.eb(0);
			a[i] += carry + (i < siz(v.a) ? v.a[i] : 0);
			carry = a[i] >= base;
			if (carry)
				a[i] -= base;
		}
	}
	
	void __internal_sub(const BigInt &v) {
		for (int i = 0, carry = 0; i < siz(v.a) or carry; ++i) {
			a[i] -= carry + (i < siz(v.a) ? v.a[i] : 0);
			carry = a[i] < 0;
			if (carry) a[i] += base;
		}
		this->trim();
	}
	
	BigInt operator+=(const BigInt &v) {
		if (sign == v.sign) {
			__internal_add(v);
		}
		else {
			if (__compare_abs(*this, v) >= 0) {
				__internal_sub(v);
			}
			else {
				BigInt vv = v;
				swap(*this, vv);
				__internal_sub(vv);
			}
		}
		return *this;
	}
	
	BigInt operator-=(const BigInt &v) {
		if (sign == v.sign) {
			if (__compare_abs(*this, v) >= 0) {
				__internal_sub(v);
			}
			else {
				BigInt vv = v;
				swap(*this, vv);
				__internal_sub(vv);
				this->sign = -this->sign;
			}
		}
		else {
			__internal_add(v);
		}
		return *this;
	}
	
	//Optimize operators + and - operation
	
	template<typename L, typename R >
		typename std::enable_if<
			std::is_convertible<L, BigInt>::value &&
			std::is_convertible<R, BigInt>::value &&
			std::is_lvalue_reference<R&&>::value,
			BigInt>::type friend operator + (L &&l, R &&r) {
		BigInt result(std::forward<L>(l));
		result += r;
		return result;
	}
	
	template <typename L, typename R >
		typename std::enable_if<
			std::is_convertible<L, BigInt>::value &&
			std::is_convertible<R, BigInt>::value &&
			std::is_rvalue_reference<R&&>::value,
			BigInt>::type friend operator + (L&&l, R&&r) {
		BigInt result(std::move(r));
		result += l;
		return result;
	}
	
	template<typename L, typename R>
		typename std::enable_if<
			std::is_convertible<L, BigInt>::value &&
			std::is_convertible<R, BigInt>::value,
			BigInt>::type friend operator - (L &&l, R && r) {
		BigInt result(std::forward<L>(l));
		result -= r;
		return result;
	}
	
	friend pair<BigInt, BigInt> divmod(const BigInt &a1, const BigInt &b1) {
		assert(b1 > 0); //divmod now well-defined for b < 0
		ll norm = base / (b1.a.back() + 1);
		BigInt a = a1.abs() * norm;
		BigInt b = b1.abs() * norm;
		BigInt q = 0, r = 0;
		q.a.resize(siz(a.a));
		
		for (int i = siz(a.a) - 1; i >= 0; i--) {
			r *= base;
			r += a.a[i];
			ll s1 = siz(r.a) <= siz(b.a) ? 0 : r.a[siz(b.a)];
			ll s2 = siz(r.a) <= siz(b.a) - 1 ? 0 : r.a[siz(b.a) - 1];
			ll d = ((ll) base * s1 + s2) / b.a.back();
			r -= b * d;
			while (r < 0) {
				r += b; --d;
			}
			q.a[i] = d;
		}
		
		q.sign = a1.sign * b1.sign;
		r.sign = a1.sign;
		q.trim();
		r.trim();
		auto res = mp(q, r / norm);
		if (res.ss < 0) res.ss += b1;
		return res;
	}
	
	BigInt operator/(const BigInt &v) const {
		return divmod(*this, v).ff;
	}
	
	BigInt operator%(const BigInt &v) const {
		return divmod(*this, v).ss;
	}
	
	void operator/=(int v) {
		assert(v > 0); //operator / not well-defined for v <= 0
		if (llabs(v) >= base) {
			*this /= BigInt(v);
			return;
		}
		if (v < 0)
			sign = -sign, v = -v;
		for (int i = siz(a) - 1, rem = 0; i >= 0; --i) {
			ll cur = a[i] + rem * (ll) base;
			a[i] = (int) (cur / v);
			rem = (int) (cur % v);
		}
		trim();
	}
	
	BigInt operator/(int v) const {
		assert(v > 0);
		if (llabs(v) >= base)
			return *this / BigInt(v);
		BigInt res = *this;
		res /= v;
		return res;
	}
	
	void operator/=(const BigInt &v) {
		*this = *this / v;
	}
	
	ll operator%(ll v) const {
		assert(v > 0);
		assert(v < base);
		int m = 0;
		for (int i = siz(a) - 1; i >= 0; i--) {
			m = (a[i] + m * (ll) base) % v;
		}
		return m * sign;
	}
	
	void operator*=(int v) {
        if (llabs(v) >= base) {
            *this *= BigInt(v);
            return ;
        }
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
            if (i == (int) a.size())
                a.push_back(0);
            long long cur = a[i] * (long long) v + carry;
            carry = (int) (cur / base);
            a[i] = (int) (cur % base);
        }
        trim();
    }

    BigInt operator*(int v) const {
        if (llabs(v) >= base) {
            return *this * BigInt(v);
        }
        BigInt res = *this;
        res *= v;
        return res;
    }

    // Convert base 10^old --> 10^new.
    static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
        vector<long long> p(max(old_digits, new_digits) + 1);
        p[0] = 1;
        for (int i = 1; i < (int) p.size(); i++)
            p[i] = p[i - 1] * 10;
        vector<int> res;
        long long cur = 0;
        int cur_digits = 0;
        for (int i = 0; i < (int) a.size(); i++) {
            cur += a[i] * p[cur_digits];
            cur_digits += old_digits;
            while (cur_digits >= new_digits) {
                res.push_back((long long)(cur % p[new_digits]));
                cur /= p[new_digits];
                cur_digits -= new_digits;
            }
        }
        res.push_back((int) cur);
        while (!res.empty() && !res.back())
            res.pop_back();
        return res;
    }

    void fft(vector<complex<double> > & a, bool invert) const {
        int n = (int) a.size();

        for (int i = 1, j = 0; i < n; ++i) {
            int bit = n >> 1;
            for (; j >= bit; bit >>= 1)
                j -= bit;
            j += bit;
            if (i < j)
                swap(a[i], a[j]);
        }

        for (int len = 2; len <= n; len <<= 1) {
            double ang = 2 * 3.14159265358979323846 / len * (invert ? -1 : 1);
            complex<double> wlen(cos(ang), sin(ang));
            for (int i = 0; i < n; i += len) {
                complex<double> w(1);
                for (int j = 0; j < len / 2; ++j) {
                    complex<double> u = a[i + j];
                    complex<double> v = a[i + j + len / 2] * w;
                    a[i + j] = u + v;
                    a[i + j + len / 2] = u - v;
                    w *= wlen;
                }
            }
        }
        if (invert)
            for (int i = 0; i < n; ++i)
                a[i] /= n;
    }

    void multiply_fft(const vector<int> &a, const vector<int> &b, vector<int> &res) const {
        vector<complex<double> > fa(a.begin(), a.end());
        vector<complex<double> > fb(b.begin(), b.end());
        int n = 1;
        while (n < (int) max(a.size(), b.size()))
            n <<= 1;
        n <<= 1;
        fa.resize(n);
        fb.resize(n);

        fft(fa, false);
        fft(fb, false);
        for (int i = 0; i < n; ++i)
            fa[i] *= fb[i];
        fft(fa, true);

        res.resize(n);
        long long carry = 0;
        for (int i = 0; i < n; ++i) {
            long long t = (long long) (fa[i].real() + 0.5) + carry;
            carry = t / 1000;
            res[i] = t % 1000;
        }
    }

    BigInt mul_simple(const BigInt &v) const {
        BigInt res;
        res.sign = sign * v.sign;
        res.a.resize(a.size() + v.a.size());
        for (int i = 0; i < (int) a.size(); ++i)
            if (a[i])
                for (int j = 0, carry = 0; j < (int) v.a.size() || carry; ++j) {
                    long long cur = res.a[i + j] + (long long) a[i] * (j < (int) v.a.size() ? v.a[j] : 0) + carry;
                    carry = (int) (cur / base);
                    res.a[i + j] = (int) (cur % base);
                }
        res.trim();
        return res;
    }

    static vll karatsubaMultiply(const vll &a, const vll &b) {
        int n = a.size();
        vll res(n + n);
        if (n <= 32) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    res[i + j] += a[i] * b[j];
            return res;
        }

        int k = n >> 1;
        vll a1(a.begin(), a.begin() + k);
        vll a2(a.begin() + k, a.end());
        vll b1(b.begin(), b.begin() + k);
        vll b2(b.begin() + k, b.end());

        vll a1b1 = karatsubaMultiply(a1, b1);
        vll a2b2 = karatsubaMultiply(a2, b2);

        for (int i = 0; i < k; i++)
            a2[i] += a1[i];
        for (int i = 0; i < k; i++)
            b2[i] += b1[i];

        vll r = karatsubaMultiply(a2, b2);
        for (int i = 0; i < (int) a1b1.size(); i++)
            r[i] -= a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            r[i] -= a2b2[i];

        for (int i = 0; i < (int) r.size(); i++)
            res[i + k] += r[i];
        for (int i = 0; i < (int) a1b1.size(); i++)
            res[i] += a1b1[i];
        for (int i = 0; i < (int) a2b2.size(); i++)
            res[i + n] += a2b2[i];
        return res;
    }

    BigInt mul_karatsuba(const BigInt &v) const {
        vector<int> a6 = convert_base(this->a, base_digits, 6);
        vector<int> b6 = convert_base(v.a, base_digits, 6);
        vll a(a6.begin(), a6.end());
        vll b(b6.begin(), b6.end());
        while (a.size() < b.size())
            a.push_back(0);
        while (b.size() < a.size())
            b.push_back(0);
        while (a.size() & (a.size() - 1))
            a.push_back(0), b.push_back(0);
        vll c = karatsubaMultiply(a, b);
        BigInt res;
        res.sign = sign * v.sign;
        long long carry = 0;
        for (int i = 0; i < (int) c.size(); i++) {
            long long cur = c[i] + carry;
            res.a.push_back((int) (cur % 1000000));
            carry = cur / 1000000;
        }
        res.a = convert_base(res.a, 6, base_digits);
        res.trim();
        return res;
    }

    void operator*=(const BigInt &v) {
        *this = *this * v;
    }
    BigInt operator*(const BigInt &v) const {
        if (a.size() * v.a.size() <= 1000111) return mul_simple(v);
        if (a.size() > 500111 || v.a.size() > 500111) return mul_fft(v);
        return mul_karatsuba(v);
    }

    BigInt mul_fft(const BigInt& v) const {
        BigInt res;
        res.sign = sign * v.sign;
        multiply_fft(convert_base(a, base_digits, 3), convert_base(v.a, base_digits, 3), res.a);
        res.a = convert_base(res.a, 3, base_digits);
        res.trim();
        return res;
    }

    // -------------------- Misc --------------------
    BigInt abs() const {
        BigInt res = *this;
        res.sign *= res.sign;
        return res;
    }
    void trim() {
        while (!a.empty() && !a.back())
            a.pop_back();
        if (a.empty())
            sign = 1;
    }

    bool isZero() const {
        return a.empty() || (a.size() == 1 && !a[0]);
    }

    friend BigInt gcd(const BigInt &a, const BigInt &b) {
        return b.isZero() ? a : gcd(b, a % b);
    }
    friend BigInt lcm(const BigInt &a, const BigInt &b) {
        return a / gcd(a, b) * b;
    }

    friend BigInt sqrt(const BigInt &a1) {
        BigInt a = a1;
        while (a.a.empty() || a.a.size() % 2 == 1)
            a.a.push_back(0);

        int n = a.a.size();

        int firstDigit = (int) sqrt((double) a.a[n - 1] * base + a.a[n - 2]);
        int norm = base / (firstDigit + 1);
        a *= norm;
        a *= norm;
        while (a.a.empty() || a.a.size() % 2 == 1)
            a.a.push_back(0);

        BigInt r = (long long) a.a[n - 1] * base + a.a[n - 2];
        firstDigit = (int) sqrt((double) a.a[n - 1] * base + a.a[n - 2]);
        int q = firstDigit;
        BigInt res;

        for(int j = n / 2 - 1; j >= 0; j--) {
            for(; ; --q) {
                BigInt r1 = (r - (res * 2 * BigInt(base) + q) * q) * BigInt(base) * BigInt(base) + (j > 0 ? (long long) a.a[2 * j - 1] * base + a.a[2 * j - 2] : 0);
                if (r1 >= 0) {
                    r = r1;
                    break;
                }
            }
            res *= base;
            res += q;

            if (j > 0) {
                int d1 = res.a.size() + 2 < r.a.size() ? r.a[res.a.size() + 2] : 0;
                int d2 = res.a.size() + 1 < r.a.size() ? r.a[res.a.size() + 1] : 0;
                int d3 = res.a.size() < r.a.size() ? r.a[res.a.size()] : 0;
                q = ((long long) d1 * base * base + (long long) d2 * base + d3) / (firstDigit * 2);
            }
        }

        res.trim();
        return res / norm;
    }
    // <added>
    BigInt operator^(BigInt b) {
		BigInt a = *this;
		BigInt res = 1;
		while (!b.isZero()) {
			if (b % 2 == 1) {
				res = res * a;
			}
			b /= 2;
			a *= a;
		}
		return res;
	}
	
	string toString() {//without sign
		string res, temp;
		
		res += (a.empty() ? to_string(0) : to_string(a.back()));
		
		for (int i = siz(a) - 2; i >= 0; i--) {
			temp = to_string(a[i]);
			while (siz(temp) < 9)
				temp += '0';
			res += temp;
		}
		return res;
	}
	
	//</added>
};

int main() {
	//FI; //FO;
	//FastIO; //timeInit;
	
	BigInt a = 0;
	int cs = 0;
	
	while (cs++ < 100) {
		BigInt b;
		cin >> b;
		a += b;
	}
	
	string ans = a.toString();
	for (int i = 0; i < 10; i++)
		cout << ans[i];
	
	
	//timeTaken;
	return 0;
}
