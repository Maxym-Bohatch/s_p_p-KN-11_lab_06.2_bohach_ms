#include <iostream>
#include <cmath>

class Vector3D {
private:
    double x, y, z;

public:
    // Конструктор за замовчуванням
    Vector3D() : x(0), y(0), z(0) {}

    // Конструктор з параметрами
    Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

    // Конструктор копії
    Vector3D(const Vector3D& other) : x(other.x), y(other.y), z(other.z) {}

    // Перевантаження оператора присвоювання
    Vector3D& operator=(const Vector3D& other) {
        if (this == &other) return *this; // Перевірка на самоприсвоювання
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    // Перевантаження оператора додавання
    Vector3D operator+(const Vector3D& other) const {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }

    // Перевантаження оператора векторного добутку
    Vector3D operator*(const Vector3D& other) const {
        return Vector3D(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    // Перевантаження оператора порівняння
    bool operator==(const Vector3D& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    bool operator!=(const Vector3D& other) const {
        return !(*this == other);
    }

    // Друк вектора
    void print() const {
        std::cout << "Vector3D(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
};

int main() {
    Vector3D v1(1.0, 2.0, 3.0);
    Vector3D v2(4.0, 5.0, 6.0);

    // Використання конструктора копії
    Vector3D v3 = v1;

    // Додавання векторів
    Vector3D v4 = v1 + v2;
    v4.print(); // Очікуваний результат: Vector3D(5.0, 7.0, 9.0)

    // Векторний добуток
    Vector3D v5 = v1 * v2;
    v5.print(); // Очікуваний результат: Vector3D(-3.0, 6.0, -3.0)

    // Операції присвоювання та порівняння
    Vector3D v6;
    v6 = v1;
    std::cout << (v6 == v1) << std::endl; // Очікуваний результат: 1 (true)
    std::cout << (v6 != v2) << std::endl; // Очікуваний результат: 1 (true)

    return 0;
}
