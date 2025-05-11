#pragma once

#include <cmath>
#include <complex>
#include <initializer_list>


#define Log(fmt, ...) printf("%s[%s: %d]: " fmt, __FILE__, __FUNCTION__, __LINE__, ## __VA_ARGS__)

template <size_t N>
class Vector {
public:
    Vector() = default;
    ~Vector() = default;

    explicit Vector(float value) {
        for(size_t i = 0; i < N; i++) {
            data[i] = value;
        }
    }

    float operator[](size_t index) const {
        return data[index];
    }

    float& operator[](size_t index) {
        return data[index];
    }

    Vector(const std::initializer_list<float>& l) {
        const size_t max = std::min(N, l.size());
        size_t i = 0;
        for(i = 0; i < max; i++) {
            data[i] = *(l.begin() + i);
        }
        for(; i < N; i++) {
            data[i] = 0.0f;
        }
    }

    float data[N]{};
};

template <size_t N>
const Vector<N> One = Vector<N>(1.0f);

template <size_t N>
const Vector<N> Zero = Vector<N>(0.0f);

template <>
class Vector<2> {
public:
    Vector() = default;
    ~Vector() = default;

    union {
        struct {
            float x, y;
        };
        struct {
            float w, h;
        };
        float data[2];
    };

    float operator[](size_t index) const {
        return data[index];
    }

    float& operator[](size_t index) {
        return data[index];
    }

    Vector(const std::initializer_list<float>& l) {
        const size_t max = std::min<size_t>(2, l.size());
        size_t i = 0;
        for(i = 0; i < max; i++) {
            data[i] = *(l.begin() + i);
        }
        for(; i < 2; i++) {
            data[i] = 0.0f;
        }
    }
};

template <>
class Vector<3> {
public:
    Vector() = default;
    ~Vector() = default;

    union {
        struct {
            float x, y, z;
        };
        struct {
            float r, g, b;
        };
        struct {
            float u, v, w;
        };
        float data[3];
    };

    float operator[](size_t index) const {
        return data[index];
    }

    float& operator[](size_t index) {
        return data[index];
    }

    Vector(const std::initializer_list<float>& l) {
        const size_t max = std::min<size_t>(3, l.size());
        size_t i = 0;
        for(i = 0; i < max; i++) {
            data[i] = *(l.begin() + i);
        }
        for(; i < 3; i++) {
            data[i] = 0.0f;
        }
    }
};

template <>
class Vector<4> {
public:
    Vector() = default;
    ~Vector() = default;

    union {
        struct {
            float x, y, z, w;
        };
        struct {
            float r, g, b, a;
        };
        float data[4];
    };

    float operator[](size_t index) const {
        return data[index];
    }

    float& operator[](size_t index) {
        return data[index];
    }

    Vector(const std::initializer_list<float>& l) {
        size_t max = std::min<size_t>(4, l.size());
        size_t i = 0;
        for(i = 0; i < max; i++) {
            data[i] = *(l.begin() + i);
        }
        for(; i < 4; i++) {
            data[i] = 0.0f;
        }
    }
};

using Vec2 = Vector<2>;
using Vec3 = Vector<3>;
using Vec4 = Vector<4>;
using Color3 = Vec3;
using Color4 = Vec4;

inline float cross(const Vector<2>& a, const Vector<2>& b) {
    return a.x * b.y - a.y * b.x;
}

inline Vector<3> cross(const Vector<3>& a, const Vector<3>& b) {
    return Vector<3>{a.y* b.z - a.z * b.y, a.z* b.x - a.x * b.z, a.x* b.y - a.y * b.x};
}

template <size_t N>
Vector<N> operator+(const Vector<N>& a, const Vector<N>& b) {
    Vector<N> result;
    for(size_t i = 0; i < N; i++) {
        result.data[i] = a.data[i] + b.data[i];
    }
    return result;
}

template <size_t N>
Vector<N> operator-(const Vector<N>& a, const Vector<N>& b) {
    Vector<N> result;
    for(size_t i = 0; i < N; i++) {
        result.data[i] = a.data[i] - b.data[i];
    }
    return result;
}

template <size_t N>
Vector<N> operator*(const Vector<N>& a, const Vector<N>& b) {
    Vector<N> result;
    for(size_t i = 0; i < N; i++) {
        result.data[i] = a.data[i] * b.data[i];
    }
    return result;
}

template <size_t N>
Vector<N> operator/(const Vector<N>& a, const Vector<N>& b) {
    Vector<N> result;
    for(size_t i = 0; i < N; i++) {
        result.data[i] = a.data[i] / b.data[i];
    }
    return result;
}

template <size_t N>
Vector<N> operator*(const Vector<N>& a, float value) {
    Vector<N> result;
    for(size_t i = 0; i < N; i++) {
        result.data[i] = a.data[i] * value;
    }
    return result;
}

