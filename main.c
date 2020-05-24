#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tercih=0,toplamvekil=0,geneltoplamoy=0;
    do
    {
    int d=0,gecici=0,kontenjansayisi=0,c=0,maxsayi=0,toplamoy=0,i=0,j=0,partisayisi=0,plakakodu=0,vekilkontenjan=0,a=0;
    float gecici3=0;
    char gecici2;
    char b[23]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','R','S','T','U','V','Y','Z'};
    printf("Secime Katilan Parti Sayisi Giriniz:");
    scanf("%d",&partisayisi);
    int oysayisi[partisayisi];
    float oyyuzdesi[partisayisi];
    int mvsayisi[100]={0};

    printf("Ilin Plaka Kodunu Giriniz:");
    scanf("%d",&plakakodu);
    printf("Ilin Milletvekili Kontenjanini Giriniz:");
    scanf("%d",&vekilkontenjan);
    kontenjansayisi=vekilkontenjan;
    b[0]='A';
    for(a=0;a<partisayisi;a++)
    {
        printf(" %c Partisinin Oy Sayisini Giriniz:",b[a]);
        scanf("%d",&oysayisi[a]);
    }
       maxsayi=oysayisi[0];
       if(kontenjansayisi>0) //milletvekili hesabi
        {

            for(c=kontenjansayisi-1;c>0;c--)
            {
                for(d=0;d<kontenjansayisi;d++)
                {
                if(oysayisi[d+1]>oysayisi[d])
                {
                    maxsayi=oysayisi[d+1];
                    maxsayi=(maxsayi/2);
                    mvsayisi[d]=(mvsayisi[d]+1);
                    kontenjansayisi=kontenjansayisi-1;
                }
                else
                {
                maxsayi=oysayisi[d];
                maxsayi=(maxsayi/2);
                mvsayisi[d]=(mvsayisi[d]+1);
                kontenjansayisi=kontenjansayisi-1;
                }
                }

            }

        }

    for(i=0;i<partisayisi;i++)
        {
        toplamoy=toplamoy+oysayisi[i];
        }
    c=100;
    for(i=0;i<partisayisi;i++) //yuzde hesabi
        {
          oyyuzdesi[i]=((float)c/((float)toplamoy/(float)oysayisi[i]));
        }

    for(i=0; i<partisayisi-1;i++) //partileri siralama kabarcik yontemi
    {
        for(j=i+1; j<partisayisi; j++)
        {

                if(oysayisi[j] > oysayisi[i])
            {
                gecici = oysayisi[i];
                oysayisi[i] = oysayisi[j];
                oysayisi[j] = gecici;

                gecici2=b[i];
                b[i]=b[j];
                b[j]=gecici2;

                gecici3=oyyuzdesi[i];
                oyyuzdesi[i]=oyyuzdesi[j];
                oyyuzdesi[j]=gecici3;

            }
        }
    }

    printf("Ilin Plaka Kodu:%d\n",plakakodu);
    printf("Ilin Milletvekili Kontenjani:%d\n",vekilkontenjan);
    printf("Gecerli Oy Sayisi:%d\n",toplamoy);
    printf("Parti Adi\t Oy Sayisi\t Oy Yuzdesi\t\t MV Sayisi\n\n");
    printf("---------\t ----------\t ---------\t\t ---------\t\n");

    for(i=0;i<partisayisi;i++)
        {
            printf("%c Partisi\t Oy Sayisi:%d\t Oy Yuzdesi:%.2f\t MV Sayisi:%d\n",b[i],oysayisi[i],oyyuzdesi[i],mvsayisi[i]);
        }
        toplamvekil=(toplamvekil+vekilkontenjan);
        geneltoplamoy=(geneltoplamoy+toplamoy);
        printf("Baska Parti Girisi Olacak Mi?\n(Evet:0 Hayir:1)");
        scanf("%d",&tercih);
    }while(tercih==0);
    printf("\n");
    printf(" Turkiye Geneli\n Toplam Milletvekili Kontenjani:%d\n Toplam Gecerli Oy Sayisi:%d\n",toplamvekil,geneltoplamoy);
    return 0;
}
