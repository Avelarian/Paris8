class Model
{
private:
    double a;
    double b;
    double c;

public:
    double getA() { return a; }
    double getB() { return b; }
    double getC() { return c; }

    void setA(double a) { this->a = a; }
    void setB(double b) { this->b = b; }
    void setC(double c) { this->c = c; }

    void incrementA(double a) { this->a += a; }
    void incrementB(double b) { this->b += b; }
    void incrementC(double c) { this->c += c; }

    void decrementA(double a) { this->a -= a; }
    void decrementB(double b) { this->b -= b; }
    void decrementC(double c) { this->c -= c; }
};

// f(x, y) = z
class TrainingExample
{
private:
    double x;
    double y;
    double z;

public:
    double getX() { return x; }
    double getY() { return y; }
    double getZ() { return z; }

    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    void setZ(double z) { this->z = z; }
};