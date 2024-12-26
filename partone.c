#include <stdio.h>
#include <string.h>
typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} Student;

void deleteStudentById(int id, Student students[], int *currentLength) {
    int found = 0;
    for (int i = 0; i < *currentLength; i++) {
        if (students[i].id == id) {
            found = 1;
            for (int j = i; j < *currentLength - 1; j++) {
                students[j] = students[j + 1];
            }
            (*currentLength)--; 
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien voi id = %d\n", id);
    }
}
void printStudents(Student students[], int currentLength) {
    printf("Danh sach sinh vien:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("ID: %d, Name: %s, Age: %d, Phone: %s\n",
               students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

int main() {
    Student students[5] = {
        {1, "Nguyen Van A", 20, "0123456789"},
        {2, "Le Thi B", 21, "0987654321"},
        {3, "Tran Van C", 22, "0111222333"},
        {4, "Pham Thi D", 23, "0222333444"},
        {5, "Hoang Van E", 24, "0333444555"}
    };
    int currentLength = 5; 
    printStudents(students, currentLength);
    int idToDelete;
    printf("\nNhap id sinh vien can xoa: ");
    scanf("%d", &idToDelete);
    deleteStudentById(idToDelete, students, &currentLength);
    printStudents(students, currentLength);

    return 0;
}
