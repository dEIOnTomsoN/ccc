#include <stdio.h>
#include <math.h>

float area_of_square(float side) {
    return side * side;
}

float area_of_triangle(float base, float height) {
    return 0.5 * base * height;
}

float area_of_circle(float radius) {
    return M_PI * radius * radius;
}

float area_of_rectangle(float length, float breadth) {
    return length * breadth;
}

int main() {
    int choice;
    float side, base, length, breadth, height, area, radius;

    printf("Enter 1 to find the area of a square\n");
    printf("Enter 2 to find the area of a triangle\n");
    printf("Enter 3 to find the area of a circle\n");
    printf("Enter 4 to find the area of a rectangle\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Enter the length of a side: ");
            scanf("%f", &side);
            area = area_of_square(side);
            printf("The area of the square is %.2f square units.\n", area);
            break;
        case 2:
            printf("Enter the base and height: ");
            scanf("%f %f", &base, &height);
            area = area_of_triangle(base, height);
            printf("The area of the triangle is %.2f square units.\n", area);
            break;
        case 3:
            printf("Enter the radius: ");
            scanf("%f", &radius);
            area = area_of_circle(radius);
            printf("The area of the circle is %.2f square units.\n", area);
            break;
        case 4:
            printf("Enter the length and breadth: ");
            scanf("%f %f", &length, &breadth);
            area = area_of_rectangle(length, breadth);
            printf("The area of the rectangle is %.2f square units.\n", area);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
