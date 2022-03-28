//Double Link list
//Siti Zubaidah
//G1A021002

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;
struct node
{
    int info;
    struct node *next;
    struct node *prev;
}*start;
 
class double_list
{
    public:
        void create_list(int value);
        void add_begin(int value);
        void add_after(int value, int position);
        void delete_element(int value);
        void search_element(int value);
        void display_dlist();
        void count();
        void reverse();
        double_llist()
        {
            start = NULL;  
        }
};
 

int main()
{
    int choice, element, position;
    double_list dl;
    while (1)
    {
        cout<<endl<<"MENU"<<endl;        
        cout<<"1.Create"<<endl;
        cout<<"2.Insert"<<endl;
        cout<<"3.Insert After"<<endl;
        cout<<"4.Delete"<<endl;
        cout<<"5.Display"<<endl;
        cout<<"6.Count"<<endl;
        cout<<"7.Reverse"<<endl;
        cout<<"8.Quit"<<endl;
        cout<<"Masukkan pilihan anda : ";
        cin>>choice;
        switch ( choice )
        {
        case 1:
            cout<<"Masukkan elemen: ";
            cin>>element;
            dl.create_list(element);
            cout<<endl;
            break;
        case 2:
            cout<<"Masukkan elemen: ";
            cin>>element;
            dl.add_begin(element);
            cout<<endl;
            break;
        case 3:
            cout<<"Masukkan elemen: ";
            cin>>element;
            cout<<"Masukkan elemen setelah posisi ke: ";
            cin>>position;
            dl.add_after(element, position);
            cout<<endl;
            break;
        case 4:
            if (start == NULL)
            {                      
                cout<<"List sudah kosong"<<endl;   
                break;
            }
            cout<<"Masukkan elemen yang inign diapus: ";
            cin>>element;
            dl.delete_element(element);
            cout<<endl;
            break;
        case 5:
            dl.display_dlist();
            cout<<endl;
            break;
        case 6:
            dl.count();
            break;    
        case 7:
            if (start == NULL)
            {
                cout<<"List sudah kosong, tidak ada yang bisa dikembalikan"<<endl;
                break;
            }
            dl.reverse();
            cout<<endl;
            break;
        case 8:
            exit(1);
        default:
            cout<<"Pilihan yang anda dimasukkan salah"<<endl;
        }
    }
    return 0;
}
 
void double_list::create_list(int value)
{
    struct node *s, *temp;
    temp = new(struct node); 
    temp->info = value;
    temp->next = NULL;
    if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        s = start;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
}
 
void double_list::add_begin(int value)
{
    if (start == NULL)
    {
        cout<<"List pertama yang dibuat"<<endl;
        return;
    }
    struct node *temp;
    temp = new(struct node);
    temp->prev = NULL;
    temp->info = value;
    temp->next = start;
    start->prev = temp;
    start = temp;
    cout<<"Elemen dimasukkan"<<endl;
}
 
void double_list::add_after(int value, int pos)
{
    if (start == NULL)
    {
        cout<<"List pertama yang dibuat"<<endl;
        return;
    }
    struct node *tmp, *q;
    int i;
    q = start;
    for (i = 0;i < pos - 1;i++)
    {
        q = q->next;
        if (q == NULL)
        {
            cout<<"Elemen sudah kurang dari ";
            cout<<pos<<" element."<<endl;
            return;
        }
    }
    tmp = new(struct node);
    tmp->info = value;
    if (q->next == NULL)
    {
        q->next = tmp;
        tmp->next = NULL;
        tmp->prev = q;      
    }
    else
    {
        tmp->next = q->next;
        tmp->next->prev = tmp;
        q->next = tmp;
        tmp->prev = q;
    }
    cout<<"Elemen dimasukkan"<<endl;
}
 
void double_list::delete_element(int value)
{
    struct node *tmp, *q;
    if (start->info == value)
    {
        tmp = start;
        start = start->next;  
        start->prev = NULL;
        cout<<"Elemen dihapus"<<endl;
        free(tmp);
        return;
    }
    q = start;
    while (q->next->next != NULL)
    {   
        if (q->next->info == value)  
        {
            tmp = q->next;
            q->next = tmp->next;
            tmp->next->prev = q;
            cout<<"Elemen dihapus"<<endl;
            free(tmp);
            return;
        }
        q = q->next;
    }
    if (q->next->info == value)    
    { 	
        tmp = q->next;
        free(tmp);
        q->next = NULL;
        cout<<"Elemen dihapus"<<endl;
        return;
    }
    cout<<"Elemen "<<value<<" tidak ditemukan"<<endl;
}
 
void double_list::display_dlist()
{
    struct node *q;
    if (start == NULL)
    {
        cout<<"List kosong, tidak ada yang bisa ditampilkan"<<endl;
        return;
    }
    q = start;
    cout<<"Double Link Listnya adalah :"<<endl;
    while (q != NULL)
    {
        cout<<q->info<<" <-> ";
        q = q->next;
    }
    cout<<"NULL"<<endl;
}
 
void double_list::count()
{ 	
    struct node *q = start;
    int cnt = 0;
    while (q != NULL)
    {
        q = q->next;
        cnt++;
    }
    cout<<"Nomor elemennya adalah "<<cnt<<endl;
}
 
void double_list::reverse()
{
    struct node *p1, *p2;
    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while (p2 != NULL)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev; 
    }
    start = p1;
    cout<<"List dikembalikan"<<endl; 
}