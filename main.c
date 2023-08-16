#include <stdio.h>
#include <stdlib.h>

/*
    Bilgisayar Programciligi 1. Sinif, Programlama Temelleri 1. Sube

    220408011  -  Taha Gunes   ||   Vucut Kitle Indeksi Hesaplama Araci / Body Mass Index Calculator Tool

    Yetiskinler icin vucut kitle indeksi hesaplama araciyla kullanicidan alinan kilo ve boy degerleri, kisinin vki katsayisi hesaplamasinda kullanilir.
    Boy verisi, cm cinsinden alinir, 100'e bolunerek m cinsine cevrilir (Ör. 170 cm ==> 1.70 m). Vucut Kitle Indeksi katsayisi, fonksiyon kullanilarak
    VKI = Kilo / (Boy x Boy)  formulu ile hesaplanir. VKI katsayisina gore kisiler Zayif, Normal, Fazla Kilolu, I. Derece Obez, II. Derece Obez ve
    III. Derece Obez olmak uzere alti kategoriden birisine yerlestirilir. Sorgulama sonucunda kullanicilara, vucut kitle indeks degeri ve bu degere gore
    hangi kategoride olduklari bilgisi ile bazi yonlendirmeler ve tavsiye mesajlari da gosterilmektedir. Her hesaplamadan sonra kullanicilara yeni bir
    sorgulama yapmak isteyip istemedikleri sorulup kontrol edilir. Eger girilen veriler dogrultusunda yapilan hesaplama sonucu herhangi bir case
    degeriyle eslesmezse program, hata mesaji paylastiktan kisa bir sure sonra kendisini yeniden baslatir.
*/

    void vkiUYARI() {
    printf("\n\n\n\n\t\t\t\t\t\t\tONEMLI!");
    printf("\n\n\t\tBu olcek yetiskinler icindir, kas kutlesi ve yag dagilimini dikkate almamaktadir.");
    printf("\n\t\tAyrica cocuklar ve hamileler icin yapilacak olan hesaplamalarin isabetsiz");
    printf("\n\t\tolabilecegi goz onunde bulundurulmalidir.");
    printf("\n\n\t\tVucut Kitle Indeksi olcumu, bir kisinin kilogram cinsinden agirligini metre kare");
    printf("\n\t\tcinsinden boyuna bolerek 'saglikli' bir kiloda olup olmadigini belirleyen matematiksel");
    printf("\n\t\tbir formule dayanmaktadir ve yas, cinsiyet, genetik, beslenme, hayat tarzi, tibbi");
    printf("\n\t\tgecmis ya da diger faktorlerden bagimsiz olarak hesaplanmaktadir. VKI, kisinin");
    printf("\n\t\tsaglikli olup olmadigina karar vermek icin kullanilmamalidir.");
    }

    float vkiHESAP(float by, float kl) {
    float indx;
    by = by / 100;
    by = (by*by);
    indx = kl / by;
    return indx;
    }

