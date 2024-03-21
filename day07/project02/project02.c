#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUF_SIZE 100

typedef struct BOOK {
    char name[BUF_SIZE]; // ���ڿ��� ������ �迭�� ����
    char author[BUF_SIZE]; // ���ڿ��� ������ �迭�� ����
    char publisher[BUF_SIZE];
    int price;
    int page;
    int Id;
} book;

int main() {
    int choice;
    book books[BUF_SIZE];
    char bname[BUF_SIZE];
    char bauthor[BUF_SIZE];
    char bpublisher[BUF_SIZE];
    int bpage;
    int bprice;
    int bId;
    int numBooks = 0;
 

    while (1) {
        printf("***** �޴� *****\n");
        printf("1. ���� ���    2. ���� �˻�    3. ���� ����    4. ���� ���    5. ����\n");
        printf("��ȣ�� �Է��Ͻÿ� : \n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("å�� ������ �Է��� �ּ��� : \n");
            scanf("%s", &bname); // ������ �������� ���� ���ڿ� �Է� �ޱ�

            printf("å�� ���ڸ� �Է��� �ּ��� : \n");
            scanf("%s", &bauthor); 

            printf("å�� ���ǻ� �� �Է��� �ּ��� : \n");
            scanf("%s", &bpublisher);

            printf("å�� ID�� �Է��� �ּ��� : \n");
            scanf("%d", &bId);

            printf("å�� ������ �Է��� �ּ��� : \n");
            scanf("%d", &bprice);

            printf("å�� �������� �Է��� �ּ��� : \n");
            scanf("%d", &bpage);

            // books �迭�� å ���� ����
            strcpy(books[numBooks].name, bname);
            strcpy(books[numBooks].author, bauthor);
            strcpy(books[numBooks].publisher, bpublisher);
            books[numBooks].Id = bId;
            books[numBooks].price = bprice;
            books[numBooks].page = bpage;
            numBooks += 1; // ��ϵ� å�� �� ����
        }
        else if (choice == 2) {
            printf("�˻��� å�� ������ �Է��� �ּ���.\n");
            scanf("%s", &bname);
            for (int i = 0; i <= numBooks; i++) {
                if (strcmp(books[i].name, bname) == 0) {
                    printf("å ���� : %s\n", books[i].name);
                    printf("���ǻ� : % s\n", books[i].publisher);
                    printf("���� : % s\n", books[i].author);
                    printf("å ID : %d\n", books[i].Id);
                    printf("å ���� : %d\n", books[i].price);
                    printf("å ������ : %d\n", books[i].page);

                }
            }
        }
        
        else if (choice == 3) {
            int found = 0;
            printf("������ å�� ������ �Է��� �ּ���.\n");
            
            scanf("%s", &bname);
            
            for (int i = 0; i < numBooks; i++) {
                if (strcmp(books[i].name, bname) == 0) {
                    // �ش� å�� ã���� ����
                    for (int j = i; j < numBooks; j++) {
                        if (j == numBooks) {
                            strcpy(books[j].name, NULL);
                            strcpy(books[j].publisher, NULL);
                            strcpy(books[j].author, NULL);
                            books[j].Id = 0;
                            books[j].price = 0;
                            books[j].page = 0;
                            numBooks -= 1;
                        }
                        strcpy(books[j].name, books[j + 1].name);
                        strcpy(books[j].publisher, books[j + 1].publisher);
                        strcpy(books[j].author, books[j + 1].author);
                        books[j].Id = books[j + 1].Id;
                        books[j].price = books[j + 1].price;
                        books[j].page = books[j + 1].page;
                    }
                    numBooks--; // å�� ���� ����
                    found = 1;
                    printf("å�� ���������� �����Ǿ����ϴ�.\n");

                }
            }
            if (!found) {
                printf("�ش� å�� ã�� �� �����ϴ�.\n");
            }
            

        }
        
        else if (choice == 4) {
            if (numBooks >= 1) {
                printf("��ü å�� ��ȸ �ϰڽ��ϴ�.");
                for (int i = 0; i < numBooks; i++) {
                    printf("å ���� : %s\n", books[i].name);
                    printf("å ���ǻ� : %s\n", books[i].publisher);
                    printf("���� : % s\n", books[i].author);
                    printf("å ID : %d\n", books[i].Id);
                    printf("å ���� : %d\n", books[i].price);
                    printf("å ������ : %d\n", books[i].page);
                }
            }
            
            else if (numBooks < 1) {
                printf("��ȸ�� å�� �����ϴ�.\n");
            }
        }


        else if (choice == 5) {
            break;
        }
    }

    return 0;
}
