#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



struct AVLNode;
typedef struct AVLNode *Position;
typedef struct AVLNode *AVLTree;

typedef int ElementType;

AVLTree MakeEmpty(AVLTree T);
Position Find(ElementType X, AVLTree T);
Position FindMin(AVLTree T);
Position FindMax(AVLTree T);
AVLTree Insert(ElementType X, AVLTree T);
AVLTree Delete(ElementType X, AVLTree T);

struct AVLNode
{
  ElementType Element;
  AVLTree Left;
  AVLTree Right;
  int Height;
};

static int
Max(ElementType X, ElementType Y)
{
  return (X)>(Y)?(X):(Y);
}
static int
Height( Position P )
{
  if (P == NULL)
    return -1;
  else
    return P->Height;
}

static Position
SingleRotateWithRight (Position K1)
{
  Position K2;
  K2 = K1->Right;
  K1->Right = K2->Left;
  K2->Left= K1;

  /*Recalculate Height of tree*/
  K1->Height = Max( Height(K1->Right), Height(K1->Left)) + 1;
  K2->Height = Max( Height(K2->Right), K1->Height) + 1;

  return K2;

}
static Position
SingleRotateWithLeft (Position K2)
{
  /*K2 is The root of tree*/
  /*(K1)' is the left tree of K2*/
  /* The tree looks like:
   *            K2                         K2        (K2's left Point to K1->Right)       (K1->Right Point to K2)
   *           /                          /                                                  K1->(K1)'                
   *         (K1)'       ====>      K1->(K1)'    ====>    K1->(K1)'   K2            ====>     /    \
   *        /   \                       /  \                  /  \   /                       A      K2
   *       A     B                     A    B                A     B                                 /
   *                                                                                                 B
   *
   * /              
  /*This K1 isn't (K1)'. This K1 will be a new root after rotate*/

  Position K1;
  K1 = K2->Left;
  K2->Left = K1->Right;
  K1->Right = K2;

  /*Recalculate Height of tree*/
  K2->Height = Max( Height(K2->Left), Height(K2->Right)) + 1;
  K1->Height = Max( Height(K1->Left), K2->Height) + 1;

  return K1;

}

static Position
DoubleRotateWithLeft(Position K3)
{
  /*K3 is root of tree*/
  /*
   * DoubleRotate is component of two single rotates
   *               K3                  K3                 K2
   *              /  \                /  \               /  \
   *            K1    D             K2    D             K1   K3   
   *           /  \       ===>     /  \       ===>     /  \ /  \
   *          A    K2             K1   C              A   B C   D
   *              /  \           /  \
   *             B    C         A    B 
   *
   */
  /*Rotate between K1 and K2*/

  K3->Left = SingleRotateWithRight(K3->Left);

  return SingleRotateWithLeft(K3);
}
static Position
DoubleRotateWithRight(Position K3)
{
  /*K3 is root of tree*/
  /*
   * DoubleRotate is component of two single rotates
   *
   */
  /*Rotate between K1 and K2*/

  K3->Right = SingleRotateWithLeft(K3->Right);

  return SingleRotateWithRight(K3);
}
AVLTree
Insert(ElementType X, AVLTree T)
{
  /*When T is NULL*/
  if (T == NULL)
  {
    /*Create and return a one-node tree*/
    T = (struct AVLNode*)malloc(sizeof (struct AVLNode));
    if (T == NULL) {
      perror("malloc");
      exit(1);
    }else{
      T->Element = X; T->Height = 0;
      T->Left = T->Right = NULL;
    }
  }
  /*When T isn't NULL*/
  else
  if (X < T->Element)
  {
    /*When X need Insert into Left Tree of T.*/
    T->Left = Insert(X, T->Left);
    if (Height(T->Left) - Height(T->Right) == 2) {
      /*Now we need a rotate to balance*/
      if (X < T->Left->Element) {
         T = SingleRotateWithLeft(T);
      }else {
         T = DoubleRotateWithLeft(T); 
      }
    }
  }
  else
  if (X > T->Element)
  {
    /*When X need Insert into Right Tree of T.*/
    T->Right = Insert(X, T->Right);
    if (Height(T->Right) - Height(T->Left) == 2) {
      if (X > T->Right->Element) {
        T=SingleRotateWithRight(T);
      }else{
        T=DoubleRotateWithRight(T);
      }
    }
  }
  /*When X is ready in Tree, we do nothing.*/
  T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
  return T;
}
void show(AVLTree T)
{
  if (T == NULL) {
    return;
  }else {
    printf("James:%d\n", T->Element);
    show(T->Left);
    show(T->Right);
  }
}
int
main(int argc, char **argv)
{
  int max = 16;
  int i;
  AVLTree T=NULL;
  while(max--) {
    scanf("%d\n", &i);
    T=Insert(i, T);
  }
  show(T);
	return 0;
}
