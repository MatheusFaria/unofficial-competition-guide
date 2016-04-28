#include <stdio.h>
#include <stdlib.h>

int read_int(){
     int x = 0, f = 1;

     char ch = getchar();
     while(ch < '0' || ch > '9'){
        if(ch=='-') f=-1;
        ch=getchar_unlocked();
     }
     while(ch>='0' && ch<='9'){
        x = (x<<1) + (x<<3) + ch - '0';
        ch = getchar_unlocked();
     }
     return x*f;
}

int main()
{
    // FAST IO

    // Basic input and output
        int a; long int b; long long int c;
        float d; double e;
        char f;
        scanf ("%d %ld %lld %f %lf %c", &a, &b, &c, &d, &e, &f);

        printf ("%d %ld %lld %f %lf %c\n", a, b, c, d, e, f);

    // Get a line with spaces. Ex: "Test this string"
        char name[100];
        scanf ("%[^\n]%*c", name);

    ////////////



    // FASTER IO

    // Get one char
        char g;
        g = getchar();
        putchar(g);
        putchar('<');

    ////////////


    // FASTEST IO

    // Read int
        int h = read_int();

    ////////////
    return 0;
}
