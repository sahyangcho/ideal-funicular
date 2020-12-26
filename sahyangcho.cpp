#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <dirent.h>

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#define     MAX_num_nom         64
#define     MAX_num_expression  64
#define     MAX_num_mc          18

#define     MAX_papy_nom        64
#define     MAX_papy_nbe        26


#define    tagc_Noire    0
#define    tagc_GriseF   1
#define    tagc_GriseM   2
#define    tagc_Pink2    3
#define    tagc_Pink3    4
#define    tagc_Pink     5
#define    tagc_Rouge    6
#define    tagc_Bleu     7
#define    tagc_Jaune    8

#define    tagc_Vert     9
/*
#define    tagc_Vert_   10
#define    tagc_Vert_a  11
#define    tagc_Vert_C  12
#define    tagc_Bleu_   13
#define    tagc_Violet  14
#define    tagc_Bleu_a  15
#define    tagc_Noire_  16
*/

#define    tag_electron_    0
#define    tag_muon_        1
#define    tag_tau_         2
#define    tag_W1_          3
#define    tag_X0           4
#define    tag_Z1           5
#define    tag_Minfini      6
#define    tag_top__        7
#define    tag_proton_      8
#define    tag_De_          9
#define    tag_Tr_         10  //
#define    tag_He3__       11  //
#define    tag_He4__       12  //

#define    tag_Pi0         13
#define    tag_Pi_         14
#define    tag_K_          15
#define    tag_K0          16
#define    tag_alpha_inv   17
#define    tag_H           18
#define    tag_Neutron     19
#define    tag_up__        20
#define    tag_down__      21
#define    tag_strange__   22
#define    tag_charm__     23
#define    tag_beauty__    24
#define    tag_Delta_H_pe  25

//#define tag_k20k12         26

//
/*int scene[8][13]={
                { 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                { 1, 2, 1, 1, 2, 2, 2, 1, 1, 2, 1, 1, 1},
                { 2, 2, 2, 1, 2, 2, 2, 1, 1, 2, 2, 1, 1},
                { 1, 2, 2, 4, 2, 2, 2, 1, 1, 1, 2, 1, 1},
                { 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
                { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1},
                { 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1},
                { 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1}
              };*/
