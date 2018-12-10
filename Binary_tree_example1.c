#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node * left, * right;
};
node* root=NULL;
node* root3=NULL;

node* new_node(int data){
node* p=new node;
p-&gt;left=NULL;
p-&gt;right=NULL;
p-&gt;data = data;
return(p);
}
node* insert(node* root, int data){
if(root!=NULL){
if(data &lt; root-&gt;data)
root-&gt;left= insert(root-&gt;left,data);
else if(data &gt; root-&gt;data)

root-&gt;right=insert(root-&gt;right,data);

}

else
root=new_node(data);
return root;
}
node* copyOdd(node* root, node* root3){
if(root!=NULL){

if(root-&gt;data % 2 == 1)

root3 = insert(root3, root-&gt;data);
root3 = copyOdd(root-&gt;left, root3);
root3 = copyOdd(root-&gt;right, root3);
}
return root3;
}
int main(){                  //Finds the odd numbers in a binary tree and copy these data to new one.
int dizi[14] = {25, 14, 23, 40, 24, 23, 48, 7, 5, 34, 10, 7, 17, 36};
for(int i=0;i&lt;14;i++) {
root = insert(root, dizi[i]);
}
root3 = copyOdd(root, root3);
printf(&quot;Agac Yapisi Inorder:\n&quot;);
printtree(root3);
}