int main()
{
    char secim;
    char arac[]="*\\-   Vucut Kitle Indeksi (VKI) Hesaplama Araci   -/*";
    int i;
    float boy, kilo, index;
    float vkiKategori1[6] = {(18.5), 25, 30, 35, 40, 80};
    char vkiKategori2[6][30] = {"Zayif", "Normal ('Saglikli')", "Fazla Kilolu", "I. Derece Obez", "II. Derece Obez", "III. Derece (Morbid) Obez"};

    do {
        secim = 'H';

        printf ("\n\t\t\t\t%s\n", arac);
        vkiUYARI();

        printf ("\n\n\tBoyunuz (cm):\n");
        scanf ("%f", &boy);

        printf ("\n\tKilonuz (kg):\n");
        scanf ("%f", &kilo);

        index = vkiHESAP(boy, kilo);

        for (i=0; i<6; i++) {

            if ((index < vkiKategori1[i])) {break;}
            else { continue; }
        }

        switch ((i+1)) {

            case 1:
                printf ("\n\n\t\tVucut Kitle Indeksiniz: \t%.1f", index);
                Sleep(1200);  //   Bazi noktalarda iki kod arasinda, programin belirli surelerde beklemesi istenmistir. Bunun icin, Sleep() fonksiyonu kullanilmistir (1 saniye = 1000 milisaniye).
                printf ("\n\t\t\t     Durumunuz: \t%s", vkiKategori2[i]);
                Sleep(1200);
                printf ("\n\n\tKilonuz normal degerlerin altinda.\n\tBu durumun sagliginiza olumsuz etkisi olabilecegini dusunuyorsaniz\n\tbir diyetisyene basvurmak isteyebilirsiniz.\n");

                printf ("\n\n\tYeni bir sorgulama yapmak istiyor musunuz ( E/H )?\n");
                scanf (" %[^\n]", &secim);
                Sleep(1700);
                system("cls");  // Standart kutuphanede (stdlib.h) mevcut olan System() fonksiyonunu kullanan bu komut ile konsol ekraninda daha once yazilmis olan her sey siliniyor ve temizleniyor.
                break;

            case 2:
                printf ("\n\n\t\tVucut Kitle Indeksiniz: \t%.1f", index);
                Sleep(1200);
                printf ("\n\t\t\t     Durumunuz: \t%s", vkiKategori2[i]);
                Sleep(1200);
                printf ("\n\n\tKilonuz normal deger araliklari arasinda.\n");

                printf ("\n\n\tYeni bir sorgulama yapmak istiyor musunuz ( E/H )?\n");
                scanf (" %[^\n]", &secim);
                Sleep(1700);
                system("cls");
                break;

            case 3:
                printf ("\n\n\t\tVucut Kitle Indeksiniz: \t%.1f", index);
                Sleep(1200);
                printf ("\n\t\t\t     Durumunuz: \t%s", vkiKategori2[i]);
                Sleep(1200);
                printf ("\n\n\tFazla kilolariniz var.\n\tBeslenme ve cesitli fiziksel aktivitelerle saglikli bir kiloya sahip olabilirsiniz.\n");

                printf ("\n\n\tYeni bir sorgulama yapmak istiyor musunuz ( E/H )?\n");
                scanf (" %[^\n]", &secim);
                Sleep(1700);
                system("cls");
                break;

            case 4:
                printf ("\n\n\t\tVucut Kitle Indeksiniz: \t%.1f", index);
                Sleep(1200);
                printf ("\n\t\t\t     Durumunuz: \t%s", vkiKategori2[i]);
                Sleep(1200);
                printf ("\n\n\tAile hekimine gorunmenizde fayda olabilir. Aile hekiminiz tarafindan buyuk ihtimalle\n\tdiyetisyene ya da 2. basamak bir saglik kurulusuna sevk edileceksiniz.\n");

                printf ("\n\n\tYeni bir sorgulama yapmak istiyor musunuz ( E/H )?\n");
                scanf (" %[^\n]", &secim);
                Sleep(1700);
                system("cls");
                break;

            case 5:
                printf ("\n\n\t\tVucut Kitle Indeksiniz: \t%.1f", index);
                Sleep(1200);
                printf ("\n\t\t\t     Durumunuz: \t%s", vkiKategori2[i]);
                Sleep(1200);
                printf ("\n\n\tObezitenin deri ve endokrin, kardiyovaskuler, solunum, gastrointestinal, genitoruriner,\n\tkas iskelet vucut sistemleri ile psikoloji uzerinde olumsuz etkileri oldugu, dolayisiyla");
                printf ("\n\tsaglik problemlerine neden oldugu degerlendirilmektedir. Lutfen bir saglik kurulusuna\n\tbasvurmayi dusunun.\n");

                printf ("\n\n\tYeni bir sorgulama yapmak istiyor musunuz ( E/H )?\n");
                scanf (" %[^\n]", &secim);
                Sleep(1700);
                system("cls");
                break;

            case 6:
                printf ("\n\n\t\tVucut Kitle Indeksiniz: \t%.1f", index);
                Sleep(1200);
                printf ("\n\t\t\t     Durumunuz: \t%s", vkiKategori2[i]);
                Sleep(1200);
                printf ("\n\n\tMumkun olan en kisa surede bir saglik kurulusuna basvurun! Obezitenin cesitli hastaliklarla iliskisi bilinmekte\n\tolup morbidite ve mortaliteyi artirici etkisi saglik otoritelerince");
                printf(" ortaya konulmustur. Obezite, bireylerin\n\tkararli katilimi ile hekim, diyetisyen, psikolog ve fizyoterapistten olusan bir ekibin gozetimini gerektiren,\n\ttedavi sureci uzun ve zorlu olan bir hastaliktir.\n");

                printf ("\n\n\tYeni bir sorgulama yapmak istiyor musunuz ( E/H )?\n");
                scanf (" %[^\n]", &secim);
                Sleep(1700);
                system("cls");
                break;

            default:
                printf ("\n\n\t\tHATA: Vucut Kitle Indeksiniz Dogru Bir Sekilde Kategorilendirilemedi!!! \n\n");
                Sleep(3800);
                printf ("\t\tProgram Yeniden Baslatiliyor...");
                Sleep(3000);
                printf ("\n\t\t\t\t\t\t\t.");
                Sleep(700);
                printf ("\n\t\t\t\t\t\t\t.");
                Sleep(700);
                printf ("\n\t\t\t\t\t\t\t.");
                Sleep(700);
                printf ("\n\t\t\t\t\t\t\t.");
                Sleep(700);
                system("cls");
                main();
        }
    }
    while ((secim == 'E') || (secim == 'e'));

    return 0;
}
