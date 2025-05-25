#include <stdio.h>
#include <stdlib.h>

#define MIN_NILAI 70

//Deklarasi struktur data siswa
typedef struct //untuk menyimpan data setiap siswa
{
    char nama [100];
    int afektif;
    int kognitif;
    int psikomotor;
    float ratarata;
    int nilai_tidak_mencukupi;
} siswa;

//Fungsi menginput nama dan rata-rata seseorang
void input_data (siswa *s)
{
    printf ("Masukan nama siswa : ");
    scanf ("%s", s->nama);
    
    printf ("Masukan nilai kognitif : ");
    scanf ("%d", &s->kognitif);
    
    printf ("Masukan nilai afektif : ");
    scanf  ("%d", &s->afektif);
    
    printf ("Masukan nilai psikomotor : ");
    scanf ("%d", &s->psikomotor);
    
    s->ratarata = (s->kognitif + s->afektif + s->psikomotor) / 3.0 ;
    
    s->nilai_tidak_mencukupi = (s->ratarata < MIN_NILAI);
}

//Fungsi untuk melakukan proses pengurutan 
void urutan (siswa s[], int n)
{
    for (int i = 0 ; i < n-1 ; i++) 
    {
        for (int j = 0 ; j < n-i-1 ; j++)
        {
            if (s[j].ratarata < s[j+1].ratarata) 
            {
                siswa temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp ;
            }
        }
    }
}

 //Fungsi siswa terbaik
 void siswaterbaik (siswa s[], int jumlah)
 {
    int terbaik = (jumlah < 5) ? jumlah : 5 ;
    for (int i = 0 ; i < terbaik ; i++)
    {
        printf ("%2d. %-12s %8.1f\n",
        i + 1, s[i].nama, s[i].ratarata,
        s[i].nilai_tidak_mencukupi ? "tidak_cukup" : "");
    }
 }

 //Fungsi main
 int main() {
    int jumlah_siswa;

    printf ("Masukan jumlah siswa : ");
    scanf ("%d", &jumlah_siswa);

    siswa *siswa= malloc(jumlah_siswa * sizeof(siswa));

    for (int i = 0 ; i < jumlah_siswa ; i++)
    {
        input_data (&siswa[i]);
    }

    urutan (siswa, jumlah_siswa);
    siswaterbaik (siswa, jumlah_siswa);

    for (int i = 0 ; i < jumlah_siswa ; i++)
    {
        if (siswa[i].nilai_tidak_mencukupi)
        {
            printf("- %s (Psikomotor:%d ...)\n", siswa[i].nama, siswa[i].psikomotor);
        }
    }

    free (siswa);
    return 0;

 }