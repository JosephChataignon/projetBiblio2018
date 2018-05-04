#include "cassebrique.h"

#include <QTimer>
#include <QDebug>
#include <thread>

cassebrique::cassebrique(){
    tabMur.push_back(new mur(murGauche,murHaut,0,true));
    tabMur.push_back(new mur(murDroite,murHaut,0,true));
    tabMur.push_back(new mur(murGauche,murHaut,0,false));
    tabMur.push_back(new mur(murGauche,murBas,0,false,true));
    barre =new palet(0,-75,0);
    fond_=new fond(0,-67,0,murGauche,murDroite+10,-10,147.0f);
    current_balle=new balle(0,-65,0,5);
    score_=0;
    nbBalle=3;
    niveau_=1;
    nouvelleBalle();
    nouveauNiveau();
}

void cassebrique::affichage(){
    for(int i=0;i<tabBrique.size();i++){
       if(tabBrique[i]->isPresente()){
           tabBrique[i]->displayBrique();
       }
    }
    for(int i=0;i<tabMur.size();i++){
       tabMur[i]->displayMur();
    }
    barre->displayPalet();
    fond_->displayFond();
    current_balle->displayBalle();

}

void cassebrique::animation(float vX){
    // Mouvement du palet
    if(vitessePalet > 0){vitessePalet -= 2; }else{ vitessePalet += 2; }
    vitessePalet +=vX;
    if(vitessePalet > 25){ vitessePalet = 25; }else if(vitessePalet < -25){ vitessePalet = -25; }
    if(( barre->getXPalet()-30+vitessePalet <= murGauche )||( barre->getXPalet()+30+vitessePalet >= murDroite )){
        vitessePalet = -vitessePalet;
    }
    barre->movePalet(vitessePalet);

    // Mouvement de la balle
    float xBalle = current_balle->getXBalle();
    float yBalle = current_balle->getYBalle();
    float xPalet = barre->getXPalet();
    xBalle += vitesseBalleX;
    yBalle += vitesseBalleY;

    // Collisions de la balle avec les murs, le palet et les briques
    if( yBalle+5 >= murHaut-5 ){ vitesseBalleY = -vitesseBalleY; }
    if( xBalle+5 >= murDroite-5 ){ vitesseBalleX = -vitesseBalleX; }
    if( xBalle-5 <= murGauche+15 ){ vitesseBalleX = -vitesseBalleX; }
    if( yBalle-5 <= -70 && yBalle-5 >= -71 && xPalet-xBalle<35 && xPalet-xBalle>-35 && vitesseBalleY<0 ){
        vitesseBalleY = -vitesseBalleY;
        vitesseBalleX += (xBalle-xPalet)*0.5;
    }
    if( yBalle-5 <= murBas+5 ){
        nbBalle -= 1;
        xBalle=0;
        yBalle=-65;
        nouvelleBalle();
    }
    bool aRebondi = false;
    for(int i=0;i<tabBrique.size();i++){
       if(tabBrique[i]->isPresente()){
           rebondBrique(tabBrique[i],xBalle,yBalle);
       }
    }

    current_balle->setXBalle(xBalle);
    current_balle->setYBalle(yBalle);

}

void cassebrique::nouvelleBalle(){

    newBall=true;
    vitessePalet=0;
    vitesseBalleY = 5;
    vitesseBalleX = rand()%5-2.5;
    if(vitesseBalleX==0){vitesseBalleX+=1;}
    barre->setXPalet(0);

    if(nbBalle <= 0){
        niveau_=1;
        score_=0;
        nouveauNiveau();
    }
}

void cassebrique::nouveauNiveau(){
    //par défaut
    tabBrique.clear();
    for(int j=0;j<8;j++){
        for(int i=0;i<10;i++){
           tabBrique.push_back(new brique(-155+30*i,65-j*10,0,0.0f,30,0.0f,10));
        }
    }
}


void cassebrique::rebondBrique(brique* b, float xBalle, float yBalle){
    float xmin = b->getX(); float xmax = b->getX()+30;
    float ymin = b->getY(); float ymax = b->getY()+30;
    bool rebond = false;
    if(yBalle+5>=ymin && yBalle+5<ymax && xBalle>xmin && xBalle<xmax){
        vitesseBalleY = -vitesseBalleY;
        rebond = true;
    }


    if(rebond){
        b->setPresente(false);
        score_ += 1;
        //TODO - vérifier si c'est la dernière brique du niveau
    }
}
