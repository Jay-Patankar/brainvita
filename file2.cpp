
#include<simplecpp>
#include<vector>
class Grid{
  vector <Circle> circles;
  vector<int> fill;
  int marbles;
  public:
      Grid(){ marbles=32;
      for(int i=0;i<7;i++){
       circles.push_back(Circle(300+i*40,310,15)) ;fill.push_back(1);
      }
       for(int i=0;i<7;i++){
        circles.push_back(Circle(300+i*40,350,15)) ;fill.push_back(1);
       //info[Circle(300+i*40,350,15)]=1;
      }
       for(int i=0;i<7;i++){
        circles.push_back(Circle(300+i*40,390,15)) ;fill.push_back(1);
       //info[Circle(300+i*40,390,15)]=1;
      }
       for(int i=0;i<3;i++){
        circles.push_back(Circle(380+i*40,270,15)) ;fill.push_back(1);
       //info[Circle(380+i*40,270,15)]=1;
      }
      for(int i=0;i<3;i++){
        circles.push_back(Circle(380+i*40,230,15)) ;fill.push_back(1);
       //info[Circle(380+i*40,230,15)]=1;
      }
      /*for(int i=0;i<2;i++){
          circles.push_back(Circle(380+i*40,190,15)) ;fill.push_back(1);
       //info[Circle(380+i*40,190,15)]=1;
      }*/
      for(int i=0;i<3;i++){
          circles.push_back(Circle(380+i*40,430,15) );fill.push_back(1);
       //info[Circle(380+i*40,430,15)]=1;
      }
      for(int i=0;i<3;i++){
          circles.push_back(Circle(380+i*40,470,15)) ;fill.push_back(1);
       //info[Circle(380+i*40,470,15)]=1;
      }
      /*for(int i=0;i<2;i++){
          circles.push_back(Circle(380+i*40,510,15)) ;fill.push_back(1);
       //info[Circle(380+i*40,510,15)]=1;
      }
      for(map<Circle,int>::iterator i=info.begin();i<info.end();i++){
        i->first.imprint(); i->first.setColor(COLOR("green"));
        i->first.setFill(true);
      }*/
      for(int i=0;i<circles.size();i++){
       circles[i].imprint(); circles[i].setColor(COLOR("green"));
        circles[i].setFill(true);
      }
      circles[10].setFill(false); fill[10]=0;
      }


     bool perfectclk(int a,int b,int c,int d){
      return ((abs(c-a)<=110 and abs(c-a)>=50) || (abs(d-b)<=110 and abs(d-b)>=50));}

     bool correctclk(int x1,int y1,int x2,int y2){//cout<<"hi";
      // var=90;
       for(int i=0;i<circles.size();i++){
          int xc=circles[i].getX();  int yc=circles[i].getY();
          if((pow(x1-xc,2)+pow(y1-yc,2)<=225) && fill[i]==1){ //cout<<"hi";
             for(int j=0;j<circles.size();j++){
               int  xc2=circles[j].getX(); int  yc2=circles[j].getY();
                if((pow(x2-xc2,2)+pow(y2-yc2,2)<=225) && fill[j]==0
                    && (perfectclk(x1,y1,x2,y2))){//cout<<"hi";
                      takeaction(i,j); return true;
                }
             }

          }
       }
         return false;


     }

    /* bool perfectclk(int a,int b,int c,int d){
      return (abs(c-a)<=110 and abs(c-a)>=50) || (abs(d-b)<=110 and abs(d-b)>=50));





     }*/
    void takeaction(int i,int j){
       int midx=(circles[i].getX()+circles[j].getX())/2;
       int midy=(circles[i].getY()+circles[j].getY())/2;
       for(int t=0;t<circles.size();t++){
             if (circles[t].getX()==midx and circles[t].getY()==midy){
                circles[t].setFill(false);  fill[t]=0;
                circles[i].setFill(false); fill[i]=0;
                circles[j].setFill(true); fill[j]=1;
                marbles--;
                break;
             }

      }
      }  friend class Disk;
};



class Disk{// vq=0;
  Grid g;
  Circle* c1,*c2;
public:
  Disk(){//cout<<"in";
     c1=new Circle(420,350,200);
     c2=new Circle(420,350,240);}
//Text msg(75,250,"YOU WIN!! \n Click anywhere to exit");  msg.imprint();
  void process(int xx1,int yy1,int xx2,int yy2){
      if (!g.correctclk(xx1,yy1,xx2,yy2)){
       Text t(75,500,"Wrong clicks!!");   wait(2);
      }
  }
  void win(){//Text msg(75,250,"YOU WIN!! \n Click anywhere to exit");  msg.imprint();
    if (g.marbles==1) {                   Text msg(75,250,"YOU WIN!!");  msg.imprint();
                                           Text msg2(80,300,"Click anywhere to exit"); msg2.imprint();
     if (getClick()) exit(0);}
  }


};

int main()
{initCanvas("                BRAINVITA              ",700,700); Disk d;

Text mes(75,150,"Click on a marble") ;
mes.imprint();
 Text mes2(75,180,"and an empty place"); mes2.imprint();
 Text mes3(75,210,"to play your move"); mes3.imprint();
while(1){//var=12;
    d.win();
    int pos=getClick();     int pos2=getClick();
    d.process(pos/65536,pos%65536,pos2/65536,pos2%65536);

}

}
