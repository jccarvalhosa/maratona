#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int x,y,r,p,q,a,t,dentro, intersepta1, intersepta2;
    float ST, S1,S2,h1,h2,teta1,teta2, sena, cosa,senat,cosat,ang1,ang2,angcentro, angtg1, angtg2, angdif;
    while(1){
        scanf("%d %d %d",&x,&y,&r);
        getchar();
        if(x==0 && y==0 && r==0) return 0;
        scanf("%d %d %d %d",&p,&q,&a,&t);
        ST = 4 * atan(1) * r * r;
        ang1 = a - t/2.0;
        ang2 = a + t/2.0;        
        if(ang1 < 0) ang1 += 360;
        if(ang2 >= 360) ang2 -= 360;
        if(ang2 < ang1){
			angdif = ang2;
			ang2 = ang1;
			ang1 = angdif;
		}
        sena = sin(ang1 * atan(1) / 45);
        cosa = cos(ang1 * atan(1) / 45);
        senat = sin(ang2 * atan(1) / 45);
        cosat = cos(ang2 * atan(1) / 45); 
        
        if(x-p == 0){
			if(y-q > 0) angcentro = 90;
			else angcentro = 270;
		}
		else{
			angcentro = atan((float)(y-q)/(x-p)) * 45 / atan(1);
			if(x-p < 0) angcentro += 180;
			else if(y-q < 0) angcentro += 360;
		}

		angdif = asin((float)r/ sqrt((y-q)*(y-q) + (x-p)*(x-p))) * 45 / atan(1);
		angtg1 = angcentro - angdif;
		if(angtg1 < 0) angtg1 += 360;
		angtg2 = angcentro + angdif;
		if(angtg2 > 360) angtg2 -= 360;
		if(angtg2 < angtg1){
			angdif = angtg2;
			angtg2 = angtg1;
			angtg1 = angdif;
		}
		
		if(ang2 - ang1 < 180){
			if((angcentro <= ang1 && angcentro <= ang2) || (angcentro >= ang1 && angcentro >= ang2)) dentro = 0;
			else dentro = 1;
		}
		else{
			if(angcentro <= ang1 || angcentro >= ang2) dentro = 1;
			else dentro = 0;
		} 
		if(angtg2 - angtg1 <= 180){
			if((ang1 <= angtg1 && ang1 <= angtg2) || (ang1 >= angtg1 && ang1 >= angtg2)) intersepta1 = 0;
			else intersepta1 = 1;
			if((ang2 <= angtg1 && ang2 <= angtg2) || (ang2 >= angtg1 && ang2 >= angtg2)) intersepta2 = 0;
			else intersepta2 = 1;
		}
		else{
			if(ang1 <= angtg1 || ang1 >= angtg2) intersepta1 = 1;
			else intersepta1 = 0;
			if(ang2 <= angtg1 || ang2 >= angtg2) intersepta2 = 1;
			else intersepta2 = 0;
		} 
        h1 = fabs((y-q) * cosa - (x-p) * sena);
        h2 = fabs((y-q) * cosat - (x-p) * senat);

        if(h1 < r && intersepta1){
              if(h1 == 0)  teta1 = 4 * atan(1);
              else{
				  teta1 = acos(h1/r);
			  }
			  S1 = r * r * (teta1  - sin(2 * teta1))/2;
        }
        else S1 = 0;
        
        if(h2 < r && intersepta2){
              if(h2 == 0) teta2 = 4 * atan(1);
              else{
				  teta2 = acos(h2/r);
			  }
			  S2 = r * r * (teta2  - sin(2 * teta2))/2; 
        }
        else S2 = 0;
        
        if(dentro == 1) printf("%.1f\n", ST - S1 - S2);
        else printf("%.1f\n", fabs(S1 - S2));
        
        /*
        printf("ang1 = %f\n", ang1);
        printf("ang2 = %f\n", ang2);
        printf("angcentro = %f\n", angcentro);
        printf("angtg1 = %f\n", angtg1);
        printf("angtg2 = %f\n", angtg2);       
        printf("h1 = %f\n", h1);
        printf("teta1 = %f\n", teta1);
        printf("h2 = %f\n", h2);
        printf("teta2 = %f\n", teta2);
        printf("dentro: %d\n", dentro);
        printf("S1 = %f\n", S1);
        printf("S2 = %f\n", S2);
        printf("ST = %f\n", ST);
        */

        }
}