template <size_t N>
Vector<N> operator/(const Vector<N>& a, float value) {
    Vector<N> result;
    for(size_t i = 0; i < N; i++) {
        result.data[i] = a.data[i] / value;
    }
    return result;
}

template <size_t N>
Vector<N> operator*(float value, const Vector<N>& a) {
    return a * value;
}

template <size_t N>
Vector<N> operator/=(Vector<N>& a, float value) {
    for(size_t i = 0; i < N; i++) {
        a.data[i] /= value;
    }
    return a;
}

template <size_t N>
Vector<N> operator+=(Vector<N>& a, const Vector<N>& b) {
    for(size_t i = 0; i < N; i++) {
        a.data[i] += b.data[i];
    }
    return a;
}

template <size_t N>
Vector<N> operator-=(Vector<N>& a, const Vector<N>& b) {
    for(size_t i = 0; i < N; i++) {
        a.data[i] -= b.data[i];
    }
    return a;
}

template <size_t N>
bool operator==(const Vector<N>& a, const Vector<N>& b) {
    for(size_t i = 0; i < N; i++) {
        if(a.data[i] != b.data[i]) {
            return false;
        }
    }
    return true;
}

template <size_t N>
bool operator!=(const Vector<N>& a, const Vector<N>& b) {
    return !(a == b);
}

template <size_t N>
float dot(const Vector<N>& a, const Vector<N>& b) {
    float result = 0.0f;
    for(size_t i = 0; i < N; i++) {
        result += a.data[i] * b.data[i];
    }
    return result;
}

template <size_t N>
float length(const Vector<N>& a) {
    return std::sqrt(dot(a, a));
}

template <size_t N>
Vector<N> normalize(const Vector<N>& a) {
    Vector<N> result;
    float len = length(a);
    if(len > 0.0f) {
        for(size_t i = 0; i < N; i++) {
            result.data[i] = a.data[i] / len;
        }
    }
    return result;
}

template <size_t N>
std::ostream& operator<<(std::ostream& os, const Vector<N>& a) {
    os << "Vector<" << N << ">(";
    for(size_t i = 0; i < N; i++) {
        if(i == N - 1) {
            os << " " << a.data[i] << ")";
        } else {
            os << " " << a.data[i] << ",";
        }
    }
    return os;
}

template <typename T>
inline T clamp(T value, T min, T max) {
    return std::max(min, std::min(value, max));
}


template <size_t Col, size_t Row>
class Matrix {
public:
    Matrix() = default;
    ~Matrix() = default;

    explicit Matrix(float value) {
        for(auto& d : m_data) {
            d = value;
        }
    }
    Matrix(const std::initializer_list<float>& l) {
        for(size_t i = 0; i < l.size(); i++) {
            set(i % Col, i / Col, *(l.begin() + i));
        }
    }
    Matrix(const std::initializer_list<Vector<Row>>& l) {
        for(size_t i = 0; i < l.size(); i++) {
            const auto& row = *(l.begin() + i);
            for(size_t j = 0; j < Row; j++) {
                set(i, j, row.data[j]);
            }
        }
    }

    static size_t getCols() { return Col; }
    static size_t getRows() { return Row; }

    [[nodiscard]] float get(size_t col, size_t row) const {
        return m_data[col * Row + row];
    }

    void set(size_t col, size_t row, float value) {
        m_data[col * Row + row] = value;
    }

    Matrix operator*=(float value) {
        for(auto& element : m_data) {
            element *= value;
        }
        return *this;
    }
    Matrix operator/=(float value) {
        for(auto& element : m_data) {
            element /= value;
        }
        return *this;
    }
    Matrix operator+=(const Matrix& m) {
        for(size_t i = 0; i < Col * Row; i++) {
            m_data[i] += m.get(i % Col, i / Col);
        }
        return *this;
    }
    Matrix operator-=(const Matrix& m) {
        for(size_t i = 0; i < Col * Row; i++) {
            m_data[i] -= m.get(i % Col, i / Col);
        }
        return *this;
    }
    Matrix operator*(float value) const {
        Matrix result = *this;
        for(auto& element : result.m_data) {
            element *= value;
        }
        return result;
    }
    Matrix operator/(float value) const {
        Matrix result = *this;
        for(auto& element : result.m_data) {
            element /= value;
        }
        return result;
    }
    Matrix operator+(const Matrix& m) const {
        Matrix result = *this;
        for(size_t i = 0; i < Col * Row; i++) {
            result.m_data[i] += m.get(i % Col, i / Col);
        }
        return result;
    }
    Matrix operator-(const Matrix& m) const {
        Matrix result = *this;
        for(size_t i = 0; i < Col * Row; i++) {
            result.m_data[i] -= m.get(i % Col, i / Col);
        }
        return result;
    }
    Matrix operator*(const Matrix& m) {
        static_assert(Col == Row, "Matrix multiplication only works for square matrices.");
        Matrix result = *this;
        for(size_t i = 0; i < Col; i++) {
            for(size_t j = 0; j < Row; j++) {
                float sum = 0.0f;
                for(size_t k = 0; k < Col; k++) {
                    sum += this->get(k, j) * m.get(i, k);
                }
                result.set(i, j, sum);
            }
        }
        return result;
    }
    Matrix operator*=(const Matrix& m) {
        static_assert(Col == Row, "Matrix multiplication only works for square matrices.");
        Matrix result = *this;
        for(size_t i = 0; i < Col; i++) {
            for(size_t j = 0; j < Row; j++) {
                float sum = 0.0f;
                for(size_t k = 0; k < Col; k++) {
                    sum += this->get(k, j) * m.get(i, k);
                }
                result.set(i, j, sum);
            }
        }
        *this = result;
        return *this;
    }

