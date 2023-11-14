/**
 * @file 210801.c
 * @author Tepag (z190tpg@gmail.com)
 * @brief Esercizio 4 pag 338 | Record: 00h 32m 03s
 * @version 0.1
 * @date 2022-01-08
 *
 * @copyright Copyright (c) 2022
 *
 */

/*Traccia:
progetta una struttura per definire le figure geometriche utilizzando la definizione del loro tipo {triangolo, rettangolo, quadrato, crerchio}.
quindi scrivere un programma in grado di calcolare il l'area e il perimetro di tali figure
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI_GRECO 3.14
typedef struct
{
    float h;
    float b;
    float l1;
    float l2;
    float area;
    float perimetro;
} Triangolo;

typedef struct
{
    float l1;
    float l2;
    float area;
    float perimetro;

} Rettangolo;

typedef struct
{
    float lato;
    float area;
    float perimetro;
} Quadrato;

typedef struct
{
    float r;
    float area;
    float perimetro;
} Cerchio;

void Triangolo_calcAreaEPerimetro(Triangolo *);
void Rettangolo_calcAreaEPerimetro(Rettangolo *);
void Quadrato_calcAreaEPerimetro(Quadrato *);
void Cerchio_calcAreaEPerimetro(Cerchio *);

int main()
{
    Triangolo *t1 = (Triangolo *)malloc(sizeof(Triangolo));
    Rettangolo *r1 = (Rettangolo *)malloc(sizeof(Rettangolo));
    Quadrato *q1 = (Quadrato *)malloc(sizeof(Quadrato));
    Cerchio *c1 = (Cerchio *)malloc(sizeof(Cerchio));

    // Triangolo
    t1->b = 3;
    t1->h = 4;
    t1->l1 = 4;
    t1->l2 = 6;
    Triangolo_calcAreaEPerimetro(t1);
    printf("\n%.2f", t1->area);
    printf("\n%.2f", t1->perimetro);

    // rettangolo
    r1->l1 = 2;
    r1->l2 = 3;
    Rettangolo_calcAreaEPerimetro(r1);
    printf("\n%.2f", r1->area);
    printf("\n%.2f", r1->perimetro);

    // quadrato
    q1->lato = 2;
    Quadrato_calcAreaEPerimetro(q1);
    printf("\n%.2f", q1->area);
    printf("\n%.2f", q1->perimetro);

    // cerchio
    c1->r = 2.0;
    Cerchio_calcAreaEPerimetro(c1);

    printf("\n%.2f", c1->area);
    printf("\n%.2f", c1->perimetro);

    return 0;
}

void Triangolo_calcAreaEPerimetro(Triangolo *sp)
{
    sp->area = sp->b * sp->h / 2;
    sp->perimetro = sp->l1 + sp->l2 + sp->b;
}

void Rettangolo_calcAreaEPerimetro(Rettangolo *sp)
{
    sp->area = sp->l1 * sp->l2;
    sp->perimetro = (sp->l2 + sp->l1) * 2;
}

void Quadrato_calcAreaEPerimetro(Quadrato *sp)
{
    sp->area = pow(sp->lato, 2);
    sp->perimetro = sp->lato * 4;
}

void Cerchio_calcAreaEPerimetro(Cerchio *sp)
{
    sp->area = PI_GRECO * pow(sp->r, 2);
    sp->perimetro = PI_GRECO * 2 * sp->r;
}
