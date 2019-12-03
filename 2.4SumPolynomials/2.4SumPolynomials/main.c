//
//  main.c
//  testC
//
//  Created by SZDCMAC11 on 2019/12/3.
//  Copyright © 2019 SZDCMAC11. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//typedef struct PolyNode {
//    int Base;
//    int Exponent;
//    struct PolyNode* Next;
//
//}PolyNode;
//typedef PolyNode* Polynomial;
//
//Polynomial CreatEmptyPolyNode() {
//    Polynomial p = (Polynomial)malloc(sizeof(PolyNode));
//    p->Next = NULL;
//    return p;
//}
//
//void ReadPolynomical(Polynomial p) {
//    if (p == NULL) {
//        p = CreatEmptyPolyNode();
//    }
//    int i, N;
//    int Exponent, Base;
//    Polynomial Cur = p;
//    Polynomial Temp = Cur -> Next;
//    scanf("%d",&N);
//    for (i = 0; i < N; i++) {
//        scanf("%d %d",&Base,&Exponent);
//        Temp = CreatEmptyPolyNode();
//        Temp -> Base = Base;
//        Temp -> Exponent = Exponent;
//        Cur -> Next = Temp;
//        Cur = Cur -> Next;
//        Temp = Temp -> Next;
//    }
//}
//
//Polynomial SumPolynomial(Polynomial p1, Polynomial p2) {
//    Polynomial Result = CreatEmptyPolyNode();
//    Polynomial Temp1 = p1 -> Next;
//    Polynomial Temp2 = p2 -> Next;
//    Polynomial Cur = Result;
//    Polynomial TempR = Result -> Next;
//    while (Temp1 && Temp2) {
//        if (Temp1->Exponent > Temp2->Exponent) {
//            TempR = CreatEmptyPolyNode();
//            TempR -> Exponent = Temp1 -> Exponent;
//            TempR -> Base = Temp1 -> Base;
//            Cur -> Next = TempR;
//            Cur = Cur -> Next;
//            TempR = TempR -> Next;
//            Temp1 = Temp1 -> Next;
//        } else if (Temp1->Exponent < Temp2->Exponent) {
//            TempR = CreatEmptyPolyNode();
//            TempR ->Exponent = Temp2 ->Exponent;
//            TempR ->Base = Temp1 -> Base;
//            Cur -> Next = TempR;
//            Cur = Cur -> Next;
//            TempR = TempR -> Next;
//            Temp1 = Temp1 -> Next;
//        } else {
//            if (Temp1->Exponent + Temp2->Exponent != 0) {
//                TempR = CreatEmptyPolyNode();
//                TempR -> Exponent = Temp2 -> Exponent;
//                TempR -> Base = Temp2 -> Base + Temp1->Base;
//                Cur ->Next = TempR;
//                Cur = Cur -> Next;
//                TempR = TempR ->Next;
//            }
//            Temp1 = Temp1 -> Next;
//            Temp2 = Temp2 -> Next;
//        }
//    }
//    while (Temp1) {
//        TempR = CreatEmptyPolyNode();
//        TempR -> Exponent = Temp1 -> Exponent;
//        TempR -> Base = Temp1 -> Base;
//        Cur -> Next = TempR;
//        Cur = Cur -> Next;
//        TempR = TempR -> Next;
//        Temp1 = Temp1 -> Next;
//    }
//    while (Temp2) {
//        TempR = CreatEmptyPolyNode();
//        TempR -> Exponent = Temp2 -> Exponent;
//        TempR -> Base = Temp1 -> Base;
//        Cur -> Next = TempR;
//        Cur = Cur -> Next;
//        TempR = TempR -> Next;
//        Temp2 = Temp2 -> Next;
//    }
//    return Result;
//}
//
//void ClearPolynomial(Polynomial p) {
//    if (!p) {
//        return;
//    }
//    Polynomial Cur = p;
//    Polynomial Temp = p -> Next;
//    while (Temp) {
//        free(Cur);
//        Cur = Temp;
//        Temp = Temp -> Next;
//    }
//    free(Cur);
//    p = NULL;
//}
//
//void OutputPolynomial(Polynomial p) {
//    Polynomial Temp = p -> Next;
//    printf("多项式:");
//    if (!Temp) {
//        printf("0");
//    } else {
//        while (Temp) {
//            if (Temp -> Next == NULL) {
//                printf("(%dx^%d)",Temp->Base,Temp->Exponent);
//            } else {
//                printf("(%dx^%d)",Temp->Base, Temp->Exponent);
//            }
//            Temp = Temp->Next;
//        }
//    }
//    return;
//}

typedef struct PolyNode {/*多项式结点*/
    int Base;/*系数*/
    int Exponent;/*指数*/
    struct PolyNode* Next;
}PolyNode;
typedef PolyNode* Polynomial;/*多项式*/

/*新建空多项式
 【规则】
 1、新建的多项式作为先导头，不存储实际数据
 2、新的多项式末接空结点
 【参数】
 无
 【返回值】
 新的多项式
 */
Polynomial CreateEmptyPolyNode() {
    Polynomial P = (Polynomial)malloc(sizeof(PolyNode));
    P->Next = NULL;
    return P;
}

/*读入多项式
 【规则】
 1、多项式刚被新建或为空,不能为野指针
 2、输入用空格分隔，第一个数表示多项式的结点数，随后两两成对输入，它们分别表示系数和指数
 3、先导头不存数据
 【参数】
 P：待处理的多项式
 【返回值】
 无
 */
