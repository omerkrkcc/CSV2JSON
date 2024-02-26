# CSV2JSON

CSV2JSON, C dilinde yazılmış olan bir programdır ve CSV formatında yazılmış herhangi dosyayı 
kolaylıkla JSON formatına dönüştürmenize olanak tanır.

## Kullanım
1- Dosyayı rardan çıkartınız.
2- Programın çalışması için "tdm gcc" indirmiş olmanız gerekmektedir.
3- Komut İstemi'ni çalıştırdıktan sonra cd komutuyla klasörün içindeki CSV2JSON.exe'nin olduğu dizine geliniz.
4- Yukarıdaki talimatları uyguladıktan sonra gcc -o CSV2JSON CSV2JSON.c komutunu çalıştırınız.
5- Ardından CSV2JSON [input.csv] [output.json] [header=ON | OFF]
6- Böylelikle json ilgili dizinde oluşmuş oldu. 
7- input.csv ve output.json dosyalarının isimleri sadece İngilizce karakterler içermelidir.
8- Dosya içeriğinde Türkçe karakterlerin olması bir sorun teşkil etmemektedir.

Örnek çalıştırma,
C:\Users\UserName> cd Desktop\CSV2JSON 
C:\Users\UserName\Desktop\CSV2JSON> gcc -o CSV2JSON CSV2JSON.c
C:\Users\UserName\Desktop\CSV2JSON> CSV2JSON deneme.csv output.json header=ON


## Katkı
Bütün katkılar hoş karşılanmaktadır. Büyük değişiklikler için lütfen neyi değiştirmek istediğinizi belirtiniz.

## Lisans
MIT License Copyright (c) [2022] [ÖMER KARAKEÇE]
 Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
and associated documentation files (the "Software"), to deal in the Software without restriction, 
including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, 
subject to the following conditions: The above copyright notice and this permission notice shall be 
included in all copies or substantial portions of the Software. THE SOFTWARE IS PROVIDED "AS IS", 
WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS 
OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
IN THE SOFTWARE.
