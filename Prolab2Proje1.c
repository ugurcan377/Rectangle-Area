//      Prolab2Proje1.c
//      
//      Copyright 2011 Uğurcan <ugurcan@pavilion>
//      
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//      
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//      
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.
//      
//      


#include <stdio.h>

int main(int argc, char **argv)
{
	int dikdortgen=0;
	long int talan,kalan;
	int ksistem[1000][1000]={0};
	FILE *dosya;
	dosya=fopen("dikdortgen.dat","r");
	if (dosya == NULL) {
		printf("Dosya hatası : Lütfen giriş dosyanızı kontrol ediniz\n");
		return 0;
	}
	else {
		fscanf(dosya,"%d",&dikdortgen);
		if (dikdortgen > 100) {
			printf("Dikdörtgen sayisi 100'den büyük olamaz\n");
			return 0;
			}
		else
		{
			int a=0,i,j,k,xx1,xx2,yy1,yy2,x1[dikdortgen],x2[dikdortgen],y1[dikdortgen],y2[dikdortgen],kdik=0;
			for (i=0; i<dikdortgen; i++){
				fscanf(dosya,"%d %d %d %d\n",&xx1,&yy1,&xx2,&yy2);
				if (xx1<0 || xx1>1000 || xx2<0 || xx2>1000 || yy1<0 || yy1>1000 || yy2<0 || yy2>1000)
				{
					printf("Verilen koordinatlardan en az biri sınırların dışında lütfen kontrol ediniz.");
					return 0;
					}
				else {
					if (xx1 < xx2) {
						x1[i]=xx1;
						x2[i]=xx2;  
						}
					else {
						x1[i]=xx2;
						x2[i]=xx1;
						}
					if (yy2 < yy1) {
						y1[i]=yy1;
						y2[i]=yy2;					
					}
					else {
						y1[i]=yy2;
						y2[i]=yy1;
						}
				}
			}
			for (i=0;i<dikdortgen;i++){
				for (j=x1[i];j<=x2[i]-1;j++){
					for (k=y2[i];k<=y1[i]-1;k++){
						//printf("i=%d,j=%d k=%d \n",i,j,k);
						if (ksistem[j][k]>=1) {ksistem[j][k]=2; a=1;}
						if (ksistem[j][k]==0) {ksistem[j][k]=1;}
												}
					}
				if (a==1){
					if (kdik==0) {kdik+=2; }
					else kdik++;
					a=0;
					}
				}
				
				
			talan=0;
			kalan=0;
			for (i=0;i<1000;i++) {
				for (j=0;j<1000;j++){
					if (ksistem[i][j] > 0) {
					//	printf("Koordinatlar x= %d, y=%d \n",i,j);
						talan++;
						if (ksistem[i][j] > 1){
							kalan++;
							}
						}
					}
				}
			printf("Toplam alan = %d \nKesisen alan = %d \nKesismeyen dikdortgen sayisi = %d \n",talan,kalan,dikdortgen-kdik);
			}
	}
	
	return 0;
}

