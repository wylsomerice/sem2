#include "globals.h"
#include <QString>

Globals::Globals()
{

    int win1 = 0;
    int win2 = 0;
    int win3 = 0;
    int win4 = 0;
    int win5 = 0;
    int win6 = 0;
    int win7 = 0;
    int win8 = 0;

    int lose1 = 0;
    int lose2 = 0;
    int lose3 = 0;
    int lose4 = 0;
    int lose5 = 0;
    int lose6 = 0;
    int lose7 = 0;
    int lose8 = 0;

    int draw1 = 0;
    int draw2 = 0;
    int draw3 = 0;
    int draw4 = 0;
    int draw5 = 0;
    int draw6 = 0;
    int draw7 = 0;
    int draw8 = 0;

    int score1 = 0;
    int score2 = 0;
    int score3 = 0;
    int score4 = 0;
    int score5 = 0;
    int score6 = 0;
    int score7 = 0;
    int score8 = 0;


    int goals1 = rand()% 5;
    int goals2 = rand()% 5;
    while(goals2 > goals1)
    {
        goals2 = rand()% 5;
    }

    if(goals1>goals2){win1++; lose2++;
    }
    else if((goals1 = goals2)){draw1++; draw2++;
    }

    //MATCH_2

     int goals3 = rand()% 5;
     int goals4 = rand()% 5;
    while(goals3 > goals4)
    {
        goals4 = rand()% 5;
    }

    if(goals3<goals4){win4++; lose3++;
    }
    else if((goals3 = goals4)){draw3++; draw4++;
    }

    //MATCH_3

     int goals5 = rand()% 5;
     int goals6 = rand()% 5;
    while(goals5 > goals6)
    {
        goals6 = rand()% 5;
    }

    if(goals5<goals6){win6++; lose5++;
    }
    else if((goals5 = goals6)){draw5++; draw6++;
    }

    //MATCH_4

     int goals7 = rand()% 5;
     int goals8 = rand()% 5;
    while(goals7 > goals8)
    {
        goals8 = rand()% 5;
    }

    if(goals7>goals8){win7++; lose8++;
    }
    else if((goals7 = goals8)){draw7++; draw8++;
    }

    //MATCH_5

     int goals9 = rand()% 5;
     int goals10 = rand()% 5;
    while(goals9 < goals10)
    {
        goals10 = rand()% 5;
    }

    if(goals9>goals10){win1++; lose7++;
    }
    else if((goals9 = goals10)){draw1++; draw7++;
    }

    //MATCH_6

     int goals11 = rand()% 5;
     int goals12 = rand()% 5;
    while(goals11 < goals12)
    {
        goals12 = rand()% 5;
    }

    if(goals11>goals12){win4++; lose6++;
    }
    else if((goals11 = goals12)){draw4++; draw6++;
    }

    //MATCH_7

     int goals13 = rand()% 5;
     int goals14 = rand()% 5;
    while(goals13 < goals14)
    {
        goals14 = rand()% 5;
    }

    if(goals13>goals14){win4++; lose1++;
    }
    else if((goals13 = goals14)){draw1++; draw4++;
    }

     int global_goals1 = goals1 + goals9 + goals13;
     int global_goals2 = goals2;
     int global_goals3 = goals3;
     int global_goals4 = goals4 + goals9 + goals14;
     int global_goals5 = goals5;
     int global_goals6 = goals6 + goals12;
     int global_goals7 = goals7 + goals9;
     int global_goals8 = goals8;

     int global_passes1 = goals2 + goals10 + goals14;
     int global_passes2 = goals1;
     int global_passes3 = goals4;
     int global_passes4 = goals3 + goals12 + goals13;
     int global_passes5 = goals6;
     int global_passes6 = goals5 + goals11;
     int global_passes7 = goals8 + goals9;
     int global_passes8 = goals7;
}


/*
 extern int backend()

{
  int win1 = 0;
  int win2 = 0;
  int win3 = 0;
  int win4 = 0;
  int win5 = 0;
  int win6 = 0;
  int win7 = 0;
  int win8 = 0;

  int lose1 = 0;
  int lose2 = 0;
  int lose3 = 0;
  int lose4 = 0;
  int lose5 = 0;
  int lose6 = 0;
  int lose7 = 0;
  int lose8 = 0;

  int draw1 = 0;
  int draw2 = 0;
  int draw3 = 0;
  int draw4 = 0;
  int draw5 = 0;
  int draw6 = 0;
  int draw7 = 0;
  int draw8 = 0;

  int score1 = 0;
  int score2 = 0;
  int score3 = 0;
  int score4 = 0;
  int score5 = 0;
  int score6 = 0;
  int score7 = 0;
  int score8 = 0;

//DATA

  //MATCH_1

    int goals1 = rand()% 5;
    int goals2 = rand()% 5;
    while(goals2 > goals1)
    {
        goals2 = rand()% 5;
    }

    if(goals1>goals2){win1++; lose2++;
    }
    else if((goals1 = goals2)){draw1++; draw2++;
    }

    //MATCH_2

    int goals3 = rand()% 5;
    int goals4 = rand()% 5;
    while(goals3 > goals4)
    {
        goals4 = rand()% 5;
    }

    if(goals3<goals4){win4++; lose3++;
    }
    else if((goals3 = goals4)){draw3++; draw4++;
    }

    //MATCH_3

    int goals5 = rand()% 5;
    int goals6 = rand()% 5;
    while(goals5 > goals6)
    {
        goals6 = rand()% 5;
    }

    if(goals5<goals6){win6++; lose5++;
    }
    else if((goals5 = goals6)){draw5++; draw6++;
    }

    //MATCH_4

    int goals7 = rand()% 5;
    int goals8 = rand()% 5;
    while(goals7 > goals8)
    {
        goals8 = rand()% 5;
    }

    if(goals7>goals8){win7++; lose8++;
    }
    else if((goals7 = goals8)){draw7++; draw8++;
    }

    //MATCH_5

    int goals9 = rand()% 5;
    int goals10 = rand()% 5;
    while(goals9 < goals10)
    {
        goals10 = rand()% 5;
    }

    if(goals9>goals10){win1++; lose7++;
    }
    else if((goals9 = goals10)){draw1++; draw7++;
    }

    //MATCH_6

    int goals11 = rand()% 5;
    int goals12 = rand()% 5;
    while(goals11 < goals12)
    {
        goals12 = rand()% 5;
    }

    if(goals11>goals12){win4++; lose6++;
    }
    else if((goals11 = goals12)){draw4++; draw6++;
    }

    //MATCH_7

    int goals13 = rand()% 5;
    int goals14 = rand()% 5;
    while(goals13 < goals14)
    {
        goals14 = rand()% 5;
    }

    if(goals13>goals14){win4++; lose1++;
    }
    else if((goals13 = goals14)){draw1++; draw4++;
    }

    int global_goals1 = goals1 + goals9 + goals13;
    int global_goals2 = goals2;
    int global_goals3 = goals3;
    int global_goals4 = goals4 + goals9 + goals14;
    int global_goals5 = goals5;
    int global_goals6 = goals6 + goals12;
    int global_goals7 = goals7 + goals9;
    int global_goals8 = goals8;

    int global_passes1 = goals2 + goals10 + goals14;
    int global_passes2 = goals1;
    int global_passes3 = goals4;
    int global_passes4 = goals3 + goals12 + goals13;
    int global_passes5 = goals6;
    int global_passes6 = goals5 + goals11;
    int global_passes7 = goals8 + goals9;
    int global_passes8 = goals7;

    //DATA_END
*/

