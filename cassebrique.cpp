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
    if( yBalle+5 >= murHaut-5    && vitesseBalleY>0 ){ vitesseBalleY = -vitesseBalleY; }
    if( xBalle+5 >= murDroite-5  && vitesseBalleX>0 ){ vitesseBalleX = -vitesseBalleX; }
    if( xBalle-5 <= murGauche+15 && vitesseBalleX<0 ){ vitesseBalleX = -vitesseBalleX; }
    if( yBalle-5 <= -70 && yBalle-5 >= -71 && xPalet-xBalle<35 && xPalet-xBalle>-35 && vitesseBalleY<0 ){
        vitesseBalleY = -vitesseBalleY;
        vitesseBalleX += (xBalle-xPalet)*0.5;
    }

    bool aRebondi = false;
    for(int i=0;i<tabBrique.size();i++){
       if(tabBrique[i]->isPresente()){
           if(rebondBrique(tabBrique[i],xBalle,yBalle)){
               aRebondi = true;
           }
       }
    }

    if( yBalle-5 <= murBas+5 ){
        nbBalle -= 1;
        nouvelleBalle();
    }else if(!aRebondi){
        current_balle->setXBalle(xBalle);
        current_balle->setYBalle(yBalle);
    }

}

void cassebrique::nouvelleBalle(){

    newBall=true;
    current_balle->setXBalle(0);
    current_balle->setYBalle(-65);
    vitessePalet=0;
    vitesseBalleY = 2 + niveau_;
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
    //pour avoir seulement la brique du milieu
    for(int i=0;i<tabBrique.size();i++){
        if(i != 45){tabBrique[i]->setPresente(false);}
    }
    //pour avoir seulement les briques de la partie gauche
    /*for(int i=0;i<tabBrique.size();i++){
        if(tabBrique[i]->getX()>20){tabBrique[i]->setPresente(false);}
    }*/
}


bool cassebrique::rebondBrique(brique* b, float xBalle, float yBalle){
    float xmin = b->getX(); float xmax = xmin+30;
    float ymin = b->getY(); float ymax = ymin+10;
    bool rebond = false;
    if(yBalle+5>=ymin && yBalle+5<ymax && xBalle>xmin && xBalle<xmax && vitesseBalleY>0){
        vitesseBalleY = -vitesseBalleY;
        rebond = true;
    }else if(yBalle-5<=ymax && yBalle-5>ymin && xBalle>xmin && xBalle<xmax && vitesseBalleY<0){
        vitesseBalleY = -vitesseBalleY;
        rebond = true;
    }else if(xBalle+5>=xmin && xBalle+5<xmin+5 && yBalle>ymin && yBalle<ymax && vitesseBalleX>0){
        vitesseBalleX = -vitesseBalleX;
        rebond = true;
    }else if(xBalle-5<=xmax && xBalle-5>xmax-5 && yBalle>ymin && yBalle<ymax && vitesseBalleX<0){
        vitesseBalleX = -vitesseBalleX;
        rebond = true;
    }//TODO - rebond coins


    if(rebond){
        b->setPresente(false);
        score_ += 1;
        //TODO - vérifier si c'est la dernière brique du niveau
        bool derniere = true;
        for(int i=0;i<tabBrique.size();i++){
           if(tabBrique[i]->isPresente()){
               derniere = false;
               break;
           }
        }
        if(derniere){
            qInfo("fin niveau");
            niveau_ += 1;
            nouvelleBalle();
            nouveauNiveau();
        }
    }

    return rebond;
}
