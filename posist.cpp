#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    char name[20];
    struct node* left;
    struct node* right;
};
int times() {

   time_t now = time(0);


   char* dt = ctime(&now);

   cout << "The local date and time is: " << dt << endl;

   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
   cout << "The UTC date and time is:"<< dt << endl;
}

int maxDepth(struct node* node)
{
   if (node==NULL)
       return 0;
   else
   {

       int lDepth = maxDepth(node->left);
       int rDepth = maxDepth(node->right);


       if (lDepth > rDepth)
           return(lDepth+1);
       else return(rDepth+1);
   }
}


struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

int main()
{
    struct node *root = newNode(1);
    times();

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout<<"Hight of tree is "<< maxDepth(root);
getchar();

    return 0;
}
