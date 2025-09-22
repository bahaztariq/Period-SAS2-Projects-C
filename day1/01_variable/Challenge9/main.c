#include <stdio.h>
#include <math.h>

 typedef struct{
    int x,y,z;
 }point;

int main() {

    int distance = 0;
    point p1;
    point p2;
    printf("Enter The valus of point 1: ");
    scanf("%d %d %d", &p1.x, &p1.y, &p1.z);
    printf("Enter The valus of point 2: ");
    scanf("%d %d %d", &p2.x, &p2.y, &p2.z);
    distance= sqrt( pow((p2.x-p1.x),2) + pow((p2.y-p1.y),2) + pow((p2.z-p1.z),2));
    printf("the distance is %d",distance);

    return 0;
}
