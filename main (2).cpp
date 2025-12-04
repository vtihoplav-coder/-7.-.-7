#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Function {
protected:
    string type;
    double a, b, c, d;

public:
    Function() : a(0), b(0), c(0), d(0), type("base") {}
    Function(string t, double a_, double b_, double c_, double d_)
        : type(t), a(a_), b(b_), c(c_), d(d_) {}

    virtual ~Function() {}

    virtual double compute(double x) = 0;

    virtual void show() {
        cout << "Тип: " << type << endl;
        cout << "a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;
    }

    virtual void edit() {
        cout << "Нові значення (a b c d): ";
        cin >> a >> b >> c >> d;
    }

    virtual bool matches(double value) {
        return (a == value || b == value || c == value || d == value);
    }
};

class Linear : public Function {
public:
    Linear() : Function("Лінійна", 0, 0, 0, 0) {}
    Linear(double a_, double b_) : Function("Лінійна", a_, b_, 0, 0) {}

    double compute(double x) override {
        return a * x + b;
    }
};

class Quadratic : public Function {
public:
    Quadratic() : Function("Квадратична", 0, 0, 0, 0) {}
    Quadratic(double a_, double b_, double c_)
        : Function("Квадратична", a_, b_, c_, 0) {}

    double compute(double x) override {
        return c * x * x + a * x + b;
    }
};

class Cubic : public Function {
public:
    Cubic() : Function("Кубічна", 0, 0, 0, 0) {}
    Cubic(double a_, double b_, double c_, double d_)
        : Function("Кубічна", a_, b_, c_, d_) {}

    double compute(double x) override {
        return d * x * x * x + c * x * x + a * x + b;
    }
};

int main() {
    vector<Function*> arr;
    arr.push_back(new Linear(2, 3));
    arr.push_back(new Quadratic(1, -2, 1));
    arr.push_back(new Cubic(1, 0, -1, 2));

    cout << "Всі функції:" << endl;
    for (auto f : arr) {
        f->show();
        cout << endl;
    }

    cout << "Пошук за коефіцієнтом (введіть значення): ";
    double key;
    cin >> key;

    for (auto f : arr) {
        if (f->matches(key)) {
            cout << "Знайдено: ";
            f->show();
        }
    }

    cout << "Редагування першої функції:" << endl;
    arr[0]->edit();

    cout << "Після редагування:" << endl;
    arr[0]->show();

    for (auto f : arr) delete f;
    return 0;
}