    Matrix transpose() const {
        for(size_t i = 0; i < Col; i++) {
            for(size_t j = 0; j < Row; j++) {
                set(j, i, get(i, j));
            }
        }
        return  *this;
    }

    Matrix inverse() const {
        static_assert(Col == Row, "Matrix inverse only works for square matrices.");
        for(size_t i = 0; i < Col; i++) {
            for(size_t j = 0; j < Row; j++) {
                float sum = 0.0f;
                for(size_t k = 0; k < Col; k++) {
                    sum += get(k, i) * get(k, j);
                }
                set(i, j, sum);
            }
        }
        return  *this;
    }

private:
    float m_data[Col * Row]{};
};

using Mat22 = Matrix<2, 2>;
using Mat33 = Matrix<3, 3>;
using Mat44 = Matrix<4, 4>;

template <size_t Col, size_t Row>
Matrix<Col, Row> transpose(const Matrix<Col, Row>& m) {
    Matrix<Col, Row> result;
    for(size_t i = 0; i < Col; i++) {
        for(size_t j = 0; j < Row; j++) {
            result.set(j, i, m.get(i, j));
        }
    }
    return result;
}

template <size_t Col, size_t Row>
Matrix<Col, Row> inverse(const Matrix<Col, Row>& m) {
    static_assert(Col == Row, "Matrix inverse only works for square matrices.");
    Matrix<Col, Row> result = m;
    for(size_t i = 0; i < Col; i++) {
        for(size_t j = 0; j < Row; j++) {
            float sum = 0.0f;
            for(size_t k = 0; k < Col; k++) {
                sum += m.get(k, i) * m.get(k, j);
            }
            result.set(i, j, sum);
        }
    }
    return result;
}

template <size_t Col, size_t Row>
Vector<Row> operator*(const Matrix<Col, Row>& m, const Vector<Col>& v) {
    Vector<Row> result;
    for(size_t j = 0; j < Row; j++) {
        float sum = 0.0f;
        for(size_t i = 0; i < Col; i++) {
            sum += v.data[i] * m.get(i, j);
        }
        result.data[j] = sum;
    }
    return result;
}

template <size_t Col, size_t Row>
std::ostream& operator<<(std::ostream& os, const Matrix<Col, Row>& m) {
    os << "Matrix<" << Col << "," << Row << ">[" << '\n';
    for(size_t i = 0; i < Row; i++) {
        for(size_t j = 0; j < Col; j++) {
            if(j == Col - 1) {
                os << m.get(j, i);
            } else {
                os << m.get(j, i) << ",";
            }
        }
        os << std::endl;
    }
    os << ']';
    return os;
}

template <size_t Col, size_t Row>
Matrix<Col, Row> operator*(const Matrix<Col, Row>& m1, const Matrix<Col, Row>& m2) {
    static_assert(Col == Row, "Matrix multiplication only works for square matrices.");
    Matrix<Col, Row> result;
    for(size_t i = 0; i < Col; i++) {
        for(size_t j = 0; j < Row; j++) {
            float sum = 0.0f;
            for(size_t k = 0; k < Col; k++) {
                sum += m1.get(i, k) * m2.get(k, j);
            }
            result.set(i, j, sum);
        }
    }
    return result;
}

struct Rect {
    Vec2 pos;
    Vec2 size;
};

inline bool isPointInRect(const Vec2& p, const Rect& r) {
    return p.x >= r.pos.x && p.x <= r.pos.x + r.size.w &&
        p.y >= r.pos.y && p.y <= r.pos.y + r.size.h;
}

inline bool isRectsIntersect(const Rect& r1, const Rect& r2) {
    Rect rect{};
    rect.pos.x = std::max(r1.pos.x, r2.pos.x);
    rect.pos.y = std::max(r1.pos.y, r2.pos.y);
    rect.pos.w = std::min(r1.pos.x + r1.size.w, r2.pos.x + r2.size.w) - rect.pos.x;
    rect.pos.h = std::min(r1.pos.y + r1.size.h, r2.pos.y + r2.size.h) - rect.pos.y;
    if(rect.size.w > 0 && rect.size.h > 0) {
        return true;
    }
    return false;
}