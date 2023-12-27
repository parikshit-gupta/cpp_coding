template <typename T>
class pair
{
private:
    T x;
    T y;

public:
    void set_val(T x, T y)
    {
        this->x = x;
        this->y = y;
    }

    T get_x()
    {
        return x;
    }
    T get_y()
    {
        return y;
    }
};

template <typename T, typename V>
class pair1
{
private:
    T x;
    V y;

public:
    void set_val(T x, V y)
    {
        this->x = x;
        this->y = y;
    }

    T get_x()
    {
        return x;
    }
    V get_y()
    {
        return y;
    }
};

template <typename T, typename V>
class triple
{
private:
    T x;
    T y;
    V z;

public:
    void set_val(T x, T y, V z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    T get_x()
    {
        return x;
    }
    T get_y()
    {
        return y;
    }
    V get_z()
    {
        return z;
    }
};