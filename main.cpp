#include <iostream>

using namespace std;

class polynom {
public:
    float *cff;
    int size;

    polynom(int size1 = 1)
            : size(size1) {
        this->cff = new float[size];
        for (int i = 0; i < size; i++) {
            cff[i] = 0;
        }
    }

    polynom(const polynom &other) {
        this->size = other.size;
        this->cff = new float[other.size];
        for (int i = 0; i < other.size; i++) {
            this->cff[i] = other.cff[i];
        }
    }

    ~polynom() {
        delete[] cff;
    }

    void c_cin() {
        for (int i = 0; i < size; i++) {
            cin >> cff[i];
            if (size > 1) {
                if (i != size - 1) {
                    cout << "X^" << size - 1 << "\n";
                }
            }
        }
    }

    polynom &operator=(const polynom &other) {
        if (&other == this) {
            return *this;
        }
        this->size = other.size;
        delete[] this->cff;
        this->cff = new float[other.size];
        for (int i = 0; i < other.size; i++) {
            this->cff[i] = other.cff[i];
        }
        return *this;
    }

    polynom& operator+=(polynom &pol2){
        polynom tmp(*this);
        int k = this->size;
        int l = pol2.size;
        while (k != 0 or l != 0){
            --k;
            --l;
            this->cff[k] = this->cff[k] + pol2.cff[l];
        }
        return *this;
    }
    polynom& operator-=(polynom &pol2){
        polynom tmp(*this);
        int k = this->size;
        int l = pol2.size;
        while (k != 0 or l != 0){
            --k;
            --l;
            this->cff[k] = this->cff[k] - pol2.cff[l];
        }
        return *this;
    }

    polynom& operator+(polynom &other){
        int k = this->size;
        int l = other.size;
        while (k != 0 or l != 0){
            --k;
            --l;
            this->cff[k] = this->cff[k] + other.cff[l];
        }
        return *this;
    }
    polynom& operator-(polynom &other){
        int k = this->size;
        int l = other.size;
        while (k != 0 or l != 0){
            --k;
            --l;
            this->cff[k] = this->cff[k] - other.cff[l];
        }
        return *this;
    }
    polynom& operator-(){
        for (int i = 0; i < this->size; ++i){
            this->cff[i] = -1 * this->cff[i];
        }
        return *this;
    }

    polynom& operator/(float vall){
        for (int i = 0; i< size; ++i){
            this->cff[i] = this->cff[i] / vall;
        }
        return *this;
    }
    polynom& operator*(polynom& other){
        for (int i = 0; i < this->size; i++){
            for(int j = 0; j < other.size; i++){
                this->cff[i] += this->cff[i] * other.cff[i];
            }
        }
        return *this;
    }

    float operator[](int vall){
        return cff[vall];
    }
};

bool operator==(const polynom pol1, const polynom pol2) {
    if (pol1.size != pol2.size) {
        return false;
    }
    for (int i = 0; i < pol1.size; i++) {
        if (pol1.cff != pol2.cff) {
            return false;
        }
    }
}

bool operator!=(const polynom pol1, const polynom pol2) {
    return !operator==(pol1, pol2);
}

ostream &operator<<(ostream &stream, const polynom &value) {
    for (int i = 0; i < value.size; i++) {
        if (value.size > 1 and i != value.size - 1)
            stream << " " << value.cff[i] << "X^" << value.size - 1 - i << " +";
        if (value.size > 0 and value.size < 2) {
            stream << value.cff[0];
        }
        if (i == value.size - 1){
            stream << " " << value.cff[i];
        }
    }
    return stream;
}


int main() {


    return 0;
}
