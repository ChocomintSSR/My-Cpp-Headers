
class point
{
private:
    int x_pos, y_pos;

public:
    point operator+(const point &ref);
    void operator=(const point &ref);
};

point point::operator+(const point &ref)
{
    point tmp;
    tmp.x_pos = this->x_pos + ref.x_pos;
    tmp.y_pos = this->y_pos + ref.y_pos;
    return tmp;
}

void point::operator=(const point &ref)
{
    this->x_pos = ref.x_pos;
    this->y_pos = ref.y_pos;
}

int main()
{

    point a, b, c;
    c = a + b;
}