void ReadPolynomial(Polynomial P) {
    if (P == NULL)
        P = CreateEmptyPolyNode();
    int i, N;
    int Exponent, Base;
    Polynomial Cur = P;
    Polynomial Temp = Cur->Next;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d %d", &Base, &Exponent);
        Temp = CreateEmptyPolyNode();
        Temp->Base = Base;
        Temp->Exponent = Exponent;
        Cur->Next = Temp;
        Cur = Cur->Next;
        Temp = Temp->Next;
    }
}

/*多项式加法
 【规则】
 两个多项式需要已经存在
 【参数】
 P1，P2：待运算的两个多项式
 【返回值】
 结果多项式
 */
Polynomial SumPolynomials(Polynomial P1, Polynomial P2) {
    Polynomial Result = CreateEmptyPolyNode();
    Polynomial Temp1 = P1->Next;
    Polynomial Temp2 = P2->Next;
    Polynomial Cur = Result;
    Polynomial TempR = Result->Next;
    while (Temp1 && Temp2) {
        if (Temp1->Exponent > Temp2->Exponent) {
            TempR = CreateEmptyPolyNode();
            TempR->Exponent = Temp1->Exponent;
            TempR->Base = Temp1->Base;
            Cur->Next = TempR;
            Cur = Cur->Next;
            TempR = TempR->Next;
            Temp1 = Temp1->Next;
        }
        else if (Temp1->Exponent < Temp2->Exponent) {
            TempR = CreateEmptyPolyNode();
            TempR->Exponent = Temp2->Exponent;
            TempR->Base = Temp2->Base;
            Cur->Next = TempR;
            Cur = Cur->Next;
            TempR = TempR->Next;
            Temp2 = Temp2->Next;
        }
        else /*Temp1->Exponent == Temp2->Exponent*/ {
            if (Temp1->Base + Temp2->Base != 0) {
                TempR = CreateEmptyPolyNode();
                TempR->Exponent = Temp2->Exponent;/*或者Temp1->Exponent*/
                TempR->Base = Temp2->Base + Temp1->Base;
                Cur->Next = TempR;
                Cur = Cur->Next;
                TempR = TempR->Next;
            }/*else Temp1->Base + Temp2->Base == 0 跳过上述操作*/
            Temp1 = Temp1->Next;
            Temp2 = Temp2->Next;
        }
    }
    /*Temp1或Temp2有一为空*/
    while (Temp1) {
        TempR = CreateEmptyPolyNode();
        TempR->Exponent = Temp1->Exponent;
        TempR->Base = Temp1->Base;
        Cur->Next = TempR;
        Cur = Cur->Next;
        TempR = TempR->Next;
        Temp1 = Temp1->Next;
    }
    while (Temp2) {
        TempR = CreateEmptyPolyNode();
        TempR->Exponent = Temp2->Exponent;
        TempR->Base = Temp2->Base;
        Cur->Next = TempR;
        Cur = Cur->Next;
        TempR = TempR->Next;
        Temp2 = Temp2->Next;
    }
    return Result;
}
/*清除多项式
 【规则】
 1、释放多项式内存，包括前导头结点
 2、清除成功后，多项式置NULL
 【参数】
 P：待清除多项式
 【返回值】
 无
 */
void ClearPolynomial(Polynomial P) {
    if (!P) return;
    Polynomial Cur = P;
    Polynomial Temp = P->Next;
    while (Temp) {
        free(Cur);
        Cur = Temp;
        Temp = Temp->Next;
    }
    free(Cur);
    P = NULL;
}

/*多项式乘法
 【规则】
 两个多项式需要已经存在
 【参数】
 P1，P2：待运算的两个多项式
 【返回值】
 结果多项式
 */
Polynomial MultiPolynomials(Polynomial P1, Polynomial P2) {
    Polynomial Temp1 = P1->Next, Temp2 = P2->Next;
    Polynomial Result = CreateEmptyPolyNode();
    Polynomial TempResult = CreateEmptyPolyNode();
    Polynomial Cur = TempResult;
    Polynomial TempR = TempResult->Next;
    while (Temp1) {
        while (Temp2) {
            TempR = CreateEmptyPolyNode();
            TempR->Base = Temp1->Base * Temp2->Base;
            TempR->Exponent = Temp2->Exponent + Temp1->Exponent;
            Cur->Next = TempR;
            Cur = Cur->Next;
            TempR = TempR->Next;
            Temp2 = Temp2->Next;
        }
        Result = SumPolynomials(Result, TempResult);
        ClearPolynomial(TempResult);
        /*重置TempResult*/
        TempResult = CreateEmptyPolyNode();
        TempR = TempResult->Next;
        Cur = TempResult;
        Temp1 = Temp1->Next;
        Temp2 = P2->Next;
    }
    return Result;
}



/*输出多项式
 【规则】
 按照指数由大到小输出
 【参数】
 P:带输出多项式
 【返回值】
 无
 */
void OutputPolynomial(Polynomial P) {
    Polynomial Temp = P->Next;
    printf("多项式:");
    if (!Temp) printf("0");
    else {
        while (Temp) {
            if (Temp->Next == NULL)
                printf("(%dx^%d)", Temp->Base, Temp->Exponent);
            else
                printf("(%dx^%d)+", Temp->Base, Temp->Exponent);
            Temp = Temp->Next;
        }
    }
    return;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    Polynomial P1, P2;
    Polynomial ResultAdd;
    P1 = CreateEmptyPolyNode();
    P2 = CreateEmptyPolyNode();
    ResultAdd = CreateEmptyPolyNode();
    ReadPolynomial(P1);
    ReadPolynomial(P2);
    ResultAdd = SumPolynomials(P1, P2);
    OutputPolynomial(ResultAdd);
    ClearPolynomial(P1);
    ClearPolynomial(P2);
    ClearPolynomial(ResultAdd);
    
    return 0;
}
