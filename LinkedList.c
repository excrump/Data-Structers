#include <stdio.h>
#include <stdlib.h>

int sayi,data;
struct node{
    int data;
    struct node *next ;

};
struct node *head;


int basaekle(){
    struct node *yeni;
    yeni = (struct node*)malloc(sizeof(struct node));
    yeni->next= NULL;
    printf("\n Eklenecek veriyi giriniz; ");
    scanf("%d", &yeni->data);
    if (head==NULL){
        head= yeni;
    }
    else{
        yeni->next=head;
        head=yeni;
    }
    return 0;
}

int sonaekle(){
    struct node *yeni;
    struct node *temp;
    yeni=(struct node*)malloc(sizeof(struct node));
    printf("\n Eklenecek veriyi giriniz; ");
    scanf("%d",&yeni->data);
    yeni->next= NULL;
        if(head==NULL){
            head=yeni;
            return 1;
        }
        else{
            temp=head;
            while(temp->next!=NULL){
                temp = temp-> next;
            }
            yeni->next=NULL;
            temp->next= yeni;
        }
        return 0;
}
void bilgi(){
    struct node *temp;
    temp=head;
    if(temp!=NULL){
        printf("\n Listenin icerigi: ");
        while(temp!=NULL){
            printf("%d ->",temp->data);
            temp=temp->next;
        }
    }
    else    {
        printf("\n Suanda listeniz bos \n");
    }
}

int silme(struct node *head, int key){
    if(head==NULL){
            printf("Liste bos.\n");
        return 0;
    }
    struct node *temp=head;
    if(head->data==key){
        head=head->next;
        free(temp);
    }
    else{
            while(temp->next->data != key){
                temp=temp->next;
            }
    }
        struct node *temp2=temp->next;
        temp->next=temp->next->next;
        free(temp2);

    return head;
}

int hepsinisay(){
    struct node *yeni;
    int counter = 0;
    while(head!=NULL){
        counter++;
        head=head->next;
    }
    printf("Listedeki eleman sayisi %d ' dir.\n",counter);
    return 1;
}

void hepsinisil(struct node *temp2){

    struct node *temp=head;
    while (temp!=NULL){
        temp=head->next;
        free(head);
        head=temp;
    }
}
void printReverse(struct node *head){

    if(head==NULL){
        return;
    }
    printReverse(head->next);
    printf("%d",head->data);
}

int main(){
    while(1){
        printf("\n1.Listenin tum elemanlarini yazdirir\n");
        printf("2.Listenin Basina Eleman Ekler\n");
        printf("3.Listenin Sonuna Eleman Ekler\n");
        printf("4.Listenin eleman sayisini sayar\n");
        printf("5.Belirtilen veriye sahip dugumu siler\n");
        printf("6.Tum listeyi siler\n");
        printf("7.Listeyi tersten yazar\n");
        scanf("%d", &sayi);
        switch(sayi){
        case 1:
            bilgi(head);
            break;
        case 2:
            basaekle(head);
            break;
        case 3:
            sonaekle(head);
            break;
        case 4:
            hepsinisay(head);
            break;
        case 5:
            printf("Silmek istediginiz dugumun degerini giriniz: ");
            scanf("%d",&data);
            head=silme(head,data);
            break;
        case 6:
            hepsinisil(head);
            break;
        case 7:
            printReverse(head);
            break;
            default: printf("Gecerli bir tercih giriniz.\n");
        }
    }
    return 0;
}
