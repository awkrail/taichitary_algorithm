#include "taichitary.h"

struct xy{
    double x;
    double y;
};

int n;

void koch(int d, xy a, xy b){
    if(d == 0) return; //終了条件

    xy s, t, u;
    double th = M_PI * 60.0 / 180.0;

    s.x = (2.0*a.x + 1.0*b.x) / 3.0;
    s.y = (2.0*a.y + 1.0*b.y) / 3.0;
    t.x = (1.0*a.x + 2.0*b.x) / 3.0;
    t.y = (1.0*a.y + 2.0*b.y) / 3.0;
    u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

    koch(d-1, a, s);
    cout << s.x << " " << s.y << endl;
    koch(d-1, s, u);
    cout << u.x << " " << u.y << endl;
    koch(d-1, u, t);
    cout << t.x << " " << t.y << endl;
    koch(d-1, t, b);

}

int main(){

    cin >> n;

    xy a;
    a.x = 0;
    a.y = 0;
    xy b;
    b.x = 100.0;
    b.y = 0;

    cout << a.x << " " << a.y << endl;
    koch(n, a, b);
    cout << b.x << " " << b.y << endl;

}