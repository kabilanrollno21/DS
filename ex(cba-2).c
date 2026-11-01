#include <stdio.h>
#include <stdlib.h>
#define MAX 5
void producer();
void consumer();
void display();
int q[MAX], rear = 1, front = 1;
int main() {
 int choice;
 do {
 printf("\n1.Producer \n2.Consumer \n3.Display \n4.Exit");
 printf("\nEnter your choice: ");
 scanf("%d", &choice);
 switch(choice) {
 case 1:
 producer();
 break;
 case 2:
 consumer();
 break;
 case 3:
 display();
 break;
 case 4:
 exit(0);
 default:
 printf("\nEnter valid choice:");
 }
 } while(choice != 4);
 return 0;
}
void producer() {
 int value;
 if (rear > MAX) {
 printf("\nBuffer is full");
 } else {
 printf("\nEnter the piece of data : ");
 scanf("%d", &value);
 q[rear] = value;
 rear++;
 }
}
void consumer() {
 int x, i;
 if (rear == 1) {
 printf("\nBuffer is empty");
 } else {
 x = q[front];
 for (i = front; i < rear; i++)
 q[i] = q[i + 1];
 printf("\nThe consumed data is = %d", x);
 rear--;
 }
}
void display() {
 int count;
 if (rear == 1) {
 printf("\nThere are no data");
 } else {
 printf("\nThe data are");
 for (count = front; count < rear; count++) {
 printf("\n%d", q[count]);
 }
 }
}