//char *scene ;
int scene[45][35]=
{
{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
{ 1, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 3, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
{ 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 2, 2, 1 },
{ 1, 2, 2, 2, 1, 2, 4, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 1, 2, 2, 2, 2, 2, 1 },
{ 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1 },
{ 1, 2, 1, 3, 2, 2, 1, 2, 1, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 1, 2, 1, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 1 },
{ 1, 2, 1, 2, 2, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1 },
{ 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 2, 1, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 1 },
{ 1, 1, 1, 2, 2, 2, 1, 2, 1, 1, 1, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1 },
{ 1, 2, 2, 2, 2, 2, 1, 2, 1, 2, 2, 2, 2, 2, 1, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 1, 2, 2, 2, 1 },
{ 1, 2, 1, 1, 2, 4, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 6, 4, 2, 1 },
{ 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 2, 2, 1, 6, 4, 2, 1 },
{ 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 6, 1, 3, 1 },
{ 1, 2, 2, 4, 2, 1, 2, 2, 2, 4, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 6, 1, 3, 1 },
{ 1, 2, 1, 1, 1, 2, 2, 1, 1, 4, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 6, 1, 1, 1 },
{ 1, 2, 1, 2, 2,11, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 2, 2, 1 },
{ 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 2, 1, 2, 1 },
{ 1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 1, 2, 1, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 1, 2, 2, 2, 1, 2, 1, 2, 2, 2, 1 },
{ 1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1 },
{ 1, 2, 1, 2, 1, 2, 2, 2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 1, 2, 1 },
{ 1, 2, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 2, 1 },
{ 1, 2, 1, 2, 1, 2, 1, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 1, 2, 1 },
{ 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1 },
{ 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 2, 2, 1, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1 },
{ 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1 },
{ 1, 2, 1, 2, 2, 2, 1, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 1, 2, 1, 2, 1 },
{ 1, 2, 1, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 2, 1 },
{ 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1 },
{ 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1 },
{ 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1 },
{ 1, 2, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 2, 1 },
{ 1, 2, 1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 1 },
{ 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1 },
{ 1, 2, 1, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 2, 1 },
{ 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1 },
{ 1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 1, 2, 1 },
{ 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1 },
{ 1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 1 },
{ 1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 1 },
{ 1, 2, 1, 2, 2, 2, 2, 2, 1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1 },
{ 1, 2, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1 },
{ 1, 2, 2, 2, 2, 2, 1, 2, 1, 2, 1, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1 },
{ 1, 2, 1, 1, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1 },
{ 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1 },
{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

#define    tag_truc          11
#define    tag_xtruc         27
#define    tag_ytruc         35


double alg_expr_cst_minuscule[26] = {0} ; // 'a' = [0] , ...
double alg_expr_cst_majuscule[26] = {0} ; // 'A' = [0] , ...


/*
typedef struct
    {
        char nom[MAX_num_nom];
        int tag_img ;
        int x_img;
        int y_img;
        int effet ;
    } laby ;
laby tuiles[18];
//tuiles[0].nom[0] = 'V' ;
tuiles[0].x_img = 14 ;
tuiles[0].y_img = 21 ;

tuiles[1].nom[0] = 'M' ;
tuiles[1].x_img = 21 ;
tuiles[1].y_img = 2 ;
tuiles[2].effet = -1 ; // bloquant

tuiles[2].nom[0] = 'C' ;
tuiles[2].x_img = 44 ;
tuiles[2].y_img = 4 ;
tuiles[2].effet = 0 ; // chemin

tuiles[11].nom[0] = 'W' ;
tuiles[11].x_img = 27 ;
tuiles[11].y_img = 41 ;
tuiles[11].effet = 2^24 ; // W.tau*(k12/k20)^25=Mp
//De*phi^2*((jdz/lv)^3*10^(1/2))^9=Mp
// W.tau = De.phi^2.(jdz/lv)^2*10^4*10^(1/2)
// tau = ((jdz/lv)^6-1)/10*5/27 */
#define    tag_mur           1
#define    tag_xmur         21
#define    tag_ymur         2

#define    tag_sol           2
#define    tag_xsol         44
#define    tag_ysol         4

#define    tag_sol2          6
#define    tag_xsol2         47
#define    tag_ysol2         4

#define    tag_hero          12
#define    tag_xh            17
int add_tag_hero_xh = 0 ;
#define    tag_yh            64
int add_tag_hero_yh = 0 ;

#define    tag_hero_          11
#define    tag_xh_            17
int add_tag_hero_xh_ = 0 ;
#define    tag_yh_            59
int add_tag_hero_yh_ = 0 ;


#define    tag_potion            3
#define    tag_x_potion          1
#define    tag_y_potion          42

int xh = 31 ;
int yh = 10 ;

double vxh = 0 ;
double vyh = 0 ;

double axh = 0 ;
double ayh = 0 ;

double lxh = 31.0 ;
double lyh = 10.0 ;



//int xh_ = 5 ;
//int yh_ = 3 ;

int xh_ = 5 ;
int yh_ = 3 ;
//scene[ xh ][ yh ] = tag_hero ;
int dsx = 0 ;
int dsy = 0 ;

typedef struct  {
        char nom[MAX_num_nom];
        double m;
        double z ;
        double p;
        double c[MAX_num_mc] ;
        char t[MAX_num_mc] ;
        char *txt[MAX_num_mc] ;

        //char* expression;
        int choix ;
        // = -1 ou si c est vide ---  z
        // = 0, 1, ... , Max_num_mc-1. c[choix]
//        void *other ;
//        void *same ;
                } num ;

struct  init
        {
//            char tag; // &1=affiché &2=visible &4=infravisible
            int x;
            int y;
            int c;//=1; //couleur
            int p;
            int dxu;
            int dyu;
            int dxc;
            int dyc;
            int tag;
        };

typedef struct {
        char nom[MAX_papy_nom];
        num mev ;
        num mu ;
        num me ;
//        num mplk ;
//        num mm;
//        void *n;
        struct init affichage;
                } papy;


//////////////////////////:

double alg_exp( double nombre , int exposant )
{
    double resultat = 1 ;
    if ( exposant > 0 )
    {
        while( exposant )
        {
        resultat*= nombre ;
        exposant-- ;
        }
    }
    else
    {
        while( exposant )
        {
        resultat/= nombre ;
        exposant++ ;
        }
    }
    return( resultat ) ;
}

int alg_q_entier( char *alg_exp )
{
    if( !( alg_exp[0] > '0' -1 && alg_exp[0] < '9' + 1 ) )
        return(0) ;
    while( alg_exp[0] > '0' -1 && alg_exp[0] < '9' + 1 )
        alg_exp++ ;
    if( alg_exp[0] == '.' || alg_exp[0]==',' )
        return(0) ;
    else return(1) ;

}

//char expr_i_alg_eval[ 1024 ] ;
double alg_eva_m( char *expr );


double alg_eva( char *expr )
{
    double resultat = 0 ;
    //expr[0]=0;
    if ( expr[0] == 0 )
        return(0) ;
 //return(1);
    char expr_store[128] ;
    char *p_expr ;
    p_expr = expr ;
    int ident_i = 0 ;
    int parenthese = 0 ;

    while( expr[ident_i] != 0 && ident_i < 128 )
    {
        expr_store[ident_i] = expr[ident_i] ;
        ident_i++;
    }
//    return(0) ;

    while(p_expr[0] != 0 ) // on va à la fin de la chaine
        p_expr++ ;


//    p_expr-- ;
//    ident_i-- ;
    /*
    while( ( p_expr[1] != '+' || p_expr[1] == '+' && (( p_expr[0] == '*' || p_expr[0] == '^' || p_expr[0] == '/' )))
        ||  ( p_expr[1] != '-' || p_expr[1] == '-' && (( p_expr[0] == '*' || p_expr[0] == '^' || p_expr[0] == '/' )))
        && p_expr != expr + 1 ) // on recule tant qu'il n'y a pas d'addition
    */
//    while ( p_expr[1] != '+' && ( p_expr[0] != '+' || p_expr[0] != '-' || p_expr[0] != '*'  || p_expr[0] != '/'|| p_expr[0] != '^' ) && p_expr != expr )

    while ( p_expr != expr && (p_expr[1] != '+' || ( p_expr[1] == '+' && (p_expr[0] == '-'|| p_expr[0] == '*'  || p_expr[0] == '/'|| p_expr[0] == '^') ))
             && (p_expr[1] != '-' || ( p_expr[1] == '-' && (p_expr[0] == '+'|| p_expr[0] == '*'  || p_expr[0] == '/'|| p_expr[0] == '^') ))
            )
    {
        if( p_expr[0] == ')' )
        {
            parenthese++;
            while( parenthese && p_expr != expr )
            {
                p_expr-- ;
                ident_i-- ;
                if( p_expr[0] == ')' )
                    parenthese++ ;
                if( p_expr[0] == '(' )
                    parenthese-- ;
            }
            if( p_expr != expr )
            {
                p_expr-- ;
                ident_i-- ;
            }
        }
        else
         {
            p_expr-- ;
            ident_i-- ;
        }
    }
    if( p_expr[1] == '+' || p_expr[1] == '-' )
    {
        p_expr++;
        expr_store[ident_i+1] = 0 ;
        return( alg_eva( expr_store ) + alg_eva_m( p_expr ) );
    }
    else
    {
    return( alg_eva_m( p_expr ) );
    }
/*    if ( cex == '(' )
    {
        while(cex != ')' || cex != 0 )
        {
            p_expr++ ;
            cex = p_expr[0] ;
        }
     }*/
}

double alg_eva_m( char *expr )
{
    double      resultat         = 1 ;
    double      valeur_lambda_   = 1 ;
    double      valeur_lambda_f  = 1 ;
    double      valeur_exposant  = 1 ;
    int         exposant_inverse = 0 ;
    int         alg_tag_inverse  = 0 ;
    int         signe            = 1 ;

//    int lg_expr = strlen(expr) ;
    char cex = expr[ 0 ] ;
    if( cex == 0 )
        return( 1 ) ;

    if( cex == '/' )
    {
        alg_tag_inverse = 1 ;
        expr++ ;
        cex = expr[0] ;
    }

    if( cex == '(' )
    {
        char alg_eva_expr_parenthese[128] ;
        int parenthese = 1 ;
        int ident = 0 ;
        expr++ ;
        cex = expr[0] ;
        while( parenthese && cex != 0 )
        {
            alg_eva_expr_parenthese[ident] = expr[0] ;
            expr++ ;
            ident++;
            if( expr[0] == ')' )
                parenthese-- ;
            if( expr[0] == '(' )
                parenthese++ ;
            cex = expr[0] ;
        }


        alg_eva_expr_parenthese[ident] = 0 ;
        if( alg_tag_inverse == 1 )
        {
            //resultat = alg_eva( alg_eva_expr_parenthese )  ;
            valeur_lambda_f = alg_eva( alg_eva_expr_parenthese )  ;
            //alg_tag_inverse = 0 ;
        }
        else
            //resultat = alg_eva( alg_eva_expr_parenthese )  ;
            valeur_lambda_f = alg_eva( alg_eva_expr_parenthese )  ;


    }

//    while( cex != 0 )

    if( (cex > '0' -1 && cex < '9' + 1) || ( cex == '-' && (expr[1] > '0' -1 && expr[1] < '9' + 1)) || ( cex == '+'&& (expr[1] > '0' -1 && expr[1] < '9' + 1) ))//            if( alg_q_entier(expr) )
        {
            sscanf( expr,"%lf", &valeur_lambda_f ) ;
            if ( cex == '-' || cex == '+' )
                expr++ ;
//                while( (expr[0] > '0' -1 && expr[0] < '9' + 1) || expr[0] == '.' )
            while( (expr[0] > '0' -1 && expr[0] < '9' + 1) || expr[0] == '.' || expr[0] == 'e' || expr[0] == 'E' )
                expr++;
            expr--;
        }
    if ( cex == '-' )
        signe = -1 ;
    if ( cex == '+' )
        signe = +1 ;

    if ( (cex == '-' && ( expr[1] > 'a' -1 && expr[1] < 'z' + 1 && ( expr[1] !='e' || expr[1] != 'E' ) )) || (cex == '+') && ( expr[1] > 'a' -1 && expr[1] < 'z' + 1 && ( expr[1] !='e' || expr[1] != 'E' ) ))
    {
        expr++ ;
        cex = expr[0] ;
    }
    if( cex > 'a' -1 && cex < 'z' + 1 && ( cex!='e'||cex!='E' ) )  // e et E sont exclues des constantes puisqu'elles représentent pour scanf l'exposant
        valeur_lambda_f = signe*alg_expr_cst_minuscule[ cex  - 'a'] ;
    if( cex > 'A' -1 && cex < 'Z' + 1 )
        valeur_lambda_f = signe*alg_expr_cst_majuscule[ cex  - 'A'] ;

    valeur_lambda_ = valeur_lambda_f  ;
//        valeur_lambda_ *= valeur_lambda_i ;

    expr++ ;
    cex = expr[ 0 ];

    if( cex == '^'  )
    {
        expr++ ;
        cex = expr[ 0 ] ;
        if( cex == '/'  )
        {
            expr++ ;
            exposant_inverse = 1;
//              valeur_lambda_ = sqrt( valeur_lambda_ ) ;
//                expr++ ;
        }
        //else
        {

            sscanf( expr,"%lf", &valeur_exposant ) ;
//                while( (expr[0] > '0' -1 && expr[0] < '9' + 1) || expr[0]='.' )
            while( (expr[0] > '0' -1 && expr[0] < '9' + 1) || expr[0] == '.' || expr[0] == 'e' || expr[0] == 'E' )
                expr++ ;
//                valeur_lambda_ = alg_exp( valeur_lambda_, valeur_exposant ) ;
        if(exposant_inverse==1 )
            valeur_lambda_ = pow( valeur_lambda_, 1/valeur_exposant ) ;
        else
            valeur_lambda_ = pow( valeur_lambda_, valeur_exposant ) ;
        }
    }
    resultat *= valeur_lambda_ ;


    if( ( expr[0] == '/' && alg_tag_inverse == 0 ) || ( expr[0] == '*' && alg_tag_inverse == 1 ) )
    {

        if( expr[1] != 0 )
        {
            if( (expr)[0] == '*' )
                expr++ ;
            return( resultat / alg_eva_m( expr ) ) ;
        }
        else
            return( resultat ) ;
    }

    if( expr[0] == '*' )
        expr++ ;
 /*   if( expr[0] == '+' )
    {
        expr++ ;
        return( resultat + alg_eva( expr ) ) ;
    }
    if( expr[0] == '-' )
    {
        return( resultat + alg_eva( expr ) ) ;
    }
*/

    if( expr[0] != 0 )
        return( resultat * alg_eva_m( expr ) ) ;
    else
        return( resultat ) ;

}

// thank you i get this
void SDL_PutPixel32(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
    Uint8 *p;
    if (x<0 || y<0 || x>surface->w-1 || y>surface->h-1)
        return;
    p = (Uint8*)surface->pixels + y * surface->pitch + x * 4;
    *(Uint32*)p = pixel;
}

void Line(SDL_Surface* surf,int x1,int y1, int x2,int y2,Uint32 couleur)  // Bresenham
{
    int x,y;
    int Dx,Dy;
    int xincr,yincr;
    int erreur;
    int i;
    Dx = abs(x2-x1);
    Dy = abs(y2-y1);
    if(x1<x2)
        xincr = 1;
    else
        xincr = -1;
    if(y1<y2)
        yincr = 1;
    else
        yincr = -1;
    x = x1;
    y = y1;
    if(Dx>Dy)
    {
        erreur = Dx/2;
        for(i=0;i<Dx;i++)
        {
            x += xincr;
            erreur += Dy;
            if(erreur>Dx)
            {
                erreur -= Dx;
                y += yincr;
            }
            SDL_PutPixel32(surf,x, y,couleur);
        }
    }
    else
    {
        erreur = Dy/2;
        for(i=0;i<Dy;i++)
        {
            y += yincr;
            erreur += Dx;
            if(erreur>Dy)
            {
                erreur -= Dy;
                x += xincr;
            }
            SDL_PutPixel32(surf,x, y,couleur);
        }
    }
    SDL_PutPixel32(surf,x1,y1,couleur);
    SDL_PutPixel32(surf,x2,y2,couleur);
}
//
//void DrawPixel(SDL_Surface* Target, Sint16 X, Sint16 Y, Uint16 Color); //Draws the specified color at the specified X and Y on the target surface.
//Uint32 ReadPixel(SDL_Surface* Source, Sint16 X, Sint16 Y); //Returns the color of the specified surface on the specified X and Y coordinates.


/*SDL_Surface *ScaleSurface(SDL_Surface *Surface, Uint16 Width, Uint16 Height)
{
    if(!Surface || !Width || !Height)
        return 0;

    SDL_Surface *_ret = SDL_CreateRGBSurface(Surface->flags, Width, Height, Surface->format->BitsPerPixel,
        Surface->format->Rmask, Surface->format->Gmask, Surface->format->Bmask, Surface->format->Amask);

    double    _stretch_factor_x = (static_cast<double>(Width)  / static_cast<double>(Surface->w)),
        _stretch_factor_y = (static_cast<double>(Height) / static_cast<double>(Surface->h));

    for(Sint32 y = 0; y < Surface->h; y++)
        for(Sint32 x = 0; x < Surface->w; x++)
            for(Sint32 o_y = 0; o_y < _stretch_factor_y; ++o_y)
                for(Sint32 o_x = 0; o_x < _stretch_factor_x; ++o_x)
                    DrawPixel(_ret, static_cast<Sint32>(_stretch_factor_x * x) + o_x,
                        static_cast<Sint32>(_stretch_factor_y * y) + o_y, ReadPixel(Surface, x, y));

    return _ret;
}
*/
int spiral(SDL_Surface* surf,int xs,int ys,int largeurs,int ns, int k,Uint32 couls)
{
    if  ( ns < 0 ) return 0;
    int i;
    for( i = 0 ; i++ < 300 ; i++ )
    {
        SDL_PutPixel32(surf,xs+i/2*cos(2*M_PI*i/128+k/128),ys+i/2*sin(2*M_PI*i/256+k/256),couls);
    }
        return 1;
}
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

int main(int argc, char *argv[])
{

//////////// L O C A L E ////////////////////

//    char *phrase[26];
    char pg0[] = "nist 2020" ;
    char pg1[] = "min" ;
    char pg2[] = "max" ;

    char pg3[] = "rpp 2020" ;
    char pg4[] = "Nature 2020" ;

    char pg___[] = "..." ;

//    char ptxt[]="";

    //char pX[2][ MAX_num_expression ]={"jZ/100","a"};

    //char ppi1[2][ MAX_num_expression ]={"k^9/l^9","a"};

    const double phi = (sqrt(5)+1)/2;
    const double k12 = sqrt(5)*phi*phi*phi*phi/2;
    const double k20 = 5*(1+phi)/6 ;
    double pi = M_PI ;
    int tag_changement_constante = 0 ;
/*
    pi = 3477.44-24-1*206.768283; //( k12 - phi/2  ) / ( k20 ) ;
    pi = 3477.44-phi-phi/sqrt(2)*206.768283; //( k12 - phi/2  ) / ( k20 ) ;

    pi = 1/phi*3477.44-1-sqrt(2)*206.768283; //( k12 - phi/2  ) / ( k20 ) ;
    pi = (3477.34116-18-0*1/phi/phi/phi/phi/phi/phi-206.768283)/sqrt(3); //( k12 - phi/2  ) / ( k20 ) ;
   pi = (3477.44161-18-1.4276/phi/phi/phi/phi/phi/phi-206.768283)/sqrt(3); //( k12 - phi/2  ) / ( k20 ) ;

   pi = M_PI;
*/

// alpha0 = 137.490;

//    double    alpha0 = 1/137.03599908 ;
    double    alpha0 = 1/(alg_exp((k12/k20),3)*sqrt(10)+2.0/3/alg_exp(7,4)/alg_exp((k12/k20),2)) ;  //(kdz/kv)^3*10^(1/2)+2/3*1/7^4*(kv/kdz)^2

//    double tplanck = 5.391247E-44 + 0*0.000060 ;

//    double tpi0  = 8.52e-17 + 0* 0.18 ;  // 25 nm
//    double tkpi0 = alg_exp(2511, 8) ;

//    double tpi1  = 2.6033e-8 + 0* 0.0005 ; // 7,8045 m
  //  double tkpi1 = alg_exp( 3*32, 18) ;   // 25 nm
//  double tkpi1 = alg_exp( 3*32, 1) ;   // 25 nm


//    double tmu   = 0 ; //


    alg_expr_cst_minuscule['a'-'a'] = alpha0 ;  //a = alpha
   // alg_expr_cst_minuscule[1] = 8 ;  //b = beauty //c=charm //d =deuterium i=k20/k12 j=k12/k20 k=k12 l=k20 m=muon n=neutron p=proton q=planck
 //   alg_expr_cst_minuscule[1] = 8 ;  //b = beauty //c=charm //d =deuterium i=k20/k12 j=k12/k20 k=k12 l=k20 m=muon n=neutron p=proton q=planck
//    alg_expr_cst_minuscule[8] = 137  ;  //b = beauty //c=charm //d =deuterium i=k20/k12 j=k12/k20 k=k12 l=k20 m=muon n=neutron p=proton q=planck



    double double_ = 1/7 ;
//    double *doublep=&double_ ;

    int int_= 14 ;
//    int *intp = &int_ ;

    papy mamy[MAX_papy_nbe];

    // fenêtre par défaut
    int mywindx                 =   1242 ; //932;
    int mywindy                 =   765 ; //574;
    int mywindeep               =   32;
    int mywintag                =   SDL_HWSURFACE | SDL_DOUBLEBUF;

    char mytitle[17]            =   "merde à tous !";
//    char mypolicename[17]="Loma.ttf";
    char    mypolicename[1024]  =   "fonts/fonts_app_default/lo.ttf" ;
    int     mypolicesize        =   18 ; // 16
    int     mytinypolicesize    =   14 ; // 12
    int     mysupertinypolicesize    =   11 ; // 12

    char    mycomma             =   ',';


    char    wincomma        =   mycomma ;
    char   *wintitle        =   mytitle ;
    char   *winpolicename   =   mypolicename ;

    int     winpolicesize            =   mypolicesize ;
    int     wintinypolicesize        =   mytinypolicesize ;
    int     winsupertinypolicesize   =   mysupertinypolicesize ;

    int     windx   =   mywindx ;
    int     windy   =   mywindy ;
    int     windeep =   mywindeep ;
    int     wintag  =   mywintag ;


    int spiralk ;

    int id_fonts    =   0 ;
//    int n_fonts     =   1 ;
    int tag_changement_fonts ;

    int click_F1 = 0 ;
    int click_shift_F1 = 0 ;
    int click_F3 = 1 ;
    int click_F10 = 1 ;
    int click_shift_F2 = 0 ;

    int tag_shift_space = 0 ;
    int shift_space = 0 ;

    int tag_chargement = 0 ;
    int tag_sauvegarde = 0 ;


    double val_shift_enter = 0 ;

    int couleur_F1 = 0 ;
    int tag_liste = 0 ;
    int choix_liste = 0 ;
//    int tag_1 = 0 ;
//    int l_unit[] = { tag_Z1, tag_X0, tag_W1_, tag_alpha, tag_Tau_, tag_muon_, tag_electron_, -1, tag_Minfini, tag_k20k12, tag_Proton_, tag_Neutron, tag_De_, tag_He3__, tag_Tr_, tag_He4__  } ;
    int lki = 1 ;
    int lkiunit = 0 ;
    int lkiold = 0 ;


    int i = 0 ;
//    int j = 0 ;
    int k = 0 ;
    int l = 0 ;
    int m = 0 ;
//    int n = 0 ;

    int k_calc = 0 ;

    int goon = 0 ;

    int dxl = 0 ;
    int dyl = 0 ;
    int X = 160 ;
    int Y = 20 ;

/*    int X_stone = 200 ;
    int Y_stone = 200 ;
    double x_stone = 200 ;
    double y_stone = 200 ;
    double dx_stone = 0.4200 ;
    double dy_stone = 0.37 ;
    double xs_stone = 200 ;
    double ys_stone = 200 ;
*/

    int dx = 0 ;
    int dy = 0 ;

    int tag ;

    double cp3    =   cos(pi/3);
    cp3 = k12 / k20 ;
    double sp3    =   sin(pi/3);
    sp3 = sqrt(10) ;

//    const double cp5    =   cos(3*pi/20);   //cos(pi/5);
    const double cp5    =   cos(2*pi/45);   //cos(pi/5);
  //  const double sp5    =   sin(3*pi/20);  //sin(pi/5);
    const double sp5    =   sin(2*pi/45);  //sin(pi/5);

    const double r2 =   2;
    const double r3 =   3;
    const double r5 =   5;

    double lk = 1 ;
    double lk_add = 0 ;
//    double lk_mul = 1 ;
//    double lk_exp = 1 ;


    double lkunit = 1 ;
    double lkphi = 1 ;
    double lkpi = 1 ;
    double lk12 = 1 ;
    double lk20 = 1 ;
    double lkalpha0 = 1 ;
    double lkcp3 = 1 ;
    double lkcp5 = 1 ;
    double lksp3 = 1 ;
    double lksp5 = 1 ;
    double lkr2 = 1 ;
    double lkr3 = 1 ;
    double lkr5 = 1 ;
    double dbtag = 1 ;


//    char lkn[nbe][48]={"unit","%phi","%pi","k_12","k_20","%alpha_0","cos_%pi/3","sin_%pi/3","cos_%pi/5","sin_%pi/5","2","3","5","k_14","m_14"};
    double* lkp[]={&lk,&lkphi,&lkpi,&lk12,&lk20,&lkalpha0,&lkcp3,&lksp3,&lkcp5,&lksp5,&lkr2,&lkr3,&lkr5,&dbtag} ;
    double lkv[]={lk,phi,pi,k12,k20,alpha0,cp3, sp3, cp5, sp5,r2,r3,r5,-1} ;

//    lk=pow(*doublep,(double) compt_pwr[k]/compt_sqr[l]
//    lk*=pow(lkv[1],compt_pwr[1]/compt_sqr[1]);
    int* compt ;
    int compt_pwr[] =   {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ;
    int compt_sqr[] =   {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} ;
    compt   =   compt_pwr ;
    int taginverse = 0 ;
//    int tagsqr = 1 ;
//    int tg_transfert = 0 ;
//    int aff_init[]={1,2,3,0,4,5, 7,8,9,10,11,12,13,14,-1};
//    int aff_init[] = {1,2,17,12,11,10,9,8,7,3,4,5,13,14,15,16,6,20,21,22,23,24,-1} ;
    int aff_init[] = {1,2,17,12,11,10,9,8,7,3,4,5,18,25,19,13,14,15,16,6,20,21,22,23,24,-1} ;

    int aff_liste[] = {5,4,3,99,2,1,0,99,6,8,19, 9,10,11,12, 13,14, 15,16, 7,24,23,22,21,20,-1} ;

    int * aff = aff_init ;

//muon : (60^3+20^3-9)*j^(1/5)/*phi^12
/*    char name[26][64]={"electron_", "muon_", "tau_", "W1_", "X0","Z0","Minfini", "_top__",
                    "proton_", "_De+__", "__Tr+_", "__He3++_", "_He4++__",
                    "pion0", "pion1_", "K1_", "K0",
                     "alpha inv_", "H", "neutron", "up", "dw", "st", "ch", "bt", "alpha" } ;*/
    char name[MAX_papy_nbe][64]={"electron_", "muon_", "tau_", "W1_", "X0","Z1","Minfini", "__top_",
                    "_proton", "_De+", "_Tr+_", "__He3++", "__He4++",
                    "pion0", "_pion+", "_K+", "K0",
                     "alpha inv", "H", "neutron", "__up_", "_down__", "_strange__", "__charm_", "_beauty__", "H-p-e" } ;
    const double Mev____= 0.51099895 ;
    const double u____= 0.00054857990907 ;//
    double unite____ = 1 ;


//    char abrev[26*3]={"emtwgzitpdefhp0p1k1k0jHnudscba"};
//    char name[28][64]={"ele_","muon_","tau_","W1_","Z1","X0","Minfini","_top__","__beauty_","_charm__","__stan_","__down_","_up__","pion0","pion1_","K1_","K0","proton_","H","neutron","De_","De","Tr_","Tr","He3_","He3","He4_","He4"};
    double valeurcentrale_Mev[MAX_papy_nbe]={0.51099895 , 206.768283*0.51099895, 1776.86, 80379, 125100, 91187.6, 1.22089e22, 172760,
        1836.15267343*0.51099895, 3670.48296788*0.51099895, 5496.92153573*0.51099895, 5495.88528007*0.51099895, 7294.29954142*0.51099895,
                134.9768, 139.57031,493.677,497.611,
                 (0*6059509+1*137.035999206+0*(11) +0/137.035999085)*0.51099895, 1837.15264705656*0.51099895, 1838.68366173*0.51099895, 2.16, 4.67, 92.1, 1273.0, 4180.0, (1837.15264705656-1836.15267343-1)*0.51099895 } ;
   // double valeurcentrale_u[28]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} ;
   // double valeurcentrale_e[28]={1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} ;
    double erreurmin_Mev[MAX_papy_nbe]={0, 0.0000046*0.51099895, 0.12, 12, 140, 2.1, 0.000012e22, 300,
        0.000000016,  0.00000013*0.51099895, 0.00000027*0.51099895, 0.00000024*0.51099895 ,0.00000024*0.51099895,
         0.0005*0.51099895,0.00024*0.51099895, 0.016*0.51099895 ,0.013*0.51099895,

          (0.00000014)*0.51099895, 1.8229e-7, 0.00000089*0.51099895, 0.26, 0.17, 5, 20, 20, (1.8229e-7+0.000000016)*0.51099895 } ;
    //double erreurmin_u[28]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} ;
    //double erreurmin_e[28]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} ;
    double erreurmax_Mev[MAX_papy_nbe]={0, 0.0000046*0.51099895, 0.12, 12, 140, 2.1, 0.000012e22, 300,
     0.000000016, 0.00000013*0.51099895, 0.00000027*0.51099895, 0.00000024*0.51099895, 0.00000024*0.51099895,
      0.0005*0.51099895, 0.00024*0.51099895, 0.016*0.51099895,0.013*0.51099895,
      (0.00000001)*0.51099895, 1.8229e-7, 0.00000089*0.51099895, 0.49, 0.48, 11, 20, 30, (1.8229e-7+0.000000016)*0.51099895 } ;
    //double erreurmax_u[28]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} ;
    //double erreurmax_e[28]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} ;
    int couleur_element[MAX_papy_nbe]={tagc_Jaune, tagc_Jaune, tagc_Jaune, tagc_Jaune, tagc_Vert, tagc_Vert, tagc_Pink, tagc_Bleu,
    tagc_Pink, tagc_Pink, tagc_Pink, tagc_Pink, tagc_Pink,
     tagc_Vert, tagc_Jaune, tagc_Jaune, tagc_Vert,
     tagc_Rouge, tagc_Vert, tagc_Vert, tagc_Bleu, tagc_Bleu, tagc_Bleu, tagc_Bleu, tagc_Bleu, tagc_Jaune} ;



//char pX[2][ MAX_num_expression ]={"jZ/100","a"};

    //électron

    mamy[tag_electron_].nom[0]=name[tag_electron_][0];
    while(name[tag_electron_][i++]!=0)
        mamy[tag_electron_].nom[i]=name[tag_electron_][i];
    mamy[tag_electron_].nom[i]=0;
/*
    mamy[tag_electron_].mev.m=0.51099895;
    mamy[tag_electron_].mev.z=0.51099895;
    mamy[tag_electron_].mev.p=0.51099895;
*/

    mamy[tag_electron_].mu.m = 0.00054857990907 ;
    mamy[tag_electron_].mu.z = 0.00054857990907 ;
    mamy[tag_electron_].mu.p = 0.00054857990907 ;

    mamy[tag_electron_].me.m = 1 ;
    mamy[tag_electron_].me.p = 1 ;
    mamy[tag_electron_].me.z = 1 ;
    mamy[tag_electron_].me.c[0] = 0 ;
    mamy[tag_electron_].me.c[1] = mamy[tag_electron_].me.z ;
    mamy[tag_electron_].me.c[2] = mamy[tag_electron_].me.m ;
    mamy[tag_electron_].me.c[3] = mamy[tag_electron_].me.p ;

    mamy[tag_electron_].me.choix = 0 ;

/*
    mamy[tag_electron_].mev.m=0.51099895*(13*13*k12+1/k12);
    mamy[tag_electron_].mev.z=0.51099895*(13*13*k12+1/k12);
    mamy[tag_electron_].mev.p=0.51099895*(13*13*k12+1/k12);

   mamy[tag_electron_].me.m=(13*13*k12+1/k12);
    mamy[tag_electron_].me.z=(13*13*k12+1/k12);
    mamy[tag_electron_].me.p=(13*13*k12+1/k12);
*/

    //muon
 /*   i=0;
    mamy[tag_muon_].nom[0]=name[tag_muon_][0];
    while(name[tag_muon_][i++]!=0)
        mamy[tag_muon_].nom[i]=name[tag_muon_][i];
    mamy[tag_muon_].nom[i]=0;

    mamy[tag_muon_].affichage.c=tagc_Pink2;

    mamy[tag_muon_].mev.m=105.6583745;
    mamy[tag_muon_].mev.z=105.6583745;
    mamy[tag_muon_].mev.p=105.6583745;

    mamy[tag_muon_].mu.m=0.11;
    mamy[tag_muon_].mu.z=0.11;
    mamy[tag_muon_].mu.p=0.11;

    mamy[tag_muon_].me.m = ( 206.7682830 - 0.0000046 ) / mamy[tag_electron_].me.p ;
    mamy[tag_muon_].me.z = 206.768283 / mamy[tag_electron_].me.z ;
    mamy[tag_muon_].me.p = ( 206.768283 + 0.0000046 ) / mamy[tag_electron_].me.m ;
*/
//
// muon = 1/w.(jdz/lv)^6/2^(1/2)/10 hbe

// edit match choix user

//    alpha0 = 137.03599908 ;
//    alpha0 = 1/( (k12/k20)*(k12/k20)*(k12/k20)*sqrt(10)+1/((24-1.0/3)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20))) ;
//    alpha0 = 1*( (k12/k20)*(k12/k20)*(k12/k20)*sqrt(10)+phi*phi*phi*k12/(3*3*3*3*3*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*sqrt(10))) ;

//   alpha0 = 1/(alg_exp((k12/k20),3)*sqrt(10)+2.0/3/alg_exp(7,4)/alg_exp((k12/k20),2)) ;
    alpha0 = 1/(alg_exp((k12/k20),3)*sqrt(10)+2.0/3.0/alg_exp(7.0,4)/alg_exp((k12/k20),2)) ;
    alg_expr_cst_minuscule['a'-'a'] = alpha0 ;  //a = alpha

//    alpha0.expression ='(k12/k20)^3*10^(1/2)+phi^3*k12/(3^5*(k12/k20)^6*10^(1/2))

  //    alpha0 = (k12/k20)*(k12/k20)*(k12/k20)*sqrt(10) +phi/(sqrt(2)*3*3*3*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(phi*phi*phi*phi*phi*phi)*k12 ) ;


    mamy[0].me.txt[ 0 ] = pg0 ;
    mamy[0].me.txt[ 1 ] = pg1 ;
    mamy[0].me.txt[ 2 ] = pg2 ;

    mamy[1].me.txt[ 0 ] = pg0 ;
    mamy[1].me.txt[ 1 ] = pg1 ;
    mamy[1].me.txt[ 2 ] = pg2 ;

    mamy[2].me.txt[ 0 ] = pg0 ;
    mamy[2].me.txt[ 1 ] = pg1 ;
    mamy[2].me.txt[ 2 ] = pg2 ;


    for( int_ = 3 ; int_ != MAX_num_mc ; int_++ )
    {
        mamy[0].me.txt[ int_ ] = pg___ ;
        mamy[1].me.txt[ int_ ] = pg___ ;
        mamy[2].me.txt[ int_ ] = pg___ ;

    }

//les autres
    int i_tag = 0 ;
    for( ; i_tag < MAX_papy_nbe ;  i_tag++  )
    {
        i = 0 ;
        mamy[i_tag].nom[0] = name[i_tag][0] ;
        while( name[i_tag][i++] != 0 )
            mamy[i_tag].nom[i] = name[i_tag][i] ;
        mamy[i_tag].nom[i] = 0 ;

        mamy[i_tag].mev.m = valeurcentrale_Mev[i_tag] - erreurmin_Mev[i_tag] ;
        mamy[i_tag].mev.z = valeurcentrale_Mev[i_tag] ;
        mamy[i_tag].mev.p = valeurcentrale_Mev[i_tag] + erreurmax_Mev[i_tag] ;

        mamy[i_tag].me.m = mamy[i_tag].mev.m / mamy[tag_electron_].mev.p ;
        mamy[i_tag].me.z = mamy[i_tag].mev.z / mamy[tag_electron_].mev.z ;
        mamy[i_tag].me.p = mamy[i_tag].mev.p / mamy[tag_electron_].mev.m ;
        mamy[i_tag].affichage.c = couleur_element[i_tag] ;

        mamy[i_tag].me.c[0] = mamy[i_tag].me.z ;
        mamy[i_tag].me.c[1] = mamy[i_tag].me.m ;
        mamy[i_tag].me.c[2] = mamy[i_tag].me.p ;
        mamy[i_tag].me.c[3] = 0 ;
//        mamy[i_tag].me.c[4] = mamy[i_tag].me.z ;
//        mamy[i_tag].me.c[5] = mamy[i_tag].me.m ;
//        mamy[i_tag].me.c[6] = mamy[i_tag].me.p ;


        mamy[i_tag].me.t[0] = '.' ;
        mamy[i_tag].me.t[1] = '>' ;
        mamy[i_tag].me.t[2] = '<' ;
        mamy[i_tag].me.t[3] = 0 ;

        if( i_tag == 17 )
            mamy[i_tag].me.txt[0] = pg4 ;
        else if ( (i_tag > 8 && i_tag < 13) || i_tag == 0 || i_tag == 1 || i_tag == 2 )
            mamy[i_tag].me.txt[0] = pg0 ;
        else
            mamy[i_tag].me.txt[0] = pg3 ;
        mamy[i_tag].me.txt[1] = pg1 ;
        mamy[i_tag].me.txt[2] = pg2 ;

        for( int_ = 3 ; int_ != MAX_num_mc ; int_++ )
            mamy[i_tag].me.txt[ int_ ] = pg___ ;

        mamy[i_tag].me.choix = 0 ;
    }

////////////////////////////////
    //a = alpha
    //d = deuterium
    //f = He3
    //g = Tr3
    //h = He4
    //k = jdz
    //l = lv
    //m = muon
    //t = tau
    //p = proton
    //n = neutron
    //q = (jdz/lv)
    //u = up
    //v = dw
    //s = st
    //c = ch
    //b = bot
    //t = tau
    //T = top
    //X = hbe
    //W = W
    //Z = Z

///////////////////////////////

// relations
/// w=1/100/10^(1/2)/2^(1/2)*(k12/k20)^9/(mu-1/3)*Z
/*//////////////////////////////////////////////////
//
// matière barionique ((W/Z)^2-1)*h^-2
// mc+ec
/////////////////////////////                           */

/*    double mb ;
//    mb = mamy[tag_W1_].me.z / mamy[tag_Z1].me.z  ;
    mb = mb * mb ;
    mb = 1 - mb ;

    double h ;
    h=0.674 ;
    mb*=1/h*1/h/10;
    mb = 1 / mb ;*/
//    mamy[tag_Minfini].me.z = mb ;
  //  pi=(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20) ;
//    printf("mb : %lf",mb ) ;


  //      mamy[tag_Pi_].me.m = ( 5*mamy[tag_Z1].mev.m - 3*mamy[tag_X0].mev.p - 1*mamy[tag_W1_].mev.p ) / mamy[tag_electron_].mev.p ;
    //    mamy[tag_Pi_].me.z = ( 5*mamy[tag_Z1].mev.z - 3*mamy[tag_X0].mev.z - 1*mamy[tag_W1_].mev.z ) / mamy[tag_electron_].mev.z ;
      //  mamy[tag_Pi_].me.p = ( 5*mamy[tag_Z1].mev.p - 3*mamy[tag_X0].mev.m - 1*mamy[tag_W1_].mev.m ) / mamy[tag_electron_].mev.m ;

//        mamy[tag_X0].mev.m = ( mamy[tag_Z1].mev.m*5/3 - mamy[tag_W1_].mev.p/3 ) ; // mamy[tag_electron_].mev.p ;
//***  mamy[tag_X0].mev.z = 320*k12*k12*k12/sp5* mamy[tag_electron_].mev.p ; // mamy[tag_electron_].mev.p ;
 /*       mamy[tag_X0].mev.m = ( mamy[tag_Z1].mev.m*5/3 - mamy[tag_W1_].mev.p/3 ) ; // mamy[tag_electron_].mev.z ;
        mamy[tag_X0].mev.p = ( mamy[tag_Z1].mev.p*5/3 - mamy[tag_W1_].mev.m/3 ) ; // mamy[tag_electron_].mev.m ;
        mamy[tag_X0].me.z = 320*k12*k12*k12/sp5;
        mamy[tag_X0].me.m = mamy[tag_X0].mev.m / mamy[tag_electron_].mev.p ;
        mamy[tag_X0].me.p = mamy[tag_X0].mev.p / mamy[tag_electron_].mev.m ;

        mamy[tag_W1_].mev.z = 432 * k12 * k12 * k12 * cp5 * mamy[tag_electron_].mev.p ; // mamy[tag_electron_].mev.p ;
        mamy[tag_W1_].mev.z = 24 * k12 * k12 * k12 * k12 * k12 * k12 /25*cp5 * mamy[tag_electron_].mev.p ; // mamy[tag_electron_].mev.p ;
      //  mamy[tag_W1_].mev.m = ( mamy[tag_Z1].mev.m*5/3 - mamy[tag_W1_].mev.p/3 ) ; // mamy[tag_electron_].mev.z ;
       // mamy[tag_W1_].mev.p = ( mamy[tag_Z1].mev.p*5/3 - mamy[tag_W1_].mev.m/3 ) ; // mamy[tag_electron_].mev.m ;
        mamy[tag_W1_].me.z = 432*k12*k12*k12*cp5;
        mamy[tag_W1_].me.z = 24 * k12 * k12 * k12 * k12 * k12 * k12 /25*cp5;
        mamy[tag_W1_].me.m = mamy[tag_W1_].mev.m / mamy[tag_electron_].mev.p ;
        mamy[tag_W1_].me.p = mamy[tag_W1_].mev.p / mamy[tag_electron_].mev.m ;*/

//        mamy[tag_Pi_].me.m = ( 5*mamy[tag_Z1].mev.m - 3*mamy[tag_X0].mev.p - 1*mamy[tag_W1_].mev.p ) / mamy[tag_electron_].mev.p ;
   //     mamy[tag_Pi_].me.z = ( 5*mamy[tag_Z1].mev.z - 3*mamy[tag_X0].mev.z - 1*mamy[tag_W1_].mev.z ) / mamy[tag_electron_].mev.z ;
//        mamy[tag_Pi_].me.p = ( 5*mamy[tag_Z1].mev.p - 3*mamy[tag_X0].mev.m - 1*mamy[tag_W1_].mev.m ) / mamy[tag_electron_].mev.m ;



//    unsigned char *t[1024];
  //  char te[1024];

    int x, y ; //,zx,zy;

    char tx[1024*12+48];
//pi    char txgrec[4]={0xc0,0x03,0,0};
    char txgrec[4] = { (char) 0xb1 , (char) 0x03 , 0 , 0 } ; //alpha en unicode
    char txmath[4] = { (char) 0x1a , (char) 0x22 , 0 , 0 } ; //racine carrée en unicode

    char ko3[3*1024] ;
    char ck[1024] ;
    char ligne_vide[17] ;


    char *txp ;
//    char * txp ;
    const char* dossier_sauvegarde = "save/" ;
//    const char* nom_generique_sauvegarde = "choix#" ;
    char chemin_sauvegarde[1024] ;
    k = 0 ;
    while( dossier_sauvegarde[k] != 0 )
    {
        chemin_sauvegarde[k]=dossier_sauvegarde[k] ;
        k++ ;
    }
    const int ident_ds = k ;

///

    tx[1] = 0x03 ; //phi en unicode
    tx[0] = 0xc6 ; //
    tx[2] = 0 ;
    tx[3] = 0 ;
    txp = tx + 4 ;
    sprintf( txp , ": %.12f" , phi ) ;
    txp[3] = wincomma ;
    SDL_Surface *ecran = NULL, *texte = NULL, *fond = NULL, *icon_mf=NULL, *icon_fil=NULL;
    SDL_Rect position;
    SDL_Rect sdl_rect;
//    int Ktime = 0;
    sdl_rect.h = 32 ;
    sdl_rect.w = 32 ;
    sdl_rect.x = 0 ;
    sdl_rect.y = 0 ;


    SDL_Event event;
    TTF_Font *police = NULL;
    TTF_Font *tinypolice = NULL;
    TTF_Font *supertinypolice = NULL;
    SDL_Color couleur[10] = {{5, 5, 5},{30, 30, 30},{160, 160, 160},{210, 130, 130},{200, 104, 182},{255, 124, 182},{220,30,30},{10,64,230},{248, 205, 29},{28, 205, 29}};
    //char NomDesCouleurs[10][64]={"Noir","GriseF","GriseM","Pink2","Pink3","Pink","Rouge","Bleu","Jaune","Vert"};

    SDL_Color mynowcouleur ;

    Uint8 *keystate ;

    int nb_fonts_load = 0 ;
    int nb_choix_load = 0 ;

    int continuer = 1;

    //

    char dossier_fonts_load[]="fonts/fonts_load/";

// icon
//
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetIcon(SDL_LoadBMP("gfx/gfx_app_default/5.m.pomme.bmp"), NULL);
    TTF_Init();
    // load support for the JPG and PNG image formats
    int flags = IMG_INIT_JPG | IMG_INIT_PNG ;
    int initted = IMG_Init( flags ) ;
    if( ( initted & flags ) != flags )
    {
        printf("IMG_Init: Failed to init required jpg and png support!\n");
        printf("IMG_Init: %s\n", IMG_GetError());
        exit(-2) ;
    }

    ecran = SDL_SetVideoMode( windx, windy, windeep, wintag );

    SDL_WM_SetCaption( wintitle, NULL ) ;

    const char* dossier_gfx="gfx/gfx_app_default/";
 //   char* app_gfx[]={"0.0.rectangle d or.bmp","3.m.fil.bmp","4.m.liste.png"};
//    char* app_gfx[]={"0.0.rectangle d or.bmp","9.m.stone_g_b.png","4.m.liste.png","_32_32_umno.png","_32_32_cyanide_gems_globes.png","liste.png","ding.png","ding2.png"};
    const char* app_gfx[]={"0.0.rectangle d or.bmp","9.m.stone_g_b.png","4.m.liste.png","_32_32_umno.png","0.1.rectangle d or.bmp","liste 4.png","ding.png","ding2.png","toute guerre est maudite.png","titre.png","helpshiftF1_fr.png","ki.png"};
    int nbe_g = 12 ;
    SDL_Surface * app_g[ nbe_g ] ;
    char ko2[ 2048 ] ;
    char kotxt[ 2048 ]  ;
    kotxt[0]=0 ;
    kotxt[1]=0 ;

    k = 0 ;
    l = 0 ;
    i = 0 ;
    for( ; l < nbe_g ; l++ )
    {
        k = 0 ;
        while( dossier_gfx[ k ] != 0 )
            ko2[ k++ ] = dossier_gfx[ k ] ;
        i = k ;
        k = 0 ;
        while( app_gfx[ l ][ k ] != 0 )
            ko2[ i + k++ ] = app_gfx[ l ][ k ] ;
        ko2[ i + k ] = 0 ;
        app_g[ l ] = IMG_Load( ko2 ) ;
    }
    fond = app_g[0] ;
    icon_fil = app_g[1] ;
    icon_mf = app_g[2] ;
//

/*typedef struct
{
    char* name;
    void* a;
} listep;

listep p1;
p1.name=NULL;
p1.a=NULL;

listep *p;*/

    DIR * rep = opendir("fonts/fonts_load");
    struct dirent * ent;

    if (rep != NULL)
    {
        i=0;
        k=0;
        l=0;
        while ((ent = readdir(rep)) != NULL)
        {
        if ( ent->d_name[0] != '.' )
            {   i++;
                while( ent->d_name[k] != 0 )
                    k++ ;
                k++ ;
                l+=k ;
                k=0 ;
             //printf("%s\n", ent->d_name);
            }
        }

        closedir(rep);
    }
    //on reserve i pointeurs +l char de memoire <-- contenu du repertoire
    char *cap = (char*) malloc( l ) ;
    char *fonts_loadp[ i ] ;
    nb_fonts_load = i ;

    // puis deuxieme passage on remplit la memoire qu'on vient de reserver avec le nom des fonts en load

    rep=opendir("fonts/fonts_load") ;
    //opendir("fonts/fonts_store/liberation");

    if (rep != NULL && nb_fonts_load != 0 )
    {
        i=0;
        k=0;
        l=0;
        while ((ent = readdir(rep)) != NULL)
        {
            if (ent->d_name[0]!='.')
            {
                fonts_loadp[i]=cap+l;
                i++;
                while(ent->d_name[k]!=0)
                {
                    cap[l+k]=ent->d_name[k];
                    k++;
                }
                l+=k;
                cap[l]=0;
                l++;
                k=0;

                //puis askmem k+1
                //    while(ent->d_name[k]!=0)
              //      cap=ent->d_name[k++];
                //askmem 1

            //printf("%s\n", ent->d_name);
            }
        }
        closedir(rep);
    }


    /* Chargement de la police */
    police = TTF_OpenFont( winpolicename, winpolicesize ) ;
    tinypolice = TTF_OpenFont( winpolicename, wintinypolicesize ) ;
    supertinypolice = TTF_OpenFont( winpolicename, winsupertinypolicesize ) ;
    mynowcouleur = couleur[ tagc_Pink ] ;
    x = 0 ;
    y = 0 ;

///////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////
// chargement liste des choix sauvegardés   //
/////////////////////////////////////////////
    rep = opendir("save");

    if ( rep != NULL )
    {
        i = 0 ;
        k = 0 ;
        l = 0 ;
        while ((ent = readdir(rep)) != NULL)
        {
            if ( ent->d_name[0] != '.' )
            {
                i++;
                while( ent->d_name[k] != 0 )
                    k++ ;
                k++ ;
                l+=k ;
                k=0 ;
             //printf("%s\n", ent->d_name);
            }
        }
        closedir(rep);
    }
    //on reserve i pointeurs +l char de memoire <-- contenu du repertoire
    char *memoire_sauvegarde_choix = (char*) malloc( l ) ;
    char *choix_loadp[ i ] = { 0 } ;
    nb_choix_load = i ;

    // puis deuxieme passage on remplit la memoire qu'on vient de reserver avec le nom des fonts en load

    rep=opendir("save") ;
    //opendir("fonts/fonts_store/liberation");

    if (rep != NULL && nb_choix_load != 0 )
    {
        i=0;
        k=0;
        l=0;
        while ((ent = readdir(rep)) != NULL)
        {
            if (ent->d_name[0]!='.')
            {
                choix_loadp[i] = memoire_sauvegarde_choix + l ;
                i++;
                while(ent->d_name[k]!=0)
                {
                    memoire_sauvegarde_choix[l+k]=ent->d_name[k];
                    k++;
                }
                l+=k;
                memoire_sauvegarde_choix[l]=0;
                l++;
                k=0;

                //puis askmem k+1
                //    while(ent->d_name[k]!=0)
              //      cap=ent->d_name[k++];
                //askmem 1

//            printf("%s\n", ent->d_name);
            }
        }
        closedir(rep);
    }





//////////////////////////////////////////////////////////////////////
    char* aec_min_name[26] = {0} ; // 'a' = [0] , ...
 //   Uint16* aec_min_nameU[26] = {0} ;

    char* aec_maj_name[26] = {0} ; // 'a' = [0] , ...
//    Uint16* aec_maj_nameU[26] = {0} ;

    char aec_min_tag_choix[26] = {0} ; // 'a' = [0] , ...
    char aec_maj_tag_choix[26] = {0} ; // 'a' = [0] , ...

//double alg_expr_cst_majuscule[26] = {0} ; // 'A' = [0] , ...

       // papy * aec_min[26]={0};
       // papy * aec_maj[26]={0};

        alg_expr_cst_minuscule['b' - 'a'] = mamy[ tag_beauty__ ].me.z ;
        aec_min_name['b' - 'a'] = mamy[ tag_beauty__ ].nom ;
       // aec_min['b' - 'a'] = &mamy[ tag_beauty__ ] ;
        aec_min_tag_choix['b' - 'a'] = mamy[ tag_beauty__ ].me.t[mamy[ tag_beauty__ ].me.choix ] ;

        alg_expr_cst_minuscule['c' - 'a'] = mamy[ tag_charm__ ].me.z ;
        aec_min_name['c' - 'a'] = mamy[ tag_charm__ ].nom ;
        aec_min_tag_choix['c' - 'a'] = mamy[ tag_charm__ ].me.t[mamy[ tag_charm__ ].me.choix ] ;

        alg_expr_cst_minuscule['d' - 'a'] = mamy[ tag_De_ ].me.z ;
        aec_min_name['d' - 'a'] = mamy[ tag_De_ ].nom ;
        aec_min_tag_choix['d' - 'a'] = mamy[ tag_De_ ].me.t[mamy[ tag_De_ ].me.choix ] ;

        alg_expr_cst_minuscule['f' - 'a'] = mamy[ tag_Tr_ ].me.z ;
        aec_min_name['f' - 'a'] = mamy[ tag_Tr_ ].nom ;
        aec_min_tag_choix['f' - 'a'] = mamy[ tag_Tr_ ].me.t[mamy[ tag_Tr_ ].me.choix ] ;

        alg_expr_cst_minuscule['g' - 'a'] = mamy[ tag_He3__ ].me.z ;
        aec_min_name['g' - 'a'] = mamy[ tag_He3__ ].nom ;
        aec_min_tag_choix['g' - 'a'] = mamy[ tag_He3__ ].me.t[mamy[ tag_He3__ ].me.choix ] ;

        alg_expr_cst_minuscule['h' - 'a'] = mamy[ tag_He4__ ].me.z ;
        aec_min_name['h' - 'a'] = mamy[ tag_He4__ ].nom ;
        aec_min_tag_choix['h' - 'a'] = mamy[ tag_He4__ ].me.t[mamy[ tag_He4__ ].me.choix ] ;

        alg_expr_cst_minuscule['i' - 'a'] = mamy[ tag_Pi0 ].me.z ;
        aec_min_name['i' - 'a'] = mamy[ tag_Pi0 ].nom ;
        aec_min_tag_choix['i' - 'a'] = mamy[ tag_Pi0 ].me.t[mamy[ tag_Pi0 ].me.choix ] ;

        alg_expr_cst_minuscule['j' - 'a'] = mamy[ tag_Pi_ ].me.z ;
        aec_min_name['j' - 'a'] = mamy[ tag_Pi_ ].nom ;
        aec_min_tag_choix['j' - 'a'] = mamy[ tag_Pi_ ].me.t[mamy[ tag_Pi_ ].me.choix ] ;

        alg_expr_cst_minuscule['k' - 'a'] = k12 ;
        aec_min_name['k' - 'a'] = (char *) "k12 (Vol. D12)" ;

        alg_expr_cst_minuscule['l' - 'a'] = k20 ;
        aec_min_name['l' - 'a'] = (char *) "k20 (Vol. D20)" ;

        alg_expr_cst_minuscule['m' - 'a'] = mamy[ tag_muon_ ].me.z ;
        aec_min_name['m' - 'a'] = mamy[ tag_muon_ ].nom ;
        aec_min_tag_choix['m' - 'a'] = mamy[ tag_muon_ ].me.t[mamy[ tag_muon_ ].me.choix ] ;

        alg_expr_cst_minuscule['n' - 'a'] = mamy[ tag_Neutron ].me.z ;
        aec_min_name['n' - 'a'] = mamy[ tag_Neutron ].nom ;
        aec_min_tag_choix['n' - 'a'] = mamy[ tag_Neutron ].me.t[mamy[ tag_Neutron ].me.choix ] ;

        alg_expr_cst_minuscule['o' - 'a'] = M_PI ;

        alg_expr_cst_minuscule['p' - 'a'] = mamy[ tag_proton_ ].me.z ;
        aec_min_name['p' - 'a'] = mamy[ tag_proton_ ].nom ;
        aec_min_tag_choix['p' - 'a'] = mamy[ tag_proton_ ].me.t[mamy[ tag_proton_ ].me.choix ] ;

        alg_expr_cst_minuscule['q' - 'a'] = k12 / k20 ;
        aec_min_name['q' - 'a'] = (char *) "k12/k20" ;

        alg_expr_cst_minuscule['s' - 'a'] = mamy[ tag_strange__ ].me.z ;
        aec_min_name['s' - 'a'] = mamy[ tag_strange__ ].nom ;
        aec_min_tag_choix['s' - 'a'] = mamy[ tag_strange__ ].me.t[mamy[ tag_strange__ ].me.choix ] ;

        alg_expr_cst_minuscule['t' - 'a'] = mamy[ tag_tau_ ].me.z ;
        aec_min_name['t' - 'a'] = mamy[ tag_tau_ ].nom ;
        aec_min_tag_choix['t' - 'a'] = mamy[ tag_tau_ ].me.t[mamy[ tag_tau_ ].me.choix ] ;

        alg_expr_cst_minuscule['u' - 'a'] = mamy[ tag_up__ ].me.z ;
        aec_min_name['u' - 'a'] = mamy[ tag_up__ ].nom ;
        aec_min_tag_choix['u' - 'a'] = mamy[ tag_up__ ].me.t[mamy[ tag_up__ ].me.choix ] ;

        alg_expr_cst_minuscule['v' - 'a'] = mamy[ tag_down__ ].me.z ;
        aec_min_name['v' - 'a'] = mamy[ tag_down__ ].nom ;
        aec_min_tag_choix['v' - 'a'] = mamy[ tag_down__ ].me.t[mamy[ tag_down__ ].me.choix ] ;


        alg_expr_cst_majuscule['D' - 'A'] = mamy[ tag_H ].me.z - mamy[ tag_proton_ ].me.z - 1  ;
        aec_maj_name['D' - 'A'] = "H-p-e" ;
        aec_maj_tag_choix['D' - 'A'] = mamy[ tag_H ].me.t[mamy[ tag_H ].me.choix ] ;

        alg_expr_cst_majuscule['H' - 'A'] = mamy[ tag_H ].me.z  ;
        aec_maj_name['H' - 'A'] = mamy[ tag_H ].nom ;
        aec_maj_tag_choix['H' - 'A'] = mamy[ tag_H ].me.t[mamy[ tag_H ].me.choix ] ;

        alg_expr_cst_majuscule['K' - 'A'] = mamy[ tag_K0 ].me.z  ;
        aec_maj_name['K' - 'A'] = mamy[ tag_K0 ].nom ;
        aec_maj_tag_choix['K' - 'A'] = mamy[ tag_K0 ].me.t[mamy[ tag_K0 ].me.choix ] ;

        alg_expr_cst_majuscule['L' - 'A'] = mamy[ tag_K_ ].me.z  ;
        aec_maj_name['L' - 'A'] = mamy[ tag_K_ ].nom ;
        aec_maj_tag_choix['L' - 'A'] = mamy[ tag_K_ ].me.t[mamy[ tag_K_ ].me.choix ] ;

        alg_expr_cst_majuscule['M' - 'A'] = mamy[ tag_Minfini ].me.z  ;
        aec_maj_name['M' - 'A'] = mamy[ tag_Minfini ].nom ;
        aec_maj_tag_choix['M' - 'A'] = mamy[ tag_Minfini ].me.t[mamy[ tag_Minfini ].me.choix ] ;

        alg_expr_cst_majuscule['P' - 'A'] = phi ;

        alg_expr_cst_majuscule['T' - 'A'] = mamy[ tag_top__ ].me.z ;
        aec_maj_name['T' - 'A'] = mamy[ tag_top__ ].nom ;
        aec_maj_tag_choix['T' - 'A'] = mamy[ tag_top__ ].me.t[mamy[ tag_top__ ].me.choix ] ;

        alg_expr_cst_majuscule['W' - 'A'] = mamy[ tag_W1_ ].me.z ;
        aec_maj_name['W' - 'A'] = mamy[ tag_W1_ ].nom ;
        aec_maj_tag_choix['W' - 'A'] = mamy[ tag_W1_ ].me.t[mamy[ tag_W1_ ].me.choix ] ;

        alg_expr_cst_majuscule['X' - 'A'] = mamy[ tag_X0 ].me.z ;
        aec_maj_name['X' - 'A'] = mamy[ tag_X0 ].nom ;
        aec_maj_tag_choix['X' - 'A'] = mamy[ tag_X0 ].me.t[mamy[ tag_X0 ].me.choix ] ;

        alg_expr_cst_majuscule['Z' - 'A'] = mamy[ tag_Z1  ].me.z ;
        aec_maj_name['Z' - 'A'] = mamy[ tag_Z1 ].nom ;
        aec_maj_tag_choix['Z' - 'A'] = mamy[ tag_Z1 ].me.t[mamy[ tag_Z1 ].me.choix ] ;


///////////////////////////////////



    ///////////////////////////////////////////////////



//////////////////////
///  electron     ///
////////////////////

        mamy[tag_electron_].me.c[0] = mamy[tag_electron_].me.z ;
        mamy[tag_electron_].me.c[1] = 1 * 0.51099894985/0.51099895 ;
        mamy[tag_electron_].me.c[2] = 1 * 0.51099895015/0.51099895 ;
        mamy[tag_electron_].me.c[3] = 0 ;
//        mamy[i_tag].me.c[4] = mamy[i_tag].me.z ;
//        mamy[i_tag].me.c[5] = mamy[i_tag].me.m ;
//        mamy[i_tag].me.c[6] = mamy[i_tag].me.p ;


        mamy[tag_electron_].me.t[0] = '.' ;
        mamy[tag_electron_].me.t[1] = '>' ;
        mamy[tag_electron_].me.t[2] = '<' ;
        mamy[tag_electron_].me.t[3] = 0 ;


/////////////////
///  muon    ///
///////////////

//    mamy[ tag_Z1 ].me.txt[3] = (char *) eval_txt_Z1[3] ;

//    mamy[ tag_Z1 ].me.c[3] = alg_eva(mamy[tag_Z1].me.txt[3]) ;
//
    mamy[tag_muon_].me.c[0] =    mamy[tag_muon_].me.z ;
    mamy[tag_muon_].me.c[1] =    mamy[tag_muon_].me.m ;
    mamy[tag_muon_].me.c[2] =    mamy[tag_muon_].me.p ;
/*    mamy[tag_muon_].me.c[3] = ( 20.95*pi*pi )/(1-1.0/(144*144*144)) / mamy[tag_electron_].me.z ;
    //(21-1/20)*pi^2/(1-1/144^3)
    mamy[tag_muon_].me.c[4] = ( 27.0*k12-0*k20/16.0  ) / mamy[tag_electron_].me.z ;
    mamy[tag_muon_].me.c[5] = ( 1/alpha0*3/2+1+3.0/14 ) / mamy[tag_electron_].me.z ;
    //3j/2+1+3/14
    mamy[tag_muon_].me.c[6] = ( 1/alpha0*3.0/2 )*(1+25.0/(2*2*2*23*23)) / mamy[tag_electron_].me.z ;
    //3j/2*(1+25/(2*(2*23)^2))
    mamy[tag_muon_].me.c[7] = 0 ;
  //  mamy[tag_muon_].me.c[8] = mamy[tag_muon_].me.z ;
    //codata2019
*/
    mamy[tag_muon_].me.t[0] = '.'  ;
    mamy[tag_muon_].me.t[1] = '>'  ;
    mamy[tag_muon_].me.t[2] = '<'  ;

const char eval_txt_muon_[8][128] = { "centrale", "min", "max", // 0, 1, 2
                                "20.95*o^2/(1-1/144^3)", // 3
                                "27*k", // 4
                                "3/2/a+1+3/14", // 5
                                "3/2/a*(1+25/(2^3*23^2))", // 6
                                0
                                } ;


    mamy[tag_muon_].me.t[3] = 'o'  ;
    mamy[tag_muon_].me.t[4] = 'k'  ;
    mamy[tag_muon_].me.t[5] = 'a'  ;
    mamy[tag_muon_].me.t[6] = 'A'  ;
    mamy[tag_muon_].me.t[7] = 0 ;

    k = 3 ;
    while(mamy[tag_muon_].me.t[k] != 0 )
    {
        mamy[tag_muon_].me.txt[k] = (char*) eval_txt_muon_[k] ;
        mamy[tag_muon_].me.c[k]   = alg_eva( (char*) eval_txt_muon_[k] ) ;
        k++;
    }
    mamy[tag_muon_].me.choix = 0 ;


//////////////////////
///  Méson pi0    ///
////////////////////


    const char eval_txt_pion0[6][128] = { "centrale", "min", "max", // 0, 1, 2
                                "(1-1/512)*q^9/P^6/k/5^/2", // 3
//                                "(1+1/512)*q^9/P^6/k*1/5^/2", // 4
                                0
                                } ;

    mamy[tag_Pi0].me.t[3]=':';
//    mamy[tag_Pi0].me.t[4]=';';
    mamy[tag_Pi0].me.t[4]=0;
    mamy[tag_Pi0].me.choix = 0 ;

    k = 3 ;
    while(mamy[tag_Pi0].me.t[k] != 0 )
    {
        mamy[tag_Pi0].me.txt[k] = (char*) eval_txt_pion0[k] ;
        mamy[tag_Pi0].me.c[k]   = alg_eva( (char*) eval_txt_pion0[k] ) ;
        k++;
    }

//    mamy[tag_Pi0].me.c[3]= (1-1.0/512)*(pow((k12/k20),9)/(pow(phi,6)*k12*sqrt(5))) ;
//  "(1-1/512)*kl^9/(phi^9*k*5^/2)"
//  "1/(1+1/512)*kl^9/(phi^9*k*5^/2)"
//    mamy[tag_Pi0].me.c[4]= (1+1.0/512)*(pow((k12/k20),9)/(pow(phi,6)*k12*sqrt(5))) ;




///////////////////////
///  Boson hbe     ///
/////////////////////


    const char eval_txt_X0[10][128] = { "centrale", "min", "max", // 0, 1, 2
                                "800*o^5", // 3
                                "q^8*a*7*m", // 4
                                "W*m/q^6*10*2^/2", // 5
                                "6*d*10^/2*q", // 6
                                "6*P^2*l/25*Z",
                                "t*(t+m+e)/20/P^2",
                                0
                                } ;

    mamy[tag_X0].me.choix = 0 ;
    mamy[tag_X0].me.t[0] = '.' ;
    mamy[tag_X0].me.t[1] = '>' ;
    mamy[tag_X0].me.t[2] = '<' ;
    mamy[tag_X0].me.t[3] = 'o' ;
    mamy[tag_X0].me.t[4] = 'm' ;
    mamy[tag_X0].me.t[5] = 'W' ;
    mamy[tag_X0].me.t[6] = 'd' ;
    mamy[tag_X0].me.t[7] = 'Z' ;
    mamy[tag_X0].me.t[8] = 'K' ;
    mamy[tag_X0].me.t[9] = 0;
    mamy[tag_X0].me.c[9] = 0 ;

    k = 3 ;
    while(mamy[tag_X0].me.t[k] != 0 )
    {
        mamy[tag_X0].me.txt[k] = (char*) eval_txt_X0[k] ;
        mamy[tag_X0].me.c[k]   = alg_eva( (char*) eval_txt_X0[k] ) ;
        k++;
    }



//    mamy[tag_X0].me.c[7] = phi*phi*24*k20/100*mamy[tag_Z1].me.c[7] ;



//////////////////////////
///  Boson W +/-      ///
////////////////////////

    const char eval_txt_W1_[7][128] = { "centrale", "min", "max", // 0, 1, 2
                                "q^8*a*4.5*m", // 3
                                "q^5/10^/2*4.5*m", // 4
                                "P/l^3/k*10*10^/2*X",
                                0
                                } ;

    mamy[tag_W1_].me.t[0] = '.' ;
    mamy[tag_W1_].me.t[1] = '>' ;
    mamy[tag_W1_].me.t[2] = '<' ;
    mamy[tag_W1_].me.t[3] = 'm' ;
    mamy[tag_W1_].me.t[4] = 'M' ;
    mamy[tag_W1_].me.t[5] = 'X' ;
    mamy[tag_W1_].me.t[6] = 0 ;
    mamy[tag_W1_].me.c[6] = 0 ;
    mamy[tag_W1_].me.choix = 0 ;
    int_ = 3 ;
    while( mamy[tag_W1_].me.t[int_] != 0 )
    {
        mamy[tag_W1_].me.txt[int_] = (char *) eval_txt_W1_[ int_ ] ;
        mamy[tag_W1_].me.c[int_] = alg_eva( mamy[tag_W1_].me.txt[int_] ) ;
        int_++ ;
    }


 /*

    mamy[tag_W1_].me.c[3] = (k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20) * alpha0 * 4.5 * mamy[tag_muon_].me.c[2] ;
//    mamy[tag_W1_].me.c[3] = (k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20) / alpha0 * 4.5 * mamy[tag_muon_].me.c[2] ;
    mamy[tag_W1_].me.c[4] = (k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)/sqrt(10) * 4.5 * mamy[tag_muon_].me.c[2] ;*/


/*
    mamy[tag_W1_].me.c[5] = phi*(k12/k20)*(k12/k20)*(k12/k20)/(k12*k12*k12*k12)*sqrt(10)*10 * mamy[tag_X0].me.c[0] ;
    mamy[tag_W1_].me.c[6] = 0 ;
    mamy[tag_W1_].me.t[5]='X' ;
*/

//////////////////////////
///  Masse de Planck  ///
////////////////////////

    const char eval_txt_Minfini[9][128] = { "centrale", "min", "max", // 0, 1, 2
                                "1295.2*2^64", // 3
                                "d/a^9/P^2", // 4
                                "1/a^12/(p-1/P)", // 5
                                "Wt*q^25", // 6
                                "gm*10^/2*q^29", // 7
                                0
                                } ;

    mamy[tag_Minfini].me.t[0] = '.';
    mamy[tag_Minfini].me.t[1] = '>';
    mamy[tag_Minfini].me.t[2] = '<';
    mamy[tag_Minfini].me.t[3] = '1';
    mamy[tag_Minfini].me.t[4] = 'd';
    mamy[tag_Minfini].me.t[5] = 'p';
    mamy[tag_Minfini].me.t[6] = 'W';
    mamy[tag_Minfini].me.t[7] = '3';
    mamy[tag_Minfini].me.t[8] = 0 ;

    mamy[tag_Minfini].me.c[8] = 0 ;

    k = 3 ;
    while(mamy[tag_Minfini].me.t[k] != 0 )
    {
        mamy[tag_Minfini].me.txt[k] = (char*) eval_txt_Minfini[k] ;
        mamy[tag_Minfini].me.c[k]   = alg_eva( (char*) eval_txt_Minfini[k] ) ;
        k++ ;
    }



// mamy[tag_Minfini].me.c[3]=2.38923751377792E+022;
    mamy[ tag_Minfini ].me.choix = 0 ;

 //   mamy[tag_Minfini].me.z = ( (double) 4096 * 4096 * 4096 * 4096 * 4096 * 16 ) * (( 512 - 343 ) * k12 + 1 / k12 + 0*1/k12/k12)  ;

/////////////////////
///  t a u       ///
///////////////////
    const char eval_txt_tau[5][128] = { "centrale", "min", "max", // 0, 1, 2
                                "X/(1+1/m)*P/l^4/5", // 3
                                0
                                } ;



   mamy[tag_tau_].me.c[3] = 2* (mamy[tag_X0].me.c[7])/(1+1/mamy[tag_muon_].me.c[0])*((1/k20/k20/k20)/10/k20*phi) ;//
   mamy[tag_tau_].me.t[3] ='X' ;
   mamy[tag_tau_].me.c[4] = 0 ;

    k = 3 ;
    while(mamy[tag_tau_].me.t[k] != 0 )
    {
        mamy[tag_tau_].me.txt[k] = (char*) eval_txt_tau[k] ;
        mamy[tag_tau_].me.c[k]   = alg_eva( (char*) eval_txt_tau[k] ) ;
        k++ ;
    }


//    mamy[tag_Tau_].me.z = mamy[tag_muon_].me.z*(1+sqrt(10)/((k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)))*(1+sqrt(10)/((k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)))*mamy[tag_muon_].me.z/((k12/k20)*(k12/k20)) ;//
//    mamy[tag_Tau_].me.z = 1/(1/mamy[tag_muon_].me.z-1.0/60000)*mamy[tag_muon_].me.z/((k12/k20)*(k12/k20)) ;//

/////////////////////
///  Boson Z     ///
///////////////////


    const char eval_txt_Z[7][128] = { "centrale", "min", "max", // 0, 1, 2
                                "P*10^/2*M*(64+1/64)/q^36", // 3
                                "1/a*(-1+m+t)/2/2^/2",
                                "3^4*7*q^4/100*m",

                                0
                                } ;
    mamy[tag_Z1].me.t[3]='M';
    mamy[tag_Z1].me.t[4]='K';
    mamy[tag_Z1].me.t[5]='m';
//    mamy[tag_Pi0].me.t[4]=';';
    mamy[tag_Z1].me.t[6]=0;
    mamy[tag_Z1].me.c[6]=0;
    mamy[tag_Z1].me.choix = 0 ;

    k = 3 ;
    while(mamy[tag_Z1].me.t[k] != 0 )
    {
        mamy[tag_Z1].me.txt[k] = (char*) eval_txt_Z[k] ;
        mamy[tag_Z1].me.c[k]   = alg_eva( (char*) eval_txt_Z[k] ) ;
        k++;
    }
///////////////////////////////////////////////////////////////
//    char eval_txt_Z1_3[ 64 ] = "P*10^/2*M*64.015625/q^36" ;
/*    char eval_txt_Z1_3[ 64 ] = "P*10^/2*M*(64+1/64)/q^36" ;
    mamy[tag_Z1].me.txt[3] = eval_txt_Z1_3 ;
    mamy[tag_Z1].me.c[3] = alg_eva(mamy[tag_Z1].me.txt[3]) ;


/*    mamy[tag_Z1].me.c[3]= phi*sqrt(10)*mamy[tag_Minfini].me.c[4]*(64.0+1/64.0)/((k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)
                          *(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)
                          *(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)
                          *(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20));
*/
//    mamy[tag_Z1].me.t[3] = 'M' ;
//    mamy[tag_Z1].me.tbis[3] = '.' ;
//    mamy[tag_Z1].me.tter[3] = '1' ;

//    mamy[tag_Z1].me.c[4]= 2.5*(10)*mamy[tag_Minfini].me.c[4]/((k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)
  //207,23                        *alpha0*alpha0*alpha0*alpha0*alpha0*alpha0*alpha0*alpha0);
 //   mamy[tag_Z1].me.c[4]= 250.0/100*mamy[tag_Minfini].me.c[2]/(k20*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)
   //                       *alpha0*alpha0*alpha0*alpha0*alpha0*alpha0);
   //(64.0+1/64.0)=64.015625
/*    mamy[tag_Z1].me.c[4]= phi*sqrt(10)*mamy[tag_Minfini].me.c[3]*(64.015625)/((k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)
                          *(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)
                          *(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)
                          *(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20));
    mamy[tag_Z1].me.t[4]=';'; */
    //mamy[tag_Z1].me.c[5]= 250.0/100*mamy[tag_Minfini].me.c[0]/(k20*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)
    //                    *alpha0*alpha0*alpha0*alpha0*alpha0*alpha0);
/*    mamy[tag_Z1].me.c[5]= phi*sqrt(10)*mamy[tag_Minfini].me.c[5]*(64.0+1/64.0)/((k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)
                          *(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)
                          *(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)
                          *(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20));
    mamy[tag_Z1].me.t[5]='/';*/
/*    mamy[tag_Z1].me.c[4]= 250.0/100*mamy[tag_Minfini].me.c[1]/(k20*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)*(k12/k20)
                          *alpha0*alpha0*alpha0*alpha0*alpha0*alpha0);
    mamy[tag_Z1].me.t[4]='.';
    mamy[tag_Z1].me.c[5]=( 1/alpha0 * ( -1.0 + mamy[ tag_muon_ ].me.z + mamy[ tag_tau_ ].me.c[ 2 ]  ) )/2/sqrt(2);
    mamy[tag_Z1].me.t[5]='K';

    mamy[tag_Z1].me.c[ 6 ]=( 1/alpha0 * ( -1.0 + mamy[ tag_muon_ ].me.z + mamy[ tag_tau_ ].me.c[2]  ) )/2/sqrt(2);
    mamy[tag_Z1].me.t[ 6 ]='k';
//    mamy[tag_Z1].me.c[ 7 ] = 0 ;
//3477,4416
//    mamy[tag_Z1].me.z=mamy[tag_Z1].me.c[ 3 ] ;

    char eval_txt_Z1_7[ 128 ] ="3^4*7*q^4/100*m";
//    char eval_txt_Z1_7[ 1024 ] ="3^4*7*k^4*1/l^4/100*m";
//    char eval_txt[ 1024 ] = "3^4*7*207/100";
    mamy[tag_Z1].me.txt[7]= eval_txt_Z1_7 ;
    mamy[tag_Z1].me.c[7] = alg_eva(mamy[tag_Z1].me.txt[7]) ;
    mamy[tag_Z1].me.t[7]='m';

   // mamy[tag_Z1].me.c[8] = 0 ;
    char eval_txt_Z1_8[ 128 ] ="3^4*7/a^2/10^3/q^2*m";
//    char eval_txt_Z1_7[ 1024 ] ="3^4*7*k^4*1/l^4/100*m";
//    char eval_txt[ 1024 ] = "3^4*7*207/100";
    mamy[tag_Z1].me.txt[8]= eval_txt_Z1_8 ;
    mamy[tag_Z1].me.c[8] = alg_eva(mamy[tag_Z1].me.txt[8]) ;
    mamy[tag_Z1].me.t[8]='a';

   char eval_txt_Z1_9[ 128 ] ="3^4*7/a/10^3*q*10^/2*m";
//    char eval_txt_Z1_7[ 1024 ] ="3^4*7*k^4*1/l^4/100*m";
//    char eval_txt[ 1024 ] = "3^4*7*207/100";
    mamy[tag_Z1].me.txt[ 9 ]= eval_txt_Z1_9 ;
    mamy[tag_Z1].me.c[ 9 ] = alg_eva(mamy[tag_Z1].me.txt[ 9 ]) ;
    mamy[tag_Z1].me.t[ 9 ]='q';
    mamy[tag_Z1].me.c[ 10 ] = 0 ;

const char eval_txt_Z1[11][128] = { "centrale", "min", "max", // 0, 1, 2
                                "P*10^/2*M*(64+1/64)/q^36", // 3
                                "", // 4
                                "", // 5
                                "", // 6
                                "", // 7
                                "", // 8
                                "3^4*7/a/10^3*q*10^/2*m", // 9
                                0
                                } ;

    mamy[ tag_Z1 ].me.txt[3] = (char *) eval_txt_Z1[3] ;

    mamy[ tag_Z1 ].me.c[3] = alg_eva(mamy[tag_Z1].me.txt[3]) ;
*/



//    mamy[tag_Z1].me.z=mamy[tag_Z1].me.c[ 3 ] ;

  //  mamy[tag_X0].me.z=mamy[tag_Z1].me.c[ 3 ] ;
//////////////
// X0 = 6*(k12/k20)^7/phi*10e
// Z = X/24/phi/k20*100=X/4/phi/k20*(k12/k20)^7*1000
// X0(7)  = 24*phi^2*k20/100*Z1(3)=phi^6*k12/100*Z
// W1(5)  = phi*10*sqr(10)/(k20^3/k12)*X0(7) =
// Z = 3^4*7*(k12/k20)^3/100 * muon ;
//
// Tau(3) = 2*phi*(X0(7))/(1+1/muon)/(k20^4*10)
// Tau(4) = p*((k12/k20)^3/(phi*10*2^(1/2))
//
//////////////////////////
//    1/(12/20):2 * tau = muon * 1/207
        //tplanck *=(243*243*243*243*243*243*243*243*243*243*243*243);
////////


/*
//    char    ppi1_1[] = "kl^9" ;
//        char    ppi1_1[] = "123" ;
//        char    ppi1_1[] = "48^6" ;
        char    pW1_5[]  = "10*10^/2*P/k/l^3*X" ; // X.7
//        char    pW1_5[]  = "10*10^/2*10^/2*1/5/5" ; // X.7
        char    pX0_7[]  = "p^2*24*l/100*Z" ; // Z.7
//        char    pX0_7[]  = "X/2/2" ; // Z.7


//        double  ipi1_1   = alg_eva( ppi1_1 ) ;

        mamy[tag_X0].me.txt[7] = pX0_7 ;
        mamy[tag_X0].me.c[7] = alg_eva( pX0_7 ) ;

        mamy[tag_X0].me.t[7]='Z';
        mamy[tag_X0].me.c[8] = 0 ;

        alg_expr_cst_majuscule['X' - 'A'] = mamy[ tag_X0 ].me.c[0] ;


        mamy[tag_W1_].me.txt[5] = pW1_5 ;
        mamy[tag_W1_].me.c[5] = alg_eva( pW1_5 ) ;
        mamy[tag_W1_].me.t[5] = 'X' ;
        mamy[tag_W1_].me.c[6] = 0 ;


//        mamy[tag_Pi0].me.txt[3] = ppi1_1 ;

*/
//////////////////////
///  Quark top    ///
////////////////////


    const char eval_txt_top[5][128] = { "centrale", "min", "max", // 0, 1, 2
                                "18/a^2",
                                0
                                } ;

    mamy[tag_top__].me.t[3]='a';
//    mamy[tag_Pi0].me.t[4]=';';
    mamy[tag_top__].me.t[4]=0;
    mamy[tag_top__].me.choix = 0 ;

    k = 3 ;
    while(mamy[tag_top__].me.t[k] != 0 )
    {
        mamy[tag_top__].me.txt[k] = (char*) eval_txt_top[k] ;
        mamy[tag_top__].me.c[k]   = alg_eva( (char*) eval_txt_top[k] ) ;
        k++;
    }
//////////////////////
///  Quark top    ///
////////////////////


    const char eval_txt_beauty[5][128] = { "centrale", "min", "max", // 0, 1, 2
                                "36^3/l/P^2",
                                0
                                } ;

    mamy[tag_beauty__].me.t[3]='l';
//    mamy[tag_Pi0].me.t[4]=';';
    mamy[tag_beauty__].me.t[4]=0;
    mamy[tag_beauty__].me.choix = 0 ;

    k = 3 ;
    while(mamy[tag_beauty__].me.t[k] != 0 )
    {
        mamy[tag_beauty__].me.txt[k] = (char*) eval_txt_beauty[k] ;
        mamy[tag_beauty__].me.c[k]   = alg_eva( (char*) eval_txt_beauty[k] ) ;
        k++;
    }


////////////////////////
///  Quark charm    ///
//////////////////////


    const char eval_txt_charm[5][128] = { "centrale", "min", "max", // 0, 1, 2
                                "18/a", // 30
                                0
                                } ;

    mamy[tag_charm__].me.t[3]='a';
//    mamy[tag_Pi0].me.t[4]=';';
    mamy[tag_charm__].me.t[4]=0;
    mamy[tag_charm__].me.choix = 0 ;

    k = 3 ;
    while(mamy[tag_charm__].me.t[k] != 0 )
    {
        mamy[tag_charm__].me.txt[k] = (char*) eval_txt_charm[k] ;
        mamy[tag_charm__].me.c[k]   = alg_eva( (char*) eval_txt_charm[k] ) ;
        k++ ;
    }


//////////////:
    int nb_sauvegarde = 0 ;
    int numero_sauvegarde = 0 ;

    ///////////////////////////////////////////////////
    while ( continuer )
    {
        if( goon == 0 )
        {
            //if (tag_changement_fonts!=1)
                goon = 1 ;
        }
        else
        {
            SDL_WaitEvent( &event ) ;
            //SDL_PollEvent( &event ) ;
            goon = 0 ;
//        SDL_PollEvent(&event);
            switch( event.type )
            {
                case SDL_KEYDOWN:
                    if(tag_chargement==2)
                    {
                        tag_chargement=0 ;
                        kotxt[0] = 0 ;
                        k_calc = 0 ;
                    }
                    if( tag_sauvegarde == 2 )
                    {
                        tag_sauvegarde = 0 ;
                        kotxt[0] = 0 ;
                        k_calc = 0 ;
                    }
                   // SDL_GetMouseState( &x, &y);
                   // X = x ;
                   // Y = y ;
                   // Line(ecran,0,0,x,y,0xAAAABBAA);
                   click_shift_F1  = 0 ;
                   click_shift_F2 = 0 ;
                   keystate = SDL_GetKeyState( NULL ) ;
                   goon = 1 ;
       /* while(SDL_PollEvent(&event)){
  switch(event.type){
    case SDL_KEYDOWN:
      if(event.key.keysym.sym==SDLK_LEFT)
        move_left();
      break;*/
                    switch( event.key.keysym.sym )
                    {
                        case SDLK_TAB:
                        int lkj;
                        if((tag_liste == 0 && !( keystate[SDLK_LSHIFT] || keystate[SDLK_RSHIFT] )) || (tag_liste == 1 && ( keystate[SDLK_LSHIFT] || keystate[SDLK_RSHIFT] )))
                        {
                            if(tag_liste == 0 && !( keystate[SDLK_LCTRL] || keystate[SDLK_RCTRL] ) )
                            {
                                lkiold = lkiunit ;
                                lkiunit++ ;
                                if( lkiunit > MAX_papy_nbe - 1 )
                                    lkiunit = 0 ;
                                lkj = lkiunit ;//l_unit[ lkiunit ] ;
                                lkunit *= mamy[ lkj ].me.z / mamy[ lkiold ].me.z ;
                                choix_liste = lkiunit ;

                            }
                            if(tag_liste == 0 && ( keystate[SDLK_LCTRL] || keystate[SDLK_RCTRL] ) )
                            {
                                lkiold = lkiunit ;
                                lkiunit-- ;
                                if( lkiunit == - 1 )
                                    lkiunit = MAX_papy_nbe - 1 ;
                                lkj = lkiunit ;//l_unit[ lkiunit ] ;
                                lkunit *= mamy[ lkj ].me.z / mamy[ lkiold ].me.z ;
                                choix_liste = lkiunit ;

                            }
                            if(tag_liste == 1 && !( keystate[SDLK_LCTRL] || keystate[SDLK_RCTRL] ) )
                            {
                               // lkunit/=mamy[ lkiunit ].me.c[ choix_liste ] ;
                                choix_liste++ ;
                                if( choix_liste  > MAX_papy_nbe - 1 )
                                    choix_liste = 0 ;
                                //lkunit*=mamy[ lkiunit ].me.c[ choix_liste ] ;
                            }
                            if(tag_liste == 1 && ( keystate[SDLK_LCTRL] || keystate[SDLK_RCTRL] ) )
                            {
                               // lkunit/=mamy[ lkiunit ].me.c[ choix_liste ] ;
                                choix_liste-- ;
                                if( choix_liste  == - 1 )
                                    choix_liste = MAX_papy_nbe - 1 ;
                                //lkunit*=mamy[ lkiunit ].me.c[ choix_liste ] ;
                            }
                        }
                        if((tag_liste == 1 && !( keystate[SDLK_LSHIFT] || keystate[SDLK_RSHIFT] )) || (tag_liste == 0 && ( keystate[SDLK_LSHIFT] || keystate[SDLK_RSHIFT] )))
                        {

                            lkj = choix_liste ;
                            double_ = mamy[ lkj ].me.z ;
                            if( mamy[ lkj ].me.choix != -1 )
                                mamy[ lkj ].me.choix++;
                            if(mamy[ lkj ].me.c[ mamy[lkj].me.choix ] == 0 )
                                mamy[ lkj ].me.choix=0;
                            mamy[ lkj ].me.z = mamy[ lkj ].me.c[mamy[ lkj ].me.choix] ;
                            if( lkj == lkiunit )
                            {
                                lkunit *= mamy[ lkj ].me.z / double_ ;
                            }
                            tag_changement_constante = 1 ;
                        }

                            break ;

                        case SDLK_SPACE:
                            if ( keystate[SDLK_LSHIFT] || keystate[SDLK_RSHIFT] && !( tag_chargement || tag_sauvegarde ) )
                            {
                                if( tag_shift_space == 0 )
                                {
                                    tag_shift_space = 1 ;
                                    shift_space = choix_liste ;
                                }
                                else
                                {
                                    tag_shift_space = 0 ;
                                    shift_space = 0 ;
                                }
                            }
                            else
                            {
                                if ( !( tag_chargement || tag_sauvegarde ) )
                                    taginverse = !taginverse ;
                            }
                            break ;

                        case SDLK_MINUS:
                            kotxt[k_calc++] = '-' ;
                            kotxt[k_calc] = 0 ;
                            break ;

/*                        case SDLK_COMMA:
                            kotxt[k_calc++] = '.' ;
                            break ;*/

                        case SDLK_PERIOD:
                            kotxt[k_calc++] = '.' ;
                            kotxt[k_calc] = 0 ;
                            break ;

                        case SDLK_BACKSPACE:
                            if( k_calc > 0 )
                                kotxt[ --k_calc ] = 0 ;
                            break;

                        case SDLK_a:
                            kotxt[ k_calc++ ] = 'a' ;
                            kotxt[k_calc] = 0 ;
                            break ;

                        case SDLK_b:
                            kotxt[ k_calc++ ] = 'b' ;
                            kotxt[k_calc] = 0 ;
                            break ;

                        case SDLK_c:
                            kotxt[ k_calc++ ] = 'c' ;
                            kotxt[k_calc] = 0 ;
                            break ;

                        case SDLK_d:
                            if ( keystate[SDLK_LSHIFT] || keystate[SDLK_RSHIFT] && !( tag_chargement || tag_sauvegarde ) )
                            {
                                kotxt[ k_calc++ ] = 'D' ;
                                kotxt[k_calc] = 0 ;
                            }
                        else
                            {
                                kotxt[ k_calc++ ] = 'd' ;
                                kotxt[k_calc] = 0 ;
                            }
                        break ;

                        case SDLK_e:
                            kotxt[ k_calc++ ] = 'e' ;
                            kotxt[k_calc] = 0 ;
                            break ;


                        case SDLK_f:
                            if ( keystate[SDLK_LCTRL] || keystate[SDLK_RCTRL] || keystate[SDLK_LSHIFT] || keystate[SDLK_RSHIFT] )
                            {
                                tag_changement_fonts=1;
                                id_fonts++;
                                if( id_fonts > nb_fonts_load - 1 )
                                    id_fonts = 0 ;
                                goon = 0 ;
                            }
                            else
                            {
                                kotxt[ k_calc++ ] = 'f' ;
                                kotxt[k_calc] = 0 ;
                            }
                            break;

                        case SDLK_g:
                            kotxt[ k_calc++ ] = 'g' ;
                            break ;

                        case SDLK_h:
                            kotxt[ k_calc++ ] = 'h' ;
                            kotxt[k_calc] = 0 ;
                            break ;

                        case SDLK_i:
                            kotxt[ k_calc++ ] = 'i' ;
                            kotxt[k_calc] = 0 ;
                            break ;

                        case SDLK_j:
                            kotxt[ k_calc++ ] = 'j' ;
                            kotxt[k_calc] = 0 ;
                            break ;

                        case SDLK_k:
                            kotxt[ k_calc++ ] = 'k' ;
                            kotxt[k_calc] = 0 ;
                            break ;

                        case SDLK_l:
                            kotxt[ k_calc++ ] = 'l' ;
                            kotxt[k_calc] = 0 ;
                            break ;

                        case SDLK_m:
                            if ( keystate[SDLK_LSHIFT] || keystate[SDLK_RSHIFT] && !( tag_chargement || tag_sauvegarde ) )
                            {
                                kotxt[ k_calc++ ] = 'M' ;
                                kotxt[k_calc] = 0 ;
                            }
                            else
                            {
                                kotxt[ k_calc++ ] = 'm' ;
                                kotxt[k_calc] = 0 ;
                            }
                            break ;

                        case SDLK_n:
                            kotxt[ k_calc++ ] = 'n' ;
                            kotxt[k_calc] = 0 ;
                            break ;

                        case SDLK_o:
                            kotxt[ k_calc++ ] = 'o' ;
                            kotxt[k_calc] = 0 ;
                            break ;

                        case SDLK_p:
                            if ( keystate[SDLK_LSHIFT] || keystate[SDLK_RSHIFT] && !( tag_chargement || tag_sauvegarde ) )
                            {
                                kotxt[ k_calc++ ] = 'P' ;
                                kotxt[k_calc] = 0 ;
                            }
                            else
                            {
                                kotxt[ k_calc++ ] = 'p' ;
                                kotxt[k_calc] = 0 ;
                            }
                            break ;

                        case SDLK_q:
                            if ( ( keystate[SDLK_LSHIFT] || keystate[SDLK_RSHIFT] ) && ( keystate[SDLK_LCTRL] || keystate[SDLK_RCTRL] ) )
                                continuer = 0 ;
                            else
                            {
                                kotxt[ k_calc++ ] = 'q' ;
                                kotxt[k_calc] = 0 ;
                            }
                            break ;

                        case SDLK_r:
                            kotxt[ k_calc++ ] = 'r' ;
                            kotxt[k_calc] = 0 ;
                            break ;

                        case SDLK_s:
                            kotxt[ k_calc++ ] = 's' ;
                            kotxt[k_calc] = 0 ;
                            break ;

                        case SDLK_t:
                            if ( keystate[SDLK_LSHIFT] || keystate[SDLK_RSHIFT] && !( tag_chargement || tag_sauvegarde ) )
                            {
                                kotxt[ k_calc++ ] = 'T' ;
                                kotxt[k_calc] = 0 ;
                            }
                            else
                            {
                                kotxt[ k_calc++ ] = 't' ;
                                kotxt[k_calc] = 0 ;
                            }
                            break ;

                        case SDLK_u:
                            kotxt[ k_calc++ ] = 'u' ;
                            kotxt[k_calc] = 0 ;
                            break ;

                        case SDLK_v:
                            kotxt[ k_calc++ ] = 'v' ;
                            kotxt[k_calc] = 0 ;
                            break ;

                        case SDLK_w:
                            if ( !( tag_chargement || tag_sauvegarde ) )
                            {
                                kotxt[ k_calc++ ] = 'W' ;
                                kotxt[k_calc] = 0 ;
                            }
                            else
                            {
                                kotxt[ k_calc++ ] = 'w' ;
                                kotxt[k_calc] = 0 ;
                            }
                            break ;

                        case SDLK_x:
                            if ( !( tag_chargement || tag_sauvegarde ) )
                            {
                                kotxt[ k_calc++ ] = 'X' ;
                                kotxt[k_calc] = 0 ;
                            }
                            else
                            {
                                kotxt[ k_calc++ ] = 'x' ;
                                kotxt[k_calc] = 0 ;
                            }
                            break ;

                        case SDLK_y:
                            kotxt[ k_calc++ ] = 'y' ;
                            kotxt[k_calc] = 0 ;
                            break ;

                        case SDLK_z:
                            if ( !( tag_chargement || tag_sauvegarde ) )
                            {
                                kotxt[ k_calc++ ] = 'Z' ;
                                kotxt[k_calc] = 0 ;
                            }
                            else
                            {
                                kotxt[ k_calc++ ] = 'z' ;
                                kotxt[k_calc] = 0 ;
                            }
                            break ;


                        case SDLK_0:
                            kotxt[ k_calc++ ] = '0' ;
                            kotxt[k_calc] = 0 ;
                            break ;

                        case SDLK_1:
                            kotxt[ k_calc++ ] = '1' ;
                            kotxt[k_calc] = 0 ;
                            break ;

                        case SDLK_2:
                            kotxt[ k_calc++ ] = '2' ;
                            kotxt[k_calc] = 0 ;
                            break;

                         case SDLK_3:
                            kotxt[ k_calc++ ] = '3' ;
                            kotxt[k_calc] = 0 ;
                            break;

                        case SDLK_4:
                            kotxt[ k_calc++ ] = '4' ;
                            kotxt[k_calc] = 0 ;
                            break;

                        case SDLK_5:
                            kotxt[ k_calc++ ] = '5' ;
                            kotxt[k_calc] = 0 ;
                            break ;

                        case SDLK_6:
                            kotxt[ k_calc++ ]= '6' ;
                            kotxt[k_calc] = 0 ;
                            break;

                        case SDLK_7:
                            kotxt[ k_calc++ ] = '7' ;
                            kotxt[k_calc] = 0 ;
                            break;

                         case SDLK_8:
                            kotxt[ k_calc++ ] = '8' ;
                            kotxt[k_calc] = 0 ;
                            break;

                        case SDLK_9:
                            kotxt[ k_calc++ ] = '9' ;
                            kotxt[k_calc] = 0 ;
                            break;

                        case SDLK_QUOTE:
                            kotxt[ k_calc++ ] = '^' ;
                            kotxt[ k_calc++ ] = '/' ;
                            kotxt[k_calc] = 0 ;
                            break;

                        case SDLK_SEMICOLON:
                            kotxt[ k_calc++ ] = '^' ;
                            kotxt[k_calc] = 0 ;
                            break;

                        case SDLK_SLASH:
                            kotxt[ k_calc++ ] = '/' ;
                            kotxt[k_calc] = 0 ;
                            break;

                        case SDLK_COMMA:
                            kotxt[ k_calc++ ] = '*' ;
                            kotxt[k_calc] = 0 ;
                            break;

                        case SDLK_EQUALS:
                            kotxt[ k_calc++ ] = '+' ;
                            kotxt[k_calc] = 0 ;
                            break;

                        case SDLK_LEFTBRACKET:
                            kotxt[ k_calc++ ] = '(' ;
                            kotxt[k_calc] = 0 ;
                            break;

                        case SDLK_RIGHTBRACKET:
                            kotxt[ k_calc++ ] = ')' ;
                            kotxt[k_calc] = 0 ;
                            break;


                        case SDLK_F1: // affiche un unique monument aux morts

                            if ( keystate[SDLK_LSHIFT] || keystate[SDLK_RSHIFT] )
                            {
                                if( click_shift_F1 == 1 )
                                    click_shift_F1 = 0 ;
                                else
                                    click_shift_F1 = 1 ;
                            }
                            else
                            {
                                if( click_F1 == 1 )
                                    click_F1 = 0 ;
                                else
                                    click_F1 = 1 ;
                            }
                            break;

                        case SDLK_F2: // affiche la liste des particules
                            if ( keystate[SDLK_LSHIFT] || keystate[SDLK_RSHIFT]  )
                            {
                                if( click_shift_F2 == 0 )
                                    click_shift_F2 = 1 ;
                            }
                            else
                            {
                                if(tag_liste == 1 )
                                {
                                    tag_liste = 0 ;
                                    choix_liste = lkiunit ;
                                }
                                else
                                    tag_liste = 1 ;
                            }
                            break;

                        case SDLK_F3: // affiche ou non les formules
                            if(click_F3 == 1 )
                                click_F3 = 0 ;
                            else
                                click_F3 = 1 ;
                            break;

                        case SDLK_F4: // change l'unité de la liste e---MeV---u
                            if( tag_liste == 1 )
                            {
                                if( unite____ == 1 )
                                    unite____ = Mev____;
                                else
                                if( unite____ == Mev____ )
                                    unite____ = u____ ;
                                else
                                    unite____ = 1 ;
                            }
                            break;

                        case SDLK_F5:
                       //     aff[0]=1; aff[1]=2; aff[2]=3;aff[3]=0;aff[4]=-1;
                            if ( keystate[SDLK_LSHIFT] || keystate[SDLK_RSHIFT]  ) // passe en mode de chargement des choix pour chaque particule
                            {

                                tag_chargement = 1 ;
                                tag_sauvegarde = 0 ;
/*                                if( numero_sauvegarde == nb_sauvegarde )
                                {
                                    numero_sauvegarde = - 1 ;
                                }
                                else
                                {
                                    numero_sauvegarde++ ;
                                }*/

                            }

/*
                            for(k=0;k!=MAX_papy_nbe-2;k++)
                            {
                                for( int_= 0 ; int_ < 17 ; int_++ )
                                    ligne_vide[int_] = ' ' ;

                                l = strlen( name[k] ) ;
                                if( 17-l > 0 )
                                    ligne_vide[ 17-l ] = 0 ;
                                else
                                    ligne_vide[ 0 ] = 0 ;
                                printf("%s%s %c : %s\n",name[k], ligne_vide, (char) mamy[k].me.choix+'0', mamy[k].me.txt[mamy[k].me.choix]) ;
                            }*/
                            break;

    //                    case SDLK_F6:
                            //aff[]={1,2,3,0,11,12,-1};
      //                  sscanf( kotxt, "%lf", &lk_add ) ;

        //                    break;

               //         case SDLK_F7:
                 //       lk_add=0;
                 //       break;

                        case SDLK_F9: // remets à zéro ce qu'on additionne à chaque particule
                            lk_add = 0 ;
                            break ;

                        case SDLK_F10: // affiche ou non l'évaluation de l'expression arithmétique et symbolique entrée par l'utilisateur
                            if( click_F10 == 0 )
                                click_F10 = 1 ;
                            else
                                click_F10 = 0 ;
                            break ;


                        case SDLK_RETURN:
                            if( tag_chargement || tag_sauvegarde )
                            {
                                if(tag_chargement)
                                {
                                    k = ident_ds ;
                                    l = 0 ;
                                    while( kotxt[l] != 0 )
                                    {
                                        chemin_sauvegarde[ k + l ] = kotxt[l] ;
                                        l++ ;
                                    }
                                    chemin_sauvegarde[ k + l ] = 0 ;
                                    FILE *fichier_choix = NULL ;
                                    fichier_choix=fopen( chemin_sauvegarde, "r" ) ;
                                        if( fichier_choix != NULL )
                                        {
                                            i = 0 ;
                                            for( ; i != MAX_papy_nbe ; i++ )
                                            {
                                                int_ = fgetc( fichier_choix ) ;
                                                if( int_ < '9'+1 && int_> '0'-1 )
                                                {
                                                    mamy[ i ].me.choix = int_ - '0';
                                                }
                                                else
                                                    mamy[ i ].me.choix = int_ + 10 - 'a' ;
                                            }
                                            fclose( fichier_choix ) ;
                                            tag_chargement++;
                                            tag_changement_constante = 1 ;

                                        }
                                 //   if( tag_chargement == 3 )
                                   //     tag_chargement = 0 ;
                                }
                                else
                                {
                                    k = ident_ds ;
                                    l = 0 ;
                                    while( kotxt[l] != 0 )
                                    {
                                        chemin_sauvegarde[ k + l ] = kotxt[l] ;
                                        l++ ;
                                    }
                                    chemin_sauvegarde[ k + l ] = 0 ;
                                    FILE *fichier_choix = NULL ;
                                    fichier_choix = fopen( chemin_sauvegarde, "w" ) ;
                                        if( fichier_choix != NULL )
                                        {
                                            i = 0 ;
                                            for( ; i != MAX_papy_nbe ; i++ )
                                            {
                                                int_ = mamy[ i ].me.choix ;
                                                if( int_ < 10 )
                                                {
                                                    if( int_ < 0 )
                                                        int_ = 0 ;
                                                    fputc( int_+'0', fichier_choix ) ;
                                                }
                                                else
                                                    fputc( int_ - 10 + 'a', fichier_choix ) ;
                                            }
                                            fclose( fichier_choix ) ;
                                            tag_sauvegarde++ ;
                                        /////////////////////////////////////////////////
                                        // rechargement liste des choix sauvegardés   //
                                        ///////////////////////////////////////////////
                                            rep = opendir("save");

                                            if ( rep != NULL )
                                            {
                                                i = 0 ;
                                                k = 0 ;
                                                l = 0 ;
                                                while ((ent = readdir(rep)) != NULL)
                                                {
                                                    if ( ent->d_name[0] != '.' )
                                                    {
                                                        i++;
                                                        while( ent->d_name[k] != 0 )
                                                            k++ ;
                                                        k++ ;
                                                        l+=k ;
                                                        k=0 ;
                                                     //printf("%s\n", ent->d_name);
                                                    }
                                                }
                                                closedir(rep);
                                            }
                                            //on reserve i pointeurs +l char de memoire <-- contenu du repertoire
                                            free( memoire_sauvegarde_choix ) ;
                                            memoire_sauvegarde_choix = (char*) malloc( l ) ;
                                            int_ = 0 ;
                                            while( int_ < nb_choix_load )
                                            {
                                                choix_loadp[ int_ ] = NULL ;
                                                int_++ ;
                                            }
                                            nb_choix_load = i ;
                                            // puis deuxieme passage on remplit la memoire qu'on vient de reserver avec le nom des fonts en load

                                            rep=opendir("save") ;
                                            //opendir("fonts/fonts_store/liberation");

                                            if (rep != NULL && nb_choix_load != 0 )
                                            {
                                                i=0;
                                                k=0;
                                                l=0;
                                                while ((ent = readdir(rep)) != NULL)
                                                {
                                                    if (ent->d_name[0]!='.')
                                                    {
                                                        choix_loadp[i] = memoire_sauvegarde_choix + l ;
                                                        i++;
                                                        while(ent->d_name[k]!=0)
                                                        {
                                                            memoire_sauvegarde_choix[l+k]=ent->d_name[k];
                                                            k++;
                                                        }
                                                        l+=k;
                                                        memoire_sauvegarde_choix[l]=0;
                                                        l++;
                                                        k=0;

                                                        //puis askmem k+1
                                                        //    while(ent->d_name[k]!=0)
                                                      //      cap=ent->d_name[k++];
                                                        //askmem 1

                                        //            printf("%s\n", ent->d_name);
                                                    }
                                                }
                                                closedir(rep);
                                            }


                                        }
                                    //if( tag_sauvegarde == 3 )
                                      //  tag_sauvegarde = 0 ;
                                }
                            }
                            else
                            {
                                if ( keystate[SDLK_LSHIFT] || keystate[SDLK_RSHIFT] ) // additionne, pour chaque particule, l'évaluation de l'expression arithmétique et symbolique
                                {
                                    val_shift_enter = alg_eva( kotxt ) ;
                                }
                                else
                                    lk_add = alg_eva( kotxt ) ;
                            }
                            break ;

                            //sscanf( kotxt, "%lf" , &lk_add ) ;
//                            tg_transfert = 1 ;
                        //mamy[max_element].me.z=lk_add;
//                        sprintf(ko2,"%f",lk_add*2);
//                            k_calc=0;

                            break;


                        case SDLK_ESCAPE:
                            if ( keystate[SDLK_LSHIFT] || keystate[SDLK_RSHIFT]  ) //passe en mode de sauvegarde des choix pour chaque particule
                            {
                                tag_sauvegarde = 1 ;
                                tag_chargement = 0 ;
                            }
                            else // chanhe , en . et vice-versa
                            {
                                if( tag_chargement || tag_sauvegarde )
                                {
                                    tag_chargement = 0 ;
                                    tag_sauvegarde = 0 ;
                                    kotxt[0] = 0 ;
                                    k_calc = 0 ;
                                }

                                else

                              //  {
                                if ( wincomma == ',' )
                                    wincomma = '.' ;
                                else
                                    wincomma = ',' ;
                                //}
                            }
                        break ;

                        case SDLK_LEFT:

                            if ( keystate[SDLK_LSHIFT] || keystate[SDLK_RSHIFT] )
                            {
                                dsx-- ;
                                add_tag_hero_xh++ ;
                            }
                            else
                            {
                                xh-- ;
                                vxh = -1 ;
                                if( scene[yh][xh] == 1 )
                                {
                                    xh++ ;
                                    vxh++;
                                }
                                if( scene[yh][xh] == 4 )
                                {
                                    scene[ yh ][ xh++ ] = 3 ;
                                    vxh = 0 ;
                                }
                                if( scene[yh][xh] == 3 )
                                {
                                    scene[yh][xh++] = 2 ;
                                    xh--;
//                                    vxh/=2 ;
                                    //gloo glouu
                                    //potion_verte + 1 ;
                                }
                            }

    //Uint8 *keystate = SDL_GetKeyState(NULL);

    //if ( keystate[SDLK_RETURN] ) printf("Return Key Pressed.\n");

                            if ( keystate[SDLK_LSHIFT] || keystate[SDLK_RSHIFT]  )
                            {
                               // compt = compt_sqr ;
                                if(compt_sqr[lki]>1)
                                    {
                                        compt_sqr[lki] -= 1;
                                    }

                            }
                            else
                            {
                                //if ( keystate[SDLK_LCTRL] || keystate[SDLK_RCTRL]  )
                                //{
                                  //  compt = compt_sqr ;
                                   // if(compt[0]>1)
                                    //{
                                     //   compt[0] -= 1;
                                   // }
                               // }
                             //   else
                               // {
                                    //compt=compt_pwr;
                                    compt_pwr[lki] -= 1;
                                  //  *lkp[lki]/=lkv[lki];
                                  //  lk/=lkv[lki];
                                //}
                            }
                            break;
                        case SDLK_RIGHT:

                            //xh++;
                           // dsx++;
                           // if(scene[yh+dsy][xh+dsx]==1)
                             // {
                              //  xh-- ;
                             // dsx--;
                             //   }
                            if ( keystate[SDLK_LSHIFT] || keystate[SDLK_RSHIFT] )
                            {
                                    dsx++ ;
                                    add_tag_hero_xh-- ;
                            }
                            else
                            {
                                xh++ ;
                                if( scene[yh][xh] == 1 )
                                    xh-- ;

                                if( scene[yh][xh] == 4 )
                                    scene[yh][xh--] = 3 ;
                                if( scene[yh][xh] == 3 )
                                {
                                    scene[yh][xh--] = 2 ;
                                    //potion_verte + 1 ;
                                }
                            }
                            if ( keystate[SDLK_LSHIFT] || keystate[SDLK_RSHIFT] )
                                compt_sqr[lki] += 1;
                            else
                                    compt_pwr[lki] += 1;
                            break;

                        case SDLK_UP:
                            if ( keystate[SDLK_LSHIFT] || keystate[SDLK_RSHIFT] )
                            {
                                dsy++ ;
                                add_tag_hero_yh-- ;
                            }
                            else
                            {
                                yh--;
                                if( scene[ yh ][ xh ] == 1 )
                                    yh++ ;

                                if( scene[ yh ][ xh ] == 4 )
                                    scene[ yh++ ][ xh ] = 3 ;

                                if( scene[ yh ][ xh ] == 3 )
                                {
                                    scene[ yh++ ][ xh ] = 2 ;
                                    //potion_verte + 1 ;
                                }
                            }
//
                            if( --lki == -1 )
                                lki++ ;

                            break;

                        case SDLK_DOWN:

                            if ( keystate[SDLK_LSHIFT] || keystate[SDLK_RSHIFT] )
                            {
                                dsy-- ;
                                add_tag_hero_yh++ ;
                            }
                            else
                            {
                                yh++;
                                if(scene[yh][xh]==1)
                                    yh-- ;

                                if( scene[yh][xh] == 4 )
                                    scene[yh--][xh] = 3 ;

                                if( scene[yh][xh] == 3 )
                                {
                                    scene[yh--][xh] = 2 ;
                                    //potion_verte + 1 ;
                                }
                            }
                            if(lkv[++lki]==-1) lki--;
                            break;
                        default:
                            break;
                    }
                    break;

//                case SDLK_ESCAPE:
//                    continuer = 0;
//                    break;

                case SDL_QUIT:
                    continuer = 0;
                    break;

                 default:
                    break;
            }
        }
/////////////////////////////////////////////
        while( SDL_PollEvent( &event ) ) ;
////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//                                                                        //
//On met à jour les constantes suivant le choix pour chaque particule    //
//                                                                      //
/////////////////////////////////////////////////////////////////////////
        if ( tag_changement_constante == 1 )
        {
            alg_expr_cst_minuscule['b' - 'a'] = mamy[ tag_beauty__ ].me.z ;
            aec_min_tag_choix['b' - 'a'] = mamy[ tag_beauty__ ].me.t[mamy[ tag_beauty__ ].me.choix ] ;

            alg_expr_cst_minuscule['c' - 'a'] = mamy[ tag_charm__ ].me.z ;
            aec_min_tag_choix['c' - 'a'] = mamy[ tag_charm__ ].me.t[mamy[ tag_charm__ ].me.choix ] ;

            alg_expr_cst_minuscule['d' - 'a'] = mamy[ tag_De_ ].me.z ;
            aec_min_tag_choix['d' - 'a'] = mamy[ tag_De_ ].me.t[mamy[ tag_De_ ].me.choix ] ;

            alg_expr_cst_minuscule['f' - 'a'] = mamy[ tag_Tr_ ].me.z ;
            aec_min_tag_choix['f' - 'a'] = mamy[ tag_Tr_ ].me.t[mamy[ tag_Tr_ ].me.choix ] ;

            alg_expr_cst_minuscule['g' - 'a'] = mamy[ tag_He3__ ].me.z ;
            aec_min_tag_choix['g' - 'a'] = mamy[ tag_He3__ ].me.t[mamy[ tag_He3__ ].me.choix ] ;

            alg_expr_cst_minuscule['h' - 'a'] = mamy[ tag_He4__ ].me.z ;
            aec_min_tag_choix['h' - 'a'] = mamy[ tag_He4__ ].me.t[mamy[ tag_He4__ ].me.choix ] ;

            alg_expr_cst_minuscule['i' - 'a'] = mamy[ tag_Pi0 ].me.z ;
            aec_min_tag_choix['i' - 'a'] = mamy[ tag_Pi0 ].me.t[mamy[ tag_Pi0 ].me.choix ] ;

            alg_expr_cst_minuscule['j' - 'a'] = mamy[ tag_Pi_ ].me.z ;
            aec_min_tag_choix['j' - 'a'] = mamy[ tag_Pi_ ].me.t[mamy[ tag_Pi_ ].me.choix ] ;

    //        alg_expr_cst_minuscule['k' - 'a'] = k12 ;
     //       aec_min_name['k' - 'a'] = (char *) "k12 (Vol. D12)" ;

    //        alg_expr_cst_minuscule['l' - 'a'] = k20 ;
    //        aec_min_name['l' - 'a'] = (char *) "k20 (Vol. D20)" ;

            alg_expr_cst_minuscule['m' - 'a'] = mamy[ tag_muon_ ].me.z ;
            aec_min_tag_choix['m' - 'a'] = mamy[ tag_muon_ ].me.t[mamy[ tag_muon_ ].me.choix ] ;

            alg_expr_cst_minuscule['n' - 'a'] = mamy[ tag_Neutron ].me.z ;
            aec_min_tag_choix['n' - 'a'] = mamy[ tag_Neutron ].me.t[mamy[ tag_Neutron ].me.choix ] ;

    //        alg_expr_cst_minuscule['o' - 'a'] = M_PI ;

            alg_expr_cst_minuscule['p' - 'a'] = mamy[ tag_proton_ ].me.z ;
    //        aec_min_name['p' - 'a'] = mamy[ tag_proton_ ].nom ;
            aec_min_tag_choix['p' - 'a'] = mamy[ tag_proton_ ].me.t[mamy[ tag_proton_ ].me.choix ] ;

    //        alg_expr_cst_minuscule['q' - 'a'] = k12 / k20 ;
    //        aec_min_name['q' - 'a'] = (char *) "k12/k20" ;

            alg_expr_cst_minuscule['s' - 'a'] = mamy[ tag_strange__ ].me.z ;
            aec_min_tag_choix['s' - 'a'] = mamy[ tag_strange__ ].me.t[mamy[ tag_strange__ ].me.choix ] ;

            alg_expr_cst_minuscule['t' - 'a'] = mamy[ tag_tau_ ].me.z ;
            aec_min_tag_choix['t' - 'a'] = mamy[ tag_tau_ ].me.t[mamy[ tag_tau_ ].me.choix ] ;

            alg_expr_cst_minuscule['u' - 'a'] = mamy[ tag_up__ ].me.z ;
            aec_min_tag_choix['u' - 'a'] = mamy[ tag_up__ ].me.t[mamy[ tag_up__ ].me.choix ] ;

            alg_expr_cst_minuscule['v' - 'a'] = mamy[ tag_down__ ].me.z ;
            aec_min_tag_choix['v' - 'a'] = mamy[ tag_down__ ].me.t[mamy[ tag_down__ ].me.choix ] ;


            alg_expr_cst_majuscule['D' - 'A'] = mamy[ tag_H ].me.z - mamy[ tag_proton_ ].me.z - 1  ;
            aec_maj_tag_choix['D' - 'A'] = mamy[ tag_H ].me.t[mamy[ tag_H ].me.choix ] ;

            alg_expr_cst_majuscule['H' - 'A'] = mamy[ tag_H ].me.z  ;
            aec_maj_tag_choix['H' - 'A'] = mamy[ tag_H ].me.t[mamy[ tag_H ].me.choix ] ;

            alg_expr_cst_majuscule['K' - 'A'] = mamy[ tag_K0 ].me.z  ;
            aec_maj_tag_choix['K' - 'A'] = mamy[ tag_K0 ].me.t[mamy[ tag_K0 ].me.choix ] ;

            alg_expr_cst_majuscule['L' - 'A'] = mamy[ tag_K_ ].me.z  ;
            aec_maj_tag_choix['L' - 'A'] = mamy[ tag_K_ ].me.t[mamy[ tag_K_ ].me.choix ] ;

            alg_expr_cst_majuscule['M' - 'A'] = mamy[ tag_Minfini ].me.z  ;
            aec_maj_tag_choix['M' - 'A'] = mamy[ tag_Minfini ].me.t[mamy[ tag_Minfini ].me.choix ] ;

    //        alg_expr_cst_majuscule['P' - 'A'] = phi ;

            alg_expr_cst_majuscule['T' - 'A'] = mamy[ tag_top__ ].me.z ;
            aec_maj_tag_choix['T' - 'A'] = mamy[ tag_top__ ].me.t[mamy[ tag_top__ ].me.choix ] ;

            alg_expr_cst_majuscule['W' - 'A'] = mamy[ tag_W1_ ].me.z ;
            aec_maj_tag_choix['W' - 'A'] = mamy[ tag_W1_ ].me.t[mamy[ tag_W1_ ].me.choix ] ;

            alg_expr_cst_majuscule['X' - 'A'] = mamy[ tag_X0 ].me.z ;
            aec_maj_tag_choix['X' - 'A'] = mamy[ tag_X0 ].me.t[mamy[ tag_X0 ].me.choix ] ;

            alg_expr_cst_majuscule['Z' - 'A'] = mamy[ tag_Z1  ].me.z ;
            aec_maj_tag_choix['Z' - 'A'] = mamy[ tag_Z1 ].me.t[mamy[ tag_Z1 ].me.choix ] ;


///////////////////////////////////
//    int_ = 3 ;
            for(k=1 ; k < MAX_papy_nbe ; k++)
            {
            int_ = 3 ;
                while( mamy[k].me.t[int_] != 0 )
                {
        //            mamy[k].me.txt[int_] = (char *) eval_txt_W1_[ int_ ] ;
                    mamy[k].me.c[int_] = alg_eva( mamy[k].me.txt[int_] ) ;
                    int_++ ;
                }
                mamy[k].me.z = mamy[k].me.c[ mamy[k].me.choix ] ;
            }
            tag_changement_constante = 0 ;
        }
///////////////////////////////////

//////////////////////////////////////////////////
/////////////////// efface l'écran et le décore
        if( click_F1 == 1 )
        {
            SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 225-couleur_F1, 225-couleur_F1, 255));
            couleur_F1 += 1 ;
            if (couleur_F1 == 225-125)
            {
                couleur_F1 = 0 ;
                click_F1 = 0 ;
            }
        }
        else
            SDL_FillRect( ecran, NULL, SDL_MapRGB(ecran->format, 125, 125, 255) );
 //                   Line(ecran,x-10,y,x+10,y,0xAAAABBAA);

//////////////
        position.x = windx/2 - 24  ;
        position.y = windy/2 + 1 ;
        if( tag_liste == 1 )
        {
            position.x += 58  ;
            position.y -= 108  ;
        }
//        position.y += 14*phi;//60;

        SDL_BlitSurface( app_g[ 9 ], NULL, ecran, &position ) ;


///////////////////////////fenetre 3

        position.x = 0 ; //windx/2 - app_g[4]-> w / 2 ;
        position.y = windy - app_g[4]-> h ;
        SDL_BlitSurface( app_g[ 4 ], NULL, ecran, &position);

        position.y -= 42 ;
        position.x += app_g[ 0 ]-> w /2 ;
        SDL_BlitSurface( app_g[ 0 ], NULL, ecran, &position ) ;
        position.x -= app_g[ 0 ]-> w /2 ;

        position.y += 42 ;


        position.x = app_g[ 4 ]->w ;
        SDL_BlitSurface( app_g[ 4 ], NULL, ecran, &position );


        //tplanck =12.0 ;
//        sprintf( ko3, "%12f", ipi1_1 );//1/(mamy[1].me.m/M_PI/M_PI-20.95));
//        SDL_FreeSurface(texte);
//        texte = TTF_RenderText_Blended(tinypolice, ko3, couleur[tagc_GriseM]);
//        position.y += 14*phi;//60;
//        SDL_BlitSurface(texte, NULL, ecran, &position);
        x=0;
        y=0;
        position.x = x;
        position.y = y;
        SDL_BlitSurface(fond, NULL, ecran, &position);
        position.x = x;
        position.y = windy /3;
        SDL_BlitSurface(fond, NULL, ecran, &position);
        position.x =  windx /3 + 2*icon_mf->w /2 ;
        position.y =  icon_mf->h /2 ;

        if( tag_liste != 1 )
            SDL_BlitSurface(icon_mf, NULL, ecran, &position) ;
        position.x = windx /2 ;
        position.y = 0 ;
        SDL_BlitSurface( icon_fil, NULL, ecran, &position ) ;
        y = 0 ;

//affiche muon et autres
        i = 0 ;
        dy = 0 ;
        dxl=(int) -10*phi;
        dyl=(int) -2*phi;
        X = 160 ;
        Y = 20 ;

        while( aff[ i ] != -1 )
          {
            tag = aff[ i++ ] ;

            if( i == 4 )
            {
                dy = 0 ;
                dx = -128 ;
            }
            if( i == 5 )
            {
                dy +=6 ;
                dx = -128 ;
            }
            if( i == 8 )
            {
                dy += 6 ;
                dx = -128 ;
            }

            if( i == 11 )
            {
                dy += 6 ;
                dx = -128 ;
            }
            if( i == 15 )
            {
                dy = 89 ;
                dx = 10 ;
            }

/*            if( i == 18 && tag_liste != 1 )
            {
                dy = 290 ;
                dx = 140 ;
            } */

// affiche le nom
            mynowcouleur = couleur[ mamy[tag].affichage.c ] ;
            k = 0 ;
            while( mamy[tag].nom[k] != 0 )
                k++;
            txp=mamy[tag].nom;

            position.x = (int) (X+dx+dxl+2*(-k+4))*phi;
            position.y = (int) (Y+dy+dyl)*phi ;
            //SDL_free(texte);

            k  = 1 ;
            lk = 1 ;
            while( lkv[k]!=-1 )
                {
                   *lkp[k] = pow(lkv[k],(double) ((double) compt_pwr[k]/(double) compt_sqr[k])) ;
                    lk *= *lkp[k];
                    k++ ;
                }


            SDL_FreeSurface( texte ) ;
            texte = TTF_RenderText_Blended( tinypolice, txp, mynowcouleur ) ;
            SDL_BlitSurface( texte, NULL, ecran, &position ) ;

            position.x = (int) (X+dx+dxl+mytinypolicesize/2 ) * phi ;
            position.y = (int) (Y+dy+dyl + mytinypolicesize/2 ) * phi ;
            SDL_FreeSurface( texte ) ;
           // kotxt[ 1024 ] = mamy[ tag ].me.t[ mamy[ tag ].me.choix ] ;
            ko2[ 1024 ] = mamy[ tag ].me.t[ mamy[ tag ].me.choix ] ;
            ko2[ 1025 ] = 0 ;
           // kotxt[ 1025 ] = 0 ;

            texte = TTF_RenderText_Blended( tinypolice, ko2 + 1024 , couleur[ tagc_Jaune ] ) ;
            SDL_BlitSurface( texte, NULL, ecran, &position ) ;


            if( taginverse == 1 )
                Line(ecran,position.x,position.y+wintinypolicesize,position.x+wintinypolicesize*2,position.y+wintinypolicesize,0xaabbcc00);
//
            txp=tx+8+24;
            if(taginverse==1)
                sprintf(txp,"%.14f",1/(mamy[tag].me.m/lk/lkunit+lk_add));
            else
                sprintf(txp,"%.14f",mamy[tag].me.m/lk/lkunit+lk_add);
            k=0;
            while(txp[k]!='.' && k<17) k++;
            if (txp[k]=='.')
                txp[k]=wincomma;
//            txp[16]=0;

            position.x = (int) (X+dx)*phi;
            position.y = (int) (Y-8+dy)*phi ;
            mynowcouleur=couleur[tagc_GriseM];
            txp=tx+32;
            SDL_FreeSurface(texte);
            texte = TTF_RenderText_Blended(tinypolice, (const char*)txp, mynowcouleur);
            SDL_BlitSurface(texte, NULL, ecran, &position);
//
            if( taginverse == 1 )
                sprintf(txp,"%.14f",1/(mamy[tag].me.z/lk/lkunit+lk_add));
            else
                sprintf(txp,"%.14f",mamy[tag].me.z/lk/lkunit+lk_add);
            k=0;
            while( txp[ k ] != '.' && k < 17 )
                k++;
            if (txp[k]=='.')
                txp[k] = wincomma ;
            txp[ 16 ] = 0 ;
            position.x = (int) (X+dx)*phi;
            position.y = (int) (Y+dy)*phi ;
            mynowcouleur=couleur[mamy[tag].affichage.c];
            txp=tx+32;
            SDL_FreeSurface(texte);
            texte = TTF_RenderText_Blended(police, (const char*)txp, mynowcouleur);
            SDL_BlitSurface(texte, NULL, ecran, &position);
            if( taginverse == 1 )
                sprintf(txp,"%.14f",1/(mamy[tag].me.p/lk/lkunit+lk_add));
            else
                sprintf(txp,"%.14f",mamy[tag].me.p/lk/lkunit+lk_add);
            k=0;
            while(txp[k]!='.' && k<17) k++;
            if (txp[k]=='.')
                txp[k]=wincomma;
            txp[16]=0;
            position.x = (int) (X+dx)*phi;
            position.y = (int) (Y+9+dy)*phi ;
            mynowcouleur=couleur[tagc_GriseM];
            txp=tx+32;
            SDL_FreeSurface(texte);
            texte = TTF_RenderText_Blended(tinypolice, (const char*)txp, mynowcouleur);
            SDL_BlitSurface(texte, NULL, ecran, &position);
            txp=tx+4;
            dy+=32;

        }
        dy=0;
        dx=0;


        position.x = (int) windx*4/5-mypolicesize + mypolicesize*3 ;//60;
        //fuzzy;
        //position.y = (int) (4+10*lki)*(phi+1);//370;
        position.y = (int) (4+11*lki)*(phi+1);//370;

// curseur
        txp=tx+64;
        txp[0]='>';
        txp[1]=0;
        txp[2]=0;
        txp[3]=0;

        SDL_FreeSurface( texte ) ;
        texte = TTF_RenderUNICODE_Blended(police,(const Uint16*)txp, couleur[tagc_Noire]);
        SDL_BlitSurface(texte, NULL, ecran, &position);


///////////////////////////////////////
//// affiche ou pas la valeur bonus
        if( val_shift_enter != 0 )
        {
            position.x = windx/2-8*mypolicesize;//60;
            position.y = windy-17*mypolicesize;//windy - 8*mypolicesize ; //370;
            SDL_FreeSurface(texte);
            txp = ko3 ;
            sprintf(txp,"%.8f",val_shift_enter);
            texte = TTF_RenderText_Blended(police, ko3, couleur[ tagc_Pink2 ] ) ;
            SDL_BlitSurface(texte, NULL, ecran, &position);

            position.x += 2*mypolicesize;//60;
            position.y += 3*mypolicesize;//windy - 8*mypolicesize ; //370;


            if( taginverse == 1 )
                Line(ecran,position.x,position.y+wintinypolicesize,position.x+wintinypolicesize*2,position.y+wintinypolicesize,0xaabbcc00);

            if( taginverse == 1 )
                sprintf( txp, "%.8f", 1/val_shift_enter/lk/lkunit ) ;
            else
                sprintf( txp, "%.8f", val_shift_enter/lk/lkunit ) ;
            k = 0 ;
            while( txp[k] != '.' && k < 17)
                k++;
            if ( txp[k] == '.' )
                txp[k] = wincomma ;
            mynowcouleur=couleur[tagc_GriseM];
            SDL_FreeSurface(texte);
            texte = TTF_RenderText_Blended(tinypolice, (const char*)txp, mynowcouleur);
            SDL_BlitSurface(texte, NULL, ecran, &position);
        }


// liste
     //   SDL_FreeSurface(texte);
//        texte = TTF_RenderUNICODE_Blended(police,(const Uint16*)txp, couleur[tagc_Noire]);
        if( tag_liste == 1 )
        {
            position.x = (int) windx/3-96;//60;
            position.y = (int) 23*(phi+0*1);//370;

            SDL_BlitSurface( app_g[5], NULL, ecran, &position ) ;

            position.x =  windx /3 ; //- icon_mf->w  ;
            position.y =  icon_mf->h /2 - icon_mf->w /2 ;

           // if( tag_liste == 1 )
            SDL_BlitSurface(icon_mf, NULL, ecran, &position);

            position.x = (int) windx/3-96;//60;
            position.y = (int) 23*(phi+0*1);//370;

            i=0;
            while( aff_liste[i] != -1 )
            {
                if( i == 3 )
                    sprintf(txp,"%.14f", alpha0);
                //else if( i == 9 )
                  //  sprintf(txp,"%.14f", k12/k20);
                else if( i != 7 )
                    if( i == 8 )
                        sprintf( txp, "%.22f", mamy[aff_liste[i]].me.z * unite____ ) ;
                    else
                        sprintf( txp, "%.12f", mamy[aff_liste[i]].me.z * unite____ ) ;
                else
                    sprintf( txp, " " ) ;

                k = 0 ;
                while( txp[k]!='.' && k < 17 )
                    k++;
                if ( txp[k] == '.' )
                    txp[k] = wincomma ;
                if( i != 8 )
                    txp[14] = 0 ;
                else
                    txp[24] = 0 ;

                position.x = (int) (windx/3)+75;
                position.y = (int) (42)*phi + (phi*i)*mypolicesize -23 ;
                //txp=tx+32;
                SDL_FreeSurface( texte ) ;

                if( i != 8 )
                    texte = TTF_RenderText_Blended( police, (const char*) txp, couleur[ 2 ] );
                else
                    texte = TTF_RenderText_Blended( supertinypolice, (const char*)txp, couleur[ 2 ] ) ;

                SDL_BlitSurface( texte, NULL, ecran, &position ) ;
                ///////////////////////:
                // et on affiche le tag nom
               if( i != 3 && i != 7 && i != 9 )
               {
                    ck[ 0 ] = mamy[ aff_liste[i] ].me.t[ mamy[ aff_liste[i] ].me.choix ] ;
                    ck[ 1 ] = 0 ;
                    //tx*[ 2 ] = 0 ;
                //        tx[ 3 ] = 0 ;
                    position.x -= mypolicesize;
                   // position.y += mypolicesize/2;

                    SDL_FreeSurface( texte ) ;

                    texte = TTF_RenderText_Blended( tinypolice, ck, couleur[ tagc_Jaune ] ) ;
                    SDL_BlitSurface( texte, NULL, ecran, &position ) ;
                    position.x += mypolicesize;
                //    position.y -= mypolicesize/2;
                }
                i++ ;
            }
        }
//shift+f1 : help
        if( click_shift_F1 == 0 )

        {
            position.x = (int) 0 ;//60;
            position.y = (int) 0 ;//370;
            SDL_FreeSurface(texte);
            texte = TTF_RenderText_Blended(supertinypolice, "shift+F1 : help", couleur[ tagc_Pink2 ] ) ;
            SDL_BlitSurface(texte, NULL, ecran, &position);
        }

//tick
        position.x = (int) windx/2 - 128 ;//60;
        position.y = (int) 0 ;//370;

        txp = tx + 64 ;
        sprintf(txp,"%is %ims",SDL_GetTicks()/1000,SDL_GetTicks()-(1000*((int)SDL_GetTicks()/1000)) );//1/(mamy[1].me.m/M_PI/M_PI-20.95));
        SDL_FreeSurface(texte);
        texte = TTF_RenderText_Blended(tinypolice, txp, couleur[ tagc_Noire + 1 ]);
//ko2[9]=0;
 //texte = TTF_RenderText_Blended(tinypolice, ko2, couleur[tagc_Pink3]);
        SDL_BlitSurface(texte, NULL, ecran, &position);
        SDL_FreeSurface(texte);
        position.x-=1;
        position.y-=1;

        texte = TTF_RenderText_Blended(tinypolice, txp, couleur[tagc_Pink]);
//ko2[9]=0;
 //texte = TTF_RenderText_Blended(tinypolice, ko2, couleur[tagc_Pink3]);
        SDL_BlitSurface(texte, NULL, ecran, &position);


 // résultat saisie utilisateur

    if(!(tag_chargement||tag_sauvegarde))
    {
         SDL_FreeSurface(texte);
   //kotxt[ 15 ] = 0 ;
        position.x = (int) windx/3-128 ;//60;
        position.y = (int) 0*(phi+1);//370;

        texte = TTF_RenderText_Blended(tinypolice, kotxt, couleur[tagc_Pink3]);
        SDL_BlitSurface(texte, NULL, ecran, &position);
    }

//lk (valeur global de division ie unite)
        position.x = (int) windx/2+48 ;//60;
        position.y = (int) 6*(phi+1);//370;

        txp = tx + 64 ;
        sprintf( txp, "%.16f", lk ) ;//1/(mamy[1].me.m/M_PI/M_PI-20.95));
        k = 0 ;
        while( txp[ k ] != '.' && txp[ k ] != 0 )
            k++ ;
        if ( txp[ k ] == '.' )
            txp[ k ] = wincomma ;
        SDL_FreeSurface( texte ) ;
        texte = TTF_RenderText_Blended( police, txp, couleur[tagc_GriseF] ) ;
        SDL_BlitSurface(texte, NULL, ecran, &position);

        position.x += texte->w + mytinypolicesize/2;
        position.y -=1;
        txp=tx+64;
        k = 0 ;
        txp[ 0 ] = name[ lkiunit ][ 0 ] ;
        while( name[ lkiunit ][ k ] != 0 && k < 18 )
        {
            txp[ k ] = name[ lkiunit ][ k ] ;
            k++ ;
        }
        txp[k] = 0 ;

        SDL_FreeSurface( texte ) ;
        texte = TTF_RenderText_Blended( police, txp, couleur[ tagc_GriseF ] ) ;
        SDL_BlitSurface( texte, NULL, ecran, &position ) ;
        position.x -= 1 ;
        position.y += 1 ;


        txp -= 2 ;
 //       if( tag_liste == 1 )
        {

            SDL_FreeSurface(texte);
            txp=tx+64;
            k = 0 ;
            txp[ 0 ] = name[ choix_liste ][ 0 ] ;
            while( name[ choix_liste ][ k ] != 0 && k < 18 )
                {
                    txp[ k ] = name[ choix_liste ][ k ] ;
                    k++ ;
                }
            txp[k++] = ' ' ;
            txp[k] = 0 ;


            texte = TTF_RenderText_Blended( police, txp, couleur[tagc_GriseF] ) ;

    // suite
            position.x = (int) windx/2+48 ;//60;
            position.y = (int) 16*(phi+1);//370;
            SDL_BlitSurface( texte, NULL, ecran, &position ) ;

            position.x += texte->w ;//60;
            SDL_FreeSurface(texte) ;
            position.x -= 1 ;
            position.y += 1 ;
            texte = TTF_RenderText_Blended( police, mamy[choix_liste].me.txt[mamy[choix_liste].me.choix], couleur[tagc_GriseM] ) ;
            SDL_BlitSurface( texte, NULL, ecran, &position ) ;
            position.x += 1 ;
            position.y -= 1 ;

            SDL_FreeSurface(texte);
            texte = TTF_RenderText_Blended( police, mamy[choix_liste].me.txt[mamy[choix_liste].me.choix], couleur[tagc_GriseF] ) ;
            SDL_BlitSurface( texte, NULL, ecran, &position ) ;

        }
        if( tag_shift_space == 1 && !(tag_liste) )
        {

            SDL_FreeSurface(texte);
            txp=tx+64;
            k = 0 ;
            txp[ 0 ] = name[ shift_space ][ 0 ] ;
            while( name[ shift_space ][ k ] != 0 && k < 18 )
            {
                txp[ k ] = name[ shift_space ][ k ] ;
                k++ ;
            }
            txp[k++] = ' ' ;
            txp[k] = 0 ;
            texte = TTF_RenderText_Blended( police, txp, couleur[tagc_GriseF] ) ;
            position.x = (int) windx/2-6*mypolicesize ;//60;
            position.y = (int) 16*(phi+1);//370;
            SDL_BlitSurface( texte, NULL, ecran, &position ) ;
    }

///////////////////////////////////////////////////////////////
//phi
        X=(int) 4*windx/5 + mypolicesize*3 ;
        Y= (int) 14*(phi+1);
        position.x = X ;
        position.y = Y ;

        SDL_FreeSurface( texte ) ;
        texte = TTF_RenderUNICODE_Blended( police, ( const Uint16* ) tx, couleur[ tagc_Jaune ] );
        SDL_BlitSurface( texte, NULL, ecran, &position );

        txp = tx + 4 ;
        position.x += 10*phi;//60;
        txp[1] = 0 ;
        SDL_FreeSurface(texte);
        texte = TTF_RenderText_Blended(police, txp, couleur[tagc_Pink]);
        SDL_BlitSurface(texte, NULL, ecran, &position);

        position.x -= 8*phi;//60;
        position.y -= 4*phi;//60;
            txp=tx+40;
            sprintf(txp,"%2i",compt[1]);//1/(mamy[1].me.m/M_PI/M_PI-20.95));

        SDL_FreeSurface(texte);
        texte = TTF_RenderText_Blended(tinypolice, txp, couleur[tagc_Jaune]);
        SDL_BlitSurface(texte, NULL, ecran, &position);

        position.x += 8*phi;//60;
        position.y += 4*phi;//60;


        txp=tx+64;
            sprintf(txp,"%.12f",*lkp[1]);//1/(mamy[1].me.m/M_PI/M_PI-20.95));
    // 20=pi()^5/kdz
    // 1/20=kdz/pi()^5
//    =(pi()^7/kdz+kdz/pi()^3)*kdz
            k=0;
            while(txp[k]!='.' && k<45) k++;
            if (txp[k]=='.')
                txp[k]=wincomma;
            txp[15]=0;

        position.x += 2*mypolicesize/3;//60;
        SDL_FreeSurface(texte);
        texte = TTF_RenderText_Blended(police, txp, couleur[tagc_GriseM]);
        SDL_BlitSurface(texte, NULL, ecran, &position);

//pi
        position.x = X ;//60;
        position.y = Y+mypolicesize*phi;//370;
        txgrec[0]+=15;
        SDL_FreeSurface(texte);
        texte = TTF_RenderUNICODE_Blended(police, (const Uint16*)txgrec, couleur[tagc_Bleu]);
        SDL_BlitSurface(texte, NULL, ecran, &position);
        txgrec[0]-=15;
        txp=tx+4;
        position.x += 10*phi;//60;
        txp[1]=0;
        SDL_FreeSurface(texte);
        texte = TTF_RenderText_Blended(police, txp, couleur[tagc_Pink]);
        SDL_BlitSurface(texte, NULL, ecran, &position);

        position.x -= 8*phi;//60;
        position.y -= 4*phi;//60;
        txp=tx+40;
        if(!(compt_pwr[2]==1 && compt_sqr[2]==1))
        {
            sprintf(txp,"%2i",compt_pwr[2]);//1/(mamy[1].me.m/M_PI/M_PI-20.95));
            if(compt_sqr[2]>1)
            {
                k=0;
                while(txp[k++]!=0);
                txp[k-1]='/';
                sprintf(txp+k,"%i",compt_sqr[2]);//1/(mamy[1].me.m/M_PI/M_PI-20.95));
                SDL_FreeSurface(texte);
                texte = TTF_RenderText_Blended(tinypolice, txp, couleur[tagc_Bleu]);
                SDL_BlitSurface(texte, NULL, ecran, &position);
            }
            else
            {
                SDL_FreeSurface(texte);
                texte = TTF_RenderText_Blended(tinypolice, txp, couleur[tagc_Bleu]);
                SDL_BlitSurface(texte, NULL, ecran, &position);
            }
        }
        position.x += 8*phi;//60;
        position.y += 4*phi;//60;


        txp=tx+64;
        sprintf(txp,"%.12f",*lkp[2]);//1/(mamy[1].me.m/M_PI/M_PI-20.95));
    // 20=pi()^5/kdz
    // 1/20=kdz/pi()^5
//    =(pi()^7/kdz+kdz/pi()^3)*kdz
        k=0;
        while(txp[k]!='.' && k<45) k++;
        if (txp[k]=='.')
            txp[k]=wincomma;
        txp[15]=0;

        position.x += 2*mypolicesize/3;//60;
        SDL_FreeSurface(texte);
        texte = TTF_RenderText_Blended(police, txp, couleur[tagc_GriseM]);
        SDL_BlitSurface(texte, NULL, ecran, &position);
        txp-=2;
      //  position.x += 1;//60;
      //  position.y += 1;//370;
        SDL_BlitSurface(texte, NULL, ecran, &position);

//        SDL_PutPixel32(ecran, (int) ((phi+1)*10), (int) (10*phi), 0x00AA6699);
//k12
        position.x = X ;//60;
        position.y = Y+2*mypolicesize*phi;//370;
        txgrec[0]+=9;
        SDL_FreeSurface(texte);
        position.x -= mysupertinypolicesize/2 ;
        texte = TTF_RenderUNICODE_Blended(police, (const Uint16*)txgrec, couleur[tagc_Jaune]);
        SDL_BlitSurface(texte, NULL, ecran, &position);
        position.x += mysupertinypolicesize/2 ;
        txgrec[0]-=9;
//
        position.x += mysupertinypolicesize/2 ;//60;
        position.y += 5*phi;//60;
        txp=tx+40;
        txp[0]='1';
        txp[1]='2';
        txp[2]=0 ;
        SDL_FreeSurface(texte);
        texte = TTF_RenderText_Blended( supertinypolice, txp, couleur[ tagc_Jaune ] ) ;
        SDL_BlitSurface( texte, NULL, ecran, &position ) ;
        position.x -= mysupertinypolicesize/2 ;//60;
        position.y -= 5*phi;//60;
////////:::

        txp=tx+4;
        position.x += 10*phi;//60;
        txp[1]=0 ;

        SDL_FreeSurface(texte);
        texte = TTF_RenderText_Blended(police, txp, couleur[tagc_Pink]);
        SDL_BlitSurface(texte, NULL, ecran, &position);

        position.x -= 8*phi;//60;
        position.y -= 4*phi;//60;
            txp=tx+40;
            sprintf(txp,"%2i",compt[3]);//1/(mamy[1].me.m/M_PI/M_PI-20.95));

        SDL_FreeSurface(texte);
        texte = TTF_RenderText_Blended(tinypolice, txp, couleur[tagc_Bleu]);
        SDL_BlitSurface(texte, NULL, ecran, &position);

        position.x += 8*phi;//60;
        position.y += 4*phi;//60;


        txp=tx+64;
            sprintf(txp,"%.12f",*lkp[3]);//1/(mamy[1].me.m/M_PI/M_PI-20.95));
    // 20=pi()^5/kdz
    // 1/20=kdz/pi()^5
//    =(pi()^7/kdz+kdz/pi()^3)*kdz
            k=0;
            while(txp[k]!='.' && k<45) k++;
            if (txp[k]=='.')
                txp[k]=wincomma;
            txp[15]=0;

        position.x += 2*mypolicesize/3;//60;
        SDL_FreeSurface(texte);
        texte = TTF_RenderText_Blended(police, txp, couleur[tagc_GriseM]);
        SDL_BlitSurface(texte, NULL, ecran, &position);
        txp-=2;
      //  position.x += 1;//60;
      //  position.y += 1;//370;
        SDL_BlitSurface(texte, NULL, ecran, &position);

//        SDL_PutPixel32(ecran, (int) ((phi+1)*10), (int) (10*phi), 0x00AA6699);
//k20
        position.x = X ;//60;
        position.y = Y+3*mypolicesize*phi;//370;
        txgrec[0]+=9;
        SDL_FreeSurface(texte);
        position.x -= mysupertinypolicesize/2 ;
        texte = TTF_RenderUNICODE_Blended(police, (const Uint16*)txgrec, couleur[tagc_Bleu]);
        SDL_BlitSurface(texte, NULL, ecran, &position);
        position.x += mysupertinypolicesize/2 ;
        txgrec[0]-=9;
//
        position.x += mysupertinypolicesize/2 ;//60;
        position.y += 5*phi;//60;
        txp=tx+40;
        txp[0]='2';
        txp[1]='0';
        txp[2]=0 ;
        SDL_FreeSurface(texte);
        texte = TTF_RenderText_Blended( supertinypolice, txp, couleur[ tagc_Bleu ] ) ;
        SDL_BlitSurface( texte, NULL, ecran, &position ) ;
        position.x -= mysupertinypolicesize/2 ;//60;
        position.y -= 5*phi;//60;

        txp=tx+4;
        position.x += 10*phi;//60;
        txp[1]=0;
        SDL_FreeSurface(texte);
        texte = TTF_RenderText_Blended(police, txp, couleur[tagc_Pink]);
        SDL_BlitSurface(texte, NULL, ecran, &position);

        position.x -= 8*phi;//60;
        position.y -= 4*phi;//60;
        txp=tx+40;
        sprintf(txp,"%2i",compt[4]);
        SDL_FreeSurface(texte);
        texte = TTF_RenderText_Blended(tinypolice, txp, couleur[tagc_Jaune]);
        SDL_BlitSurface(texte, NULL, ecran, &position);
        position.x += 8*phi;//60;
        position.y += 4*phi;//60;
        txp=tx+64;
        sprintf(txp,"%.12f",*lkp[4]);//1/(mamy[1].me.m/M_PI/M_PI-20.95));
        k=0;
        while(txp[k]!='.' && k<45) k++;
        if (txp[k]=='.')
            txp[k]=wincomma;
        txp[15]=0;
        position.x += 2*mypolicesize/3;//60;
        SDL_FreeSurface(texte);
        texte = TTF_RenderText_Blended(police, txp, couleur[tagc_GriseM]);
        SDL_BlitSurface(texte, NULL, ecran, &position);
        txp-=2;
        SDL_BlitSurface(texte, NULL, ecran, &position);
//alpha0
        position.x = X ;//60;
        position.y = Y+4*mypolicesize*phi;//370;
//      txgrec[0]-=0;
        SDL_FreeSurface(texte);
        texte = TTF_RenderUNICODE_Blended(police, (const Uint16*)txgrec, couleur[tagc_Rouge]);
        SDL_BlitSurface(texte, NULL, ecran, &position);
//        txgrec[0]+=0;
        txp=tx+4;
        position.x += 10*phi;//60;
        txp[1]=0;
        SDL_FreeSurface(texte);
        texte = TTF_RenderText_Blended(police, txp, couleur[tagc_Pink]);
        SDL_BlitSurface(texte, NULL, ecran, &position);

        position.x -= 8*phi;//60;
        position.y -= 4*phi;//60;
            txp=tx+40;
            sprintf(txp,"%2i",compt[5]);//1/(mamy[1].me.m/M_PI/M_PI-20.95));

        SDL_FreeSurface(texte);
        texte = TTF_RenderText_Blended(tinypolice, txp, couleur[tagc_Pink]);
        SDL_BlitSurface(texte, NULL, ecran, &position);

        ///////////////////////////////////:
        if(!(compt_pwr[5]==1 && compt_sqr[5]==1))
        {
            sprintf(txp,"%2i",compt_pwr[5]);//1/(mamy[1].me.m/M_PI/M_PI-20.95));
            if(compt_sqr[5]>1)
            {
                k=0;
                while(txp[k++]!=0);
                txp[k-1]='/';
                sprintf(txp+k,"%i",compt_sqr[5]);//1/(mamy[1].me.m/M_PI/M_PI-20.95));
                SDL_FreeSurface(texte);
                texte = TTF_RenderText_Blended(tinypolice, txp, couleur[tagc_Bleu]);
                SDL_BlitSurface(texte, NULL, ecran, &position);
            }
            else
            {
                SDL_FreeSurface(texte);
                texte = TTF_RenderText_Blended(tinypolice, txp, couleur[tagc_Bleu]);
                SDL_BlitSurface(texte, NULL, ecran, &position);
            }
        }
        position.x += 8*phi;//60;
        position.y += 4*phi;//60;

        ////////////////////////////////////




        position.x += 8*phi;//60;
        position.y += 4*phi;//60;


        txp=tx+64;
            sprintf(txp,"%.12f",*lkp[5]);//1/(mamy[1].me.m/M_PI/M_PI-20.95));
    // 20=pi()^5/kdz
    // 1/20=kdz/pi()^5
//    =(pi()^7/kdz+kdz/pi()^3)*kdz
            k=0;
            while(txp[k]!='.' && k<45) k++;
            if (txp[k]=='.')
                txp[k]=wincomma;
            txp[15]=0;

        position.x += 2*mypolicesize/3;//60;
        SDL_FreeSurface(texte);
        texte = TTF_RenderText_Blended(police, txp, couleur[tagc_GriseM]);
        SDL_BlitSurface(texte, NULL, ecran, &position);
        txp-=2;
      //  position.x += 1;//60;
      //  position.y += 1;//370;
        SDL_BlitSurface(texte, NULL, ecran, &position);

// it was cos pi/3
// but now k12 / k20
        position.x = X ;//60;
        position.y = Y+5*mypolicesize*phi;//370;
        txgrec[0]+=9;
        SDL_FreeSurface(texte);
        texte = TTF_RenderUNICODE_Blended(police, (const Uint16*)txgrec, couleur[tagc_Bleu]);
        txgrec[0]-=9;
        SDL_BlitSurface(texte, NULL, ecran, &position);
        position.x += 10*phi;//60;
        position.x -= 8*phi;//60;
        position.y -= 4*phi;//60;
        txp=tx+40;
        sprintf(txp,"%2i",compt[6]);//1/(mamy[1].me.m/M_PI/M_PI-20.95));
        SDL_FreeSurface(texte);
        texte = TTF_RenderText_Blended(tinypolice, txp, couleur[tagc_Bleu]);
        SDL_BlitSurface(texte, NULL, ecran, &position);
        position.x += 8*phi;//60;
        position.y += 4*phi;//60;
        position.x -= 3*phi;//60;
        position.y += 5*phi;//60;
        txp=tx+40;
        /*
        txp[0]=txgrec[0]+15;
        txp[1]=txgrec[1];
        txp[2]='/';
        txp[3]=0;
        txp[4]='3';
        txp[5]=0;
        txp[6]=0;
        txp[7]=0;*/
        txp[0]='1';
        txp[1]='2';
        txp[2]='/';
        txp[3]='2';
        txp[4]='0';
        txp[5]=0;

        SDL_FreeSurface(texte);
//        texte = TTF_RenderUNICODE_Blended(tinypolice, (const Uint16*)txp, couleur[tagc_Bleu]);
        texte = TTF_RenderText_Blended( supertinypolice, txp, couleur[tagc_Bleu] );
        SDL_BlitSurface( texte, NULL, ecran, &position ) ;
        position.x += 3*phi;//60;
        position.y -= 5*phi;//60;
        position.x += 10*phi;
        txp=tx+64;
        sprintf(txp,"%.12f",*lkp[6]);//1/(mamy[1].me.m/M_PI/M_PI-20.95));
        k=0;
        while(txp[k]!='.' && k<45) k++;
        if (txp[k]=='.')
            txp[k]=wincomma;
        txp[15]=0;
        position.x += 2*mypolicesize/3;//60;
        SDL_FreeSurface(texte);
        texte = TTF_RenderText_Blended(police, txp, couleur[tagc_GriseM]);
        SDL_BlitSurface(texte, NULL, ecran, &position);

// it was sin pi/3
// but now square root 10
        position.x = X ;//60;
        position.y = Y+6*mypolicesize*phi;//370;
        //txgrec[0]+=18;

        SDL_FreeSurface(texte);
        texte = TTF_RenderUNICODE_Blended(police, (const Uint16*) txmath , couleur[tagc_Pink]);
        //txgrec[0]-=18;
        SDL_BlitSurface(texte, NULL, ecran, &position);
        position.x += 10*phi;//60;

        position.x -= 8*phi;//60;
        position.y -= 4*phi;//60;
            txp=tx+40;
            sprintf(txp,"%2i",compt[7]);//1/(mamy[1].me.m/M_PI/M_PI-20.95));

        SDL_FreeSurface(texte);
        texte = TTF_RenderText_Blended(tinypolice, txp, couleur[tagc_Pink2]);
        SDL_BlitSurface(texte, NULL, ecran, &position);

        position.x += 8*phi;//60;
        position.y += 4*phi;//60;

        position.x -= 3*phi;//60;
        position.y += 5*phi;//60;
            txp=tx+40;

            //sprintf(txp,"/3");//1/(mamy[1].me.m/M_PI/M_PI-20.95));
//        txp[0]=txgrec[0]+15;
//        txp[1]=txgrec[1];
        txp[0]='1';
        txp[1]=0;
        txp[2]='0';
        txp[3]=0;
        txp[4]=0;
        txp[5]=0;

        SDL_FreeSurface( texte ) ;
        texte = TTF_RenderUNICODE_Blended(tinypolice, ( const Uint16* ) txp, couleur[tagc_Pink]);
        SDL_BlitSurface( texte, NULL, ecran, &position ) ;

        position.x += 3*phi;//60;
        position.y -= 5*phi;//60;

        position.x += 10*phi;

        txp=tx+64;
            sprintf(txp,"%.12f",*lkp[7]);//1/(mamy[1].me.m/M_PI/M_PI-20.95));
    // 20=pi()^5/kdz
    // 1/20=kdz/pi()^5
//    =(pi()^7/kdz+kdz/pi()^3)*kdz
            k=0;
            while(txp[k]!='.' && k<45) k++;
            if (txp[k]=='.')
                txp[k]=wincomma;
            txp[15]=0;

        position.x += 2*mypolicesize/3;//60;
        SDL_FreeSurface( texte ) ;
        texte = TTF_RenderText_Blended( police, txp, couleur[ tagc_GriseM ] ) ;
        SDL_BlitSurface( texte, NULL, ecran, &position ) ;
//cos pi/5
        position.x = X ;//60;
        position.y = Y + 7 * mypolicesize * phi ;//370;
        txgrec[ 0 ] += 17 ;
        SDL_FreeSurface( texte ) ;
        texte = TTF_RenderUNICODE_Blended( police, (const Uint16*) txgrec, couleur[tagc_Bleu] ) ;
        txgrec[ 0 ] -= 17 ;
        SDL_BlitSurface( texte, NULL, ecran, &position ) ;
        position.x += 10 * phi ;//60;
        position.x -= 8 * phi ;//60;
        position.y -= 4 * phi ;//60;
        txp = tx + 40 ;
        sprintf( txp, "%2i", compt[ 8 ] ) ;//1/(mamy[1].me.m/M_PI/M_PI-20.95));
        SDL_FreeSurface( texte ) ;
        texte = TTF_RenderText_Blended( tinypolice, txp, couleur[ tagc_Bleu ] ) ;
        SDL_BlitSurface( texte, NULL, ecran, &position ) ;
        position.x += 8 * phi ;//60;
        position.y += 4 * phi ;//60;
        position.x -= 3 * phi ;//60;
        position.y += 5 * phi ;//60;
        txp = tx + 40 ;
        /*
        txp[ 0 ] = txgrec[ 0 ] + 15 ;
        txp[ 1 ] = txgrec[ 1 ] ;
        txp[ 2 ] ='/' ;
        txp[ 3 ] = 0 ;
        txp[ 4 ] = '5';
        txp[ 5 ] = 0 ;
        txp[ 6 ] = 0 ;
        txp[ 7 ] = 0 ;
        */

        txp[ 0 ] = '2';
        txp[ 1 ] = 0 ;
        txp[ 2 ] = txgrec[ 0 ] + 15 ;
        txp[ 3 ] = txgrec[ 1 ] ;
        txp[ 4 ] ='/' ;
        txp[ 5 ] = 0 ;
        txp[ 6 ] = '4';
        txp[ 7 ] = 0 ;
        txp[ 8 ] = '5' ;
        txp[ 9 ] = 0 ;
        txp[ 10 ] = 0 ;
        txp[ 11 ] = 0 ;

        SDL_FreeSurface( texte ) ;
        texte = TTF_RenderUNICODE_Blended( tinypolice, (const Uint16*) txp, couleur[ tagc_Bleu ] ) ;
        SDL_BlitSurface( texte, NULL, ecran, &position ) ;
        position.x += 3*phi;//60;
        position.y -= 5*phi;//60;
        position.x += 10*phi;
        txp=tx+64;
        sprintf(txp,"%.12f",*lkp[8]);//1/(mamy[1].me.m/M_PI/M_PI-20.95));
        k=0;
        while(txp[k]!='.' && k<45) k++;
        if (txp[k]=='.')
            txp[k]=wincomma;
        txp[15]=0;
        position.x += 2*mypolicesize/3;//60;
        SDL_FreeSurface(texte);
        texte = TTF_RenderText_Blended(police, txp, couleur[tagc_GriseM]);
        SDL_BlitSurface(texte, NULL, ecran, &position);
//sin pi/5
        position.x = X ;//60;
        position.y = Y+8*mypolicesize*phi;//370;
        txgrec[0]+=18;
        SDL_FreeSurface(texte);
        texte = TTF_RenderUNICODE_Blended(police, (const Uint16*)txgrec, couleur[tagc_Pink]);
        txgrec[0]-=18;
        SDL_BlitSurface(texte, NULL, ecran, &position);
        position.x += 10*phi;//60;
        position.x -= 8*phi;//60;
        position.y -= 4*phi;//60;
        txp=tx+40;
        sprintf(txp,"%2i",compt[9]);//1/(mamy[1].me.m/M_PI/M_PI-20.95));

        SDL_FreeSurface(texte);
        texte = TTF_RenderText_Blended(tinypolice, txp, couleur[tagc_Pink2]);
        SDL_BlitSurface(texte, NULL, ecran, &position);
        position.x += 8*phi;//60;
        position.y += 4*phi;//60;
        position.x -= 3*phi;//60;
        position.y += 5*phi;//60;
        txp=tx+40;

        /*
        txp[ 0 ] = txgrec[ 0 ] + 15 ;
        txp[ 1 ] = txgrec[ 1 ] ;
        txp[ 2 ] ='/' ;
        txp[ 3 ] = 0 ;
        txp[ 4 ] = '5';
        txp[ 5 ] = 0 ;
        txp[ 6 ] = 0 ;
        txp[ 7 ] = 0 ;
        */

        txp[ 0 ] = '2';
        txp[ 1 ] = 0 ;
        txp[ 2 ] = txgrec[ 0 ] + 15 ;
        txp[ 3 ] = txgrec[ 1 ] ;
        txp[ 4 ] ='/' ;
        txp[ 5 ] = 0 ;
        txp[ 6 ] = '4';
        txp[ 7 ] = 0 ;
        txp[ 8 ] = '5' ;
        txp[ 9 ] = 0 ;
        txp[ 10 ] = 0 ;
        txp[ 11 ] = 0 ;

        SDL_FreeSurface(texte);
        texte = TTF_RenderUNICODE_Blended(tinypolice, (const Uint16*)txp, couleur[tagc_Pink]);
        SDL_BlitSurface(texte, NULL, ecran, &position);

        position.x += 3*phi;//60;
        position.y -= 5*phi;//60;

        position.x += 10*phi;

        txp=tx+64;
            sprintf(txp,"%.12f",*lkp[9]);//1/(mamy[1].me.m/M_PI/M_PI-20.95));
    // 20=pi()^5/kdz
    // 1/20=kdz/pi()^5
//    =(pi()^7/kdz+kdz/pi()^3)*kdz
            k=0;
            while(txp[k]!='.' && k<45) k++;
            if (txp[k]=='.')
                txp[k]=wincomma;
            txp[15]=0;

        position.x += 2*mypolicesize/3;//60;
        SDL_FreeSurface(texte);
        texte = TTF_RenderText_Blended(police, txp, couleur[tagc_GriseM]);
        SDL_BlitSurface(texte, NULL, ecran, &position);



//2
    for(int k_=0;k_<3;k_++)
    {
        position.x = X ;//60;
        position.y = Y + (9+k_)* mypolicesize*phi;//370;
//      txgrec[0]-=0;
        SDL_FreeSurface(texte);
        //txgrec[0]='2';
        ko2[0]='2'+k_;
        if(k_== 2 )
            ko2[0]='5';

        ko2[1]=0 ;
        ko2[2]=0 ;
        ko2[3]=0 ;


        texte = TTF_RenderUNICODE_Blended(police, (const Uint16*)ko2, couleur[tagc_Rouge-k_]);
        SDL_BlitSurface(texte, NULL, ecran, &position);
//        txgrec[0]+=0;
        txp=tx+4;
        position.x += 10*phi;//60;
        txp[1]=0;
        SDL_FreeSurface(texte);
        texte = TTF_RenderText_Blended(police, txp, couleur[tagc_Pink]);
        SDL_BlitSurface(texte, NULL, ecran, &position);

        position.x -= 8*phi;//60;
        position.y -= 4*phi;//60;
            txp=tx+40;
            sprintf(txp,"%2i",compt[10+k_]);//1/(mamy[1].me.m/M_PI/M_PI-20.95));

        SDL_FreeSurface(texte);
        texte = TTF_RenderText_Blended(tinypolice, txp, couleur[tagc_Pink]);
        SDL_BlitSurface(texte, NULL, ecran, &position);

        ///////////////////////////////////:
        if(!(compt_pwr[10+k_]==1 && compt_sqr[10+k_]==1))
        {
            sprintf(txp,"%2i",compt_pwr[10+k_]);//1/(mamy[1].me.m/M_PI/M_PI-20.95));
            if(compt_sqr[10+k_]>1)
            {
                k=0;
                while(txp[k++]!=0);
                txp[k-1]='/';
                sprintf(txp+k,"%i",compt_sqr[10+k_]);//1/(mamy[1].me.m/M_PI/M_PI-20.95));
                SDL_FreeSurface(texte);
                texte = TTF_RenderText_Blended(tinypolice, txp, couleur[tagc_Bleu]);
                SDL_BlitSurface(texte, NULL, ecran, &position);
            }
            else
            {
                SDL_FreeSurface(texte);
                texte = TTF_RenderText_Blended(tinypolice, txp, couleur[tagc_Bleu]);
                SDL_BlitSurface(texte, NULL, ecran, &position);
            }
        }
        position.x += 8*phi;//60;
        position.y += 4*phi;//60;

        ////////////////////////////////////

        position.x += 8*phi;//60;
        position.y += 4*phi;//60;


        txp=tx+64;
        sprintf(txp,"%.12f",*lkp[10+k_]);//1/(mamy[1].me.m/M_PI/M_PI-20.95));
    // 20=pi()^5/kdz
    // 1/20=kdz/pi()^5
//    =(pi()^7/kdz+kdz/pi()^3)*kdz
        k=0;
        while(txp[k] != '.' && k<45)
            k++;
        if ( txp[k] == '.' )
            txp[k] = wincomma ;
        txp[ 15 ] = 0 ;

        position.x += 2*mypolicesize/3;//60;
        SDL_FreeSurface(texte);
        texte = TTF_RenderText_Blended(police, txp, couleur[tagc_GriseM]);
        SDL_BlitSurface(texte, NULL, ecran, &position);
        txp-=2;
      //  position.x += 1;//60;
      //  position.y += 1;//370;
        SDL_BlitSurface(texte, NULL, ecran, &position);
    }
//3
////////////////////

            k=0;
            l=0;
            i=0;

    //for(;l<nbe_g;l++)
    {
        k = 0 ;
        while( dossier_fonts_load[k] != 0 )
            {
                ko2[k] = dossier_fonts_load[ k ] ;
                k++ ;
            }
        i = k ;
        k = 0 ;
        if ( tag_changement_fonts == 1 )

        {
            cap = fonts_loadp[ id_fonts ];
            while( *( cap + k ) != 0 )
                {
                    ko2[ i + k ] = *( cap + k ) ;
                    k++ ;
                }
            ko2[ i + k ] = 0 ;

            TTF_CloseFont( supertinypolice ) ;
            TTF_CloseFont( tinypolice ) ;
            TTF_CloseFont( police ) ;

            tinypolice = TTF_OpenFont( ko2, mytinypolicesize ) ;
            supertinypolice = TTF_OpenFont( ko2, mysupertinypolicesize ) ;
            police = TTF_OpenFont( ko2, mypolicesize ) ;
            tag_changement_fonts = 0 ;
        }

    }


        position.x = windx/2;//60;
        position.y = windy - mytinypolicesize ;//60;
        cap = fonts_loadp[ id_fonts ] ;
        SDL_FreeSurface( texte ) ;
        texte = TTF_RenderText_Blended( tinypolice, cap, couleur[ tagc_GriseF ] ) ;
        SDL_BlitSurface( texte, NULL, ecran, &position ) ;


    //    int_ = random() ;
/*        position.x = (int) x_stone ;
        position.y = (int) y_stone ;

        if( dx_stone < 0 )
            dx_stone -= 0.0003 ;
        else
            dx_stone += 0.0003 ;
        if( dy_stone < 0 )
            dy_stone -= 0.0003 ;
        else
            dy_stone += 0.0003 ;


        x_stone += dx_stone ;
        if( abs( xs_stone - x_stone ) > 1 )
        {
            xs_stone = x_stone ;
            if( x_stone > windx || x_stone < 0 )
            {
                dx_stone = - dx_stone;
            }
        }
        y_stone += dy_stone ;
        if( abs( ys_stone - y_stone ) > 1 )
        {
            ys_stone = y_stone ;
            if( y_stone > windy || y_stone < 0 )
            {
                dy_stone = - dy_stone;
            }
        }

//        k=srnd(SDL_GetTicks());
//for(l=0;l<9;l++)
//{
//if( position.x + position.y > 10 ) //`buggy`
//        {
            double_ = int_ / RAND_MAX ;
            double_ = random() / RAND_MAX ;
//            position.x = (int) () ;
            position.x = (int) (( xs_stone + double_ * dx_stone )) ;
            position.y = (int) (( ys_stone + double_ * dy_stone )) ;
  //      }
  //      else
        {
    //        position.x = (int) ( x_stone  ) ;
      //      position.y = (int) ( y_stone  ) ;
        }

//        sdl_rect.x=32*(app_g[4]->w/32*((int)int_/RAND_MAX));
        //sdl_rect.y=320;
        if( Ktime < 38*9 )
        {
            Ktime++ ;
        }
        else
        {
            Ktime = 0 ;
            int K = int_ ;
            int KX = app_g[3]->w/32 ;
            int KY = app_g[3]->h/32 ;
            sdl_rect.x = 32*( KX * K ) / RAND_MAX ;
            K=random() ;
            sdl_rect.y = 32*( KY * K ) / RAND_MAX ;


            sdl_rect.x = 32 * ((random()*KX)/RAND_MAX -1) ;
            K=random() ;
            sdl_rect.y = 32 * ((random()*KY)/RAND_MAX -1);
        }
//        sdl_rect.y=32*(app_g[4]->h/32-1)*((int)int_/RAND_MAX-1);
SDL_SetAlpha(app_g[3],SDL_SRCALPHA,10);

        SDL_BlitSurface( app_g[3], &sdl_rect, ecran, &position ) ;
//}
            //SDL_BlitSurface( icon_fil, NULL, ecran, &position ) ;

//        SDL_PutPixel32(ecran, (int) ((phi+1)*10), (int) (10*phi), 0x00AA6699);
*/
    sdl_rect.x = 32 * compt_pwr[0];
    sdl_rect.y = 32 * compt_sqr[0];
    sdl_rect.w = 32 ;
    sdl_rect.h = 32 ;

/////
    position.x =  ( windy /2 ) + 16*mypolicesize + mypolicesize  ;
//    if( tag_liste == 1 )
    {
  //      SDL_FreeSurface( texte ) ;
//        texte = TTF_RenderText_Blended( tinypolice, cap, couleur[ tagc_GriseF ] ) ;
        int_ = 0 ;
        i = 0 ;
        while( mamy[choix_liste].me.c[i] != 0 && i < MAX_num_mc )
        {
            if( strlen( mamy[choix_liste].me.txt[i] ) > int_ )
                int_ = strlen( mamy[choix_liste].me.txt[i] ) ;
            i++ ;
        }

        for( m = 0 ;  mamy[ choix_liste ].me.c[ m ] !=0 && m != MAX_num_mc ; m++ )
        {
            position.y = 62   + ( mypolicesize+9 ) * ( m + 1 ) ;
            SDL_BlitSurface( app_g[7], NULL, ecran, &position ) ;


            if( click_F3 == 1 && int_ > 18 )
         //   if( click_F3 == 1 )
            {
                position.x += 90 ;
                SDL_BlitSurface( app_g[7], NULL, ecran, &position ) ;
                position.x -= 90 ;
            }
            SDL_FreeSurface( texte ) ;
            txp[ 0 ] = mamy[ choix_liste ].me.t[ m ] ;
            txp[ 1 ] = 0 ;

            texte = TTF_RenderText_Blended( tinypolice, txp, couleur[ tagc_Jaune ] ) ;
            SDL_BlitSurface( texte, NULL, ecran, &position ) ;

            SDL_FreeSurface( texte ) ;
            sprintf( txp, "%.14f", ( mamy[ choix_liste ].me.c[m]) );
            txp[ 12 ] = 0 ;
            //if(m==0 || m==1)
            //position.x -= mytinypolicesize  ;
            //else
                position.x += mytinypolicesize  ;
            if( mamy[ choix_liste ].me.c[m] < mamy[ choix_liste ].me.m || mamy[ choix_liste ].me.c[m] > mamy[ choix_liste ].me.p )
                texte = TTF_RenderText_Blended( tinypolice, txp, couleur[ tagc_Rouge ] ) ;
            else
                texte = TTF_RenderText_Blended( tinypolice, txp, couleur[ tagc_GriseM ] ) ;
            SDL_BlitSurface( texte, NULL, ecran, &position ) ;
            if( m == mamy[ choix_liste ].me.choix )
                Line(ecran,position.x-wintinypolicesize/2,position.y+wintinypolicesize,position.x+(wintinypolicesize)/2 ,position.y+wintinypolicesize,0xaabbcc00);
            //position.x -= mytinypolicesize  ;
      //      position.x+=mysupertinypolicesize ;
            if( click_F3 == 1 )
            {
                position.y += mysupertinypolicesize + 2 ;

                position.x += 1 ;
                position.y -= 1 ;

                SDL_FreeSurface( texte ) ;
                texte = TTF_RenderText_Blended( supertinypolice, mamy[ choix_liste ].me.txt[ m ], couleur[ tagc_Noire ] ) ;
                SDL_BlitSurface( texte, NULL, ecran, &position ) ;

                position.x -= 1 ;
                position.y += 1 ;


                SDL_FreeSurface( texte ) ;
                texte = TTF_RenderText_Blended( supertinypolice, mamy[ choix_liste ].me.txt[ m ], couleur[ tagc_Pink ] ) ;
                SDL_BlitSurface( texte, NULL, ecran, &position ) ;


          //      position.x-=mysupertinypolicesize ;
                position.y -= mysupertinypolicesize - 2 ;
            }

        }


    }
    position.y = 62    ;
    position.x -= mypolicesize  ;

    SDL_BlitSurface( app_g[6], NULL, ecran, &position ) ;

    SDL_FreeSurface( texte ) ;
    txp[ 0 ] = mamy[ choix_liste ].me.t[ mamy[ choix_liste ].me.choix ] ;
    txp[ 1 ] = 0 ;
    //tx*[ 2 ] = 0 ;
//        tx[ 3 ] = 0 ;

    double_ = 7*(mamy[ choix_liste ].me.c[ mamy[ choix_liste ].me.choix ] - mamy[ choix_liste ].me.m) ;
    double_ /= (mamy[ choix_liste ].me.p - mamy[ choix_liste ].me.m) ;
    double_ *= mypolicesize ;
    position.x +=  (int) double_  ;
    position.y -= 2*mypolicesize/5 ;//////////////////////////////// L A B Y
    //position.x += double_ ;

    texte = TTF_RenderText_Blended( police, txp, couleur[ tagc_Jaune ] ) ;
    SDL_BlitSurface( texte, NULL, ecran, &position ) ;

    position.y += 2*mypolicesize/5 ;//////////////////////////////// L A B Y
    //position.x -=  double_  ;

    k = 0 ;
    l = 0 ;
    i = 0 ;
///////////////////////////:
/////
    position.x =  ( windy /2 ) + 4*mypolicesize  ;

    if( tag_shift_space == 1 && !(tag_liste) )
    {
  //      SDL_FreeSurface( texte ) ;
//        texte = TTF_RenderText_Blended( tinypolice, cap, couleur[ tagc_GriseF ] ) ;
        int_ = 0 ;
        i = 0 ;
        while( mamy[shift_space].me.c[i] != 0 && i < MAX_num_mc )
        {
            if( strlen( mamy[shift_space].me.txt[i] ) > int_ )
                int_ = strlen( mamy[shift_space].me.txt[i] ) ;
            i++ ;
        }

        for( m = 0 ;  mamy[ shift_space ].me.c[ m ] !=0 && m != MAX_num_mc ; m++ )
        {
            position.y = 62   + ( mypolicesize+9 ) * ( m + 1 ) ;
            SDL_BlitSurface( app_g[7], NULL, ecran, &position ) ;


            if( click_F3 == 1 && int_ > 18 )
         //   if( click_F3 == 1 )
            {
                position.x += 90 ;
                SDL_BlitSurface( app_g[7], NULL, ecran, &position ) ;
                position.x -= 90 ;
            }
            SDL_FreeSurface( texte ) ;
            txp[ 0 ] = mamy[ shift_space ].me.t[ m ] ;
            txp[ 1 ] = 0 ;

            texte = TTF_RenderText_Blended( tinypolice, txp, couleur[ tagc_Jaune ] ) ;
            SDL_BlitSurface( texte, NULL, ecran, &position ) ;

            SDL_FreeSurface( texte ) ;
            sprintf( txp, "%.14f", ( mamy[ shift_space ].me.c[m]) );
            txp[ 12 ] = 0 ;
            //if(m==0 || m==1)
            //position.x -= mytinypolicesize  ;
            //else
                position.x += mytinypolicesize  ;
            if( mamy[ shift_space ].me.c[m] < mamy[ shift_space ].me.m || mamy[ shift_space ].me.c[m] > mamy[ shift_space ].me.p )
                texte = TTF_RenderText_Blended( tinypolice, txp, couleur[ tagc_Rouge ] ) ;
            else
                texte = TTF_RenderText_Blended( tinypolice, txp, couleur[ tagc_GriseM ] ) ;
            SDL_BlitSurface( texte, NULL, ecran, &position ) ;
            if( m == mamy[ shift_space ].me.choix )
                Line(ecran,position.x-wintinypolicesize/2,position.y+wintinypolicesize,position.x+(wintinypolicesize)/2 ,position.y+wintinypolicesize,0xaabbcc00);
            position.x -= mytinypolicesize - 1.5*m ; //- 3 ;
      //      position.x+=mysupertinypolicesize ;
            if( click_F3 == 1 )
            {
                position.y += mysupertinypolicesize + 2 ;

                position.x += 1 ;
                position.y -= 1 ;

                SDL_FreeSurface( texte ) ;
                texte = TTF_RenderText_Blended( supertinypolice, mamy[ shift_space ].me.txt[ m ], couleur[ tagc_Noire ] ) ;
                SDL_BlitSurface( texte, NULL, ecran, &position ) ;

                position.x -= 1 ;
                position.y += 1 ;


                SDL_FreeSurface( texte ) ;
                texte = TTF_RenderText_Blended( supertinypolice, mamy[ shift_space ].me.txt[ m ], couleur[ tagc_Pink ] ) ;
                SDL_BlitSurface( texte, NULL, ecran, &position ) ;


          //      position.x-=mysupertinypolicesize ;
                position.y -= mysupertinypolicesize - 2 ;
            }

        }


        position.y = 62    ;
        position.x -= mypolicesize  ;

        SDL_BlitSurface( app_g[6], NULL, ecran, &position ) ;

        SDL_FreeSurface( texte ) ;
        txp[ 0 ] = mamy[ shift_space ].me.t[ mamy[ shift_space ].me.choix ] ;
        txp[ 1 ] = 0 ;
        //tx*[ 2 ] = 0 ;
    //        tx[ 3 ] = 0 ;

        double_ = 7*(mamy[ shift_space ].me.c[ mamy[ shift_space ].me.choix ] - mamy[ shift_space ].me.m) ;
        double_ /= (mamy[ shift_space ].me.p - mamy[ shift_space ].me.m) ;
        double_ *= mypolicesize ;
        position.x +=  (int) double_  ;
        position.y -= 2*mypolicesize/5 ;//////////////////////////////// L A B Y
        //position.x += double_ ;

        texte = TTF_RenderText_Blended( police, txp, couleur[ tagc_Jaune ] ) ;
        SDL_BlitSurface( texte, NULL, ecran, &position ) ;

        position.y += 2*mypolicesize/5 ;//////////////////////////////// L A B Y
        position.x -=  double_  ;
    }

    k=0;
    l=0;
    i=0;
///////////////////////////:



//    if(en_mouvement)
    {
  //      cumulvitesse=cumulvitesse+vitesse*tick ;
    }
//largeur_laby_choisi
//largeur_aff_laby
//longueur_laby_choisi
//longueur_aff_laby
    if( abs(dsx - xh) > 8)
        dsx += 1 ;
    if( abs(dsx - xh) < 3)
        dsx -= 1 ;
    if( abs(dsy - yh) > 5)
        dsy += 1 ;
    if( abs(dsy - yh) < 2)
        dsy -= 1 ;

    if( dsx > (35-13) ) dsx = 35-13;
    if( dsx < 0 ) dsx = 0 ;
    if( dsy > (45-8) ) dsy = 45-8 ;
    if( dsy < 0 ) dsy = 0 ;


//if( dsx - xh < -2)
  //  dsx += 1 ;

for( k = 0 ; k < 13+4 ; k++ )
    for( l = 0 ; l < 8+2 ; l++ )
    {
        position.x=ecran-> w/2 + 32 * k + 16 + 3*16 ;
        position.y=ecran-> h/2 + 32 * l + 16 + 2*16 ;
        if( l+dsy < 45 && k+dsx < 35 )
        {
            if( scene[l+dsy][k+dsx] == tag_mur || scene[l+dsy][k+dsx] == 4 )
            {
                sdl_rect.x = 32 * ( tag_xmur - 0 ) ;
                sdl_rect.y = 32 * ( tag_ymur - 0 ) ;
            }

            if( scene[l+dsy][k+dsx] == tag_sol2 )
            {
                if( lkiunit == tag_Minfini )
                {
                    sdl_rect.x = 32 * ( tag_xsol2 - 0 ) ;
                    sdl_rect.y = 32 * ( tag_ysol2 - 0 ) ;
                }
                else
                {
                    sdl_rect.x = 32 * ( tag_xsol - 0 ) ;
                    sdl_rect.y = 32 * ( tag_ysol - 0 ) ;
                }
            }

            if(scene[ l + dsy ][ k + dsx ] == tag_truc )
            {

                sdl_rect.x = 32 * ( tag_xsol - 0 ) ;
                sdl_rect.y = 32 * ( tag_ysol - 0 ) ;
                SDL_BlitSurface( app_g[3], &sdl_rect, ecran, &position ) ;

                sdl_rect.x = 32 * ( tag_xtruc - 0 ) ;
                sdl_rect.y = 32 * ( tag_ytruc - 0 ) ;
            }
            if(scene[ l + dsy ][ k + dsx ] == tag_sol )
            {
                sdl_rect.x = 32 * ( tag_xsol - 0 ) ;
                sdl_rect.y = 32 * ( tag_ysol - 0 ) ;
            }
            if(scene[ l + dsy ][ k + dsx ] == tag_potion )
            {
                sdl_rect.x = 32 * ( tag_xsol - 0 ) ;
                sdl_rect.y = 32 * ( tag_ysol - 0 ) ;
                SDL_BlitSurface( app_g[3], &sdl_rect, ecran, &position ) ;

                sdl_rect.x = 32 * ( tag_x_potion - 0 ) ;
                sdl_rect.y = 32 * ( tag_y_potion - 0 ) ;
            }
            SDL_BlitSurface( app_g[3], &sdl_rect, ecran, &position ) ;
            if(  l + dsy == yh && k + dsx == xh )
            {
                sdl_rect.x = 32 * ( tag_xh + add_tag_hero_xh - 0 ) ;
                sdl_rect.y = 32 * ( tag_yh + add_tag_hero_yh - 0 ) ;
                SDL_BlitSurface( app_g[3], &sdl_rect, ecran, &position ) ;

            }
        }
    }
// on affiche le compagnon
    if( dsx < xh_+ 1 && dsx + 8 > xh_ && dsy < yh_ + 1 && dsy + 13 > yh_)
    {
        if( xh==xh_ && yh==yh_ ) xh_++;
        position.x=ecran-> w/2 + 32 * ( xh_- dsx ) + 16 + 3*16 ;
        position.y=ecran-> h/2 + 32 * ( yh_- dsy ) + 16 + 2*16 ;
        sdl_rect.x = 32 * ( tag_xh_ + add_tag_hero_xh_ - 0 ) ;
        sdl_rect.y = 32 * ( tag_yh_ + add_tag_hero_yh_ - 0 ) ;
        SDL_BlitSurface( app_g[ 3 ], &sdl_rect, ecran, &position ) ;
    }
       // position.x=ecran->w/2+32*xh+16;
      //  position.y=ecran->h/2+32*yh+16;
    //    sdl_rect.x=32*(tag_xh-0);
//        sdl_rect.y=32*(tag_yh-0);

  //      SDL_BlitSurface( app_g[3], &sdl_rect, ecran, &position ) ;

        Line( ecran, (int) ((phi+1)*10+1), (int) (10*phi), (int) ((phi+1)*10+233*phi), (int) (10*phi), 0x00AA6699 ) ;

        if ( spiralk < 0 || spiralk > 31416 )
            spiralk = 0 ;
        else spiralk += 3 ;
        spiral( ecran,(int) windx/phi,(int) windy/phi ,20 ,2 , spiralk ,0x00123456 ) ;

   /*     if ( vxh==-1 )
        {

            xh-- ;
            vxh = -1 ;
            if( scene[yh][xh] == 1 )
              {
                xh++ ;
                vxh++;
                }
            if( scene[yh][xh] == 4 )
            {
                scene[ yh ][ xh++ ] = 3 ;
                vxh = 0 ;
            }
            if( scene[yh][xh] == 3 )
            {
                scene[yh][xh++] = 2 ;
                xh--;
//                                    vxh/=2 ;
                //gloo glouu
                //potion_verte + 1 ;
            }
        }*/


//////////////////////////////////////
        if( click_F10 == 1 )
        {
            position.x = 18*phi + 1 ;//60;
            position.y = windy - mypolicesize ;//60;

            sprintf( ko3, "%12f", alg_eva(kotxt) ) ; //1/(mamy[1].me.m/M_PI/M_PI-20.95));
            SDL_FreeSurface( texte ) ;
    //        ko3[ 24 ] = 0 ;
            texte = TTF_RenderText_Blended(tinypolice, ko3, couleur[tagc_GriseM]);
    //        texte = TTF_RenderText_Blended(tinypolice, mamy[ tag_Pi0 ].me.txt[ 3 ], couleur[tagc_GriseM]);
            SDL_BlitSurface(texte, NULL, ecran, &position);
        }




        if( click_F1 == 1 )
        {
                position.x = windx/2 - app_g[8]-> w / 2 ;
                position.y = windy/2 - app_g[8]-> h /2 ;
                SDL_BlitSurface( app_g[ 8 ], NULL, ecran, &position ) ;
        }
        if( click_shift_F1 == 1 )
        {
//                position.x = mypolicesize*2 ;// windx/2 - app_g[8]-> w /2 ;
                position.x = 8 ;// windx/2 - app_g[8]-> w /2 ;
                position.y = mypolicesize ;// *2 - 1 ;// windy/2 - app_g[8]-> h /2 ;
                SDL_BlitSurface( app_g[ 10 ], NULL, ecran, &position ) ;
        }
 /*       if( tag_chargement || tag_sauvegarde )
        {
//                position.x = mypolicesize*2 ;// windx/2 - app_g[8]-> w /2 ;
                position.x =  windx/2 - app_g[11]-> w /2 ;
                position.y =  windy/2 - app_g[11]-> h /2 ;
                SDL_BlitSurface( app_g[ 11 ], NULL, ecran, &position ) ;
        }
*/
        if( click_shift_F2 == 1 || tag_chargement || tag_sauvegarde)
        {
//                position.x = mypolicesize*2 ;// windx/2 - app_g[8]-> w /2 ;
                position.x =  windx/2 - app_g[11]-> w /2 ;
                position.y =  windy/2 - app_g[11]-> h /2 ;
                SDL_BlitSurface( app_g[ 11 ], NULL, ecran, &position ) ;
                ko3[ 1024 ] = 'a' ;
                ko3[ 1025 ] =  0  ;

                l = 0 ;
                position.x += mypolicesize ;
                for( ; l<26 ; l++ )
                {
                    if( aec_min_name[l] != 0 || l == 0 || l == 14 )
                    {
                        ko3[1024]= (char) 'a'+l ;
                        position.y += mypolicesize ;
                        SDL_FreeSurface(texte) ;
                        position.x -= 1 ;
                        position.y += 1 ;
                        texte = TTF_RenderText_Blended( police, ko3+1024, couleur[tagc_GriseM] ) ;
                        SDL_BlitSurface( texte, NULL, ecran, &position ) ;
                        position.x += 1 ;
                        position.y -= 1 ;
                        SDL_FreeSurface(texte);
                        texte = TTF_RenderText_Blended( police, ko3+1024, couleur[tagc_GriseF] ) ;
                        SDL_BlitSurface( texte, NULL, ecran, &position ) ;

                        int_= -1 ;
                        if( l == 0 )  // on affiche la lettre grec alpha
                            int_ = 0 ;
                        if( l == 14 )  // on affiche la lettre grec pi
                            int_ = 15 ;

                        if( int_ != -1 )  // on affiche la lettre grec alpha
                        {
                            txgrec[0] += (char) int_ ;
                            position.x += mypolicesize*1.5 ;
                            position.x -= 1 ;
                            position.y += 1 ;
                            texte = TTF_RenderUNICODE_Blended( police, (Uint16 *) txgrec, couleur[tagc_GriseM] ) ;
                            SDL_BlitSurface( texte, NULL, ecran, &position ) ;
                            position.x += 1 ;
                            position.y -= 1 ;

                            SDL_FreeSurface(texte);
                            texte = TTF_RenderUNICODE_Blended( police, (Uint16 *) txgrec, couleur[tagc_GriseF] ) ;
                            SDL_BlitSurface( texte, NULL, ecran, &position ) ;
                            position.x -= mypolicesize*1.5 ;
                            txgrec[0] -= (char) int_ ;
                        }
                        else
                        {
                            if( aec_min_name[l] != 0 )
                            {
//                                position.x += mypolicesize*1.5 + mytinypolicesize*(10-strlen(aec_min_name[l]))/2 ;
                                position.x += mypolicesize*1.5 ;

                                position.x -= 1 ;
                                position.y += 1 ;
                                texte = TTF_RenderText_Blended( tinypolice, aec_min_name[l], couleur[tagc_GriseM] ) ;
                                SDL_BlitSurface( texte, NULL, ecran, &position ) ;
                                position.x += 1 ;
                                position.y -= 1 ;
                                SDL_FreeSurface(texte);
                                texte = TTF_RenderText_Blended( tinypolice, aec_min_name[l], couleur[tagc_GriseF] ) ;
                                SDL_BlitSurface( texte, NULL, ecran, &position ) ;
                                if(l != 'k'-'a' && l != 'l'-'a' && l != 'q'-'a' )
                                {
                                    int_ = texte->w ;
                                    position.x += int_ ;
                                    SDL_FreeSurface(texte);
                                    ko3[127] = '(';
                                    ko3[128] = aec_min_tag_choix[l];
                                    ko3[129] = ')';
                                    ko3[130] = 0 ;

                                    //texte = TTF_RenderText_Blended( tinypolice, aec_min_tag_choix[l], couleur[tagc_GriseF] ) ;
                                    texte = TTF_RenderText_Blended( supertinypolice, ko3+127, couleur[tagc_GriseF] ) ;
                                    //texte = TTF_RenderText_Blended( supertinypolice, "(.)", couleur[tagc_GriseF] ) ;
                                    SDL_BlitSurface( texte, NULL, ecran, &position ) ;
                                    position.x -= int_ ;
                                }

//                                position.x -= mypolicesize*1.5 + mytinypolicesize*(10-strlen(aec_min_name[l]))/2 ;
                                position.x -= mypolicesize*1.5 ;
                            }
                        }
                        /////////////affiche la valeur
                        sprintf( (ko3+127),"%.8f",alg_expr_cst_minuscule[l] );

                        texte = TTF_RenderText_Blended( tinypolice, ko3+127, couleur[tagc_GriseF] ) ;
                        //texte = TTF_RenderText_Blended( supertinypolice, "(.)", couleur[tagc_GriseF] ) ;
                        position.x += mytinypolicesize*10 ;
                        SDL_BlitSurface( texte, NULL, ecran, &position ) ;
                        position.x -= mytinypolicesize*10 ;
                    }
                }

//                position.x =  windx/2 + app_g[11]-> w /4 + mypolicesize/2 ;
                position.x =  windx/2 + app_g[11]-> w /6;// + mypolicesize/2 ;
                position.y =  windy/2 - app_g[11]-> h /2 ;
                ko3[ 1024 ] = 'A' ;
                ko3[ 1025 ] =  0  ;

                l = 0 ;
//                position.x += mypolicesize ;
                for( ; l<26 ; l++ )
                {
                    if( aec_maj_name[l] != 0 || l == 15 )
                    {
                        ko3[1024]= (char) 'A'+l ;
                        position.y += mypolicesize ;
                        SDL_FreeSurface(texte) ;
                        position.x -= 1 ;
                        position.y += 1 ;
                        texte = TTF_RenderText_Blended( police, ko3+1024, couleur[tagc_GriseM] ) ;
                        SDL_BlitSurface( texte, NULL, ecran, &position ) ;
                        position.x += 1 ;
                        position.y -= 1 ;

                        SDL_FreeSurface(texte);
                        texte = TTF_RenderText_Blended( police, ko3+1024, couleur[tagc_GriseF] ) ;
                        SDL_BlitSurface( texte, NULL, ecran, &position ) ;

                        if( l == 15 )  // on affiche la lettre grec phi
                        {
                            position.x += 3*mypolicesize/2 ;
                            position.x -= 1 ;
                            position.y += 1 ;
                            texte = TTF_RenderUNICODE_Blended( police, (Uint16 *) tx, couleur[tagc_GriseM] ) ;
                            SDL_BlitSurface( texte, NULL, ecran, &position ) ;
                            position.x += 1 ;
                            position.y -= 1 ;

                            SDL_FreeSurface(texte);
                            texte = TTF_RenderUNICODE_Blended( police, (Uint16 *) tx, couleur[tagc_GriseF] ) ;
                            SDL_BlitSurface( texte, NULL, ecran, &position ) ;
                            position.x -= 3*mypolicesize/2 ;

                        }
                        else
                        {
                            if( aec_maj_name[l] != 0 )
                            {
                                position.x += mypolicesize*1.5 ;
                                position.x -= 1 ;
                                position.y += 1 ;
                                texte = TTF_RenderText_Blended( tinypolice, aec_maj_name[l], couleur[tagc_GriseM] ) ;
                                SDL_BlitSurface( texte, NULL, ecran, &position ) ;
                                position.x += 1 ;
                                position.y -= 1 ;

                                SDL_FreeSurface(texte);
                                texte = TTF_RenderText_Blended( tinypolice, aec_maj_name[l], couleur[tagc_GriseF] ) ;
                                SDL_BlitSurface( texte, NULL, ecran, &position ) ;
                                position.x -= mypolicesize*1.5 ;
                            }
                        }
                                                /////////////affiche la valeur
                        if( l == 'D'-'A' )
                            sprintf( (ko3+127),"%.9f",alg_expr_cst_majuscule[l] );

                        if( l == 'M'-'A' )
                            sprintf( (ko3+127),"%.1f",alg_expr_cst_majuscule[l] );
                        else
                            if( l != 'D'- 'A' )
                            sprintf( (ko3+127),"%.6f",alg_expr_cst_majuscule[l] );

                        SDL_FreeSurface(texte);
                        texte = TTF_RenderText_Blended( tinypolice, ko3+127, couleur[tagc_GriseF] ) ;
                        //texte = TTF_RenderText_Blended( supertinypolice, "(.)", couleur[tagc_GriseF] ) ;
                        position.x += mytinypolicesize*8 ;
                        SDL_BlitSurface( texte, NULL, ecran, &position ) ;
                        position.x -= mytinypolicesize*8 ;

                    }
                }

        }

        if( tag_chargement )
        {
                position.x =  windx/2 - 8*mypolicesize ; // - app_g[11]-> w /2-64*mypolicesize ;
                position.y =  windy/2 - app_g[11]-> h /2 + mypolicesize ;
                if( tag_chargement==1 )
                {
                   SDL_FreeSurface(texte);
                   texte = TTF_RenderText_Blended( police, "chargement de ", couleur[tagc_GriseF] ) ;
                   SDL_BlitSurface( texte, NULL, ecran, &position ) ;
                }
//               position.x +=  (strlen("chargement de "))*(mypolicesize-2);
                int_ = texte->w ;
                position.x += int_ ;
                position.x -= 1 ;
                position.y += 1 ;
                SDL_FreeSurface(texte);
                texte = TTF_RenderText_Blended( police, kotxt, couleur[tagc_GriseF] ) ;
                SDL_BlitSurface( texte, NULL, ecran, &position ) ;
                position.x += 1 ;
                position.y -= 1 ;
                SDL_FreeSurface(texte);
                if( tag_chargement == 2 )
                    texte = TTF_RenderText_Blended( police, kotxt, couleur[tagc_Vert] ) ;
                else
                    texte = TTF_RenderText_Blended( police, kotxt, couleur[tagc_GriseM] ) ;

                SDL_BlitSurface( texte, NULL, ecran, &position ) ;
                position.x -= int_ ;

        }

        if( tag_sauvegarde == 1 )
        {
               position.x =  windx/2 - 8*mypolicesize ; // - app_g[11]-> w /2-64*mypolicesize ;
               position.y =  windy/2 - app_g[11]-> h /2 + mypolicesize ;
               SDL_FreeSurface(texte);
               texte = TTF_RenderText_Blended( police, "sauvegarde de ", couleur[tagc_GriseF] ) ;
               SDL_BlitSurface( texte, NULL, ecran, &position ) ;
//               position.x +=  (strlen("chargement de "))*(mypolicesize-2);
               int_ = texte->w ;
               position.x += int_ ;
               SDL_FreeSurface(texte);
               texte = TTF_RenderText_Blended( police, kotxt, couleur[tagc_GriseF] ) ;
               SDL_BlitSurface( texte, NULL, ecran, &position ) ;
               position.x -= int_ ;

        }

        if( tag_chargement || tag_sauvegarde )
        {
               position.x =  windx/2 - 10*mypolicesize ; // - app_g[11]-> w /2-64*mypolicesize ;
               position.y =  windy/2 - app_g[11]-> h /2 + 3*mypolicesize ;

               k = nb_choix_load-1 ;
               while( k != -1 )
               {

                    position.x -= 1 ;
                    position.y += 1 ;
                    SDL_FreeSurface(texte);
                    texte = TTF_RenderText_Blended( police, choix_loadp[k], couleur[tagc_GriseF] ) ;
                    SDL_BlitSurface( texte, NULL, ecran, &position ) ;
                    position.x += 1 ;
                    position.y -= 1 ;
                    SDL_FreeSurface(texte);
                    texte = TTF_RenderText_Blended( police, choix_loadp[k], couleur[tagc_Vert] ) ;
                    SDL_BlitSurface( texte, NULL, ecran, &position ) ;


                    position.y += mypolicesize ;
                    k-- ;
               }
        }
/////////////////////////////////
//        SDL_Delay( 4 ) ;

//FLIP:
//        while( SDL_PollEvent( &event ) );
//        SDL_Delay( 20 ) ;

        SDL_Flip( ecran ) ;

    }

    TTF_CloseFont( police ) ;
    TTF_CloseFont( tinypolice ) ;
    TTF_CloseFont( supertinypolice ) ;

    TTF_Quit( ) ;

    SDL_FreeSurface( texte ) ;
    SDL_FreeSurface( ecran ) ;
//    SDL_FreeSurface( icon_fil ) ;
//    SDL_FreeSurface( icon_mf ) ;

    k = 0 ;
    while( k < nbe_g ) //while(k<K_app_g)
        SDL_FreeSurface( app_g[ k++ ] ) ;
    IMG_Quit( ) ;
    free( cap ) ;
    free( memoire_sauvegarde_choix ) ;

    SDL_Quit( ) ;
    return EXIT_SUCCESS;
}
