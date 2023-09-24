int norm (int x) {
        if (x < 0) {
                x += mod;
        }
        if (x >= mod) {
                x -= mod;
        }
        return x;
}
template<class T>
T power(T a, int b) {
        T res = 1;
        for (; b; b /= 2, a *= a) {
                if (b % 2) {
                res *= a;
                }
        }
        return res;
}
struct Z {
        int x;
        Z(int x = 0) : x(norm(x)) {}
        int val() const {
                return x;
        }
        Z operator-() const {
                return Z(norm(mod - x));
        }
        Z inv() const {
                assert(x != 0);
                return power(*this, mod - 2);
        }
        Z &operator*=(const Z &rhs) {
                x = x * rhs.x % mod;
                return *this;
        }
        Z &operator+=(const Z &rhs) {
                x = norm(x + rhs.x);
                return *this;
        }
        Z &operator-=(const Z &rhs) {
                x = norm(x - rhs.x);
                return *this;
        }
        Z &operator/=(const Z &rhs) {
                return *this *= rhs.inv();
        }
        friend Z operator*(const Z &lhs, const Z &rhs) {
                Z res = lhs;
                res *= rhs;
                return res;
        }
        friend Z operator+(const Z &lhs, const Z &rhs) {
                Z res = lhs;
                res += rhs;
                return res;
        }
        friend Z operator-(const Z &lhs, const Z &rhs) {
                Z res = lhs;
                res -= rhs;
                return res;
        }
        friend Z operator/(const Z &lhs, const Z &rhs) {
                Z res = lhs;
                res /= rhs;
                return res;
        }
        friend std::istream &operator>>(std::istream &is, Z &a) {
                int v;
                is >> v;
                a = Z(v);
                return is;
        }
        friend std::ostream &operator<<(std::ostream &os, const Z &a) {
                return os << a.val();
        }
};
