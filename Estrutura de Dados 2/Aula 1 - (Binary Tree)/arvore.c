#include "arvore.h"


Arvore* cria_arv_vazia (void) {
   return NULL;
}

Arvore* constroi_arv (char c, Arvore *e, Arvore *d) {
   Arvore *no = (Arvore*)malloc(sizeof(Arvore));
   no->info = c;
   no->esq = e;
   no->dir = d;
   return no;
}

int verifica_arv_vazia (Arvore *a) {
   return (a == NULL);
}

void arv_libera (Arvore* a) {
    if (!verifica_arv_vazia(a)) {
      arv_libera (a->esq);
      arv_libera (a->dir);
      free(a);
   }
}

//========= Exercício 2 - pré-ordem ====
void pre_ordem(Arvore* a){
    if(!verifica_arv_vazia(a)){
        printf("%c", a->info);
        pre_ordem(a->esq);
        pre_ordem(a->dir);
    }
}

//========= Exercício 2 - in-ordem ====
void in_ordem(Arvore* a){
    if(!verifica_arv_vazia(a)){
        pre_ordem(a->esq);
        printf("%c", a->info);
        pre_ordem(a->dir);
    }
}

//========= Exercício 2 - pós-ordem ====
void pos_ordem(Arvore* a){
    if(!verifica_arv_vazia(a)){
        pre_ordem(a->esq);
        pre_ordem(a->dir);
        printf("%c", a->info);
    }
}

//========= Exercício 3 - pertence ====
int pertence(Arvore* a, char c){
    if(!verifica_arv_vazia(a)){
        if(a->info == c)
            return 1;
        else
            return(pertence(a->esq, c) || pertence(a->dir, c));
    }
    return (0);
}

//========= Exercício 4 - conta nós ====
int conta_nos (Arvore *a){
    if(!verifica_arv_vazia(a)){
        return(conta_nos(a->esq)+conta_nos(a->dir)+1);
    }
    return 0;
}

//========= Exercício 5 - calcula altura ====
int calcula_altura_arvore (Arvore *a){
    if(!verifica_arv_vazia(a)){
        if(calcula_altura_arvore(a->esq)>=calcula_altura_arvore(a->dir)){
            return(calcula_altura_arvore(a->esq)+1);
        }
        else if(calcula_altura_arvore(a->esq)<calcula_altura_arvore(a->dir)){
            return(calcula_altura_arvore(a->dir)+1);
        }
    }
    return 0;
}


//========= Exercício 6 - conta folhas ====
int conta_nos_folha (Arvore *a){
    if(!verifica_arv_vazia(a->dir) && !verifica_arv_vazia(a->esq)){
        return (conta_nos_folha(a->esq)+conta_nos_folha(a->dir));
    }
    else
        return(1);
    return 0;
}


int main (int argc, char *argv[]) {

    Arvore *a = constroi_arv ('a',
       constroi_arv('b',
       cria_arv_vazia(),
       constroi_arv('d', cria_arv_vazia(),cria_arv_vazia())
     ),
     constroi_arv('c',
       constroi_arv('e',cria_arv_vazia(),cria_arv_vazia()),
       constroi_arv('f',constroi_arv('g', cria_arv_vazia(), cria_arv_vazia()), constroi_arv('h', cria_arv_vazia(), cria_arv_vazia()))
     )
    );	
    pre_ordem(a);
    printf("\n");
    in_ordem(a);
    printf("\n");
    pos_ordem(a);
    printf("\n");
    printf("%d\n", pertence(a,'o'));
    printf("a arvore tem %d nos\n", conta_nos(a));
    printf("a altura da arvore eh %d\n",calcula_altura_arvore (a));
    printf("a arvore tem %d folhas\n", conta_nos_folha(a));
    arv_libera (a);

   return 0;
}
