// CSV2JSON.cpp : This file contains the 'main' function. Program execution begins and ends there.
// ctrl + f5 to execute
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <wchar.h> // utf-8
#include <string.h> // string operations
#include <locale.h> // setlocale()

int main(int argc, char* argv[])
{
    // init
    setlocale(LC_ALL, "Turkish");
    FILE* csvDosyasi; // okunacak
    FILE* jsonDosyasi; // üstüne yazýlacak

    // 3 tane komut eklenmiþ mi kontrol et
    //    [1]        [2]        [3]
    // input.csv output.json header=OFF
    if (argc == 4)
    {
        // ----- ANA KOD -----
        // dosyalarý aç
        csvDosyasi = fopen(argv[1], "rt, ccs=UTF-8");
        jsonDosyasi = fopen(argv[2], "wt, ccs=UTF-8");
        wchar_t satir[200]; // max 200 satir


        if (csvDosyasi && jsonDosyasi) // dosya açýksa
        {
            fwprintf(jsonDosyasi, L"[");
            wchar_t baslikSatiri[200]; // ilk satir
            fgetws(baslikSatiri, 200, csvDosyasi);

            wchar_t basliklar[50][50]; // max 50 baslik, 50 karakter

            // baslik sayisini hesapla ve basliklar dizisine ekle
            wchar_t* tokenBaslik = wcstok(baslikSatiri, L" ,");
            int baslikIndex = 0;
            int baslikSayisi = 0;
            while (tokenBaslik != NULL)
            {
                wcscpy(basliklar[baslikIndex], tokenBaslik); // wide char string copy
                baslikIndex++;
                baslikSayisi++;
                tokenBaslik = wcstok(NULL, L" ,");
            }
            // satirdaki son elemanýn en sonundaki \n karakterini \0 ile deðiþtir
            basliklar[baslikSayisi - 1][wcslen(basliklar[baslikSayisi - 1]) - 1] = L'\0';

            // header kapalýysa baslikSatiri olarak
            // alýnan ilk satýrý da kolon1: "veri" þeklinde yaz
            if (!strcmp(argv[3], "header=OFF"))
            {
                fwprintf(jsonDosyasi, L"\n\t{\n\t\t");
                for (int i = 0; i < baslikSayisi; i++)
                {
                    
                    fwprintf(jsonDosyasi, L"\"");
                    fwprintf(jsonDosyasi, L"Kolon");
                    wchar_t buffer[50];
                    _itow(i + 1, buffer, 50);
                    fwprintf(jsonDosyasi, buffer);
                    fwprintf(jsonDosyasi, L"\"");

                    fwprintf(jsonDosyasi, L": ");

                    fwprintf(jsonDosyasi, L"\"");
                    fwprintf(jsonDosyasi, basliklar[i]);
                    fwprintf(jsonDosyasi, L"\",\n\t\t");
                }
                // en sondaki veriden sonra gelen virgülü temizlemek ve daha iyi format için
                fseek(jsonDosyasi, -5, SEEK_END);
                fwprintf(jsonDosyasi, L"");

                fwprintf(jsonDosyasi, L"\n\t},");

                
            }

            // her satýrý oku
            while (fgetws(satir, 200, csvDosyasi) != NULL)
            {
                fwprintf(jsonDosyasi, L"\n\t{\n\t\t");

                // satiri parsela
                wchar_t* tokenSatirN = wcstok(satir, L" ,"); // n. satir tokeni
                wchar_t satirParsed[50][50]; // parse'lanmýþ satiri depolamak için
                int satirIndex = 0;
                while (tokenSatirN != NULL)
                {
                    wcscpy(satirParsed[satirIndex], tokenSatirN); // wide char string copy
                    satirIndex++;
                    tokenSatirN = wcstok(NULL, L" ,");
                }
                // satirdaki son elemanýn en sonundaki \n karakterini \0 ile deðiþtir
                satirParsed[baslikSayisi - 1][wcslen(satirParsed[baslikSayisi - 1]) - 1] = L'\0';

                // verileri kullanarak pair'leri oluþtur
                // I = I. satir, J = J. veri
                // "baslik": "satirIJ"
                for (int i = 0; i < baslikSayisi; i++)
                {
                    
                    if (!strcmp(argv[3], "header=OFF"))
                    {
                        fwprintf(jsonDosyasi, L"\"");
                        fwprintf(jsonDosyasi, L"Kolon");
                        wchar_t buffer[50];
                        _itow(i + 1, buffer, 50);
                        fwprintf(jsonDosyasi, buffer);
                        fwprintf(jsonDosyasi, L"\"");
                    }
                    else if (!strcmp(argv[3], "header=ON"))
                    {
                        fwprintf(jsonDosyasi, L"\"");
                        fwprintf(jsonDosyasi, basliklar[i]);
                        fwprintf(jsonDosyasi, L"\"");
                    }
                    fwprintf(jsonDosyasi, L": ");

                    fwprintf(jsonDosyasi, L"\"");
                    fwprintf(jsonDosyasi, satirParsed[i]);
                    fwprintf(jsonDosyasi, L"\",\n\t\t");
                }
                // en sondaki veriden sonra gelen virgülü temizlemek ve daha iyi format için
                fseek(jsonDosyasi, -5, SEEK_END);
                fwprintf(jsonDosyasi, L"");
                //fwprintf(jsonDosyasi, satir);

                fwprintf(jsonDosyasi, L"\n\t},");
            }
            // en sondaki veriden sonra gelen virgülü temizlemek ve daha iyi format için
            fseek(jsonDosyasi, -3, SEEK_END);
            fwprintf(jsonDosyasi, L"\t}");
            fwprintf(jsonDosyasi, L"\n]");

            fclose(csvDosyasi);
            fclose(jsonDosyasi);
            
            printf("Program baþarýyla çalýþmýþtýr");
        }
    }
    else
    {
        printf("Program komut satýrý eksikliðinden dolayý çalýþtýrýlamamýþtýr.");
    }
    return 0;
}
