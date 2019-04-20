#include <stdio.h>

int sum(int a, int b){
    return a+b;
}

int product(int a, int b){
    return a * b;
}

float fproduct(float a, float b){
    return a * b;
}

int square(int a){
    return product(a, a);
}

double sqroot(double square)
{
    double root=square/3;
    int i;
    if (square <= 0) return 0;
    for (i=0; i<32; i++)
        root = (root + square / root) / 2;
    return root;
}

int main(void){

    float gravity = 9.82;
    float mass = 47.0; //kg
    printf("Kinetic energy table: f=1/2m*v^2\n");
    printf("kg | velocity | kJ\n");
    printf("----------------------\n");
    for(int i=5;i<25;i+=5){
        printf("%.0f |%5d     | %.2f\n", mass, i, (fproduct(mass,square(i)))/2000 );
    }

    printf("\nFree falling: v = g*t\n");
    printf("Gravity | time | velocity\n");
    printf("---------------------------\n");
    for(int time=0;time<=100;time+=20){
        printf("%.2f    |%5d | %.2f\n", gravity, time, fproduct(gravity, time));
    }
    printf("\nEnergy required for escape velocity\n");
    int v = 11186; //km/h
    float ratio = 0.0002778;
    int human = 90;
    int elephant = 6000;
    int m1tank = 62000;
    printf("Object    |  kg   |   GJ    |  GWh\n");
    printf("-----------------------------------\n");

    float hjoules = (fproduct(human,square(v)/2));
    float ejoules = (fproduct(elephant,square(v)/2));
    float tjoules = (fproduct(m1tank,square(v)/2));
    printf(" %8s | %5d | %7.2f | %.2f\n", "Human", human, hjoules/1000000000, fproduct(hjoules, ratio)/1000000);
    printf(" %8s | %5d | %7.2f | %.2f\n", "Elephant", elephant, ejoules/1000000000, fproduct(ejoules, ratio)/1000000);
    printf(" %8s | %5d | %7.2f | %.2f\n", "M1 Abram", m1tank, tjoules/1000000000, fproduct(tjoules, ratio)/1000000);


    int n = 3;
    int arr1[3][3] = {{1,2,3},{3,2,1},{1,2,3}};
    int arr2[3][3] = {{4,5,6},{6,5,4},{4,6,5}};
    int arr3[3][3];
    printf("\nMatrix multiplication:\nMatrix1:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ", arr1[i][j]);
        }
        printf("\n");
    }
    printf("\nMatrix2:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ", arr2[i][j]);
        }
        printf("\n");
    }
    int sum;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum = 0;
            for(int k=0;k<n;k++){
                sum += arr1[i][k]*arr2[k][j];
            }
            arr3[i][j] = sum;
        }
    }
    printf("\nAlgorithm:\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ", arr3[i][j]);
        }
        printf("\n");
    }
}

